#-------------------------------------------------
#
# Project created by QtCreator 2020-11-01T11:39:38
#
#-------------------------------------------------

QT       -=

TARGET = MGAUserLib
TEMPLATE = lib
CONFIG += staticlib

SOURCES += mgauserlib.cpp

HEADERS += mgauserlib.h
unix {
    target.path = ./
    INSTALLS += target
}
