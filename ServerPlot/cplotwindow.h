#ifndef CPLOTWINDOW_H
#define CPLOTWINDOW_H

#include <QMainWindow>
#include <ccontroller.h>

namespace Ui {
class CPlotWindow;
}

class CPlotWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CPlotWindow(QWidget *parent = 0);
    ~CPlotWindow();
    void createGraph();
    void setParametres();

public slots:
    void reDraw();


private:
    Ui::CPlotWindow *ui;
    CController *mController;
    CModel *mModel;
};

#endif // CPLOTWINDOW_H
