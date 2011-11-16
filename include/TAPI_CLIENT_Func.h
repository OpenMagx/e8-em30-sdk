

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef _TAPI_CLIENT_FUNC_H  
#define _TAPI_CLIENT_FUNC_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_General.h"
#include "TAPI_AppMsgId.h"
#include "TAPI_AppMsg.h"
#include "TAPI_Result.h"

INTERFACE INT32         
TAPI_CLIENT_Init(
                 const TAPI_APP_MSGID_T*     pAsynMsgBuf,
                 UINT8                       asyncMsgNum 
                 );

INTERFACE void          
TAPI_CLIENT_Fini( void );

INTERFACE INT32         
TAPI_CLIENT_ReadMessage(
                        INT32       tapiFd,
                        void*       pBuf,
                        UINT16*     pBufLen 
                        );

INTERFACE TAPI_RESULT_E 
TAPI_CLIENT_RegisterAsyncMsgId(
                               const TAPI_APP_MSGID_T*     pMsgId,
                               UINT16                      msgIdNums 
                               );

INTERFACE TAPI_RESULT_E 
TAPI_CLIENT_DeregisterAsyncMsgId(
                                 const TAPI_APP_MSGID_T*     pMsgId,
                                 UINT16                      msgIdNums 
                                 );

#ifdef __cplusplus
}

#endif
#endif 
