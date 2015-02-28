/*
    Author : Justin Porteous
    Student : 51565579
    Assignment 1 Question 1
    Unique assignment no: 576435
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString GetRandomString(QString qsInputString, int length, QString qsInvalidCharacters);
    void GenerateUserDetails();

private slots:


private slots:
    void on_pbGenerateDetails_clicked();
};

#endif // MAINWINDOW_H
