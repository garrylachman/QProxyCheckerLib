#include "checker.h"

Checker::Checker(ProxyItem* a_proxyItem, QObject *parent) : QObject(parent), _proxyItem(a_proxyItem)
{
    this->_nam = new QNetworkAccessManager(this);
    this->_proxy = new QNetworkProxy();
}

void Checker::start()
{
    this->_proxyItem->setCheckingStatus(ProxyItem::CheckingStatus::Checking);
}
