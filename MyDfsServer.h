#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <iostream>
#include <QString>
#include <QByteArray>
#include <QObject>

class MyDFSServer : public QObject
{
    Q_OBJECT
 //构造函数
public:
    MyDFSServer(QString basePath,quint16 port);
private:
    quint16 port;
private:
     QTcpServer *tcpserver;
     QTcpSocket *clientSocket;//读写套接字
public:
     void start();
private slots:
    void processConnection();
    void processText();
};


