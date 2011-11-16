

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_CALLSETUP_CLIENT_H  
#define TAPI_CALLSETUP_CLIENT_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_SETUP_General.h"
#include "TAPI_CALL_General.h"

typedef struct  _TAPI_CS_DIVERT_PARAM_S
{
    UINT8               mode;           
    TAPI_PHONE_NUMBER_A divertNumber;   
} TAPI_CS_DIVERT_PARAM_S;

extern TAPI_RESULT_E   
TAPI_CS_GetCallMeter( 
                     TAPI_CS_CALL_METER_A callMeter 
                     );

extern TAPI_RESULT_E   
TAPI_CS_ResetCallMeter( void );

extern TAPI_RESULT_E   
TAPI_CS_GetCallMeterMax( 
                        TAPI_CS_CALL_METER_A callMeterMax 
                        );

extern TAPI_RESULT_E   
TAPI_CS_SetCallMeterMax(
                        const TAPI_CS_CALL_METER_A  callMeterMax 
                        );

extern TAPI_RESULT_E   
TAPI_CS_GetPriceUnit( 
                     TAPI_CALL_PRICE_UNIT_S* pPriceUnit 
                     );

extern TAPI_RESULT_E   
TAPI_CS_SetPriceUnit( 
                     const TAPI_CALL_PRICE_UNIT_S tPriceUnit 
                     );

extern TAPI_RESULT_E   
TAPI_CS_GetAudibleTimer( 
                        UINT16* pSecond 
                        );

extern TAPI_RESULT_E   
TAPI_CS_SetAudibleTimer( 
                        UINT16 second 
                        );

extern TAPI_RESULT_E   
TAPI_CS_GetAutoAnswerTimer( 
                           UINT16* pSecond 
                           );

extern TAPI_RESULT_E   
TAPI_CS_SetAutoAnswerTimer( 
                           UINT16 second 
                           );

extern TAPI_RESULT_E   
TAPI_CS_GetRemainCredit(
                        TAPI_CS_CALL_REMAIN_CREDIT_A    remainCredit 
                        );

extern TAPI_RESULT_E   
TAPI_CS_ResetCallTime( void );

extern TAPI_RESULT_E   
TAPI_CS_GetLeftCallTime( 
                        TAPI_CALL_TIME_S* pLeftTime 
                        );

extern TAPI_RESULT_E   
TAPI_CS_GetTotalCallTime( 
                         TAPI_CALL_TIME_S* pTotalTime 
                         );

extern TAPI_RESULT_E   
TAPI_CS_GetChargeType( 
                      TAPI_CALL_CHARGE_TYPE_E* pType 
                      );

extern TAPI_RESULT_E   
TAPI_CS_SetChargeType( 
                      const TAPI_CALL_CHARGE_TYPE_E type 
                      );

extern TAPI_RESULT_E   
TAPI_CS_SetChargeDisplay(
                         const TAPI_CALL_CHARGE_STATUS_E value 
                         );

extern TAPI_RESULT_E   
TAPI_CS_GetChargeDisplay( 
                         TAPI_CALL_CHARGE_STATUS_E* pValue 
                         );

extern TAPI_RESULT_E   
TAPI_CS_DivertCallToNumber(
                           const TAPI_CALL_DIVERT_MODE_E   mode,
                           const TAPI_CS_DIVERT_TYPE_E     type,
                           const TAPI_CS_DIVERT_WHEN_E     condition,
                           const TAPI_PHONE_NUMBER_A       number,
                           const TAPI_CS_DELAY_TIME_E      time 
                           );

extern TAPI_RESULT_E   
TAPI_CS_GetDivertStatus(
                        const TAPI_CS_DIVERT_TYPE_E     divertType,
                        const TAPI_CS_DIVERT_WHEN_E     divertWhen,
                        TAPI_CALL_RSP_DIVERT_MSG_S*     pDivert 
                        );

extern TAPI_RESULT_E   
TAPI_CS_CancelAllDivert( void );

extern TAPI_RESULT_E   
TAPI_CS_CancelAllVoiceDivert( void );

