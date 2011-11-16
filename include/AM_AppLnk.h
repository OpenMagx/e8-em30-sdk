

// Copyright (c) 24-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef AM_APPLNK_H
#define AM_APPLNK_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "AM_AppObject.h"

class AM_AppRegistryImpl;

class AM_AppLnk : public AM_AppObject
{

public:
    enum AppType
    {
        InvalidAppType = -1,
        UndefinedAppType = InvalidAppType,
        NativeApp = 0,
        JavaApp = 1,
        FaultlineApp = 2,
        WebuiApp = 3
    };

    enum Attribute
    {
        InvalidAttr = 0,    

        System = 1,         
        Preloaded = 2,      
        Installed = 3       
    }; 
protected:
    AM_AppLnk();

    virtual ~AM_AppLnk();

private:
    AM_AppLnk(const AM_AppLnk & rhs);
    AM_AppLnk & operator=(const AM_AppLnk &rhs);

public:
    virtual AM_AppLnk::Attribute getAttribute() const;

    virtual QString getExec() const;

    virtual QString getExecFullPath() const;

    virtual unsigned int getSize() const;

    virtual QString getVendor() const;

    virtual QString getArgs() const;

    virtual QString getAutoRunArgs() const;

    virtual AM_Global::Device getDevice() const;

    virtual bool isDaemon() const;

    virtual int  getUserID() const;

    virtual int  getGroupID()  const;

    virtual int getJavaId() const;

    virtual QString getExecId() const;

    virtual QString getInstalledDate()  const;

    virtual bool isRemovable() const;

    virtual bool isSharable() const;

    virtual QString getSmallIcon() const;

    virtual QString getBigIcon() const;

    virtual QString getAnimationIcon() const;

    virtual QString getSimpleIcon() const;

    virtual QString getSVGIcon() const;

    virtual bool isMovable() const;

    virtual QString getDirectory() const;

    virtual AM_AppLnk::AppType getAppType() const;

    virtual QString getVersion() const;

    virtual QString getDescription() const;

    virtual QString getIconImagePath(const int type) const;

    virtual bool getDebugMode() const;

protected:
    virtual AM_RESULT_CODE_T initObject(const QString & uid, const AppRecord & record);

    virtual void setVendor( const QString &newVendor);

    virtual void setArgs( const QString &newArgs );

    virtual void setAutoRunArgs ( const QString &newAutoRunArgs );

    virtual void setDevice( const AM_Global:: Device newDevice);

    virtual void setIsDaemon( bool b);

    virtual void setUserID( int uid);

    virtual void setGroupID( int gid);

    virtual void setJavaId( int jid);

    virtual void setInstalledDate( const QString &d);

    virtual void setRemovable( bool b );

    virtual void setSharable( bool b );   

    virtual void setMpkgFile( const QString &file );

    virtual void setSize( unsigned int size);

    virtual void setDirectory( const QString &newDir );

    virtual QString getDefaultName() const;

    enum IconType
    {
      BigIcon = 0,    
      SmallIcon = 1,  
      AniIcon = 2,    
      SVGIcon = 3,    
      SimpleIcon = 4  
    };

    QString mExec;
    bool    mIsDaemon; 
    int     mUserId;
    int     mGroupId;
    QString mDir;
    AppType mAppType;
    Attribute mAttr; 
    QString mAutoRunArgs; 
    QString mArgs;  
    AM_Global::Device mDevice;     

    QString mInstalledDate;
    int     mJavaId;
    QString mExecId;
    QString mMpkgFile;
    int     mIsSharable;
    QString mVendor;
    unsigned int mSize;

    QString mVersion; 
    QString mDateIssued;
    QString mDescription;
    QString mDescriptionResourceId;
    bool    mDebugMode; 

    bool mRemovable; 

private:
    QString getIconNameByType(IconType type, int attr ) const;
    QString getDefaultIconNameByType(IconType type) const;    
    QString getIcon( IconType ) const; 
    int getUidByString( const QString &id );
    int getGidByString( const QString &id );

friend class AM_AppRegistryImpl;

};

#endif

