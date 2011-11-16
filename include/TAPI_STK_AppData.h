

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_STK_APP_MSG_DEF_H
#define TAPI_STK_APP_MSG_DEF_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_AppMsgId.h"
#include "TAPI_General.h"
#include "TAPI_SIM_FileClient.h"

#define TAPI_STK_APPMSG_MAX_LEN          1620

#define TAPI_STK_BUFFER_MAX_LEN_BYTES    640

#define TAPI_STK_MAX_ROOT_MENU_LEN       1000

#define     TAPI_TIME_UNIT_MINUTES       0x00
#define     TAPI_TIME_UNIT_SECONDS       0x01
#define     TAPI_TIME_UNIT_DECISECONDS   0x02

#define TAPI_STK_MAX_NUM_REFRESH_FILES 60

enum _TAPI_STK_TONE_TYPE_E
{
    TAPI_STK_TONE_DIAL_EV           = 0x01,
    TAPI_STK_TONE_CALLED_BUSY_EV    = 0x02,
    TAPI_STK_TONE_CONGESTION_EV     = 0x03,
    TAPI_STK_TONE_RADIO_PATH_ACK_EV = 0x04,
    TAPI_STK_TONE_CALL_DROP_EV      = 0x05,
    TAPI_STK_TONE_ERROR_EV          = 0x06,
    TAPI_STK_TONE_CALL_WAITING_EV   = 0x07,
    TAPI_STK_TONE_RING_EV           = 0x08,
    TAPI_STK_TONE_GENERAL_BEEP_EV   = 0x10,
    TAPI_STK_TONE_CONFIRM_EV        = 0x11,
    TAPI_STK_TONE_NEGATE_EV         = 0x12,
    TAPI_STK_TONE_USER_DEFINE_CALL  = 0x13,
    TAPI_STK_TONE_USER_DEFINE_SMS   = 0x14
};

typedef UINT8   TAPI_STK_TONE_TYPE_E;

typedef enum    _TAPI_STK_ICON_EXPLANATORY_E
{
    TAPI_STK_ICON_EXPLANATORY_SELF_EV   = 0x00,
    TAPI_STK_ICON_EXPLANATORY_NONE_EV   = 0x01,
} TAPI_STK_ICON_EXPLANATORY_E;

typedef enum    _TAPI_STK_TEXT_PRIORITY_E
{
    TAPI_STK_TEXT_PRIORITY_NORMAL_EV    = 0x00,
    TAPI_STK_TEXT_PRIORITY_HIGH_EV      = 0x01
} TAPI_STK_TEXT_PRIORITY_E;

typedef enum    _TAPI_STK_TEXT_CLEAR_E
{
    TAPI_STK_TEXT_CLEAR_AUTO_EV         = 0x00,
    TAPI_STK_TEXT_CLEAR_MANUAL_EV       = 0x01
} TAPI_STK_TEXT_CLEAR_E;

typedef enum    _TAPI_STK_INKEY_E
{
    TAPI_STK_INKEY_YES_NO_EV            = 0x00,
    TAPI_STK_INKEY_DIGITS_EV            = 0x01,
    TAPI_STK_INKEY_SMS_ALPHA_EV         = 0x02,
    TAPI_STK_INKEY_UCS2_ALPHA_EV        = 0x03,
    TAPI_STK_INKEY_IMMEDIATE_DIGIT      = 0x04
} TAPI_STK_INKEY_E;

typedef enum    _TAPI_STK_INPUT_E
{
    TAPI_STK_INPUT_DIGITS_EV            = 0x00,
    TAPI_STK_INPUT_SMS_ALPHA_EV         = 0x01,
    TAPI_STK_INPUT_UCS2_ALPHA_EV        = 0x02
} TAPI_STK_INPUT_E;

typedef enum    _TAPI_STK_SELECTION_PREFERENCE_E
{
    TAPI_STK_SELECTION_PREFERENCE_NONE_EV   = 0x00,
    TAPI_STK_SELECTION_PREFERENCE_SOFTKEY_EV= 0x01
} TAPI_STK_SELECTION_PREFERENCE_E;

