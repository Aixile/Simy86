#include "y86sim.h"
#include <QString>
#include <QFileDialog>
#include <QAction>
#include <fstream>
#include <Qt>
#include "utility.h"
#include <qprocess.h>
#include <qdebug.h>
#include "htmldelegate.h"

y86sim::y86sim(QWidget *parent)
	: QMainWindow(parent)
{
	sourcelist=new sourceListDock(this);
	addDockWidget(static_cast<Qt::DockWidgetArea>(2),sourcelist);
	sourcelist->setAllowedAreas(Qt::AllDockWidgetAreas);
	//HTMLDelegate *htmld=new HTMLDelegate();
//	sourcelist->sourcelist->setItemDelegate(htmld);
	memorywatcher=new memoryWatcherDock(this);
	addDockWidget(static_cast<Qt::DockWidgetArea>(2),memorywatcher);
	memorywatcher->setAllowedAreas(Qt::AllDockWidgetAreas);

	ui.setupUi(this);
	about=new aboutdialog(this);
	about->hide();
	nowCycle=totCycle=0;
	
	speedSlider.setRange(1,200);
	speedSlider.setMaximumWidth(150);
	speedSlider.setOrientation(Qt::Horizontal);
	speedSlider.setValue(10);
	QWidget* spacer = new QWidget();
	spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	speedSpinbox.setRange(0.1,20);
	speedSpinbox.setValue(1.0);
	speedSpinbox.setSingleStep(0.1);
	speedSpinbox.setSuffix(tr("Hz"));
	speedSpinbox.setFixedWidth(60);

	void (QDoubleSpinBox::*tp)(double)=&QDoubleSpinBox::valueChanged;
	connect(&speedSpinbox,tp,this,&y86sim::setSliderValue);
	connect(&speedSlider,&QSlider::valueChanged,this,&y86sim::setSpinBoxValue);

	ui.mainToolBar->addWidget(spacer);
	ui.mainToolBar->addWidget(&speedSlider);
	ui.mainToolBar->addWidget(&speedSpinbox);
	
	connect(ui.action_Open,&QAction::triggered,this,&y86sim::action_Open);
	connect(ui.action_Compile,&QAction::triggered,this,&y86sim::action_Compile);
	connect(ui.action_Compile_use_yas,&QAction::triggered,this,&y86sim::action_yas_Compile);
	connect(ui.action_Save_Log,&QAction::triggered,this,&y86sim::action_Save_Log);
	connect(ui.action_Register_and_CC,&QAction::triggered,this,&y86sim::action_showRegCC);
	connect(ui.action_Memory_Watcher,&QAction::triggered,this,&y86sim::action_showMemoryWatcher);
	connect(ui.action_Source_Code,&QAction::triggered,this,&y86sim::action_showSourceCode);
	connect(ui.action_About,&QAction::triggered,this,&y86sim::action_show_About);
	connect(ui.action_Forward,&QAction::triggered,this,&y86sim::increase);
	connect(ui.action_Backward,&QAction::triggered,this,&y86sim::decrease);
	connect(ui.action_GotoStart,&QAction::triggered,this,&y86sim::gotoStart);
	connect(ui.action_GotoEnd,&QAction::triggered,this,&y86sim::gotoEnd);
	connect(ui.action_Stop,&QAction::triggered,this,&y86sim::resetAll);
	connect(ui.action_Play,&QAction::toggled,this,&y86sim::setTimer);
	connect(memorywatcher,&memoryWatcherDock::refreshPushed,this,&y86sim::doRefreshMemoryWatcher);

	playTimer= new QTimer(this);
	connect(playTimer,&QTimer::timeout,this,&y86sim::increase);
	connect(&speedSpinbox,tp,this,&y86sim::speedChanged);
	connect(this,&y86sim::isEnd,this,&y86sim::stopPlay);

	QPalette* palette = new QPalette();
	palette->setColor(QPalette::Base,QColor(240,240,240,0));
	ui.cycleSpinBox->setPalette(*palette);
	ui.cycleSpinBox->setFrame(false);

	connect(this,&y86sim::nowCycleChanged,this,&y86sim::showNowCycle);
	void (QSpinBox::*tp2)(int)=&QSpinBox::valueChanged;
	connect(ui.cycleSpinBox,tp2,this,&y86sim::showNowCycle);

	emptyPipe.Mem.clear();
	pipeQue.push_back(emptyPipe);
}

