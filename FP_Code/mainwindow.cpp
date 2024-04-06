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



}

void MainWindow::intil(){
    counter=0;
    state = 0;
    timer = new QTimer(this);
    timer2 = new QTimer(this);
    timer2->setInterval(1000);
    timer3 = new QTimer(this);
    timer3->setInterval(1000);
    timer->setInterval(1000);
    timer->start();
   qInfo()<<"HEY";
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
    qInfo()<<"HEY2";
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
    int progress = (counter * 100) / 21;
    ui->SessionPr->setValue(progress);

    // session ends
    if(counter == 21){
        counter = 0;
        ui->SessionPr->setValue(0); // reset progress bar
        timer2->stop(); // stop session timer
    }

}
