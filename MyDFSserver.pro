#-------------------------------------------------
#
# Project created by QtCreator 2015-06-28T21:20:52
#
#-------------------------------------------------
#-----------------------------------------------
#此处的network是我添加上去的,因为我使用了<QtNetwork/QTcpSocket>
#故而需要添加network
#-----------------------------------------------
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyDFSserver
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    MyDfsServer.cpp \
    MyDfsFolder.cpp \

HEADERS  += mainwindow.h \
    MyDfsFolder.h \
    MyDfsServer.h

FORMS    += mainwindow.ui
