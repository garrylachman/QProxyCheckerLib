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
signals:

public slots:
    void finished(QNetworkReply* networkReply);
    void networkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility accessible);
    void sslErrors(QNetworkReply * reply, const QList<QSslError> & errors);
    //todo:
    //QNetworkAccessManager::proxyAuthenticationRequired slot
};

#endif // CHECKER_H
