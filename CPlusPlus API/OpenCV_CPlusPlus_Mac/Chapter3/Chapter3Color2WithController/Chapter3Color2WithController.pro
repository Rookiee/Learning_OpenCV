#-------------------------------------------------
#
# Project created by QtCreator 2015-12-18T21:11:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chapter3Color2WithController
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    colordetector.cpp \
    colordetectorcontroller.cpp

HEADERS  += mainwindow.h \
    colordetector.h \
    colordetectorcontroller.h

FORMS    += mainwindow.ui



INCLUDEPATH += /usr/local/include

LIBS += -L/usr/local/lib

LIBS += -lopencv_core \
        -lopencv_highgui

