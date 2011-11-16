

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef _TAPI_SYNC_GENERAL_H_
#define _TAPI_SYNC_GENERAL_H_

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_General.h"
#include "TAPI_SETUP_General.h"
#include "TAPI_GPRS_AppData.h"
#include "TAPI_CPHS_Client.h"

#define TAPI_MAX_WELCOME_MSG_CHAR_NUM      (50)

#ifndef _W_CHAR
#define _W_CHAR
typedef unsigned short W_CHAR;
#endif

typedef W_CHAR  TAPI_SIM_WELCOME_TEXT_A[TAPI_MAX_WELCOME_MSG_CHAR_NUM + 1];

typedef struct  _TAPI_SYNC_NOTIFY_STATUS_MSG_S
{
    TAPI_BATTERY_STATUS_E           batteryStatus;      
    TAPI_SIM_STATUS_E               simStatus;          
    TAPI_SECURITY_PIN_STATUS_E      pinStatus;          
    TAPI_SECURITY_SUBSIDY_STATUS_E  subsidyStatus;      
    TAPI_CHARGER_STATUS_E           chargeStatus;       
    TAPI_EIHF_STATUS_E              EIHFStatus;         
    TAPI_SMART_SPD_STATUS_E         smartSPDStatus;     
    TAPI_POWER_ON_MODE_E            powerOnStatus;      
    UINT8                           batteryValue;       
    TAPI_USB_STATUS_E               usbStatus;           
    TAPI_NETWORK_SIGNAL_E           signalQuality;      
    TAPI_NETWORK_ROAM_E             isRoaming;          
    TAPI_GPRS_ATTACH_STATUS_E       gprsAttachStatus;   
    TAPI_BOOL_STATUS_E              gprsServerStatus;   
    BOOLEAN                         isPrepaidSim;       
    BOOLEAN                         isTestSim;          
    TAPI_NETWORK_OPERATOR_NAME_A    networkId;          
    TAPI_NETWORK_STATUS_E           netWorkStatus;      
    TAPI_BOOL_STATUS_E              gprsFeatureStatus;  
    TAPI_IMSI_NUMBER_A              imsi;               
    TAPI_CPHS_NOTIFY_INFO_MSG_S     cphsInfo;           
    TAPI_BOOL_STATUS_E              egprsServiceStatus; 
    TAPI_BOOL_STATUS_E              suspendStatus;      
} TAPI_SYNC_NOTIFY_STATUS_MSG_S;

typedef struct  _TAPI_POWER_NOTIFY_STATUS_MSG_S
{
    TAPI_CHARGER_STATUS_E   chargeStatus;   
    TAPI_POWER_ON_MODE_E    powerOnStatus;  
} TAPI_POWER_NOTIFY_STATUS_MSG_S;

#ifdef __cplusplus
}
#endif 

#endif  

