/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_aboutdialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *aboutdialog)
    {
        if (aboutdialog->objectName().isEmpty())
            aboutdialog->setObjectName(QStringLiteral("aboutdialog"));
        aboutdialog->resize(350, 139);
        label = new QLabel(aboutdialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(16, 19, 251, 21));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI Semibold"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(aboutdialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(26, 49, 71, 21));
        label_3 = new QLabel(aboutdialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(26, 59, 301, 41));
        label_4 = new QLabel(aboutdialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(27, 69, 311, 61));

        retranslateUi(aboutdialog);

        QMetaObject::connectSlotsByName(aboutdialog);
    } // setupUi

    void retranslateUi(QDialog *aboutdialog)
    {
        aboutdialog->setWindowTitle(QApplication::translate("aboutdialog", "About", 0));
        label->setText(QApplication::translate("aboutdialog", "Simy 86", 0));
        label_2->setText(QApplication::translate("aboutdialog", "Version: 1.0 ", 0));
        label_3->setText(QApplication::translate("aboutdialog", "Simy 86 is a simple y86 architecture simulator.", 0));
        label_4->setText(QApplication::translate("aboutdialog", "Copyright (C) 2013 by Jin Yanghua/Amane Nagatsuki.", 0));
    } // retranslateUi

};

namespace Ui {
    class aboutdialog: public Ui_aboutdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
