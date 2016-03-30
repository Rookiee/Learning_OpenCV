QT += core
QT -= gui

TARGET = 9_test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    CameraCalibrator.cpp \
    main.cpp

INCLUDEPATH += /usr/local/include

LIBS += -L/usr/local/lib

LIBS += -lopencv_core \
        -lopencv_highgui \
        -lopencv_imgproc \
        -lopencv_features2d \
        -lopencv_calib3d

HEADERS += \
    CameraCalibrator.h