typedef enum    _TAPI_STK_PRESENTATION_E
{
    TAPI_STK_PRESENTATION_NONE_EV               = 0x00,
    TAPI_STK_PRESENTATION_DATA_VALUE_CHOICE_EV  = 0x01,
    TAPI_STK_PRESENTATION_NAVIGATION_CHOICE_EV  = 0x02
} TAPI_STK_PRESENTATION_E;

typedef enum    _TAPI_STK_CALL_E
{
    TAPI_STK_CALL_NORAML_EV                     = 0x00,
    TAPI_STK_CALL_NORAML_REDIAL_EV              = 0x01,
    TAPI_STK_CALL_HOLD_OTHERS_EV                = 0x02,
    TAPI_STK_CALL_HOLD_OTHERS_REDIAL_EV         = 0x03,
    TAPI_STK_CALL_DISCONNECT_OTHERS_EV          = 0x04,
    TAPI_STK_CALL_DISCONNECT_OTHERS_REDIAL_EV   = 0x05
} TAPI_STK_CALL_E;

typedef enum    _TAPI_STK_LB_SUBCMD_E
{
    TAPI_STK_LB_SUBCMD_IF_NOT_LAUNCHED_EV       = 0x00,
    TAPI_STK_LB_SUBCMD_USE_EXISTING_SESSION_EV  = 0x02,
    TAPI_STK_LB_SUBCMD_CLOSE_AND_LAUNCH_NEW_EV  = 0x03
} TAPI_STK_LB_SUBCMD_E;

enum _TAPI_STK_BEARER_E
{
    TAPI_STK_BEARER_SMS_EV                      = 0x00,
    TAPI_STK_BEARER_CSD_EV                      = 0x01,
    TAPI_STK_BEARER_USSD_EV                     = 0x02,
    TAPI_STK_BEARER_GPRS_EV                     = 0x03,
};
typedef UINT8   TAPI_STK_BEARER_E;

typedef enum    _TAPI_STK_RETVALUE_E
{
    TAPI_STK_RETVALUE_PERFORMED_SUCC_EV                 = 0x00, 
    TAPI_STK_RETVALUE_PERFORMED_PARTIAL_COMPREHENSION_EV= 0x01,
    TAPI_STK_RETVALUE_PERFORMED_MISSING_INFO_EV         = 0x02,
    TAPI_STK_RETVALUE_REFRESH_ADDITIONAL_EFS_READ_EV    = 0x03,
    TAPI_STK_RETVALUE_PERFORMED_SUCC_ICON_FAIL_EV       = 0x04, 
    TAPI_STK_RETVALUE_PERFORMED_MODIFY_BY_CC_BY_SIM_EV  = 0x05,
    TAPI_STK_RETVALUE_PERFORMED_LIMTED_SERVICE_EV       = 0x06,
    TAPI_STK_RETVALUE_USER_TEMINATE_SESSION_EV          = 0x10,
    TAPI_STK_RETVALUE_MOVE_BACKWARD_EV                  = 0x11, 

    TAPI_STK_RETVALUE_NO_RSP_FROM_USER_EV               = 0x12, 

    TAPI_STK_RETVALUE_REQUIRE_HELP_INFO_EV              = 0x13, 
    TAPI_STK_RETVALUE_USER_TERMINATE_SS_EV              = 0x14, 
    TAPI_STK_RETVALUE_ME_UNABLE_PROCESS_EV              = 0x20, 
    TAPI_STK_RETVALUE_NETWORK_UNABLE_PROCESS_EV         = 0x21, 
    TAPI_STK_RETVALUE_USER_REFUSE_COMMAND_EV            = 0x22, 
    TAPI_STK_RETVALUE_USER_CLEAR_DOWN_EV                = 0x23, 
    TAPI_STK_RETVALUE_SIM_CC_TEMP_PROBLEM_EV            = 0x25,
    TAPI_STK_RETVALUE_LAUNCH_BROWSER_ERROR_EV           = 0x26,
    TAPI_STK_RETVALUE_BEYOND_ME_CAPABILITIES_EV         = 0x30, 
    TAPI_STK_RETVALUE_COMMAND_TYPE_NOT_UNDERSTOOD_EV    = 0x31, 
    TAPI_STK_RETVALUE_COMMAND_DATA_NOT_UNDERSTOOD_EV    = 0x32, 
    TAPI_STK_RETVALUE_COMMAND_NUMBER_UNKNOWN_EV         = 0x33, 
    TAPI_STK_RETVALUE_SS_RETURN_ERROR_EV                = 0x34, 
    TAPI_STK_RETVALUE_SMS_RPERROR_EV                    = 0x35,
    TAPI_STK_RETVALUE_MISSING_REQUIRED_VALUE_EV         = 0x36, 
    TAPI_STK_RETVALUE_USSD_RETURN_ERROR_EV              = 0x37, 
    TAPI_STK_RETVALUE_SIM_CC_PERMANENT_PROBLEM_EV       = 0x39
} TAPI_STK_RETVALUE_E;

