
#include <QRunnable>
#include <QtNetwork/QTcpSocket>
class MydfsTask:public QRunnable{
public:
    MydfsTask(QTcpSocket * tcpsocket){
        this->tcpsocket=tcpsocket;
    }
private:
    QTcpSocket * tcpsocket;
public:
    void run(){}
};

