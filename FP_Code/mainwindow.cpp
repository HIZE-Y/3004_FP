#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QCoreApplication>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    intil();
    updateLightIndicator("#00FF00", false); // Turn off the green light
    updateLightIndicator("#0000FF", false); // Turn off the blue light
    updateLightIndicator("#FF0000", false); // Turn off the red light
    connect(ui->Start, &QPushButton::clicked, [this]() { start(); });
    ui->Battery->setValue(100);
    ui->Battery->setVisible(false);
    ui->frame->setVisible(false);
    ui->SessionPr->setValue(0);
    connect(ui->power,&QPushButton::clicked, [this]() { power(); });
    connect(ui->log,&QPushButton::clicked, [this]() { log(); });
    connect(ui->stopButton,&QPushButton::clicked, [this]() { stop(); });
    connect(ui->Pause,&QPushButton::clicked, [this]() { pause(); });
    connect(ui->Resume,&QPushButton::clicked, [this]() { resume(); });
    connect(ui->Disconnect,&QPushButton::clicked, [this]() { disconnect(); });
    //connect(ui->dateTimeEdit,&QDateTimeEdit::dateTimeChanged, [this] {start();});

    QString filePath = QCoreApplication::applicationDirPath() + "/history.txt";
    qInfo()<< filePath;

    m_logHistory.setFileName(filePath);

    connect(timer, SIGNAL(timeout()), this, SLOT(updateBattery()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(updateProgressBar()));
    connect(timer3, SIGNAL(timeout()), this, SLOT(stop()));
    connect(flash, &QTimer::timeout, this, &MainWindow::handleFlash);

    inputData();
    void setupCompositeWaveformPlot(QCustomPlot *compositeWaveformPlot);
    QCustomPlot *compositeWaveformPlot = findChild<QCustomPlot*>("wavePlot");
    if (compositeWaveformPlot) {
            setupCompositeWaveformPlot(compositeWaveformPlot);
        } else {
            qDebug() << "Failed to find QCustomPlot widget";
        }
}

void MainWindow::updateLightIndicator(const QString &lightColor, bool turnedOn) {
    QString baseStyle = "border-radius: 10px;"; // Common style for all lights
    QString offStyle = "background-color: rgba(0, 0, 0, 0.1);"; // Style for turned off light
    QString onStyleTemplate = "background-color: qradialgradient(cx: 0.5, cy: 0.5, radius: 1, fx: 0.5, fy: 0.5, stop: 0 %1, stop: 0.8 %2);"; // Style for turned on light

    QString onStyle = onStyleTemplate.arg(lightColor + "80", lightColor); // Adding transparency for a glow effect

    if (lightColor == "#FF0000") { // Red Light
        ui->lightIndicatorRed->setStyleSheet(baseStyle + (turnedOn ? onStyle : offStyle));
    } else if (lightColor == "#00FF00") { // Green Light
        ui->lightIndicatorGreen->setStyleSheet(baseStyle + (turnedOn ? onStyle : offStyle));
    } else if (lightColor == "#0000FF") { // Blue Light
        ui->lightIndicatorBlue->setStyleSheet(baseStyle + (turnedOn ? onStyle : offStyle));
    }
}


void MainWindow::disconnect() {
    qInfo() << "The electrolode patch were disconnect";
    stop();
}

void MainWindow::inputData(){
    SignalData signalArray[3];//Alpha
    signalArray[0] = SignalData(440.0, 8.0);
    signalArray[1] = SignalData(880.0, 10.8);
    signalArray[2] = SignalData(880.0, 11.8);

    SignalData signalArray2[3];//Beta Wave
    signalArray2[0] = SignalData(440.0, 12.0);
    signalArray2[1] = SignalData(880.0, 15.8);
    signalArray2[2] = SignalData(880.0, 20.8);

    SignalData signalArray3[3];//theta
    signalArray3[0] = SignalData(440.0, 8.0);
    signalArray3[1] = SignalData(880.0, 4.8);
    signalArray3[2] = SignalData(880.0, 5.8);
    SignalData signalArray4[3];//gamma
    signalArray4[0] = SignalData(440.0, 25.0);
    signalArray4[1] = SignalData(880.0, 30.8);
    signalArray4[2] = SignalData(880.0, 90.8);
    SignalData signalArray5[3];//alpha
    signalArray5[0] = SignalData(440.0, 8.0);
    signalArray5[1] = SignalData(880.0, 11.8);
    signalArray5[2] = SignalData(880.0, 9.8);
    SignalData signalArray6[3];//theta
    signalArray6[0] = SignalData(440.0, 4.50);
    signalArray6[1] = SignalData(880.0, 5.8);
    signalArray6[2] = SignalData(880.0, 6.8);
    SignalData signalArray7[3];// Beta
    signalArray7[0] = SignalData(440.0, 12.0);
    signalArray7[1] = SignalData(880.0, 13.8);
    signalArray7[2] = SignalData(880.0, 19.8);

    fd[0] = math(signalArray, 3);
    fd[1] = math(signalArray2, 3);
    fd[2] = math(signalArray3, 3);
    fd[3] = math(signalArray4, 3);
    fd[4] = math(signalArray5, 3);
    fd[5] = math(signalArray6, 3);
    fd[6] = math(signalArray7, 3);
    treatment(fd);
};

void MainWindow:: treatment(double t[]){

    for (int i=0;i<7 ;i++ ) {
        fd1[i]=t[i]+0.1;
        fd2[i]= fd1[i]+0.1;
        fd3[i]= fd2[i]+0.1;
        fTd[i]= fd3[i]+0.1;
    }

}

