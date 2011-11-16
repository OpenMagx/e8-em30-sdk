

// Copyright (c) 16-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_SETUP_SET_MANAGER_H 
#define PUBLIC_API_SETUP_SET_MANAGER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>
#include <qmap.h>
#include "ZConfig.h"
#include "AM_Global.h"

class SETUP_SET_Manager:public ZConfig
{
public:
    SETUP_SET_Manager(AM_Global::Apps appName, bool bFlush = false );

    SETUP_SET_Manager(QString fileName, bool bFlush = false);

    ~SETUP_SET_Manager();

    void getSettingInfo(QString groupName, QString keyName, QString& value, QString defaultValue, bool encrypted=false);

    void getSettingInfo(QString groupName, QString keyName, int& value, int defaultValue );

    void getSettingInfo(QString groupName, QString keyName, bool& value, bool defaultValue );

    void getSettingInfo(QString groupName, QString keyName, unsigned int& value, unsigned int defaultValue );

    void getSettingInfo(QString groupName, QString keyName, unsigned short& value, unsigned short defaultValue );

    bool setSettingInfo(QString groupName, QString keyName, QString value, bool encrypted=false);

    bool setSettingInfo(QString groupName, QString keyName, int value);

    bool setSettingInfo(QString groupName, QString keyName, bool value);

    bool setSettingInfo(QString groupName, QString keyName, unsigned int value);

    bool setSettingInfo(QString groupName, QString keyName, unsigned short value);

    ZConfigGroup getEntryKeyList(QString  groupName);

    bool removeEntry( QString groupName, QString keyName );

    bool clearGroup( QString groupName);

    bool flush();

private:
    static QString getSettingFileName(AM_Global::Apps);
};

#endif  

