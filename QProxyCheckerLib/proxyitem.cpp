#include "proxyitem.h"

ProxyItem::ProxyItem(ProxyType type, QObject *parent) : QObject(parent),
    _checkingStatus(CheckingStatus::NotChecked), _proxyStatus(ProxyStatus::None),
    _proxyType(type), _anonymityLevel(AnonymityLevel::NotSet)
{

}

void ProxyItem::setCheckingStatus(CheckingStatus checkingStatus)
{
    this->_checkingStatus = checkingStatus;
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
