#include "TaskCore.h"
#include <QUuid>
#include <iostream>
TaskCore::TaskCore()
{

}
void TaskCore::upload(){
    QUuid id = QUuid::createUuid();
    QString strId = id.toString();
    std::cout<<strId.toStdString()<<std::endl;
}
