/*
    Author : Justin Porteous
    Student : 51565579
    Assignment 1 Question 1
    Unique assignment no: 576435
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>


int pwFirstnameLength = 1;
int pwSurnameLength = 5;
int pwTotalLength = 6;
QString qsFirstName = "";
QString qsSurname = "";
QString qsPadding = "";
QString qsUserName = "";
QString qsPassword = "";
QString qsFullName = "";
QStringList qslNames;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{


    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GenerateUserDetails()
{
    bool ok;
    QInputDialog* inputDialog = new QInputDialog();
    inputDialog->setOptions(QInputDialog::NoButtons);

    //Get user's full name
    qsFullName = QInputDialog::getText(this, tr("Enter Full Name"),tr("User's Full Name:"), QLineEdit::Normal,"", &ok);

    //Split into firstname & surname
    QRegExp rx("(\\ )");
    qslNames = qsFullName.split(rx);

    //Save firstname & surname
    qsFirstName = qslNames.first();
    qsSurname = qslNames.last();

    //Determine password's structure
    //  1 char from Firstname, 5 Chars from surname
    if (qsSurname.length() < pwSurnameLength)
    {
        pwFirstnameLength =  pwFirstnameLength + (pwSurnameLength - qsSurname.length());
        pwSurnameLength = qsSurname.length();
    }

    //Construct Username
    qsUserName = qsFirstName.mid(0,pwFirstnameLength) + qsSurname.mid(0,pwSurnameLength);

    //Pad with zeros if needed
    if (qsUserName.length() < pwTotalLength)
        qsUserName = qsUserName.leftJustified(pwTotalLength,'0');

    //Generate Password
    qsPassword = GetRandomString(qsFullName,pwTotalLength," ");

    QMessageBox::information(this,"User Created!", "The Username is " + qsUserName + " and the password is " + qsPassword);

}

QString MainWindow::GetRandomString(QString qsInputString, int length, QString qsInvalidCharacters)
{
    QString randomString;

    // Seed the random generator with current time
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    //Remove invalid characters
    for (int i= 0; i <= qsInvalidCharacters.length(); i++)
    {
        qsInputString = qsInputString.replace(qsInvalidCharacters[i],"");
    }

    //Get random string
    for(int i=0; i<length; ++i)
    {
        int index = qrand() % qsInputString.length();
        QChar nextChar = qsInputString.at(index);
        randomString.append(nextChar);
    }

    return randomString;
}

void MainWindow::on_pbGenerateDetails_clicked()
{
    GenerateUserDetails();
    ui->lblFullName->setText(qsFullName);
    ui->lbLogonName->setText(qsUserName);
    ui->lbPassword->setText(qsPassword);
}
