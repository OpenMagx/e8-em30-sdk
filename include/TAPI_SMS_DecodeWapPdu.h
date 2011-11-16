

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_SMS_DECODEWAPPDU_H 
#define TAPI_SMS_DECODEWAPPDU_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_SMS_TextModeClient.h"
#include "TAPI_SMS_PduModeClient.h"
#include "TAPI_Result.h"

#define WAP_PUSH_MAX_LEN 141

typedef struct  _TAPI_SMS_WAP_SM_S
{
    TAPI_PHONE_NUMBER_A     originalAddress;
    TAPI_PHONE_NUMBER_A     scAddress;
    TAPI_SMS_PROTOCOL_E     protocol;
    TAPI_SMS_TIME_STAMP_S   timeStamp;
    TAPI_SMS_TYPE_E         encodingType;
    UINT8                   userData[WAP_PUSH_MAX_LEN];
} TAPI_SMS_WAP_SM_S;

extern TAPI_RESULT_E   
TAPI_SMS_DecodeWapPdu(
                      TAPI_SMS_PDU_SM_S*  pPdu,
                      TAPI_SMS_WAP_SM_S*  pWapSm 
                      );

#ifdef __cplusplus
}
#endif 

#endif  