typedef enum    _TAPI_STK_RETVALUE_ADDITIONAL_ME_PROBLEM_E
{
    TAPI_STK_RETVALUE_ADDITIONAL_NO_SPECIFIED_CAUSE_EV      = 0x00,
    TAPI_STK_RETVALUE_ADDITIONAL_SREEN_BUSY_EV              = 0x01,
    TAPI_STK_RETVALUE_ADDITIONAL_ME_BUSY_ON_CALL_EV         = 0x02,
    TAPI_STK_RETVALUE_ADDITIONAL_ME_BUSY_ON_SS_EV           = 0x03,
    TAPI_STK_RETVALUE_ADDITIONAL_NO_SERVICE_EV              = 0x04,
    TAPI_STK_RETVALUE_ADDITIONAL_ACCESS_CONTROL_BAR_EV      = 0x05,
    TAPI_STK_RETVALUE_ADDITIONAL_RADIO_RESOURCE_NOT_GRANT_EV= 0x06,
    TAPI_STK_RETVALUE_ADDITIONAL_NOT_IN_SPEECH_CALL_EV      = 0x07,
    TAPI_STK_RETVALUE_ADDITIONAL_ME_BUSY_ON_USSD_EV         = 0x08,
    TAPI_STK_RETVALUE_ADDITIONAL_ME_BUSY_ON_SEND_DTMF_EV    = 0x09
} TAPI_STK_RETVALUE_ADDITIONAL_ME_PROBLEM_E;

typedef enum    _TAPI_STK_RETVALUE_ADDITIONAL_BROWSER_PROBLEM_E
{
    TAPI_STK_RETVALUE_ADDITIONAL_BROWSER_NO_SPECIFIED_CAUSE_EV          = 0x00,
    TAPI_STK_RETVALUE_ADDITIONAL_BROWSER_BEARER_UNAVAILABLE_EV          = 0x01,
    TAPI_STK_RETVALUE_ADDITIONAL_BROWSER_UNAVAILABLE_EV                 = 0x02,
    TAPI_STK_RETVALUE_ADDITIONAL_BROWSER_UNABLE_READ_PROVISION_DATA_EV  = 0x03
} TAPI_STK_RETVALUE_ADDITIONAL_BROWSER_PROBLEM_E;

typedef enum    _TAPI_STK_USER_CONFIRMATION_E
{
    TAPI_STK_USER_OK_EV                    = 0,
    TAPI_STK_USER_CANCEL_EV,
    TAPI_STK_USER_END_SESSION_EV,
    TAPI_STK_USER_PROCESS_ERROR_EV
} TAPI_STK_USER_CONFIRMATION_E;

typedef enum    _TAPI_STK_BUILD_CHANNEL_RESULT_E
{
    TAPI_STK_BUILD_CHANNEL_SUCCESS_EV      = 0,    
    TAPI_STK_BUILD_CHANNEL_FAILURE_EV              
} TAPI_STK_BUILD_CHANNEL_RESULT_E;

