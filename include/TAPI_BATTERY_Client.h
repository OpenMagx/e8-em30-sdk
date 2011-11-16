

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_BATTERY_CLIENT_H 
#define TAPI_BATTERY_CLIENT_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_SETUP_General.h"

extern TAPI_RESULT_E   
TAPI_BATTERY_GetMode( 
                     TAPI_BATTERY_MODE_E* pMode 
                     );

extern TAPI_RESULT_E   
TAPI_BATTERY_SetMode( 
                     const TAPI_BATTERY_MODE_E mode 
                     );

extern TAPI_RESULT_E   
TAPI_BATTERY_GetBatteryChargeInfo( 
                                  TAPI_BATTERY_INFO_S* pInfo 
                                  );

extern TAPI_RESULT_E   
TAPI_BATTERY_GetCapacity( 
                         UINT8* pValue 
                         );

extern TAPI_RESULT_E   
TAPI_BATTERY_GetStatus( 
                       TAPI_BATTERY_STATUS_E* pStatus 
                       );

extern TAPI_RESULT_E   
TAPI_BATTERY_GetChargerConnectionStatus(
                                        TAPI_CHARGER_USB_STATUS_S*  pStatus  
                                        );

extern TAPI_RESULT_E   
TAPI_BATTERY_GetBatteryEpromData(
                                 TAPI_BATTERY_TYPE_E*            pType,
                                 TAPI_BATTERY_SERIAL_NUMBER_A    serialNumber,
                                 TAPI_BATTERY_EPROM_DATA_A       romData 
                                 );

#ifdef __cplusplus
}

#endif
#endif 
