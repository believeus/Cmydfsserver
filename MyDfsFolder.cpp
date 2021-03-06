#include "MyDfsFolder.h"
//定义静态变量
char MyDfsFolder::c[]={'0','1','2','3','4',
                       '5','6','7','8','9',
                       'A','B','C','D','E','F'};

MyDfsFolder::MyDfsFolder(QString basepath){
    this->basepath=basepath;
}

void MyDfsFolder::init(){
    QDir dir(this->basepath);

    try{
        if(dir.exists()){
            std::cout<<this->basepath.toStdString()<<" has exsits;"<<std::endl;
        }else{
            dir.mkdir(this->basepath);
            std::cout<<"create base path:"<<this->basepath.toStdString()<<std::endl;
        }
        this->initFolder(this->basepath,true);
    }catch(...){
        std::cout<<"exception;"<<std::endl;
    }
}

//初始化文件夹和子文件夹
void MyDfsFolder::initFolder(QString path,bool isCreateSub){

    for (int i = 0; i < sizeof(MyDfsFolder::c);i++) {
        for(int j=0;j<sizeof(MyDfsFolder::c);j++){
            QDir dir(path+"/"+MyDfsFolder::c[i]+MyDfsFolder::c[j]);
            if(!dir.exists()){
               // std::cout<<dir.absolutePath().toStdString()<<std::endl;
                bool success=dir.mkdir(path+"/"+c[i]+MyDfsFolder::c[j]);
                if(success&&isCreateSub){
                    //递归方法,方法又是新方法了,变量都是新的
                    this->initFolder(path+"/"+c[i]+c[j]+"/",false);
                }

            }

        }
    }
}

