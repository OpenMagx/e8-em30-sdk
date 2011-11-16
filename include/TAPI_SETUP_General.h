

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_SETUP_GENERAL_H
#define TAPI_SETUP_GENERAL_H

#ifdef __cplusplus 
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include "TAPI_AppMsgId.h"
#include "TAPI_Result.h"
#include "TAPI_General.h"
#include "TAPI_AppMsg.h"
#include "TAPI_CLIENT_Func.h"
#include "TAPI_General.h"

#define BP_VERSION_FILE      "/tmp/VersionInfo"

#define TAPI_PASSWORD_LENGTH                   20

#define TAPI_NETWORK_MAX_SERVICE_NAME_LENGTH   24

#define TAPI_NETWORK_MAX_PLMN_VERSION_LENGTH   48

#define TAPI_NETWORK_MAX_PREFERED_NUMBER       100

#define TAPI_MAX_MCC_DIGITS_LENGTH             4

#define TAPI_MAX_MNC_DIGITS_LENGTH             4

#define TAPI_NETWORK_MAX_OPERATOR_ID_LENGTH    12

#define TAPI_MAX_CALL_METER_LENGTH             100

#define TAPI_MAX_CREDIT_LENGTH                 100

#define TAPI_MAX_PLMN_NAME_BYTE_LENGTH         24

#define TAPI_BLUETOOTH_ADDRESS_LENGTH          6

#define TAPI_NETWORK_SUB_ADDRESS_LENGTH        23

#define TAPI_LOG_MAX_CCM_STRING_LENGTH         50

#define TAPI_NETWORK_IN_ROAMING_EV      TAPI_NETWORK_IN_HOME_ROAMING_EV

#define TAPI_CALL_TYPE_COUNT  7

#define TAPI_BATTERY_VALUE_UNKNOWN_EV 255

typedef enum    _TAPI_USB_CABLE_STATUS_E
{
    TAPI_USB_CABLE_STATUS_NO_EV             = 0,    
    TAPI_USB_CABLE_STATUS_NETMONITOR_EV,            
    TAPI_USB_CABLE_STATUS_ACM_CFG1_MODEM_EV,        
    TAPI_USB_CABLE_STATUS_CFG11_EV,                 
    TAPI_USB_CABLE_STATUS_CFG16_EV,                 
    TAPI_USB_CABLE_STATUS_DSP_LOGGER_EV,            
    TAPI_USB_CABLE_STATUS_INVALID_EV        = 255
} TAPI_USB_CABLE_STATUS_E;

typedef enum    _TAPI_USB_CHARGING_E
{
    TAPI_USB_CHARGING_NOT_ALLOWED_EV        = 0,    
    TAPI_USB_CHARGING_ABLE_PROVIDE_500MA_EV,        
    TAPI_USB_CHARGING_INVALID_EV            = 255
} TAPI_USB_CHARGING_E;

enum _TAPI_SPEAKER_VOLUME_E
{
    TAPI_SPEAKER_VOLUME_0_EV,
    TAPI_SPEAKER_VOLUME_1_EV,
    TAPI_SPEAKER_VOLUME_2_EV,
    TAPI_SPEAKER_VOLUME_3_EV,
    TAPI_SPEAKER_VOLUME_4_EV,
    TAPI_SPEAKER_VOLUME_5_EV,
    TAPI_SPEAKER_VOLUME_6_EV,
    TAPI_SPEAKER_VOLUME_7_EV,
};
typedef INT32   TAPI_SPEAKER_VOLUME_E;

typedef enum    _TAPI_NETWORK_SEARCH_MODE_E
{
    TAPI_NETWORK_SEARCH_MODE_AUTOMATIC_EV,          
    TAPI_NETWORK_SEARCH_MODE_MANUAL_EV,             
    TAPI_NETWORK_SEARCH_MODE_DEREGISTER_EV,         
    TAPI_NETWORK_SEARCH_MODE_SETONLY_EV,            
    TAPI_NETWORK_SEARCH_MODE_REGISTER_EV            
} TAPI_NETWORK_SEARCH_MODE_E;

typedef enum    _TAPI_NETWORK_SEARCH_SPEED_E
{
    TAPI_NETWORK_SEARCH_SPEED_SLOW_EV,      
    TAPI_NETWORK_SEARCH_SPEED_MEDIUM_EV,    
    TAPI_NETWORK_SEARCH_SPEED_FAST_EV,      
    TAPI_NETWORK_SEARCH_SPEED_CONTINOUS_EV  
} TAPI_NETWORK_SEARCH_SPEED_E;

typedef enum    _TAPI_NETWORK_BAND_E
{
    TAPI_NETWORK_BAND_1800_EV,
    TAPI_NETWORK_BAND_900_EV,
    TAPI_NETWORK_BAND_1900_EV,
    TAPI_NETWORK_BAND_900_1800_EV,
    TAPI_NETWORK_BAND_850_1900_EV,
    TAPI_NETWORK_BAND_850_EV,
    TAPI_NETWORK_BAND_AUTOSWITCH_EV,
    TAPI_NETWORK_BAND_UTRA_1900_EV,
    TAPI_NETWORK_BAND_UTRA_2100_EV,
    TAPI_NETWORK_BAND_UTRA_850_1900_EV,
    TAPI_NETWORK_BAND_AUTO_NORTH_AMERICA_EV,
    TAPI_NETWORK_BAND_AUTO_EUROPE_EV,
    TAPI_NETWORK_BAND_JAPAN_EV,
    TAPI_NETWORK_BAND_GSM_GPRS_FIRST_THEN_UMTS_EV,
    TAPI_NETWORK_BAND_UMTS_FIRST_GSM_GPRS_EV,
    TAPI_NETWORK_BAND_GSM_ONLY_AUTOMATIC_EV,
    TAPI_NETWORK_BAND_WCDMA_ONLY_AUTOMATIC_EV,
    TAPI_NETWORK_BAND_MAX_EV
} TAPI_NETWORK_BAND_E;

