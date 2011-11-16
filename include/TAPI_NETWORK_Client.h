

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_NETWORK_CLIENT_H 
#define TAPI_NETWORK_CLIENT_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_SETUP_General.h"
#include "TAPI_GPRS_AppData.h"
#include "TAPI_ACCE_Client.h"
#include "TAPI_UMAN_Client.h"

typedef enum    _TAPI_NETWORK_PLMN_LIST_TYPE_E
{
    TAPI_NETWORK_PLMN_LIST_TYPE_PLMNSEL,         
    TAPI_NETWORK_PLMN_LIST_TYPE_PLMNWACT,
    TAPI_NETWORK_PLMN_LIST_TYPE_OPLMNWACT,
    TAPI_NETWORK_PLMN_LIST_TYPE_HPLMNWACT
} TAPI_NETWORK_PLMN_LIST_TYPE_E;

typedef enum    _TAPI_NETWORK_RADIO_SETTING_ALWON_VALUE_E
{
    TAPI_NETWORK_RADIO_SETTING_ALWON_VALUE_HE_OFF_VS_OFF_VD_OFF = 0,
    TAPI_NETWORK_RADIO_SETTING_ALWON_VALUE_HE_OFF_VS_OFF_VD_ON  = 1,
    TAPI_NETWORK_RADIO_SETTING_ALWON_VALUE_HE_OFF_VS_ON_VD_OFF  = 2,
    TAPI_NETWORK_RADIO_SETTING_ALWON_VALUE_HE_OFF_VS_ON_VD_ON   = 3,
    TAPI_NETWORK_RADIO_SETTING_ALWON_VALUE_HE_ON_VS_OFF_VD_OFF  = 4,
    TAPI_NETWORK_RADIO_SETTING_ALWON_VALUE_HE_ON_VS_OFF_VD_ON   = 5,
    TAPI_NETWORK_RADIO_SETTING_ALWON_VALUE_HE_ON_VS_ON_VD_OFF   = 6,
    TAPI_NETWORK_RADIO_SETTING_ALWON_VALUE_HE_ON_VS_ON_VD_ON    = 7,
    TAPI_NETWORK_RADIO_SETTING_ALWON_VALUE_UNKNOWN              = 255
} TAPI_NETWORK_RADIO_SETTING_ALWON_VALUE_E;

typedef enum _TAPI_NETWORK_RADIO_SETTINGS_FEATURE_E
{
   TAPI_NETWORK_RADIO_SETTINGS_FEATURE_OFF     = 0,
   TAPI_NETWORK_RADIO_SETTINGS_FEATURE_ON      = 1,
   TAPI_NETWORK_RADIO_SETTINGS_FEATURE_UNKNOWN = 255
} TAPI_NETWORK_RADIO_SETTINGS_FEATURE_E;

typedef UINT8   TAPI_NETWORK_ID_STRING_A[TAPI_NETWORK_MAX_OPERATOR_ID_LENGTH];

typedef UINT8   TAPI_NETWORK_PLMN_VERSION_A[TAPI_NETWORK_MAX_PLMN_VERSION_LENGTH];

typedef struct  _TAPI_PLMN_INFO_STRUCT_S
{
    TAPI_NETWORK_ID_STRING_A    mccMnc;     

    TAPI_NETWORK_PLMN_NAME_A    longName;   
    TAPI_NETWORK_PLMN_NAME_A    shortName;  
    TAPI_UMAN_SERVICE_ZONE_PARAMS_S service_zone; 
} TAPI_PLMN_INFO_STRUCT_S;

typedef struct  _TAPI_NETWORK_PREFER_PLMN_S
{
    TAPI_NETWORK_INDEX_T        priority;   
    TAPI_NETWORK_ID_STRING_A    mccMnc;     

    TAPI_NETWORK_ACCESS_TECHNOLOGY_S   access_technology;  
    TAPI_NETWORK_PLMN_NAME_A    name;
} TAPI_NETWORK_PREFER_PLMN_S;

typedef struct  _TAPI_NETWORK_PREFERRED_S
{
    TAPI_NETWORK_INDEX_T        totalNum;
    TAPI_NETWORK_PREFER_PLMN_S  networks[TAPI_NETWORK_MAX_PREFERED_NUMBER];
} TAPI_NETWORK_PREFERRED_S;

typedef struct  _TAPI_NETWORK_MCC_MNC_ID_S
{
    UINT16  mcc;    
    UINT16  mnc;    
} TAPI_NETWORK_MCC_MNC_ID_S;

typedef struct _TAPI_NETWORK_PLMN_VERSION_S
{
    TAPI_NETWORK_PLMN_VERSION_A version;
} TAPI_NETWORK_PLMN_VERSION_S;

