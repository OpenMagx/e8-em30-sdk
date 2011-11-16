

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef __ZUNS_UTIL_H__
#define __ZUNS_UTIL_H__

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qarray.h>
#include <qdatastream.h>
#include <quuid.h>
#include "AM_ActionData.h"

class QString;
class QCString;

template<class Key, class T> class QMap;

#define UNS_CALLBACK_MSG "UNSCallback"

#define UNS_CALLBACK_MSG_CLEAR "UNSCallbackClear"

#define UNS_CALLBACK_MSG_CLEAR_ALL   "UNSCallbackClearAll"

#define UNS_MISSED_EVENT_TYPE_INVALID ((int)0x80000000)

enum MISSED_EVENT_T             
{

    MET_NONE,

    MET_MISSED_CALL_VOICE,   
    MET_MISSED_CALL_PTT,     
    MET_MISSED_CALL_PTT_IPA, 
    MET_MISSED_CALL_PTT_RTT, 
    MET_MISSED_CALL_VIDEO,   

    MET_UNABLE_TO_SEND_MESSAGE,                             
    MET_FAILED_TO_SEND_MESSAGE,                             
    MET_MESSAGE_DOWNLOAD_FAILED,                            
    MET_INCOMING_MMS_MESSAGE,                               
    MET_INCOMING_SMS_BROWSER_EMS_INFO_SERVICE_MESSAGE,      
    MET_INCOMING_SMS_MMS_EMS_INFO_SERVICE_BROWSER_MESSAGE,  
    MET_INCOMING_CONFIGURATION_MESSAGE,                     
    MET_INCOMING_MMS_MESSAGE_WITH_DEFERRED_DOWNLOAD_TURNED_ON,  
    MET_INCOMING_READ_REPORT_MESSAGE,
    MET_INCOMING_SMS_MESSAGE_STORED_DIRECTLY_TO_SIM_CARD,   
    MET_INCOMING_UPI_MESSAGES,                              
    MET_NEW_VOICEMAIL,                                      
    MET_INCOMING_VOICEMAIL,
    MET_WIFI_PROFILE,                                       
    MET_MSG_MEMORY_FULL,                                    
    MET_MSG_DOWNLOAD_COMPLETE,                              

    MET_INCOMING_VIDEO_MAIL_NOTIFICATION, 

    MET_NEW_EMAIL,
    MET_EMAIL_DOWNLOAD_COMPLETE, 

    MET_DM_SYS_MSG,

    MET_DOWNLOAD_COMPLETE_SINGLE,	
    MET_DOWNLOAD_COMPLETE_MULTIPLE, 
    MET_DOWNLOAD_FAILED_SINGLE,     
    MET_BLUETOOTH_RECEIVE_COMPLETE, 
    MET_BLUETOOTH_SEND_COMPLETE,    

    MET_IM_SYSTEM_MESSAGE,           
    MET_IM_ROAMING_MESSAGE,          
    MET_NEW_IM,                      
    MET_IM_INVITATION,               
    MET_IM_FILE_TRANSFER_REQUEST,    
    MET_IM_PRESENCE_AUTHORIZATION,   
    MET_IM_OFFLINE_MSG,              

    MET_PTT_ONLINE_ALERT,
    MET_PTT_GROUP_ADVERTISEMENT, 
    MET_KODIAK_PTT_NOTICE,  

    MET_JAVA_PUSH_MSG,

    MET_CALENDAR_EVENT,

    MET_MAX_NATIVE,       

    MET_OTHERS_MISSED = MET_MAX_NATIVE, 

};

struct MISSED_EVENT_ITEM_SUB_T
{
    MISSED_EVENT_T source;   
    int            subType;  
    int            itemID;
    int            count;    

    MISSED_EVENT_ITEM_SUB_T() :
        source(MET_NONE), subType(0), itemID(0), count(0)
    {}
};

void UNS_AddItem(int source, int subType, int itemID,
                 const QString& text, const QString& iconFile,
                 const QCString& channel, const QByteArray& data,
                 const QUuid& appUuid, unsigned int count = 1,
                 bool bNewItem = true, bool bActionable = false);

void UNS_AddItem(int source, int subType, int itemID,
        const QString& text, const QString& iconFile,
        const AM_ActionData &actionData, unsigned int count = 1,
        bool bNewItem = true, bool bActionable = false);

void UNS_RemoveItem(int source, int subType, int itemID);

void UNS_SetBrandedIMPromptForCLI(const QMap<MISSED_EVENT_T, QString>&);

struct MISSED_EVENT_ITEM
{
    MISSED_EVENT_T source;   
    int   count;             

    MISSED_EVENT_ITEM() :
        source(MET_NONE), count(0)
    {}
};

extern QDataStream& operator<<(QDataStream&, const MISSED_EVENT_ITEM&);
extern QDataStream& operator>>(QDataStream&, MISSED_EVENT_ITEM&);

extern QDataStream& operator<<(QDataStream&, const MISSED_EVENT_T&);
extern QDataStream& operator>>(QDataStream&, MISSED_EVENT_T&);

#endif  

