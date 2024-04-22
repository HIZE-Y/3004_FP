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
    intil(); // Initializes the main window and its components
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

    QString filePath = QCoreApplication::applicationDirPath() + "/history.txt";
    qInfo() << filePath;
    m_logHistory.setFileName(filePath); // Set the filename for the log history

    // Connect timer signals to their slots
    connect(timer, SIGNAL(timeout()), this, SLOT(updateBattery()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(updateProgressBar()));
    connect(timer3, SIGNAL(timeout()), this, SLOT(stop()));
    connect(flash, &QTimer::timeout, this, &MainWindow::handleFlash);
    connect(redFlash, &QTimer::timeout, this, &MainWindow::handleRedFlash);
    connect(timer2, SIGNAL(timeout()), this, SLOT(updateBattery()));
    connect(contactTimer, SIGNAL(timeout()), this, SLOT(off()));
    connect(countDown, SIGNAL(timeout()), this, SLOT(countDownF()));
    inputData(); // Input initial data
}

// Updates the light indicator based on color and whether it should be turned on
void MainWindow::updateLightIndicator(const QString &lightColor, bool turnedOn) {
    // Styles for the light indicator based on state
    QString baseStyle = "border-radius: 10px;";
    QString offStyle = "background-color: rgba(0, 0, 0, 0.1);";
    QString onStyleTemplate = "background-color: qradialgradient(cx: 0.5, cy: 0.5, radius: 1, fx: 0.5, fy: 0.5, stop: 0 %1, stop: 0.8 %2);";
    QString onStyle = onStyleTemplate.arg(lightColor + "80", lightColor);

    // Apply styles to specific lights based on color
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
    qInfo() << "The electrolode patch were disconnect";
    redFlashCount = 0;
    redFlash->start();

    countDownF();
    stop(); // Stops the session
}

// Handles input of initial signal data for plots
void MainWindow::inputData(){
    // Initialize data arrays for different signals and their treated forms
    // Populate signal data
    signalArray[0] = SignalData(440.0, 8.0);
    signalArray[1] = SignalData(880.0, 10.8);
    signalArray[2] = SignalData(880.0, 11.8);
    signalArray2[0] = SignalData(440.0, 12.0);
    signalArray2[1] = SignalData(880.0, 15.8);
    signalArray2[2] = SignalData(880.0, 20.8);
    // More initializations...
    // Call treatment function to calculate treated data
    fd[0] = math(signalArray, 3);
    fd[1] = math(signalArray2, 3);
    // More calculations...
    treatment(fd);
}

// Adjusts treated data based on initial data
void MainWindow::treatment(double t[]){
    for (int i = 0; i < 7; i++) {
        fd1[i] = t[i] + 0.1;
        fd2[i] = fd1[i] + 0.1;
        fd3[i] = fd2[i] + 0.1;
        fTd[i] = fd3[i] + 0.1;
    }
}

// Calculates a mathematical value based on signal data
double MainWindow::math(SignalData t[], int size) {
    double numerator = 0.0;
    double denominator = 0.0;
    for (int i = 0; i < size; ++i) {
        numerator += t[i].frequency * (t[i].amplitude * t[i].amplitude);
        denominator += (t[i].amplitude * t[i].amplitude);
    }
    if (denominator == 0) {
        qWarning() << "Denominator is zero, cannot divide by zero.";
        return -1; // Error handling
    }
    return numerator / denominator;
}


void MainWindow:: countDownF(){
    countDown->start();
    ui->counter->setVisible(true);
    ui->label_3->setVisible(true);
    if (ui->counter->value() != 0) {
            ui->counter->setValue(ui->counter->value() - 10);
    } else { // Battery empty
        off();
        ui->counter->setValue(ui->counter->value() + 100);
        countDown->stop();
        ui->counter->setVisible(false);
        ui->label_3->setVisible(false);
    }
}
// Initializes timers and state variables
void MainWindow::intil(){
    inputData();
    counter = 0;
    state = 0;
    timer = new QTimer(this);
    timer2 = new QTimer(this);
    timer2->setInterval(1000);
    timer3 = new QTimer(this);
    timer3->setInterval(5000);
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
    if (m_logHistory.isOpen()) {
        m_logHistory.close();
    }
    QFile file("history.txt");
    if (!m_logHistory.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open for reading:" << m_logHistory.errorString();
        return;
    }
    QTextStream in(&m_logHistory);
    QString content = in.readAll();
    ui->Histroylog->setText(content);
    m_logHistory.close();
}

