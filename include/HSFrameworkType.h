

// Copyright (c) 09-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef HSFRAMEWORKTYPE_H
#define HSFRAMEWORKTYPE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>

#define HS_PLUGIN_STATUS_ICONS             QString("StatusIcons")

#define HS_PLUGIN_STATUS_TEXT              QString("StatusText")

#define HS_PLUGIN_CLOCK                    QString("Clock")
#define HS_PLUGIN_DATE                     QString("Date")

#define HS_PLUGIN_CROSSSTYLE_NAVIKEY       QString("CrossStyleNaviKey")

#define HS_PLUGIN_IDLE_MUSIC_PLAYER        QString("IdleMusicPlayer")

#define HS_PLUGIN_IDLE_RADIO_PLAYER        QString("IdleRadioPlayer")

#define HS_PLUGIN_SCREEN3                  QString("Screen3")

#define HS_PLUGIN_HSA	                   QString("HSA")

#define HS_PLUGIN_HSA_STARTUP	            QString("HSAStartup")

#define HS_PLUGIN_MYFIVE                   QString("MyFave")

#define HS_PLUGIN_IL                       QString("InstantLauncher")

#define HS_FOCUSMGR_ABSOLUTE   QString("AbsoluteMgr")

#define HS_FOCUSMGR_NAVIKEY    QString("NaviKeyMgr")

#define HS_FOCUSMGR_SOFTKEY    QString("SoftKeyMgr")

class HSFrameworkType
{
public:
    typedef enum
    {
       HS_KEY_PRESS,

       HS_KEY_RELEASE,

       HS_KEY_PRESS_AND_HOLD,

       HS_OMG_SCROLL

    } HSEvent;

    typedef enum
    {
        HS_EVENT_ACCEPT,

        HS_EVENT_IGNORE
    } HSEventStatus;

    typedef enum
    {
        PLUGIN_STATE_ACTIVATED,

        PLUGIN_STATE_FOCUSED,

        PLUGIN_STATE_OBSCURED

    } HSPluginTransState;

};

#endif 
