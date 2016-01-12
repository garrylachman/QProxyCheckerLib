/* This file is part of QProxyCheckerLib
 * https://github.com/garrylachman/QProxyCheckerLib
 * https://rev.proxies.online
 *
 * Copyright (C) 2016 Garry Lachman <garry@lachman.co>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1, as published by the Free Software Foundation.
 *
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */
#include <QString>
#include <QtTest>
#include <QSignalSpy>
#include <QDebug>

#include "../QProxyCheckerLib/qproxycheckerlib.h"
#include "../QProxyCheckerLib/proxyitem.h"

class QProxyCheckerLibTestTest : public QObject
{
    Q_OBJECT

public:
    QProxyCheckerLibTestTest();

private Q_SLOTS:
    void testSignals();
};

QProxyCheckerLibTestTest::QProxyCheckerLibTestTest()
{

}

void QProxyCheckerLibTestTest::testSignals()
{
    QProxyCheckerLib* checker = new QProxyCheckerLib();

    QSignalSpy spy(checker, SIGNAL(statusChanged(ProxyItem*)));

    checker->checkProxy(ProxyItem::ProxyType::Http, "rev1.proxies.online", 8081);

    QVERIFY(spy.wait(10000));
}

QTEST_GUILESS_MAIN(QProxyCheckerLibTestTest)

#include "tst_qproxycheckerlibtesttest.moc"
