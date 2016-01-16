#Proxy Checker Lib for QT C++
Copyright (C) 2016 Garry Lachman <garry@lachman.co> under GNU LGPL

https://rev.proxies.online

##Usage

1. Install the library
2. Include the headers
#include "qproxycheckerlib.h"
#include "proxyitem.h"
3. Public slots
```
public slots:
  void statusChanged(ProxyItem*);
```
3. Usage
```
QProxyCheckerLib* checker = new QProxyCheckerLib();
checker->checkProxy(ProxyItem::ProxyType::Http, "rev1.proxies.online", 8081);
```

Any checking status change will emit statusChanged with the proxyItem that change status

###ProxyItem API
```
CheckingStatus checkingStatus() const;
ProxyStatus proxyStatus() const;
ProxyType proxyType() const;
AnonymityLevel anonymityLevel() const;
QString hostname() const;
int port() const;
QString username() const;
QString password() const;
```

###ENUMS
```
CheckingStatus { NotChecked, Checking, Checked };
```
```
ProxyStatus { None, Online, Offline };
```
```
ProxyType { Socks5, Http };
```
```
AnonymityLevel { NotSet, Transparent, Anonymous, Elite };
```

##Licence
Copyright (C) 2016 Garry Lachman <garry@lachman.co>

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License version 2.1, as published by the Free Software Foundation.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this library; see the file COPYING.LIB.  If not, write to
the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
Boston, MA 02110-1301, USA.
