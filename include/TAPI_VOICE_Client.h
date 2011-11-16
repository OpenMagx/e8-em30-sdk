

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_VOICECALL_CLIENT_H 
#define TAPI_VOICECALL_CLIENT_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_AppMsgId.h"
#include "TAPI_Result.h"
#include "TAPI_CALL_General.h"
#include "TAPI_VOICE_AppData.h"

extern TAPI_RESULT_E   
TAPI_VOICE_MakeCall(
                    TAPI_CALL_LINE_E    line_no,
                    TAPI_PHONE_NUMBER_A phoneNumber,
                    TAPI_CALL_ID_T*     pCallID 
                    );

extern TAPI_RESULT_E   
TAPI_VOICE_MakeStkCall(
                       TAPI_PHONE_NUMBER_A         phoneNumber,
                       TAPI_VOICE_DIAL_CALL_TYPE_E type,
                       BOOLEAN                     bRedial,
                       UINT32                      duration,
                       TAPI_CALL_ID_T*             pCallID 
                       );

extern TAPI_RESULT_E   
TAPI_VOICE_AnswerCall(
                      TAPI_CALL_ID_T                  callId,
                      TAPI_VOICE_ANSWER_CALL_TYPE_E   type 
                      );

extern TAPI_RESULT_E   
TAPI_VOICE_DropCall(
                    TAPI_CALL_ID_T              callId,
                    TAPI_VOICE_DROP_CALL_TYPE_E type 
                    );   

extern TAPI_RESULT_E   
TAPI_VOICE_DropAllCall( void );

extern TAPI_RESULT_E  
TAPI_VOICE_DropCurrentCall(
                           TAPI_CALL_ID_T callId 
                           );

extern TAPI_RESULT_E   
TAPI_VOICE_DropSpecificCall( 
                            TAPI_CALL_ID_T callId 
                            );

extern TAPI_RESULT_E   
TAPI_VOICE_RejectCall(
                      TAPI_CALL_ID_T                  callId,
                      TAPI_VOICE_REJECT_CALL_TYPE_E   type 
                      );

extern TAPI_RESULT_E   
TAPI_VOICE_CancelCall( 
                      TAPI_CALL_ID_T callId 
                      );

extern TAPI_RESULT_E   
TAPI_VOICE_MakeDtmfTone(
                        UINT8                           dtmfCh,
                        TAPI_VOICE_DTMF_KEY_STATUS_E    upOrDown 
                        );

extern TAPI_RESULT_E   
TAPI_VOICE_HoldCall( 
                    TAPI_CALL_ID_T callId 
                    );

extern TAPI_RESULT_E   
TAPI_VOICE_RetrieveCall( 
                        TAPI_CALL_ID_T callId 
                        );

extern TAPI_RESULT_E   
TAPI_VOICE_MuteCall( 
                    UINT8 isMute 
                    );

extern TAPI_RESULT_E   
TAPI_VOICE_JoinCall(
                    TAPI_CALL_ID_T  activeCallId,
                    TAPI_CALL_ID_T  holdCallId 
                    );

extern TAPI_RESULT_E   
TAPI_VOICE_SplitCall( 
                     TAPI_CALL_ID_T callId 
                     );

extern TAPI_RESULT_E   
TAPI_VOICE_TransferCall(
                        TAPI_CALL_ID_T      callId,
                        TAPI_PHONE_NUMBER_A phoneNumber,
                        TAPI_CALL_ID_T*     pNewCallId 
                        );

extern TAPI_RESULT_E   
TAPI_VOICE_LinkCall(
                    TAPI_CALL_ID_T  fromCallId,
                    TAPI_CALL_ID_T  toCallId 
                    );

extern TAPI_RESULT_E   
TAPI_VOICE_SwitchCall(
                      TAPI_CALL_ID_T  toHoldCallId,
                      TAPI_CALL_ID_T  toRetrieveCallId 
                      );

extern TAPI_RESULT_E   
TAPI_VOICE_GetCallStatus(
                         TAPI_CALL_ID_T              callId,
                         TAPI_CALL_SESSION_TYPE_E    callType,
                         TAPI_CALL_STATUS_E*         pStatus 
                         );

extern TAPI_RESULT_E   
TAPI_CALL_GetCallSession(
                         TAPI_CALL_ID_T              callId,
                         TAPI_CALL_SESSION_TYPE_E    callType,
                         TAPI_CALL_SESSION_S*        pSession 
                         );

extern TAPI_RESULT_E   
TAPI_CALL_GetAllOwnCallSessions(
                                TAPI_CALL_SESSION_TABLE_S*  pSessions 
                                );

extern TAPI_RESULT_E   
TAPI_CALL_GetAllCallSessions(
                             TAPI_CALL_SESSION_TABLE_S*  pSessions 
                             );

extern TAPI_RESULT_E   
TAPI_VOICE_CheckRingStatus( void );

extern 
BOOLEAN TAPI_VOICE_IsEmergencyNumber( 
                                     TAPI_PHONE_NUMBER_A phoneNumber 
                                     );

extern 
BOOLEAN  TAPI_VOICE_IsBeginOfEmergencyNumber(
                                             TAPI_PHONE_NUMBER_A phoneNumber 
                                             );

extern TAPI_RESULT_E   
TAPI_VOICE_MuteBeep( void );

extern TAPI_RESULT_E   
TAPI_VOICE_StartRecordAudio( void );

extern TAPI_RESULT_E   
TAPI_VOICE_StopRecordAudio( void );

extern TAPI_RESULT_E   
TAPI_VOICE_MakeKodiakPTTCall( TAPI_KODIAK_PHONE_NUMBER_A phoneNumber,
                              TAPI_CALL_ID_T*            pCallID );

extern TAPI_RESULT_E   
TAPI_VOICE_DTMFStringReq( TAPI_CALL_ID_T     callId,
                          TAPI_DTMF_STRING_A dtmfString);

extern TAPI_RESULT_E   
TAPI_VOICE_DTMFStringStopReq( TAPI_CALL_ID_T     callId);

#ifdef __cplusplus
}
#endif 

#endif  

