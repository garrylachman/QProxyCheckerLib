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
#ifndef CHECKER_H
#define CHECKER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkProxy>
#include <QNetworkReply>
#include <QUrl>
#include <QList>
#include <QSslError>
#include <QJsonObject>
#include <QJsonDocument>
#include "proxyitem.h"

class Checker : public QObject
{
    Q_OBJECT
public:
    explicit Checker(ProxyItem* a_proxyItem, QObject *parent = 0);
    void start();

private:
    ProxyItem* _proxyItem;
    QNetworkAccessManager* _nam;
    QNetworkProxy* _proxy;

    void send();
    void setProxy();
signals:

public slots:
    void finished(QNetworkReply* networkReply);
    void sslErrors(QNetworkReply * reply, const QList<QSslError> & errors);
    //todo:
    //QNetworkAccessManager::proxyAuthenticationRequired slot
};

#endif // CHECKER_H