typedef struct _TAPI_NETWORK_SUPPORTED_PLMN_LISTS_S
{
    TAPI_BOOL_STATUS_E plmnsel_list;
    TAPI_BOOL_STATUS_E user_controlled_list;
    TAPI_BOOL_STATUS_E operator_controlled_list;
    TAPI_BOOL_STATUS_E hplmn_list;
} TAPI_NETWORK_SUPPORTED_PLMN_LISTS_S;

typedef struct _TAPI_NETWORK_OTAP_RADIO_SETTINGS_S
{
    TAPI_NETWORK_RADIO_SETTING_ALWON_VALUE_E always_on_pdp;
    TAPI_NETWORK_RADIO_SETTINGS_FEATURE_E    secondary_pdp;
    TAPI_NETWORK_RADIO_SETTINGS_FEATURE_E    ciphering_rf3;
    TAPI_NETWORK_RADIO_SETTINGS_FEATURE_E    compressed_mode_rf4;
    TAPI_NETWORK_RADIO_SETTINGS_FEATURE_E    compressed_mode_rf5;
    TAPI_BOOL_STATUS_E                       apply_immediately;
} TAPI_NETWORK_OTAP_RADIO_SETTINGS_S;

extern TAPI_RESULT_E   
TAPI_NETWORK_GetServiceProviderName(
                                    TAPI_SERVICE_PROVIDER_NAME_S*   pServiceName 
                                    );

extern TAPI_RESULT_E   
TAPI_NETWORK_GetSearchMode( 
                           TAPI_NETWORK_SEARCH_MODE_E* pMode 
                           );

extern TAPI_RESULT_E   
TAPI_NETWORK_SetSearchMode( 
                           const TAPI_NETWORK_SEARCH_MODE_E    mode 
                           );

extern TAPI_RESULT_E   
TAPI_NETWORK_GetSearchFrequency(
                                TAPI_NETWORK_SEARCH_SPEED_E*    pFrequency 
                                );

extern TAPI_RESULT_E   
TAPI_NETWORK_SetSearchFrequency(
                                const TAPI_NETWORK_SEARCH_SPEED_E   frequency 
                                );

extern TAPI_RESULT_E   
TAPI_NETWORK_SetPreferredOperator(
                                  const TAPI_NETWORK_INDEX_T          priority,
                                  const TAPI_NETWORK_OPERATOR_ID_A    networkId 
                                  );

extern TAPI_RESULT_E   
TAPI_NETWORK_DeleteSelectedOperator(
                                    const TAPI_NETWORK_INDEX_T  priority 
                                    );

extern TAPI_RESULT_E   
TAPI_NETWORK_GetTotalPreferredOperatorNumber(
                                             TAPI_NETWORK_INDEX_T*   pTotalNumber 
                                             );

extern TAPI_RESULT_E  
TAPI_NETWORK_SetBand( 
                     const TAPI_NETWORK_BAND_E band 
                     );

extern TAPI_RESULT_E   
TAPI_NETWORK_GetBand( 
                     TAPI_NETWORK_BAND_E* pBand 
                     );

extern TAPI_RESULT_E   
TAPI_NETWORK_GetCurrentNetworkId(
                                 TAPI_NETWORK_MCC_DIGITS_A   pMccStr,
                                 TAPI_NETWORK_MNC_DIGITS_A   pMncStr 
                                 );

extern TAPI_RESULT_E  
TAPI_NETWORK_CancelGetAvailableNetworks( 
                                        void 
                                        );

extern TAPI_RESULT_E   
TAPI_NETWORK_FindNewNetworks( 
                             void 
                             );

extern TAPI_RESULT_E   
TAPI_NETWORK_GetAvailableNetwork( 
                                 void 
                                 );

extern TAPI_RESULT_E   
TAPI_NETWORK_GetPlmnCount( 
                          UINT16* pCount 
                          );

extern TAPI_RESULT_E   
TAPI_NETWORK_GetPlmnVersion( 
                            TAPI_NETWORK_PLMN_VERSION_S *pPlmnVer
                            );

extern TAPI_RESULT_E   
TAPI_NETWORK_GetPlmnList( 
                         TAPI_NETWORK_PLMN_INFO_S* pPlmnInfo 
                         );

extern TAPI_RESULT_E   
TAPI_NETWORK_RegisterOperator(
                              TAPI_NETWORK_OPERATOR_ID_A  networkId 
                              );

extern TAPI_RESULT_E   
TAPI_NETWORK_GetLocalAreaId(
                            TAPI_NETWORK_LOCAL_AREA_ID_S*   pLocalId 
                            );

extern TAPI_RESULT_E   
TAPI_NETWORK_GetCurrentPlmnName(
                                const TAPI_NETWORK_ID_STRING_A  mccMnc,
                                const BOOLEAN                   isNativeLanguage,
                                TAPI_PLMN_INFO_STRUCT_S*        pInfo 
                                );

