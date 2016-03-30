QT += core
QT -= gui

TARGET = 1_Erosion_and_Dilation_Console
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    erodeanddilate.h

INCLUDEPATH += /usr/local/include

LIBS += -L/usr/local/lib

LIBS += -lopencv_core \
        -lopencv_highgui \
        -lopencv_imgproc
