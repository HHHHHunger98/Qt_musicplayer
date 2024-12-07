#ifndef COURSEUI_STD_H
#define COURSEUI_STD_H

#include <QDialog>

namespace Ui {
class courseui_std;
}

class courseui_std : public QDialog
{
    Q_OBJECT

public:
    explicit courseui_std(QWidget *parent = nullptr);
    ~courseui_std();

private slots:
    void on_pushButton_selected_clicked();
    void on_pushButton_courses_clicked();
    void onItemClicked();

private:
    Ui::courseui_std *ui;
};

#endif // COURSEUI_STD_H