// Starts a session, updates lights, and begins data collection
void MainWindow::start(){
    updateLightIndicator("#0000FF", true); // Blue light on
    updateLightIndicator("#00FF00", false); // Green light off
    updateLightIndicator("#FF0000", false); // Red light off
    flashCount = 0;
    flash->start(); // Start flashing
    QDateTime sessionStartDateTime = ui->dateTimeEdit->dateTime();
    QString sessionStartStr = sessionStartDateTime.toString("yyyy-MM-dd HH:mm");
    timer2->start();
    counter = 1;
    // Setup plot for displaying data
    QCustomPlot *compositeWaveformPlot = findChild<QCustomPlot*>("wavePlot");
    // More setup...
    if (compositeWaveformPlot) {
        setupCompositeWaveformPlot(compositeWaveformPlot, signalArray);
        // More setups...
    } else {
        qDebug() << "Failed to find QCustomPlot widget";
    }
}

// Stops the session, updates lights, and stops timers
void MainWindow::stop(){
   updateLightIndicator("#FF0000", true); // Red light on
   QTimer::singleShot(2000, [this](){
       updateLightIndicator("#FF0000", false); // Turn off red light after 2s
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
    updateLightIndicator("#00FF00", false); // Green light off
}

// Resumes the session, restarts timers, and updates lights
void MainWindow::resume(){
    timer3->stop();
    timer2->start();
    state = 1;
    flashCount = 0;
    flash->start();
    updateLightIndicator("#FF0000", false); // Red light off
}

// Turns on the device, makes UI elements visible, and updates lights
void MainWindow::on(){
    ui->Battery->setVisible(true);
    ui->Start->setVisible(true);
    ui->frame->setVisible(true);
    updateLightIndicator("#00FF00", true); // Green light on
}

// Turns off the device, hides UI elements, and updates lights
void MainWindow::off(){
    ui->Battery->setVisible(false);
    ui->Start->setVisible(false);
    ui->frame->setVisible(false);
    timer2->stop();
    stop();
    updateLightIndicator("#0000FF", false); // Blue light off
    updateLightIndicator("#00FF00", false); // Green light off
    updateLightIndicator("#FF0000", false); // Red light off
    counter = 0;
}

// Handles the power button to toggle device state
void MainWindow::power(){
    if(state == 0){
        on();
        state = 1; // Device is on
    } else if(state == 1){
        off();
        state = 0; // Device is off
    } else if(state == 2){
        off();
        state = 0; // Device is off during session
    }
}

// Updates the battery level based on device state
void MainWindow::updateBattery() {
    if (ui->Battery->value() != 0) {
        if (state == 1) { // Device on
            ui->Battery->setValue(ui->Battery->value() - 1);
        } else if (state == 2) { // Session active
            ui->Battery->setValue(ui->Battery->value() - 2);
            log();
        }
    } else { // Battery empty
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
        GraphWindow* graphWindow = new GraphWindow(this);
        graphWindow->show();
    }
}

// Handles the flashing of the green light
void MainWindow::handleFlash() {
    bool isOn = (flashCount % 2) == 0;
    updateLightIndicator("#00FF00",isOn);
    flashCount++;
    if (flashCount >= 10) {
        flash->stop();
        flashCount = 0;
    }
}

// Handles the flashing of the red light
void MainWindow::handleRedFlash() {
    bool isOn = (redFlashCount % 2) == 0;
    updateLightIndicator("#FF0000",isOn);
    redFlashCount++;
    if (redFlashCount >= 12) {
        redFlash->stop();
        redFlashCount = 0;
    }
}

// Sets up the composite waveform plot for a QCustomPlot widget
void MainWindow::setupCompositeWaveformPlot(QCustomPlot *customPlot, SignalData *l) {
    QVector<double> x(1001), y(1001); // Prepare data points
    double tStep = 1.0 / (x.size() - 1);
    for (int i = 0; i < x.size(); ++i) {
        double t = i * tStep; // Calculate time for each point
        y[i] = l[0].amplitude * qSin(2 * M_PI * l[0].frequency * t) + l[1].amplitude * qSin(2 * M_PI * l[1].frequency * t) + l[2].amplitude * qSin(2 * M_PI * l[2].frequency * t);
    }
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    customPlot->xAxis->setLabel("Time (s)");
    customPlot->yAxis->setLabel("Amplitude");
    customPlot->xAxis->setRange(0, 1);
    customPlot->yAxis->setRange(-2300, 2300);
    customPlot->replot();
}
