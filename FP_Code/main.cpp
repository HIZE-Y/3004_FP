#include "mainwindow.h"
#include "graphwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    GraphWindow v;
    w.show();
    return a.exec();
}
