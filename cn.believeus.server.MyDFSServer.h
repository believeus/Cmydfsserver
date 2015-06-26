#include <QtNetwork/QTcpServer>
#include <QtNetwork/QHostAddress>
#include <iostream>
#include <QString>
#include "cn.believeus.server.MyDFSFolder.h"

using namespace cn_believeus_server;

namespace cn_believeus_server {
class MyDFSServer{
public:
    MyDFSServer(int port,QString basePath);
private:
    int port;
    MyDfsFolder mydfsFolder;

public:
    void setPort(int port);
    int getPort();
};

MyDFSServer::MyDFSServer(int port,QString basepath){
    this->port=port;
    mydfsFolder.init(basepath);
}


//Begin---------------set get------------------------------------------
int MyDFSServer::getPort(){
    return this->port;
}
void MyDFSServer::setPort(int port){
    this->port=port;
}


//Een---------------set get------------------------------------------