typedef enum    _TAPI_NETWORK_SIGNAL_E
{
    TAPI_NETWORK_SIGNAL_LEVEL_0_EV          = 0,
    TAPI_NETWORK_SIGNAL_LEVEL_1_EV,
    TAPI_NETWORK_SIGNAL_LEVEL_2_EV,
    TAPI_NETWORK_SIGNAL_LEVEL_3_EV,
    TAPI_NETWORK_SIGNAL_LEVEL_4_EV,
    TAPI_NETWORK_SIGNAL_LEVEL_5_EV
} TAPI_NETWORK_SIGNAL_E;

typedef enum    _TAPI_NETWORK_ROAM_E
{
    TAPI_NETWORK_IN_HOME_EV                 = 0,    
    TAPI_NETWORK_IN_HOME_ROAMING_EV,                
    TAPI_NETWORK_OVERSEAS_ROAMING_EV                
} TAPI_NETWORK_ROAM_E;

enum _TAPI_CALL_TYPE_E
{
    TAPI_CALL_TYPE_VOICE_EV                 = 1,            
    TAPI_CALL_TYPE_DATA_EV                  = 2,            
    TAPI_CALL_TYPE_FAX_EV                   = 4,            
    TAPI_CALL_TYPE_SHORT_MESS_EV            = 8,            
    TAPI_CALL_TYPE_DATA_CIRCUIT_SYNC_EV     = 16,           
    TAPI_CALL_TYPE_DATA_CIRCUIT_EV          = 32,           
    TAPI_CALL_TYPE_VIDEO_EV                 = 64             
};
typedef UINT8   TAPI_CALL_TYPE_E;

enum _TAPI_SECURITY_PIN2_STATUS_E
{
    TAPI_SECURITY_PIN2_STAT_UNLOCKED_EV             = 0,    
    TAPI_SECURITY_PIN2_STAT_LOCKED_EV,                      
    TAPI_SECURITY_PIN2_STAT_PERMANENTLY_LOCKED_EV           
};
typedef UINT8   TAPI_SECURITY_PIN2_STATUS_E;

enum _TAPI_SECURITY_SUBSIDY_UNLOCK_E
{
    TAPI_SECURITY_SUBSIDY_UNLOCK_OK_EV              = 0,    
    TAPI_SECURITY_SUBSIDY_UNLOCK_ENTER_WRONG_CODE_EV,       
    TAPI_SECURITY_SUBSIDY_UNLOCK_WAIT_EV    
};
typedef UINT8   TAPI_SECURITY_SUBSIDY_UNLOCK_E;

enum _TAPI_SECURITY_SUBSIDY_AIRTEL_LOCKID_STATUS_E
{
    TAPI_SUBSIDY_AIRTEL_LOCKID_STATUS_ACCESS_ERROR_EV = 0, 
    TAPI_SUBSIDY_AIRTEL_LOCKID_STATUS_NOT_ALLOWED_EV,
    TAPI_SUBSIDY_AIRTEL_LOCKID_STATUS_ACTIVATED_EV,
    TAPI_SUBSIDY_AIRTEL_LOCKID_STATUS_DEACTIVATED_EV,
    TAPI_SUBSIDY_AIRTEL_LOCKID_STATUS_INVALID_CODE_EV,
    TAPI_SUBSIDY_AIRTEL_LOCKID_STATUS_PENALTY_EV,
    TAPI_SUBSIDY_AIRTEL_LOCKID_STATUS_TRY_LATER_EV

};
typedef UINT8 TAPI_SECURITY_SUBSIDY_AIRTEL_LOCKID_STATUS_E;

enum _TAPI_SECURITY_SUBSIDY_LOCK_RESET_LOCK_STATUS_E
{
    TAPI_SUBSIDY_LOCK_RESET_NONE,                 
	TAPI_SUBSIDY_LOCK_RESET_SINGLELAYER_LOCKED,
	TAPI_SUBSIDY_LOCK_RESET_SINGLELAYER_UNLOCKED,
	TAPI_SUBSIDY_LOCK_RESET_DUALLAYER_LOCKED, 
	TAPI_SUBSIDY_LOCK_RESET_DUALLAYER_UNLOCKED,
	TAPI_SUBSIDY_LOCK_RESET_DUALLAYER_SECONDARY_UNLOCKED 

};
typedef UINT8 TAPI_SECURITY_SUBSIDY_LOCK_RESET_LOCK_STATUS_E;

