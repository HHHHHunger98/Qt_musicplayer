#include "studentinfosystem.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StudentInfoSystem w;
    w.show();
    return a.exec();
}
