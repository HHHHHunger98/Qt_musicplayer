#include "studentinfosystem.h"
#include "ui_studentinfosystem.h"
#include "databaseconnectionsingleton.h"
#include "globals.h"

#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>


StudentInfoSystem::StudentInfoSystem(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StudentInfoSystem)
{
    ui->setupUi(this);
    ui->lineEdit_Password->setEchoMode(QLineEdit::Password);
    ui->lineEdit_UserID->setText("1");
    ui->lineEdit_Password->setText("123456");

    groupLoginType = new QButtonGroup(this);
    groupLoginType->addButton(ui->radioButton_Student,0);
    groupLoginType->addButton(ui->radioButton_Teacher,1);
    groupLoginType->addButton(ui->radioButton_Administrator,2);
    ui->radioButton_Student->setChecked(true);
    loginType = "Students";
    primaryKeyForQuery = "std_id";

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
        primaryKeyForQuery = "std_id";
        break;
    case 1:
        loginType = "Teachers";
        primaryKeyForQuery = "t_id";
        break;
    case 2:
        loginType = "Administrators";
        primaryKeyForQuery = "ad_name";
        break;
    }
}

void StudentInfoSystem::on_pushButton_Login_clicked()
{
    QString userid = ui->lineEdit_UserID->text();
    QString password = ui->lineEdit_Password->text();

    // get the connection to database.
    db = DatabaseConnectionSingleton::getConnection();

    /*
     * Logic:
     * if database is opened
     *      generate query to check the validation of input value
     *      enter the UI of system
     * else
     *      inform the user of the failure
    */
    if (db.isOpen()) {

        QSqlQuery query(db);

        /*
         * generate sql query statement
         * Three different login type:
         * 1. Studuents      PR_KEY: std_id
         * 2. Teachers       PR_KEY: t_id
         * 3. Administrators PR_KEY: ad_name
         *
         *
        */

        QString sqlQuery = "SELECT pwd FROM " + loginType + " WHERE " + primaryKeyForQuery + "='" + userid + "';";

        qDebug() << sqlQuery;
        query.exec(sqlQuery);
        qDebug() << query.next();

        if (query.value(0).toString() == password) {

            user_id = userid;
            user_pwd = password;
            switch (groupLoginType->checkedId()) {
                case 0:
                    this->hide();
                    std_ui = new StudentUI(this);
                    connect(std_ui,&StudentUI::logout, this, &StudentInfoSystem::return_to_systemUI);
                    std_ui->show();
                    break;
                case 1:
                    break;
                case 2:
                    break;
            }
        }else{
            QMessageBox::warning(this, "Login", "Invalid user id or password");
        }
    }
    else {
        QMessageBox::warning(this, "Login", db.lastError().text());
    }
}


void StudentInfoSystem::on_pushButton_Cancel_clicked()
{
    QApplication::quit();
}

void StudentInfoSystem::return_to_systemUI()
{
    this->show();
}
