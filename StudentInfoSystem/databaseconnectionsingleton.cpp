#include "databaseconnectionsingleton.h"

DatabaseConnectionSingleton::DatabaseConnectionSingleton() {}

QSqlDatabase& DatabaseConnectionSingleton::getConnection(){
    static QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "StudentInfoConnection");

    if (!db.isOpen()){
        db.setHostName("localhost");
        db.setDatabaseName("studentinfo");
        db.setUserName("root");
        db.setPassword("2024mySQL...");

        if (db.open()) {
            qDebug() << "Database connected!";
        } else {
            qDebug() << "Unable to open Database!";
        }
    }

    return db;
}
