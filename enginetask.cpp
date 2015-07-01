#include <iostream>
#include <QString>
#include <QtNetwork/QHostAddress>
#include "EngineTask.h"

EngineTask::EngineTask(QTcpServer * tcpserver,qintptr socketDescriptor)
{
    this->isRun=true;
    this->tcpserver=tcpserver;
    this->tcpsocket=new QTcpSocket();
    this->tcpsocket->setSocketDescriptor(socketDescriptor);
    QObject::connect(this->tcpserver,SIGNAL(newConnection()),this,SLOT(processConnection()));
    QObject::connect(this->tcpsocket,SIGNAL(readyRead()),this,SLOT(processData()));
}
void EngineTask::run(){
    std::cout<<this->isRun<<std::endl;
    while (this->isRun) {
     std::cout<<this->isRun<<std::endl;
    }
}
void EngineTask::processConnection(){
     //获取客户端的ip地址
     std::cout<<"client ip:"<<this->tcpsocket->peerAddress().toString().toStdString()<<std::endl;
}
void EngineTask::processData(){
     QString data =QString(this->tcpsocket->readLine());
     std::cout<<"server rec:"<<data.toStdString()<<std::endl;
     this->isRun=false;
}
