#include "cmainwindow.h"
#include "ui_cmainwindow.h"

CMainWindow::CMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CMainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("SpinnedBox");

    ui->mSpinBox->setMaximum(10000);
    ui->mSpinBox->setMinimum(-10000);

    mController = new CController;
}

CMainWindow::~CMainWindow()
{
    delete mController;
    delete ui;
}

//check does connection was made
bool CMainWindow::isConnected()
{
    if (mController->makeConnection()) {
        return true;
    } else {
        return false;
    }
}

//after button was clicked
//send current value of spinbox to server
void CMainWindow::on_mPushButton_clicked()
{
    mController->sendData( QString::number(ui->mSpinBox->value()) );
}