y86sim::~y86sim()
{

}

void y86sim::action_Open(){
	doOpen();
}

void y86sim::action_Compile(){
	doCompile();
}

void y86sim::action_yas_Compile(){
	doYasCompile();
}

void y86sim::action_Save_Log(){
	doSaveLog();
}

void y86sim::action_showRegCC(){
	if(ui.dockWidget->isVisible())	ui.dockWidget->setVisible(false);
	else	ui.dockWidget->setVisible(true);
}

void y86sim::action_showMemoryWatcher(){
	if(memorywatcher->isVisible())	memorywatcher->setVisible(false);
	else	memorywatcher->setVisible(true);
}

void y86sim::action_showSourceCode(){
	if(sourcelist->isVisible())	sourcelist->setVisible(false);
	else	sourcelist->setVisible(true);
}

void y86sim::action_show_About(){
	about->exec();
}

char tempStr[10000];
void y86sim::doOpen(){
	QString name=QFileDialog::getOpenFileName(this,tr("Open Y86 Program"),QDir::currentPath(),tr("Y86 assembly code file(*.yo)"));
	if(!name.isEmpty()){
		pipeProcessingNow =new pipe;
		std::ifstream yoFile(name.toStdString());
		sourcelist->clear();
		srcmap.clear();
		memorywatcher->memorylist->clear();
		pipeProcessingNow->Mem.clear();
		while(1){
			yoFile.getline(tempStr,9000,'|');
			int l=strlen(tempStr);
			int colon=-1;
			for(int i=0;i<l;i++){
				if(tempStr[i]==':')	colon=i;
			}
			int addr=0,bac_addr=0;
			if(colon>=0){
				tempStr[colon]=0;
				sscanf(tempStr,"%i",&addr);
				bac_addr=addr;
			}
			if(colon>=0&&tempStr[colon+2]!=' '){
				char val[20];
				sscanf(tempStr+colon+1,"%s",val);
				int vl=strlen(val);
				for(int i=0;i<vl;i+=2){
					int v=byte2int(val+i);
					pipeProcessingNow->Mem.write(addr,1,v);
					addr++;
				}
			}
			yoFile.getline(tempStr,9000);
			if(colon>=0){
				sourcelist->sourcelist->addItem(QString::fromStdString(int2hexStr12bit(bac_addr))+": "+QString(tempStr));
			}else	sourcelist->sourcelist->addItem(tempStr);
			if(colon>=0){
				srcmap[bac_addr]=sourcelist->sourcelist->count()-1;
			//	qDebug() << srcmap[bac_addr]<<" "<<addr<<" "<<bac_addr;
			}
			if(yoFile.eof())	break;
		}
		yoFile.close();
		pipeQue.clear();
		doProcess();
	}
}

//Use simyas to compile ys file
void y86sim::doCompile(){
	QString name=QFileDialog::getOpenFileName(this,tr("Open Y86 Program"),QDir::currentPath(),tr("Y86 source file(*.ys)"));
	if(!name.isEmpty()){
		QProcess::startDetached(QDir::currentPath()+"\\yas\\simyas.exe",QStringList(name));
	}
}

//Use yas to compile ys file
void y86sim::doYasCompile(){
	QString name=QFileDialog::getOpenFileName(this,tr("Open Y86 Program"),QDir::currentPath(),tr("Y86 source file(*.ys)"));
	if(!name.isEmpty()){
		QProcess::startDetached(QDir::currentPath()+"\\yas\\yas.exe",QStringList(name));
	}
}



