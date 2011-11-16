

// Copyright (c) 05-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifdef __cplusplus
extern "C" {
#endif

#ifndef TAPI_SIM_APDU_H
#define TAPI_SIM_APDU_H

#include "TAPI_SETUP_General.h"
#include "TAPI_SECURITY_Client.h"

#define TAPI_SIM_APDU_AID_MAX_LENGTH     16 

#define TAPI_SIM_APDU_COMMAND_MAX_LENGTH TAPI_SIM_APDU_COMMAND_MAX+6

#define TAPI_SIM_APDU_COMMAND_MAX 256

#define TAPI_SIM_APDU_COMMAND_RESPONSE_MAX 512

#define TAPI_SIM_APDU_ATR_MAX_SIZE       33

#define TAPI_SIM_APDU_LAST_WIM_ADF_INDEX  0xFC

#define TAPI_SIM_APDU_LAST_PKCS15_ADF_INDEX  0xFD

#define TAPI_SIM_APDU_INVALID_ADF_INDEX  0xFB

typedef enum                     
{
    TAPI_SIM_APDU_CARD_TYPE_UNKNOWN =0,  
    TAPI_SIM_APDU_CARD_TYPE_2G_SIM,      
    TAPI_SIM_APDU_CARD_TYPE_3G_UICC
} TAPI_SIM_APDU_CARD_TYPE_E;

typedef enum                     
{
    TAPI_SIM_APDU_SLOT_COLD_SWAPPABLE = 0,
    TAPI_SIM_APDU_SLOT_HOT_SWAPPABLE,
    TAPI_SIM_APDU_SLOT_UNKNOWN  
}TAPI_SIM_APDU_SLOT_TYPE_E;

typedef enum                     
{
    TAPI_SIM_APDU_PIN_OPERATION_SUCCESS=0,       
    TAPI_SIM_APDU_PIN_ERROR,
    TAPI_SIM_APDU_PIN_INCORRECT_PASSWORD,
    TAPI_SIM_APDU_PIN_ENABLED,                 
    TAPI_SIM_APDU_PIN_DISABLED,                
    TAPI_SIM_APDU_PIN_SIM_PUK_REQUIRED,
    TAPI_SIM_APDU_PIN_PERM_BLOCKED,            
    TAPI_SIM_APDU_PIN_BAD_CODE_ONE_TRY_LEFT,          
    TAPI_SIM_APDU_PIN_STATUS_VERIFIED          
}TAPI_SIM_APDU_PIN_STATUS_E;

typedef enum                     
{
    TAPI_SIM_SEND_APDU_RESULT_SUCCESS=0,
    TAPI_SIM_SEND_APDU_RESULT_SLOT_NOT_EXIST,                
    TAPI_SIM_SEND_APDU_RESULT_BUSY,
    TAPI_SIM_SEND_APDU_RESULT_CMD_IN_PROGRESS,
    TAPI_SIM_SEND_APDU_RESULT_ILLEGAL_ARGUMENT,
    TAPI_SIM_SEND_APDU_RESULT_FAIL
}TAPI_SIM_SEND_APDU_RESULT_E;

typedef enum                     
{
    TAPI_SIM_APDU_CONN_RESULT_UNKNOWN_APP=0,
    TAPI_SIM_APDU_CONN_RESULT_NO_AVAILABLE_CHANNELS,
    TAPI_SIM_APDU_CONN_RESULT_OPEN_CHANNEL_FAILED,
    TAPI_SIM_APDU_CONN_RESULT_SELECT_APP_FAILED,
    TAPI_SIM_APDU_CONN_RESULT_PIN_DATA_FAILED,
    TAPI_SIM_APDU_CONN_RESULT_CACHING_FAILED,
    TAPI_SIM_APDU_CONN_RESULT_SUCC,                               
    TAPI_SIM_APDU_CONN_RESULT_SLOT_NOT_EXIST,  
    TAPI_SIM_APDU_CONN_RESULT_FAIL
}TAPI_SIM_APDU_CONN_RESULT_E;

enum _TAPI_SIM_APDU_PIN_OP_TYPE_E                   
{
    TAPI_SIM_APDU_ENABLE_PIN=0,                 
    TAPI_SIM_APDU_DISABLE_PIN,                  
    TAPI_SIM_APDU_CHANGE_PIN,                   
    TAPI_SIM_APDU_UNBLOCK_PIN,                  
    TAPI_SIM_APDU_VERIFY_PIN,                   
    TAPI_SIM_APDU_DISABLE_PIN_W_REPLACEMENT                 
};    
typedef UINT8 TAPI_SIM_APDU_PIN_OP_TYPE_E;

typedef UINT8 TAPI_SIM_APDU_AID [TAPI_SIM_APDU_AID_MAX_LENGTH];

typedef struct
{ 
    UINT8 slotNumber;           
    TAPI_SIM_APDU_AID aid;   
    UINT8 aid_length;        
    UINT8 adf_index;  
} TAPI_SIM_APDU_OPEN_CONN_REQ_T;

typedef struct
{ 
    UINT8 slotNumber;                
    UINT8 channelNumber;   
    UINT8 adf_index;   
}TAPI_SIM_APDU_CLOSE_CONN_REQ_T;

typedef struct
{ 
    UINT8 slotNumber;
    UINT8 channelNumber;
    UINT8 keyReference;
    TAPI_PASSWORD_A oldPin;
    TAPI_PASSWORD_A newPin;
    TAPI_SIM_APDU_PIN_OP_TYPE_E pinOperation;    
}TAPI_SIM_APDU_MODIFY_PIN_REQ_T;

typedef struct
{ 
    UINT8 slotNumber;
    UINT32 c_size;
    UINT8 commandAPDU[TAPI_SIM_APDU_COMMAND_MAX_LENGTH];
}TAPI_SIM_APDU_SYNC_ASYNC_CMD_REQ_T;

typedef struct
{ 
    UINT32 r_size;
    UINT8 responseAPDU[TAPI_SIM_APDU_COMMAND_RESPONSE_MAX];
}TAPI_SIM_APDU_SYNC_ASYNC_CMD_CNF_T;

typedef struct
{ 
    UINT8 sw1;
    UINT8 sw2;
}TAPI_SIM_APDU_PIN_OPERATION_CNF_T;

typedef struct
{ 
    UINT8 length;
    UINT8 atr[TAPI_SIM_APDU_ATR_MAX_SIZE];
}TAPI_SIM_APDU_ATR_CNF_T;

typedef struct
{ 
    UINT16 responseSize;
    UINT8 responseApdu[TAPI_SIM_APDU_COMMAND_RESPONSE_MAX+8];
}TAPI_SIM_APDU_CMD_CNF_T;

TAPI_RESULT_E                                 
TAPI_SIM_APDU_OpenConnection(UINT8 slot, UINT8 *aid, UINT8 aid_len, UINT8 adf_index, UINT8* channelNumber, 
                             TAPI_SIM_APDU_CONN_RESULT_E * apdu_conn_result );

TAPI_RESULT_E                                 
TAPI_SIM_APDU_CloseConnection(UINT8 slot, UINT8 channelNumber, UINT8 adf_index, TAPI_SIM_APDU_CONN_RESULT_E *apdu_conn_result);

TAPI_RESULT_E   
TAPI_SIM_APDU_GetSlotCount(UINT8 *slot_cnt);

TAPI_RESULT_E   
TAPI_SIM_APDU_GetCardType(UINT8 slot, TAPI_SIM_APDU_CARD_TYPE_E* type);

TAPI_RESULT_E   
TAPI_SIM_APDU_GetSlotType(UINT8 slot, TAPI_SIM_APDU_SLOT_TYPE_E* type);

TAPI_RESULT_E   
TAPI_SIM_APDU_GetATR(UINT8 slot, UINT8 *atr, UINT8 *atr_size);

TAPI_RESULT_E
TAPI_SIM_APDU_ChangePin(UINT8 slot, UINT8 channelNumber, UINT8 keyReference, TAPI_PASSWORD_A oldPin, 
                        TAPI_PASSWORD_A newPin, UINT8 *sw1, UINT8 *sw2, TAPI_SIM_APDU_PIN_STATUS_E *apdu_pin_status);

TAPI_RESULT_E   
TAPI_SIM_APDU_UnblockPin(UINT8 slot, UINT8 channelNumber, UINT8 keyReference, TAPI_PASSWORD_A pukID, 
                         TAPI_PASSWORD_A pin, UINT8 *sw1, UINT8 *sw2, TAPI_SIM_APDU_PIN_STATUS_E *apdu_pin_status);

TAPI_RESULT_E 
TAPI_SIM_APDU_VerifyPin(UINT8 slot, UINT8 channelNumber, UINT8 keyReference, TAPI_PASSWORD_A pinID, 
                        UINT8 *sw1, UINT8 *sw2, TAPI_SIM_APDU_PIN_STATUS_E *apdu_pin_status);

TAPI_RESULT_E 
TAPI_SIM_APDU_SetPin(UINT8 slot, UINT8 channelNumber, UINT8 keyReference, BOOLEAN mode,  
                     TAPI_PASSWORD_A pin, UINT8 *sw1, UINT8 *sw2, TAPI_SIM_APDU_PIN_STATUS_E *apdu_pin_status);

TAPI_RESULT_E   
TAPI_SIM_APDU_SendSyncCmd(UINT8 slot, UINT8 *commandAPDU, UINT32 c_size, UINT8 *responseAPDU, UINT32 *r_size,
                          TAPI_SIM_SEND_APDU_RESULT_E *apdu_send_cmd_status);

TAPI_RESULT_E   
TAPI_SIM_APDU_SendAsyncCmd(UINT8 slot, UINT8 *commandAPDU, UINT32 c_size, 
                          UINT32 *apdu_send_cmd_status);

#endif  
#ifdef __cplusplus
}
#endif
