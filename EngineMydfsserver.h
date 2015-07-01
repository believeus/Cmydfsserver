#include <QtNetwork/QTcpServer>
#include <QThreadPool>

//ACE socket epoll  mongoose
class EngineMydfsserver:public QTcpServer
{
    Q_OBJECT
public:
    EngineMydfsserver(QString basepath,quint16 port,int worker);
private:
    QThreadPool *   threadpool;
    QString         basepath;
    quint16         port;
    int             worker;
public:
    void start();
    void incomingConnection(qintptr socketDescriptor);

};
