#ifndef QPROXYCHECKERLIB_H
#define QPROXYCHECKERLIB_H

#include <QString>
#include "proxyitem.h"

class QProxyCheckerLib
{

public:
    QProxyCheckerLib();
    QString testLib();
    ProxyItem* getItem();

};

#endif // QPROXYCHECKERLIB_H
