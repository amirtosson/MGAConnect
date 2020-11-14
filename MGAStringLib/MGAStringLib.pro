#-------------------------------------------------
#
# Project created by QtCreator 2020-10-27T08:38:25
#
#-------------------------------------------------

QT       +=widgets

TARGET = MGAString
TEMPLATE = lib
CONFIG += staticlib

SOURCES += mgastring.cpp

HEADERS += mgastring.h
unix {
    target.path = ./
    INSTALLS += target
}
