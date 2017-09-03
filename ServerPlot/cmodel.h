#ifndef CMODEL_H
#define CMODEL_H

#include <QObject>
#include <QVector>
#include <QHostAddress>

const int kDefaultTimeValue = 100;
const QHostAddress kDefaultAddress = QHostAddress::Any;
const qint16 kDefaultPortNumber = 8080;

class CModel : public QObject
{
    Q_OBJECT
public:
    CModel();
    void addPoint(int newValue);
    QVector<double>getHorizontalX();
    QVector<double>getVerticalY();

signals:

public slots:

private:
    QVector<double> horizontalValuesX, verticalValuesY;
    int valueX;
};

#endif // CMODEL_H
