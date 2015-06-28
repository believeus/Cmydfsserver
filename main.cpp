#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include "MyDfsServer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    quint16 port=12000;
    QString basepath="D:/data/mydfs/store/";
    MyDFSServer mydfsserver(basepath,port);
    mydfsserver.start();

    QTcpSocket *tcpSocket = new QTcpSocket;
    tcpSocket->abort();
    tcpSocket->connectToHost(QHostAddress::LocalHost,port);
    MainWindow w;
    w.show();

    return a.exec();
}
