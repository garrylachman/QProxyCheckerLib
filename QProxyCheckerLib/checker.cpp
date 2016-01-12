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
#include "checker.h"

Checker::Checker(ProxyItem* a_proxyItem, QObject *parent) : QObject(parent), _proxyItem(a_proxyItem)
{
    this->_nam = new QNetworkAccessManager(this);
    QObject::connect(this->_nam, SIGNAL(finished(QNetworkReply*)),
                     this, SLOT(finished(QNetworkReply*)));

    QObject::connect(this->_nam, SIGNAL(sslErrors(QNetworkReply*, const QList<QSslError>)),
                     this, SLOT(sslErrors(QNetworkReply*, const QList<QSslError>)));

    this->_proxy = new QNetworkProxy();
}

void Checker::start()
{
    this->setProxy();
    this->_proxyItem->setCheckingStatus(ProxyItem::CheckingStatus::Checking);
    this->send();
}

void Checker::send()
{
    QNetworkRequest networkRequest = QNetworkRequest(QUrl("http://httpbin.org/get"));

    QNetworkReply* networkReply = this->_nam->get(networkRequest);
}

void Checker::setProxy()
{
    switch (this->_proxyItem->proxyType())
    {
        case ProxyItem::ProxyType::Http:
            this->_proxy->setType(QNetworkProxy::ProxyType::HttpProxy);
        break;

        case ProxyItem::ProxyType::Socks5:
            this->_proxy->setType(QNetworkProxy::ProxyType::Socks5Proxy);
        break;
    }

    this->_proxy->setHostName(this->_proxyItem->hostname());
    this->_proxy->setPort((quint16)this->_proxyItem->port());

    if ( ! this->_proxyItem->username().isEmpty() &&
         ! this->_proxyItem->password().isEmpty())
    {
        this->_proxy->setUser(this->_proxyItem->username());
        this->_proxy->setPassword(this->_proxyItem->password());
    }

    this->_nam->setProxy(*this->_proxy);
}

void Checker::finished(QNetworkReply *networkReply)
{
    if (networkReply->error() != QNetworkReply::NetworkError::NoError)
    {
        this->_proxyItem->setProxyStatus(ProxyItem::ProxyStatus::Offline);
        this->_proxyItem->setCheckingStatus(ProxyItem::CheckingStatus::Checked);
        return;
    }

    QString strReply = (QString)networkReply->readAll();

    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
    QJsonObject jsonObj = jsonResponse.object();
    QString origin = jsonObj["origin"].toString();

    // Check if for "," in origin string, if true we got 2 ips
    // the proxy is level 1 (ProxyItem::AnonymityLevel::Transparent)
    bool isOriginMultiIPs = origin.contains(",");

    // Check if for "x-via" header, if true we can detect proxy use but
    // the sender is anontmous, the proxy is level 2 (ProxyItem::AnonymityLevel::Anonymous)
    bool isViaHeader = networkReply->hasRawHeader(QString("x-via").toUtf8());

    if (isOriginMultiIPs)
    {
        this->_proxyItem->setAnonymityLevel(ProxyItem::AnonymityLevel::Transparent);
    }
    else if ( ! isOriginMultiIPs && isViaHeader)
    {
        this->_proxyItem->setAnonymityLevel(ProxyItem::AnonymityLevel::Anonymous);
    }
    else
    {
        // sender IP and x-via is not detected, the proxy is level 3
        this->_proxyItem->setAnonymityLevel(ProxyItem::AnonymityLevel::Elite);
    }

    this->_proxyItem->setProxyStatus(ProxyItem::ProxyStatus::Online);
    this->_proxyItem->setCheckingStatus(ProxyItem::CheckingStatus::Checked);
}

void Checker::sslErrors(QNetworkReply *reply, const QList<QSslError> &errors)
{
    reply->ignoreSslErrors();
}
