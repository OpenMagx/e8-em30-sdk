

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef Z_DEFS_H
#define Z_DEFS_H

#ifndef __cplusplus
#error "This is a C++ header file;it requires C++ to compile."
#endif

#include <qstringlist.h>
#include <qcstring.h>
#include <qwidget.h>
#include <qrect.h>
#include <qsize.h>
#include <qpopupmenu.h>
#include <quuid.h>
#include <qmap.h>
#include <qstring.h>

#define EZX_YEAR_MAX 2069   
#define EZX_YEAR_MIN 1901   

#define EZXQTSERVER_CHANNEL "EZX/QtServer"

#define IMSERVCHANNEL_NAME "EZX/IMServer"

#define SYSTEM_CHANNEL "EZX/System"

#define SYS_SETUP_CHANNEL "/systemsetup/broadcast"

#define MSG_SLIDER_OPENED "sliderOpened"    
#define MSG_SLIDER_CLOSED "sliderClosed"    

#define APP_CHANNEL_PREF "EZX/Application/"

#define CHN_SYS_DISPLAY_EXTERNAL "/system/display/external"
#define MSG_OPENLIDLOGO_PAINTED "openLidLogoPainted"

namespace ZGlobal
{
    enum TouchSoundType_T
    {
        CLICK = 0, 
        TONE, 
        SILENT, 
        THEMED 
    };
};

#ifdef FEAT_UISTYLE_CHAMELEON

#include <qevent.h>

#define RETURN_IDLE_EVENT            5678

#define RETURN_IDLE_BY_END_KEY       -5000
#define RETURN_IDLE_BY_FLIP          -5001
#define RETURN_IDLE_BY_APP_TIMEOUT   -5002
#define RETURN_IDLE_BY_SLIDER        -5003

#define LCD_ON_MESSAGE                   "LCDOn"               
#define LCD_OFF_MESSAGE                  "LCDOff"              
#define DISPLAY_BACKLIGHT_DIMMED         "DPL_BKLGT_DIMMED"    
#define DISPLAY_BACKLIGHT_RESTORED       "DPL_BKLGT_RESTORED"  

class ZReturnIdleEvent : public QCustomEvent
{
public:
    ZReturnIdleEvent( int nReason )
      : QCustomEvent( RETURN_IDLE_EVENT),
        accepted ( true ) { reason = nReason; }

    void reject() { accepted = false; }

    void accept() { accepted = true; }
    bool isAccepted() const { return accepted; }

    int getReason( ) const { return reason; };

private:
    int reason;
    bool accepted;
};

#endif

#endif 

