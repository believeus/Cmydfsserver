
#include "MyDfsFolder.h"
#include "MyDFSServer.h"

//构造函数
MyDFSServer::MyDFSServer(QString basepath,quint16 port){
    this->port=port;
    MyDfsFolder mydfsFolder(basepath);
    mydfsFolder.init(basepath);

}
void MyDFSServer::start(){
    this->tcpserver=new QTcpServer;
    this->tcpserver->listen(QHostAddress::Any,this->port);
    connect(tcpserver,SIGNAL(newConnection()),this,SLOT(processConnection()));
}
void MyDFSServer::processConnection(){
    this->clientSocket=this->tcpserver->nextPendingConnection();
    connect(this->clientSocket,SIGNAL(readyRead()),this,SLOT(processText()));
    std::cout<<"hello client"<<std::endl;
}
void MyDFSServer::processText(){
    QByteArray data=this->clientSocket->readAll();
    std::cout<<data.toStdString()<<std::endl;
}
