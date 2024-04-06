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
    connect(ui->Start, &QPushButton::clicked, [this]() { start(); });
    ui->Battery->setValue(100);
    ui->Battery->setVisible(false);
    ui->frame->setVisible(false);
    ui->SessionPr->setValue(0);
    connect(ui->power,&QPushButton::clicked, [this]() { power(); });
    connect(ui->log,&QPushButton::clicked, [this]() { log(); });
    connect(ui->stopButton,&QPushButton::clicked, [this]() { stop(); });
    //connect(ui->dateTimeEdit,&QDateTimeEdit::dateTimeChanged, [this] {start();});

    QString filePath = QCoreApplication::applicationDirPath() + "/history.txt";
    qInfo()<< filePath;

    m_logHistory.setFileName(filePath);

    connect(timer, SIGNAL(timeout()), this, SLOT(updateBattery()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(updateProgressBar()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(dataEntry()));
    connect(timer3, SIGNAL(timeout()), this, SLOT(stop()));


    inputData();

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
};
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
    timer3->setInterval(1000);
    timer->setInterval(1000);
    timer->start();

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

    for (int i = 0; i <7; i++){
        qInfo() << "Dominant Frequency: " << fd[i] << " Hz";
    }
    if (m_logHistory.isOpen()) {
            m_logHistory.close();
        }

    QDateTime sessionStartDateTime = ui->dateTimeEdit->dateTime();
    QString sessionStartStr = sessionStartDateTime.toString("yyyy-MM-dd HH:mm");


    timer2->start();
     QFile file("history.txt");
    if (!m_logHistory.open(QIODevice::Append | QIODevice::Text | QIODevice::ReadOnly )){
            qDebug() << "Failed to open" << m_logHistory.errorString();
        }
    qInfo()<<"added to the history log";
    QString sessionEntry = "the result of the session that you start it at: " + sessionStartStr + "\n";
    QTextStream out(&m_logHistory);
    out << sessionEntry;

}


void MainWindow::dataEntry(){
   // timer->stop(  if(timer==0)
    counter++;
    if(counter==21){
       qInfo()<<"Reached 21";
    timer2->stop();    }
     qInfo()<<counter;
}

void MainWindow::stop(){
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

}

void MainWindow::off(){
    ui->Battery->setVisible(false);
    ui->Start->setVisible(false);
    ui->frame->setVisible(false);
    timer2->stop();//stops the session
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
            //turn screen back off
            off();
            state = 0; //device is turned off
        }
        //if session is in progress and power is pressed, deal with the interruption, and then turn device off
        else if(state == 2){
            //turn screen back off
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
    int progress = (counter * 100) / 7;
    ui->SessionPr->setValue(progress);

    // session ends
    if(counter == 7){
        ui->SessionPr->setValue(100);
        stop();
    }

}