enum _TAPI_SECURITY_SUBSIDY_RESET_STATUS_E
{
	TAPI_SUBSIDY_LOCK_RESET_ERROR_EV = 0,
    TAPI_SUBSIDY_LOCK_RESET_NOT_ALLOWED_EV ,
    TAPI_SUBSIDY_LOCK_RESET_SUCCESS_EV,
    TAPI_SUBSIDY_LOCK_RESET_FAILURE_EV

};
typedef UINT8 TAPI_SECURITY_SUBSIDY_RESET_STATUS_E;

typedef enum    _TAPI_SECURITY_PIN_STATUS_E
{
    TAPI_SECURITY_PIN_STATUS_ENABLE_EV              = 2,    
    TAPI_SECURITY_PIN_STATUS_DISABLE_EV             = 3,    
    TAPI_SECURITY_PIN_STATUS_BLOCKED_EV             = 5,    
    TAPI_SECURITY_PIN_STATUS_PERMANENT_BLOCKED_EV   = 6,    
    TAPI_SECURITY_PIN_STATUS_ENABLE_CHECKED_EV      = 7,    

    TAPI_SECURITY_PIN_STATUS_UNKNOWN_EV,                    
    TAPI_SECURITY_PIN_STATUS_INVALID_EV             = 255   
} TAPI_SECURITY_PIN_STATUS_E;

typedef enum    _TAPI_SIM_PIN1_STATUS_E
{
    TAPI_SIM_PIN1_STATUS_BLOCK_EV                   = 0,
    TAPI_SIM_PIN1_STATUS_UNBLOCK_EV,
} TAPI_SIM_PIN1_STATUS_E;

enum _TAPI_CALL_CHARGE_TYPE_E
{
    TAPI_CALL_CHARGE_TYPE_UNIT_EV                   = 0,    
    TAPI_CALL_CHARGE_TYPE_CURRENCY_EV                       
};

typedef UINT8   TAPI_CALL_CHARGE_TYPE_E;

enum _TAPI_CALL_CHARGE_STATUS_E
{
    TAPI_CALL_CHARGE_STATUS_OFF_EV,             
    TAPI_CALL_CHARGE_STATUS_TIME_PER_CALL_EV,   
    TAPI_CALL_CHARGE_STATUS_COST_PER_CALL_EV,   
    TAPI_CALL_CHARGE_STATUS_TOTAL_COST_EV,      
    TAPI_CALL_CHARGE_STATUS_CREDIT_AVAILABLE_EV 
};

typedef UINT8   TAPI_CALL_CHARGE_STATUS_E;

typedef enum    _TAPI_CALL_DIVERT_MODE_E
{
    TAPI_CALL_DIVERT_MODE_DISABLE_EV,           
    TAPI_CALL_DIVERT_MODE_ENABLE_EV,            
    TAPI_CALL_DIVERT_MODE_QUERY_STATUS_EV,      
    TAPI_CALL_DIVERT_MODE_REGISTRATION_EV,      
    TAPI_CALL_DIVERT_MODE_ERASURE_EV            
} TAPI_CALL_DIVERT_MODE_E;

typedef enum    _TAPI_CS_DIVERT_TYPE_E
{
    TAPI_CS_DIVERT_TYPE_VOICE_EV                    = 1,    
    TAPI_CS_DIVERT_TYPE_DATA_EV                     = 2,    
    TAPI_CS_DIVERT_TYPE_VIDEO_EV                    = 3,    
    TAPI_CS_DIVERT_TYPE_FAX_EV                      = 4,    
    TAPI_CS_DIVERT_TYPE_CANCEL_ALL_EV,                      
    TAPI_CS_DIVERT_TYPE_CANCEL_ALL_VOICE_EV                 
} TAPI_CS_DIVERT_TYPE_E;

typedef enum    _TAPI_CS_DIVERT_WHEN_E
{
    TAPI_CS_DIVERT_WHEN_UNCONDITIONAL_EV,   
    TAPI_CS_DIVERT_WHEN_BUSY_EV,            
    TAPI_CS_DIVERT_WHEN_NO_ANSWER_EV,       
    TAPI_CS_DIVERT_WHEN_NOT_REACHABLE_EV,   
    TAPI_CS_DIVERT_WHEN_ALL_FORWARDING_EV,  
    TAPI_CS_DIVERT_WHEN_ALL_CONDITIONAL_EV  
} TAPI_CS_DIVERT_WHEN_E;

typedef enum _TAPI_CS_DELAY_TIME_E
{
    TAPI_CS_DELAY_TIME_5_EV  = 5,
    TAPI_CS_DELAY_TIME_10_EV = 10,
    TAPI_CS_DELAY_TIME_15_EV = 15,
    TAPI_CS_DELAY_TIME_20_EV = 20,
    TAPI_CS_DELAY_TIME_25_EV = 25,
    TAPI_CS_DELAY_TIME_30_EV = 30,
    TAPI_CS_DELAY_TIME_INVALID_EV    = 255
}TAPI_CS_DELAY_TIME_E;

typedef enum    _TAPI_CS_BAR_TYPE_E
{
    TAPI_CS_BAR_OUTGOING_INTERNATIONAL_EV               = 0,    
    TAPI_CS_BAR_OUTGOING_INTERNATIONAL_EXCEPT_HOME_EV,          

    TAPI_CS_BAR_OUTGOING_ALL_EV,                                
    TAPI_CS_BAR_OUTGOING_ALL_SERVICE_EV,                        
    TAPI_CS_BAR_INCOMING_WHEN_ROAM_EV,                          
    TAPI_CS_BAR_INCOMING_ALL_EV,                                
    TAPI_CS_BAR_INCOMING_ALL_SERVICE_EV,                        
    TAPI_CS_BAR_CANCEL_EV                                       
} TAPI_CS_BAR_TYPE_E;

