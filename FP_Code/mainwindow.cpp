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
    connect(ui->Start, &QPushButton::clicked, [this]() { start(); });
    ui->Battery->setValue(100);
    connect(ui->power,&QPushButton::clicked, [this]() { power(); });

    QString filePath = QCoreApplication::applicationDirPath() + "/history.txt";
    qInfo()<< filePath;
    m_logHistory.setFileName(filePath);
    if (!m_logHistory.open(QIODevice::Append | QIODevice::Text)){
        qDebug() << "Failed to open" << m_logHistory.errorString();
    }
}

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
}
