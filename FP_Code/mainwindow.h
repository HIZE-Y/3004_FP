#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDebug>
#include <QMainWindow>
#include <QFile>

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

private:
    Ui::MainWindow *ui;
    int battery;
    int state;
    QFile m_logHistory;
};
#endif // MAINWINDOW_H
