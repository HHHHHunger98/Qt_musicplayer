#include "courseui_std.h"
#include "ui_courseui_std.h"
#include "globals.h"

#include <QStandardItemModel>
#include <QSqlQuery>

courseui_std::courseui_std(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::courseui_std)
{
    ui->setupUi(this);

    // query all the courses data
    if (db.isOpen()) {
        QString sqlQuery = "SELECT * FROM Courses "
                           "WHERE c_id IN "
                           "(SELECT c_id FROM Enrollment WHERE std_id = '" + user_id + "')";

        QSqlQuery query(db);
        query.exec(sqlQuery);
        qDebug() << sqlQuery;
        while (query.next()) {
            qDebug() << query.value(0).toString();
            qDebug() << query.value(1).toString();
        }
    }
}

courseui_std::~courseui_std()
{
    delete ui;
}