extern TAPI_RESULT_E   
TAPI_NETWORK_GetChosenPlmnName(
                               const TAPI_NETWORK_ID_STRING_A  mccMnc,
                               const BOOLEAN                   isNativeLanguage,
                               TAPI_PLMN_INFO_STRUCT_S*        pInfo 
                               );

extern TAPI_RESULT_E   
TAPI_NETWORK_GetPreferredOperator(
                                  TAPI_NETWORK_PREFERRED_S*   pOperators,
                                  const BOOLEAN               isNativeLanguage 
                                  );

extern TAPI_RESULT_E   
TAPI_NETWORK_GetOperatorNameList(
                                 TAPI_PLMN_INFO_STRUCT_S*    pInfo,
                                 const UINT16                totalNum,
                                 const BOOLEAN               isNativeLanguage 
                                 );

extern TAPI_RESULT_E   
TAPI_NETWORK_SetNitzStatus( 
                           const TAPI_BOOL_STATUS_E status 
                           );

extern TAPI_RESULT_E   
TAPI_NETWORK_GetNitzStatus( 
                           TAPI_BOOL_STATUS_E* pStatus 
                           );

extern TAPI_RESULT_E   
TAPI_NETWORK_GetNetworkTime(
                            TAPI_NETWORK_NITZ_TIME_S*   pNitzTime 
                            );

extern TAPI_RESULT_E   
TAPI_NETWORK_RescanNetwork( 
                           void 
                           );

extern TAPI_RESULT_E   
TAPI_NETWORK_SetCreg( 
                     UINT16 kind 
                     );

extern TAPI_RESULT_E   
TAPI_NETWORK_GetCreg(
                     TAPI_GET_NETWORK_REG_STATUS_S*  pRegStatus 
                     );

extern TAPI_RESULT_E   
TAPI_NETWORK_SyncGetAvailableNetwork(
                                     TAPI_NETWORK_NOTIFY_PREFERED_LIST_MSG_S*    pNameList 
                                     );

extern TAPI_RESULT_E   
TAPI_NETWORK_GetMflex(
                      TAPI_VERSION_A              bpFlexVersion,
                      TAPI_NETWORK_PLMN_NAME_A    carrierName,
                      TAPI_NETWORK_MCC_DIGITS_A   pMccStr 
                      );

extern TAPI_RESULT_E 
TAPI_NETWORK_CancelFindNewNetworks( 
                                   void 
                                   );

extern TAPI_RESULT_E 
TAPI_NETWORK_DeleteAllStoredNITZName( 
                                     void 
                                     );

extern TAPI_RESULT_E
TAPI_NETWORK_GetRegStates(
                          TAPI_NETWORK_ROAM_E *roam_state,
                          TAPI_NETWORK_STATUS_E *service_state
                          );

extern TAPI_RESULT_E 
TAPI_NETWORK_GetPlmnListFromSim ( 
                                 TAPI_NETWORK_PLMN_LIST_TYPE_E list_type,
                                 TAPI_NETWORK_PREFERRED_S* plmn_list 
                                 );

extern TAPI_RESULT_E 
TAPI_NETWORK_AddPlmn ( 
                      TAPI_NETWORK_PLMN_LIST_TYPE_E list_type,
                      TAPI_NETWORK_PLMN_S plmn 
                      );

extern TAPI_RESULT_E 
TAPI_NETWORK_UpdatePlmn ( 
                         TAPI_NETWORK_PLMN_LIST_TYPE_E list_type,
                         TAPI_NETWORK_PLMN_S plmn 
                         );

extern TAPI_RESULT_E 
TAPI_NETWORK_DeletePlmn( 
                        TAPI_NETWORK_PLMN_LIST_TYPE_E list_type,
                        const TAPI_NETWORK_INDEX_T index
                        );

extern TAPI_RESULT_E 
TAPI_NETWORK_GetMaxNumberListEntries( 
                                     TAPI_NETWORK_PLMN_LIST_TYPE_E list_type,
                                     TAPI_NETWORK_INDEX_T* pMaxNumber 
                                     );

extern TAPI_RESULT_E 
TAPI_NETWORK_GetSupportedPlmnLists ( 
                                    TAPI_NETWORK_SUPPORTED_PLMN_LISTS_S* lists 
                                    );

extern TAPI_RESULT_E 
TAPI_NETWORK_GetMAType ( 
                        TAPI_NETWORK_MA_TYPE_E *maType 
                        );

extern TAPI_RESULT_E   
TAPI_NETWORK_SetRadioSettings( 
                           const TAPI_NETWORK_OTAP_RADIO_SETTINGS_S* radio_settings 
                           );

#ifdef __cplusplus
}
#endif 

#endif  

