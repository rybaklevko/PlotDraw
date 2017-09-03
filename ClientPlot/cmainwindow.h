#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ccontroller.h"

namespace Ui {
class CMainWindow;
}

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CMainWindow(QWidget *parent = 0);
    ~CMainWindow();
    bool isConnected();

private slots:
    void on_mPushButton_clicked();

private:
    Ui::CMainWindow *ui;
    CController *mController;
};

#endif // MAINWINDOW_H
