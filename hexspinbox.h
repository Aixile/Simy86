#ifndef HEXSPINBOX_H
#define HEXSPINBOX_H

#include <QSpinBox>


//HexFormQSpinBox
//Support Range:0x0~0x7FFFFFFF
class HexSpinBox : public QSpinBox
{
	Q_OBJECT

public:
	HexSpinBox(QWidget *parent);
	~HexSpinBox();

private:
	QRegExpValidator *validator;

protected:
	int valueFromText(const QString &text) const;
	QString textFromValue(int value) const;
	QValidator::State validate(QString &text, int &pos) const;
};

#endif // HEXSPINBOX_H
