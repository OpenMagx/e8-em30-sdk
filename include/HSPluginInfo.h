

// Copyright (c) 09-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef HSPLUGININFO_H
#define HSPLUGININFO_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>
#include <qrect.h>

#include "HSPlugin.h"

class HSPluginInfo {

    public:
    typedef enum
    {
        HSPLUGIN_STATUS_LAUNCH_WHEN_POWER_ON = 0x00000001,
        HSPLUGIN_STATUS_ACTIVE = 0x00000002,
        HSPLUGIN_STATUS_MULTIPLE_DISPLAY_RECT = 0x00000004,
        HSPLUGIN_STATUS_UNINSTALL_PLUG_IN = 0x00000008
    }HSPLUGIN_STATUS;

    typedef enum
    {
        HSPLUGIN_STATE_ACTIVE = 0x00000001,
        HSPLUGIN_STATE_FOCUS = 0x00000002,
        HSPLUGIN_STATE_INITIALIZED = 0x00000004,
        HSPLUGIN_STATE_HIDDEN = 0x00000008,
        HSPLUGIN_STATE_DROP_BY_LAYOUT = 0x00010000

    }HSPLUGIN_STATE;

    virtual ~HSPluginInfo() {};

    virtual QString getPluginName() const = 0;

    virtual HSPlugin* getPlugin() = 0;

    virtual void setState(HSPluginInfo::HSPLUGIN_STATE state, bool value) = 0;

    virtual bool checkState(HSPluginInfo::HSPLUGIN_STATE state) = 0;

    virtual bool isHidden() = 0;

    virtual void setGeometry(const QRect& rect) = 0;

    virtual const QRect* getGeometry() = 0;

    virtual int getFocusIndex() const = 0;

    virtual int getDisplayIndex() const = 0;
};

#endif 