typedef enum    _TAPI_STK_PROXY_STATE_E
{
    TAPI_STK_PROXY_STATE_IND_ACTIVE_EV     = 0,    
    TAPI_STK_PROXY_STATE_IND_INACTIVE_EV,          
    TAPI_STK_PROXY_STATE_IND_FAILED_EV             
} TAPI_STK_PROXY_STATE_E;

typedef enum    _TAPI_STK_BUFFER_STATE_E
{
    TAPI_STK_BUFFER_SEND_READY_EV         = 0,    
    TAPI_STK_BUFFER_SEND_WAITING_EV,              
    TAPI_STK_BUFFER_RECV_DATA_EV                  
} TAPI_STK_BUFFER_STATE_E;

typedef enum    _TAPI_STK_CLASS_E_CMD_ID_E
{
    TAPI_STK_CLASS_E_SHOW_MSG_EV,       
    TAPI_STK_CLASS_E_CREATE_SET_EV,     
    TAPI_STK_CLASS_E_ACT_PROXY_EV,      
    TAPI_STK_CLASS_E_DESTROY_PROXY_EV,  
    TAPI_STK_CLASS_E_GET_PROXY_ATTR_EV, 
    TAPI_STK_CLASS_E_SEND_DATA_EV,      
    TAPI_STK_CLASS_E_PROXY_STATUS_EV,   
    TAPI_STK_CLASS_E_USER_RESULT_EV,    
    TAPI_STK_CLASS_E_BUFFER_STATUS_EV,  
    TAPI_STK_CLASS_E_UNKNOWN_EV         
} TAPI_STK_CLASS_E_CMD_ID_E;

enum _TAPI_STK_BROWSER_TERMINATION_CAUSE_E
{
    TAPI_STK_BROWSER_TERMINATION_BY_USER_EV     = 0x00,
    TAPI_STK_BROWSER_TERMINATION_BY_ERROR_EV
};
typedef UINT8   TAPI_STK_BROWSER_TERMINATION_CAUSE_E;

typedef enum _TAPI_STK_MO_SMS_CONTROL_E
{
    TAPI_STK_MO_SMS_ALLOWED_WITHOUT_MODIFICATION_EV,
    TAPI_STK_MO_SMS_NOT_ALLOWED_EV,
    TAPI_STK_MO_SMS_ALLOWED_WITH_MODIFICATION_EV
}TAPI_STK_MO_SMS_CONTROL_E;

enum _TAPI_STK_REFERSH_TYPE_E
{
    TAPI_STK_REFERSH_TYPE_FULL = 0, 

    TAPI_STK_REFERSH_TYPE_FILE,     

    TAPI_STK_REFERSH_TYPE_I_F,      

    TAPI_STK_REFERSH_TYPE_INIT,     

    TAPI_STK_REFERSH_TYPE_RESET,    

    TAPI_STK_REFERSH_TYPE_USIM_APP, 

    TAPI_STK_REFERSH_TYPE_RESET_3G  

};
typedef UINT8 TAPI_STK_REFERSH_TYPE_E;

typedef struct  _TAPI_STK_ICON_ID_S
{
    TAPI_STK_ICON_EXPLANATORY_E iconQualifier;
    UINT8                   iconId;
}  TAPI_STK_ICON_ID_S;

typedef struct  _TAPI_STK_RSP_LENGTH_S
{
    UINT8   minResponseLength;  
    UINT8   maxResponseLength;  
}  TAPI_STK_RSP_LENGTH_S;

typedef struct  _TAPI_STK_DURATION_S
{ 
    UINT8   timeUnit;           
    UINT8   timeInterval;
}  TAPI_STK_DURATION_S;

typedef struct  _TAPI_STK_MENU_ITEM_S
{
    UINT8       itemId;
    UINT16      itemTextLength; 
    W_CHAR*     pItemText;
}  TAPI_STK_MENU_ITEM_S;

typedef struct  _TAPI_STK_ICON_ID_LIST_S
{
    TAPI_STK_ICON_EXPLANATORY_E iconIdListQualifier;
    UINT8*                  pIconIdList;    
}  TAPI_STK_ICON_ID_LIST_S;

