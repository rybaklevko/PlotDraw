#include "ccontroller.h"

CController::CController(QObject *parent) : QObject(parent)
{
    mSocket = new QTcpSocket();
}

//try to make connection
bool CController::makeConnection()
{
    mSocket->connectToHost(kDefaultAddress,kDefaultPortNumber);
    if (mSocket->waitForConnected(kDefaultTimeValue)) {
        qDebug()<<"Connected!";
    } else {
        qDebug()<<"Wasn't connected!";
        mSocket->close();
        return false;
    }
    return true;
}

//function,which send data
void CController::sendData(const QString &data)
{
    QByteArray request;
    request.append("HTTP/1.1 200 OK\r\n");
    request.append("Content-Type: text/plain\r\n");
    request.append("Content-Length:" + QString::number(data.size()) + "\r\n");
    request.append("Connection: close\r\n\r\n");
    request.append(data);
    mSocket->write(request);
    mSocket->flush();
    mSocket->waitForBytesWritten(kDefaultTimeValue);
}
