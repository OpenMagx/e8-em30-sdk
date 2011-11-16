

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_VOICE_APPDATA_H_  
#define TAPI_VOICE_APPDATA_H_

#ifdef __cplusplus 
extern "C" {
#endif

#include <sys/types.h>
#include "TAPI_Result.h"
#include "TAPI_CALL_General.h"

#define   TAPI_CALL_MAX_BCD_STRING_LENGTH          512

#define   TAPI_CALL_MAX_COST_STRING_LENGTH         23

typedef enum    _TAPI_VOICE_DIAL_CALL_TYPE_E
{
    TAPI_VOICE_DIAL_CALL_NORMAL_EV      = 0,    
    TAPI_VOICE_DIAL_CALL_STK_SETUP_EV,          
    TAPI_VOICE_DIAL_CALL_SS_MODIFY_EV,          
} TAPI_VOICE_DIAL_CALL_TYPE_E;

typedef enum    _TAPI_VOICE_ANSWER_CALL_TYPE_E
{
    TAPI_VOICE_ANSWER_CALL_DIRECT_EV,           
    TAPI_VOICE_ANSWER_CALL_DROP_ACTIVE_EV,      
    TAPI_VOICE_ANSWER_CALL_DROP_HOLD_EV,        
} TAPI_VOICE_ANSWER_CALL_TYPE_E;

typedef enum    _TAPI_VOICE_DROP_CALL_TYPE_E
{
    TAPI_VOICE_DROP_CALL_CURRENT_EV,            
    TAPI_VOICE_DROP_CALL_ALL_EV,                
    TAPI_VOICE_DROP_CALL_SPECIFIC_EV,           
} TAPI_VOICE_DROP_CALL_TYPE_E;

typedef enum    _TAPI_VOICE_REJECT_CALL_TYPE_E
{
    TAPI_VOICE_REJECT_CALL_IGNORE_EV,          
    TAPI_VOICE_REJECT_CALL_BUSY_EV,            
} TAPI_VOICE_REJECT_CALL_TYPE_E;

typedef enum    _TAPI_VOICE_INCOMING_CALL_TYPE_E
{
    TAPI_VOICE_INCOMING_CALL_RING_EV,          
    TAPI_VOICE_INCOMING_CALL_WAITING_EV,       
} TAPI_VOICE_INCOMING_CALL_TYPE_E;

typedef enum    _TAPI_VOICE_CALL_STATUS_E
{
    TAPI_VOICE_CALL_STATUS_CONNECT_EV,      
    TAPI_VOICE_CALL_STATUS_DISCONNECT_EV,   
    TAPI_VOICE_CALL_STATUS_CONNECT_FAIL_EV, 
    TAPI_VOICE_CALL_STATUS_BUSY_EV,         
    TAPI_VOICE_CALL_STATUS_REDIAL_EV,       
    TAPI_VOICE_CALL_STATUS_HOLD_EV,         
    TAPI_VOICE_CALL_STATUS_CONNECTING_EV,   
    TAPI_VOICE_CALL_STATUS_BARRING_EV,      
} TAPI_VOICE_CALL_STATUS_E;

typedef enum    _TAPI_VOICE_CALL_ACTION_E
{
    TAPI_VOICE_CALL_ACTION_HOLD_EV          = 2,    
    TAPI_VOICE_CALL_ACTION_RETRIEVE_EV      = 3,    
    TAPI_VOICE_CALL_ACTION_RELEASE_EV       = 5,    
    TAPI_VOICE_CALL_ACTION_CONFERENCE_EV    = 4,    
    TAPI_VOICE_CALL_ACTION_SPLIT_EV         = 11,   
    TAPI_VOICE_CALL_ACTION_TRANSFER_EV      = 7,    
    TAPI_VOICE_CALL_ACTION_LINK_EV          = 8,    
    TAPI_VOICE_CALL_ACTION_SWITCH_EV        = 13,   
} TAPI_VOICE_CALL_ACTION_E;

typedef enum    _TAPI_CREDIT_MODE_E
{
    TAPI_CREDIT_LIMIT_REACHED_EV      = 0,    
    TAPI_CREDIT_LIMIT_1_MINUTE_LEFT_EV,       
    TAPI_CREDIT_LIMIT_2_MINUTE_LEFT_EV,       
} TAPI_CREDIT_MODE_E;

typedef enum    _TAPI_CALL_CONTROL_E
{
    TAPI_CALL_CONTROL_ALLOWED_EV            = 0,    
    TAPI_CALL_CONTROL_NOT_ALLOWED_EV,               
    TAPI_CALL_CONTROL_NUMBER_MODIFIED_EV,           
    TAPI_CALL_CONTROL_MODIFY_TO_SS_EV,              
} TAPI_CALL_CONTROL_E;

typedef enum    _TAPI_CALL_CSSI_E
{
    TAPI_CALL_CSSI_CALL_FORWARD_UNCONDITIONAL_EV,   

    TAPI_CALL_CSSI_CALL_FORWARD_CONDITIONAL_EV,     

    TAPI_CALL_CSSI_CALL_HAS_BEEN_FORWAREDED_EV,     
    TAPI_CALL_CSSI_CALL_WAITING_EV,                 
    TAPI_CALL_CSSI_A_CUG_CALL_EV,                   
    TAPI_CALL_CSSI_BAR_OUTGOING_EV          = 5,    
    TAPI_CALL_CSSI_BAR_INCOMING_EV,                 
    TAPI_CALL_CSSI_CLIR_SUPPRES_REJECTED_EV,        
    TAPI_CALL_CSSI_CALL_HAS_BEEN_DEFLECTED_EV,      
    TAPI_CALL_CSSI_INVALID_NOTIFICATION_EV  = 0xFF  
} TAPI_CALL_CSSI_E;

typedef enum    _TAPI_CALL_CSSU_E
{
    TAPI_CALL_CSSU_INCOMING_IS_A_FORWARDED_CALL_EV  = 0,  

    TAPI_CALL_CSSU_A_CUG_CALL_EV                    = 1,  

    TAPI_CALL_CSSU_FORWARD_CHECK_SS_MSG_RECEIVED_EV = 6,  

    TAPI_CALL_CSSU_CONNECTED_WITH_REMOTE_PARTY_EV   = 8,  

    TAPI_CALL_CSSU_FORWARDED_INCOMING_EV            = 0x0a,

    TAPI_CALL_CSSU_CALL_IS_AOC_RESTRICTED_EV        = 12,  

    TAPI_CALL_CSSU_INVALID_NOTIFICATION_EV          = 0xFF 

} TAPI_CALL_CSSU_E;

typedef enum    _TAPI_CALL_STK_TYPE_E
{
    TAPI_CALL_DIAL_STK_SETUP_EV                     = 1,    
    TAPI_CALL_DIAL_SS_MODIFY_EV,                            
} TAPI_CALL_STK_TYPE_E;

typedef enum    _TAPI_CALL_STK_REDIAL_E
{
    TAPI_CALL_STK_REDIAL_RESTRICTED_EV              = 0,    
    TAPI_CALL_STK_REDIAL_NOT_RESTRICTED_EV,                 
} TAPI_CALL_STK_REDIAL_E;

typedef enum    _TAPI_VOICE_DTMF_KEY_STATUS_E
{
    TAPI_VOICE_DTMF_KEY_DOWN_EV                     = 0,    
    TAPI_VOICE_DTMF_KEY_UP_EV,                              
} TAPI_VOICE_DTMF_KEY_STATUS_E;

enum _TAPI_TTY_MODE_E
{
    TAPI_TTY_MODE_VOICE_EV                          = 0,    
    TAPI_TTY_MODE_TTY_EV,                                   
    TAPI_TTY_MODE_VCO_EV,                                   
    TAPI_TTY_MODE_HCO_EV,                                   
};

typedef UINT8   TAPI_TTY_MODE_E;

typedef UINT8   TAPI_CALL_COST_INCALL_STRING_A[TAPI_CALL_MAX_COST_STRING_LENGTH];

typedef UINT8   TAPI_PANIC_BCD_A[TAPI_CALL_MAX_BCD_STRING_LENGTH];

typedef struct  _TAPI_VOICE_NOTIFY_CALL_CONTROL_MSG_S
{
    TAPI_CALL_CONTROL_E value;            
    TAPI_PHONE_NUMBER_A number;           
    BOOLEAN             bAlphaIdPresent;
    UINT16              alphaIdLength;
    TAPI_STK_ALPHAID_A  alphaId;
} TAPI_VOICE_NOTIFY_CALL_CONTROL_MSG_S;

typedef struct  _TAPI_VOICE_NOTIFY_CALL_STATUS_MSG_S
{
    TAPI_CALL_ID_T              callId;     
    TAPI_VOICE_CALL_STATUS_E    status;     
    pid_t                       pid;        
} TAPI_VOICE_NOTIFY_CALL_STATUS_MSG_S;

typedef struct  _TAPI_VOICE_NOTIFY_SERVICE_RESULT_MSG_S
{
    TAPI_VOICE_CALL_ACTION_E    action;     
    TAPI_RESULT_E               result;     
    TAPI_CALL_CAUSE_E           cause;      
} TAPI_VOICE_NOTIFY_SERVICE_RESULT_MSG_S;

typedef struct  _TAPI_VOICE_NOTIFY_INCOMING_CALL_MSG_S
{
    TAPI_CALL_ID_T                  callId;          
    TAPI_VOICE_INCOMING_CALL_TYPE_E type;            
    BOOLEAN                         isKodiakPTTCall; 
    TAPI_PHONE_NUMBER_A             phoneNumber;     
    TAPI_CALL_LINE_E                lineNo;          
    TAPI_PHONEBOOK_NAME_A           alpha;
} TAPI_VOICE_NOTIFY_INCOMING_CALL_MSG_S;

typedef struct  _TAPI_VOICE_NOTIFY_INCOMING_REFER_MSG_S
{
    TAPI_CALL_ID_T                  callId;         
    TAPI_PHONE_NUMBER_A             phoneNumber;    
} TAPI_VOICE_NOTIFY_INCOMING_REFER_MSG_S;

typedef struct  _TAPI_VOICE_NOTIFY_SPECIAL_CALL_MSG_S
{
    TAPI_CALL_ID_T  callId;     
    INT8            service;    
    INT8            cause;      
} TAPI_VOICE_NOTIFY_SPECIAL_CALL_MSG_S;

typedef struct  _TAPI_VOICE_NOTIFY_CALLING_MSG_S
{
    pid_t               pid;            
    TAPI_CALL_ID_T      callId;         
    TAPI_PHONE_NUMBER_A phoneNumber;    
} TAPI_VOICE_NOTIFY_CALLING_MSG_S;

typedef struct  _TAPI_VOICE_NOTIFY_CONFERRENCE_CALL_S
{
    pid_t           pid;        
    TAPI_CALL_ID_T  callId;     
} TAPI_VOICE_NOTIFY_CONFERRENCE_CALL_S;

typedef struct  _TAPI_VOICE_NOTIFY_DTMF_STRING_CONFIRM_MSG_S
{
    TAPI_CALL_ID_T      callId; 
    TAPI_RESULT_E       result; 
} TAPI_VOICE_NOTIFY_DTMF_STRING_CONFIRM_MSG_S;

typedef struct  _TAPI_CALL_NOTIFY_RINGBACK_MSG_S
{
    TAPI_CALL_ID_T    callId;              
    BOOLEAN           play_local_ringback; 
} TAPI_CALL_NOTIFY_RINGBACK_MSG_S;

typedef struct  _TAPI_VOICE_NOTIFY_CALL_TRANSFER_MSG_S
{
    TAPI_CALL_ID_T              callIdHeld;     	
    TAPI_PHONE_NUMBER_A 	phoneNumberHeld;    	

    TAPI_CALL_ID_T              callIdActive;     	
    TAPI_PHONE_NUMBER_A 	phoneNumberActive;    	

} TAPI_VOICE_NOTIFY_CALL_TRANSFER_MSG_S ;

#ifdef __cplusplus
}
#endif 

#endif  
