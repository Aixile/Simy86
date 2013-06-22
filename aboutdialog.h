#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include "ui_aboutdialog.h"

//About Dialog
class aboutdialog : public QDialog
{
	Q_OBJECT

public:
	aboutdialog(QWidget *parent = 0);
	~aboutdialog();

private:
	Ui::aboutdialog ui;
};

#endif // ABOUTDIALOG_H