void doWriteFile(std::ostream &o,const char *str,std::string val){
	o<<"\t"<<str<<"\t"<<"= "<<val<<std::endl;
}

void y86sim::doSaveLog(){
	QString name=QFileDialog::getSaveFileName(this,tr("Save Log File"),QDir::currentPath(),tr("Y86 Pipeline Log(*.log)"));
	if(!name.isEmpty()){
		std::ofstream logFile(name.toStdString());
		for(int i=0;i<=totCycle;i++){
			pipe &p=pipeQue[i];
			logFile<<"Cycle_"<<i<<std::endl;
			for(int j=0;j<20;j++)	logFile<<"-";
			logFile<<std::endl;
			logFile<<"FETCH:"<<std::endl;
			doWriteFile(logFile,"F_predPC",int2hexStr(p.f.predPC));
			logFile<<std::endl;
			logFile<<"DECODE:"<<std::endl;
			doWriteFile(logFile,"D_icode",int2hexStr4bit(p.d.icode));
			doWriteFile(logFile,"D_ifun",int2hexStr4bit(p.d.ifun));
			doWriteFile(logFile,"D_rA",int2hexStr4bit(p.d.ra));
			doWriteFile(logFile,"D_rB",int2hexStr4bit(p.d.rb));
			doWriteFile(logFile,"D_valC",int2hexStr(p.d.valC));
			doWriteFile(logFile,"D_valP",int2hexStr(p.d.valP));
			logFile<<std::endl;
			logFile<<"EXECUTE:"<<std::endl;
			doWriteFile(logFile,"E_icode",int2hexStr4bit(p.e.icode));
			doWriteFile(logFile,"E_ifun",int2hexStr4bit(p.e.ifun));
			doWriteFile(logFile,"E_valC",int2hexStr(p.e.valC));
			doWriteFile(logFile,"E_valA",int2hexStr(p.e.valA));
			doWriteFile(logFile,"E_valB",int2hexStr(p.e.valB));
			doWriteFile(logFile,"E_dstE",int2hexStr4bit(p.e.dstE));
			doWriteFile(logFile,"E_dstM",int2hexStr4bit(p.e.dstM));
			doWriteFile(logFile,"E_srcA",int2hexStr4bit(p.e.srcA));
			doWriteFile(logFile,"E_srcB",int2hexStr4bit(p.e.srcB));
			logFile<<std::endl;
			logFile<<"MEMORY:"<<std::endl;
			doWriteFile(logFile,"M_icode",int2hexStr4bit(p.m.icode));
			doWriteFile(logFile,"M_Bch",bit2tf(p.m.cnd));
			doWriteFile(logFile,"M_valE",int2hexStr(p.m.valE));
			doWriteFile(logFile,"M_valA",int2hexStr(p.m.valA));
			doWriteFile(logFile,"M_dstE",int2hexStr4bit(p.m.dstE));
			doWriteFile(logFile,"M_dstM",int2hexStr4bit(p.m.dstM));
			logFile<<std::endl;
			logFile<<"WRITE_BACK:"<<std::endl;
			doWriteFile(logFile,"W_icode",int2hexStr4bit(p.w.icode));
			doWriteFile(logFile,"W_valE",int2hexStr(p.w.valE));
			doWriteFile(logFile,"W_valM",int2hexStr(p.w.valM));
			doWriteFile(logFile,"W_dstE",int2hexStr4bit(p.w.dstE));
			doWriteFile(logFile,"W_dstM",int2hexStr4bit(p.w.dstM));
			logFile<<std::endl;
		}
		logFile.close();
	}
}


