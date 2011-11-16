

// Copyright (c) 25-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef AM_APP_REGISTRY_H
#define AM_APP_REGISTRY_H

#ifndef __cplusplus
#error "This is C++ header file; it requires C++ to compile."
#endif

#include <qobject.h>
#include <qvaluelist.h>
#include <qstring.h>
#include <qstringlist.h>
#include <quuid.h>

#include "AM_Defs.h"

class AM_RegistryObject;
class AM_Folder;
class AM_AppObject;
class AM_AppLnk;

class AM_AppRegistryImpl;

class AM_AppRegistry : public QObject
{
    Q_OBJECT

public:

    struct LockableAppObject
    {
        const AM_AppObject * appObject;
        int lockValue;
    };

    AM_AppRegistry(QObject * parent = 0, const char * name = 0);

    ~AM_AppRegistry();

    AM_RESULT_CODE_T init();

    const AM_RegistryObject * getRegistryObject(const QString & uid) const;

    const AM_Folder * getRootFolder() const;

    const AM_AppLnk * getAppLnk(const QUuid & appId) const;

    void getInstalledApplications(bool all, QValueList<const AM_AppLnk *> & appLnkList) const;

    void getAllAppObjects(QValueList<const AM_AppObject *> & appObjectList) const;

    AM_RESULT_CODE_T getLockEnabledAppObjects(QValueList<LockableAppObject> & lockableList) const;

    void getAutoStartEnabledAppObjects(QValueList<const AM_AppObject *> & autoStartList) const;

    AM_RESULT_CODE_T isAutoStartEnabled(const QUuid & appId, bool & enabled) const;

    static AM_RESULT_CODE_T getAppLockValue(const QUuid & appId, int & value);

    static AM_RESULT_CODE_T getAppName(const QUuid & appId, QString & appName);

    AM_RESULT_CODE_T setAutoStartEnabled(const QUuid & appId, bool enabled);

    AM_RESULT_CODE_T updateFolderOrder(const QString & folderUid, const QStringList & uidList);

    AM_RESULT_CODE_T updateRegistryObjectAppearance(const QString & uid, 
            const QString & newName, const QString & newBigIcon, 
            const QString & newSmallIcon, const QString & newAniIcon,
            const QString & newSVGIcon, bool temporary = false);

    AM_RESULT_CODE_T updateRegistryObjectAppearance( const QString & uid, 
        const QString & newName, const QString & newSVGIcon, 
        const QString & newSimpleIcon, bool temporary  = false);

    AM_RESULT_CODE_T moveRegistryObject(const QString & uid, 
            const QString & destFolderUid, int position = -1);

    AM_RESULT_CODE_T setAppLockValue(const QUuid & appId, int value);

signals:

    void signalFolderOrderUpdated(const QString &folderUid);

    void signalRegistryObjectUpdated(const QString &uid);

    void signalRegistryObjectMoved(const QString &uid, 
            const QString &srcFolderUid, const QString &destFolderUid);

    void signalAppObjectAdded(const QString &uid, const QString &folderUid);

    void signalAppObjectRemoved(const QString &uid, const QString &folderUid);

    void signalCardPlugged(const QStringList & folderUids);

    void signalCardUnplugged(const QStringList & folderUids);

private:
    AM_AppRegistry(const AM_AppRegistry & rhs);
    AM_AppRegistry & operator=(const AM_AppRegistry & rhs);

private slots:
    void slotFolderOrderUpdated(const QString & folderUid);
    void slotRegistryObjectUpdated(const QString & uid);
    void slotRegistryObjectMoved(const QString &uid, 
            const QString &srcFolderUid, const QString &destFolderUid);
    void slotAppObjectAdded(const QString &uid, const QString &folderUid);
    void slotAppObjectRemoved(const QString &uid, const QString &folderUid);
    void slotCardPlugged(const QStringList & folderUids);
    void slotCardUnplugged(const QStringList & folderUids);

private:
    AM_AppRegistryImpl * m_impl;
};

#endif 
