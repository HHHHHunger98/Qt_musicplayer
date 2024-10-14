#ifndef STUDENTUI_H
#define STUDENTUI_H

#include <QDialog>
#include "courseui_std.h"

namespace Ui {
class StudentUI;
}

class StudentUI : public QDialog
{
    Q_OBJECT

public:
    explicit StudentUI(QWidget *parent = nullptr);
    ~StudentUI();

signals:
    void logout();

private slots:
    void on_pushButton_logout_clicked();

    void on_pushButton_courses_clicked();

private:
    Ui::StudentUI *ui;
    courseui_std *c_std_ui;
};

#endif // STUDENTUI_H
