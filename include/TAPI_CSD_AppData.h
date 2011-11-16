

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef _TAPI_CSD_APPDATA_H 
#define _TAPI_CSD_APPDATA_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_Result.h"
#include "TAPI_CALL_General.h"
#include "TAPI_SETUP_General.h"

#define  TAPI_CSD_MAX_RLP_NUMBER    16

typedef enum    _TAPI_CALL_DATA_RATE_E
{
    TAPI_CALL_DATA_RATE_AUTO_BAUD_EV    = 0,    
    TAPI_CALL_DATA_RATE_300_V22_EV      = 1,    
    TAPI_CALL_DATA_RATE_1200_V22_EV     = 2,    
    TAPI_CALL_DATA_RATE_1200_75_V23_EV  = 3,    
    TAPI_CALL_DATA_RATE_2400_V22_EV     = 4,    
    TAPI_CALL_DATA_RATE_2400_V26_EV     = 5,    
    TAPI_CALL_DATA_RATE_4800_V32_EV     = 6,    
    TAPI_CALL_DATA_RATE_9600_V32_EV     = 7,    
    TAPI_CALL_DATA_RATE_9600_V34_EV     = 12,   
    TAPI_CALL_DATA_RATE_14400_V34_EV    = 14,   
    TAPI_CALL_DATA_RATE_19200_V34_EV    = 15,   
    TAPI_CALL_DATA_RATE_28800_V34_EV    = 16,   
    TAPI_CALL_DATA_RATE_1200_V120_EV    = 34,   
    TAPI_CALL_DATA_RATE_2400_V120_EV    = 36,   
    TAPI_CALL_DATA_RATE_4800_V120_EV    = 38,   
    TAPI_CALL_DATA_RATE_9600_V120_EV    = 39,   
    TAPI_CALL_DATA_RATE_14400_V120_EV   = 43,   
    TAPI_CALL_DATA_RATE_19200_V120_EV   = 47,   
    TAPI_CALL_DATA_RATE_28800_V120_EV   = 48,   
    TAPI_CALL_DATA_RATE_38400_V120_EV   = 49,   
    TAPI_CALL_DATA_RATE_48000_V120_EV   = 50,   
    TAPI_CALL_DATA_RATE_56000_V120_EV   = 51,   
    TAPI_CALL_DATA_RATE_2400_V110_EV    = 68,   
    TAPI_CALL_DATA_RATE_4800_V110_EV    = 70,   
    TAPI_CALL_DATA_RATE_9600_V110_EV    = 71,   
    TAPI_CALL_DATA_RATE_14400_V110_EV   = 75,   
    TAPI_CALL_DATA_RATE_56000_V110_EV   = 83,   
    TAPI_CALL_DATA_RATE_56000_EV        = 115,  
    TAPI_CALL_DATA_RATE_64000_EV        = 116,  
    TAPI_CALL_DATA_RATE_32000_PIAFS_EV  = 120,  
    TAPI_CALL_DATA_RATE_64000_PIAFS_EV  = 121,  
    TAPI_CALL_DATA_RATE_28800_MM_EV     = 130,  
    TAPI_CALL_DATA_RATE_32000_MM_EV     = 131,  
    TAPI_CALL_DATA_RATE_33600_MM_EV     = 132,  
    TAPI_CALL_DATA_RATE_56000_MM_EV     = 133,  
    TAPI_CALL_DATA_RATE_64000_MM_EV     = 134   
} TAPI_CALL_DATA_RATE_E;

typedef enum    _TAPI_CALL_DATA_DEST_TYPE_E
{
    TAPI_CALL_DATA_DEST_TYPE_ISDN_EV,           
    TAPI_CALL_DATA_DEST_TYPE_MODEM_EV           
} TAPI_CALL_DATA_DEST_TYPE_E;

typedef enum    _TAPI_CALL_CONNECTION_TYPE_E
{
    TAPI_CALL_CONNECTION_TRANSPARENT_EV                     = 0,    
    TAPI_CALL_CONNECTION_NONE_TRANSPARENT_EV                = 1,    
    TAPI_CALL_CONNECTION_BOTH_TRANSPARENT_PREFERRED_EV      = 2,    
    TAPI_CALL_CONNECTION_BOTH_NONE_TRANSPARENT_PREFERRED_EV = 3,    
} TAPI_CALL_CONNECTION_TYPE_E;

typedef enum    _TAPI_CALL_DATA_CIRCUIT_TYPE_E
{
    TAPI_CALL_GSM_DATA_CIRCUIT_ASYNC_EV                     = 0,    
    TAPI_CALL_GSM_DATA_CIRCUIT_SYNC_EV                      = 1,    
    TAPI_CALL_GSM_PAD_ACCESS_ASYNC_EV                       = 2,    
    TAPI_CALL_GSM_PACKET_ACCESS_SYNC_EV                     = 3,    
} TAPI_CALL_DATA_CIRCUIT_TYPE_E;

