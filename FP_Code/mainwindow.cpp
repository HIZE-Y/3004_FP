#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QCoreApplication>
#include <QDebug>
#include <graphwindow.h>

// Constructor of the main window
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initializes the main window and its components
    intil();

    // Initial state of light indicators (all turned off)
    updateLightIndicator("#00FF00", false); // Green light off
    updateLightIndicator("#0000FF", false); // Blue light off
    updateLightIndicator("#FF0000", false); // Red light off

    // Connect button signals to corresponding slots
    connect(ui->Start, &QPushButton::clicked, [this]() { start(); });
    ui->Battery->setValue(100); // Set initial battery level
    ui->Battery->setVisible(false); // Hide the battery level indicator initially
    ui->frame->setVisible(false); // Hide the frame initially
    ui->SessionPr->setValue(0); // Set initial session progress to 0

    //counter for the Disconnect button
    ui->counter->setValue(100);
    ui->counter->setVisible(false);
    ui->label_3->setVisible(false);

    // More button connections
    connect(ui->power, &QPushButton::clicked, [this]() { power(); });
    connect(ui->log, &QPushButton::clicked, [this]() { log(); });
    connect(ui->stopButton, &QPushButton::clicked, [this]() { stop(); });
    connect(ui->Pause, &QPushButton::clicked, [this]() { pause(); });
    connect(ui->Resume, &QPushButton::clicked, [this]() { resume(); });
    connect(ui->Disconnect, &QPushButton::clicked, [this]() { disconnect(); });
    connect(ui->clearHistory, &QPushButton::clicked, [this]() { clearHistory(); });

    //setup the file path for the history log
    QString filePath = QCoreApplication::applicationDirPath() + "/history.txt";
    m_logHistory.setFileName(filePath); // Set the filename for the log history


    // Connect timer signals to their slots
    connect(timer, SIGNAL(timeout()), this, SLOT(updateBattery())); //main timer for thhe battery
    connect(timer2, SIGNAL(timeout()), this, SLOT(updateProgressBar()));// timer for the sesssion
    connect(timer3, SIGNAL(timeout()), this, SLOT(stop()));// timer for pausing
    connect(flash, &QTimer::timeout, this, &MainWindow::handleFlash); //timer for the greenn ligh
    connect(redFlash, &QTimer::timeout, this, &MainWindow::handleRedFlash);// timerr for the red light
    connect(timer2, SIGNAL(timeout()), this, SLOT(updateBattery()));
    connect(contactTimer, SIGNAL(timeout()), this, SLOT(off())); //timer for disconnect button
    connect(countDown, SIGNAL(timeout()), this, SLOT(countDownF()));//timer for the dissconnect counter

}

// Updates the light indicator based on color and whether it should be turned on
void MainWindow::updateLightIndicator(const QString &lightColor, bool turnedOn) {
    QString baseStyle = "border-radius: 10px;";
    QString offStyle = "background-color: rgba(0, 0, 0, 0.1);";
    QString onStyleTemplate = "background-color: qradialgradient(cx: 0.5, cy: 0.5, radius: 1, fx: 0.5, fy: 0.5, stop: 0 %1, stop: 0.8 %2);";
    QString onStyle = onStyleTemplate.arg(lightColor + "80", lightColor);

    if (lightColor == "#FF0000") {
        ui->lightIndicatorRed->setStyleSheet(baseStyle + (turnedOn ? onStyle : offStyle));
    } else if (lightColor == "#00FF00") {
        ui->lightIndicatorGreen->setStyleSheet(baseStyle + (turnedOn ? onStyle : offStyle));
    } else if (lightColor == "#0000FF") {
        ui->lightIndicatorBlue->setStyleSheet(baseStyle + (turnedOn ? onStyle : offStyle));
    }
}

// Disconnects the electrodes and stops any ongoing processes
void MainWindow::disconnect() {
    qInfo() << "The electrode patch were disconnect";
    redFlashCount = 0;
    redFlash->start();

    countDownF();
    stop();
}

// Handles input of initial signal data for plots
void MainWindow:: countDownF(){
    qInfo()<<"**Beep**";
    countDown->start();
    ui->counter->setVisible(true);
    ui->label_3->setVisible(true);
    if (ui->counter->value() != 0) {
            ui->counter->setValue(ui->counter->value() - 10);
    } else {
        off();
        ui->counter->setValue(ui->counter->value() + 100);
        countDown->stop();
        ui->counter->setVisible(false);
        ui->label_3->setVisible(false);
    }
}
// Initializes timers and state variables
void MainWindow::intil(){
    counter = 0;
    state = 0;
    timer = new QTimer(this);
    timer2 = new QTimer(this);
    timer2->setInterval(1000);
    timer3 = new QTimer(this);
    timer3->setInterval(10000);
    timer->setInterval(1000);
    timer->start();
    flash = new QTimer(this);
    flash->setInterval(500);
    redFlash = new QTimer(this);
    redFlash->setInterval(500);

    contactTimer = new QTimer(this);
    contactTimer->setInterval(10000);


    countDown = new QTimer(this);
    countDown->setInterval(1000);
}

