#-------------------------------------------------
#
# Project created by QtCreator 2015-12-16T16:55:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CameraCapture
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/include

LIBS += -L/usr/local/lib

