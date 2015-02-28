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
QStringList qslNames;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
        bool ok;
        QInputDialog* inputDialog = new QInputDialog();
        inputDialog->setOptions(QInputDialog::NoButtons);

        //Get user's full name
        QString qsUserInput = QInputDialog::getText(this, tr("Enter Full Name"),tr("User's Full Name:"), QLineEdit::Normal,"", &ok);

        //Split into firstname & surname
        QRegExp rx("(\\ )");
        qslNames = qsUserInput.split(rx);

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

        QMessageBox::information(this,"title", "The Username is " + qsUserName);



    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

