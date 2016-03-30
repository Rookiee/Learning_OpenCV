#-------------------------------------------------
#
# Project created by QtCreator 2015-12-03T20:59:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenCVGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/include

LIBS += -L/usr/local/lib
LIBS += -lopencv_core -lopencv_highgui -lopencv_imgproc