void y86sim::doProcess(){
	totCycle=0;
	pipeQue.push_back(*pipeProcessingNow);
	do{
		pipe  *nextPipe=new pipe;
		*nextPipe=pipeProcessingNow->controller();
		pipeProcessingNow=nextPipe;
		pipeQue.push_back(*pipeProcessingNow);
		totCycle++;
	}while(totCycle<=5000000&&!pipeProcessingNow->W_stall());
	ui.cycleSpinBox->setRange(0,totCycle);
	ui.cycleSpinBox->setValue(0);
	ui.cycleSpinBox->setSuffix(QString::fromStdString("/"+int2str(totCycle)));
	last_f_addr=0;
	last_d_addr=-1;
	last_e_addr=-1;
	last_m_addr=-1;
	last_w_addr=-1;
	nowCycle=0;
	emit nowCycleChanged(0);
}

void y86sim::setSliderValue(double a){
	speedSlider.setValue(a*10);
}

void y86sim::setSpinBoxValue(int a){
	speedSpinbox.setValue(double(a)/10);
}

//Refresh all infomation
void y86sim::showPipe(struct pipe& p){
	QFont font2;
    font2.setFamily(QStringLiteral("Segoe UI"));
	font2.setPointSize(12);
	ui.value_eax->setText(QString::fromStdString(int2hexStr(p.Reg.read(0))));
	ui.value_ecx->setText(QString::fromStdString(int2hexStr(p.Reg.read(1))));
	ui.value_edx->setText(QString::fromStdString(int2hexStr(p.Reg.read(2))));
	ui.value_ebx->setText(QString::fromStdString(int2hexStr(p.Reg.read(3))));
	ui.value_esp->setText(QString::fromStdString(int2hexStr(p.Reg.read(4))));
	ui.value_ebp->setText(QString::fromStdString(int2hexStr(p.Reg.read(5))));
	ui.value_esi->setText(QString::fromStdString(int2hexStr(p.Reg.read(6))));
	ui.value_edi->setText(QString::fromStdString(int2hexStr(p.Reg.read(7))));
	ui.value_PredPC->setText(QString::fromStdString(int2hexStr(p.f.predPC)));
	ui.value_D_valC->setText(QString::fromStdString(int2hexStr(p.d.valC)));
	ui.value_D_valP->setText(QString::fromStdString(int2hexStr(p.d.valP)));
	ui.value_E_valA->setText(QString::fromStdString(int2hexStr(p.e.valA)));
	ui.value_E_valB->setText(QString::fromStdString(int2hexStr(p.e.valB)));
	ui.value_E_valC->setText(QString::fromStdString(int2hexStr(p.e.valC)));
	ui.value_M_valA->setText(QString::fromStdString(int2hexStr(p.m.valA)));
	ui.value_M_valE->setText(QString::fromStdString(int2hexStr(p.m.valE)));
	ui.value_W_valE->setText(QString::fromStdString(int2hexStr(p.w.valE)));
	ui.value_W_valM->setText(QString::fromStdString(int2hexStr(p.w.valM)));
	ui.value_ZF->setText(QString(fourbit2hex(p.cc.isZF())));
	ui.value_SF->setText(QString(fourbit2hex(p.cc.isSF())));
	ui.value_OF->setText(QString(fourbit2hex(p.cc.isOF())));
	ui.value_D_icode->setText(QString::fromStdString(getIcode(mylog2(p.d.icode))));
	ui.value_D_ifun->setText(QString::fromStdString(getIfun(mylog2(p.d.icode),p.d.ifun)));
	ui.value_E_icode->setText(QString::fromStdString(getIcode(mylog2(p.e.icode))));
	ui.value_E_ifun->setText(QString::fromStdString(getIfun(mylog2(p.e.icode),p.e.ifun)));
	ui.value_M_icode->setText(QString::fromStdString(getIcode(mylog2(p.m.icode))));
	ui.value_W_icode->setText(QString::fromStdString(getIcode(mylog2(p.w.icode))));
	ui.value_D_rA->setText(QString::fromStdString(getReg(p.d.ra)));
	ui.value_D_rB->setText(QString::fromStdString(getReg(p.d.rb)));
	ui.value_E_srcB->setText(QString::fromStdString(getReg(p.e.srcB)));
	ui.value_E_srcA->setText(QString::fromStdString(getReg(p.e.srcA)));
	ui.value_E_srcB->setText(QString::fromStdString(getReg(p.e.srcB)));
	ui.value_E_dstE->setText(QString::fromStdString(getReg(p.e.dstE)));
	ui.value_E_dstM->setText(QString::fromStdString(getReg(p.e.dstM)));
	ui.value_M_dstE->setText(QString::fromStdString(getReg(p.m.dstE)));
	ui.value_M_dstM->setText(QString::fromStdString(getReg(p.m.dstM)));
	ui.value_W_dstE->setText(QString::fromStdString(getReg(p.w.dstE)));
	ui.value_W_dstM->setText(QString::fromStdString(getReg(p.w.dstM)));
	ui.value_M_cnd->setText(QString(fourbit2hex(p.m.cnd)));
	ui.value_D_stat->setText(QString::fromStdString(getState(p.d.stat,p.d_addr)));
	ui.value_E_stat->setText(QString::fromStdString(getState(p.e.stat,p.e_addr)));
	ui.value_M_stat->setText(QString::fromStdString(getState(p.m.stat,p.m_addr)));
	ui.value_W_stat->setText(QString::fromStdString(getState(p.w.stat,p.w_addr)));

	if(last_f_addr!=-1){
		QMap<int,int>::const_iterator i=srcmap.find(last_f_addr);
		if(i!=srcmap.end()){
			int t=i.value();
			if(!(t&1))	sourcelist->sourcelist->item(t)->setBackground(Qt::white);
			else	sourcelist->sourcelist->item(t)->setBackground(QColor("#f6f6f6"));
		}
	}

	if(last_d_addr!=-1){
		QMap<int,int>::const_iterator i=srcmap.find(last_d_addr);
		if(i!=srcmap.end()){
			int t=i.value();
			if(!(t&1))	sourcelist->sourcelist->item(t)->setBackground(Qt::white);
			else	sourcelist->sourcelist->item(t)->setBackground(QColor("#f6f6f6"));
		}
	}

	if(last_e_addr!=-1){
		QMap<int,int>::const_iterator i=srcmap.find(last_e_addr);
		if(i!=srcmap.end()){
			int t=i.value();
			if(!(t&1))	sourcelist->sourcelist->item(t)->setBackground(Qt::white);
			else	sourcelist->sourcelist->item(t)->setBackground(QColor("#f6f6f6"));
		}
	}

	if(last_m_addr!=-1){
		QMap<int,int>::const_iterator i=srcmap.find(last_m_addr);
		if(i!=srcmap.end()){
			int t=i.value();
			if(!(t&1))	sourcelist->sourcelist->item(t)->setBackground(Qt::white);
			else	sourcelist->sourcelist->item(t)->setBackground(QColor("#f6f6f6"));
		}
	}

	if(last_w_addr!=-1){
		QMap<int,int>::const_iterator i=srcmap.find(last_w_addr);
		if(i!=srcmap.end()){
			int t=i.value();
			if(!(t&1))	sourcelist->sourcelist->item(t)->setBackground(Qt::white);
			else	sourcelist->sourcelist->item(t)->setBackground(QColor("#f6f6f6"));
		}
	}

	if(p.w_addr!=-1){
		QMap<int,int>::const_iterator i=srcmap.find(p.w_addr);
		if(i!=srcmap.end()){
			int t=i.value();
			sourcelist->sourcelist->setCurrentRow(t);
			sourcelist->sourcelist->item(t)->setBackground(QColor("#ff7f77"));
		}
	}

	if(p.m_addr!=-1){
		QMap<int,int>::const_iterator i=srcmap.find(p.m_addr);
		if(i!=srcmap.end()){
			int t=i.value();
			sourcelist->sourcelist->setCurrentRow(t);
			sourcelist->sourcelist->item(t)->setBackground(QColor("#fff77f"));
		}
	}

	if(p.e_addr!=-1){
		QMap<int,int>::const_iterator i=srcmap.find(p.e_addr);
		if(i!=srcmap.end()){
			int t=i.value();
			sourcelist->sourcelist->setCurrentRow(t);
			sourcelist->sourcelist->item(t)->setBackground(QColor("#8affe9"));
		}
	}

	if(p.d_addr!=-1){
		QMap<int,int>::const_iterator i=srcmap.find(p.d_addr);
		if(i!=srcmap.end()){
			int t=i.value();
			sourcelist->sourcelist->setCurrentRow(t);
			sourcelist->sourcelist->item(t)->setBackground(QColor("#7888ff"));
		}
	}

	if(p.f_addr!=-1){
		QMap<int,int>::const_iterator i=srcmap.find(p.f_addr);
		if(i!=srcmap.end()){
			int t=i.value();
			sourcelist->sourcelist->setCurrentRow(t);
			sourcelist->sourcelist->item(t)->setBackground(QColor("#d881ff"));
		}
	}

	last_f_addr=p.f_addr;
	last_d_addr=p.d_addr;
	last_e_addr=p.e_addr;
	last_m_addr=p.m_addr;
	last_w_addr=p.w_addr;
}

