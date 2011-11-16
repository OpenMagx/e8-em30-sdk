

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_SMS_ENCODE_CLIENT_H  
#define TAPI_SMS_ENCODE_CLIENT_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "EZX_TypeDefs.h"
#include "TAPI_General.h"
#include "TAPI_Result.h"
#include "TAPI_SMS_TextModeClient.h"
#include "TAPI_SMS_PduModeClient.h"

extern TAPI_RESULT_E   
TAPI_SMS_PackMoSmToSinglePdu(
                             TAPI_SMS_MO_SM_S*   pMoSms,
                             TAPI_SMS_PDU_SM_S*  pPduSm 
                             );

extern TAPI_RESULT_E   
TAPI_SMS_PackMtSmToSinglePdu(
                             TAPI_SMS_MT_SM_S*   pMtSm,
                             TAPI_SMS_PDU_SM_S*  pPduSm 
                             );

extern TAPI_RESULT_E   
TAPI_SMS_PackTextSingleUserData(
                                const W_CHAR*       pSmContent,
                                UINT8               userDataLength,
                                UINT8*              pPackedUserData,
                                UINT16*             pBitsNumber,
                                TAPI_SMS_TYPE_E*    pEncodingType 
                                );

extern TAPI_RESULT_E   
TAPI_SMS_PackPeerAddress(
                         TAPI_PHONE_NUMBER_A peerAddress,
                         UINT8               bufLength,
                         UINT8*              pPackedData 
                         );

extern TAPI_RESULT_E   
TAPI_SMS_PackScAddress(
                       TAPI_PHONE_NUMBER_A scAddress,
                       UINT8               bufLength,
                       UINT8*              pPackedData 
                       );

extern TAPI_RESULT_E   
TAPI_SMS_PackTimeStamp(
                       const TAPI_SMS_TIME_STAMP_S*    pTs,
                       UINT8*                          pTpScts 
                       );

#ifdef __cplusplus
}
#endif 

#endif  