typedef struct  _TAPI_STK_PROVISION_FILE_REF_S
{
    UINT16  lenProvFileRef; 
    UINT8*  pProvFileRef;
}  TAPI_STK_PROVISION_FILE_REF_S;

typedef struct  _TAPI_STK_NOTIFY_DISPLAY_TEXT_MSG_S
{
    TAPI_APP_MSGID_T            msgId;

    TAPI_STK_TEXT_PRIORITY_E    priority;       
    TAPI_STK_TEXT_CLEAR_E       clearmode;      
    UINT16                      textStringLength; 
    W_CHAR*                     pTextString;    
    TAPI_STK_DURATION_S         duration;       

    BOOLEAN                     bIconIdPresent; 
    TAPI_STK_ICON_ID_S          iconId;         
    BOOLEAN                     bImmediateResponse; 
}  TAPI_STK_NOTIFY_DISPLAY_TEXT_MSG_S;

typedef struct  _TAPI_STK_NOTIFY_GET_INKEY_MSG_S
{
    TAPI_APP_MSGID_T    msgId;

    TAPI_STK_INKEY_E    inkeyType;          
    BOOLEAN             bHelpAvailable;     
    UINT16              textStringLength;   
    W_CHAR*             pTextString;        
    TAPI_STK_DURATION_S duration;           
    BOOLEAN             bIconIdPresent;     
    TAPI_STK_ICON_ID_S  iconId;             
}  TAPI_STK_NOTIFY_GET_INKEY_MSG_S;

typedef struct  _TAPI_STK_NOTIFY_GET_INPUT_MSG_S
{
    TAPI_APP_MSGID_T        msgId;

    TAPI_STK_INPUT_E        inputType;              
    BOOLEAN                 bEchoInput;             
    BOOLEAN                 bHelpAvailable;         
    UINT16                  textStringLength;       
    W_CHAR*                 pTextString;            
    TAPI_STK_RSP_LENGTH_S   responseLength;         
    BOOLEAN                 bDefaultTextPresent;    
    UINT16                  defaultTextLength;      
    W_CHAR*                 pDefaultText;           
    TAPI_STK_DURATION_S     duration;               

    BOOLEAN                 bIconIdPresent;         
    TAPI_STK_ICON_ID_S      iconId;                 
}  TAPI_STK_NOTIFY_GET_INPUT_MSG_S;

typedef struct  _TAPI_STK_NOTIFY_PLAY_TONE_MSG_S
{
    TAPI_APP_MSGID_T        msgId;

    BOOLEAN                 bAlphaIdPresent;    
    UINT16                  alphaIdLength;      
    W_CHAR*                 pAlphaId;           
    BOOLEAN                 bTonePresent;       
    TAPI_STK_TONE_TYPE_E    tone;               
    BOOLEAN                 bDurationPresent;   
    TAPI_STK_DURATION_S     duration;           
    BOOLEAN                 bIconIdPresent;     
    TAPI_STK_ICON_ID_S      iconId;             
}  TAPI_STK_NOTIFY_PLAY_TONE_MSG_S;

typedef struct  _TAPI_STK_NOTIFY_SETUP_MENU_MSG_S
{
    TAPI_APP_MSGID_T                msgId;

    TAPI_STK_SELECTION_PREFERENCE_E selectPrefer;
    BOOLEAN                 bHelpAvailable;

    UINT16                  alphaIdLength;  
    W_CHAR*                 pAlphaId;       
    UINT8                   itemNum;        
    TAPI_STK_MENU_ITEM_S*   pItemList;      
    BOOLEAN                 bIconIdPresent; 
    TAPI_STK_ICON_ID_S      iconId;         
    BOOLEAN                 bIconIdListPresent;     
    TAPI_STK_ICON_ID_LIST_S iconIdList;             
}  TAPI_STK_NOTIFY_SETUP_MENU_MSG_S;