extern TAPI_RESULT_E   
TAPI_CS_SetVoiceWaitingStatus( 
                              const TAPI_BOOL_STATUS_E mode 
                              );

extern TAPI_RESULT_E   
TAPI_CS_GetVoiceWaitingStatus( 
                              TAPI_BOOL_STATUS_E* pStatus 
                              );

extern TAPI_RESULT_E   
TAPI_CS_SetBarCall(
                   const TAPI_CS_BAR_TYPE_E    kind,
                   const TAPI_BOOL_STATUS_E    lock,
                   const TAPI_PASSWORD_A       password 
                   );

extern TAPI_RESULT_E   
TAPI_CS_SetBarCallService(
                          const TAPI_CS_BAR_TYPE_E    kind,
                          const UINT8                 callType,
                          const TAPI_BOOL_STATUS_E    lock,
                          const TAPI_PASSWORD_A       password 
                          );

extern TAPI_RESULT_E   
TAPI_CS_GetBarStatus(
                     const TAPI_CS_BAR_TYPE_E    kind,
                     const TAPI_CALL_TYPE_E      callType,
                     TAPI_BOOL_STATUS_E*         pState 
                     );

extern TAPI_RESULT_E   
TAPI_CS_GetBarAllBearStatus(
                            const TAPI_CS_BAR_TYPE_E        kind,
                            TAPI_CS_CALL_BAR_ALL_STATUS_A   allStates 
                            );

extern TAPI_RESULT_E   
TAPI_CS_SelectLine( 
                   const TAPI_CALL_LINE_E line 
                   );

extern TAPI_RESULT_E   
TAPI_CS_GetLine( 
                TAPI_CALL_LINE_E* pLine 
                );

extern TAPI_RESULT_E   
TAPI_CS_GetAutoRedialStatus( 
                            TAPI_BOOL_STATUS_E* pStatus 
                            );

extern TAPI_RESULT_E   
TAPI_CS_SetAutoRedialStatus( 
                            const TAPI_BOOL_STATUS_E status 
                            );

extern TAPI_RESULT_E  
TAPI_CS_GetPendingCallDropToneStatus(
                                     TAPI_BOOL_STATUS_E*     pStatus 
                                     );

extern TAPI_RESULT_E   
TAPI_CS_SetPendingCallDropToneStatus(
                                     const TAPI_BOOL_STATUS_E    status 
                                     );

extern TAPI_RESULT_E   
TAPI_CS_ShowIdToPeer( void );

extern TAPI_RESULT_E   
TAPI_CS_HideIdToPeer( void );

extern TAPI_RESULT_E   
TAPI_CS_SetRestrictId( 
                      const TAPI_CALL_RESTRICT_ID_E state 
                      );

extern TAPI_RESULT_E   
TAPI_CS_GetRestrictId(
                    TAPI_CS_RESTRICT_ID_PARAM_S*    pRestrictId 
                    );

extern TAPI_RESULT_E   
TAPI_CS_GetLastCallCost( 
                        UINT8* pValue 
                        );

extern TAPI_RESULT_E   
TAPI_CS_SetCallMode( 
                    const UINT8 mode 
                    );

extern TAPI_RESULT_E   
TAPI_CS_GetCallMode( 
                    UINT8* pMode 
                    );

extern TAPI_RESULT_E   
TAPI_CS_SetRestrictNextCallID(
                              TAPI_CALL_RESTRICT_NEXT_ID_E    status 
                              );

extern TAPI_RESULT_E   
TAPI_CS_GetRestrictNextCallID(
                              TAPI_CALL_RESTRICT_NEXT_ID_E*   pStatus 
                              );

extern TAPI_RESULT_E   
TAPI_CS_SetDtmfToneType( 
                        TAPI_CALL_DTMF_TONE_TYPE_E type 
                        );

extern TAPI_RESULT_E   
TAPI_CS_GetDtmfToneType( 
                        TAPI_CALL_DTMF_TONE_TYPE_E* pType 
                        );

extern TAPI_RESULT_E
TAPI_CS_GetDivertIconStatus(
                           TAPI_CALLSET_DIVERT_ICON_E *pIconStatus
                            );

#ifdef __cplusplus
}

#endif
#endif 
