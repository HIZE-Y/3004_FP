#include "graphwindow.h"
#include "ui_graphwindow.h"
#include <QTextStream>
#include <QCoreApplication>
#include <QDebug>
#include "ui_graphwindow.h"
#include "mainwindow.h"
#include <random>

GraphWindow::GraphWindow(QWidget *parent) :
    QMainWindow(parent)
   , ui(new Ui::Form)
{
    ui->setupUi(this);
    inputData();
    QString filePath = QCoreApplication::applicationDirPath() + "/history2.txt";
    qInfo()<< filePath;
    m_logHistory.setFileName(filePath);
    //graphs pre
    QCustomPlot *compositeWaveformPlot = findChild<QCustomPlot*>("wavePlot10");
    QCustomPlot *compositeWaveformPlot2 = findChild<QCustomPlot*>("wavePlot10_2");
    QCustomPlot *compositeWaveformPlot3 = findChild<QCustomPlot*>("wavePlot10_3");
    QCustomPlot *compositeWaveformPlot4 = findChild<QCustomPlot*>("wavePlot10_4");
    QCustomPlot *compositeWaveformPlot5 = findChild<QCustomPlot*>("wavePlot10_5");
    QCustomPlot *compositeWaveformPlot6 = findChild<QCustomPlot*>("wavePlot10_6");
    QCustomPlot *compositeWaveformPlot7 = findChild<QCustomPlot*>("wavePlot10_7");

    // graphs post
    QCustomPlot *treat = findChild<QCustomPlot*>("treat");
    QCustomPlot *treat2 = findChild<QCustomPlot*>("treat_2");
    QCustomPlot *treat3 = findChild<QCustomPlot*>("treat_3");
    QCustomPlot *treat4 = findChild<QCustomPlot*>("treat_4");
    QCustomPlot *treat5 = findChild<QCustomPlot*>("treat_5");
    QCustomPlot *treat6 = findChild<QCustomPlot*>("treat_6");
    QCustomPlot *treat7 = findChild<QCustomPlot*>("treat_7");
    if (compositeWaveformPlot) {
            setupCompositeWaveformPlot1(compositeWaveformPlot, signalArray);
            setupCompositeWaveformPlot1(compositeWaveformPlot2, signalArray2);
            setupCompositeWaveformPlot1(compositeWaveformPlot3, signalArray3);
            setupCompositeWaveformPlot1(compositeWaveformPlot4, signalArray4);
            setupCompositeWaveformPlot1(compositeWaveformPlot5, signalArray5);
            setupCompositeWaveformPlot1(compositeWaveformPlot6, signalArray6);
            setupCompositeWaveformPlot1(compositeWaveformPlot7, signalArray7);

            setupCompositeWaveformPlot1(treat, tsignalArray);
            setupCompositeWaveformPlot1(treat2, tsignalArray2);
            setupCompositeWaveformPlot1(treat3, tsignalArray3);
            setupCompositeWaveformPlot1(treat4, tsignalArray4);
            setupCompositeWaveformPlot1(treat5, tsignalArray5);
            setupCompositeWaveformPlot1(treat6, tsignalArray6);
            setupCompositeWaveformPlot1(treat7, tsignalArray7);
        } else {
            qDebug() << "Failed to find QCustomPlot widget";
        }

}

GraphWindow::~GraphWindow()
{
    delete ui; // Properly delete the UI object to prevent memory leaks
}