//Cycle increase
void y86sim::increase(){
	if(totCycle!=nowCycle){
		emit nowCycleChanged(nowCycle+1);
	}else emit isEnd();
}

//Cycle decrease
void y86sim::decrease(){
	if(nowCycle!=0){
		emit nowCycleChanged(nowCycle-1);
	}
}

//Goto first cycle
void y86sim::gotoStart(){
	ui.action_Play->setChecked(false);
	emit nowCycleChanged(0);
}

//Goto last cycle
void y86sim::gotoEnd(){
	ui.action_Play->setChecked(false);
	emit nowCycleChanged(totCycle);
}


//Show Present Cycle Info
void y86sim::showNowCycle(int c){
	if(c==totCycle)	emit isEnd();
	nowCycle=c;
	showPipe(pipeQue[nowCycle]);
	ui.cycleSpinBox->setValue(nowCycle);
}

void y86sim::setTimer(){
	if(ui.action_Play->isChecked())
		playTimer->start(1000/speedSpinbox.value());
	else playTimer->stop();
}

void y86sim::speedChanged(){
	playTimer->stop();
	if(ui.action_Play->isChecked())	playTimer->start(1000/speedSpinbox.value());
}

void y86sim::resetAll(){
	playTimer->stop();
	speedSpinbox.setValue(1.0);
	gotoStart();
}

