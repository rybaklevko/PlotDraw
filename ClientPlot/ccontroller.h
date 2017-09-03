#ifndef CCONTROLLER_H
#define CCONTROLLER_H

#include <QObject>
#include <QTcpSocket>
#include <QString>
#include <QDebug>

const int kDefaultTimeValue = 100;
const QString kDefaultAddress = "127.0.0.1";
const qint16 kDefaultPortNumber = 8080;

class CController : public QObject
{
    Q_OBJECT
public:
    explicit CController(QObject *parent = 0);
    bool makeConnection();
    void sendData(const QString &data);


signals:

public slots:

private:
    QTcpSocket *mSocket;
};

#endif // CCONTROLLER_H
