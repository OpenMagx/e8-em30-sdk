

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_BLUETOOTH_CLIENT_H 
#define TAPI_BLUETOOTH_CLIENT_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_SETUP_General.h"

extern TAPI_RESULT_E   
TAPI_BLUETOOTH_PowerOn( void );

extern TAPI_RESULT_E   
TAPI_BLUETOOTH_PowerOff( void );

extern TAPI_RESULT_E   
TAPI_BLUETOOTH_GetAddress( 
                          TAPI_BLUETOOTH_ADDRESS_A btAddress 
                          );

extern TAPI_RESULT_E   
TAPI_BLUETOOTH_MakeDtmfTone(
                            UINT8   mode,
                            UINT8   tone 
                            );

extern TAPI_RESULT_E   
TAPI_BLUETOOTH_GetFreqOffset( 
                             INT32* pBluetoothFreqOffset 
                             );

extern TAPI_RESULT_E   
TAPI_BLUETOOTH_DisableNoiseReduction( 
                                     BOOLEAN bDisable 
                                     );

#ifdef __cplusplus
}
#endif 

#endif  

