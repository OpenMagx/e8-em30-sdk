

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_SMS_SETTING_API_H    
#define TAPI_SMS_SETTING_API_H

#ifdef __cplusplus 
extern "C" {
#endif

#include  "EZX_TypeDefs.h"
#include  "TAPI_Result.h"
#include  "TAPI_General.h"
#include  "TAPI_SMS_PduModeClient.h"

#define TAPI_SMS_STORAGE_NAME_LENGTH 10

typedef enum    _TAPI_SMS_EXPIRE_PERIOD_E
{
    TAPI_SMS_EXPIRE_PERIOD_FIVE_MINUTE_EV= 0,    
    TAPI_SMS_EXPIRE_PERIOD_HALF_HOUR_EV,         
    TAPI_SMS_EXPIRE_PERIOD_DAY_EV,               
    TAPI_SMS_EXPIRE_PERIOD_WEEK_EV,              
    TAPI_SMS_EXPIRE_PERIOD_MAX_EV   = 255        
} TAPI_SMS_EXPIRE_PERIOD_E;

enum _TAPI_SMS_TRANSPORT_MODE_E
{
    TAPI_SMS_TRANSPORT_MODE_PACKET_DOMAIN_ONLY_EV       = 0,    
    TAPI_SMS_TRANSPORT_MODE_CIRCUIT_SWITCH_ONLY_EV      = 1,    
    TAPI_SMS_TRANSPORT_MODE_PACKET_DOMAIN_PREFERRED_EV  = 2,    

    TAPI_SMS_TRANSPORT_MODE_CIRCUIT_SWITCH_PREFERRED_EV = 3     

};

typedef UINT8   TAPI_SMS_TRANSPORT_MODE_E;

enum _TAPI_SMS_RPLINK_CONT_MODE_E
{
    TAPI_SMS_RPLINK_CONT_MODE_DISABLE_EV       = 0,    
    TAPI_SMS_RPLINK_CONT_MODE_KEEP_ENABLE_EV   = 1,    
    TAPI_SMS_RPLINK_CONT_MODE_ENABLE_EV        = 2,    
};

typedef UINT8 TAPI_SMS_RPLINK_CONT_MODE_E;

typedef struct  _TAPI_SMS_EXPIRE_PERIOD_DATA_S
{
    TAPI_SMS_EXPIRE_PERIOD_E    unit;
    UINT8                       value;
} TAPI_SMS_EXPIRE_PERIOD_DATA_S;

typedef struct  _TAPI_SMS_SERVICE_PARM_S
{
    UINT8   mt; 
    UINT8   mo; 
    UINT8   bm; 
} __attribute__( (packed) )  TAPI_SMS_SERVICE_PARM_S;

typedef struct  _TAPI_SMS_SERVICE_TYPE_S
{
    UINT8                   service;        

    TAPI_SMS_SERVICE_PARM_S serviceParm;    
} TAPI_SMS_SERVICE_TYPE_S;

typedef struct  _TAPI_SMS_SIM_STORAGE_STATUS_S
{
    UINT16  usedCount;  
    UINT16  totalCount; 
} TAPI_SMS_SIM_STORAGE_STATUS_S;

extern TAPI_RESULT_E   
TAPI_SMS_SetServiceCenter( 
                          const TAPI_PHONE_NUMBER_A scAddress 
                          );

extern TAPI_RESULT_E   
TAPI_SMS_GetServiceCenter( 
                          TAPI_PHONE_NUMBER_A scAddress 
                          );

extern TAPI_RESULT_E   
TAPI_SMS_SetEmailGateway(
                         const TAPI_PHONE_NUMBER_A   emailGatewayAddress 
                         );

extern TAPI_RESULT_E   
TAPI_SMS_GetEmailGateway(
                         TAPI_PHONE_NUMBER_A emailGatewayAddress 
                         );

extern TAPI_RESULT_E   
TAPI_SMS_SetExpirePeriod(
                         TAPI_SMS_EXPIRE_PERIOD_DATA_S   *pExpirePeriod 
                         );

extern TAPI_RESULT_E   
TAPI_SMS_GetExpirePeriod(
                         TAPI_SMS_EXPIRE_PERIOD_DATA_S*  pExpirePeriod 
                         );

extern TAPI_RESULT_E   
TAPI_SMS_SetMessageService(
                           UINT8                       MsgServiceType,
                           TAPI_SMS_SERVICE_PARM_S*    pServiceParm 
                           );

extern TAPI_RESULT_E   
TAPI_SMS_GetMessageService(
                           TAPI_SMS_SERVICE_TYPE_S*    pMsgServiceType 
                           );

extern TAPI_RESULT_E   
TAPI_SMS_GetSmsTransportMode( 
                             TAPI_SMS_TRANSPORT_MODE_E* pMode 
                             );

extern TAPI_RESULT_E   
TAPI_SMS_SetSmsTransportMode( 
                             TAPI_SMS_TRANSPORT_MODE_E mode 
                             );

extern TAPI_RESULT_E   
TAPI_SMS_GetRPLinkContinuityMode(
                                 TAPI_SMS_RPLINK_CONT_MODE_E*  pRPLinkContinuityMode 
                                 );

extern TAPI_RESULT_E   
TAPI_SMS_SetRPLinkContinuityMode(
                                 TAPI_SMS_RPLINK_CONT_MODE_E  RPLinkContinuityMode 
                                 );

extern BOOLEAN         
TAPI_SMS_ExpirePeriodToUINT8(
                             TAPI_SMS_EXPIRE_PERIOD_DATA_S   *pEp,
                             UINT8*                          pEpValue 
                             );

extern BOOLEAN         
TAPI_SMS_UINT8toExpirePeriod(
                             UINT8                           ep_value,
                             TAPI_SMS_EXPIRE_PERIOD_DATA_S*  ep_data 
                             );

extern BOOLEAN         
TAPI_SMS_BcdToHex(
                  UINT8*  pSrcBuf,
                  UINT8*  pHexBuf 
                  );

extern BOOLEAN         
TAPI_SMS_HexToBcd(
                  UINT8*  pBcdBuf,
                  UINT8*  pHexBuf,
                  UINT16  length 
                  );

extern TAPI_RESULT_E   
TAPI_SMS_GetSimSmsStorageStatus(
                                TAPI_SMS_SIM_STORAGE_STATUS_S*  pStorageStatus 
                                );

#ifdef __cplusplus
}
#endif 

#endif  