void y86sim::stopPlay(){
	playTimer->stop();
	ui.action_Play->setChecked(false);
}

void y86sim::doRefreshMemoryWatcher(int s_addr,int e_addr){
	s_addr&=0xFFFFFFF8;
	e_addr&=0xFFFFFFF8;
	if(s_addr<=e_addr){
		memorywatcher->memorylist->clear();
		qDebug() << pipeQue[nowCycle].Mem.TrieRoot;
		for(u32 i=s_addr;i<=e_addr;i+=8){
			QString s=QString::fromStdString(int2hexStr12bit(i));
			s+=": "+QString::fromStdString(int2byte(pipeQue[nowCycle].Mem.read(i,1)));
			s+=" "+QString::fromStdString(int2byte(pipeQue[nowCycle].Mem.read(i+1,1)));
			s+=" "+QString::fromStdString(int2byte(pipeQue[nowCycle].Mem.read(i+2,1)));
			s+=" "+QString::fromStdString(int2byte(pipeQue[nowCycle].Mem.read(i+3,1)));
			s+=" "+QString::fromStdString(int2byte(pipeQue[nowCycle].Mem.read(i+4,1)));
			s+=" "+QString::fromStdString(int2byte(pipeQue[nowCycle].Mem.read(i+5,1)));
			s+=" "+QString::fromStdString(int2byte(pipeQue[nowCycle].Mem.read(i+6,1)));
			s+=" "+QString::fromStdString(int2byte(pipeQue[nowCycle].Mem.read(i+7,1)));
			memorywatcher->memorylist->addItem(s);
		}
	}
}