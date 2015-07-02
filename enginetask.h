#ifndef ENGINETASK_H
#define ENGINETASK_H
#include <QRunnable>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include "TaskCore.h"
class EngineTask:public QObject,public QRunnable
{
     Q_OBJECT
private:
    QTcpSocket * tcpsocket;
    QTcpServer * tcpserver;
    TaskCore    *  taskCore;
    bool isRun;
    //构造方法
public:
    EngineTask(QTcpServer * tcpserver,qintptr socketDescriptor);
    ~EngineTask();
public:
   void run();
public slots:
   void processConnection();
   void processData();
   void close();
};

#endif // ENGINETASK_H
