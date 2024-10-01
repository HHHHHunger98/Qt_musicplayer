#include "studentinfosystem.h"
#include "ui_studentinfosystem.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


StudentInfoSystem::StudentInfoSystem(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StudentInfoSystem)
{
    ui->setupUi(this);
    groupLoginType = new QButtonGroup(this);
    groupLoginType->addButton(ui->radioButton_Student,0);
    groupLoginType->addButton(ui->radioButton_Teacher,1);
    groupLoginType->addButton(ui->radioButton_Administrator,2);
    ui->radioButton_Student->setChecked(true);
    loginType = "Students";

    connect(ui->radioButton_Student, SIGNAL(clicked(bool)), this, SLOT(slots_loginType()));
    connect(ui->radioButton_Teacher, SIGNAL(clicked(bool)), this, SLOT(slots_loginType()));
    connect(ui->radioButton_Administrator, SIGNAL(clicked(bool)), this, SLOT(slots_loginType()));
}

StudentInfoSystem::~StudentInfoSystem()
{
    db.close();
    delete ui;
}

void StudentInfoSystem::slots_loginType(){
    switch (groupLoginType->checkedId()) {
    case 0:
        loginType = "Students";
        break;
    case 1:
        loginType = "Teachers";
        break;
    case 2:
        loginType = "Administrators";
        break;
    }
}

void StudentInfoSystem::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();

    // Add and connect to Database
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("studentinfo");
    db.setUserName("root");
    db.setPassword("2024mySQL...");


    /*
     * Logic:
     * if database is opened
     *      generate query to check the validation of input value
     *      enter the UI of system
     * else
     *      inform the user of the failure
    */
    if (db.open()) {

        QSqlQuery query;
        QString sqlQuery = "SELECT pwd FROM " + loginType + " WHERE std_name='" + username + "';";

        qDebug() << sqlQuery;
        query.exec(sqlQuery);
        qDebug() << query.next();

        if (query.value(0).toString() == password) {

            hide();
            sysui = new SystemUI(this);
            sysui->show();
        }else{
            QMessageBox::warning(this, "Login", "Invalid username or password");
        }
    }
    else {
        QMessageBox::warning(this, "Login", db.lastError().text());
    }
}

