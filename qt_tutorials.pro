#-------------------------------------------------
#
# Project created by QtCreator 2020-03-04T17:25:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_tutorials
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
LIBS += -lKernel32
# this is for solving PSTR conversion problem in GetWindowText
DEFINES -= UNICODE

SOURCES += main.cpp\
        mainwindow.cpp \
    subwindow.cpp \
    ssubwindow.cpp \
    counterwindow.cpp \
    storywindow.cpp \
    settingsdialog.cpp

HEADERS  += mainwindow.h \
    subwindow.h \
    ssubwindow.h \
    counterwindow.h \
    storywindow.h \
    settingsdialog.h

FORMS    += mainwindow.ui \
    subwindow.ui \
    ssubwindow.ui \
    counterwindow.ui \
    storywindow.ui \
    settingsdialog.ui

RESOURCES += \
    font.qrc \
    img.qrc
