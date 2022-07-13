#include "qtOpenGL.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qtOpenGL w;
    w.show();
    return a.exec();
}
