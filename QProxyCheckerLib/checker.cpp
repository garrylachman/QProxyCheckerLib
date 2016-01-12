#include "checker.h"
#include <QDebug>

Checker::Checker(ProxyItem* a_proxyItem, QObject *parent) : QObject(parent), _proxyItem(a_proxyItem)
{
    this->_nam = new QNetworkAccessManager(this);
    QObject::connect(this->_nam, SIGNAL(finished(QNetworkReply*)),
                     this, SLOT(finished(QNetworkReply*)));

    QObject::connect(this->_nam, SIGNAL(networkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility)),
                     this, SLOT(networkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility)));

    QObject::connect(this->_nam, SIGNAL(sslErrors(QNetworkReply*, const QList<QSslError>)),
                     this, SLOT(sslErrors(QNetworkReply*, const QList<QSslError>)));

    this->_proxy = new QNetworkProxy();
}

void Checker::start()
{
    this->_proxyItem->setCheckingStatus(ProxyItem::CheckingStatus::Checking);
    this->send();
}

void Checker::send()
{
    qDebug() << "Checker::send";
    QNetworkRequest networkRequest = QNetworkRequest(QUrl("http://httpbin.org/get"));

    QNetworkReply* networkReply = this->_nam->get(networkRequest);
}

void Checker::finished(QNetworkReply *networkReply)
{
    qDebug() << "finished";
    if (networkReply->error() != QNetworkReply::NetworkError::NoError)
    {
        this->_proxyItem->setProxyStatus(ProxyItem::ProxyStatus::Offline);
        this->_proxyItem->setCheckingStatus(ProxyItem::CheckingStatus::Checked);
        return;
    }

    QString strReply = (QString)networkReply->readAll();

    qDebug() << "Response:" << strReply;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
    QJsonObject jsonObj = jsonResponse.object();
    QString origin = jsonObj["origin"].toString();
    qDebug() << origin;

    // Check if we got "," in origin string, if true we got 2 ips
    // the proxy is level 1 (ProxyItem::AnonymityLevel::Transparent)
    bool isOriginMultiIPs = origin.contains(",");
    if (isOriginMultiIPs)
    {
        this->_proxyItem->setAnonymityLevel(ProxyItem::AnonymityLevel::Transparent);
    }
    qDebug() << "isOriginMultiIPs: " << isOriginMultiIPs;

}

void Checker::networkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility accessible)
{
    qDebug() << "networkAccessibleChanged";
}

void Checker::sslErrors(QNetworkReply *reply, const QList<QSslError> &errors)
{
    qDebug() << "sslErrors";
    reply->ignoreSslErrors();
}
