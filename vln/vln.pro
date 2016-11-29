QT += core
QT -= gui

CONFIG += c++11

TARGET = vln
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    person.cpp \
    domain.cpp \
    data.cpp

HEADERS += \
    person.h \
    domain.h \
    data.h
