

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_CPHS_CLIENT_H 
#define TAPI_CPHS_CLIENT_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_SETUP_General.h"
#include "TAPI_Result.h"

enum _TAPI_CPHS_STATUS_E
{
    TAPI_CPHS_INVALID_EV            = 0,    
    TAPI_CPHS_SUPPORT_PHASE_ONE_EV  = 1,    
    TAPI_CPHS_SUPPORT_PHASE_TWO_EV  = 2,    
};

typedef UINT8   TAPI_CPHS_STATUS_E;

typedef enum
{
    TAPI_CPHS_MESSAGE_WAITING_FLAG_TYPE_LINE1_EV= 0,
    TAPI_CPHS_MESSAGE_WAITING_FLAG_TYPE_LINE2_EV= 1,
    TAPI_CPHS_MESSAGE_WAITING_FLAG_TYPE_FAX_EV  = 2,
    TAPI_CPHS_MESSAGE_WAITING_FLAG_TYPE_DATA_EV = 3,
} TAPI_CPHS_MESSAGE_WAITING_FLAG_TYPE_E;

typedef enum
{
    TAPI_CPHS_MESSAGE_WAITING_FLAG_OFF_EV       = 0,
    TAPI_CPHS_MESSAGE_WAITING_FLAG_ON_EV        = 1,
} TAPI_CPHS_MESSAGE_WAITING_FLAG_E;

typedef struct  _TAPI_CPHS_NOTIFY_INFO_MSG_S
{
    TAPI_CPHS_STATUS_E  cphsStatus;         
    TAPI_BOOL_STATUS_E  voiceMailStatus;    
    TAPI_BOOL_STATUS_E  shortFormStatus;    
    TAPI_BOOL_STATUS_E  cspStatus;          
    TAPI_BOOL_STATUS_E  infoNumbersStatus;  
    TAPI_BOOL_STATUS_E  sstStatus;          
} TAPI_CPHS_NOTIFY_INFO_MSG_S;

typedef struct  _TAPI_CALL_DIVERT_PARAM_WITHTIME_S
{
    TAPI_CALL_DIVERT_MODE_E mode;           
    TAPI_PHONE_NUMBER_A     number;         
    UINT8                   time;           
} TAPI_CALL_DIVERT_PARAM_WITHTIME_S;

typedef struct  _TAPI_CPHS_MESSAGE_WAITING_FLAG_PARAM_S
{
    TAPI_CPHS_MESSAGE_WAITING_FLAG_TYPE_E   type;
    TAPI_CPHS_MESSAGE_WAITING_FLAG_E        flag;
} TAPI_CPHS_MESSAGE_WAITING_FLAG_PARAM_S;

typedef struct  _TAPI_CPHS_NOTIFY_WAITTING_MSG_S
{
    BOOLEAN hasLine1VoiceMessage;           
    BOOLEAN hasLine2VoiceMessage;           
    BOOLEAN hasDataMessage;                 
    BOOLEAN hasFaxMessage;                  
} TAPI_CPHS_NOTIFY_WAITTING_MSG_S;

typedef struct  _TAPI_CPHS_INFO_NUMBERS_S
{
    UINT16                  index;
    TAPI_PHONE_NUMBER_A     phoneNumber;
    UINT8                   entryStatus;
    TAPI_PHONEBOOK_NAME_A   alphaTag;
} TAPI_CPHS_INFO_NUMBERS_S;

extern TAPI_RESULT_E   
TAPI_CPHS_GetLongName( 
                      TAPI_NETWORK_PLMN_NAME_A name 
                      );

extern TAPI_RESULT_E   
TAPI_CPHS_GetShortName( 
                       TAPI_NETWORK_PLMN_NAME_A name 
                       );

extern TAPI_RESULT_E   
TAPI_CPHS_GetCallDivertStatus(
                              TAPI_BOOL_STATUS_E*     pIsLine1DivertOn,
                              TAPI_BOOL_STATUS_E*     pIsLine2DivertOn 
                              );

extern TAPI_RESULT_E   
TAPI_CPHS_GetLineLockStatus( 
                            BOOLEAN* pIsLock 
                            );

extern TAPI_RESULT_E   
TAPI_CPHS_SetLineLockStatus( 
                            const BOOLEAN isLock 
                            );

extern TAPI_RESULT_E   
TAPI_CPHS_SetMessageWaitingFlag(
                                const TAPI_CPHS_MESSAGE_WAITING_FLAG_TYPE_E type,
                                const TAPI_CPHS_MESSAGE_WAITING_FLAG_E      state 
                                );

extern TAPI_RESULT_E   
TAPI_CPHS_GetInformationNumberRecords(
                                      UINT16                      start,
                                      UINT16                      count,
                                      TAPI_CPHS_INFO_NUMBERS_S*   pInfoNumber 
                                      );

extern TAPI_RESULT_E   
TAPI_CPHS_GetInformationNumberRecordCount( 
                                          UINT32* pCount 
                                          );

#ifdef __cplusplus
}

#endif
#endif 
