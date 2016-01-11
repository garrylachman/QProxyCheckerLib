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

headersDataFiles.path = $$[QT_INSTALL_HEADERS]/QProxyCheckerLib/
headersDataFiles.files = $$PWD/*.h
INSTALLS += headersDataFiles

libraryFiles.path = $$[QT_INSTALL_LIBS]
Debug:libraryFiles.files = $$OUT_PWD/debug/*.a $$OUT_PWD/debug/*.prl
Release:libraryFiles.files = $$OUT_PWD/release/*.a $$OUT_PWD/release/*.prl
INSTALLS += libraryFiles

#
#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#}
