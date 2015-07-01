#include <iostream>
#include <QString>
#include <QDir>
class MyDfsFolder{
public:
    MyDfsFolder(QString);

private:
    static char c[];
    QString basepath;

public:
    void init();
private:
    void initFolder(QString,bool);
};
