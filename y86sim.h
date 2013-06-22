#ifndef Y86SIM_H
#define Y86SIM_H

#include <QtWidgets/QMainWindow>
#include "ui_y86sim.h"
#include "pipe.h"
#include "memory.h"
#include <vector>
#include <qspinbox.h>
#include <qtimer.h>
#include "sourcelistdock.h"
#include "memorywatcherdock.h"
#include <qmap.h>
#include "aboutdialog.h"

class y86sim : public QMainWindow
{
	Q_OBJECT

public:
	y86sim(QWidget *parent = 0);
	~y86sim();

//	Actions
	void action_Open();
	void action_Compile();
	void action_yas_Compile();
	void action_showRegCC();
	void action_showMemoryWatcher();
	void action_showSourceCode();
	void action_Save_Log();
	void action_show_About();
	void doOpen();
	void doProcess();
	void doCompile();
	void doYasCompile();
	void doSaveLog();

private:
	
//	Qt GUI Widget
//	basic window
	Ui::y86simClass ui;
//	source code dock
	sourceListDock *sourcelist;
//	memory watcher dock
	memoryWatcherDock *memorywatcher;
//	play speed slider
	QSlider speedSlider;
//	play speed spinbox
	QDoubleSpinBox speedSpinbox;
	void setSliderValue(double a);
	void setSpinBoxValue(int a);
//	about dialog
	aboutdialog *about;

//	pipe data
	struct pipe *pipeProcessingNow,emptyPipe;
	std::vector<struct pipe> pipeQue;

//	map memory address to source code line  
	QMap<int,int> srcmap;

//	last used address
	int last_f_addr,last_d_addr,last_e_addr,last_m_addr,last_w_addr;

//	CPU Cycle
	int totCycle,nowCycle;
	void increase();
	void decrease();
	void gotoStart();
	void gotoEnd();

//	show nowCycle
	void showPipe(struct pipe&);

//	Timer
	QTimer *playTimer;
	void setTimer();
	void speedChanged();
	void resetAll();
	void stopPlay();

signals:
	void nowCycleChanged(int c);
	void isEnd();	

public slots:
	void showNowCycle(int c);
	void doRefreshMemoryWatcher(int s_addr,int e_addr);
};

#endif // Y86SIM_H