typedef enum    _TAPI_CALL_DATA_MODE_E
{
    TAPI_CALL_DATA_MODE_ASYNC_UDI_EV                        = 0,    
    TAPI_CALL_DATA_MODE_SYNC_UDI_EV                         = 1,    
    TAPI_CALL_DATA_MODE_PDA_ASYNC_UDI_EV                    = 2,    
    TAPI_CALL_DATA_MODE_PACKET_SYNC_UDI_EV                  = 3,    
    TAPI_CALL_DATA_MODE_ASYNC_RDI_EV                        = 4,    
    TAPI_CALL_DATA_MODE_SYNC_RDI_EV                         = 5,    
    TAPI_CALL_DATA_MODE_PDA_ASYNC_RDI_EV                    = 6,    
    TAPI_CALL_DATA_MODE_PACKET_SYNC_RDI_EV                  = 7,    
} TAPI_CALL_DATA_MODE_E;

typedef enum    _TAPI_FAX_ACTION_E
{
    TAPI_FAX_ACTION_DIAL_EV,    
    TAPI_FAX_ACTION_ANSWER_EV,  
    TAPI_FAX_ACTION_DROP_EV,    
    TAPI_FAX_ACTION_FTH_EV,     
    TAPI_FAX_ACTION_FRH_EV,     
    TAPI_FAX_ACTION_FTM_EV,     
    TAPI_FAX_ACTION_FRM_EV,     
} TAPI_FAX_ACTION_E;

typedef enum    _TAPI_CALL_FCLASS_E
{
    TAPI_CALL_FCLASS_CSD_EV                                 = 0,    
    TAPI_CALL_FCLASS_FAX_EV                                 = 1,    
} TAPI_CALL_FCLASS_E;

typedef struct  _TAPI_CALL_DATA_OPTION_S
{
    UINT8                       dataRate;       

    UINT8                       dataMode;       

    UINT8                       connectionType; 

    TAPI_CALL_DATA_DEST_TYPE_E  destType;       

} TAPI_CALL_DATA_OPTION_S;

typedef struct  _TAPI_CSD_NOTIFY_CONNECT_STATUS_MSG_S
{
    TAPI_CALL_ID_T  callId; 
    pid_t           pid;    
} TAPI_CSD_NOTIFY_CONNECT_STATUS_MSG_S;

typedef struct  _TAPI_CSD_NOTIFY_INCOMING_MSG_S
{
    TAPI_CALL_ID_T                  callId;         
    TAPI_PHONE_NUMBER_A             phoneNumber;    
    TAPI_CALL_DATA_CIRCUIT_TYPE_E   circuitType;    

    UINT8                           connectionType; 

    TAPI_PHONEBOOK_NAME_A           alpha;
} TAPI_CSD_NOTIFY_INCOMING_MSG_S;

typedef struct  _TAPI_CSD_NOTIFY_CALL_TYPE_MSG_S
{
    INT32               callType;       
    TAPI_PHONE_NUMBER_A phoneNumber;    
} TAPI_CSD_NOTIFY_CALL_TYPE_MSG_S;

typedef struct  _TAPI_CSD_NOTIFY_SERVICE_STATUS_MSG_S
{
    INT32   service;            
    INT32   cause;              
} TAPI_CSD_NOTIFY_SERVICE_STATUS_MSG_S;

typedef struct  _TAPI_CSD_NOTIFY_NETWORK_ERROR_STATUS_MSG_S
{
    TAPI_CALL_ID_T      callId;
    TAPI_RESULT_E       cause;  
    pid_t               pid;    
} TAPI_CSD_NOTIFY_NETWORK_ERROR_STATUS_MSG_S;

typedef struct  _TAPI_FAX_NOTIFY_ERROR_STATUS_MSG_S
{
    TAPI_FAX_ACTION_E   action; 
    TAPI_RESULT_E       cause;  
} TAPI_FAX_NOTIFY_ERROR_STATUS_MSG_S;

typedef struct  _TAPI_FAX_NOTIFY_CONNECTION_STATUS_MSG_S
{
    TAPI_CALL_ID_T      callId; 
    TAPI_FAX_ACTION_E   action; 
    pid_t               pid;    
} TAPI_FAX_NOTIFY_CONNECTION_STATUS_MSG_S;

typedef struct  _TAPI_CALL_DATA_NOTIFY_CALLING_MSG_S
{
    TAPI_CALL_ID_T      callId;         
    TAPI_PHONE_NUMBER_A phoneNumber;    
    pid_t               pid;            
} TAPI_CALL_DATA_NOTIFY_CALLING_MSG_S;

typedef struct  _TAPI_CALL_DATA_RLP_PARAM_S
{
    INT16   iws;
    INT16   mws;
    INT16   T1;
    INT16   N2;
    INT8    version;
    INT16   T4;
} TAPI_CALL_DATA_RLP_PARAM_S;

typedef struct  _TAPI_CRLP_READ_PARM_S
{
    UINT8   param_num;
    INT16   iws;
    INT16   mws;
    INT16   T1;
    INT16   N2;
    INT8    version;
    INT16   T4;
} __attribute__( (packed) )  TAPI_CRLP_READ_PARM_S;

typedef struct  _TAPI_CRLP_READ_PARM_LIST_S
{
    INT32                   number;                             
    TAPI_CRLP_READ_PARM_S   protocols[TAPI_CSD_MAX_RLP_NUMBER]; 
} __attribute__( (packed) )  TAPI_CRLP_READ_PARM_LIST_S;

#ifdef __cplusplus
}
#endif 

#endif  

