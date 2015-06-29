#include "MyDfsFolder.h"
#include "MyDFSServer.h"
#include <QString>
//构造函数
MyDFSServer::MyDFSServer(QString basepath,quint16 port,int workers){
    this->port=port;
    MyDfsFolder mydfsFolder(basepath);
    mydfsFolder.init(basepath);
    this->threadPool=QThreadPool::globalInstance();
    this->threadPool->setMaxThreadCount(workers);

}
void MyDFSServer::start(){
    this->tcpserver=new QTcpServer;
    this->tcpserver->listen(QHostAddress::Any,this->port);
    //当有新的连接连接调用processConnection方法
    connect(tcpserver,SIGNAL(newConnection()),this,SLOT(processConnection()));
}
void MyDFSServer::processConnection(){
    this->socket=this->tcpserver->nextPendingConnection();
    connect(this->socket,SIGNAL(readyRead()),this,SLOT(processText()));
    std::cout<<"hello client:"<<std::endl;

}
void MyDFSServer::processText(){
    QTcpSocket * socket=this->socket;
    QString data =QString(socket->readLine());
    //获取客户端的ip地址
    std::cout<<"client ip:"<<socket->peerAddress().toString().toStdString()<<std::endl;
    std::cout<<"server rec:"<<data.toStdString()<<std::endl;

}

