#ifndef STUDENTINFOSYSTEM_H
#define STUDENTINFOSYSTEM_H

#include <QMainWindow>
#include <QButtonGroup>
#include "systemui.h"
#include "studentui.h"

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
    void on_pushButton_Cancel_clicked();
    void return_to_systemUI();

private:
    Ui::StudentInfoSystem *ui;
    SystemUI *sysui;
    StudentUI *std_ui;
    QButtonGroup *groupLoginType;
};
#endif // STUDENTINFOSYSTEM_H
