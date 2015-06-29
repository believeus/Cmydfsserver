#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <iostream>
#include <QString>
#include <QByteArray>
#include <QObject>
#include <QThreadPool>
#include "mydfstask.h"
class MyDFSServer : public QObject
{
    Q_OBJECT
 //构造函数
public:
    MyDFSServer(QString basePath,quint16 port,int workers);
private:
    quint16 port;
    int workers;
    QTcpServer *tcpserver;
    QTcpSocket *socket;//读写套接字
    QThreadPool * threadPool;
    MydfsTask * task;
public:
     void start();
private slots:
    void processConnection();
    void processText();
};
