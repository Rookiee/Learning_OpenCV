#-------------------------------------------------
#
# Project created by QtCreator 2015-12-04T21:24:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SaltChapter2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    salt.cpp

HEADERS  += mainwindow.h \
    salt.h \
    reducecolors.h

FORMS    += mainwindow.ui

INCLUDEPATH =+ /usr/local/include

LIBS += -L/usr/local/lib

LIBS += -lopencv_core -lopencv_highgui -lopencv_imgproc
