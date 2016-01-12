#-------------------------------------------------
# This file is part of QProxyCheckerLib
# https://github.com/garrylachman/QProxyCheckerLib
# https://rev.proxies.online
#
# Copyright (C) 2016 Garry Lachman <garry@lachman.co>
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License version 2.1, as published by the Free Software Foundation.
#
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this library; see the file COPYING.LIB.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
# Boston, MA 02110-1301, USA.
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
