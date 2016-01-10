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
CONFIG += c++11

SOURCES += qproxycheckerlib.cpp \
    proxyitem.cpp

HEADERS += qproxycheckerlib.h \
    proxyitem.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
