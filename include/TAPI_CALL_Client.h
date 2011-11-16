

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_CALL_CLIENT_H  
#define TAPI_CALL_CLIENT_H 

#ifdef __cplusplus
extern "C" {
#endif

#include "TAPI_AppMsgId.h"
#include "TAPI_Result.h"
#include "TAPI_CALL_General.h"
#include "TAPI_CSD_AppData.h"

#define TAPI_CALL_USER_USER_INFO_MAX_LENGTH   32

#define TAPI_CALL_MAX_NUMBER_OF_CSOPTIONS      2

typedef enum _TAPI_CALL_CS_TYPE_E
{
    TAPI_CALL_CS_TYPE_VOICE,        
    TAPI_CALL_CS_TYPE_CSD,          
    TAPI_CALL_CS_TYPE_FAX,          
    TAPI_CALL_CS_TYPE_MULTIMEDIA,   
    TAPI_CALL_CS_TYPE_UNKNOWN       
} TAPI_CALL_CS_TYPE_E;

typedef enum _TAPI_CALL_CS_STK_TYPE_E
{
    TAPI_CALL_CS_STK_TYPE_BY_USER,      
    TAPI_CALL_CS_STK_TYPE_CC_MODIFIED,  
    TAPI_CALL_CS_STK_TYPE_PROACTIVE     
} TAPI_CALL_CS_STK_TYPE_E;

typedef enum _TAPI_CALL_UUI_ALIAS_ADDRESS_TYPE_E
{
    TAPI_CALL_UUI_ALIAS_ADDRESS_TYPE_RESERVED, 
    TAPI_CALL_UUI_ALIAS_ADDRESS_TYPE_EMAIL,    
    TAPI_CALL_UUI_ALIAS_ADDRESS_TYPE_URL,      
    TAPI_CALL_UUI_ALIAS_ADDRESS_TYPE_H323      
} TAPI_CALL_UUI_ALIAS_ADDRESS_TYPE_E;

typedef struct _TAPI_CALL_UUI_ALIAS_ADDRESS_TYPE_S
{
    TAPI_CALL_UUI_ALIAS_ADDRESS_TYPE_E    addressType;
    UINT8                                 uuiData[TAPI_CALL_USER_USER_INFO_MAX_LENGTH];
} TAPI_CALL_UUI_ALIAS_ADDRESS_TYPE_S;

typedef struct _TAPI_CALL_CS_DATA_OPTION_S
{
    TAPI_CALL_CS_TYPE_E                   callType;
    TAPI_CALL_DATA_RATE_E                 dataRate;
    TAPI_CALL_DATA_MODE_E                 dataMode;
    TAPI_CALL_CONNECTION_TYPE_E           connectionType;
    TAPI_CALL_DATA_DEST_TYPE_E            destType;
    BOOL                                  isUuiIncluded;
    TAPI_CALL_UUI_ALIAS_ADDRESS_TYPE_S    uuiAddress;
} TAPI_CALL_CS_DATA_OPTION_S;

extern TAPI_RESULT_E
TAPI_CALL_MakeVTCall(
                     TAPI_CALL_ID_T *callId,
                     TAPI_CALL_CS_STK_TYPE_E stkType,
                     TAPI_PHONE_NUMBER_A phoneNumber
                     );

extern TAPI_RESULT_E
TAPI_CALL_Make2StageVTCall(
                           TAPI_CALL_ID_T *callId,
                           TAPI_CALL_CS_STK_TYPE_E stkType,
                           TAPI_PHONE_NUMBER_A phoneNumber,
                           TAPI_CALL_UUI_ALIAS_ADDRESS_TYPE_S uuiAddress
                           );

extern TAPI_RESULT_E
TAPI_CALL_CallDial(
                   TAPI_CALL_ID_T *callId,
                   TAPI_CALL_CS_STK_TYPE_E stkType,
                   TAPI_PHONE_NUMBER_A phoneNumber,
                   TAPI_CALL_CS_DATA_OPTION_S csOptions[TAPI_CALL_MAX_NUMBER_OF_CSOPTIONS]
                   );

extern TAPI_RESULT_E
TAPI_CALL_CallRelease(
                      TAPI_CALL_ID_T callId,
                      TAPI_CALL_CAUSE_E cause
                      );

extern TAPI_RESULT_E
TAPI_CALL_CallReleaseAll(
                         TAPI_CALL_CAUSE_E cause
                         );

extern TAPI_RESULT_E
TAPI_CALL_CallModeChangeReq(
                            TAPI_CALL_ID_T callId,
                            TAPI_CALL_CS_TYPE_E callType
                            );

extern TAPI_RESULT_E
TAPI_CALL_CallModeChangeRsp(
                            TAPI_CALL_ID_T callId,
                            TAPI_CALL_CS_TYPE_E callType
                            );

extern TAPI_RESULT_E
TAPI_CALL_CallAnswer(
                     TAPI_CALL_ID_T    CallId 
                     );

#ifdef __cplusplus
}
#endif 

#endif  

