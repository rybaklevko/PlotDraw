#include "cmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CMainWindow w;
    if( !w.isConnected()) {
        return false;
    }
    w.show();

    return a.exec();
}
