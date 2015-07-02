#include "mainwindow.h"
#include <QApplication>
#include <QtNetwork/QTcpSocket>
#include <EngineMydfsserver.h>
#include <QThread>
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QString basepath="C:/data/mydfs/store/";
    quint16 port=9999;
    int worker=4;
    //启动服务器端程序
    EngineMydfsserver engineServer(basepath,port,worker);
    engineServer.start();


    QTcpSocket  tcpsocket;
    tcpsocket.abort();
    tcpsocket.connectToHost("127.0.0.1", 9999);
    tcpsocket.waitForConnected();
    tcpsocket.write("upload");
    tcpsocket.waitForBytesWritten();
    tcpsocket.close();

    MainWindow w;
    w.show();

    return a.exec();
}
