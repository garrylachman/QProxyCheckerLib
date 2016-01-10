#include <QString>
#include <QtTest>
#include <QDebug>

#include "../QProxyCheckerLib/qproxycheckerlib.h"

class QProxyCheckerLibTestTest : public QObject
{
    Q_OBJECT

public:
    QProxyCheckerLibTestTest();

private Q_SLOTS:
    void testLib();
};

QProxyCheckerLibTestTest::QProxyCheckerLibTestTest()
{
    QProxyCheckerLib* checker = new QProxyCheckerLib();
    QString ret = checker->testLib();
    qDebug() << ret;
}

void QProxyCheckerLibTestTest::testLib()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(QProxyCheckerLibTestTest)

#include "tst_qproxycheckerlibtesttest.moc"
