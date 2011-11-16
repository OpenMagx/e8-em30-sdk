

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_SMS_DECODE_CLIENT_H     
#define TAPI_SMS_DECODE_CLIENT_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "EZX_TypeDefs.h"
#include "TAPI_Result.h"
#include "TAPI_SMS_TextModeClient.h"

extern TAPI_RESULT_E   
TAPI_SMS_DecodeSinglePdu(
                         UINT8                       state,
                         UINT8                       pduLen,
                         UINT8                       tpduLen,
                         UINT8*                      pPduData,
                         TAPI_SMS_SIM_STORE_SM_S*    pSm 
                         );

#ifdef __cplusplus
}
#endif 

#endif  

