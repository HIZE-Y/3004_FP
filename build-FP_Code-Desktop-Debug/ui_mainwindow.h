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
    QProgressBar *counter;
    QLabel *label_3;
    QPushButton *power;
    QPushButton *Disconnect;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *lightIndicatorRed;
    QLabel *lightIndicatorBlue;
    QLabel *lightIndicatorGreen;
    QPushButton *clearHistory;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 541);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #1a1a1a; /* Dark charcoal, adds depth and focus to other elements */\n"
"}\n"
"\n"
"\n"
"QWidget {\n"
"    color: white;\n"
"    font: bold 10pt \"Arial\";\n"
"}\n"
"\n"
"QPushButton, QFrame, QProgressBar, QDateTimeEdit, QTextBrowser {\n"
"    border: 2px solid green;\n"
"    border-radius: 10px;\n"
"    background-color: #333333; /* Dark grey for slightly lighter contrast against main window */\n"
"}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(70, 20, 701, 451));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: black;     /* Sets the background to black */\n"
"    border: 3px solid green;     /* Sets the border color to green and width to 3px */\n"
"    border-radius: 10px;         /* Optional: Adds rounded corners with a radius of 10px */\n"
"}\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Start = new QPushButton(frame);
        Start->setObjectName(QString::fromUtf8("Start"));
        Start->setGeometry(QRect(110, 140, 83, 25));
        Start->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;                      /* White text color */\n"
"    background-color: #333333;         /* Dark grey background, slightly lighter than black for contrast */\n"
"    border: 2px solid green;           /* Green border */\n"
"    border-radius: 10px;               /* Rounded corners */\n"
"    padding: 5px;                      /* Padding for better text display */\n"
"    font-weight: bold;                 /* Bold text font */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: green;           /* Change background to green on hover */\n"
"    color: black;                      /* Change text color to black on hover */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #005500;         /* Darker green when pressed */\n"
"    color: white;                      /* White text color when pressed */\n"
"}\n"
""));
        log = new QPushButton(frame);
        log->setObjectName(QString::fromUtf8("log"));
        log->setGeometry(QRect(110, 180, 83, 31));
        log->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;                      /* White text color */\n"
"    background-color: #333333;         /* Dark grey background, slightly lighter than black for contrast */\n"
"    border: 2px solid green;           /* Green border */\n"
"    border-radius: 10px;               /* Rounded corners */\n"
"    padding: 5px;                      /* Padding for better text display */\n"
"    font-weight: bold;                 /* Bold text font */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: green;           /* Change background to green on hover */\n"
"    color: black;                      /* Change text color to black on hover */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #005500;         /* Darker green when pressed */\n"
"    color: white;                      /* White text color when pressed */\n"
"}\n"
""));
        Battery = new QProgressBar(frame);
        Battery->setObjectName(QString::fromUtf8("Battery"));
        Battery->setGeometry(QRect(17, 10, 131, 23));
        Battery->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    border: 2px solid green;           /* Green border */\n"
"    border-radius: 5px;                /* Rounded corners */\n"
"    background-color: black;           /* Black background for the entire progress bar */\n"
"}\n"
"QProgressBar::chunk {\n"
"    background-color: green;           /* Green color for the progress chunk */\n"
"    width: 20px;                       /* Width of the chunk segments */\n"
"}\n"
""));
        Battery->setValue(24);
        dateTimeEdit = new QDateTimeEdit(frame);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(200, 180, 201, 31));
        dateTimeEdit->setStyleSheet(QString::fromUtf8("QDateTimeEdit {\n"
"    color: white;                      /* White text color for readability */\n"
"    background-color: #333333;         /* Dark grey background, lighter than black for contrast */\n"
"    border: 2px solid green;           /* Solid green border */\n"
"    border-radius: 8px;                /* Rounded corners */\n"
"    padding: 5px;                      /* Padding around the text */\n"
"    font-weight: bold;                 /* Bold text for better visibility */\n"
"}\n"
"QDateTimeEdit::drop-down {\n"
"    subcontrol-origin: padding;        /* Align the drop-down button */\n"
"    subcontrol-position: top right;    /* Position to the top right */\n"
"    width: 30px;                       /* Width of the drop-down button */\n"
"    border-left: 1px solid green;      /* Border to separate from the edit area */\n"
"}\n"
"QDateTimeEdit::down-arrow {\n"
"    image: url(:/icons/down-arrow.png); /* Custom image for the arrow */\n"
"    width: 16px;                       /* Width of the arrow */\n"
""
                        "    height: 16px;                      /* Height of the arrow */\n"
"}\n"
""));
        Pause = new QPushButton(frame);
        Pause->setObjectName(QString::fromUtf8("Pause"));
        Pause->setGeometry(QRect(210, 140, 83, 25));
        Pause->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;                      /* White text color */\n"
