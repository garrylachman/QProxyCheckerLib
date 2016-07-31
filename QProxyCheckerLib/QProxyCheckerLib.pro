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

QT       += network widgets testlib core

QT       -= gui

TARGET = QProxyCheckerLib
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11
CONFIG += create_pc create_prl

SOURCES += qproxycheckerlib.cpp \
    proxyitem.cpp \
    checker.cpp

HEADERS += qproxycheckerlib.h \
    proxyitem.h \
    checker.h

headersDataFiles.path = $$[QT_INSTALL_HEADERS]/QProxyCheckerLib/
headersDataFiles.files = $$PWD/*.h
INSTALLS += headersDataFiles

target.path = $$[QT_INSTALL_LIBS]
INSTALLS += target

QMAKE_PKGCONFIG_NAME = QProxyCheckerLib
QMAKE_PKGCONFIG_DESCRIPTION = Qt5 QProxyCheckerLib
QMAKE_PKGCONFIG_PREFIX = $$INSTALLBASE
QMAKE_PKGCONFIG_LIBDIR = $$target.path
QMAKE_PKGCONFIG_INCDIR = $$headers.path
QMAKE_PKGCONFIG_VERSION = $$VERSION
