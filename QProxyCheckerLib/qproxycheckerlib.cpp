#include "qproxycheckerlib.h"
#include <QDebug>

QProxyCheckerLib::QProxyCheckerLib()
{

}

QString QProxyCheckerLib::testLib()
{
    ProxyItem * item = new ProxyItem(ProxyItem::ProxyType::Http, "127.0.0.1", 8081);

    qDebug() << item->checkingStatus();

    item->setCheckingStatus(ProxyItem::Checking);
    qDebug() << item->checkingStatus();
    qDebug() << item->hostname();

    return QString("test lib static 1");
}

ProxyItem* QProxyCheckerLib::getItem()
{
     ProxyItem * item = new ProxyItem(ProxyItem::ProxyType::Http, "127.0.0.1", 8081);
     return item;
}
