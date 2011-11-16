

// Copyright (c) 25-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef AM_REGISTRYOBJECT_H
#define AM_REGISTRYOBJECT_H

#ifndef __cplusplus
#error "This is C++ header file; it requires C++ to compile."
#endif

#include <qmap.h>
#include <qstring.h>
#include <quuid.h>
#include <qpixmap.h>
#include "AM_Defs.h"
#include "AM_Global.h"
typedef QMap< QString, QString > AppRecord;

class AM_AppRegistryImpl;
class AM_Folder;

class AM_RegistryObject
{
public:
    enum Type
    {
        InvalidType = 0,    
        Folder = 1,         
        Application = 2,    
        EmbeddedLink = 3,   
        Shortcut = 4        
    };

protected:
    AM_RegistryObject( Type t = InvalidType);

    virtual ~AM_RegistryObject();

private:
    AM_RegistryObject(const AM_RegistryObject & rhs);
    AM_RegistryObject & operator=(const AM_RegistryObject & rhs);

public:
    virtual AM_RegistryObject::Type getType() const;

    virtual QString getUid() const;

    virtual QString getName() const;

    virtual void getNameAndResourceId(QString &name, QString &resourceId) const;

    virtual const AM_Folder* getParentFolder() const;

    virtual QString getBigIcon() const;

    virtual QString getSmallIcon() const;

    virtual QString getAnimationIcon() const;

    virtual QString getSVGIcon() const;

    virtual QString getSimpleIcon() const;

    virtual bool isVisible() const;

    virtual bool isMovable() const { return false; }

    virtual QString getIconImagePath(const int type) const { return ""; }

protected:

    virtual AM_RESULT_CODE_T initObject(const QString & uid, const AppRecord &record ) = 0;

    virtual void setType( Type newType);

    virtual void setUid( const QString &newUid );

    virtual void setName( const QString &newName, bool isCustomized = false );

    virtual void setParentFolder(const AM_Folder *newParentFolder );

    virtual void setSmallIcon( const QString &newIcon );

    virtual void setBigIcon( const QString &newIcon );

    virtual void setAnimationIcon( const QString &newIcon );

    virtual void setSVGIcon( const QString &newIcon );

    virtual void setSimpleIcon( const QString &newIcon );

    virtual void setVisible( bool isVisible);

    virtual QString getDefaultName() const = 0;

private:
    void init();

protected:
    Type mType;
    QString mUid; 
    QString mBigIcon;
    QString mSmallIcon;
    QString mAniIcon;
    QString mSVGIcon;
    QString mSimpleIcon;
    QString mName;
    QString mNameResourceId;
    QString mDefaultRid;
    const AM_Folder *mParentFolder;
    bool mIsVisible;
    bool mHasCustomizedName;

friend class AM_AppRegistryImpl;
friend class AM_Folder;

};
#endif
