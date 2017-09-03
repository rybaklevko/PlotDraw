#include "cmodel.h"

CModel::CModel() : valueX(0)
{

}

//add new value to the list(QVector) on numbers
void CModel::addPoint(int newValue)
{
    //horizontal values are in order
    //like 0,1,2,...
    valueX++;
    horizontalValuesX.push_back(valueX);
    verticalValuesY.push_back(newValue);
}

//return vertical values
QVector<double> CModel::getHorizontalX()
{
    return horizontalValuesX;
}

//return horizontal values
QVector<double> CModel::getVerticalY()
{
    return verticalValuesY;
}
