#include "calculator.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator c;
    c.start();
    return a.exec();

}
