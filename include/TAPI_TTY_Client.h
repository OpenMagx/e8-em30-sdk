

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_TTY_CLIENT_H
#define TAPI_TTY_CLIENT_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_AppMsgId.h"
#include "TAPI_Result.h"
#include "TAPI_CALL_General.h"
#include "TAPI_VOICE_AppData.h"

extern TAPI_RESULT_E   
TAPI_TTY_GetTtyMode( 
                    TAPI_TTY_MODE_E* pMode 
                    );

extern TAPI_RESULT_E   
TAPI_TTY_SetTtyMode( 
                    TAPI_TTY_MODE_E mode 
                    );

extern TAPI_RESULT_E   
TAPI_TTY_SetCurrentCallTtyMode( 
                               TAPI_TTY_MODE_E mode 
                               );

extern TAPI_RESULT_E   
TAPI_TTY_GetCtmBit( 
                   TAPI_BOOL_STATUS_E* pOnOff 
                   );

extern TAPI_RESULT_E   
TAPI_TTY_SetHeadsetStatus( 
                          UINT8 status 
                          );

#ifdef __cplusplus
}
#endif 

#endif  

