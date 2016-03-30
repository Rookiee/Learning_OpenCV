QT += core
QT -= gui

TARGET = 10_1VideoCapture
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    videoprocessing.cpp \
    main.cpp

INCLUDEPATH += /usr/local/include

LIBS += -L/usr/local/lib

LIBS += -lopencv_core \
        -lopencv_highgui \
        -lopencv_imgproc
HEADERS += \
    videoprocessor.h
