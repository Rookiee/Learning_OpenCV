# -------------------------------------------------
# Project created by QtCreator 2010-09-10T15:33:45
# -------------------------------------------------
QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = color_detector

TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    colordetector.cpp \
    colordetector.cpp \
    colorDetectController.cpp
HEADERS += mainwindow.h \
    colordetector.h \
    colorDetectController.h
FORMS += mainwindow.ui

INCLUDEPATH += /usr/local/include

LIBS += -L/usr/local/lib \
    -lopencv_core \
    -lopencv_highgui \
    -lopencv_imgproc \
    -lopencv_features2d \
    -lopencv_calib3d
