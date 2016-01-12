#ifndef QPROXYCHECKERLIB_H
#define QPROXYCHECKERLIB_H

#include <QObject>
#include <QString>
#include "proxyitem.h"
#include "checker.h"

class QProxyCheckerLib : public QObject
{
    Q_OBJECT
public:
    QProxyCheckerLib(QObject *parent = 0);
    void checkProxy(ProxyItem::ProxyType proxyType, QString hostname, int port,
                    QString username = QString(), QString password = QString());
signals:
    void onCheckStarted(ProxyItem*);
public slots:
    void checkingStatusChanged(ProxyItem *proxyItem, ProxyItem::CheckingStatus checkingStatus);
};

#endif // QPROXYCHECKERLIB_H
