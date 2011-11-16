

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_CALL_APPDATA_H   
#define TAPI_CALL_APPDATA_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_CSD_AppData.h"
#include "TAPI_CALL_General.h"
#include "TAPI_General.h"
#include "TAPI_CALL_Client.h"

typedef struct _TAPI_CALL_NOTIFY_INCOMING_MSG_S
{
    TAPI_CALL_ID_T             callId;      
    TAPI_PHONE_NUMBER_A        phoneNumber; 
    TAPI_CALL_LINE_E           lineNumber;  
    TAPI_CALL_CS_DATA_OPTION_S csOptions[TAPI_CALL_MAX_NUMBER_OF_CSOPTIONS];
} TAPI_CALL_NOTIFY_INCOMING_MSG_S;

typedef struct _TAPI_CALL_NOTIFY_CONNECT_MSG_S
{
    TAPI_CALL_ID_T      callId;    
    TAPI_CALL_CS_TYPE_E callType;  
    pid_t               pid;       
} TAPI_CALL_NOTIFY_CONNECT_MSG_S;

typedef struct _TAPI_CALL_NOTIFY_DISCONNECT_MSG_S
{
    TAPI_CALL_ID_T      callId;    
    TAPI_CALL_CAUSE_E   cause;     
} TAPI_CALL_NOTIFY_DISCONNECT_MSG_S;

typedef struct _TAPI_CALL_NOTIFY_MODE_CHANGE_MSG_S
{
    TAPI_CALL_ID_T      callId;    
    TAPI_RESULT_E       result;    
    TAPI_CALL_CS_TYPE_E callType;  
} TAPI_CALL_NOTIFY_MODE_CHANGE_MSG_S;

typedef struct _TAPI_CALL_NOTIFY_CSOPTIONS_MODIFIED_MSG_S
{
    TAPI_CALL_ID_T             callId;    
    TAPI_CALL_CS_DATA_OPTION_S csOptions[TAPI_CALL_MAX_NUMBER_OF_CSOPTIONS];
} TAPI_CALL_NOTIFY_CSOPTIONS_MODIFIED_MSG_S;

#ifdef __cplusplus
}
#endif 

#endif  

