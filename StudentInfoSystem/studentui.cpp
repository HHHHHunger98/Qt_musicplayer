#include "studentui.h"
#include "ui_studentui.h"
#include "globals.h"

#include <QSqlQuery>
#include <QSqlError>

StudentUI::StudentUI(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StudentUI)
{
    ui->setupUi(this);

    //Display the personal information on the screen.
    if (db.isOpen()) {

        QSqlQuery query(db);
        QString sqlQuery = "SELECT std_id, std_name, birthday, gender, program, studyField FROM "+loginType+" WHERE std_id = '" + user_id + "'";

        query.exec(sqlQuery);
        query.next();

        QString std_name = query.value(1).toString();
        QString birthday = query.value(2).toString();
        QString gender = query.value(3).toString();
        QString program = query.value(4).toString();
        QString study_field = query.value(5).toString();

        ui->label_name->setText("Name: " + std_name);
        ui->label_std_id->setText("Student ID: " + user_id);
        ui->label_study_major->setText("Course of study: " + study_field);
        ui->label_birthday->setText("Birthday: " + birthday);
        ui->label_gender->setText("Gender: " + gender);
        ui->label_program->setText("Program: " + program);
    } else {
        qDebug() << db.lastError().text();
    }
}

StudentUI::~StudentUI()
{
    delete ui;
}

void StudentUI::on_pushButton_logout_clicked()
{
    emit logout();
    StudentUI::close();
}

