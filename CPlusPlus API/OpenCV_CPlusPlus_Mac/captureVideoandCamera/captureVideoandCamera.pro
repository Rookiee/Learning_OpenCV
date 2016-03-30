QT += core
QT -= gui


TARGET = captureVideoandCamera
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.10



INCLUDEPATH += /usr/local/include/

LIBS += -L/usr/local/lib

LIBS += -lopencv_core

LIBS += -lopencv_imgproc

LIBS += -lopencv_highgui

LIBS += -lopencv_ml

LIBS += -lopencv_video

LIBS += -lopencv_features2d

LIBS += -lopencv_calib3d

LIBS += -lopencv_objdetect

LIBS += -lopencv_flann

LIBS += -lopencv_imgcodecs
