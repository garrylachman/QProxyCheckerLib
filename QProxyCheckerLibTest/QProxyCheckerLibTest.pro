#-------------------------------------------------
#
# Project created by QtCreator 2016-01-10T04:09:05
#
#-------------------------------------------------

QT       += network testlib core

QT       -= gui

TARGET = tst_qproxycheckerlibtesttest
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += c++11

TEMPLATE = app


SOURCES += tst_qproxycheckerlibtesttest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-QProxyCheckerLib-Desktop_Qt_5_5_0_clang_64bit-Debug/release/ -lQProxyCheckerLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-QProxyCheckerLib-Desktop_Qt_5_5_0_clang_64bit-Debug/debug/ -lQProxyCheckerLib
else:unix: LIBS += -L$$PWD/../build-QProxyCheckerLib-Desktop_Qt_5_5_0_clang_64bit-Debug/ -lQProxyCheckerLib

INCLUDEPATH += $$PWD/../QProxyCheckerLib
DEPENDPATH += $$PWD/../build-QProxyCheckerLib-Desktop_Qt_5_5_0_clang_64bit-Debug
