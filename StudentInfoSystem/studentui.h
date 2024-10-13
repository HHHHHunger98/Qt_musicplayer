#ifndef STUDENTUI_H
#define STUDENTUI_H

#include <QDialog>

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

private:
    Ui::StudentUI *ui;
};

#endif // STUDENTUI_H
