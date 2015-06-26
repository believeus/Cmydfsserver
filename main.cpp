#include <QCoreApplication>
#include <iostream>
#include <QString>
#include <QChar>
#include <QDir>
#include "cn.believeus.server.MyDFSServer.h"
using namespace cn_believeus_server;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString basePath="C:/data/store/";
    MyDFSServer mydfsserver(9999,basePath);


    return a.exec();
}

