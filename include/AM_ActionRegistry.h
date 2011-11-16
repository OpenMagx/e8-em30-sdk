//Fix for E8/EM30 by Ant-ON, 25-10-2010

// Copyright (c) 24-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef UTIL_ACTIONREGISTRY_H
#define UTIL_ACTIONREGISTRY_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "AM_Global.h"
#include "AM_Defs.h"
#include "ZConfig.h"
#include <qobject.h>

class AM_ActionRegistry : public QObject
{
    Q_OBJECT
public:
    AM_ActionRegistry(QObject  * parent = 0, const char * name = 0);                         
    ~AM_ActionRegistry();                        

    void initRegisterData();

    bool defaultApp(const QString & action, QUuid & app);
    bool systemApp(const QString & action, QUuid & app);

private:
    const QString registerFile() const;
    const QString originalRegisterFile() const;
};

#endif  

