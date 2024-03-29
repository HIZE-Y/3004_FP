#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    intil();
    connect(ui->Start, &QPushButton::clicked, [this]() { start(); });
    ui->Battery->setValue(100);
    connect(ui->power,&QPushButton::clicked, [this]() { power(); });
    connect(timer, SIGNAL(timeout()), this, SLOT(updateBattery()));

}

void MainWindow::intil(){
state = 0;
timer = new QTimer(this);
timer->setInterval(10000);
timer->start();}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: start(){
    qInfo()<<"HEY";
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