typedef enum    _TAPI_CALL_RESTRICT_ID_E
{
    TAPI_CALL_RESTRICT_ID_DEPEND_NETWORK_EV             = 0,    
    TAPI_CALL_RESTRICT_ID_ENABLE_EV,                            
    TAPI_CALL_RESTRICT_ID_DISABLE_EV                            
} TAPI_CALL_RESTRICT_ID_E;

typedef enum    _TAPI_SIM_STATUS_E
{
    TAPI_SIM_STATUS_AVAILABLE_EV                        = 0,    
    TAPI_SIM_STATUS_BAD_EV,                                     
    TAPI_SIM_STATUS_NONE_EV,                                    
    TAPI_SIM_STATUS_GOOD_EV,                                    
    TAPI_SIM_STATUS_GOOD_WCDMA_EV,                              
    TAPI_SIM_STATUS_USIM_UNSELECTED_EV,                         
    TAPI_SIM_STATUS_USIM_RESTORED_EV,                           
    TAPI_SIM_STATUS_USIM_SELECT_FAILURE_EV,                     
    TAPI_SIM_STATUS_2G_UNREG_EV,                                
    TAPI_SIM_STATUS_3G_UNREG_EV,                                
    TAPI_SIM_STATUS_INVALID_EV,                                 
    TAPI_SIM_STATUS_MANDATORY_FILE_MISSING_EV,
    TAPI_SIM_STATUS_UNKNOWN_EV                          = 255   
} TAPI_SIM_STATUS_E;

typedef enum    _TAPI_SECURITY_SUBSIDY_STATUS_E
{
    TAPI_SECURITY_SUBSIDY_STATUS_LOCK_OFF_EV,                   
    TAPI_SECURITY_SUBSIDY_STATUS_LOCK_ON_EV,                    
    TAPI_SECURITY_SUBSIDY_STATUS_LOCK_WAIT_EV,                  
    TAPI_SECURITY_SUBSIDY_STATUS_LOCK_UNKNOWN_EV,               
    TAPI_SECURITY_SUBSIDY_STATUS_UNKNOWN_EV             = 255   
} TAPI_SECURITY_SUBSIDY_STATUS_E;

typedef enum    _TAPI_RF_STATUS_E
{
    TAPI_RF_STATUS_OPENED_EV = 0,   
    TAPI_RF_STATUS_CLOSED_EV,       
    TAPI_RF_ACCE_STATUS_OPENED_EV,  
    TAPI_RF_ACCE_STATUS_CLOSED_EV   
} TAPI_RF_STATUS_E;

typedef enum    _TAPI_ENUM_DEVICE_STATUS_E
{
    TAPI_EMU_PIHF_CHARGING_DISABLE_EV                   = 0,    
    TAPI_EMU_PIHF_CHARGING_ENABLED_500MA_EV,                    
    TAPI_EMU_PIHF_CHARGING_ENABLED_1500MA_EV,                   
    TAPI_EMU_PIHF_POWER_ON_EV                                   
} TAPI_EMU_DEVICE_STATUS_E;

enum _TAPI_BATTERY_MODE_E
{
    TAPI_BATTERY_MODE_NORMAL_EV,    
    TAPI_BATTERY_MODE_SAVING_EV     
};

typedef UINT8   TAPI_BATTERY_MODE_E;

typedef enum    _TAPI_BATTERY_STATUS_E
{
    TAPI_BATTERY_STATUS_NONE_EV                         = 0,    
    TAPI_BATTERY_STATUS_UNCHARGABLE_EV,                         
    TAPI_BATTERY_STATUS_CHARGABLE_EV,                           
    TAPI_BATTERY_STATUS_INVALID_EV,                             
    TAPI_BATTERY_STATUS_UNKOWN_EV                       = 255   
} TAPI_BATTERY_STATUS_E;

typedef enum    _TAPI_CHARGER_STATUS_E
{
    TAPI_CHARGER_STATUS_CONNECT_EV                      = 0,    
    TAPI_CHARGER_STATUS_DISCONNECT_EV                   = 1,    
    TAPI_CHARGER_STATUS_INVALID_EV                      = 2,    
    TAPI_CHARGER_STATUS_UNKNOWN_EV                      = 255   
} TAPI_CHARGER_STATUS_E;

typedef enum _TAPI_USB_STATUS_E
{
   TAPI_USB_STATUS_CABLE_NONE_EV                           = 0,   
   TAPI_USB_STATUS_CABLE_USB_EV                            = 1,   
   TAPI_USB_STATUS_CABLE_REGRESSION_EV                     = 2,   
   TAPI_USB_STATUS_CABLE_FACTORY_EV                        = 3,   
   TAPI_USB_STATUS_CABLE_UNKNOWN_EV                        = 255  
} TAPI_USB_STATUS_E;

