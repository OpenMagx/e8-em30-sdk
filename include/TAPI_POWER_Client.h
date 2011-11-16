

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_POWER_CLIENT_H 
#define TAPI_POWER_CLIENT_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_SETUP_General.h"

extern TAPI_RESULT_E   
TAPI_POWER_NotifyBpPowerOff(
                            const TAPI_POWER_OFF_CAUSE_E    reason 
                            );

extern TAPI_RESULT_E   
TAPI_POWER_EnableAuto( 
                      const TAPI_TIME_DATE_S autoTime 
                      );

extern TAPI_RESULT_E   
TAPI_POWER_DisableAuto( 
                       void 
                       );

extern TAPI_RESULT_E   
TAPI_POWER_NotifySuspend( 
                         void 
                         );

extern TAPI_RESULT_E   
TAPI_POWER_PowerDownPhone( 
                          void 
                          );

extern TAPI_RESULT_E   
TAPI_POWER_GetMode( 
                   TAPI_POWER_ON_MODE_E* pMode 
                   );

#ifdef __cplusplus
}
#endif 

#endif  

