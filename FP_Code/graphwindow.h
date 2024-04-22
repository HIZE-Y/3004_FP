#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <qcustomplot.h> // Ensure you have included QCustomPlot
#include "ui_graphwindow.h"
#include "signaldata.h"
#include  "math.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GraphWindow; }
QT_END_NAMESPACE

class GraphWindow : public QMainWindow
{
    Q_OBJECT
public:
    GraphWindow(QWidget *parent = nullptr);
    ~GraphWindow();
    void log();
private:
    Ui::Form *ui;
    QCustomPlot *customPlot;
    void inputData();
    void setupCompositeWaveformPlot1(QCustomPlot *customPlot, SignalData *signaArray);

    void treatment(double t[]);
    double math(SignalData array[], int size);
    SignalData signalArray[3];      // Array for one type of signal
    SignalData signalArray2[3];     // Another array for a different type
    SignalData signalArray3[3];
    SignalData signalArray4[3];      // Array for one type of signal
    SignalData signalArray5[3];     // Another array for a different type
    SignalData signalArray6[3];
    SignalData signalArray7[3];

    QFile m_logHistoryTwo;


     SignalData tsignalArray[4];      // Array for one type of signal
     SignalData tsignalArray2[4];     // Another array for a different type
     SignalData tsignalArray3[4];
     SignalData tsignalArray4[4];      // Array for one type of signal
     SignalData tsignalArray5[4];     // Another array for a different type
     SignalData tsignalArray6[4];
     SignalData tsignalArray7[4];

     double fd[7];
     double fTd[7];
     double fd1[7];
     double fd2[7];
     double fd3[7];
};

#endif // GRAPHWINDOW_H
