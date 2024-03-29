#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDebug>
#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void start();
//    void log();
    void power();
    void on();
    void off();
    void updateBattery();
    void intil();

private:
    Ui::MainWindow *ui;
    int battery;
    int state;
    QTimer *timer;
};
#endif // MAINWINDOW_H