typedef struct  _TAPI_STK_NOTIFY_SELECT_ITEM_MSG_S
{
    TAPI_APP_MSGID_T                msgId;

    TAPI_STK_PRESENTATION_E         presentType;
    TAPI_STK_SELECTION_PREFERENCE_E selectPrefer;
    BOOLEAN                 bHelpAvailable;

    BOOLEAN                 bAlphaIdPresent;        
    UINT16                  alphaIdLength;          
    W_CHAR*                 pAlphaId;               
    UINT8                   itemNum;                
    TAPI_STK_MENU_ITEM_S*   pItemList;              
    BOOLEAN                 bItemIdChosenPresent;   
    UINT8                   itemIdChosen;           
    TAPI_STK_DURATION_S     duration;               

    BOOLEAN                 bIconIdPresent;         
    TAPI_STK_ICON_ID_S      iconId;                 
    BOOLEAN                 bIconIdListPresent;     
    TAPI_STK_ICON_ID_LIST_S iconIdList;             
}  TAPI_STK_NOTIFY_SELECT_ITEM_MSG_S;

typedef struct  _TAPI_STK_NOTIFY_SEND_SMS_MSG_S
{
    TAPI_APP_MSGID_T    msgId;

    BOOLEAN             bAlphaIdPresent;        
    UINT16              alphaIdLength;          
    W_CHAR*             pAlphaId;               
    BOOLEAN             bIconIdPresent;         
    TAPI_STK_ICON_ID_S  iconId;                 
}  TAPI_STK_NOTIFY_SEND_SMS_MSG_S;

typedef struct  _TAPI_STK_NOTIFY_SEND_SS_MSG_S
{
    TAPI_APP_MSGID_T    msgId;

    BOOLEAN             bAlphaIdPresent;    
    UINT16              alphaIdLength;      
    W_CHAR*             pAlphaId;           
    UINT16              ssStringLength;     
    UINT8*              pSsString;          
    UINT8               ton;                
    UINT8               npi;
    BOOLEAN             bIconIdPresent;     
    TAPI_STK_ICON_ID_S  iconId;             
}  TAPI_STK_NOTIFY_SEND_SS_MSG_S;

typedef struct  _TAPI_STK_NOTIFY_SEND_USSD_MSG_S
{
    TAPI_APP_MSGID_T    msgId;

    BOOLEAN             bAlphaIdPresent;    
    UINT16              alphaIdLength;      
    W_CHAR*             pAlphaId;           
    UINT8               dcs;                
    UINT16              ussdStringLength;   
    UINT8*              pUssdString;        
    BOOLEAN             bIconIdPresent;     
    TAPI_STK_ICON_ID_S  iconId;             
}  TAPI_STK_NOTIFY_SEND_USSD_MSG_S;

typedef struct _TAPI_STK_NOTIFY_IDLE_MODE_TEXT_S
{
    TAPI_APP_MSGID_T msgId;

    UINT16 textStringLength;
    W_CHAR *pTextString;

    BOOLEAN bIconIdPresent;
    TAPI_STK_ICON_ID_S iconId;
}  TAPI_STK_NOTIFY_IDLE_MODE_TEXT_S;

typedef struct _TAPI_STK_NOTIFY_RUNAT_START_ALPHA_MSG_S
{
    TAPI_APP_MSGID_T msgId;

    UINT16 AlphaIDLength;
    W_CHAR *pAlphaID;

    BOOLEAN bIconIdPresent;
    TAPI_STK_ICON_ID_S iconId;
}  TAPI_STK_NOTIFY_RUNAT_START_ALPHA_MSG_S;