double MainWindow::math(SignalData t[], int size) {
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
void MainWindow::intil(){

    inputData();

    counter=0;
    state = 0;
    timer = new QTimer(this);
    timer2 = new QTimer(this);
    timer2->setInterval(1000);
    timer3 = new QTimer(this);
    timer3->setInterval(5000);
    timer->setInterval(1000);
    timer->start();

    flash = new QTimer(this);
    flash->setInterval(500); // Flash interval (500ms for example)
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::log(){

    if (m_logHistory.isOpen()) {
            m_logHistory.close();
        }
    QFile file("history.txt");
   // m_logHistory.close();

       //  Reopen the file in read-only mode to print its contents
        if (!m_logHistory.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qWarning() << "Failed to open for reading:" << m_logHistory.errorString();
            return;
        }

        QTextStream in(&m_logHistory);
            QString content = in.readAll();  // Read all content at once, more efficient for this use case.
            ui->Histroylog->setText(content);  // Assuming Histroylog is a typo of Historylog, and it's your QTextBrowser.

            // Close the file after reading.
            m_logHistory.close();
}
void MainWindow:: start(){
    updateLightIndicator("#0000FF", true); // Turn on the blue light
    updateLightIndicator("#00FF00", false); // Turn off the green light
    updateLightIndicator("#FF0000", false); // Turn off the red light
    flashCount=0;
    flash->start();
    if (m_logHistory.isOpen()) {
            m_logHistory.close();
        }

    QDateTime sessionStartDateTime = ui->dateTimeEdit->dateTime();
    QString sessionStartStr = sessionStartDateTime.toString("yyyy-MM-dd HH:mm");


    timer2->start();
    counter = 1;
     QFile file("history.txt");
    if (!m_logHistory.open(QIODevice::Append | QIODevice::Text | QIODevice::ReadOnly )){
            qDebug() << "Failed to open" << m_logHistory.errorString();
        }
    qInfo()<<"added to the history log";
    for (int i=0;i<7 ;i++ ) {
        qInfo()<<"test"<<fd[i];
        QString sessionEntry = "the result of the session that you start it at: " + sessionStartStr + "Intial FD:"+QString::number(fd[i])+"After treatment:"+QString::number(fTd[i])+"\n";
        QTextStream out(&m_logHistory);
        out << sessionEntry;
    }


}


void MainWindow::stop(){
   updateLightIndicator("#FF0000", true); // Turn on the red light
   timer3->stop();
   timer2->stop();//stops the session
   counter=0;
   ui->SessionPr->setValue(0);
   qInfo()<< "Test: Stop";

}
void MainWindow::pause(){
    timer2->stop();
    timer3->start();
    state = 2;
}

void MainWindow::resume(){
    timer3->stop();
    timer2->start();
    state = 1;
}

void MainWindow::on(){
    ui->Battery->setVisible(true);
    ui->Start->setVisible(true);
    ui->frame->setVisible(true);
    updateLightIndicator("#00FF00", true); // Turn on the green light

}

void MainWindow::off(){
    ui->Battery->setVisible(false);
    ui->Start->setVisible(false);
    ui->frame->setVisible(false);
    timer2->stop();//stops the session
    updateLightIndicator("#0000FF", false); // Turn on the blue light
    updateLightIndicator("#00FF00", false); // Turn off the green light
    updateLightIndicator("#FF0000", false); // Turn off the red light
    counter=0;
}


void MainWindow::power(){

        //if device is off and power is pressed, turn device on
        if(state == 0){
          //  initializeValues();
            on();
            state = 1; //startup is complete
        }
        //if device is on and power is pressed, turn device off
        else if(state == 1){
            off();
            state = 0; //device is turned off
        }
        //if session is in progress and power is pressed, deal with the interruption, and then turn device off
        else if(state == 2){
            off();
            state = 0; //device is turned off
        }
        // add a state for when session is in progress to be used in updateBattery to decrease battery faster
}



void MainWindow::updateBattery(){
    if(ui->Battery->value() != 0){
        if(state == 1){
            ui->Battery->setValue(ui->Battery->value() - 1);
        }
    }

    else{ //battery is out, so act as if the devie has been turned off
        off();

    }
}

void MainWindow::updateProgressBar(){
    int progress = (counter * 100) / 6;
    ui->SessionPr->setValue(progress);
    qInfo() << "the counter is :" << counter;
    counter++;
    if(progress > 100){
        ui->SessionPr->setValue(100);
        stop();
    }
}

//flash
void MainWindow::handleFlash() {
    // Toggle the green light's state
    bool isOn = (flashCount % 2) == 0;
     updateLightIndicator("#00FF00",isOn);

    // Increment the flash count
    flashCount++;

    // If the desired number of flashes has occurred, stop the timer
    if (flashCount >= 6) { // 2 seconds at 500ms per interval = 4 flashes
        flash->stop();
        flashCount = 0; // Reset the counter for the next use
    }
}

void setupCompositeWaveformPlot(QCustomPlot *customPlot)
{
    // Generate some data for the composite waveform:
    QVector<double> x(1001), y(1001); // 1001 points for smoothness
    double tStep = 1.0 / (x.size() - 1);

    for (int i = 0; i < x.size(); ++i)
    {
        double t = i * tStep; // Time from 0 to 1
        x[i] = t;
        // Calculate the composite waveform as the sum of three sine waves
        y[i] = 440 * qSin(2 * M_PI * 8.0 * t) + 880.0 * qSin(2 * M_PI * 10.8 * t) + 880.0 * qSin(2 * M_PI * 11.8 * t);
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

