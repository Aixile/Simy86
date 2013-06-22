/********************************************************************************
** Form generated from reading UI file 'y86sim.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_Y86SIM_H
#define UI_Y86SIM_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_y86simClass
{
public:
    QAction *action_Open;
    QAction *action_Play;
    QAction *action_Stop;
    QAction *action_Forward;
    QAction *action_Backward;
    QAction *action_GotoStart;
    QAction *action_GotoEnd;
    QAction *action_Compile;
    QAction *action_Register_and_CC;
    QAction *action_Memory_Watcher;
    QAction *action_Source_Code;
    QAction *action_Save_Log;
    QAction *action_About;
    QAction *action_Compile_use_yas;
    QWidget *centralWidget;
    QFrame *line;
    QLabel *mainbg;
    QLabel *textFetch;
    QLabel *textDecode;
    QLabel *textExecute;
    QLabel *textMemory;
    QLabel *textWriteback;
    QLabel *text_PredPC;
    QTextBrowser *value_PredPC;
    QLabel *text_E_stat;
    QTextBrowser *value_E_stat;
    QLabel *text_M_stat;
    QTextBrowser *value_M_stat;
    QTextBrowser *value_W_stat;
    QLabel *text_W_stat;
    QTextBrowser *value_D_stat;
    QLabel *text_D_stat;
    QLabel *text_D_icode;
    QTextBrowser *value_D_icode;
    QLabel *text_E_icode;
    QTextBrowser *value_E_icode;
    QLabel *text_M_icode;
    QTextBrowser *value_M_icode;
    QLabel *text_W_icode;
    QTextBrowser *value_W_icode;
    QLabel *text_D_ifun;
    QTextBrowser *value_D_ifun;
    QLabel *text_E_ifun;
    QTextBrowser *value_E_ifun;
    QLabel *text_M_Cnd;
    QTextBrowser *value_M_cnd;
    QTextBrowser *value_D_rA;
    QLabel *text_D_rA;
    QLabel *text_D_rB;
    QTextBrowser *value_D_rB;
    QLabel *text_D_valC;
    QTextBrowser *value_D_valC;
    QTextBrowser *value_D_valP;
    QLabel *text_D_valP;
    QTextBrowser *value_E_valC;
    QLabel *text_E_valC;
    QTextBrowser *value_E_valA;
    QLabel *text_E_valA;
    QLabel *text_E_valB;
    QTextBrowser *value_E_valB;
    QLabel *text_E_dstE;
    QLabel *text_E_dstM;
    QTextBrowser *value_E_dstM;
    QTextBrowser *value_E_dstE;
    QTextBrowser *value_E_srcA;
    QLabel *text_E_srcA;
    QLabel *text_E_srcB;
    QTextBrowser *value_E_srcB;
    QTextBrowser *value_M_valE;
    QLabel *text_M_valE;
    QLabel *text_M_valA;
    QTextBrowser *value_M_valA;
    QLabel *text_M_dstM;
    QLabel *text_M_dstE;
    QTextBrowser *value_M_dstM;
    QTextBrowser *value_M_dstE;
    QTextBrowser *value_W_valM;
    QTextBrowser *value_W_dstE;
    QLabel *text_W_dstE;
    QTextBrowser *value_W_valE;
    QLabel *text_W_dstM;
    QLabel *text_W_valE;
    QTextBrowser *value_W_dstM;
    QLabel *text_W_valM;
    QSpinBox *cycleSpinBox;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_View;
    QMenu *menu_Help;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QLabel *text_eax;
    QLabel *text_ebx;
    QLabel *text_ecx;
    QLabel *text_edx;
    QLabel *text_esp;
    QLabel *text_ebp;
    QLabel *text_esi;
    QLabel *text_edi;
    QTextBrowser *value_eax;
    QTextBrowser *value_ebx;
    QTextBrowser *value_ecx;
    QTextBrowser *value_edx;
    QTextBrowser *value_esp;
    QTextBrowser *value_ebp;
    QTextBrowser *value_esi;
    QTextBrowser *value_edi;
    QLabel *text_ZF;
    QLabel *text_SF;
    QLabel *text_OF;
    QTextBrowser *value_ZF;
    QTextBrowser *value_SF;
    QTextBrowser *value_OF;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *y86simClass)
    {
        if (y86simClass->objectName().isEmpty())
            y86simClass->setObjectName(QStringLiteral("y86simClass"));
        y86simClass->resize(1024, 576);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(y86simClass->sizePolicy().hasHeightForWidth());
        y86simClass->setSizePolicy(sizePolicy);
        y86simClass->setMinimumSize(QSize(1024, 576));
        y86simClass->setMaximumSize(QSize(1024, 576));
        y86simClass->setCursor(QCursor(Qt::ArrowCursor));
        y86simClass->setAutoFillBackground(false);
        y86simClass->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        y86simClass->setTabShape(QTabWidget::Rounded);
        y86simClass->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        action_Open = new QAction(y86simClass);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        action_Play = new QAction(y86simClass);
        action_Play->setObjectName(QStringLiteral("action_Play"));
        action_Play->setCheckable(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/y86sim/icon/gtk-media-play-ltr.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/y86sim/icon/gtk-media-pause.png"), QSize(), QIcon::Active, QIcon::On);
        action_Play->setIcon(icon);
        action_Stop = new QAction(y86simClass);
        action_Stop->setObjectName(QStringLiteral("action_Stop"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/y86sim/icon/gtk-media-stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Stop->setIcon(icon1);
        action_Forward = new QAction(y86simClass);
        action_Forward->setObjectName(QStringLiteral("action_Forward"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/y86sim/icon/player_fwd.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Forward->setIcon(icon2);
        action_Backward = new QAction(y86simClass);
        action_Backward->setObjectName(QStringLiteral("action_Backward"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/y86sim/icon/player_rew.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Backward->setIcon(icon3);
        action_GotoStart = new QAction(y86simClass);
        action_GotoStart->setObjectName(QStringLiteral("action_GotoStart"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/y86sim/icon/gtk-media-next-rtl.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_GotoStart->setIcon(icon4);
        action_GotoEnd = new QAction(y86simClass);
        action_GotoEnd->setObjectName(QStringLiteral("action_GotoEnd"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/y86sim/icon/gtk-media-next-ltr.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_GotoEnd->setIcon(icon5);
        action_Compile = new QAction(y86simClass);
        action_Compile->setObjectName(QStringLiteral("action_Compile"));
        action_Register_and_CC = new QAction(y86simClass);
        action_Register_and_CC->setObjectName(QStringLiteral("action_Register_and_CC"));
        action_Memory_Watcher = new QAction(y86simClass);
        action_Memory_Watcher->setObjectName(QStringLiteral("action_Memory_Watcher"));
        action_Source_Code = new QAction(y86simClass);
        action_Source_Code->setObjectName(QStringLiteral("action_Source_Code"));
        action_Save_Log = new QAction(y86simClass);
        action_Save_Log->setObjectName(QStringLiteral("action_Save_Log"));
        action_About = new QAction(y86simClass);
        action_About->setObjectName(QStringLiteral("action_About"));
        action_Compile_use_yas = new QAction(y86simClass);
        action_Compile_use_yas->setObjectName(QStringLiteral("action_Compile_use_yas"));
        centralWidget = new QWidget(y86simClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(669, -40, 10, 601));
        QFont font;
        font.setFamily(QString::fromUtf8("\343\201\277\343\201\213\343\201\241\343\202\203\343\202\223-PB"));
        font.setPointSize(18);
        line->setFont(font);
        line->setFrameShadow(QFrame::Sunken);
        line->setLineWidth(1);
        line->setMidLineWidth(0);
        line->setFrameShape(QFrame::VLine);
        mainbg = new QLabel(centralWidget);
        mainbg->setObjectName(QStringLiteral("mainbg"));
        mainbg->setGeometry(QRect(0, -2, 670, 530));
        mainbg->setFont(font);
        mainbg->setTextFormat(Qt::AutoText);
        mainbg->setPixmap(QPixmap(QString::fromUtf8(":/y86sim/bg/bg.png")));
        textFetch = new QLabel(centralWidget);
        textFetch->setObjectName(QStringLiteral("textFetch"));
        textFetch->setGeometry(QRect(30, 1, 111, 41));
        textFetch->setFont(font);
        textFetch->setTextFormat(Qt::AutoText);
        textDecode = new QLabel(centralWidget);
        textDecode->setObjectName(QStringLiteral("textDecode"));
        textDecode->setGeometry(QRect(150, 1, 111, 41));
        textDecode->setFont(font);
        textDecode->setTextFormat(Qt::AutoText);
        textExecute = new QLabel(centralWidget);
        textExecute->setObjectName(QStringLiteral("textExecute"));
        textExecute->setGeometry(QRect(290, 1, 111, 41));
        textExecute->setFont(font);
        textExecute->setTextFormat(Qt::AutoText);
        textMemory = new QLabel(centralWidget);
        textMemory->setObjectName(QStringLiteral("textMemory"));
        textMemory->setGeometry(QRect(430, 1, 111, 41));
        textMemory->setFont(font);
        textMemory->setTextFormat(Qt::AutoText);
        textWriteback = new QLabel(centralWidget);
        textWriteback->setObjectName(QStringLiteral("textWriteback"));
        textWriteback->setGeometry(QRect(555, 1, 111, 41));
        textWriteback->setFont(font);
        textWriteback->setTextFormat(Qt::AutoText);
        text_PredPC = new QLabel(centralWidget);
        text_PredPC->setObjectName(QStringLiteral("text_PredPC"));
        text_PredPC->setGeometry(QRect(10, 51, 91, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe UI Semibold"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        text_PredPC->setFont(font1);
        value_PredPC = new QTextBrowser(centralWidget);
        value_PredPC->setObjectName(QStringLiteral("value_PredPC"));
        value_PredPC->setGeometry(QRect(10, 81, 101, 28));
        QFont font2;
        font2.setFamily(QStringLiteral("Segoe UI"));
        font2.setPointSize(12);
        value_PredPC->setFont(font2);
        value_PredPC->setLayoutDirection(Qt::RightToLeft);
        value_PredPC->setFrameShadow(QFrame::Plain);
        value_PredPC->setLineWidth(0);
        value_PredPC->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_PredPC->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_E_stat = new QLabel(centralWidget);
        text_E_stat->setObjectName(QStringLiteral("text_E_stat"));
        text_E_stat->setGeometry(QRect(282, 51, 31, 21));
        text_E_stat->setFont(font1);
        value_E_stat = new QTextBrowser(centralWidget);
        value_E_stat->setObjectName(QStringLiteral("value_E_stat"));
        value_E_stat->setGeometry(QRect(320, 49, 51, 28));
        value_E_stat->setFont(font2);
        value_E_stat->setLayoutDirection(Qt::RightToLeft);
        value_E_stat->setFrameShadow(QFrame::Plain);
        value_E_stat->setLineWidth(0);
        value_E_stat->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_E_stat->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_M_stat = new QLabel(centralWidget);
        text_M_stat->setObjectName(QStringLiteral("text_M_stat"));
        text_M_stat->setGeometry(QRect(422, 51, 31, 21));
        text_M_stat->setFont(font1);
        value_M_stat = new QTextBrowser(centralWidget);
        value_M_stat->setObjectName(QStringLiteral("value_M_stat"));
        value_M_stat->setGeometry(QRect(460, 49, 51, 28));
        value_M_stat->setFont(font2);
        value_M_stat->setLayoutDirection(Qt::RightToLeft);
        value_M_stat->setFrameShadow(QFrame::Plain);
        value_M_stat->setLineWidth(0);
        value_M_stat->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_M_stat->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_W_stat = new QTextBrowser(centralWidget);
        value_W_stat->setObjectName(QStringLiteral("value_W_stat"));
        value_W_stat->setGeometry(QRect(594, 49, 51, 28));
        value_W_stat->setFont(font2);
        value_W_stat->setLayoutDirection(Qt::RightToLeft);
        value_W_stat->setFrameShadow(QFrame::Plain);
        value_W_stat->setLineWidth(0);
        value_W_stat->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_W_stat->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_W_stat = new QLabel(centralWidget);
        text_W_stat->setObjectName(QStringLiteral("text_W_stat"));
        text_W_stat->setGeometry(QRect(556, 51, 31, 21));
        text_W_stat->setFont(font1);
        value_D_stat = new QTextBrowser(centralWidget);
        value_D_stat->setObjectName(QStringLiteral("value_D_stat"));
        value_D_stat->setGeometry(QRect(179, 49, 51, 28));
        value_D_stat->setFont(font2);
        value_D_stat->setLayoutDirection(Qt::RightToLeft);
        value_D_stat->setFrameShadow(QFrame::Plain);
        value_D_stat->setLineWidth(0);
        value_D_stat->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_D_stat->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_D_stat = new QLabel(centralWidget);
        text_D_stat->setObjectName(QStringLiteral("text_D_stat"));
        text_D_stat->setGeometry(QRect(141, 51, 31, 21));
        text_D_stat->setFont(font1);
        text_D_icode = new QLabel(centralWidget);
        text_D_icode->setObjectName(QStringLiteral("text_D_icode"));
        text_D_icode->setGeometry(QRect(128, 87, 41, 31));
        text_D_icode->setFont(font1);
        value_D_icode = new QTextBrowser(centralWidget);
        value_D_icode->setObjectName(QStringLiteral("value_D_icode"));
        value_D_icode->setGeometry(QRect(179, 91, 70, 28));
        value_D_icode->setFont(font2);
        value_D_icode->setLayoutDirection(Qt::RightToLeft);
        value_D_icode->setFrameShadow(QFrame::Plain);
        value_D_icode->setLineWidth(0);
        value_D_icode->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_D_icode->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_E_icode = new QLabel(centralWidget);
        text_E_icode->setObjectName(QStringLiteral("text_E_icode"));
        text_E_icode->setGeometry(QRect(269, 87, 41, 31));
        text_E_icode->setFont(font1);
        value_E_icode = new QTextBrowser(centralWidget);
        value_E_icode->setObjectName(QStringLiteral("value_E_icode"));
        value_E_icode->setGeometry(QRect(320, 91, 70, 28));
        value_E_icode->setFont(font2);
        value_E_icode->setLayoutDirection(Qt::RightToLeft);
        value_E_icode->setFrameShadow(QFrame::Plain);
        value_E_icode->setLineWidth(0);
        value_E_icode->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_E_icode->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_M_icode = new QLabel(centralWidget);
        text_M_icode->setObjectName(QStringLiteral("text_M_icode"));
        text_M_icode->setGeometry(QRect(409, 87, 41, 31));
        text_M_icode->setFont(font1);
        value_M_icode = new QTextBrowser(centralWidget);
        value_M_icode->setObjectName(QStringLiteral("value_M_icode"));
        value_M_icode->setGeometry(QRect(460, 91, 70, 28));
        value_M_icode->setFont(font2);
        value_M_icode->setLayoutDirection(Qt::RightToLeft);
        value_M_icode->setFrameShadow(QFrame::Plain);
        value_M_icode->setLineWidth(0);
        value_M_icode->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_M_icode->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_W_icode = new QLabel(centralWidget);
        text_W_icode->setObjectName(QStringLiteral("text_W_icode"));
        text_W_icode->setGeometry(QRect(543, 87, 41, 31));
        text_W_icode->setFont(font1);
        value_W_icode = new QTextBrowser(centralWidget);
        value_W_icode->setObjectName(QStringLiteral("value_W_icode"));
        value_W_icode->setGeometry(QRect(594, 91, 70, 28));
        value_W_icode->setFont(font2);
        value_W_icode->setLayoutDirection(Qt::RightToLeft);
        value_W_icode->setFrameShadow(QFrame::Plain);
        value_W_icode->setLineWidth(0);
        value_W_icode->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_W_icode->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_D_ifun = new QLabel(centralWidget);
        text_D_ifun->setObjectName(QStringLiteral("text_D_ifun"));
        text_D_ifun->setGeometry(QRect(137, 129, 41, 31));
        text_D_ifun->setFont(font1);
        value_D_ifun = new QTextBrowser(centralWidget);
        value_D_ifun->setObjectName(QStringLiteral("value_D_ifun"));
        value_D_ifun->setGeometry(QRect(179, 133, 51, 28));
        value_D_ifun->setFont(font2);
        value_D_ifun->setLayoutDirection(Qt::RightToLeft);
        value_D_ifun->setFrameShadow(QFrame::Plain);
        value_D_ifun->setLineWidth(0);
        value_D_ifun->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_D_ifun->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_E_ifun = new QLabel(centralWidget);
        text_E_ifun->setObjectName(QStringLiteral("text_E_ifun"));
        text_E_ifun->setGeometry(QRect(278, 129, 41, 31));
        text_E_ifun->setFont(font1);
        value_E_ifun = new QTextBrowser(centralWidget);
        value_E_ifun->setObjectName(QStringLiteral("value_E_ifun"));
        value_E_ifun->setGeometry(QRect(320, 133, 51, 28));
        value_E_ifun->setFont(font2);
        value_E_ifun->setLayoutDirection(Qt::RightToLeft);
        value_E_ifun->setFrameShadow(QFrame::Plain);
        value_E_ifun->setLineWidth(0);
        value_E_ifun->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_E_ifun->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_M_Cnd = new QLabel(centralWidget);
        text_M_Cnd->setObjectName(QStringLiteral("text_M_Cnd"));
        text_M_Cnd->setGeometry(QRect(419, 129, 41, 31));
        text_M_Cnd->setFont(font1);
        value_M_cnd = new QTextBrowser(centralWidget);
        value_M_cnd->setObjectName(QStringLiteral("value_M_cnd"));
        value_M_cnd->setGeometry(QRect(460, 133, 51, 28));
        value_M_cnd->setFont(font2);
        value_M_cnd->setLayoutDirection(Qt::RightToLeft);
        value_M_cnd->setFrameShadow(QFrame::Plain);
        value_M_cnd->setLineWidth(0);
        value_M_cnd->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_M_cnd->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_D_rA = new QTextBrowser(centralWidget);
        value_D_rA->setObjectName(QStringLiteral("value_D_rA"));
        value_D_rA->setGeometry(QRect(179, 175, 51, 28));
        value_D_rA->setFont(font2);
        value_D_rA->setLayoutDirection(Qt::RightToLeft);
        value_D_rA->setFrameShadow(QFrame::Plain);
        value_D_rA->setLineWidth(0);
        value_D_rA->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_D_rA->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_D_rA = new QLabel(centralWidget);
        text_D_rA->setObjectName(QStringLiteral("text_D_rA"));
        text_D_rA->setGeometry(QRect(147, 171, 41, 31));
        text_D_rA->setFont(font1);
        text_D_rB = new QLabel(centralWidget);
        text_D_rB->setObjectName(QStringLiteral("text_D_rB"));
        text_D_rB->setGeometry(QRect(147, 213, 41, 31));
        text_D_rB->setFont(font1);
        value_D_rB = new QTextBrowser(centralWidget);
        value_D_rB->setObjectName(QStringLiteral("value_D_rB"));
        value_D_rB->setGeometry(QRect(179, 217, 51, 28));
        value_D_rB->setFont(font2);
        value_D_rB->setLayoutDirection(Qt::RightToLeft);
        value_D_rB->setFrameShadow(QFrame::Plain);
        value_D_rB->setLineWidth(0);
        value_D_rB->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_D_rB->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_D_valC = new QLabel(centralWidget);
        text_D_valC->setObjectName(QStringLiteral("text_D_valC"));
        text_D_valC->setGeometry(QRect(132, 251, 91, 21));
        text_D_valC->setFont(font1);
        value_D_valC = new QTextBrowser(centralWidget);
        value_D_valC->setObjectName(QStringLiteral("value_D_valC"));
        value_D_valC->setGeometry(QRect(132, 281, 101, 28));
        value_D_valC->setFont(font2);
        value_D_valC->setLayoutDirection(Qt::RightToLeft);
        value_D_valC->setFrameShadow(QFrame::Plain);
        value_D_valC->setLineWidth(0);
        value_D_valC->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_D_valC->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_D_valP = new QTextBrowser(centralWidget);
        value_D_valP->setObjectName(QStringLiteral("value_D_valP"));
        value_D_valP->setGeometry(QRect(132, 343, 101, 28));
        value_D_valP->setFont(font2);
        value_D_valP->setLayoutDirection(Qt::RightToLeft);
        value_D_valP->setFrameShadow(QFrame::Plain);
        value_D_valP->setLineWidth(0);
        value_D_valP->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_D_valP->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_D_valP = new QLabel(centralWidget);
        text_D_valP->setObjectName(QStringLiteral("text_D_valP"));
        text_D_valP->setGeometry(QRect(132, 313, 91, 21));
        text_D_valP->setFont(font1);
        value_E_valC = new QTextBrowser(centralWidget);
        value_E_valC->setObjectName(QStringLiteral("value_E_valC"));
        value_E_valC->setGeometry(QRect(274, 193, 101, 28));
        value_E_valC->setFont(font2);
        value_E_valC->setLayoutDirection(Qt::RightToLeft);
        value_E_valC->setFrameShadow(QFrame::Plain);
        value_E_valC->setLineWidth(0);
        value_E_valC->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_E_valC->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_E_valC = new QLabel(centralWidget);
        text_E_valC->setObjectName(QStringLiteral("text_E_valC"));
        text_E_valC->setGeometry(QRect(274, 163, 91, 21));
        text_E_valC->setFont(font1);
        value_E_valA = new QTextBrowser(centralWidget);
        value_E_valA->setObjectName(QStringLiteral("value_E_valA"));
        value_E_valA->setGeometry(QRect(273, 258, 101, 28));
        value_E_valA->setFont(font2);
        value_E_valA->setLayoutDirection(Qt::RightToLeft);
        value_E_valA->setFrameShadow(QFrame::Plain);
        value_E_valA->setLineWidth(0);
        value_E_valA->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_E_valA->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_E_valA = new QLabel(centralWidget);
        text_E_valA->setObjectName(QStringLiteral("text_E_valA"));
        text_E_valA->setGeometry(QRect(273, 228, 91, 21));
        text_E_valA->setFont(font1);
        text_E_valB = new QLabel(centralWidget);
        text_E_valB->setObjectName(QStringLiteral("text_E_valB"));
        text_E_valB->setGeometry(QRect(274, 293, 91, 21));
        text_E_valB->setFont(font1);
        value_E_valB = new QTextBrowser(centralWidget);
        value_E_valB->setObjectName(QStringLiteral("value_E_valB"));
        value_E_valB->setGeometry(QRect(274, 323, 101, 28));
        value_E_valB->setFont(font2);
        value_E_valB->setLayoutDirection(Qt::RightToLeft);
        value_E_valB->setFrameShadow(QFrame::Plain);
        value_E_valB->setLineWidth(0);
        value_E_valB->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_E_valB->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_E_dstE = new QLabel(centralWidget);
        text_E_dstE->setObjectName(QStringLiteral("text_E_dstE"));
        text_E_dstE->setGeometry(QRect(277, 360, 31, 21));
        text_E_dstE->setFont(font1);
        text_E_dstM = new QLabel(centralWidget);
        text_E_dstM->setObjectName(QStringLiteral("text_E_dstM"));
        text_E_dstM->setGeometry(QRect(270, 388, 41, 31));
        text_E_dstM->setFont(font1);
        value_E_dstM = new QTextBrowser(centralWidget);
        value_E_dstM->setObjectName(QStringLiteral("value_E_dstM"));
        value_E_dstM->setGeometry(QRect(315, 392, 51, 28));
        value_E_dstM->setFont(font2);
        value_E_dstM->setLayoutDirection(Qt::RightToLeft);
        value_E_dstM->setFrameShadow(QFrame::Plain);
        value_E_dstM->setLineWidth(0);
        value_E_dstM->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_E_dstM->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_E_dstE = new QTextBrowser(centralWidget);
        value_E_dstE->setObjectName(QStringLiteral("value_E_dstE"));
        value_E_dstE->setGeometry(QRect(315, 358, 51, 28));
        value_E_dstE->setFont(font2);
        value_E_dstE->setLayoutDirection(Qt::RightToLeft);
        value_E_dstE->setFrameShadow(QFrame::Plain);
        value_E_dstE->setLineWidth(0);
        value_E_dstE->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_E_dstE->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_E_srcA = new QTextBrowser(centralWidget);
        value_E_srcA->setObjectName(QStringLiteral("value_E_srcA"));
        value_E_srcA->setGeometry(QRect(315, 426, 51, 28));
        value_E_srcA->setFont(font2);
        value_E_srcA->setLayoutDirection(Qt::RightToLeft);
        value_E_srcA->setFrameShadow(QFrame::Plain);
        value_E_srcA->setLineWidth(0);
        value_E_srcA->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_E_srcA->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_E_srcA = new QLabel(centralWidget);
        text_E_srcA->setObjectName(QStringLiteral("text_E_srcA"));
        text_E_srcA->setGeometry(QRect(274, 422, 41, 31));
        text_E_srcA->setFont(font1);
        text_E_srcB = new QLabel(centralWidget);
        text_E_srcB->setObjectName(QStringLiteral("text_E_srcB"));
        text_E_srcB->setGeometry(QRect(275, 456, 41, 31));
        text_E_srcB->setFont(font1);
        value_E_srcB = new QTextBrowser(centralWidget);
        value_E_srcB->setObjectName(QStringLiteral("value_E_srcB"));
        value_E_srcB->setGeometry(QRect(315, 460, 51, 28));
        value_E_srcB->setFont(font2);
        value_E_srcB->setLayoutDirection(Qt::RightToLeft);
        value_E_srcB->setFrameShadow(QFrame::Plain);
        value_E_srcB->setLineWidth(0);
        value_E_srcB->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_E_srcB->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_M_valE = new QTextBrowser(centralWidget);
        value_M_valE->setObjectName(QStringLiteral("value_M_valE"));
        value_M_valE->setGeometry(QRect(415, 193, 101, 28));
        value_M_valE->setFont(font2);
        value_M_valE->setLayoutDirection(Qt::RightToLeft);
        value_M_valE->setFrameShadow(QFrame::Plain);
        value_M_valE->setLineWidth(0);
        value_M_valE->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_M_valE->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_M_valE = new QLabel(centralWidget);
        text_M_valE->setObjectName(QStringLiteral("text_M_valE"));
        text_M_valE->setGeometry(QRect(415, 163, 91, 21));
        text_M_valE->setFont(font1);
        text_M_valA = new QLabel(centralWidget);
        text_M_valA->setObjectName(QStringLiteral("text_M_valA"));
        text_M_valA->setGeometry(QRect(414, 228, 91, 21));
        text_M_valA->setFont(font1);
        value_M_valA = new QTextBrowser(centralWidget);
        value_M_valA->setObjectName(QStringLiteral("value_M_valA"));
        value_M_valA->setGeometry(QRect(414, 258, 101, 28));
        value_M_valA->setFont(font2);
        value_M_valA->setLayoutDirection(Qt::RightToLeft);
        value_M_valA->setFrameShadow(QFrame::Plain);
        value_M_valA->setLineWidth(0);
        value_M_valA->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_M_valA->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_M_dstM = new QLabel(centralWidget);
        text_M_dstM->setObjectName(QStringLiteral("text_M_dstM"));
        text_M_dstM->setGeometry(QRect(415, 336, 41, 31));
        text_M_dstM->setFont(font1);
        text_M_dstE = new QLabel(centralWidget);
        text_M_dstE->setObjectName(QStringLiteral("text_M_dstE"));
        text_M_dstE->setGeometry(QRect(422, 301, 31, 21));
        text_M_dstE->setFont(font1);
        value_M_dstM = new QTextBrowser(centralWidget);
        value_M_dstM->setObjectName(QStringLiteral("value_M_dstM"));
        value_M_dstM->setGeometry(QRect(460, 340, 51, 28));
        value_M_dstM->setFont(font2);
        value_M_dstM->setLayoutDirection(Qt::RightToLeft);
        value_M_dstM->setFrameShadow(QFrame::Plain);
        value_M_dstM->setLineWidth(0);
        value_M_dstM->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_M_dstM->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_M_dstE = new QTextBrowser(centralWidget);
        value_M_dstE->setObjectName(QStringLiteral("value_M_dstE"));
        value_M_dstE->setGeometry(QRect(460, 299, 51, 28));
        value_M_dstE->setFont(font2);
        value_M_dstE->setLayoutDirection(Qt::RightToLeft);
        value_M_dstE->setFrameShadow(QFrame::Plain);
        value_M_dstE->setLineWidth(0);
        value_M_dstE->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_M_dstE->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_W_valM = new QTextBrowser(centralWidget);
        value_W_valM->setObjectName(QStringLiteral("value_W_valM"));
        value_W_valM->setGeometry(QRect(552, 230, 101, 28));
        value_W_valM->setFont(font2);
        value_W_valM->setLayoutDirection(Qt::RightToLeft);
        value_W_valM->setFrameShadow(QFrame::Plain);
        value_W_valM->setLineWidth(0);
        value_W_valM->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_W_valM->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_W_dstE = new QTextBrowser(centralWidget);
        value_W_dstE->setObjectName(QStringLiteral("value_W_dstE"));
        value_W_dstE->setGeometry(QRect(596, 271, 41, 28));
        value_W_dstE->setFont(font2);
        value_W_dstE->setLayoutDirection(Qt::RightToLeft);
        value_W_dstE->setFrameShadow(QFrame::Plain);
        value_W_dstE->setLineWidth(0);
        value_W_dstE->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_W_dstE->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_W_dstE = new QLabel(centralWidget);
        text_W_dstE->setObjectName(QStringLiteral("text_W_dstE"));
        text_W_dstE->setGeometry(QRect(558, 273, 31, 21));
        text_W_dstE->setFont(font1);
        value_W_valE = new QTextBrowser(centralWidget);
        value_W_valE->setObjectName(QStringLiteral("value_W_valE"));
        value_W_valE->setGeometry(QRect(553, 165, 101, 28));
        value_W_valE->setFont(font2);
        value_W_valE->setLayoutDirection(Qt::RightToLeft);
        value_W_valE->setFrameShadow(QFrame::Plain);
        value_W_valE->setLineWidth(0);
        value_W_valE->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_W_valE->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_W_dstM = new QLabel(centralWidget);
        text_W_dstM->setObjectName(QStringLiteral("text_W_dstM"));
        text_W_dstM->setGeometry(QRect(551, 308, 41, 31));
        text_W_dstM->setFont(font1);
        text_W_valE = new QLabel(centralWidget);
        text_W_valE->setObjectName(QStringLiteral("text_W_valE"));
        text_W_valE->setGeometry(QRect(553, 135, 91, 21));
        text_W_valE->setFont(font1);
        value_W_dstM = new QTextBrowser(centralWidget);
        value_W_dstM->setObjectName(QStringLiteral("value_W_dstM"));
        value_W_dstM->setGeometry(QRect(596, 312, 41, 28));
        value_W_dstM->setFont(font2);
        value_W_dstM->setLayoutDirection(Qt::RightToLeft);
        value_W_dstM->setFrameShadow(QFrame::Plain);
        value_W_dstM->setLineWidth(0);
        value_W_dstM->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_W_dstM->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_W_valM = new QLabel(centralWidget);
        text_W_valM->setObjectName(QStringLiteral("text_W_valM"));
        text_W_valM->setGeometry(QRect(552, 200, 91, 21));
        text_W_valM->setFont(font1);
        cycleSpinBox = new QSpinBox(centralWidget);
        cycleSpinBox->setObjectName(QStringLiteral("cycleSpinBox"));
        cycleSpinBox->setGeometry(QRect(421, 485, 251, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\343\201\277\343\201\213\343\201\241\343\202\203\343\202\223"));
        font3.setPointSize(18);
        cycleSpinBox->setFont(font3);
        cycleSpinBox->setStyleSheet(QStringLiteral(""));
        cycleSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cycleSpinBox->setMaximum(0);
        y86simClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(y86simClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 24));
        menuBar->setAutoFillBackground(true);
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_View = new QMenu(menuBar);
        menu_View->setObjectName(QStringLiteral("menu_View"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        y86simClass->setMenuBar(menuBar);
        dockWidget = new QDockWidget(y86simClass);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setMinimumSize(QSize(80, 526));
        dockWidget->setMaximumSize(QSize(80, 526));
        QFont font4;
        font4.setFamily(QStringLiteral("Segoe UI"));
        font4.setPointSize(7);
        dockWidget->setFont(font4);
        dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        text_eax = new QLabel(dockWidgetContents);
        text_eax->setObjectName(QStringLiteral("text_eax"));
        text_eax->setGeometry(QRect(10, -10, 70, 71));
        QFont font5;
        font5.setFamily(QStringLiteral("Segoe UI"));
        font5.setPointSize(12);
        font5.setBold(false);
        font5.setWeight(50);
        text_eax->setFont(font5);
        text_ebx = new QLabel(dockWidgetContents);
        text_ebx->setObjectName(QStringLiteral("text_ebx"));
        text_ebx->setGeometry(QRect(10, 40, 81, 71));
        text_ebx->setFont(font5);
        text_ecx = new QLabel(dockWidgetContents);
        text_ecx->setObjectName(QStringLiteral("text_ecx"));
        text_ecx->setGeometry(QRect(10, 90, 81, 71));
        text_ecx->setFont(font5);
        text_edx = new QLabel(dockWidgetContents);
        text_edx->setObjectName(QStringLiteral("text_edx"));
        text_edx->setGeometry(QRect(10, 140, 81, 71));
        text_edx->setFont(font5);
        text_esp = new QLabel(dockWidgetContents);
        text_esp->setObjectName(QStringLiteral("text_esp"));
        text_esp->setGeometry(QRect(10, 190, 70, 71));
        text_esp->setFont(font5);
        text_ebp = new QLabel(dockWidgetContents);
        text_ebp->setObjectName(QStringLiteral("text_ebp"));
        text_ebp->setGeometry(QRect(10, 240, 70, 71));
        text_ebp->setFont(font5);
        text_esi = new QLabel(dockWidgetContents);
        text_esi->setObjectName(QStringLiteral("text_esi"));
        text_esi->setGeometry(QRect(10, 290, 70, 71));
        text_esi->setFont(font5);
        text_edi = new QLabel(dockWidgetContents);
        text_edi->setObjectName(QStringLiteral("text_edi"));
        text_edi->setGeometry(QRect(10, 340, 70, 71));
        text_edi->setFont(font5);
        value_eax = new QTextBrowser(dockWidgetContents);
        value_eax->setObjectName(QStringLiteral("value_eax"));
        value_eax->setGeometry(QRect(6, 40, 71, 21));
        value_eax->setLayoutDirection(Qt::RightToLeft);
        value_eax->setFrameShadow(QFrame::Plain);
        value_eax->setLineWidth(0);
        value_eax->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_eax->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_ebx = new QTextBrowser(dockWidgetContents);
        value_ebx->setObjectName(QStringLiteral("value_ebx"));
        value_ebx->setGeometry(QRect(6, 90, 71, 21));
        value_ebx->setLayoutDirection(Qt::RightToLeft);
        value_ebx->setFrameShadow(QFrame::Plain);
        value_ebx->setLineWidth(0);
        value_ebx->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_ebx->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_ecx = new QTextBrowser(dockWidgetContents);
        value_ecx->setObjectName(QStringLiteral("value_ecx"));
        value_ecx->setGeometry(QRect(6, 140, 71, 21));
        value_ecx->setLayoutDirection(Qt::RightToLeft);
        value_ecx->setFrameShadow(QFrame::Plain);
        value_ecx->setLineWidth(0);
        value_ecx->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_ecx->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_edx = new QTextBrowser(dockWidgetContents);
        value_edx->setObjectName(QStringLiteral("value_edx"));
        value_edx->setGeometry(QRect(6, 190, 71, 21));
        value_edx->setLayoutDirection(Qt::RightToLeft);
        value_edx->setFrameShadow(QFrame::Plain);
        value_edx->setLineWidth(0);
        value_edx->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_edx->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_esp = new QTextBrowser(dockWidgetContents);
        value_esp->setObjectName(QStringLiteral("value_esp"));
        value_esp->setGeometry(QRect(6, 240, 71, 21));
        value_esp->setLayoutDirection(Qt::RightToLeft);
        value_esp->setFrameShadow(QFrame::Plain);
        value_esp->setLineWidth(0);
        value_esp->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_esp->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_ebp = new QTextBrowser(dockWidgetContents);
        value_ebp->setObjectName(QStringLiteral("value_ebp"));
        value_ebp->setGeometry(QRect(6, 290, 71, 21));
        value_ebp->setLayoutDirection(Qt::RightToLeft);
        value_ebp->setFrameShadow(QFrame::Plain);
        value_ebp->setLineWidth(0);
        value_ebp->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_ebp->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_esi = new QTextBrowser(dockWidgetContents);
        value_esi->setObjectName(QStringLiteral("value_esi"));
        value_esi->setGeometry(QRect(6, 340, 71, 21));
        value_esi->setLayoutDirection(Qt::RightToLeft);
        value_esi->setFrameShadow(QFrame::Plain);
        value_esi->setLineWidth(0);
        value_esi->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_esi->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_edi = new QTextBrowser(dockWidgetContents);
        value_edi->setObjectName(QStringLiteral("value_edi"));
        value_edi->setGeometry(QRect(6, 390, 71, 21));
        value_edi->setLayoutDirection(Qt::RightToLeft);
        value_edi->setFrameShadow(QFrame::Plain);
        value_edi->setLineWidth(0);
        value_edi->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_edi->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_ZF = new QLabel(dockWidgetContents);
        text_ZF->setObjectName(QStringLiteral("text_ZF"));
        text_ZF->setGeometry(QRect(9, 420, 50, 21));
        QFont font6;
        font6.setPointSize(9);
        text_ZF->setFont(font6);
        text_SF = new QLabel(dockWidgetContents);
        text_SF->setObjectName(QStringLiteral("text_SF"));
        text_SF->setGeometry(QRect(10, 440, 50, 21));
        text_SF->setFont(font6);
        text_OF = new QLabel(dockWidgetContents);
        text_OF->setObjectName(QStringLiteral("text_OF"));
        text_OF->setGeometry(QRect(7, 460, 50, 21));
        text_OF->setFont(font6);
        value_ZF = new QTextBrowser(dockWidgetContents);
        value_ZF->setObjectName(QStringLiteral("value_ZF"));
        value_ZF->setGeometry(QRect(40, 420, 16, 21));
        value_ZF->setLayoutDirection(Qt::RightToLeft);
        value_ZF->setFrameShadow(QFrame::Plain);
        value_ZF->setLineWidth(0);
        value_ZF->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_ZF->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_SF = new QTextBrowser(dockWidgetContents);
        value_SF->setObjectName(QStringLiteral("value_SF"));
        value_SF->setGeometry(QRect(40, 440, 16, 21));
        value_SF->setLayoutDirection(Qt::RightToLeft);
        value_SF->setFrameShadow(QFrame::Plain);
        value_SF->setLineWidth(0);
        value_SF->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_SF->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_OF = new QTextBrowser(dockWidgetContents);
        value_OF->setObjectName(QStringLiteral("value_OF"));
        value_OF->setGeometry(QRect(40, 460, 16, 21));
        value_OF->setLayoutDirection(Qt::RightToLeft);
        value_OF->setFrameShadow(QFrame::Plain);
        value_OF->setLineWidth(0);
        value_OF->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        value_OF->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        dockWidget->setWidget(dockWidgetContents);
        y86simClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        mainToolBar = new QToolBar(y86simClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy1);
        mainToolBar->setIconSize(QSize(16, 16));
        y86simClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_View->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_File->addAction(action_Open);
        menu_File->addAction(action_Compile);
        menu_File->addAction(action_Compile_use_yas);
        menu_File->addAction(action_Save_Log);
        menu_View->addAction(action_Source_Code);
        menu_View->addAction(action_Register_and_CC);
        menu_View->addAction(action_Memory_Watcher);
        menu_Help->addAction(action_About);
        mainToolBar->addAction(action_GotoStart);
        mainToolBar->addAction(action_Backward);
        mainToolBar->addAction(action_Play);
        mainToolBar->addAction(action_Stop);
        mainToolBar->addAction(action_Forward);
        mainToolBar->addAction(action_GotoEnd);

        retranslateUi(y86simClass);

        QMetaObject::connectSlotsByName(y86simClass);
    } // setupUi

    void retranslateUi(QMainWindow *y86simClass)
    {
        y86simClass->setWindowTitle(QApplication::translate("y86simClass", "Simy86", 0));
        action_Open->setText(QApplication::translate("y86simClass", "&Open", 0));
        action_Play->setText(QApplication::translate("y86simClass", "play", 0));
#ifndef QT_NO_TOOLTIP
        action_Play->setToolTip(QApplication::translate("y86simClass", "Run/Pause", 0));
#endif // QT_NO_TOOLTIP
        action_Stop->setText(QApplication::translate("y86simClass", "stop", 0));
#ifndef QT_NO_TOOLTIP
        action_Stop->setToolTip(QApplication::translate("y86simClass", "Reset", 0));
#endif // QT_NO_TOOLTIP
        action_Forward->setText(QApplication::translate("y86simClass", "forward", 0));
#ifndef QT_NO_TOOLTIP
        action_Forward->setToolTip(QApplication::translate("y86simClass", "Next Cycle", 0));
#endif // QT_NO_TOOLTIP
        action_Backward->setText(QApplication::translate("y86simClass", "backward", 0));
#ifndef QT_NO_TOOLTIP
        action_Backward->setToolTip(QApplication::translate("y86simClass", "Previous Cycle", 0));
#endif // QT_NO_TOOLTIP
        action_GotoStart->setText(QApplication::translate("y86simClass", "gotoStart", 0));
#ifndef QT_NO_TOOLTIP
        action_GotoStart->setToolTip(QApplication::translate("y86simClass", "Goto Start", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        action_GotoStart->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        action_GotoEnd->setText(QApplication::translate("y86simClass", "gotoEnd", 0));
#ifndef QT_NO_TOOLTIP
        action_GotoEnd->setToolTip(QApplication::translate("y86simClass", "Goto End", 0));
#endif // QT_NO_TOOLTIP
        action_Compile->setText(QApplication::translate("y86simClass", "&Compile (use simyas)", 0));
        action_Register_and_CC->setText(QApplication::translate("y86simClass", "&Register and CC", 0));
        action_Memory_Watcher->setText(QApplication::translate("y86simClass", "&Memory Watcher", 0));
        action_Source_Code->setText(QApplication::translate("y86simClass", "&Source Code", 0));
        action_Save_Log->setText(QApplication::translate("y86simClass", "&Save Log", 0));
        action_About->setText(QApplication::translate("y86simClass", "&About", 0));
        action_Compile_use_yas->setText(QApplication::translate("y86simClass", "Compile (use yas)", 0));
        mainbg->setText(QString());
        textFetch->setText(QApplication::translate("y86simClass", "Fetch", 0));
        textDecode->setText(QApplication::translate("y86simClass", "Decode", 0));
        textExecute->setText(QApplication::translate("y86simClass", "Execute", 0));
        textMemory->setText(QApplication::translate("y86simClass", "Memory", 0));
        textWriteback->setText(QApplication::translate("y86simClass", "Writeback", 0));
        text_PredPC->setText(QApplication::translate("y86simClass", "predPC:", 0));
        value_PredPC->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0x00000000</p></body></html>", 0));
        text_E_stat->setText(QApplication::translate("y86simClass", "stat:", 0));
        value_E_stat->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">BUB</p></body></html>", 0));
        text_M_stat->setText(QApplication::translate("y86simClass", "stat:", 0));
        value_M_stat->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">BUB</p></body></html>", 0));
        value_W_stat->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">BUB</p></body></html>", 0));
        text_W_stat->setText(QApplication::translate("y86simClass", "stat:", 0));
        value_D_stat->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">BUB</p></body></html>", 0));
        text_D_stat->setText(QApplication::translate("y86simClass", "stat:", 0));
        text_D_icode->setText(QApplication::translate("y86simClass", "icode:", 0));
        value_D_icode->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">NOP</p></body></html>", 0));
        text_E_icode->setText(QApplication::translate("y86simClass", "icode:", 0));
        value_E_icode->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">NOP</p></body></html>", 0));
        text_M_icode->setText(QApplication::translate("y86simClass", "icode:", 0));
        value_M_icode->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">NOP</p></body></html>", 0));
        text_W_icode->setText(QApplication::translate("y86simClass", "icode:", 0));
        value_W_icode->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">NOP</p></body></html>", 0));
        text_D_ifun->setText(QApplication::translate("y86simClass", "ifun:", 0));
        value_D_ifun->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">---</p></body></html>", 0));
        text_E_ifun->setText(QApplication::translate("y86simClass", "ifun:", 0));
        value_E_ifun->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">---</p></body></html>", 0));
        text_M_Cnd->setText(QApplication::translate("y86simClass", "Cnd:", 0));
        value_M_cnd->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1</p></body></html>", 0));
        value_D_rA->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">---</p></body></html>", 0));
        text_D_rA->setText(QApplication::translate("y86simClass", "rA:", 0));
        text_D_rB->setText(QApplication::translate("y86simClass", "rB:", 0));
        value_D_rB->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">---</p></body></html>", 0));
        text_D_valC->setText(QApplication::translate("y86simClass", "valC:", 0));
        value_D_valC->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0x00000000</p></body></html>", 0));
        value_D_valP->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0x00000000</p></body></html>", 0));
        text_D_valP->setText(QApplication::translate("y86simClass", "valP:", 0));
        value_E_valC->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0x00000000</p></body></html>", 0));
        text_E_valC->setText(QApplication::translate("y86simClass", "valC:", 0));
        value_E_valA->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0x00000000</p></body></html>", 0));
        text_E_valA->setText(QApplication::translate("y86simClass", "valA:", 0));
        text_E_valB->setText(QApplication::translate("y86simClass", "valB:", 0));
        value_E_valB->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0x00000000</p></body></html>", 0));
        text_E_dstE->setText(QApplication::translate("y86simClass", "dstE::", 0));
        text_E_dstM->setText(QApplication::translate("y86simClass", "dstM:", 0));
        value_E_dstM->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">---</p></body></html>", 0));
        value_E_dstE->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">---</p></body></html>", 0));
        value_E_srcA->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">---</p></body></html>", 0));
        text_E_srcA->setText(QApplication::translate("y86simClass", "srcA:", 0));
        text_E_srcB->setText(QApplication::translate("y86simClass", "srcB:", 0));
        value_E_srcB->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">---</p></body></html>", 0));
        value_M_valE->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0x00000000</p></body></html>", 0));
        text_M_valE->setText(QApplication::translate("y86simClass", "valE:", 0));
        text_M_valA->setText(QApplication::translate("y86simClass", "valA:", 0));
        value_M_valA->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0x00000000</p></body></html>", 0));
        text_M_dstM->setText(QApplication::translate("y86simClass", "dstM:", 0));
        text_M_dstE->setText(QApplication::translate("y86simClass", "dstE::", 0));
        value_M_dstM->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">---</p></body></html>", 0));
        value_M_dstE->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">---</p></body></html>", 0));
        value_W_valM->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0x00000000</p></body></html>", 0));
        value_W_dstE->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">---</p></body></html>", 0));
        text_W_dstE->setText(QApplication::translate("y86simClass", "dstE::", 0));
        value_W_valE->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0x00000000</p></body></html>", 0));
        text_W_dstM->setText(QApplication::translate("y86simClass", "dstM:", 0));
        text_W_valE->setText(QApplication::translate("y86simClass", "valE:", 0));
        value_W_dstM->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">---</p></body></html>", 0));
        text_W_valM->setText(QApplication::translate("y86simClass", "valM:", 0));
        cycleSpinBox->setSuffix(QApplication::translate("y86simClass", "/0", 0));
        menu_File->setTitle(QApplication::translate("y86simClass", "&File", 0));
        menu_View->setTitle(QApplication::translate("y86simClass", "&View", 0));
        menu_Help->setTitle(QApplication::translate("y86simClass", "&Help", 0));
        dockWidget->setWindowTitle(QApplication::translate("y86simClass", "Reg&CC", 0));
        text_eax->setText(QApplication::translate("y86simClass", "%eax :", 0));
        text_ebx->setText(QApplication::translate("y86simClass", "%ebx :", 0));
        text_ecx->setText(QApplication::translate("y86simClass", "%ecx :", 0));
        text_edx->setText(QApplication::translate("y86simClass", "%edx :", 0));
        text_esp->setText(QApplication::translate("y86simClass", "%esp :", 0));
        text_ebp->setText(QApplication::translate("y86simClass", "%ebp", 0));
        text_esi->setText(QApplication::translate("y86simClass", "%esi :", 0));
        text_edi->setText(QApplication::translate("y86simClass", "%edi :", 0));
        value_eax->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:7pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0x00000000</p></body></html>", 0));
        value_ebx->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:7pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0x00000000</p></body></html>", 0));
        value_ecx->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:7pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0x00000000</p></body></html>", 0));
        value_edx->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:7pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0x00000000</p></body></html>", 0));
        value_esp->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:7pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0x00000000</p></body></html>", 0));
        value_ebp->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:7pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0x00000000</p></body></html>", 0));
        value_esi->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:7pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0x00000000</p></body></html>", 0));
        value_edi->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:7pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0x00000000</p></body></html>", 0));
        text_ZF->setText(QApplication::translate("y86simClass", "ZF :", 0));
        text_SF->setText(QApplication::translate("y86simClass", "SF :", 0));
        text_OF->setText(QApplication::translate("y86simClass", "OF :", 0));
        value_ZF->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:7pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        value_SF->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:7pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        value_OF->setHtml(QApplication::translate("y86simClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:7pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        mainToolBar->setWindowTitle(QApplication::translate("y86simClass", "Control Bar", 0));
    } // retranslateUi

};

namespace Ui {
    class y86simClass: public Ui_y86simClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_Y86SIM_H
