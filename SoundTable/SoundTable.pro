#-------------------------------------------------
#
# Project created by QtCreator 2015-01-14T19:31:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SoundTable
TEMPLATE = app


SOURCES += main.cpp\
        control.cpp \
        filterProcessor.cpp

HEADERS  += control.h \
        filterProcessor.h

FORMS    += control.ui

include(../videoengine/videoengine.pri)
