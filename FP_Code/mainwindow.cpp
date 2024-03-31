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
    connect(ui->power,&QPushButton::clicked, [this]() { power(); });
<<<<<<< HEAD

    QString filePath = QCoreApplication::applicationDirPath() + "/history.txt";
    qInfo()<< filePath;
    m_logHistory.setFileName(filePath);
    if (!m_logHistory.open(QIODevice::Append | QIODevice::Text)){
        qDebug() << "Failed to open" << m_logHistory.errorString();
    }
=======
    connect(timer, SIGNAL(timeout()), this, SLOT(updateBattery()));

>>>>>>> 61575b124b1040492ee8768dc15a76fcf11544fc
}

void MainWindow::intil(){
state = 0;
timer = new QTimer(this);
timer->setInterval(100);
timer->start();
   qInfo()<<"HEY";}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: start(){
    qInfo()<<"HEY";
    QString sessionEntry = "This is the first Session";
    QTextStream out(&m_logHistory);
    out << sessionEntry;
}

void MainWindow::on(){
    ui->Battery->setVisible(true);
    ui->Start->setVisible(true);
//    timer = new QTimer(this);
//    timer->setInterval(100);
//    timer->start();

}

void MainWindow::off(){
    ui->Battery->setVisible(false);
    ui->Start->setVisible(false);
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
