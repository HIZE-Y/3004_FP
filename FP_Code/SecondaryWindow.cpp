#include "SecondaryWindow.h"
#include "ui_
SecondaryWindow::SecondaryWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondaryWindow)
{
    ui->setupUi(this);
    // Set up the window (you can customize your UI here)
}

SecondaryWindow::~SecondaryWindow() {
    delete ui;
}
