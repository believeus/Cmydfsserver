#ifndef CN_BELIEVEUS_SERVER_MYDFSFOLDER_H
#define CN_BELIEVEUS_SERVER_MYDFSFOLDER_H

#endif // CN_BELIEVEUS_SERVER_MYDFSFOLDER_H

#include <iostream>
#include <QString>
#include <QDir>
class MyDfsFolder{
public:
    MyDfsFolder(QString);

private:
    static char c[];

public:
    void init(QString);
private:
    void initFolder(QString,bool);
};



