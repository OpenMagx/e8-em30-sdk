

// Copyright (c) 24-Apr-07 - 2008 Motorola, Inc. All rights reserved.



#ifndef __AM_GLOBAL_H__
#define __AM_GLOBAL_H__

#include <qstring.h>
#include <qimage.h>
#include <quuid.h>
#include <qcopchannel_qws.h>

#include <sys/time.h>
#include "ezxlog_define.h"

#define AM_SAFE_DELETE(p) if(p!=0){delete p; p = 0;}

class AM_Global
{
public:
    enum Device
    {
        InvalidDevice = -1,     
        Flash1 = 0,             
        Flash2 = 1,             
        Card1 = 2,              
        Card2 = 3,              
        Preload = 4,            
    };

    enum Apps
    {
        InvalidApp = -1,
        Home = 0,
        Addressbook = 1,
        Notifications = 2,
        Compose = 3,            
        Call = 4,               

        RecentCall = 61,
        MMCApp = 62,
        EMail = 64,
        People = 65,
        Calendar = 66,
        Tasks = 67,
        Notes = 68,
        VoiceRecorder = 69,
        Clock = 70,
        MediaPlayer = 71,
        Camera = 72,
        DrawingPad = 73,
        PictureViewer = 74,
        Games = 75,
        PersonalSetting = 76,
        SystemSetup = 77,
        Calculator = 79,
        FileManagement = 81,
        Inetsetup = 82,
        STK = 83,
        Link = 84,
        Browser = 85,
        Modem = 86,
        WorldClock = 87,
        Syncml = 88,
        RingComposer = 89,
        AlarmClock = 91,
        BlueTooth = 92,
        JavaApp = 93,
        MideDemo = 94,
        VideoDemo = 95,
        InitialSetup = 96,
        PowerSetup = 97,
        SecuritySetup = 98,
        Certificates = 99,
        Wvimps = 100,
        Provision = 102,
        Camcord = 103,
        CameraKey = 104,
        Radio = 105,

        MotoVPN = 600,
        GoTone = 601,
        Service = 602,
        Picsel = 603,
        AlertStyle = 604,
        VOD = 605
    };


    static QCString getLauncherChannel(void);

    static bool ensureMkDir(const QString & dirName);

    static QString getPreloadDir(void);

    static QString getSetupDir(void);

    static QString getAppWriteAmDir(void);

    static QString getInstCardDir(void);

    static QString getNativeDir(void);

    static QString getInstalledQtDir(AM_Global::Device device = Flash2);

    static unsigned int getBlockSize(const QString & fileName);

    static unsigned int getBlockSize(const char *filename);

    static QUuid createUuid();

    static unsigned int getEZXUid(void);

    static unsigned int getEZXGid(void);

    static unsigned int getDRMUid(void);
};

#endif 
