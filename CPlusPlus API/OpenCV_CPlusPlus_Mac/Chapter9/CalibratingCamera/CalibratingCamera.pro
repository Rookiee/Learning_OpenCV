QT += core
QT -= gui

TARGET = CalibratingCamera
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    cameracalibrator.cpp

INCLUDEPATH += /usr/local/include

LIBS += -L/usr/local/lib

LIBS += -lopencv_core \
        -lopencv_highgui \
        -lopencv_imgproc \
        -lopencv_features2d \
        -lopencv_calib3d

HEADERS += \
    cameracalibrator.h
