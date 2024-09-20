#include "systemui.h"
#include "ui_systemui.h"

SystemUI::SystemUI(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SystemUI)
{
    ui->setupUi(this);
}

SystemUI::~SystemUI()
{
    delete ui;
}
