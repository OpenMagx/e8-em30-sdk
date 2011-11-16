

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef _TAPI_CALL_GENERAL_H_  
#define _TAPI_CALL_GENERAL_H_

#ifdef __cplusplus 
extern "C" {
#endif

#include "EZX_TypeDefs.h"
#include "TAPI_General.h"
#include "TAPI_SETUP_General.h"

#define TAPI_CALL_MAX_CALL_NUMBER          8 

#define TAPI_TELNO_WILDCARD         ('^')

#define TAPI_GPRS_NUMBER            "*99#"

enum _TAPI_CALL_LINE_E
{
    TAPI_CALL_LINE1_EV  = 0,            
    TAPI_CALL_LINE2_EV,                 
    TAPI_CALL_LINE_CURRENT_EV           
};

typedef INT8    TAPI_CALL_LINE_E;

typedef enum    _TAPI_CALL_SESSION_TYPE_E
{
    TAPI_CALL_SESSION_TYPE_CSD_EV,      
    TAPI_CALL_SESSION_TYPE_FAX_EV,      
    TAPI_CALL_SESSION_TYPE_VOICE_EV,    
    TAPI_CALL_SESSION_TYPE_GPRS_EV      
} TAPI_CALL_SESSION_TYPE_E;

typedef enum    _TAPI_CALL_ID_TYPE_E
{
    TAPI_CALL_ID_UNUSE_EV           = 0x00, 
    TAPI_CALL_ID_INVALID_EV         = 0xFF  
} TAPI_CALL_ID_TYPE_E;

typedef enum    _TAPI_CALL_CAUSE_E
{
    TAPI_CALL_CAUSE_NO_CAUSE_EV,                         
    TAPI_CALL_CAUSE_CC_BUSY_EV,                          
    TAPI_CALL_CAUSE_PARAMETER_ERROR_EV,                  
    TAPI_CALL_CAUSE_INVALID_NUMBER_EV,                   
    TAPI_CALL_CAUSE_OUTGOING_CALL_BARRED_EV,             
    TAPI_CALL_CAUSE_TOO_MANY_CALLS_ON_HOLD_EV,           
    TAPI_CALL_CAUSE_NORMAL_EV,                           
    TAPI_CALL_CAUSE_INTERCEPT_EV,                        
    TAPI_CALL_CAUSE_REORDER_EV,                          
    TAPI_CALL_CAUSE_NO_SERVICE_EV,	                     
    TAPI_CALL_CAUSE_DROPPED_EV,                          
    TAPI_CALL_CAUSE_SYSTEM_LOCKED_EV,                    
    TAPI_CALL_CAUSE_NETWORK_EV,                          
    TAPI_CALL_CAUSE_INVALID_CALL_ID_EV,                  
    TAPI_CALL_CAUSE_NORMAL_CLEARING_EV,                  
    TAPI_CALL_CAUSE_CALL_ALREADY_ANSWERED_EV,            
    TAPI_CALL_CAUSE_TOO_MANY_ACTIVE_CALLS_EV,            
    TAPI_CALL_CAUSE_UNASSIGNED_NUMBER_EV,                
    TAPI_CALL_CAUSE_NO_ROUTE_TO_DEST_EV,                 
    TAPI_CALL_CAUSE_RESOURCE_UNAVAILABLE_EV,             
    TAPI_CALL_CAUSE_CALL_BARRED_EV,                      
    TAPI_CALL_CAUSE_USER_BUSY_EV,                        
    TAPI_CALL_CAUSE_NO_ANSWER_EV,                        
    TAPI_CALL_CAUSE_CALL_REJECTED_EV,                    
    TAPI_CALL_CAUSE_NUMBER_CHANGED_EV,                   
    TAPI_CALL_CAUSE_DEST_OUT_OF_ORDER_EV,                
    TAPI_CALL_CAUSE_SIGNALING_ERROR_EV,                  
    TAPI_CALL_CAUSE_NETWORK_ERROR_EV,                    
    TAPI_CALL_CAUSE_NETWORK_BUSY_EV,                     
    TAPI_CALL_CAUSE_NOT_SUBSCRIBED_EV,                   
    TAPI_CALL_CAUSE_INCOMING_BARRED_IN_CUG_EV,           

    TAPI_CALL_CAUSE_SERVICE_UNAVAILABLE_EV,              
    TAPI_CALL_CAUSE_SERVICE_NOT_SUPPORTED_EV,            
    TAPI_CALL_CAUSE_PREPAY_LIMIT_REACHED_EV,             
    TAPI_CALL_CAUSE_USER_NOT_MEMBER_OF_CUG_EV,           
    TAPI_CALL_CAUSE_INCOMPATIBLE_DEST_EV,                
    TAPI_CALL_CAUSE_OUTSIDE_CALL_NOT_ALLOWED_EV,         
    TAPI_CALL_CAUSE_NO_CUG_SELECTED_EV,                  
    TAPI_CALL_CAUSE_UNKNOWN_CUG_INDEX_EV,                
    TAPI_CALL_CAUSE_CUG_INDEX_INCOMPAT_EV,               
    TAPI_CALL_CAUSE_CUG_FAIL_UNSPECIFIED_EV,             
    TAPI_CALL_CAUSE_WEAK_SIGNAL_EV,                      
    TAPI_CALL_CAUSE_RESTRICTED_LOCATION_EV,              
    TAPI_CALL_CAUSE_ACCESS_DENIED_EV,                    
    TAPI_CALL_CAUSE_SIGNAL_FADED_EV,                     
    TAPI_CALL_CAUSE_FEATURE_NOT_AVAILABLE_EV,            
    TAPI_CALL_CAUSE_WRONG_CALL_STATE_EV,                 
    TAPI_CALL_CAUSE_SIGNALING_TIMEOUT_EV,                
    TAPI_CALL_CAUSE_MAX_MPTY_PARTICIPANTS_EXCEEDED_EV,   
    TAPI_CALL_CAUSE_SYSTEM_FAILURE_EV,                   
    TAPI_CALL_CAUSE_DATA_MISSING_EV,                     
    TAPI_CALL_CAUSE_BASIC_SERVICE_NOT_PROVISIONED_EV,    
    TAPI_CALL_CAUSE_ILLEGAL_SS_OPERATION_EV,             
    TAPI_CALL_CAUSE_SS_INCOMPATIBILITY_EV,               
    TAPI_CALL_CAUSE_SS_NOT_AVAILABLE_EV,                 
    TAPI_CALL_CAUSE_SS_SUBSCRIPTION_VIOLATION_EV,        
    TAPI_CALL_CAUSE_INCORRECT_PASSWORD_EV,               
    TAPI_CALL_CAUSE_TOO_MANY_PASSWORD_ATTEMPTS_EV,       
    TAPI_CALL_CAUSE_PASSWORD_REGISTRATION_FAILURE_EV,    
    TAPI_CALL_CAUSE_ILLEGAL_EQUIPMENT_EV,                
    TAPI_CALL_CAUSE_UNKNOWN_SUBSCRIBER_EV,               
    TAPI_CALL_CAUSE_ILLEGAL_SUBSCRIBER_EV,               
    TAPI_CALL_CAUSE_ABSENT_SUBSCRIBER_EV,                
    TAPI_CALL_CAUSE_USSD_BUSY_EV,                        
    TAPI_CALL_CAUSE_UNKNOWN_ALPHABET_EV,                 
    TAPI_CALL_CAUSE_CANNOT_TRANSFER_MPTY_CALL_EV,        
    TAPI_CALL_CAUSE_BUSY_WITH_UNANSWERED_CALL_EV,        
    TAPI_CALL_CAUSE_FAILED_WITH_STATUS_EV,               
    TAPI_CALL_CAUSE_UNANSWERED_CALL_PENDING_EV,          
    TAPI_CALL_CAUSE_USSD_CANCELED_EV,                    
    TAPI_CALL_CAUSE_PRE_EMPTION_EV,                      
    TAPI_CALL_CAUSE_OPERATION_NOT_ALLOWED_EV,            
    TAPI_CALL_CAUSE_NO_FREE_BEARER_AVAILABLE_EV,         
    TAPI_CALL_CAUSE_NBR_SN_EXCEEDED_EV,                  
    TAPI_CALL_CAUSE_NBR_USER_EXCEEDED_EV,                
    TAPI_CALL_CAUSE_TIME_OUT,                                           
    TAPI_CALL_CAUSE_SWITCH_CONGESTION_EV,                
    TAPI_CALL_CAUSE_UNAUTHORIZED_B_CAP_EV,               
    TAPI_CALL_CAUSE_REQ_FACILITY_NOT_AVAIL_EV,           
    TAPI_CALL_CAUSE_INVALID_TRANSIT_NW_EV,               
    TAPI_CALL_CAUSE_NON_SELECTED_USR_CLRING_EV,          
    TAPI_CALL_CAUSE_RESPONSE_STATUS_ENQ_EV,              
    TAPI_CALL_CAUSE_NORMAL_UNSPECIFIED_EV,               
    TAPI_CALL_CAUSE_UNAVAIL_B_CAP_EV,                    
    TAPI_CALL_CAUSE_CHANNEL_UNACCEPTABLE_EV,             
    TAPI_CALL_CAUSE_NO_CIRCT_NO_CHANNEL_EV,              
    TAPI_CALL_CAUSE_INFO_DISCARDED_EV,                   
    TAPI_CALL_CAUSE_CHNL_UNAVAILABLE_EV,                 
    TAPI_CALL_CAUSE_SERVICE_QLTY_UNVAILABLE_EV,          
    TAPI_CALL_CAUSE_NOT_ALLOWED_BY_CC_EV,                
    TAPI_CALL_CAUSE_MODIFIED_TO_SS_BY_CC_EV,             
    TAPI_CALL_CAUSE_MODIFIED_TO_CALL_BY_CC_EV,           
    TAPI_CALL_CAUSE_CALL_MODIFIED_BY_CC_EV,              
    TAPI_CALL_CAUSE_POWER_DOWN_EV,                       
    TAPI_CALL_CAUSE_OPERATION_FAILED_EV                  

} TAPI_CALL_CAUSE_E;

typedef enum    _TAPI_CALL_DIR_E
{
    TAPI_CALL_DIR_OUTGOING_EV,                  
    TAPI_CALL_DIR_INCOMING_EV,                  
} TAPI_CALL_DIR_E;

typedef enum    _TAPI_CALL_STATUS_E
{
    TAPI_CALL_STATUS_IDLE_EV,                   
    TAPI_CALL_STATUS_RING_EV,                   

    TAPI_CALL_STATUS_WAITING_EV,                

    TAPI_CALL_STATUS_CONNECTING_EV,             
    TAPI_CALL_STATUS_MO_ALERTING_EV,            
    TAPI_CALL_STATUS_CONNECTED_EV,              
    TAPI_CALL_STATUS_HOLD_EV,                   
    TAPI_CALL_STATUS_PROCESSING_EV,             
} TAPI_CALL_STATUS_E;

typedef UINT8           TAPI_CALL_ID_T;

typedef TAPI_CALL_ID_T  TAPI_SESSION_ID_T;

typedef TAPI_CALL_ID_T  GPRS_CONTEXT_ID_T;

typedef struct  _TAPI_CALL_SESSION_S
{
    TAPI_CALL_ID_T              appCallId;      
    TAPI_CALL_SESSION_TYPE_E    callType;       
    TAPI_CALL_STATUS_E          status;         
    TAPI_PHONE_NUMBER_A         phoneNumber;    
    UINT8                       conference;     
    TAPI_CALL_DIR_E             dir;            
} TAPI_CALL_SESSION_S;

typedef struct  _TAPI_CALL_SESSION_TABLE_S
{
    INT32               number;                  
    TAPI_CALL_SESSION_S session[TAPI_CALL_MAX_CALL_NUMBER +
        TAPI_GPRS_MAX_PDP_CONTEXT_NUMBER];       
} TAPI_CALL_SESSION_TABLE_S;

#ifdef __cplusplus
}

#endif
#endif 
