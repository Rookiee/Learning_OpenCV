QT += core
QT -= gui

TARGET = ProbabilisticHoughTransform
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

INCLUDEPATH += /usr/local/include

LIBS += -L/usr/local/lib

LIBS += -lopencv_core \
        -lopencv_highgui \
        -lopencv_imgproc

HEADERS += \
    linefinder.h