typedef enum    _TAPI_EIHF_STATUS_E
{
    TAPI_FAST_EIHF_STATUS_CONNECT_EV                    = 0,    
    TAPI_FAST_EIHF_STATUS_DISCONNECT_EV                 = 1,    
    TAPI_MID_EIHF_STATUS_CONNECT_EV                     = 2,    
    TAPI_MID_EIHF_STATUS_DISCONNECT_EV                  = 3,    
    TAPI_EIHF_STATUS_INVALID_VALUE_EV                   = 255   
} TAPI_EIHF_STATUS_E;

typedef enum    _TAPI_SMART_SPD_STATUS_E
{
    TAPI_SMART_SPD_STATUS_CONNECT_EV                    = 0,    
    TAPI_SMART_SPD_STATUS_DISCONNECT_EV                 = 1,    
    TAPI_SMART_SPD_STATUS_INVALID_VALUE_EV              = 255   
} TAPI_SMART_SPD_STATUS_E;

typedef enum    _TAPI_BLUETOOTH_POWER_E
{
    TAPI_BLUETOOTH_POWER_OFF_EV                         = 0,    
    TAPI_BLUETOOTH_POWER_ON_EV                                  
} TAPI_BLUETOOTH_POWER_E;

typedef enum    _TAPI_POWER_OFF_CAUSE_E
{
    TAPI_POWER_OFF_CAUSE_DEFAULT_EV                     = 0,    
    TAPI_POWER_OFF_CAUSE_KEY_EV,                                
    TAPI_POWER_OFF_CAUSE_BATTERY_EV                     = 3,    
    TAPI_POWER_OFF_CAUSE_CYCLE_EV                       = 6,    
    TAPI_POWER_OFF_CAUSE_TCMD_EV                        = 7,    
} TAPI_POWER_OFF_CAUSE_E;

typedef enum    _TAPI_POWER_ON_MODE_E
{
    TAPI_POWER_ON_MODE_CHARGE_ONLY_EV,                         
    TAPI_POWER_ON_MODE_NORMAL_EV,                              
    TAPI_POWER_ON_MODE_AUTO_EV,                                
    TAPI_POWER_ON_MODE_PDA_MODE_EV,                            
    TAPI_POWER_ON_MODE_UNKNOWN_EV                      = 255   
} TAPI_POWER_ON_MODE_E;

typedef enum    _TAPI_NETWORK_STATUS_E
{
    TAPI_NETWORK_STATUS_SEARCHING_EV,       
    TAPI_NETWORK_STATUS_REGISTERING_EV,     
    TAPI_NETWORK_STATUS_NO_AVAILABLE_EV,    
    TAPI_NETWORK_STATUS_UNREGISTERED_EV,    
    TAPI_NETWORK_STATUS_BUSY_EV,            
    TAPI_NETWORK_STATUS_REGISTERED_EV,      
    TAPI_NETWORK_STATUS_EMERGENCY_ONLY_EV,  
    TAPI_NETWORK_STATUS_DEREGISTED_EV,      
    TAPI_NETWORK_STATUS_UNKNOWN_EV          
} TAPI_NETWORK_STATUS_E;

typedef enum    _TAPI_ADDRESS_BOOK_TYPE_E
{
    TAPI_ADDRESS_BOOK_TYPE_SIM_CARD_EV                  = 0,    
    TAPI_ADDRESS_BOOK_TYPE_FIXDIALING_EV                        
} TAPI_ADDRESS_BOOK_TYPE_E;

typedef enum    _TAPI_PHONEBOOK_WRITE_MODE_E
{
    TAPI_PHONEBOOK_WRITE_NORMAL_EV,         
    TAPI_PHONEBOOK_WRITE_FORCE_EV           
} TAPI_PHONEBOOK_WRITE_MODE_E;

enum
{
    TAPI_CALL_RESTRICT_NEXT_ID_NOT_DEFINE_EV            = 0,    
    TAPI_CALL_RESTRICT_NEXT_ID_ENABLE_EV,                       
    TAPI_CALL_RESTRICT_NEXT_ID_DISABLE_EV,                      
    TAPI_CALL_RESTRICT_NEXT_ID_NETWORK_CONTROLLED_EV            
};

typedef UINT8 TAPI_CALL_RESTRICT_NEXT_ID_E;

enum
{
    TAPI_CALL_DTMF_TONE_TYPE_OFF_EV                     = 0,    
    TAPI_CALL_DTMF_TONE_TYPE_SHORT_EV,                          
    TAPI_CALL_DTMF_TONE_TYPE_LONG_EV                            
};

typedef UINT8 TAPI_CALL_DTMF_TONE_TYPE_E;

typedef enum _TAPI_LOG_DATA_SESSION_TYPE_E
{
    TAPI_LOG_DATA_INTERNAL_SESSION_EV                   = 0,
    TAPI_LOG_DATA_EXTERNAL_SESSION_EV                   = 1
} TAPI_LOG_DATA_SESSION_TYPE_E;

enum   
{
    TAPI_PHONE_MODE_IMS_ONLY,             
    TAPI_PHONE_MODE_CELLULAR_ONLY,        
    TAPI_PHONE_MODE_IMS_PREFERRED,        
    TAPI_PHONE_MODE_CELLULAR_PREFERRED,   
};
typedef UINT8 TAPI_PHONE_MODE_E;

typedef enum _TAPI_NETWORK_RAT_TYPE_E
{
    TAPI_NETWORK_RAT_GSM_ONLY  = 1,
    TAPI_NETWORK_RAT_UMA_ONLY  = 4,
    TAPI_NETWORK_RAT_GSM_UMA   = 5
}TAPI_NETWORK_RAT_TYPE_E;

