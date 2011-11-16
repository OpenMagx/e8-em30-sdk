

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef _TAPI_SYNC_CLIENT_H_
#define _TAPI_SYNC_CLIENT_H_

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_SYNC_AppData.h"

extern TAPI_RESULT_E   
TAPI_SYNC_SendRequest(
                      TAPI_APP_MSGID_T    msgId,
                      const UINT8*        pMsgBody,
                      UINT16              msgLen 
                      );

extern TAPI_RESULT_E   
TAPI_SYNC_ReadAndMallocMsg(
                           INT32               sockFd,
                           TAPI_APP_MSG_S*     pAppMsg 
                           );

extern TAPI_RESULT_E   
TAPI_SYNC_GetSyncContents( 
                          TAPI_SYNC_CONTENT_REQ_S* pContent 
                          );

extern TAPI_RESULT_E   
TAPI_SYNC_SetRemoveDbTableResult( 
                                 BOOLEAN bSucc 
                                 );

extern TAPI_RESULT_E   
TAPI_SYNC_SetAdnSyncDbCompleted( 
                                void 
                                );

extern TAPI_RESULT_E   
TAPI_SYNC_SetFdnSyncDbCompleted( 
                                void 
                                );

extern TAPI_RESULT_E   
TAPI_SYNC_SetSdnSyncDbCompleted( 
                                void 
                                );

extern TAPI_RESULT_E   
TAPI_SYNC_SetSmsSyncDbCompleted( 
                                void 
                                );

#ifdef __cplusplus
}
#endif 

#endif  