void GraphWindow::inputData(){
    // Create a random engine
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define distributions for amplitude and frequency for each wave type
    std::uniform_real_distribution<> alphaFreq(8.0, 12.0);
    std::uniform_real_distribution<> betaFreq(12.0, 30.0);
    std::uniform_real_distribution<> thetaFreq(4.0, 7.0);
    std::uniform_real_distribution<> gammaFreq(30.0, 100.0);  // Arbitrary upper limit for gamma
    std::uniform_real_distribution<> amplitude(300, 700);  // General amplitude range for all waves

    // Initialize signal data arrays with random values
    // Alpha waves
    for (int i = 0; i < 3; ++i) {
        signalArray[i] = SignalData(amplitude(gen), alphaFreq(gen));
        signalArray5[i] = SignalData(amplitude(gen), alphaFreq(gen));
    }

    // Beta waves
    for (int i = 0; i < 3; ++i) {
        signalArray2[i] = SignalData(amplitude(gen), betaFreq(gen));
        signalArray7[i] = SignalData(amplitude(gen), betaFreq(gen));
    }

    // Theta waves
    for (int i = 0; i < 3; ++i) {
        signalArray3[i] = SignalData(amplitude(gen), thetaFreq(gen));
        signalArray6[i] = SignalData(amplitude(gen), thetaFreq(gen));
    }

    // Gamma waves
    for (int i = 0; i < 3; ++i) {
        signalArray4[i] = SignalData(amplitude(gen), gammaFreq(gen));
    }


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
    tsignalArray[0] = SignalData(signalArray[0].amplitude, fd1[0]);
    tsignalArray[1] = SignalData(signalArray[1].amplitude, fd2[0]);
    tsignalArray[2] = SignalData(signalArray[2].amplitude, fd3[0]);
    tsignalArray[3] = SignalData(signalArray[2].amplitude, fd3[0]);

   // SignalData signalArray2[3];//Beta Wave
    tsignalArray2[0] = SignalData(signalArray2[0].amplitude, fd1[1]);
    tsignalArray2[1] = SignalData(signalArray2[1].amplitude, fd2[1]);
    tsignalArray2[2] = SignalData(signalArray2[2].amplitude, fd3[1]);

   // SignalData signalArray3[3];//theta
    tsignalArray3[0] = SignalData(signalArray3[0].amplitude, fd1[2]);
    tsignalArray3[1] = SignalData(signalArray3[1].amplitude, fd2[2]);
    tsignalArray3[2] = SignalData(signalArray3[2].amplitude, fd3[2]);

   // SignalData signalArray4[3];//gamma
    tsignalArray4[0] = SignalData(signalArray4[0].amplitude, fd1[3]);
    tsignalArray4[1] = SignalData(signalArray4[1].amplitude,fd2[3]);
    tsignalArray4[2] = SignalData(signalArray2[2].amplitude, fd3[3]);

   // SignalData signalArray5[3];//alpha
    tsignalArray5[0] = SignalData(signalArray5[0].amplitude, fd1[4]);
    tsignalArray5[1] = SignalData(signalArray5[1].amplitude, fd2[4]);
    tsignalArray5[2] = SignalData(signalArray5[2].amplitude, fd3[4]);

   // SignalData signalArray6[3];//theta
    tsignalArray6[0] = SignalData(signalArray6[0].amplitude, fd1[5]);
    tsignalArray6[1] = SignalData(signalArray6[1].amplitude, fd2[5]);
    tsignalArray6[2] = SignalData(signalArray6[2].amplitude,fd3[5]);

   // SignalData signalArray7[3];// Beta
    tsignalArray7[0] = SignalData(signalArray7[0].amplitude, fd1[6]);
    tsignalArray7[1] = SignalData(signalArray7[1].amplitude, fd2[6]);
    tsignalArray7[2] = SignalData(signalArray7[2].amplitude, fd3[6]);

// this used to save treatted data for plotting reasons only

    fd[0] = math(signalArray, 3);
    fd[1] = math(signalArray2, 3);
    fd[2] = math(signalArray3, 3);
    fd[3] = math(signalArray4, 3);
    fd[4] = math(signalArray5, 3);
    fd[5] = math(signalArray6, 3);
    fd[6] = math(signalArray7, 3);
     treatment(fd);
};

void GraphWindow:: treatment(double t[]){
    qInfo()<<"test";
    for (int i=0;i<7 ;i++ ) {
        fd1[i]=t[i]+0.1;
        fd2[i]= fd1[i]+0.1;
        fd3[i]= fd2[i]+0.1;
        fTd[i]= fd3[i]+0.1;
    }
    log();
}
void GraphWindow::setupCompositeWaveformPlot1(QCustomPlot *customPlot, SignalData *l) {
    // Generate some data for the composite waveform:
    QVector<double> x(1001), y(1001); // 1001 points for smoothness
    double tStep = 1.0 / (x.size() - 1);

    for (int i = 0; i < x.size(); ++i)
    {
        double t = i * tStep; // Time from 0 to 1
        x[i] = t;

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


void GraphWindow::log(){
    qInfo()<<"Hey";
    if (m_logHistory.isOpen()) {
            m_logHistory.close();
        }

    QFile file("history.txt");
   if (!m_logHistory.open(QIODevice::Append | QIODevice::Text | QIODevice::ReadOnly )){
           qDebug() << "Failed to open" << m_logHistory.errorString();
       }
   qInfo()<<"added to the history log";
   for (int i=0;i<7 ;i++ ) {
       //qInfo()<<"test"<<fd[i];
       QString sessionEntry = "the result of the session that you start it at: Intial FD:"+QString::number(fd[i])+"After treatment:"+QString::number(fTd[i])+"\n";
       QTextStream out(&m_logHistory);
       out << sessionEntry;
   }


}

