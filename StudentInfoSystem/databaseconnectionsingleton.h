#ifndef DATABASECONNECTIONSINGLETON_H
#define DATABASECONNECTIONSINGLETON_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

class DatabaseConnectionSingleton
{
public:
    static QSqlDatabase& getConnection();
private:
    // Set the constructor as private, and delete the copy construtor and assignment.
    DatabaseConnectionSingleton();
    DatabaseConnectionSingleton(const DatabaseConnectionSingleton&) = delete;
    DatabaseConnectionSingleton& operator=(const DatabaseConnectionSingleton&) = delete;
};

#endif // DATABASECONNECTIONSINGLETON_H
