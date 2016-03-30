#-------------------------------------------------
#
# Project created by QtCreator 2015-12-24T19:28:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 1_Erosion_and_Dilation_GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    erodeanddialate.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/include

LIBS += -L/usr/local/lib

LIBS += -lopencv_core \
        -lopencv_imgproc \
        -lopencv_highgui
