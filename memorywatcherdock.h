#ifndef MEMORYWATCHERDOCK_H
#define MEMORYWATCHERDOCK_H

#include <QDockWidget>
#include <qlistwidget.h>
#include <qspinbox.h>
#include "hexspinbox.h"
#include <qlabel.h>
#include <qaction.h>
#include <qpushbutton.h>

//Qt Dock Widget:Memory Watcher
//Support QlistWidget AutoResize
class memoryWatcherDock : public QDockWidget
{
	Q_OBJECT

public:
	memoryWatcherDock(QWidget *parent);
	~memoryWatcherDock();
	void clear();
	QListWidget *memorylist;

private:
	QWidget *mainarea;
	QLabel *l_start,*l_end;
	HexSpinBox *start,*end;
	QPushButton *ref;

protected:
	void resizeEvent(QResizeEvent *event);

signals:
	void refreshPushed(int s_addr,int e_addr);

public slots:
	void sendRefSig();

};

#endif // MEMORYWATCHERDOCK_H
