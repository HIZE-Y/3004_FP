/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QPushButton *Start;
    QPushButton *log;
    QProgressBar *Battery;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *Pause;
    QPushButton *stopButton;
    QPushButton *pushButton_2;
    QTextBrowser *Histroylog;
    QProgressBar *SessionPr;
    QLabel *label;
    QLabel *label_2;
    QPushButton *power;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(942, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(70, 20, 701, 451));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Start = new QPushButton(frame);
        Start->setObjectName(QString::fromUtf8("Start"));
        Start->setGeometry(QRect(110, 140, 83, 25));
        log = new QPushButton(frame);
        log->setObjectName(QString::fromUtf8("log"));
        log->setGeometry(QRect(110, 180, 83, 25));
        Battery = new QProgressBar(frame);
        Battery->setObjectName(QString::fromUtf8("Battery"));
        Battery->setGeometry(QRect(30, 10, 118, 23));
        Battery->setValue(24);
        dateTimeEdit = new QDateTimeEdit(frame);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(340, 190, 194, 26));
        Pause = new QPushButton(frame);
        Pause->setObjectName(QString::fromUtf8("Pause"));
        Pause->setGeometry(QRect(210, 140, 83, 25));
        stopButton = new QPushButton(frame);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(400, 140, 83, 25));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 140, 83, 25));
        Histroylog = new QTextBrowser(frame);
        Histroylog->setObjectName(QString::fromUtf8("Histroylog"));
        Histroylog->setGeometry(QRect(20, 210, 256, 192));
        SessionPr = new QProgressBar(frame);
        SessionPr->setObjectName(QString::fromUtf8("SessionPr"));
        SessionPr->setGeometry(QRect(350, 280, 118, 23));
        SessionPr->setValue(24);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(350, 310, 121, 17));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 40, 62, 17));
        power = new QPushButton(centralwidget);
        power->setObjectName(QString::fromUtf8("power"));
        power->setGeometry(QRect(780, 30, 121, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 942, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        log->setText(QCoreApplication::translate("MainWindow", "Log", nullptr));
        Pause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Resume", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Session Progress", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Battery", nullptr));
        power->setText(QCoreApplication::translate("MainWindow", "Power", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
