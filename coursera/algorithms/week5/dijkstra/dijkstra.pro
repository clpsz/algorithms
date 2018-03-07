#-------------------------------------------------
#
# Project created by QtCreator 2015-08-09T08:59:55
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = dijkstra
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    graph.cpp \
    vertex.cpp \
    dsp.cpp

HEADERS += \
    graph.h \
    vertex.h \
    dsp.h
