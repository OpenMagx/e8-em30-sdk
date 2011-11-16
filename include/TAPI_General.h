

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef _TAPI_GENERAL_H_  
#define _TAPI_GENERAL_H_ 

#ifdef __cplusplus 
extern "C" {
#endif

#include "EZX_TypeDefs.h"

#define INTERFACE

#define TAPI_FLASH_FILE_LEGNTH                120

#define TAPI_FLASH_DIRECTORY_LEGNTH           110

#define TAPI_GPRS_DOWNLOAD_FILE               "gprsstat"

#define TAPI_DOWNLOAD_DIR                     "tapi/"

#define TAPI_GPRS_PROC_FILE                   "/proc/gprsbytes"

#define TAPI_MAX_UINT8_NUMBER                  0xFF

#define TAPI_MAX_UINT16_NUMBER                 0xFFFF

#define TAPI_INVALID_SOCKETFD                  (-1)

#define TAPI_LOACL_SOCKET_PATH                 "/tmp/tapisock"

#define  TAPI_IMSI_LENGTH                       15

#define TAPI_IMEI_SV_LENGTH                     16

#define  TAPI_MAX_ADDRBK_NAME_LENGTH            50     

#define  TAPI_CALL_MAX_CURRENCY_LENGTH          40

#define  TAPI_CALL_MAX_PRICE_UNIT_LENGTH        30

#define  TAPI_PHONEBOOK_MAX_NAME_LENGTH         (100+2)

#define  TAPI_MAX_PHONE_NUMBER_LENGTH           41

#define  TAPI_KODIAK_MAX_PHONE_NUMBER_LENGTH    80 

#define  TAPI_MAX_DTMF_STRING_LENGTH    100 

#define  TAPI_MAX_PLMN_NAME_LENGTH              (15+1)

#define  TAPI_BAR_PASSWORD_LENGTH               20

#define  TAPI_GPRS_MAX_APN_LENGTH               100

#define  TAPI_GPRS_MAX_PDP_CONTEXT_NUMBER       3

#define  TAPI_GPRS_MAX_SECONDARY_PDP_CONTEXT_NUMBER       1

#define  TAPI_GPRS_SECONDARY_PDP_CONTEXT_START_ID       101

#define  TAPI_MAX_INT16_NUMBER                  0x7fff

#define  TAPI_FLEX_BITS_SHARE_MEMORY_KEY        0xFEBCAD5C

#define  TAPI_FLEX_BITS_SHARE_MEMORY_SIZE       512

#define  TAPI_STK_MAX_ALPHA_ID_LENGTH           (512+2)

#define  TAPI_NETWORK_MAX_MCC_MNC_LENGTH        8

#define TAPI_HOME_ZONE_MAX_NAME_LENGTH          14

#define TAPI_BATTERY_EPROM_DATA_LEN             128

#define TAPI_BATTERY_SERIAL_NUMBER_LEN          6

#define TAPI_MAX_EXTENSION_NUMBER_LENGTH  23

#define TAPI_HARDWARE_VERSION_LEN               10

#ifndef TRUE
#define TRUE     1
#endif
#ifndef FALSE
#define FALSE    0
#endif

typedef enum    _TAPI_HOME_ZONE_TYPE_E
{
    TAPI_HOME_ZONE_TYPE_NOT_HOME_ZONE_EV= 0,
    TAPI_HOME_ZONE_TYPE_IN_HOME_ZONE_EV,
    TAPI_HOME_ZONE_TYPE_IN_CITY_ZONE_EV
} TAPI_HOME_ZONE_TYPE_E;

typedef enum    _TAPI_BATTERY_TYPE_E
{
    TAPI_BATTERY_TYPE_INVALID_EV                = 0,
    TAPI_BATTERY_TYPE_VALID_EV
} TAPI_BATTERY_TYPE_E;

enum _TAPI_BOOL_STATUS_E
{
    TAPI_BOOL_STATUS_OFF_EV             = 0,    
    TAPI_BOOL_STATUS_ON_EV                      
};
typedef UINT8   TAPI_BOOL_STATUS_E;

typedef enum    _TAPI_FEATURE_E
{
    TAPI_FEATURE_OFF_EV                 = 0,            
    TAPI_FEATURE_ON_EV                  = 1,            
    TAPI_FEATURE_UNKNOWN_EV             = 255           
} TAPI_FEATURE_E;

typedef enum    _TAPI_PHONEBOOK_STORAGE_TYPE_E
{
    TAPI_PHONEBOOK_STORAGE_TYPE_SIM_EV,                 
    TAPI_PHONEBOOK_STORAGE_TYPE_FIXDIALING_EV,          
    TAPI_PHONEBOOK_STORAGE_TYPE_OWNNUMBER_EV,           
    TAPI_PHONEBOOK_STORAGE_TYPE_SDN_EV,                 
    TAPI_PHONEBOOK_STORAGE_TYPE_MBDN_EV                  
} TAPI_PHONEBOOK_STORAGE_TYPE_E;

typedef enum    _TAPI_IMSI_REFRESH_CAUSE_E
{
    TAPI_IMSI_REFRESH_CAUSE_POWER_ON_EV         = 0,    
    TAPI_IMSI_REFRESH_CAUSE_STK_EV              = 1,    
    TAPI_IMSI_REFRESH_CAUSE_UNKNOWN_EV                  
} TAPI_IMSI_REFRESH_CAUSE_E;

typedef enum    _TAPI_UMAN_NETWORK_STATUS_E
{
    TAPI_UMAN_NETWORK_GSM_MODE_EV               = 0,
    TAPI_UMAN_NETWORK_UMA_MODE_EV,
} TAPI_UMAN_NETWORK_STATUS_E;

#ifndef EZX_TYPEDEFINE_H

typedef unsigned char UINT8;
typedef UINT8* P_UINT8; 
typedef signed char INT8;
typedef INT8* P_INT8;   
typedef unsigned short int UINT16;
typedef UINT16* P_UINT16;
typedef signed short int INT16;
typedef INT16* P_INT16;
typedef unsigned int UINT32;
typedef UINT32* P_UINT32;
typedef signed int INT32;
typedef INT32* P_INT32;
typedef UINT8 BOOLEAN;
#endif

typedef UINT16  TAPI_HOME_ZONE_NAME_A[TAPI_HOME_ZONE_MAX_NAME_LENGTH];

typedef UINT8   TAPI_PHONEBOOK_NAME_A[TAPI_PHONEBOOK_MAX_NAME_LENGTH];

typedef UINT8   TAPI_PHONE_NUMBER_A[TAPI_MAX_PHONE_NUMBER_LENGTH + 1];

typedef UINT8   TAPI_NETWORK_OPERATOR_NAME_A[TAPI_MAX_PLMN_NAME_LENGTH];

typedef UINT8   TAPI_IMSI_NUMBER_A[TAPI_IMSI_LENGTH + 1];

typedef UINT8   TAPI_IMEI_NUMBER_A[TAPI_IMSI_LENGTH + 1];

typedef UINT8   TAPI_IMEI_SV_NUMBER_A[TAPI_IMEI_SV_LENGTH + 1];

typedef UINT8   TAPI_FACTORY_NUMBER_A[TAPI_IMSI_LENGTH + 1];

typedef UINT8   TAPI_STK_ALPHAID_A[TAPI_STK_MAX_ALPHA_ID_LENGTH];

typedef UINT8   TAPI_NETWORK_NAME_A[16];

typedef UINT8   TAPI_BATTERY_EPROM_DATA_A[TAPI_BATTERY_EPROM_DATA_LEN];

typedef UINT8   TAPI_BATTERY_SERIAL_NUMBER_A[TAPI_BATTERY_SERIAL_NUMBER_LEN];

typedef UINT8   TAPI_EXTENSION_NUMBER_A[TAPI_MAX_EXTENSION_NUMBER_LENGTH + 1];

typedef UINT8   TAPI_KODIAK_PHONE_NUMBER_A[TAPI_KODIAK_MAX_PHONE_NUMBER_LENGTH + 1];

typedef UINT8   TAPI_DTMF_STRING_A[TAPI_MAX_DTMF_STRING_LENGTH + 1];

typedef UINT8   TAPI_HARDWARE_VERSION_A[TAPI_HARDWARE_VERSION_LEN + 1];

typedef struct  _TAPI_TIME_DATE_S
{
    UINT16  year;       
    UINT8   month;      
    UINT8   day;        
    UINT8   hour;       
    UINT8   minute;     
    UINT8   second;     
} __attribute__( (packed) )  TAPI_TIME_DATE_S;

typedef struct _TAPI_ACCE_NOTIFY_TIME_CHANGED_MSG_S
{
    TAPI_TIME_DATE_S  oldTime;     
    TAPI_TIME_DATE_S  currentTime; 
} TAPI_ACCE_NOTIFY_TIME_CHANGED_MSG_S;

typedef struct  _TAPI_HOME_ZONE_INFO_S
{
    TAPI_HOME_ZONE_TYPE_E   status;
    TAPI_HOME_ZONE_NAME_A   homeZoneName;
} __attribute__( (packed) )  TAPI_HOME_ZONE_INFO_S;

typedef struct  _TAPI_PHONEBOOK_OWNNUMBER_S
{
    TAPI_PHONEBOOK_NAME_A   alpha;      
    TAPI_PHONE_NUMBER_A     number;     
    UINT8                   type;
    UINT8                   speed;
    UINT8                   service;
    UINT8                   itc;
} __attribute__( (packed) )  TAPI_PHONEBOOK_OWNNUMBER_S;

typedef struct  _TAPI_SYNC_NOTIFY_IMSI_MSG_S
{
    TAPI_IMSI_NUMBER_A          imsi;         
    TAPI_IMSI_REFRESH_CAUSE_E   reason;       
} __attribute__( (packed) )  TAPI_SYNC_NOTIFY_IMSI_MSG_S;

typedef struct  _TAPI_GPRS_ACTIVE_STATUS_S
{
    UINT8   cid;        
    UINT8   status;     
} __attribute__( (packed) )  TAPI_GPRS_ACTIVE_STATUS_S;

typedef struct  _TAPI_GPRS_ADDRESS_INFO_S
{
    UINT8   cid;
    UINT8   pdpAddress[TAPI_GPRS_MAX_APN_LENGTH];
} __attribute__( (packed) )  TAPI_GPRS_ADDRESS_INFO_S;

typedef struct  _TAPI_FLEX_BIT_S
{
    UINT8   id;         
    UINT8   flexData;   
} __attribute__( (packed) )  TAPI_FLEX_BIT_S;

typedef struct  _TAPI_LINE_ID_S
{
    TAPI_PHONE_NUMBER_A     number;
    UINT8                   type;
    TAPI_EXTENSION_NUMBER_A subAddress;
    UINT8                   subType;
    TAPI_PHONEBOOK_NAME_A   alpha;
} __attribute__( (packed) )  TAPI_LINE_ID_S;

typedef struct  _TAPI_NETWORK_REG_STATUS_S
{
    UINT8   stat;
    UINT8   lac0;   
    UINT8   lac1;   
    UINT8   cid0;   
    UINT8   cid1;   
} __attribute__( (packed) )  TAPI_NETWORK_REG_STATUS_S;

#ifdef __cplusplus
}
#endif 

#endif  

