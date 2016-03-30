#-------------------------------------------------
#
# Project created by QtCreator 2015-12-19T21:10:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chapter3Final
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    colordetector.cpp \
    colordetectcontroller.cpp

HEADERS  += mainwindow.h \
    colordetector.h \
    colordetectcontroller.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/include

LIBS += -L/usr/local/lib

LIBS += -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_features2d \
    -lopencv_calib3d

