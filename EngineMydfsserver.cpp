#include <QtNetwork/QHostAddress>
#include <iostream>
#include "EngineMydfsserver.h"
#include "EngineTask.h"
#include "mydfsfolder.h"
EngineMydfsserver::EngineMydfsserver(QString basepath,quint16 port,int worker){
    std::cout<<"EngineMydfsserver ready start"<<std::endl;
    this->worker=worker;
    this->basepath=basepath;
    this->port=port;

}
void EngineMydfsserver::start(){
    std::cout<<"EngineMydfsserver start up^_^"<<std::endl;
    this->listen(QHostAddress::Any,this->port);
    this->threadpool=QThreadPool::globalInstance();
    this->threadpool->setMaxThreadCount(worker);
    MyDfsFolder mydfsFolder(this->basepath);
    mydfsFolder.init();
}
//服务器每当监听到一个客户端试图建立连接的时候，会自动调用这个函数
void EngineMydfsserver::incomingConnection(qintptr  socketDescriptor){
    std::cout<<"client connect into now"<<std::endl;
    EngineTask * task= new EngineTask(this,socketDescriptor);
    this->threadpool->start(task);
}
