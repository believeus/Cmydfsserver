#ifndef ENGINETASK_H
#define ENGINETASK_H
#include <QRunnable>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include "EngineTask.h"
class EngineTask:public QObject,public QRunnable
{
     Q_OBJECT
private:
    QTcpSocket * tcpsocket;
    QTcpServer * tcpserver;
    bool         isRun;
    //构造方法
public:
    EngineTask(QTcpServer * tcpserver,qintptr socketDescriptor);
public:
    void run();
public slots:
   void processConnection();
   void processData();
};

#endif // ENGINETASK_H
