#include "qproxycheckerlib.h"
#include <QDebug>

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
    qDebug() << "checkingStatusChanged " << proxyItem->checkingStatus();
    emit onCheckStarted(proxyItem);
}
