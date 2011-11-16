

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef _TAPI_DATACALL_CLIENT_H 
#define _TAPI_DATACALL_CLIENT_H 

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_AppMsgId.h"
#include "TAPI_Result.h"
#include "TAPI_CALL_General.h"
#include "TAPI_CSD_AppData.h"

extern TAPI_RESULT_E   
TAPI_CSD_InitServiceClass( void );

extern TAPI_RESULT_E   
TAPI_CSD_SetBearerService( 
                          TAPI_CALL_DATA_OPTION_S* pOption 
                          );

extern TAPI_RESULT_E   
TAPI_CSD_Dial(
              TAPI_PHONE_NUMBER_A phoneNumber,
              TAPI_CALL_ID_T*     pCallID 
              );

extern TAPI_RESULT_E   
TAPI_CSD_MakeCall(
                  TAPI_PHONE_NUMBER_A         phoneNumber,
                  TAPI_CALL_DATA_OPTION_S*    pOption,
                  TAPI_CALL_ID_T*             pCallID 
                  );

extern TAPI_RESULT_E   
TAPI_CSD_AnswerCall( 
                    TAPI_CALL_ID_T callId 
                    );

extern TAPI_RESULT_E   
TAPI_CSD_AcceptCall(
                    TAPI_CALL_ID_T              callId,
                    TAPI_CALL_DATA_OPTION_S*    pOption 
                    );

extern TAPI_RESULT_E   
TAPI_CSD_DropCall( 
                  TAPI_CALL_ID_T callId 
                  );

extern TAPI_RESULT_E   
TAPI_CSD_ChangeToCommandMode( 
                             INT32 fd 
                             );

extern TAPI_RESULT_E   
TAPI_CSD_DropAllCall( void );

extern TAPI_RESULT_E   
TAPI_CSD_GetRadioLinkProtocol(
                              TAPI_CRLP_READ_PARM_LIST_S*     pRLinkList 
                              );

extern TAPI_RESULT_E   
TAPI_CSD_SetRadioLinkProtocol(
                              TAPI_CALL_DATA_RLP_PARAM_S*     pParam 
                              );

extern TAPI_RESULT_E   
TAPI_CSD_ResetTotalConnectedDuration( void );

extern TAPI_RESULT_E   
TAPI_CSD_GetTotalConnectedDuration( 
                                   UINT32* pConnectedDuration 
                                   );

extern TAPI_RESULT_E   
TAPI_CSD_GetCurrentConnectedDuration(
                                     UINT32*     pConnectedDuration 
                                     );

#ifdef __cplusplus
}
#endif 

#endif  