typedef enum _TAPI_NETWORK_MA_TYPE_E
{
    TAPI_NETWORK_MA_TYPE_NONE_EV,       
    TAPI_NETWORK_MA_TYPE_GSM_EV,        
    TAPI_NETWORK_MA_TYPE_WCDMA_EV,      
    TAPI_NETWORK_MA_TYPE_UMA_EV,        
    TAPI_NETWORK_MA_TYPE_IMS_EV         
} TAPI_NETWORK_MA_TYPE_E;

typedef enum _TAPI_CALLSET_DIVERT_ICON_E 
{ 
    TAPI_CALLSET_DIVERT_ICON_VOICE_LINE1 = 0,    
    TAPI_CALLSET_DIVERT_ICON_VOICE_LINE2,        
    TAPI_CALLSET_DIVERT_ICON_VOICE_ON,           
    TAPI_CALLSET_DIVERT_ICON_VOICE_BOTH,         
    TAPI_CALLSET_DIVERT_ICON_VIDEO_ON,           
    TAPI_CALLSET_DIVERT_ICON_OFF                 
}TAPI_CALLSET_DIVERT_ICON_E;

typedef UINT8   TAPI_LOG_CCM_STRING_A[TAPI_LOG_MAX_CCM_STRING_LENGTH];

typedef INT8    TAPI_NETWORK_MCC_DIGITS_A[TAPI_MAX_MCC_DIGITS_LENGTH];

typedef INT8    TAPI_NETWORK_MNC_DIGITS_A[TAPI_MAX_MNC_DIGITS_LENGTH];

typedef UINT32  TAPI_NETWORK_INDEX_T;

typedef UINT8   TAPI_NETWORK_OPERATOR_ID_A[TAPI_MAX_PLMN_NAME_LENGTH];

typedef UINT16  TAPI_NETWORK_SERVICE_NAME_A[TAPI_NETWORK_MAX_SERVICE_NAME_LENGTH + 1];

typedef UINT8   TAPI_NETWORK_PLMN_STRING_A[TAPI_NETWORK_MAX_SERVICE_NAME_LENGTH];

typedef UINT16  TAPI_NETWORK_PLMN_NAME_A[TAPI_MAX_PLMN_NAME_BYTE_LENGTH + 1];

typedef INT8    TAPI_CS_CALL_METER_A[TAPI_MAX_CALL_METER_LENGTH];

typedef INT8    TAPI_CS_CALL_CURRENCY_A[TAPI_CALL_MAX_CURRENCY_LENGTH + 1];

typedef INT8    TAPI_CS_CALL_PRICE_UINT_A[TAPI_CALL_MAX_PRICE_UNIT_LENGTH];

typedef INT8    TAPI_CS_CALL_REMAIN_CREDIT_A[TAPI_MAX_CREDIT_LENGTH];

typedef INT8    TAPI_PASSWORD_A[TAPI_PASSWORD_LENGTH + 1];

typedef UINT8   TAPI_BLUETOOTH_ADDRESS_A[TAPI_BLUETOOTH_ADDRESS_LENGTH];

typedef struct  _TAPI_CS_CALL_BAR_STATUS
{
    TAPI_CALL_TYPE_E    type;
    TAPI_BOOL_STATUS_E  state;
} TAPI_CS_CALL_BAR_STATUS;

typedef TAPI_CS_CALL_BAR_STATUS TAPI_CS_CALL_BAR_ALL_STATUS_A[TAPI_CALL_TYPE_COUNT];

typedef struct  _TAPI_SERVICE_PROVIDER_NAME_S
{
    BOOLEAN                     bDisplayRegisteredPlmn;
    TAPI_NETWORK_SERVICE_NAME_A name;
} TAPI_SERVICE_PROVIDER_NAME_S;

typedef struct  _TAPI_LOG_DATA_SESSION_SUM_TYPE_S
{
    UINT16                          sumType;    
    TAPI_LOG_DATA_SESSION_TYPE_E    dataSessionType;
} TAPI_LOG_DATA_SESSION_SUM_TYPE_S;

typedef struct  _TAPI_LOG_DATA_SESSION_VOLUME_S
{
    UINT32  sendVolume;
    UINT32  receiveVolume;
} TAPI_LOG_DATA_SESSION_VOLUME_S;

typedef struct  _TAPI_USB_CABLE_STATUS_S
{
    TAPI_USB_CABLE_STATUS_E cableStatus;
    TAPI_USB_CHARGING_E     chargingStatus;
} TAPI_USB_CABLE_STATUS_S;

typedef struct  _TAPI_NETWORK_NOTIFY_PREFERED_LIST_MSG_S
{
    TAPI_RESULT_E               result;             
    TAPI_NETWORK_INDEX_T        totalNum;           
    TAPI_NETWORK_OPERATOR_ID_A  networkId[TAPI_NETWORK_MAX_PREFERED_NUMBER];    
    TAPI_NETWORK_RAT_TYPE_E     ratType[TAPI_NETWORK_MAX_PREFERED_NUMBER];      
} __attribute__( (packed) )  TAPI_NETWORK_NOTIFY_PREFERED_LIST_MSG_S;

