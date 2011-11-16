

// Copyright (c) 24-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef AM_APPOBJECT_H
#define AM_APPOBJECT_H

#include "AM_RegistryObject.h"

class AM_AppRegistryImpl;

class AM_AppObject :  public AM_RegistryObject
{
protected:
    AM_AppObject();

    AM_AppObject( AM_RegistryObject::Type t);
    virtual ~AM_AppObject();

private:
    AM_AppObject(const AM_AppObject & rhs);
    AM_AppObject & operator=(const AM_AppObject & rhs);

public:

    virtual bool isAppLockEnabled() const;

    virtual QUuid getAppId() const; 

protected:
    virtual void setAppId( const QUuid &id );
    virtual void setAppLockEnabled( bool b );

protected:

    QUuid mAppId;
    bool mLockEnabled;

friend class AM_AppRegistryImpl;
};
#endif
