

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_LOG_CLIENT_H 
#define TAPI_LOG_CLIENT_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "EZX_TypeDefs.h"
#include "TAPI_General.h"
#include "TAPI_SETUP_General.h"

extern TAPI_RESULT_E   
TAPI_LOG_GetLastCallTime( 
                         TAPI_CALL_TIME_S* pLastTime 
                         );

extern TAPI_RESULT_E   
TAPI_LOG_GetDialedCallsTime( 
                            TAPI_CALL_TIME_S* pDialedTime 
                            );

extern TAPI_RESULT_E   
TAPI_LOG_GetAnsweredCallsTime( 
                              TAPI_CALL_TIME_S* pAnsweredTime 
                              );

extern TAPI_RESULT_E   
TAPI_LOG_GetLifetimeCallsTime( 
                              TAPI_CALL_TIME_S* pLifetimeTime 
                              );

extern TAPI_RESULT_E   
TAPI_LOG_GetDialedCallsCost( 
                            TAPI_LOG_CCM_STRING_A ccmCost 
                            );

extern TAPI_RESULT_E   
TAPI_LOG_GetAnsweredCallsCost( 
                              TAPI_LOG_CCM_STRING_A ccmCost 
                              );

extern TAPI_RESULT_E   
TAPI_LOG_GetAllCallsCost( 
                         TAPI_LOG_CCM_STRING_A ccmCost 
                         );

extern TAPI_RESULT_E   
TAPI_LOG_GetLastDeposit( 
                        TAPI_LOG_CCM_STRING_A ccmCost 
                        );

extern TAPI_RESULT_E   
TAPI_LOG_GetDepositExpirationDate( 
                                  TAPI_TIME_DATE_S* pDate 
                                  );

extern TAPI_RESULT_E   
TAPI_LOG_ResetAll( 
                  void 
                  );

extern TAPI_RESULT_E   
TAPI_LOG_ResetAllCallsCost( 
                           void 
                           );

extern TAPI_RESULT_E  
TAPI_LOG_ResetDialedCallsCost( 
                              void 
                              );

extern TAPI_RESULT_E   
TAPI_LOG_ResetAnsweredCallsCost( 
                                void 
                                );

extern TAPI_RESULT_E   
TAPI_LOG_GetRecentDataSessionTime(
                                  TAPI_LOG_DATA_SESSION_TYPE_E    sessionType,
                                  TAPI_CALL_TIME_S*               pSessionTime 
                                  );

extern TAPI_RESULT_E   
TAPI_LOG_GetAllDataSessionsTime(
                                TAPI_LOG_DATA_SESSION_TYPE_E    sessionType,
                                TAPI_CALL_TIME_S*               pSessionTime 
                                );

extern TAPI_RESULT_E   
TAPI_LOG_GetRecentDataSessionVolume(
                                    TAPI_LOG_DATA_SESSION_TYPE_E    sessionType,
                                    UINT32*                         pSendVolume,
                                    UINT32*                         pReceiveVolume 
                                    );

extern TAPI_RESULT_E   
TAPI_LOG_GetAllDataSessionsVolume(
                                  TAPI_LOG_DATA_SESSION_TYPE_E    sessionType,
                                  UINT32*                         pSendVolume,
                                  UINT32*                         pReceiveVolume 
                                  );

extern TAPI_RESULT_E   
TAPI_LOG_ResetDialedCallsTime( 
                              void 
                              );

extern TAPI_RESULT_E   
TAPI_LOG_ResetAnsweredCallsTime( 
                                void 
                                );

extern TAPI_RESULT_E   
TAPI_LOG_ResetDataSessionsTime( 
                               void 
                               );

extern TAPI_RESULT_E   
TAPI_LOG_ResetDataSessionsVolume( 
                                 void 
                                 );

extern TAPI_RESULT_E 
TAPI_LOG_GetOffModeLogger(
                          void
                          );

#ifdef __cplusplus
}
#endif 

#endif  

