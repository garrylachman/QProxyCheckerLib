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

    QSignalSpy spy(checker, SIGNAL(onCheckStarted(ProxyItem*)));

    checker->checkProxy(ProxyItem::ProxyType::Http, "rev1.proxies.online", 8081);

    //QCOMPARE(spy.count(), 1);
    QVERIFY(spy.wait(5000));
}

QTEST_GUILESS_MAIN(QProxyCheckerLibTestTest)

#include "tst_qproxycheckerlibtesttest.moc"