typedef struct  _TAPI_NETWORK_NOTIFY_REG_INFO_S
{
    TAPI_NETWORK_MA_TYPE_E      ma;             
    TAPI_NETWORK_STATUS_E       reg_state;      
    TAPI_NETWORK_ROAM_E         roam_status;    
    TAPI_NETWORK_OPERATOR_ID_A  plmn;           
    UINT8                       lac0;           
    UINT8                       lac1;           
    UINT8                       cid0;           
    UINT8                       cid1;           
} TAPI_NETWORK_NOTIFY_REG_INFO_S;

typedef struct  _TAPI_NETWORK_PLMN_INDEX_S
{
    UINT16  mcc;        
    UINT16  mnc;        
    INT32   location;   
    UINT8   contextLen; 
} __attribute__( (packed) )  TAPI_NETWORK_PLMN_INDEX_S;

typedef struct  _TAPI_NETWORK_PLMN_INFO_S
{
    UINT8                       plmnIdStr[TAPI_NETWORK_MAX_OPERATOR_ID_LENGTH]; 
    UINT8                       band;       
    TAPI_NETWORK_PLMN_STRING_A  name;       
} __attribute__( (packed) )  TAPI_NETWORK_PLMN_INFO_S;

typedef struct _TAPI_NETWORK_ACCESS_TECHNOLOGY_S
{
    TAPI_BOOL_STATUS_E gsm;
    TAPI_BOOL_STATUS_E gsm_compact;
    TAPI_BOOL_STATUS_E utra;
} TAPI_NETWORK_ACCESS_TECHNOLOGY_S;

typedef struct  _TAPI_NETWORK_PLMN_S
{
    TAPI_NETWORK_INDEX_T        priority;   
    TAPI_NETWORK_OPERATOR_ID_A  networkId;  
    TAPI_NETWORK_ACCESS_TECHNOLOGY_S access_technology; 
} __attribute__( (packed) )  TAPI_NETWORK_PLMN_S;

typedef struct  _TAPI_SET_PIN_STATUS_S
{
    UINT8           status;
    TAPI_PASSWORD_A password;
} __attribute__( (packed) )  TAPI_SET_PIN_STATUS_S;

typedef struct  _TAPI_SECURITY_PASSWORD_S
{
    TAPI_PASSWORD_A oldPassword;
    TAPI_PASSWORD_A newPassword;
} __attribute__( (packed) )  TAPI_SECURITY_PASSWORD_S;

typedef  struct _TAPI_SECURITY_SUBSIDY_AIRTEL_LOCK_ACTDEACT_REQUEST_S
{
    	TAPI_PASSWORD_A          password;
    	UINT8			         lock_id;

} __attribute__( (packed) ) TAPI_SECURITY_SUBSIDY_AIRTEL_LOCK_ACTDEACT_REQUEST_S;

typedef  struct _TAPI_SECURITY_SUBSIDY_AIRTEL_LOCK_DEACTIVATE_S
{
    UINT32 	                                  retries_left;
    TAPI_SECURITY_SUBSIDY_AIRTEL_LOCKID_STATUS_E  pStatus;

} __attribute__( (packed) ) TAPI_SECURITY_SUBSIDY_AIRTEL_LOCK_DEACTIVATE_S;

typedef struct _TAPI_SECURITY_SUBSIDY_RESET_VERIFY_PASSWORD_S 
{
	BOOL                              rearm_unlock;
    TAPI_PASSWORD_A                   password;

} __attribute__( (packed) ) TAPI_SECURITY_SUBSIDY_RESET_VERIFY_PASSWORD_S;

typedef struct _TAPI_SECURITY_SUBSIDY_IS_AIRTEL_ON_S 
{
	BOOL                              status;

} __attribute__( (packed) ) TAPI_SECURITY_SUBSIDY_IS_AIRTEL_ON_S;

typedef struct  _TAPI_PHONEBOOK_ENTRY_SCOPE_S
{
    UINT16  startLocation;
    UINT16  endLocation;
} __attribute__( (packed) )  TAPI_PHONEBOOK_ENTRY_SCOPE_S;

typedef struct  _TAPI_PHONEBOOK_SAVE_ENTRY_S
{
    INT16                   position;       
    TAPI_PHONE_NUMBER_A     phoneNumber;    
    TAPI_PHONEBOOK_NAME_A   name;           
    INT32                   flag;           
} __attribute__( (packed) )  TAPI_PHONEBOOK_SAVE_ENTRY_S;

typedef struct  _TAPI_CS_RESTRICT_ID_PARAM_S
{
    UINT8   status;
    UINT8   networkStatus;
} __attribute__( (packed) )  TAPI_CS_RESTRICT_ID_PARAM_S;

typedef struct  _TAPI_CALL_RSP_DIVERT_MSG_S
{
    UINT8               status;     
    UINT8               callClass;  
    TAPI_PHONE_NUMBER_A number;     
    UINT8               subAddress[TAPI_NETWORK_SUB_ADDRESS_LENGTH + 1];    
    UINT8               subType;    
    UINT8               time;       

    UINT8               type;       

} __attribute__( (packed) )  TAPI_CALL_RSP_DIVERT_MSG_S;

typedef struct  _TAPI_CALL_DATA_CBST_PARAM_S
{
    UINT16  speed;
    UINT8   service;
    UINT8   ce;
} __attribute__( (packed) )  TAPI_CALL_DATA_CBST_PARAM_S;

