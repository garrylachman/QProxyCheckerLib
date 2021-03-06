/* This file is part of QProxyCheckerLib
 * https://github.com/garrylachman/QProxyCheckerLib
 * https://rev.proxies.online
 *
 * Copyright (C) 2016 Garry Lachman <garry@lachman.co>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1, as published by the Free Software Foundation.
 *
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */
#include "qproxycheckerlib.h"

QProxyCheckerLib::QProxyCheckerLib(QObject *parent)  : QObject(parent)
{

}

void QProxyCheckerLib::checkProxy(ProxyItem::ProxyType proxyType, QString hostname, int port,
                                  QString username, QString password)
{
    ProxyItem* proxyItem = new ProxyItem(proxyType, hostname, port, username, password, this);
    QObject::connect(proxyItem, SIGNAL(checkingStatusChanged(ProxyItem*, ProxyItem::CheckingStatus)),
                     this, SLOT(checkingStatusChanged(ProxyItem*, ProxyItem::CheckingStatus)));
    Checker* checker = new Checker(proxyItem, this);
    checker->start();
}

void QProxyCheckerLib::checkingStatusChanged(ProxyItem *proxyItem, ProxyItem::CheckingStatus checkingStatus)
{
    emit statusChanged(proxyItem);
}
