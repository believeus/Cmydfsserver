#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QRunnable>
#include <QThreadPool>
#include <mydfsserver.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString basepath="C:/data/store";
    quint16 port=9999;
    int worker=4;
    //启动服务器端程序
    MyDFSServer mydfserver(basepath,port,worker);
    mydfserver.start();

    QTcpSocket  tcpsocket;
    tcpsocket.abort();
    tcpsocket.connectToHost("127.0.0.1", 9999);
    tcpsocket.waitForConnected();
    tcpsocket.write("Hello World!");
    tcpsocket.waitForBytesWritten();
    tcpsocket.write("Bye!");
    tcpsocket.waitForBytesWritten();
    tcpsocket.close();

    MainWindow w;
    w.show();

    return a.exec();
}