"    background-color: #333333;         /* Dark grey background, slightly lighter than black for contrast */\n"
"    border: 2px solid green;           /* Green border */\n"
"    border-radius: 10px;               /* Rounded corners */\n"
"    padding: 5px;                      /* Padding for better text display */\n"
"    font-weight: bold;                 /* Bold text font */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: green;           /* Change background to green on hover */\n"
"    color: black;                      /* Change text color to black on hover */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #005500;         /* Darker green when pressed */\n"
"    color: white;                      /* White text color when pressed */\n"
"}\n"
""));
        stopButton = new QPushButton(frame);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(400, 140, 83, 25));
        stopButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;                      /* White text color */\n"
"    background-color: #333333;         /* Dark grey background, slightly lighter than black for contrast */\n"
"    border: 2px solid green;           /* Green border */\n"
"    border-radius: 10px;               /* Rounded corners */\n"
"    padding: 5px;                      /* Padding for better text display */\n"
"    font-weight: bold;                 /* Bold text font */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: green;           /* Change background to green on hover */\n"
"    color: black;                      /* Change text color to black on hover */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #005500;         /* Darker green when pressed */\n"
"    color: white;                      /* White text color when pressed */\n"
"}\n"
""));
        Resume = new QPushButton(frame);
        Resume->setObjectName(QString::fromUtf8("Resume"));
        Resume->setGeometry(QRect(310, 140, 83, 25));
        Resume->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;                      /* White text color */\n"
"    background-color: #333333;         /* Dark grey background, slightly lighter than black for contrast */\n"
"    border: 2px solid green;           /* Green border */\n"
"    border-radius: 10px;               /* Rounded corners */\n"
"    padding: 5px;                      /* Padding for better text display */\n"
"    font-weight: bold;                 /* Bold text font */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: green;           /* Change background to green on hover */\n"
"    color: black;                      /* Change text color to black on hover */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #005500;         /* Darker green when pressed */\n"
"    color: white;                      /* White text color when pressed */\n"
"}\n"
""));
        Histroylog = new QTextBrowser(frame);
        Histroylog->setObjectName(QString::fromUtf8("Histroylog"));
        Histroylog->setGeometry(QRect(10, 230, 381, 192));
        Histroylog->setStyleSheet(QString::fromUtf8("QTextBrowser {\n"
"    color: white;                      /* White text color for readability */\n"
"    background-color: #333333;         /* Dark grey background, lighter than black for contrast */\n"
"    border: 2px solid green;           /* Solid green border */\n"
"    border-radius: 8px;                /* Rounded corners for a smoother look */\n"
"    padding: 10px;                     /* Padding around the text for a better text display */\n"
"    font: bold 12pt \"Arial\";           /* Set a specific font and size for better readability */\n"
"}\n"
""));
        SessionPr = new QProgressBar(frame);
        SessionPr->setObjectName(QString::fromUtf8("SessionPr"));
        SessionPr->setGeometry(QRect(410, 280, 151, 23));
        SessionPr->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    border: 2px solid green;           /* Green border */\n"
