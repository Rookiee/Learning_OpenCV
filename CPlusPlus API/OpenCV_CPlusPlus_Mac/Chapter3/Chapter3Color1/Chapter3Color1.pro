QT += core
QT -= gui

TARGET = Chapter3Color1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    colordetector.cpp

INCLUDEPATH += /usr/local/include

LIBS += -L/usr/local/lib
LIBS += -lopencv_core -lopencv_highgui

HEADERS += \
    colordetector.h
