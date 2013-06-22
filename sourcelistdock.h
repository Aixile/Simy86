#ifndef SOURCELISTDOCK_H
#define SOURCELISTDOCK_H

#include <QDockWidget>
#include <qlistwidget.h>

//Qt Dock Widget:Source Code
//Support QlistWidget AutoResize
class sourceListDock : public QDockWidget
{
	Q_OBJECT

public:
	sourceListDock(QWidget *parent);
	~sourceListDock();
	QListWidget *sourcelist;
	void clear();

private:
	QWidget *mainarea;

protected:
	void resizeEvent(QResizeEvent *event);
};

#endif // SOURCELISTDOCK_H
