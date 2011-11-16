

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_ACCE_CLIENT_H  
#define TAPI_ACCE_CLIENT_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_SETUP_General.h"

#define TAPI_BP_VERSION_STRING_LENGTH 48

#define TAPI_MODEL_ID_STRING_LENGTH 48

typedef UINT8   TAPI_VERSION_A[TAPI_BP_VERSION_STRING_LENGTH];

typedef UINT8   TAPI_MODEL_ID_A[TAPI_MODEL_ID_STRING_LENGTH];

typedef struct  _TAPI_BP_VERSION_INFO_S
{
    TAPI_VERSION_A  bpVersion;
    TAPI_VERSION_A  bpFlexVersion;
    TAPI_VERSION_A  dspVersion;
    TAPI_VERSION_A  technology;
} TAPI_BP_VERSION_INFO_S;

typedef struct  _TAPI_AP_VERSION_INFO_S
{
    TAPI_VERSION_A version;
} TAPI_AP_VERSION_INFO_S;

extern TAPI_RESULT_E   
TAPI_ACCE_SetCurrentTime( 
                         const TAPI_TIME_DATE_S currentTime 
                         );

extern TAPI_RESULT_E  
TAPI_ACCE_SetRfMode( 
                    const TAPI_RF_STATUS_E rfStatus 
                    );

extern TAPI_RESULT_E   
TAPI_ACCE_SetEmuDeviceStatus(
                             const TAPI_EMU_DEVICE_STATUS_E  emuStatus 
                             );

extern TAPI_RESULT_E 
TAPI_ACCE_GetRfMode( 
                    TAPI_RF_STATUS_E* pRfStatus 
                    );

extern TAPI_RESULT_E   
TAPI_ACCE_MasterClear( void );

extern TAPI_RESULT_E   
TAPI_ACCE_MasterReset( void );

extern TAPI_RESULT_E   
TAPI_ACCE_GetImei( 
                  TAPI_IMEI_NUMBER_A imei 
                  ); 

TAPI_RESULT_E TAPI_ACCE_GetImeiSv ( 
                                    TAPI_IMEI_SV_NUMBER_A   imeisv
                                  );

extern TAPI_RESULT_E   
TAPI_ACCE_GetImsi( 
                  TAPI_IMSI_NUMBER_A imsi 
                  );

extern TAPI_RESULT_E   
TAPI_ACCE_GetFactorySerialNo(
                             TAPI_FACTORY_NUMBER_A   factorySerialNo 
                             );

extern TAPI_RESULT_E   
TAPI_ACCE_SetSpeakerVolume( 
                           const TAPI_SPEAKER_VOLUME_E  volume 
                           );

extern TAPI_RESULT_E   
TAPI_ACCE_GetBearerService(
                           TAPI_CALL_DATA_CBST_PARAM_S*    pBearer 
                           );

extern TAPI_RESULT_E   
TAPI_ACCE_NotifyAudioAccessoryStatus( 
                                     const UINT16 state 
                                     );

extern TAPI_RESULT_E   
TAPI_ACCE_GetSimCardStatus( 
                           TAPI_SIM_STATUS_E* pSimCardStatus 
                           );

extern TAPI_RESULT_E   
TAPI_ACCE_GetSubsidyStatus(
                           TAPI_SECURITY_SUBSIDY_STATUS_E*     pSubsidyStatus 
                           );

extern TAPI_RESULT_E   
TAPI_ACCE_GetSyncStatus( 
                        BOOLEAN* bSyncFinished 
                        );

extern TAPI_RESULT_E   
TAPI_ACCE_GetServiceTone( 
                         TAPI_BOOL_STATUS_E* pServiceTone 
                         );

extern TAPI_RESULT_E   
TAPI_ACCE_GetSiginalQuality(
                            TAPI_SIGNAL_QUALITY_S*  pSignalQuality 
                            );

extern TAPI_RESULT_E   
TAPI_ACCE_GetServiceAvailability(
                                 TAPI_BOOL_STATUS_E*     pServiceAvail 
                                 );

extern TAPI_RESULT_E   
TAPI_ACCE_SetServiceTone( 
                         const TAPI_BOOL_STATUS_E serviceTone 
                         );

extern TAPI_RESULT_E   
TAPI_ACCE_SetUsbCableStatus(
                            const TAPI_USB_CABLE_STATUS_E   usbStatus,
                            const TAPI_USB_CHARGING_E       usbCharging 
                            );

extern TAPI_RESULT_E   
TAPI_ACCE_SendMdai( 
                   INT16 parameter 
                   );

extern TAPI_RESULT_E   
TAPI_ACCE_GetBpVersionInfo( 
                           TAPI_BP_VERSION_INFO_S* pVersion 
                           );

extern TAPI_RESULT_E   
TAPI_ACCE_GetApVersionInfo( 
                           TAPI_AP_VERSION_INFO_S* pVersion 
                           );

extern TAPI_RESULT_E   
TAPI_ACCE_GetBpVersion( 
                       TAPI_VERSION_A bpVersion 
                       );

extern TAPI_RESULT_E   
TAPI_ACCE_GetModelId( 
                     TAPI_MODEL_ID_A modelId 
                     );

extern TAPI_RESULT_E
TAPI_ACCE_GetHardwareVersion(
                             TAPI_HARDWARE_VERSION_A  hardwareversion 
                             );

#ifdef __cplusplus
}

#endif
#endif    
