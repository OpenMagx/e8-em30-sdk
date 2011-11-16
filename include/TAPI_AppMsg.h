

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef _TAPI_APPMSG_H 
#define _TAPI_APPMSG_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "EZX_TypeDefs.h"
#include "TAPI_AppMsgId.h"

typedef struct  _TAPI_APP_MSG_S
{
    TAPI_APP_MSGID_T    msgId;      
    UINT16              msgLen;     

    UINT8*              pMsgBody;   
} __attribute__( (packed) )  TAPI_APP_MSG_S;

#ifdef __cplusplus
}

#endif
#endif 
