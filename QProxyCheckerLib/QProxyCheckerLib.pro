#-------------------------------------------------
#
# Project created by QtCreator 2016-01-10T03:34:52
#
#-------------------------------------------------

QT       += network widgets testlib

QT       -= gui

TARGET = QProxyCheckerLib
TEMPLATE = lib
CONFIG += staticlib

SOURCES += qproxycheckerlib.cpp

HEADERS += qproxycheckerlib.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
