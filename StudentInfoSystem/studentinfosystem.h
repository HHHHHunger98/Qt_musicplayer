#ifndef STUDENTINFOSYSTEM_H
#define STUDENTINFOSYSTEM_H

#include <QMainWindow>

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

private:
    Ui::StudentInfoSystem *ui;
};
#endif // STUDENTINFOSYSTEM_H