typedef struct  _TAPI_STK_NOTIFY_SETUP_CALL_MSG_S
{
    TAPI_APP_MSGID_T    msgId;

    TAPI_STK_CALL_E     callType;               
    BOOLEAN             bAlphaIdConfirmPresent; 

    UINT16              alphaIdConfirmLength;   
    W_CHAR*             pAlphaIdConfirm;        
    UINT16              addressLength;          
    UINT8*              pAddress;               

    BOOLEAN             bSubAddressPresent;     
    UINT16              subAddressLength;       
    UINT8*              pSubAddress;            
    BOOLEAN             bDurationPresent;       
    TAPI_STK_DURATION_S duration;               
    BOOLEAN             bIconIdConfirmPresent;  

    TAPI_STK_ICON_ID_S  iconIdConfirm;          
    BOOLEAN             bAlphaIdSetupPresent;   

    UINT16              alphaIdSetupLength;     
    W_CHAR*             pAlphaIdSetup;          
    BOOLEAN             bIconIdSetupPresent;    

    TAPI_STK_ICON_ID_S  iconIdSetup;            
}  TAPI_STK_NOTIFY_SETUP_CALL_MSG_S;

typedef struct  _TAPI_STK_NOTIFY_REFRESH_MSG_S
{
    TAPI_APP_MSGID_T          msgId;
    BOOLEAN                   bReset;
    TAPI_STK_REFERSH_TYPE_E   refresh_type; 

    UINT8                     num_refresh_files;

    TAPI_SIM_FILE_E           files_to_refresh[ TAPI_STK_MAX_NUM_REFRESH_FILES ] ; 
}  TAPI_STK_NOTIFY_REFRESH_MSG_S;

typedef TAPI_STK_NOTIFY_REFRESH_MSG_S TAPI_STK_NOTIFY_REFRESH_END_MSG_S;

typedef struct _TAPI_STK_NOTIFY_LANGUAGE_MSG_S
{
    TAPI_APP_MSGID_T msgId;
    BOOLEAN bLanguagePresent;
    UINT16 language;
}  TAPI_STK_NOTIFY_LANGUAGE_MSG_S;

typedef struct  _TAPI_STK_NOTIFY_USER_ACTIVITY_REQ_MSG_S
{
    TAPI_APP_MSGID_T    msgId;
}  TAPI_STK_NOTIFY_USER_ACTIVITY_REQ_MSG_S;

typedef TAPI_STK_NOTIFY_USER_ACTIVITY_REQ_MSG_S   TAPI_STK_NOTIFY_BROWSER_TERMINATION_CAUSE_REQ_MSG_S;

typedef TAPI_STK_NOTIFY_USER_ACTIVITY_REQ_MSG_S   TAPI_STK_NOTIFY_IDLE_SCREEN_AVAILABLE_REQ_MSG_S;

typedef TAPI_STK_NOTIFY_SETUP_MENU_MSG_S    TAPI_STK_NOTIFY_INIT_ROOT_MENU_MSG_S;

typedef struct  _TAPI_STK_NOTIFY_LAUNCH_BROWSER_MSG_S
{
    TAPI_APP_MSGID_T        msgId;
    TAPI_STK_LB_SUBCMD_E    launchBrowserSubCmd;    
    UINT8                   urlLength;              
    UINT8*                  pURL;                   
    BOOLEAN                 bAlphaIdPresent;        

    UINT16                  alphaIdLength;          
    W_CHAR*                 pAlphaId;               
    BOOLEAN                 bIconIdPresent;         

    TAPI_STK_ICON_ID_S      iconId;                 
    UINT8                   bearerListLength;       
    TAPI_STK_BEARER_E*      bearerList;             
    UINT8                   gwProxyLength;          
    W_CHAR*                 pGwProxy;               
    UINT8                   provFileRefNum;         
    TAPI_STK_PROVISION_FILE_REF_S*  pProvFileRefList;    
}  TAPI_STK_NOTIFY_LAUNCH_BROWSER_MSG_S;

typedef struct _TAPI_STK_NOTIFY_MO_SMS_CONTROL_MSG_S
{
   TAPI_STK_MO_SMS_CONTROL_E result;

   BOOLEAN bAlphaIdPresent;
   UINT16 alphaIdLength;
   TAPI_STK_ALPHAID_A alphaId;
}  TAPI_STK_NOTIFY_MO_SMS_CONTROL_MSG_S;

