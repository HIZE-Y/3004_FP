#include "graphwindow.h"
#include "ui_graphwindow.h"
#include <QTextStream>
#include <QCoreApplication>
#include <QDebug>
#include "ui_graphwindow.h"
#include "mainwindow.h"


GraphWindow::GraphWindow(QWidget *parent) :
    QMainWindow(parent)
   , ui(new Ui::Form)
{
    ui->setupUi(this);
    inputData();
    QCustomPlot *compositeWaveformPlot = findChild<QCustomPlot*>("wavePlot10");
    if (compositeWaveformPlot) {
            setupCompositeWaveformPlot1(compositeWaveformPlot, signalArray);
        } else {
            qDebug() << "Failed to find QCustomPlot widget";
        }

}

GraphWindow::~GraphWindow()
{
    delete ui; // Properly delete the UI object to prevent memory leaks
}

void GraphWindow::inputData(){
    //this is for intial
  //  SignalData signalArray[3];//Alpha
    signalArray[0] = SignalData(440.0, 8.0);
    signalArray[1] = SignalData(880.0, 10.8);
    signalArray[2] = SignalData(880.0, 11.8);

   // SignalData signalArray2[3];//Beta Wave
    signalArray2[0] = SignalData(440.0, 12.0);
    signalArray2[1] = SignalData(880.0, 15.8);
    signalArray2[2] = SignalData(880.0, 20.8);

   // SignalData signalArray3[3];//theta
    signalArray3[0] = SignalData(440.0, 8.0);
    signalArray3[1] = SignalData(880.0, 4.8);
    signalArray3[2] = SignalData(880.0, 5.8);

   // SignalData signalArray4[3];//gamma
    signalArray4[0] = SignalData(440.0, 25.0);
    signalArray4[1] = SignalData(880.0, 30.8);
    signalArray4[2] = SignalData(880.0, 90.8);

   // SignalData signalArray5[3];//alpha
    signalArray5[0] = SignalData(440.0, 8.0);
    signalArray5[1] = SignalData(880.0, 11.8);
    signalArray5[2] = SignalData(880.0, 9.8);

   // SignalData signalArray6[3];//theta
    signalArray6[0] = SignalData(440.0, 4.50);
    signalArray6[1] = SignalData(880.0, 5.8);
    signalArray6[2] = SignalData(880.0, 6.8);

   // SignalData signalArray7[3];// Beta
    signalArray7[0] = SignalData(440.0, 12.0);
    signalArray7[1] = SignalData(880.0, 13.8);
    signalArray7[2] = SignalData(880.0, 19.8);

// this used to save treatted data for plotting reasons only

    fd[0] = math(signalArray, 3);
    fd[1] = math(signalArray2, 3);
    fd[2] = math(signalArray3, 3);
    fd[3] = math(signalArray4, 3);
    fd[4] = math(signalArray5, 3);
    fd[5] = math(signalArray6, 3);
    fd[6] = math(signalArray7, 3);
    treatment(fd);
//    SignalData treaTeadtedData[3];
    //treaTeadtedData[0]=SignalData(400,fd[2] );
    tsignalArray[0] = SignalData(440.0, fd1[0]);
    tsignalArray[1] = SignalData(880.0, fd1[0]);
    tsignalArray[2] = SignalData(880.0, fd1[0]);

   // SignalData signalArray2[3];//Beta Wave
    tsignalArray2[0] = SignalData(440.0, 12.0);
    tsignalArray2[1] = SignalData(880.0, 15.8);
    tsignalArray2[2] = SignalData(880.0, 20.8);

   // SignalData signalArray3[3];//theta
    tsignalArray3[0] = SignalData(440.0, 8.0);
    tsignalArray3[1] = SignalData(880.0, 4.8);
    tsignalArray3[2] = SignalData(880.0, 5.8);

   // SignalData signalArray4[3];//gamma
    tsignalArray4[0] = SignalData(440.0, 25.0);
    tsignalArray4[1] = SignalData(880.0, 30.8);
    tsignalArray4[2] = SignalData(880.0, 90.8);

   // SignalData signalArray5[3];//alpha
    tsignalArray5[0] = SignalData(440.0, 8.0);
    tsignalArray5[1] = SignalData(880.0, 11.8);
    tsignalArray5[2] = SignalData(880.0, 9.8);

   // SignalData signalArray6[3];//theta
    signalArray6[0] = SignalData(440.0, 4.50);
    signalArray6[1] = SignalData(880.0, 5.8);
    signalArray6[2] = SignalData(880.0, 6.8);

   // SignalData signalArray7[3];// Beta
    signalArray7[0] = SignalData(440.0, 12.0);
    signalArray7[1] = SignalData(880.0, 13.8);
    signalArray7[2] = SignalData(880.0, 19.8);

// this used to save treatted data for plotting reasons only

    fd[0] = math(signalArray, 3);
    fd[1] = math(signalArray2, 3);
    fd[2] = math(signalArray3, 3);
    fd[3] = math(signalArray4, 3);
    fd[4] = math(signalArray5, 3);
    fd[5] = math(signalArray6, 3);
    fd[6] = math(signalArray7, 3);
};

void GraphWindow:: treatment(double t[]){

    for (int i=0;i<7 ;i++ ) {
        fd1[i]=t[i]+0.1;
        fd2[i]= fd1[i]+0.1;
        fd3[i]= fd2[i]+0.1;
        fTd[i]= fd3[i]+0.1;
    }

}
void GraphWindow::setupCompositeWaveformPlot1(QCustomPlot *customPlot, SignalData *l) {
    // Generate some data for the composite waveform:
    QVector<double> x(1001), y(1001); // 1001 points for smoothness
    double tStep = 1.0 / (x.size() - 1);


    for (int i = 0; i < x.size(); ++i)
    {
        double t = i * tStep; // Time from 0 to 1
        x[i] = t;
        qInfo()<<"TEST"<<l[0].amplitude ;
        // Calculate the composite waveform as the sum of three sine waves
        y[i] = l[0].amplitude * qSin(2 * M_PI * l[0].frequency * t) + l[1].amplitude * qSin(2 * M_PI * l[1].frequency * t) + l[2].amplitude * qSin(2 * M_PI * l[2].frequency * t);
    }

    // Create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);

    // Give the axes some labels and set their ranges:
    customPlot->xAxis->setLabel("Time (s)");
    customPlot->yAxis->setLabel("Amplitude");
    customPlot->xAxis->setRange(0, 1);
    customPlot->yAxis->setRange(-2300, 2300); // Adjusted for the amplitude of the composite waveform
    customPlot->replot(); // This line is necessary to make the graph visible
}

double GraphWindow::math(SignalData t[], int size) {
    double numerator = 0.0;
    double denominator = 0.0;

    for (int i = 0; i < size; ++i) {
        numerator += t[i].frequency * (t[i].amplitude * t[i].amplitude);
        denominator += (t[i].amplitude * t[i].amplitude);
    }

    if (denominator == 0) {
        qWarning() << "Denominator is zero, cannot divide by zero.";
        return -1; // Handle this error as appropriate
    }

    return numerator / denominator;
}




