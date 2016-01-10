#include "qproxycheckerlib.h"
#include <QDebug>

QProxyCheckerLib::QProxyCheckerLib()
{

}

QString QProxyCheckerLib::testLib()
{
    ProxyItem * item = new ProxyItem(ProxyItem::ProxyType::Http);

    qDebug() << item->checkingStatus();

    item->setCheckingStatus(ProxyItem::Checking);
    qDebug() << item->checkingStatus();
    qDebug() << item->proxyType();

    return QString("test lib static 1");
}
