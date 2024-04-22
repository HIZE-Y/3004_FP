/********************************************************************************
** Form generated from reading UI file 'graphwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHWINDOW_H
#define UI_GRAPHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QCustomPlot *wavePlot10;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QCustomPlot *wavePlot10_2;
    QLabel *label_5;
    QCustomPlot *wavePlot10_3;
    QLabel *label_7;
    QCustomPlot *wavePlot10_4;
    QLabel *label_9;
    QCustomPlot *wavePlot10_5;
    QLabel *label_4;
    QCustomPlot *wavePlot10_6;
    QLabel *label_8;
    QCustomPlot *wavePlot10_7;
    QLabel *label_6;
    QCustomPlot *treat;
    QLabel *label_10;
    QCustomPlot *treat_2;
    QLabel *label_12;
    QCustomPlot *treat_3;
    QLabel *label_13;
    QCustomPlot *treat_4;
    QLabel *label_15;
    QCustomPlot *treat_5;
    QLabel *label_17;
    QCustomPlot *treat_6;
    QLabel *label_18;
    QCustomPlot *treat_7;
    QLabel *label_20;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(1389, 1310);
        wavePlot10 = new QCustomPlot(Form);
        wavePlot10->setObjectName(QString::fromUtf8("wavePlot10"));
        wavePlot10->setGeometry(QRect(10, 60, 271, 161));
        label_3 = new QLabel(wavePlot10);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 10, 171, 20));
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 20, 141, 41));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(670, 30, 141, 41));
        wavePlot10_2 = new QCustomPlot(Form);
        wavePlot10_2->setObjectName(QString::fromUtf8("wavePlot10_2"));
        wavePlot10_2->setGeometry(QRect(10, 230, 271, 161));
        label_5 = new QLabel(wavePlot10_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(120, 10, 171, 20));
        wavePlot10_3 = new QCustomPlot(Form);
        wavePlot10_3->setObjectName(QString::fromUtf8("wavePlot10_3"));
        wavePlot10_3->setGeometry(QRect(10, 390, 271, 161));
        label_7 = new QLabel(wavePlot10_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(150, 10, 111, 20));
        wavePlot10_4 = new QCustomPlot(Form);
        wavePlot10_4->setObjectName(QString::fromUtf8("wavePlot10_4"));
        wavePlot10_4->setGeometry(QRect(10, 560, 271, 161));
        label_9 = new QLabel(wavePlot10_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(160, 10, 141, 20));
        wavePlot10_5 = new QCustomPlot(Form);
        wavePlot10_5->setObjectName(QString::fromUtf8("wavePlot10_5"));
        wavePlot10_5->setGeometry(QRect(10, 730, 271, 161));
        label_4 = new QLabel(wavePlot10_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(130, 10, 171, 20));
        wavePlot10_6 = new QCustomPlot(Form);
        wavePlot10_6->setObjectName(QString::fromUtf8("wavePlot10_6"));
        wavePlot10_6->setGeometry(QRect(290, 60, 271, 161));
        label_8 = new QLabel(wavePlot10_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(180, 0, 111, 20));
        wavePlot10_7 = new QCustomPlot(Form);
        wavePlot10_7->setObjectName(QString::fromUtf8("wavePlot10_7"));
        wavePlot10_7->setGeometry(QRect(290, 240, 271, 161));
        label_6 = new QLabel(wavePlot10_7);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(170, 10, 171, 20));
        treat = new QCustomPlot(Form);
        treat->setObjectName(QString::fromUtf8("treat"));
        treat->setGeometry(QRect(620, 70, 271, 161));
        label_10 = new QLabel(treat);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(120, 10, 171, 20));
        treat_2 = new QCustomPlot(Form);
        treat_2->setObjectName(QString::fromUtf8("treat_2"));
        treat_2->setGeometry(QRect(620, 240, 271, 161));
        label_12 = new QLabel(treat_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(120, 10, 171, 20));
        treat_3 = new QCustomPlot(Form);
        treat_3->setObjectName(QString::fromUtf8("treat_3"));
        treat_3->setGeometry(QRect(620, 410, 271, 161));
        label_13 = new QLabel(treat_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(120, 10, 171, 20));
        treat_4 = new QCustomPlot(Form);
        treat_4->setObjectName(QString::fromUtf8("treat_4"));
        treat_4->setGeometry(QRect(620, 580, 271, 161));
        label_15 = new QLabel(treat_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(120, 10, 171, 20));
        treat_5 = new QCustomPlot(Form);
        treat_5->setObjectName(QString::fromUtf8("treat_5"));
        treat_5->setGeometry(QRect(620, 750, 271, 161));
        label_17 = new QLabel(treat_5);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(120, 10, 171, 20));
        treat_6 = new QCustomPlot(Form);
        treat_6->setObjectName(QString::fromUtf8("treat_6"));
        treat_6->setGeometry(QRect(900, 70, 271, 161));
        label_18 = new QLabel(treat_6);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(120, 10, 171, 20));
        treat_7 = new QCustomPlot(Form);
        treat_7->setObjectName(QString::fromUtf8("treat_7"));
        treat_7->setGeometry(QRect(900, 240, 271, 161));
        label_20 = new QLabel(treat_7);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(120, 10, 171, 20));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "Alpha waves", nullptr));
        label->setText(QCoreApplication::translate("Form", "Pre treatment Graphs", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "Post treatment Graphs", nullptr));
        label_5->setText(QCoreApplication::translate("Form", "Beta waves", nullptr));
        label_7->setText(QCoreApplication::translate("Form", "Theta waves", nullptr));
        label_9->setText(QCoreApplication::translate("Form", " Gamma waves", nullptr));
        label_4->setText(QCoreApplication::translate("Form", "Alpha waves", nullptr));
        label_8->setText(QCoreApplication::translate("Form", "Theta waves", nullptr));
        label_6->setText(QCoreApplication::translate("Form", "Beta waves", nullptr));
        label_10->setText(QCoreApplication::translate("Form", "Alpha waves", nullptr));
        label_12->setText(QCoreApplication::translate("Form", "Beta waves", nullptr));
        label_13->setText(QCoreApplication::translate("Form", "Theta waves", nullptr));
        label_15->setText(QCoreApplication::translate("Form", " Gamma waves", nullptr));
        label_17->setText(QCoreApplication::translate("Form", "Beta waves", nullptr));
        label_18->setText(QCoreApplication::translate("Form", "Theta waves", nullptr));
        label_20->setText(QCoreApplication::translate("Form", "Beta waves", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHWINDOW_H
