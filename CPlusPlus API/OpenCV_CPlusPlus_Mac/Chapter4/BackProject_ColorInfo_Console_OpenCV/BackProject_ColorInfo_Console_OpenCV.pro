QT += core
QT -= gui

TARGET = BackProject_ColorInfo_Console_OpenCV
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

INCLUDEPATH += /usr/local/include

LIBS += -L/usr/local/lib

LIBS += -lopencv_core \
        -lopencv_highgui \
        -lopencv_imgproc -lopencv_ml \
        -lopencv_video -lopencv_features2d \
        -lopencv_calib3d -lopencv_objdetect \
        -lopencv_contrib -lopencv_legacy \
        -lopencv_flann



HEADERS += \
    contentfinder.h \
    reducecolor.h \
    colorhistogram.h
