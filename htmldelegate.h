#ifndef HTMLDELEGATE_H
#define HTMLDELEGATE_H

#include <QStyledItemDelegate>

class HTMLDelegate : public QStyledItemDelegate
{
	Q_OBJECT

public:
	//HTMLDelegate(QObject *parent=0);
	//~HTMLDelegate();

protected:
	void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
	QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const;

private:
	
};

#endif // HTMLDELEGATE_H
