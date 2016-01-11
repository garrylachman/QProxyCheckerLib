#ifndef PROXYITEM_H
#define PROXYITEM_H

#include <QObject>
#include <QString>

class ProxyItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(CheckingStatus checkingStatus READ checkingStatus WRITE setCheckingStatus)
    Q_PROPERTY(ProxyStatus proxyStatus READ proxyStatus WRITE setProxyStatus)
    Q_PROPERTY(ProxyType proxyType READ proxyType WRITE setProxyType)
    Q_PROPERTY(AnonymityLevel anonymityLevel READ anonymityLevel WRITE setAnonymityLevel)
    Q_PROPERTY(QString hostname READ hostname)
    Q_PROPERTY(int port READ port)

public:

    enum CheckingStatus { NotChecked, Checking, Checked };
    Q_ENUM(CheckingStatus);
    void setCheckingStatus(CheckingStatus checkingStatus);
    CheckingStatus checkingStatus() const;

    enum ProxyStatus { None, Online, Offline };
    Q_ENUM(ProxyStatus);
    void setProxyStatus(ProxyStatus proxyStatus);
    ProxyStatus proxyStatus() const;

    enum ProxyType { Socks4, Socks5, Http };
    Q_ENUM(ProxyType);
    void setProxyType(ProxyType proxyType);
    ProxyType proxyType() const;

    enum AnonymityLevel { NotSet, Transparent, Anonymous, Elite };
    Q_ENUM(AnonymityLevel);
    void setAnonymityLevel(AnonymityLevel anonymityLevel);
    AnonymityLevel anonymityLevel() const;

    QString hostname() const;
    int port() const;

    explicit ProxyItem(QString a_hostname, int a_port, ProxyType a_type, QObject *parent = 0);

private:
    CheckingStatus _checkingStatus;
    ProxyStatus _proxyStatus;
    ProxyType _proxyType;
    AnonymityLevel _anonymityLevel;
    QString _hostname;
    int _port;

signals:

public slots:
};

#endif // PROXYITEM_H