"    border-radius: 5px;                /* Rounded corners */\n"
"    background-color: black;           /* Black background for the entire progress bar */\n"
"}\n"
"QProgressBar::chunk {\n"
"    background-color: green;           /* Green color for the progress chunk */\n"
"    width: 20px;                       /* Width of the chunk segments */\n"
"}\n"
""));
        SessionPr->setValue(24);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(410, 310, 151, 41));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f8f8ff;                  /* Creamy white text for a soft contrast */\n"
"    font: bold 11pt \"Times New Roman\"; /* A classic serif font */\n"
"    background-color: #282828;       /* Deep, dark gray background */\n"
"    border: 2px solid #8fbc8f;       /* Muted green border, a classic and soft shade */\n"
"    border-radius: 5px;              /* Softly rounded corners */\n"
"    padding: 10px;                   /* Ample padding around the text */\n"
"    text-align: center;              /* Center-align text */\n"
"\n"
"\n"
"\n"
"    /* Subtle gradient background for a touch of sophistication */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                                stop:0 #282828, stop:1 #3e3e3e);\n"
"}\n"
""));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 40, 101, 51));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f8f8ff;                  /* Creamy white text for a soft contrast */\n"
"    font: bold 14pt \"Times New Roman\"; /* A classic serif font */\n"
"    background-color: #282828;       /* Deep, dark gray background */\n"
"    border: 2px solid #8fbc8f;       /* Muted green border, a classic and soft shade */\n"
"    border-radius: 5px;              /* Softly rounded corners */\n"
"    padding: 10px;                   /* Ample padding around the text */\n"
"    text-align: center;              /* Center-align text */\n"
"\n"
"\n"
"\n"
"    /* Subtle gradient background for a touch of sophistication */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                                stop:0 #282828, stop:1 #3e3e3e);\n"
"}\n"
""));
        counter = new QProgressBar(frame);
        counter->setObjectName(QString::fromUtf8("counter"));
        counter->setGeometry(QRect(510, 10, 131, 23));
        counter->setValue(24);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(510, 40, 121, 51));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f8f8ff;                  /* Creamy white text for a soft contrast */\n"
"    font: bold 14pt \"Times New Roman\"; /* A classic serif font */\n"
"    background-color: #282828;       /* Deep, dark gray background */\n"
"    border: 2px solid #8fbc8f;       /* Muted green border, a classic and soft shade */\n"
"    border-radius: 5px;              /* Softly rounded corners */\n"
"    padding: 10px;                   /* Ample padding around the text */\n"
"    text-align: center;              /* Center-align text */\n"
"\n"
" \n"
"\n"
"    /* Subtle gradient background for a touch of sophistication */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                                stop:0 #282828, stop:1 #3e3e3e);\n"
"}\n"
""));
        power = new QPushButton(centralwidget);
        power->setObjectName(QString::fromUtf8("power"));
        power->setGeometry(QRect(780, 30, 121, 31));
        power->setStyleSheet(QString::fromUtf8("QPushButton:hover {\n"
"    background-color: green;           /* Change background to green on hover */\n"
"    color: black;                      /* Change text color to black on hover */\n"
"}"));
        Disconnect = new QPushButton(centralwidget);
        Disconnect->setObjectName(QString::fromUtf8("Disconnect"));
        Disconnect->setGeometry(QRect(790, 130, 83, 25));
        Disconnect->setStyleSheet(QString::fromUtf8("QPushButton:hover {\n"
"    background-color: green;           /* Change background to green on hover */\n"
"    color: black;                      /* Change text color to black on hover */\n"
"}"));
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

        clearHistory = new QPushButton(centralwidget);
        clearHistory->setObjectName(QString::fromUtf8("clearHistory"));
        clearHistory->setGeometry(QRect(790, 210, 83, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1024, 20));
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
        label_3->setText(QCoreApplication::translate("MainWindow", "Time Left", nullptr));
        power->setText(QCoreApplication::translate("MainWindow", "Power", nullptr));
        Disconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        lightIndicatorRed->setText(QString());
        lightIndicatorBlue->setText(QString());
        lightIndicatorGreen->setText(QString());
        clearHistory->setText(QCoreApplication::translate("MainWindow", "clearHistory", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
