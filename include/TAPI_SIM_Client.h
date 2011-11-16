

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef _TAPI_SIM_CLIENT_H
#define _TAPI_SIM_CLIENT_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "EZX_TypeDefs.h"
#include "TAPI_General.h"
#include "TAPI_SETUP_General.h"

#define TAPI_MAX_SUBSCRIBE_ID_STRING_LENGTH TAPI_IMSI_LENGTH

#define TAPI_SIM_SECURITY_MAX_RAND_LENGTH (16)

#define TAPI_SIM_SECURITY_MAX_AUTN_LENGTH (16)

#define TAPI_SIM_SECURITY_MAX_AUTH_CNF_DATA_LENGTH (60)

typedef UINT8 TAPI_NETWORK_SUBSCRIBER_ID_STRING_A [TAPI_MAX_SUBSCRIBE_ID_STRING_LENGTH]; 

enum _TAPI_SECURITY_CONTEXT_E
{
    TAPI_SECURITY_CONTEXT_GSM = 0, 
    TAPI_SECURITY_CONTEXT_3G,      
    TAPI_GSM_AUTHENTICATION,       
    TAPI_SECURITY_CONTEXT_ISIM     
};

typedef UINT8 TAPI_SECURITY_CONTEXT_E;

enum _TAPI_SIM_AUTH_STATUS_E
{
     TAPI_AUTH_STATUS_SUCCESS = 0 , 
     TAPI_AUTH_STATUS_OPERATION_FAILED , 
     TAPI_AUTH_STATUS_OPERATION_NOT_ALLOWED , 
     TAPI_AUTH_STATUS_SEQ_FAILURE , 
     TAPI_AUTH_STATUS_BAD_CARD 
};

typedef UINT8 TAPI_SIM_AUTH_STATUS_E;

typedef struct _TAPI_SIM_IMSI_EXT_S
{
    TAPI_NETWORK_MCC_DIGITS_A mcc;
    TAPI_NETWORK_MNC_DIGITS_A mnc;
    TAPI_NETWORK_SUBSCRIBER_ID_STRING_A subscribeId; 
} TAPI_SIM_IMSI_EXT_S;

typedef struct _TAPI_SIM_AUTH_REQ_S
{
  TAPI_SECURITY_CONTEXT_E security_context;
  UINT8 rand_length;
  UINT8 rand[TAPI_SIM_SECURITY_MAX_RAND_LENGTH];
  UINT8 auth_length;
  UINT8 auth[TAPI_SIM_SECURITY_MAX_AUTN_LENGTH];
} TAPI_SIM_AUTH_REQ_S;

typedef struct _TAPI_SECURITY_RUN_ALGO_CNF_S
{
   TAPI_SIM_AUTH_STATUS_E status;
   UINT8 data_length ;
   UINT8 data[TAPI_SIM_SECURITY_MAX_AUTH_CNF_DATA_LENGTH];

} TAPI_SECURITY_RUN_ALGO_CNF_S;

extern TAPI_RESULT_E 
TAPI_SIM_GetImsiExt(
                    TAPI_SIM_IMSI_EXT_S* pImsiExt 
                    );

extern TAPI_RESULT_E TAPI_SECURITY_RunAuthenticationReq ( TAPI_SECURITY_CONTEXT_E context,
                                                    UINT8 rand_len,
                                                    UINT8 * prand,
                                                    UINT8 auth_len,
                                                    UINT8 * pauth,
                                                    TAPI_SIM_AUTH_STATUS_E * AuthCnfStatus,
                                                    UINT8 * pAuthCnfLen,
                                                    UINT8 * pAuthCnfData);

#ifdef __cplusplus
}
#endif 

#endif  

