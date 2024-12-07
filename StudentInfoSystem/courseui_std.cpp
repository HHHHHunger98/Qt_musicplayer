#include "courseui_std.h"
#include "ui_courseui_std.h"
#include "globals.h"

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QObject>

courseui_std::courseui_std(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::courseui_std)
{
    ui->setupUi(this);

    connect(ui->tableView, SIGNAL(clicked(bool)), this, SLOT(onItemClicked()));

    // query all the courses data
    if (db.isOpen()) {
        QString sqlQuery = "SELECT * FROM Courses "
                           "WHERE c_id IN "
                           "(SELECT c_id FROM Enrollment WHERE std_id = '" + user_id + "')";

        QSqlQueryModel *model_course = new QSqlQueryModel();
        QSqlQuery *query = new QSqlQuery(db);
        query->prepare(sqlQuery);
        query->exec();
        model_course->setQuery(*query);

        ui->tableView->setModel(model_course);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->resizeRowsToContents();
    }
}

courseui_std::~courseui_std()
{
    delete ui;
}

void courseui_std::on_pushButton_selected_clicked()
{
    if (db.isOpen()) {
        QString sqlQuery = "SELECT * FROM Courses "
                           "WHERE c_id IN "
                           "(SELECT c_id FROM Enrollment WHERE std_id = '" + user_id + "')";

        QSqlQueryModel *model_course = new QSqlQueryModel();
        QSqlQuery *query = new QSqlQuery(db);
        query->prepare(sqlQuery);
        query->exec();
        model_course->setQuery(*query);

        ui->tableView->setModel(model_course);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->resizeRowsToContents();
    }
}


void courseui_std::on_pushButton_courses_clicked()
{
    if (db.isOpen()) {

        QSqlQueryModel *model_course = new QSqlQueryModel();
        QSqlQuery *query = new QSqlQuery(db);
        query->prepare("SELECT * FROM Courses ");
        query->exec();
        model_course->setQuery(*query);

        ui->tableView->setModel(model_course);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->resizeRowsToContents();
    }
}

void courseui_std::onItemClicked(){


}
