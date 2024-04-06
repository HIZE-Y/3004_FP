#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QDateTimeEdit>
#include "signaldata.h"
#include "math.h"
//=======
#include <QTimer>
//>>>>>>> 61575b124b1040492ee8768dc15a76fcf11544fc

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
    void dataEntry();
    void stop();
    void pause();
    void resume();
    void updateProgressBar();
    void inputData();
    double math(SignalData array[], int size);

private:
    Ui::MainWindow *ui;
    int battery;
    int state;
    int counter;
    double fd[7];
    QFile m_logHistory;
    QDateTimeEdit dateTimeEdit;
    QTimer *timer2;
    QTimer *timer;
    QTimer  *timer3;
    SignalData signalArray;
    SignalData signalArray2;
    SignalData signalArray3;
    SignalData signalArray4;
    SignalData signalArray5;
    SignalData signalArray6;
    SignalData signalArray7;

};
#endif // MAINWINDOW_H
