#include "studentinfosystem.h"
#include "ui_studentinfosystem.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QDebug>

StudentInfoSystem::StudentInfoSystem(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StudentInfoSystem)
{
    ui->setupUi(this);
    qDebug() <<  QSqlDatabase::drivers();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("studentinfo");
    db.setUserName("root");
    db.setPassword("2024mySQL...");
    bool ok = db.open();
    qDebug() << ok;
}

StudentInfoSystem::~StudentInfoSystem()
{
    delete ui;
}

void StudentInfoSystem::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();

    if (username == "me" && password == "123") {
        QMessageBox::information(this, "Login", "Yes, password and username is correct!");
        hide();
        sysui = new SystemUI(this);
        sysui->show();
    }
    else {
        QMessageBox::warning(this, "Login", "The username and the password is incorrect");
    }
}

