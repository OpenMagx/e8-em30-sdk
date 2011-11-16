//Fix for E8/EM30 by Ant-ON, 25-10-2010

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ZHEADER_H
#define ZHEADER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <ZWidget.h>
#include <qstring.h>
#include <qrect.h>

#define FULL_TYPE MAINDISPLAY_HEADER
#define NORMAL_TYPE CLI_HEADER

class ZHeaderSysStatus;
class QTimer;
class ZHeaderPrivate;

class ZHeader : public ZWidget
{
Q_OBJECT
public:
    enum HEADER_TYPE
    {
        CLI_HEADER,       
        CLI_IDL,      
        MAINDISPLAY_IDL,   
        MAINDISPLAY_HEADER, 
        INVALID_TYPE,   
        HEADER_TYPE_NUM = INVALID_TYPE
    };

    enum HEADER_STATUS
    {
        AIRPLANE,     
        ROAMING,      
        SIGNAL,       
        ACTIVE_CIRCUIT_DATA_CALL,   
        ACTIVE_VOICE_CALL,      
        VIDEO_CALL,     
        UMA,         
        WIFI,        
        GPRS,          
        EDGE,         
        HSDPA,         
        THREEG,         
        CDMAPDS,       
        SERVICE,        
        CALLFORWARDING,
        ACTIVELINE,    
        VOICEPRIVACY,   
        VR,            
        ROGERSMAIL,    
        BATTERY,      
        IM,            
        SYNC,           
        BT,            
        NOTIFY,        
        PRESENCE,      
        MESSAGE,       
        LOCATION,     
        HOMEZONE,     
        ALERT,        
        WIFISIGNAL,   
        USB,       
        AIM,        
        YAHOO,       
        ICQ,          
        MSN,           
        SPEAKER,     
        FDN,          
        JAVA,        
        NEWVOICE,     
        UNHEARD_VOICE,
        EMAIL,         
        ALARMCLOCK,     
        PTT,            
        MEDIAPLAYER,  
        RADIO,         
        INVALID_MODE,   
        STATUS_NUM  
    };

    enum
    {
        EMPTY_STATUS = -1, 
        START_BLINK = -3,
        END_BLINK = -4,     
        START_ANIMATION = -5,
        END_ANIMATION = -6
    };

    typedef struct AppStatus
    {
        Q_INT8 status;
        QString strResID[HEADER_TYPE_NUM];
    } AppStatus_S;

    class AppStatusInfo_S
    {
    public:
        AppStatusInfo_S();
        ~AppStatusInfo_S();

        Q_INT8 status;        
        Q_INT32 numStatus; 
        Q_INT32 priority;      
        AppStatus_S* appStatus;
    };
    
    ZHeader(QWidget* parent = 0, const char* name = 0, WFlags f = 0);
    ZHeader(ZHeader::HEADER_TYPE t,
            QWidget* parent = 0,
            const char* name = 0,
            WFlags f = 0);

    QString getPrimTitle();
    QString getSecondTitle();
    void setPrimTitle(const QString &text);
    void setSecondTitle(const QString &text);
    bool setTitleIcon(const QPixmap& pmp);
    QPixmap getTitleIcon();
    void setAlignment(int alignment);
    int alignment();
    static QSize headerSize(ZHeader::HEADER_TYPE t);
    static bool registerInfo(const ZHeader::AppStatusInfo_S& as);
    static bool changeStatus(ZHeader::HEADER_STATUS s, int statusVal);
    static bool unregisterInfo(ZHeader::HEADER_STATUS s);
    bool switchHeader(ZHeader::HEADER_TYPE t);
    void setPalette(const QPalette& pal);
    QPixmap getBlendedPixmap(int nIdx);
    bool isZEnable();
    static int getStatusVal(ZHeader::HEADER_STATUS s);
    void setTruncEnable(bool bTrunc);
    bool isTruncEnable();
    ~ZHeader();
    void setMeterRange(int min, int max);
    void setMeterValue(int val);
    void showMeter();
    void hideMeter();

signals:
    void primTitleChanged(const QString& s);
    void secondTitleChanged(const QString& s);
    void serverInitialized();
    void blendedPixmapChanged(int nIdx);

protected slots:
    void slotChangePrimTitle(const QString& text);
    void slotChangeSecondTitle(const QString& text);
    void slotGetIcon(int nIdx);
    void slotDisplayTime();
    void slotPaletteChanged();
    void slotLoadDataFromSharedMemory();

protected:
    void updateArea(int nIdx);
    void init();
    void initStatus(ZHeader::HEADER_TYPE t);
    virtual void paintEvent(QPaintEvent*);
    virtual void resizeEvent(QResizeEvent*);
    void setTimeString();    

private:
    ZHeaderPrivate * d;
};

#endif

