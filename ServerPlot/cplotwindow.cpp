#include "cplotwindow.h"
#include "ui_cplotwindow.h"

CPlotWindow::CPlotWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CPlotWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Plot");

    mModel = new CModel;
    mController = new CController(mModel);
    connect(mController,SIGNAL(signalPlotChanged()),
            this,SLOT(reDraw()));
    createGraph();
}

CPlotWindow::~CPlotWindow()
{
    delete mModel;
    delete mController;
    delete ui;
}

//draw graph first time
void CPlotWindow::createGraph()
{
    ui->mPlot->addGraph();
    // set color of the line
    ui->mPlot->graph(0)->setPen(QPen(Qt::blue));

    // add circles on the points of graph
    ui->mPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle));
    ui->mPlot->addGraph();
}

//slot, which redraw graph
void CPlotWindow::reDraw()
{
    setParametres();
    ui->mPlot->replot();
    ui->mPlot->update();
}

//set values coordinates to graph
//make grap view proportional to values
//add graph control
void CPlotWindow::setParametres()
{
    ui->mPlot->graph(0)
            ->setData(mModel->getHorizontalX(),mModel->getVerticalY());
    ui->mPlot->graph(0)->rescaleAxes();

    //gives graph control(zoom, graph control etc)
    ui->mPlot->setInteractions(QCP::iRangeDrag
                               | QCP::iRangeZoom
                               | QCP::iSelectPlottables);
}
