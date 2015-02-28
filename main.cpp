/*
    Author : Justin Porteous
    Student : 51565579
    Assignment 1 Question 1
    Unique assignment no: 576435
 */

#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
