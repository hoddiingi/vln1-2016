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
    person.cpp \
    addscientistdialog.cpp \
    addcomputerdialog.cpp \
    editscientistsdialog.cpp \
    addconnectiondialog.cpp \
    connection.cpp \
    editcomputersdialog.cpp \
    imagedialog.cpp

HEADERS  += mainwindow.h \
    computer.h \
    data.h \
    domain.h \
    person.h \
    addscientistdialog.h \
    addcomputerdialog.h \
    editscientistsdialog.h \
    addconnectiondialog.h \
    connection.h\
    editcomputersdialog.h \
    imagedialog.h


FORMS    += mainwindow.ui \
    addscientistdialog.ui \
    addcomputerdialog.ui \
    editscientistsdialog.ui \
    addconnectiondialog.ui \
    editcomputersdialog.ui \
    imagedialog.ui






-----------




QT += core sql
QT -= gui
QT += sql


CONFIG += c++11

TARGET = vln
CONFIG += console
CONFIG -= app_bundle

RESOURCES += \
    resources.qrc \
