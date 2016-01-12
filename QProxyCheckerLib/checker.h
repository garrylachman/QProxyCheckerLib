#ifndef CHECKER_H
#define CHECKER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkProxy>
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
signals:

public slots:
};

#endif // CHECKER_H
