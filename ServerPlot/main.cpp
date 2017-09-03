#include "cplotwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CPlotWindow w;
    w.show();

    return a.exec();
}
