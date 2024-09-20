#ifndef STUDENTINFOSYSTEM_H
#define STUDENTINFOSYSTEM_H

#include <QMainWindow>
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

private:
    Ui::StudentInfoSystem *ui;
    SystemUI *sysui;
};
#endif // STUDENTINFOSYSTEM_H
