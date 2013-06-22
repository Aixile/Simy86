#include "sourcelistdock.h"
#include <QResizeEvent>
#include <qapplication.h>

sourceListDock::sourceListDock(QWidget *parent)
	: QDockWidget(parent)
{
	setMinimumSize(QSize(260,38));
	mainarea=new QWidget;
	sourcelist=new QListWidget(mainarea);
	sourcelist->setGeometry(QRect(0, 0, 260, 241));       
	QFont font7;
    font7.setFamily(QStringLiteral("Courier New"));
    font7.setPointSize(9);
	sourcelist->setFont(font7);
	sourcelist->setFocusPolicy(Qt::NoFocus);
	sourcelist->setEditTriggers(QAbstractItemView::NoEditTriggers);
	sourcelist->setProperty("showDropIndicator", QVariant(false));
	sourcelist->setSelectionMode(QAbstractItemView::NoSelection);
	sourcelist->setTextElideMode(Qt::ElideMiddle);
	sourcelist->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
	sourcelist->setAlternatingRowColors(true);
	sourcelist->setLayoutMode(QListView::Batched);
	setWindowTitle(QApplication::translate("y86simClass", "Source Code", 0));
	setWidget(mainarea);
}

sourceListDock::~sourceListDock()
{

}


void sourceListDock::resizeEvent(QResizeEvent *ev){
	if(isFloating()){
		sourcelist->setMinimumSize(ev->size().width(),ev->size().height());
		sourcelist->setGeometry(0,0,(ev->size().width()),(ev->size().height()));
	
	}else{
		sourcelist->setMinimumSize(ev->size().width(),ev->size().height()-20);
		sourcelist->setGeometry(0,0,(ev->size().width()),(ev->size().height()-20));
	}
}

void sourceListDock::clear(){
	sourcelist->clear();
}