#-------------------------------------------------
#
# Project created by QtCreator 2020-03-04T17:25:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_tutorials
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    subwindow.cpp \
    ssubwindow.cpp \
    counterwindow.cpp \
    storywindow.cpp

HEADERS  += mainwindow.h \
    subwindow.h \
    ssubwindow.h \
    counterwindow.h \
    storywindow.h

FORMS    += mainwindow.ui \
    subwindow.ui \
    ssubwindow.ui \
    counterwindow.ui \
    storywindow.ui

RESOURCES += \
    font.qrc \
    img.qrc
