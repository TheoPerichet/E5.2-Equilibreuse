#include "reglagesm18.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ReglageSM18 w;
    w.show();
    return a.exec();
}
