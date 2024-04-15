#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QDateTimeEdit>
#include "signaldata.h"
#include "math.h"
#include "QThread"
#include <QTimer>
#include "qcustomplot.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void start();
    void log();
    void power();
    void on();
    void off();
    void updateBattery();
    void intil();
    void stop();
    void pause();
    void resume();
    void disconnect();
    void updateProgressBar();
    void inputData();
    void updateLightIndicator(const QString &color, bool);
    double math(SignalData array[], int size);
    void treatment(double t[]);
    void handleFlash();


   // void afterTreatment(QCustomPlot *customPlot);

    void handleRedFlash();

private:
    Ui::MainWindow *ui;
    int battery;
    int state;
    int counter;
    double fd[7];
    double fTd[7];
    double fd1[7];
    double fd2[7];
    double fd3[7];
    QFile m_logHistory;
    QDateTimeEdit dateTimeEdit;
    QTimer *timer2;
    QTimer *timer;
    QTimer  *timer3;
    int flashCount;
    int redFlashCount;
    QTimer *flash;
//<<<<<<< HEAD
    SignalData signalArray[3];      // Array for one type of signal
     SignalData signalArray2[3];     // Another array for a different type
     SignalData signalArray3[3];
     SignalData signalArray4[3];      // Array for one type of signal
      SignalData signalArray5[3];     // Another array for a different type
      SignalData signalArray6[3];
     SignalData signalArray7[3];




     SignalData tsignalArray[4];      // Array for one type of signal
     SignalData tsignalArray2[4];     // Another array for a different type
     SignalData tsignalArray3[4];
     SignalData tsignalArray4[4];      // Array for one type of signal
     SignalData tsignalArray5[4];     // Another array for a different type
     SignalData tsignalArray6[4];
//    SignalData treaTeadtedData;
//    SignalData treaTeadtedData2;
//    SignalData treaTeadtedData3;
//    SignalData treaTeadtedData4;
//    SignalData treaTeadtedData5;
//    SignalData treaTeadtedData6;
//    SignalData treaTeadtedData7;


    QTimer *redFlash;

    QCustomPlot *compositeWaveformPlot;
    void setupCompositeWaveformPlot(QCustomPlot *compositeWaveformPlot,SignalData *signalData);


};
#endif // MAINWINDOW_H
