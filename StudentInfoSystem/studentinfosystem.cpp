#include "studentinfosystem.h"
#include "ui_studentinfosystem.h"

StudentInfoSystem::StudentInfoSystem(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StudentInfoSystem)
{
    ui->setupUi(this);
}

StudentInfoSystem::~StudentInfoSystem()
{
    delete ui;
}
