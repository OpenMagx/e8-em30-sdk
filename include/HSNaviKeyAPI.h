

// Copyright (c) 25-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef HSNAVIKEYAPI_H 
#define HSNAVIKEYAPI_H 

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qcopchannel_qws.h>
#include <SETUP_SET_Manager.h>
#define HSNAVIKEYSETUP_CHANNEL "simple_idle_channel"

#define HSNAVIKEYSETUP_UPDATE    "simple_idle_shortcut_update_msg"

class HSNaviKeyAPI
{
    public:

    enum QuadStyleShortCutButtonType
    {
        QSS_BUTTON_LEFT = 0,
        QSS_BUTTON_RIGHT,
        QSS_BUTTON_UP,
        QSS_BUTTON_DOWN,
        QSS_BUTTON_NUMBER
    };

    static void HS_updateNavikey(QuadStyleShortCutButtonType type,QString const& appid )
    {
        QString asc_strFlexFileName = QString(getenv("EZX_APP_WRITE_PATH")) + "/setup/ezx_idle.cfg";
        QString asc_strGroupName = "NaviKeyPlugin";
        QString asc_strKeyShortCutIdPrefix = "ShortcutID%1"; 

        SETUP_SET_Manager manager(asc_strFlexFileName);

        int iIndex = static_cast<int>( type );

        manager.setSettingInfo(asc_strGroupName,asc_strKeyShortCutIdPrefix.arg(iIndex + 1), appid);

        QCopChannel::send(QCString(HSNAVIKEYSETUP_CHANNEL),QCString(HSNAVIKEYSETUP_UPDATE));
    }
};

#endif 
