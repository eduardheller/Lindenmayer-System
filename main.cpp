#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
	wndMain w;

    w.setWindowTitle("Stochastic L-Systems");
    w.show();

    return a.exec();
}