typedef struct  _TAPI_CALL_STATUS_S
{
    UINT8   status;
    UINT8   classes;
} __attribute__( (packed) )  TAPI_CALL_STATUS_S;

typedef struct  _TAPI_BATTERY_INFO_S
{
    UINT8   bcs;                   
    UINT8   bcl;                   
    TAPI_USB_STATUS_E   usb_cs;    
} __attribute__( (packed) )  TAPI_BATTERY_INFO_S;

typedef struct _TAPI_BATTERY_PROPERTY_S
{
    TAPI_BATTERY_STATUS_E batteryStatus;
    TAPI_CHARGER_STATUS_E chargerStatus;
    UINT8 batteryLevel;                         
    UINT8 bars;                                 
    TAPI_USB_STATUS_E usbStatus;                
    BOOLEAN bNormalLowLevel;
    BOOLEAN bFullPowerOn;
} TAPI_BATTERY_PROPERTY_S;

typedef struct  _TAPI_CHARGER_USB_STATUS_S
{
    TAPI_CHARGER_STATUS_E   chargeStatus;   
    TAPI_USB_STATUS_E       usbStatus;  
} TAPI_CHARGER_USB_STATUS_S;

typedef struct  _TAPI_CALL_TIME_S
{
    UINT32  hour;
    UINT8   minute;
    UINT8   second;
} __attribute__( (packed) )  TAPI_CALL_TIME_S;

typedef struct  _TAPI_CALL_PRICE_UNIT_S
{
    UINT8   currency[TAPI_CALL_MAX_CURRENCY_LENGTH + 1];    
    UINT8   priceUnit[TAPI_CALL_MAX_PRICE_UNIT_LENGTH];     

} __attribute__( (packed) )  TAPI_CALL_PRICE_UNIT_S;

typedef struct  _TAPI_NETWORK_PREFERRED_OPERATOR_S
{
    TAPI_NETWORK_NAME_A networkId;
    UINT8               format;
    UINT8               index;
} __attribute__( (packed) )  TAPI_NETWORK_PREFERRED_OPERATOR_S;

typedef struct  _TAPI_NETWORK_LOCAL_AREA_ID_S
{   
    TAPI_NETWORK_MCC_DIGITS_A mcc;      
    TAPI_NETWORK_MNC_DIGITS_A mnc;      
    UINT8   lac0;                     
    UINT8   lac1;                     
    UINT8   cid0;                     
    UINT8   cid1;                     
    UINT8   tac;                      
} __attribute__( (packed) )  TAPI_NETWORK_LOCAL_AREA_ID_S;

typedef struct  _TAPI_PHONEBOOK_CAPACITY_S
{
    TAPI_PHONEBOOK_STORAGE_TYPE_E   storageType;    
    UINT16                          used;           

    UINT16                          total;          

} __attribute__( (packed) )  TAPI_PHONEBOOK_CAPACITY_S;

typedef struct  _TAPI_PHONEBOOK_RANGE_S
{
    UINT8   maxNumberLen;           
    UINT8   maxNameLen;             
} __attribute__( (packed) )  TAPI_PHONEBOOK_RANGE_S;

typedef struct  _TAPI_PHONEBOOK_ENTRY_CONTENT_S
{
    UINT16                  index;  

    TAPI_PHONE_NUMBER_A     number; 
    TAPI_PHONEBOOK_NAME_A   alpha;  
    UINT8                   type;   
} __attribute__( (packed) )  TAPI_PHONEBOOK_ENTRY_CONTENT_S;

typedef struct  _TAPI_BLUETOOTH_DTMF_TONE_S
{
    UINT8   dtmfMode;   
    UINT8   keyTone;    
} __attribute__( (packed) )  TAPI_BLUETOOTH_DTMF_TONE_S;

typedef struct  _TAPI_NETWORK_EONS_NAME_S
{
    UINT16                      mcc;
    UINT16                      mnc;
    TAPI_NETWORK_PLMN_NAME_A    shortName;
    TAPI_NETWORK_PLMN_NAME_A    longName;
} __attribute__( (packed) )  TAPI_NETWORK_EONS_NAME_S;

typedef struct  _TAPI_NETWORK_NITZ_NAME_S
{
    TAPI_NETWORK_PLMN_NAME_A    shortName;
    TAPI_NETWORK_PLMN_NAME_A    longName;
} __attribute__( (packed) )  TAPI_NETWORK_NITZ_NAME_S;

typedef struct  _TAPI_NETWORK_NITZ_TIME_S
{
    TAPI_TIME_DATE_S    universalTime;      
    INT32               localZone;          
    UINT16              dayLightSavingTime; 
} __attribute__( (packed) )  TAPI_NETWORK_NITZ_TIME_S;

typedef struct  _TAPI_SIGNAL_QUALITY_S
{
    UINT8   rssi;   
    UINT8   ber;    
} __attribute__( (packed) )  TAPI_SIGNAL_QUALITY_S;

typedef struct _TAPI_CALLSET_NOTIFY_DIVERT_ICON_STATUS_S 
{ 
    TAPI_CALLSET_DIVERT_ICON_E icon_status; 
} TAPI_CALLSET_NOTIFY_DIVERT_ICON_STATUS_S;

#ifdef __cplusplus
}
#endif 

#endif  