typedef struct  _TAPI_STK_RSP_APP_RESPONSE_MSG_S
{
    TAPI_STK_RETVALUE_E result;                 
    UINT8               additionalResultLength; 
    UINT8*              pAdditionalResult;      
    UINT8               itemIdChosen;           
    BOOLEAN             bHelpRequest;           
    UINT16              inputLength;            
    W_CHAR*             pInput;                 
    BOOLEAN             bCallControlModify;         
    TAPI_STK_RETVALUE_E result2;                    
    UINT8               additionalResult2Length;    
    UINT8*              pAdditionalResult2;         
    TAPI_STK_DURATION_S duration;                   
}  TAPI_STK_RSP_APP_RESPONSE_MSG_S;

typedef struct  _TAPI_STK_NOTIFY_SEND_DTMF_START_MSG_S
{
    TAPI_APP_MSGID_T    msgId;
    UINT16              lenAlphaId;         
    W_CHAR*             pAlphaId;           
    BOOLEAN             bIconPresent;       
    TAPI_STK_ICON_ID_S  iconId;             
}  TAPI_STK_NOTIFY_SEND_DTMF_START_MSG_S;

typedef struct  _TAPI_STK_NOTIFY_SEND_DTMF_STOP_MSG_S
{
    TAPI_APP_MSGID_T    msgId;
}  TAPI_STK_NOTIFY_SEND_DTMF_STOP_MSG_S;

typedef struct  _TAPI_STK_NOTIFY_DISPLAY_ALPHA_ID_MSG_S
{
    TAPI_APP_MSGID_T    msgId;
    UINT8               cmdId;              

    BOOLEAN             bAlphaIdPresent;    
    UINT16              alphaIdLength;      
    W_CHAR*             pAlphaId;           
}  TAPI_STK_NOTIFY_DISPLAY_ALPHA_ID_MSG_S;

typedef struct  _TAPI_STK_NOTIFY_CREATE_SET_MSG_S
{
    TAPI_APP_MSGID_T    msgId;
    UINT16              dataLen;            
    UINT8*              pChannelData;       
}  TAPI_STK_NOTIFY_CREATE_SET_MSG_S;

typedef struct  _TAPI_STK_NOTIFY_ACTIVATE_DESTORY_PROXY_MSG_S
{
    TAPI_APP_MSGID_T    msgId;
    UINT8               proxyId;
}  TAPI_STK_NOTIFY_ACTIVATE_DESTORY_PROXY_MSG_S;

typedef struct  _TAPI_STK_NOTIFY_SEND_DATA_MSG_S
{
    TAPI_APP_MSGID_T    msgId;
    UINT16              dataLen;            
    UINT8               proxyId;
    UINT8*              pChannelData;       
}  TAPI_STK_NOTIFY_SEND_DATA_MSG_S;

typedef struct _TAPI_STK_RSP_CLASS_E_APP_MSG_S
{
    TAPI_STK_USER_CONFIRMATION_E    result;
    UINT8   proxyId;
    TAPI_STK_BUILD_CHANNEL_RESULT_E buildResult;
    TAPI_STK_PROXY_STATE_E          currentChannelStatus;   
    TAPI_STK_BUFFER_STATE_E         bufferStatus;           
    TAPI_STK_CLASS_E_CMD_ID_E       cmdId;                  
    UINT16  sentDataLength;                                 
    UINT16  channelDataLength;                              
    UINT8*  pChannelData;                                   
}  TAPI_STK_RSP_CLASS_E_APP_MSG_S;

typedef struct  _TAPI_STK_TERMINAL_RESPONSE_MSG_S
{
    TAPI_STK_RETVALUE_E result;                      
    UINT8               additionalResultLength;      
    UINT8               itemIdChosen;                
    BOOLEAN             bHelpRequest;                
    UINT16              inputLength;                 
    BOOLEAN             bCallControlModify;          
    TAPI_STK_RETVALUE_E result2;                     
    UINT8               additionalResult2Length;     
    TAPI_STK_DURATION_S duration;                    
    UINT8               buffer[TAPI_STK_BUFFER_MAX_LEN_BYTES];   
}  TAPI_STK_TERMINAL_RESPONSE_MSG_S;

#ifdef __cplusplus
}
#endif 

#endif  

