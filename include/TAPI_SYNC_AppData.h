

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef _SYNC_APPDATA_H
#define _SYNC_APPDATA_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_AppMsgId.h"
#include "TAPI_AppMsg.h"
#include "TAPI_SMS_TextModeClient.h"

#define TAPI_SYNC_MAX_SMS_PDU_LENGTH  256

enum _TAPI_SYNCMSGID
{
    TAPI_SYNC_NOTIFY_SIM_READY_MSGID            = TAPI_APP_ASYNC_SYNC_MSG_GRPID + 1,

    TAPI_SYNC_NOTIFY_IMSI_MSGID,                     

    TAPI_SYNC_NOTIFY_FD_STATUS_MSGID,                

           /**< Notify SyncApp Enhanced Fixdialing status. 
                                                          The msg body is UINT8, whose value is the 
                                                          same as #TAPI_FEATURE_E.*/
    TAPI_SYNC_NOTIFY_GET_ADN_CAPACITY_MSGID,         

    TAPI_SYNC_NOTIFY_GET_ADN_ENTRY_MSGID,            
    TAPI_SYNC_NOTIFY_GET_MSISDN_ENTRY_MSGID,         
    TAPI_SYNC_NOTIFY_GET_FD_CAPACITY_MSGID,          

    TAPI_SYNC_NOTIFY_GET_FD_ENTRY_MSGID,             
    TAPI_SYNC_NOTIFY_GET_SMS_ENTRY_MSGID,            
    TAPI_SYNC_NOTIFY_GET_SMS_SC_MSGID,               

    TAPI_SYNC_NOTIFY_SMS_CAPACITY_MSGID,             
    TAPI_SYNC_NOTIFY_GET_SPN_MSGID,                  

    TAPI_SYNC_NOTIFY_GET_CPHS_LONG_NAME_MSGID,       

    TAPI_SYNC_NOTIFY_GET_CPHS_SHORT_NAME_MSGID,      

    TAPI_SYNC_NOTIFY_FDN_DATA_MSGID,                 

    TAPI_SYNC_NOTIFY_ADN_DATA_MSGID,                 

    TAPI_SYNC_NOTIFY_SMS_DATA_MSGID,                 

    TAPI_SYNC_NOTIFY_GET_SDN_CAPACITY_MSGID,         

    TAPI_SYNC_NOTIFY_GET_SDN_ENTRY_MSGID,            
    TAPI_SYNC_NOTIFY_SDN_DATA_MSGID,                 

    TAPI_SYNC_NOTIFY_DB_READY_MSGID,                 
    TAPI_SYNC_NOTIFY_BP_FLEX_CHANGE_MSGID,           
    TAPI_SYNC_COMPLETED_MSGID,                       

    TAPI_APP_ASYNC_SYNC_MSG_GRPID_END           = TAPI_SYNC_COMPLETED_MSGID
};

typedef enum    _TAPI_SYNC_TYPE_E
{
    TAPI_SYNC_TYPE_POWER_ON_INIT_EV,         
    TAPI_SYNC_TYPE_STK_REFRESH_EV,           
    TAPI_SYNC_TYPE_FIXDIALLING_CHANGE_EV     
} TAPI_SYNC_TYPE_E;

typedef struct  _TAPI_SYNC_ITEM__S
{
    BOOLEAN bSyncImsi;               
    BOOLEAN bSyncCphsLongName;       
    BOOLEAN bSyncCphsShortName;      
    BOOLEAN bSyncSpn;                
    BOOLEAN bSyncFdStatus;           
    BOOLEAN bSyncSc;                 
    BOOLEAN bSyncAdn;                
    BOOLEAN bSyncFdn;                
    BOOLEAN bSyncSms;                
    BOOLEAN bSyncBpFlex;             
    BOOLEAN bSyncSdn;                
    BOOLEAN bSyncSimProvisionFile;   
    BOOLEAN bSyncSimCertification;   
    BOOLEAN bSyncStkIcon;            
} TAPI_SYNC_ITEM_S;

typedef struct  _TAPI_SYNC_CONTENT_REQ_S
{
    TAPI_SYNC_TYPE_E    syncType;        
    BOOLEAN             bDbReady;        
    TAPI_SYNC_ITEM_S    syncItems;       
} TAPI_SYNC_CONTENT_REQ_S;

typedef struct  _TAPI_SYNC_NOTIFY_SIM_SMS_DATA_MSG_S
{
    UINT16  index;           
    UINT8   smsStatus;       
    UINT8   pduLen;          
    UINT8   tpduLen;         
    UINT8   pdu[TAPI_SYNC_MAX_SMS_PDU_LENGTH];       
} __attribute__( (packed) )  TAPI_SYNC_NOTIFY_SIM_SMS_DATA_MSG_S;

#ifdef __cplusplus
}
#endif 

#endif  

