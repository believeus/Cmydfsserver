#-------------------------------------------------
#
# Project created by QtCreator 2015-06-29T10:27:18
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyDfsServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mydfsfolder.cpp \
    EngineMydfsserver.cpp \
    EngineTask.cpp

HEADERS  += mainwindow.h \
    mydfsfolder.h \
    EngineMydfsserver.h \
    EngineTask.h

FORMS    += mainwindow.ui
