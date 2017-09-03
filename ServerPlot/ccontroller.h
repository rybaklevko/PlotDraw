#ifndef CCONTROLLER_H
#define CCONTROLLER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "cmodel.h"

class CController : public QObject
{
    Q_OBJECT
public:
    CController(CModel *model);
    void parseNewValue(const QString &data);
    int findMessageLength(std::string &data);
    int findValue(QString data);

signals:
    void signalPlotChanged();

public slots:
    void slotNewClientConnection();
    void slotClientDisconnect();
    void slotReadDataFromSocket();

private:
    QTcpServer *mTcpServer;
    CModel *mModel;
};

#endif // CCONTROLLER_H
