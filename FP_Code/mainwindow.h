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
    void updateLightIndicator(const QString &color, bool);
    void handleFlash();
    void clearHistory();

    void countDownF();


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
    QTimer *contactTimer;
    QTimer *countDown;
    int flashCount;
    int redFlashCount;
    QTimer *flash;

    SignalData signalArray[3];
     SignalData signalArray2[3];
     SignalData signalArray3[3];
     SignalData signalArray4[3];
     SignalData signalArray5[3];
     SignalData signalArray6[3];
     SignalData signalArray7[3];

     SignalData tsignalArray[4];
     SignalData tsignalArray2[4];
     SignalData tsignalArray3[4];
     SignalData tsignalArray4[4];
     SignalData tsignalArray5[4];
     SignalData tsignalArray6[4];
     SignalData tsignalArray7[4];



    QTimer *redFlash;

    QCustomPlot *compositeWaveformPlot;
    void setupCompositeWaveformPlot(QCustomPlot *compositeWaveformPlot,SignalData *signalData);


};
#endif // MAINWINDOW_H
