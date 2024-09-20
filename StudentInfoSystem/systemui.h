#ifndef SYSTEMUI_H
#define SYSTEMUI_H

#include <QDialog>

namespace Ui {
class SystemUI;
}

class SystemUI : public QDialog
{
    Q_OBJECT

public:
    explicit SystemUI(QWidget *parent = nullptr);
    ~SystemUI();

private:
    Ui::SystemUI *ui;
};

#endif // SYSTEMUI_H
