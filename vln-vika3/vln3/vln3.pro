#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T13:13:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vln3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    computer.cpp \
    data.cpp \
    domain.cpp \
    person.cpp

HEADERS  += mainwindow.h \
    computer.h \
    data.h \
    domain.h \
    person.h

FORMS    += mainwindow.ui





-----------




QT += core sql
QT -= gui
QT += sql


CONFIG += c++11

TARGET = vln
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    person.cpp \
    domain.cpp \
    data.cpp \
    computer.cpp

HEADERS += \
    person.h \
    domain.h \
    data.h \
    computer.h