// Destructor to clean up UI components
MainWindow::~MainWindow()
{
    delete ui;
}

// Logs session information to a file
void MainWindow::log(){
    ui->Histroylog->clear();
    if (m_logHistory.isOpen()) {
        m_logHistory.close();
    }
    QFile file("history.txt");
    if (!m_logHistory.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open for reading MainWindow:" << m_logHistory.errorString();
        return;
    }
    QTextStream in(&m_logHistory);
    QString content = in.readAll();
    ui->Histroylog->setText(content);
    m_logHistory.close();
}

// Starts a session, updates lights, and begins data collection
void MainWindow::start(){
    if(ui->Battery->value() < 50){
        qInfo() << "Low Battery Alert: "<<ui->Battery->value();
    }
    updateLightIndicator("#0000FF", true); // Blue light on
    updateLightIndicator("#00FF00", false); // Green light off
    updateLightIndicator("#FF0000", false); // Red light off
    flashCount = 0;
    flash->start();
    timer2->start();
    counter = 1;
}

// Stops the session, updates lights, and stops timers
void MainWindow::stop(){
   updateLightIndicator("#FF0000", true);
   QTimer::singleShot(2000, [this](){
       updateLightIndicator("#FF0000", false);
   });
   timer3->stop();
   timer2->stop();
   counter = 0;
   ui->SessionPr->setValue(0);
}

// Pauses the session, stops timers, and handles the state
void MainWindow::pause(){
    timer2->stop();
    timer3->start();
    state = 2;
    redFlashCount = 0;
    redFlash->start();
    updateLightIndicator("#00FF00", false);
}

// Resumes the session, restarts timers, and updates lights
void MainWindow::resume(){
    timer3->stop();
    timer2->start();
    state = 1;
    flashCount = 0;
    flash->start();
    updateLightIndicator("#FF0000", false);
}

// Turns on the device, makes UI elements visible, and updates lights
void MainWindow::on(){
    ui->Battery->setVisible(true);
    ui->Start->setVisible(true);
    ui->frame->setVisible(true);
    updateLightIndicator("#00FF00", true);
}

// Turns off the device, hides UI elements, and updates lights
void MainWindow::off(){
    ui->Battery->setVisible(false);
    ui->Start->setVisible(false);
    ui->frame->setVisible(false);
    timer2->stop();
    stop();
    updateLightIndicator("#0000FF", false);
    updateLightIndicator("#00FF00", false);
    updateLightIndicator("#FF0000", false);
    counter = 0;
}

// Handles the power button to toggle device state
void MainWindow::power(){
    if(state == 0){
        on();
        state = 1;
    } else if(state == 1){
        off();
        state = 0;
    } else if(state == 2){
        off();
        state = 0;
    }
}

// Updates the battery level based on device state
void MainWindow::updateBattery() {

    if (ui->Battery->value() != 0) {
         if (state == 1) {
            ui->Battery->setValue(ui->Battery->value() - 1);
        } else if (state == 2) {
            ui->Battery->setValue(ui->Battery->value() - 2);
            //
        }
    } else {
        off();
    }
}

// Updates the session progress bar based on timer
void MainWindow::updateProgressBar(){
    int progress = (counter * 100) / 6;
    ui->SessionPr->setValue(progress);
    counter++;
    if(progress > 100){
        ui->SessionPr->setValue(100);
        stop();
        QDateTime sessionStartDateTime = ui->dateTimeEdit->dateTime();
        QString sessionStartStr = sessionStartDateTime.toString("yyyy-MM-dd HH:mm");
        if (m_logHistory.isOpen()) {
            m_logHistory.close();
        }
        QFile file("history.txt");
            if (!m_logHistory.open(QIODevice::Append | QIODevice::Text | QIODevice::ReadOnly )){
                    qDebug() << "Failed to open" << m_logHistory.errorString();
                }
            QString sessionEntry = "the result of the session of: " + sessionStartStr + "\n\n\n";
            QTextStream out(&m_logHistory);
            out << sessionEntry;
            GraphWindow* graphWindow = new GraphWindow(this);
            graphWindow->show();
    }
}

// Handles the flashing of the green light
void MainWindow::handleFlash() {
    bool isOn = (flashCount % 2) == 0;
    updateLightIndicator("#00FF00",isOn);
    flashCount++;
    if (flashCount >= 8) {
        flash->stop();
        flashCount = 0;
    }
}

// Handles the flashing of the red light
void MainWindow::handleRedFlash() {
    bool isOn = (redFlashCount % 2) == 0;
    updateLightIndicator("#FF0000",isOn);
    redFlashCount++;
    if (redFlashCount >= 6) {
        redFlash->stop();
        redFlashCount = 0;
    }
}

void  MainWindow::clearHistory(){

    if (m_logHistory.isOpen()) {
        m_logHistory.close();
    }
    QFile file("history.txt");
    if(file.open(QIODevice::WriteOnly)){
        file.close();
        ui->Histroylog->clear();
        qInfo() << "'Histoory  was cleared";
    }else{
            qInfo() << "Failed to Clear history";
       }
}
