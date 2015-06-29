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
