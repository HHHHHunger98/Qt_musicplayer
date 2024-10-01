#ifndef STUDENTINFOSYSTEM_H
#define STUDENTINFOSYSTEM_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QSqlDatabase>
#include "systemui.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class StudentInfoSystem;
}
QT_END_NAMESPACE

class StudentInfoSystem : public QMainWindow
{
    Q_OBJECT

public:
    StudentInfoSystem(QWidget *parent = nullptr);
    ~StudentInfoSystem();

private slots:
    void on_pushButton_Login_clicked();
    void slots_loginType();

private:
    Ui::StudentInfoSystem *ui;
    SystemUI *sysui;
    QButtonGroup *groupLoginType;
    QString loginType;
    QSqlDatabase db;
};
#endif // STUDENTINFOSYSTEM_H
