#include "memorywatcherdock.h"
#include <QResizeEvent>
#include <qapplication.h>
#include <qrect.h>

memoryWatcherDock::memoryWatcherDock(QWidget *parent)
	: QDockWidget(parent)
{
	setMinimumSize(QSize(260,38));
	mainarea=new QWidget;
	QFont font1;
	font1.setFamily(QStringLiteral("Segoe UI Semibold"));
	font1.setPointSize(11);
	font1.setBold(true);
	font1.setWeight(75);
	l_start=new QLabel(mainarea);
	l_start->setFont(font1);
	l_start->setText(QApplication::translate("y86simClass","Start Addr. :",0));
	l_start->setGeometry(10,10,100,23);
	start=new HexSpinBox(mainarea);
	start->setPrefix("0x");
	start->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
	start->setGeometry(100,10,110,23);
	l_end=new QLabel(mainarea);
	l_end->setFont(font1);
	l_end->setText(QApplication::translate("y86simClass","End Addr. :",0));
	l_end->setGeometry(10,40,100,23);
	end=new HexSpinBox(mainarea);
	end->setPrefix("0x");
	end->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
	end->setGeometry(100,40,110,23);
	ref=new QPushButton(mainarea);
	QIcon icon;
	icon.addFile(QStringLiteral(":/y86sim/icon/gtk-refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
	ref->setIcon(icon);
	ref->setGeometry(224,40,23,23);
	ref->setToolTip("Refresh");

	memorylist=new QListWidget(mainarea);
	memorylist->setFocusPolicy(Qt::NoFocus);
	memorylist->setEditTriggers(QAbstractItemView::NoEditTriggers);
	memorylist->setProperty("showDropIndicator", QVariant(false));
	memorylist->setSelectionMode(QAbstractItemView::NoSelection);
	memorylist->setTextElideMode(Qt::ElideMiddle);
	memorylist->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
	memorylist->setAlternatingRowColors(true);
	memorylist->setLayoutMode(QListView::Batched);
	memorylist->setGeometry(0,75,261,263-75);
	setWindowTitle(QApplication::translate("y86simClass", "Memory Watcher", 0));
	setWidget(mainarea);
	connect(ref,&QPushButton::clicked,this,&memoryWatcherDock::sendRefSig);
}

memoryWatcherDock::~memoryWatcherDock()
{

}

void memoryWatcherDock::resizeEvent(QResizeEvent *ev){
	if(isFloating()){
		memorylist->setMinimumSize(ev->size().width(),ev->size().height()-75);
		memorylist->setGeometry(0,75,(ev->size().width()),(ev->size().height()-75));
	
	}else{
		memorylist->setMinimumSize(ev->size().width(),ev->size().height()-20-75);
		memorylist->setGeometry(0,75,(ev->size().width()),(ev->size().height()-20-75));
	}
}

void memoryWatcherDock::sendRefSig(){
	emit refreshPushed(start->value(),end->value());
}