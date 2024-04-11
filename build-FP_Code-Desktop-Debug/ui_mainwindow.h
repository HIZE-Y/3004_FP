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
#include <QtWidgets/QVBoxLayout>
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
    QPushButton *Resume;
    QTextBrowser *Histroylog;
    QProgressBar *SessionPr;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *power;
    QPushButton *Disconnect;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *lightIndicatorRed;
    QLabel *lightIndicatorBlue;
    QLabel *lightIndicatorGreen;
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
        Resume = new QPushButton(frame);
        Resume->setObjectName(QString::fromUtf8("Resume"));
        Resume->setGeometry(QRect(310, 140, 83, 25));
        Histroylog = new QTextBrowser(frame);
        Histroylog->setObjectName(QString::fromUtf8("Histroylog"));
        Histroylog->setGeometry(QRect(10, 220, 381, 192));
        SessionPr = new QProgressBar(frame);
        SessionPr->setObjectName(QString::fromUtf8("SessionPr"));
        SessionPr->setGeometry(QRect(410, 280, 118, 23));
        SessionPr->setValue(24);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(410, 310, 121, 17));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 40, 62, 17));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 20, 62, 17));
        power = new QPushButton(centralwidget);
        power->setObjectName(QString::fromUtf8("power"));
        power->setGeometry(QRect(780, 30, 121, 31));
        Disconnect = new QPushButton(centralwidget);
        Disconnect->setObjectName(QString::fromUtf8("Disconnect"));
        Disconnect->setGeometry(QRect(790, 130, 83, 25));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(780, 330, 160, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lightIndicatorRed = new QLabel(verticalLayoutWidget);
        lightIndicatorRed->setObjectName(QString::fromUtf8("lightIndicatorRed"));

        verticalLayout->addWidget(lightIndicatorRed);

        lightIndicatorBlue = new QLabel(verticalLayoutWidget);
        lightIndicatorBlue->setObjectName(QString::fromUtf8("lightIndicatorBlue"));

        verticalLayout->addWidget(lightIndicatorBlue);

        lightIndicatorGreen = new QLabel(verticalLayoutWidget);
        lightIndicatorGreen->setObjectName(QString::fromUtf8("lightIndicatorGreen"));

        verticalLayout->addWidget(lightIndicatorGreen);

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
        Resume->setText(QCoreApplication::translate("MainWindow", "Resume", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Session Progress", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Battery", nullptr));
        label_3->setText(QString());
        power->setText(QCoreApplication::translate("MainWindow", "Power", nullptr));
        Disconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        lightIndicatorRed->setText(QString());
        lightIndicatorBlue->setText(QString());
        lightIndicatorGreen->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
