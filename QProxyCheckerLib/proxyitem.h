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
#ifndef PROXYITEM_H
#define PROXYITEM_H

#include <QObject>
#include <QString>

class ProxyItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(CheckingStatus checkingStatus READ checkingStatus WRITE setCheckingStatus NOTIFY checkingStatusChanged)
    Q_PROPERTY(ProxyStatus proxyStatus READ proxyStatus WRITE setProxyStatus)
    Q_PROPERTY(ProxyType proxyType READ proxyType WRITE setProxyType)
    Q_PROPERTY(AnonymityLevel anonymityLevel READ anonymityLevel WRITE setAnonymityLevel)
    Q_PROPERTY(QString hostname READ hostname)
    Q_PROPERTY(int port READ port)
    Q_PROPERTY(QString username READ username)
    Q_PROPERTY(QString password READ password)

public:

    enum CheckingStatus { NotChecked, Checking, Checked };
    Q_ENUM(CheckingStatus);
    void setCheckingStatus(CheckingStatus checkingStatus);
    CheckingStatus checkingStatus() const;

    enum ProxyStatus { None, Online, Offline };
    Q_ENUM(ProxyStatus);
    void setProxyStatus(ProxyStatus proxyStatus);
    ProxyStatus proxyStatus() const;

    enum ProxyType { Socks5, Http };
    Q_ENUM(ProxyType);
    void setProxyType(ProxyType proxyType);
    ProxyType proxyType() const;

    enum AnonymityLevel { NotSet, Transparent, Anonymous, Elite };
    Q_ENUM(AnonymityLevel);
    void setAnonymityLevel(AnonymityLevel anonymityLevel);
    AnonymityLevel anonymityLevel() const;

    QString hostname() const;
    int port() const;
    QString username() const;
    QString password() const;

    explicit ProxyItem(ProxyType a_type, QString a_hostname,
                       int a_port, QString a_username = QString(),
                       QString a_password= QString(), QObject *parent = 0);

private:
    CheckingStatus _checkingStatus;
    ProxyStatus _proxyStatus;
    ProxyType _proxyType;
    AnonymityLevel _anonymityLevel;
    QString _hostname;
    int _port;
    QString _username;
    QString _password;

signals:
    void checkingStatusChanged(ProxyItem*, ProxyItem::CheckingStatus);

public slots:
};

#endif // PROXYITEM_H
