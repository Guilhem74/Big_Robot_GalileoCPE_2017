
#include "CustomPlot.h"

CustomPlot::CustomPlot(QWidget *parent) :
    QCustomPlot(parent)
{

    xAxis->setRange(0, 1000);
    yAxis->setRange(-5000, 5000);
}


CustomPlot::~CustomPlot()
{

}

