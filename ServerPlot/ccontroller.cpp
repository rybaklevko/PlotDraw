#include "ccontroller.h"

CController::CController(CModel *model) : mModel(model)
{
    mTcpServer = new QTcpServer();

    //if client connected
    connect(mTcpServer,SIGNAL(newConnection()),
            this,SLOT(slotNewClientConnection()));

    if (!mTcpServer->listen(kDefaultAddress,kDefaultPortNumber)) {
        qDebug()<<"Error with connection!";
    } else {
        qDebug()<<"Started!";
    }
}

//after received new value from client
//add it to all values
//adn redraw plot
void CController::parseNewValue(const QString &data)
{
    int value = findValue(data); // find value coded in http request

    mModel->addPoint(value);

    emit  signalPlotChanged();//emit signal to redraw plot
}

//auxiliary function to find length of number
int CController::findMessageLength(std::string &data)
{
    // length of number is placed after Content-Length:
    std::string substring ("Content-Length:");

    //find substring Content-Length and get value after it
    std::size_t found = data.find(substring);
    found = found + substring.size();

    //change type of value to integer
    const char *s = new char(data[found]);
    int length = atoi(s);
    delete s;

    return length;
}

//find value coded in http request
int CController::findValue(QString data)
{
    std::string stri = data.toStdString();

    //take a coded value from one Qstring
    //and put it to another
    //take length of number from right side of Qstring
    QString str2 = data.right(findMessageLength(stri));

    int value = str2.toInt();

    qDebug()<<str2<<' '<<value;
    return value;
}

//if new client connected
void CController::slotNewClientConnection()
{
    QTcpSocket *socket = new QTcpSocket();
    socket = mTcpServer->nextPendingConnection();

    //signal-slot connection to read data
    connect(socket,SIGNAL(readyRead()),
            this,SLOT(slotReadDataFromSocket()));

    //signal-slot connection to handle disconnect
    connect(socket,SIGNAL(disconnected()),
            this,SLOT(slotClientDisconnect()));
}

//if client was disconnected
//show message about it and close socket
void CController::slotClientDisconnect()
{
    qDebug()<<"Disconnected..";
    QTcpSocket *socket = (QTcpSocket*)sender();
    socket->close();
    socket->deleteLater();
}

//if client send data
//read it from socket and parse
void CController::slotReadDataFromSocket()
{
    QTcpSocket *socket = (QTcpSocket*)sender();
    socket->waitForReadyRead(kDefaultTimeValue);
    QByteArray data = socket->readAll();
    QString receivedData = data;
    qDebug()<<"Message: "<<data;
    parseNewValue(receivedData);
}
