QT += core
QT -= gui

TARGET = ROI_Console
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

INCLUDEPATH += /usr/local/include


LIBS += -L/usr/local/lib

LIBS += -lopencv_core
LIBS += -lopencv_highgui



