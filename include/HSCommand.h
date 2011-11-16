

// Copyright (c) 09-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef HSCOMMAND_H
#define HSCOMMAND_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qobject.h>
#include <qstring.h>

class HSCommand  :public QObject
{

Q_OBJECT
public:

     typedef enum
     {
        HS_SOFTKEY_LEFT,
        HS_SOFTKEY_RIGHT
     }  HSSoftKeyType;

    virtual ~HSCommand() {};

    virtual QString getName() const = 0;

    virtual void setName(const QString& name) = 0;

    virtual int getUid() const = 0 ;

    virtual void setUid(int uid) = 0;

    virtual void setIconResID(const QString& iconID) = 0;

    virtual QString getIconResID() const = 0;

    virtual void setParentCommand(HSCommand* pParent) = 0;

    virtual void setAsParent() = 0;

    virtual bool hasSubMenu() = 0 ;

    virtual bool isSubMenu() = 0 ;

    virtual bool isEnabled() = 0 ;

    virtual void setEnabled(bool bEnabled) = 0;

signals:

    void selected(int uid);

public slots:

    virtual void choose() = 0;

private:

};

#endif 
