QT += core
QT -= gui

TARGET = RetrievingSimilarImages
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    colorhistogram.h \
    imagecomparator.h

INCLUDEPATH += /usr/local/include

LIBS += -L/usr/local/lib

LIBS += -lopencv_core \
        -lopencv_highgui \
        -lopencv_imgproc

