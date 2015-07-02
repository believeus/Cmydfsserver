#include <iostream>
#include <QString>
#include <QtNetwork/QHostAddress>
#include <QThread>
#include "EngineTask.h"


EngineTask::EngineTask(QTcpServer * tcpserver,qintptr socketDescriptor)
{
    this->isRun=true;
    this->taskCore=new TaskCore();
    this->tcpserver=tcpserver;
    this->tcpsocket=new QTcpSocket();
    this->tcpsocket->setSocketDescriptor(socketDescriptor);
    QObject::connect(this->tcpserver,SIGNAL(newConnection()),this,SLOT(processConnection()));
    QObject::connect(this->tcpsocket,SIGNAL(readyRead()),this,SLOT(processData()));
    QObject::connect(this->tcpsocket,SIGNAL(readChannelFinished()),this,SLOT(close()));
}
EngineTask:: ~EngineTask(){
    delete this->tcpsocket;
    std::cout<<"~EngineTask():"<<this->isRun<<std::endl;
}
void EngineTask::run(){
    do{
        QThread::usleep(20);
        if(!isRun)return;
    }while(true);
}
void EngineTask::processConnection(){
    //获取客户端的ip地址
    std::cout<<"client ip:"<<this->tcpsocket->peerAddress().toString().toStdString()<<std::endl;
}
void EngineTask::processData(){
    QString data =QString(this->tcpsocket->readLine());
    if(data=="upload"){
        taskCore->upload();
    }
    std::cout<<"server rec:"<<data.toStdString()<<std::endl;

}
void EngineTask::close(){
    this->isRun=false;
    std::cout<<"server close():"<<std::endl;
}
