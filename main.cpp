#include "qtcolortable.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtColorTable w;
    w.show();
    return a.exec();
}
