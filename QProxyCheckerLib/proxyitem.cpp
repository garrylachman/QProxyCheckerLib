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
#include "proxyitem.h"

ProxyItem::ProxyItem(ProxyType a_type, QString a_hostname, int a_port, QString a_username,
                     QString a_password, QObject *parent) :
    _hostname(a_hostname), _port(a_port), QObject(parent),
    _checkingStatus(CheckingStatus::NotChecked), _proxyStatus(ProxyStatus::None),
    _proxyType(a_type), _anonymityLevel(AnonymityLevel::NotSet),
    _username(a_username), _password(a_password)
{

}

void ProxyItem::setCheckingStatus(CheckingStatus checkingStatus)
{
    this->_checkingStatus = checkingStatus;
    emit checkingStatusChanged(this, this->_checkingStatus);
}

ProxyItem::CheckingStatus ProxyItem::checkingStatus() const
{
    return this->_checkingStatus;
}

void ProxyItem::setProxyStatus(ProxyStatus proxyStatus)
{
    this->_proxyStatus = proxyStatus;
}

ProxyItem::ProxyStatus ProxyItem::proxyStatus() const
{
    return this->_proxyStatus;
}

void ProxyItem::setProxyType(ProxyType proxyType)
{
    this->_proxyType = proxyType;
}

ProxyItem::ProxyType ProxyItem::proxyType() const
{
    return this->_proxyType;
}

void ProxyItem::setAnonymityLevel(AnonymityLevel anonymityLevel)
{
    this->_anonymityLevel = anonymityLevel;
}

ProxyItem::AnonymityLevel ProxyItem::anonymityLevel() const
{
    return this->_anonymityLevel;
}

QString ProxyItem::hostname() const
{
    return this->_hostname;
}

int ProxyItem::port() const
{
    return this->_port;
}

QString ProxyItem::username() const
{
    return this->_username;
}

QString ProxyItem::password() const
{
    return this->_password;
}
