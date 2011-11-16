

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_GPRS_APPDATA_H 
#define TAPI_GPRS_APPDATA_H

#ifdef __cplusplus 
extern "C" {
#endif

#include <sys/types.h>
#include "TAPI_CALL_General.h"

#define TAPI_GPRS_MAX_NAME_LENGTH 100

#define TAPI_CALL_IP_ADDRESS_LENGTH    20

#define TAPI_GPRS_MODEM_CHANNEL      1

#define TAPI_GPRS_MOBILE_CHANNEL     2

#define  TAPI_EGPRS_ERROR_RATIO_LENGTH  8

#define IPV4_MAX_LENGTH 15

#define TAPI_GPRS_IP_ADDR_AND_MASK_LENGTH 128

#define TAPI_GPRS_PORT_RANGE_LENGTH 12

#define TAPI_GPRS_IPSEC_SPI_LENGTH 9

#define TAPI_GPRS_TOS_AND_MASK_LENGTH 8

#define TAPI_GPRS_FLOW_LABEL_LENGTH 6

typedef enum    _TAPI_GPRS_PROTOCOL_E
{
    TAPI_GPRS_PROTOCOL_IP_EV,   
    TAPI_GPRS_PROTOCOL_X25_EV   
} TAPI_GPRS_PROTOCOL_E;

enum _TAPI_GPRS_ATTACH_STATUS_E
{
    TAPI_GPRS_ATTACH_STATUS_DETACH_EV           = 0,    
    TAPI_GPRS_ATTACH_STATUS_ATTACH_EV,                  
    TAPI_GPRS_ATTACH_STATUS_COMBINE_ATTACH_EV,
};

typedef UINT8   TAPI_GPRS_ATTACH_STATUS_E;

typedef enum    _TAPI_CALL_GPRS_MENU_STATUS_E
{
    TAPI_CALL_GPRS_MENU_DISPLAY_EV              = 0,    
    TAPI_CALL_GPRS_MENU_DISAPPEAR_EV,                   
} TAPI_CALL_GPRS_MENU_STATUS_E;

typedef enum    _TAPI_GPRS_AUTH_PROTOCOL_E
{
    TAPI_GPRS_AUTH_PROTOCOL_PAP_EV              = 0,    
    TAPI_GPRS_AUTH_PROTOCOL_CHAP_EV,                    
} TAPI_GPRS_AUTH_PROTOCOL_E;

typedef enum    _TAPI_EGPRS_TRAFFIC_CLASS_E
{
    TAPI_EGPRS_TRAFFIC_CLASS_CONVERSATIONAL_EV, 
    TAPI_EGPRS_TRAFFIC_CLASS_STREAMING_EV,      
    TAPI_EGPRS_TRAFFIC_CLASS_INTERACTIVE_EV,    
    TAPI_EGPRS_TRAFFIC_CLASS_BACKGROUD_EV,      
    TAPI_EGPRS_TRAFFIC_CLASS_SUBSCRIBE_EV       
} TAPI_EGPRS_TRAFFIC_CLASS_E;

typedef enum    _TAPI_EGPRS_DELIVERY_ORDER_E
{
    TAPI_EGPRS_DELIVERY_ORDER_NO_EV,            
    TAPI_EGPRS_DELIVERY_ORDER_YES_EV,           
    TAPI_EGPRS_DELIVERY_ORDER_SUBSCRIBE_EV,     
} TAPI_EGPRS_DELIVERY_ORDER_E;

typedef enum    _TAPI_EGPRS_DELIVERY_ERROR_SDU_E
{
    TAPI_EGPRS_DELIVERY_ERROR_SDU_NO_EV,            
    TAPI_EGPRS_DELIVERY_ERROR_SDU_YES_EV,           
    TAPI_EGPRS_DELIVERY_ERROR_SDU_NOT_DETECT_EV,    
    TAPI_EGPRS_DELIVERY_ERROR_SDU_SUBSCRIBE_EV,     
} TAPI_EGPRS_DELIVERY_ERROR_SDU_E;

typedef enum    _TAPI_GPRS_OPERATION_MODE_E
{
    TAPI_GPRS_OPERATION_MODE_CLASS_C_GSM = 0, 
    TAPI_GPRS_OPERATION_MODE_CLASS_C_GPRS,    
    TAPI_GPRS_OPERATION_MODE_CLASS_B,         

    TAPI_GPRS_OPERATION_MODE_CLASS_A          

} TAPI_GPRS_OPERATION_MODE_E;

typedef enum    _TAPI_GPRS_SERVICE_STATE_E
{
    TAPI_GPRS_SERVICE_STATE_AVAILABLE = 0,        
    TAPI_GPRS_SERVICE_STATE_TEMP_NA_CS_ACTIVITY,  
    TAPI_GPRS_SERVICE_STATE_GPRS_NW_NOT_AVAILABLE 
} TAPI_GPRS_SERVICE_STATE_E;

enum _TAPI_GPRS_ALWAYS_ON_PLMN_TYPE_E
{
    TAPI_GPRS_ALWAYS_ON_PLMN_TYPE_NULL =0,            
    TAPI_GPRS_ALWAYS_ON_PLMN_TYPE_HPLMN,              
    TAPI_GPRS_ALWAYS_ON_PLMN_TYPE_EPLMN_OF_HPLMN,     
    TAPI_GPRS_ALWAYS_ON_PLMN_TYPE_3HUTCH_VPLMN,       

    TAPI_GPRS_ALWAYS_ON_PLMN_TYPE_VPLMN_SAME_COUNTRY, 
    TAPI_GPRS_ALWAYS_ON_PLMN_TYPE_VPLMN_ABROAD,       
    TAPI_GPRS_ALWAYS_ON_PLMN_TYPE_ANOTHER_PLMN        

};
typedef UINT8 TAPI_GPRS_ALWAYS_ON_PLMN_TYPE_E;

typedef enum    _TAPI_GPRS_DATA_TRANSFER_STATUS_E 
{ 
    TAPI_GPRS_DATA_TRANSFER_STATUS_UNKNOWN      = 0, 
    TAPI_GPRS_DATA_TRANSFER_STATUS_GPRS_STARTED,      
    TAPI_GPRS_DATA_TRANSFER_STATUS_EGPRS_STARTED,    
    TAPI_GPRS_DATA_TRANSFER_STATUS_3G_STARTED,        
    TAPI_GPRS_DATA_TRANSFER_STATUS_HSDPA_STARTED,     
    TAPI_GPRS_DATA_TRANSFER_STATUS_GPRS_STOPPED,      
    TAPI_GPRS_DATA_TRANSFER_STATUS_EGPRS_STOPPED,    
    TAPI_GPRS_DATA_TRANSFER_STATUS_3G_STOPPED,        
    TAPI_GPRS_DATA_TRANSFER_STATUS_HSDPA_STOPPED      
} TAPI_GPRS_DATA_TRANSFER_STATUS_E;

typedef UINT8   TAPI_GPRS_NAME_A[TAPI_GPRS_MAX_NAME_LENGTH];

typedef UINT8   TAPI_GPRS_IP_ADDRESS_A[TAPI_CALL_IP_ADDRESS_LENGTH];

typedef UINT8   TAPI_EGPRS_ERROR_RATIO_A[TAPI_EGPRS_ERROR_RATIO_LENGTH + 1];

typedef UINT8   TAPI_GPRS_IP_ADDR_AND_MASK_A[TAPI_GPRS_IP_ADDR_AND_MASK_LENGTH];

typedef UINT8   TAPI_GPRS_PORT_RANGE_A[TAPI_GPRS_PORT_RANGE_LENGTH];

typedef UINT8   TAPI_GPRS_IPSEC_SPI_A[TAPI_GPRS_IPSEC_SPI_LENGTH];

typedef UINT8   TAPI_GPRS_TOS_AND_MASK_A[TAPI_GPRS_TOS_AND_MASK_LENGTH];

typedef UINT8   TAPI_GPRS_FLOW_LABEL_A[TAPI_GPRS_FLOW_LABEL_LENGTH];

typedef struct  _TAPI_GPRS_SET_CONTEXT_S
{
    TAPI_GPRS_PROTOCOL_E    protocolType;      
    TAPI_GPRS_NAME_A        apn;               

    TAPI_GPRS_NAME_A        pdpAddress;        
    UINT8                   dcomp;             
    UINT8                   hcomp;             
} TAPI_GPRS_SET_CONTEXT_S;

typedef struct  _TAPI_GPRS_SET_SECONDARY_CONTEXT_S
{
    TAPI_CALL_ID_T          primaryCid; 
    UINT8                   dcomp;      
    UINT8                   hcomp;      
} TAPI_GPRS_SET_SECONDARY_CONTEXT_S;

typedef struct  _TAPI_GPRS_SET_TFT_S
{
    UINT8                        packetFilterId; 
    UINT8                        evalIndex;      
    TAPI_GPRS_IP_ADDR_AND_MASK_A srcAddrAndMask; 
    UINT8                        protocolNum;    
    TAPI_GPRS_PORT_RANGE_A       destPortRange;  
    TAPI_GPRS_PORT_RANGE_A       srcPortRange;   
    TAPI_GPRS_IPSEC_SPI_A        ipSecSpi;       
    TAPI_GPRS_TOS_AND_MASK_A     tosAndMask;     
    TAPI_GPRS_FLOW_LABEL_A       flowLabel;      
} TAPI_GPRS_SET_TFT_S;

typedef struct  _TAPI_GPRS_ACTIVE_CONTEXT_S
{
    TAPI_GPRS_NAME_A    userName;       
    TAPI_GPRS_NAME_A    password;       
    UINT32              dns1;           

    UINT32              dns2;           

} TAPI_GPRS_ACTIVE_CONTEXT_S;

typedef struct  _TAPI_GPRS_RSP_ADDRESS_MSG_S
{
    UINT32  ipAddress;      
    UINT32  dns1;           
    UINT32  dns2;           
} TAPI_GPRS_RSP_ADDRESS_MSG_S;

typedef struct  _TAPI_GPRS_SESSION_COUNTER_S
{
    UINT32  upBytes;        
    UINT32  downBytes;      
    UINT32  connectedTime;  
} TAPI_GPRS_SESSION_COUNTER_S;

typedef struct  _TAPI_GPRS_NOTIFY_CONNECTED_MSG_S
{
    TAPI_CALL_ID_T              cid;        
    TAPI_GPRS_RSP_ADDRESS_MSG_S response;   
    pid_t                       pid;        
} TAPI_GPRS_NOTIFY_CONNECTED_MSG_S;

typedef struct  _TAPI_GPRS_NOTIFY_DISCONNECT_MSG_S
{
    TAPI_CALL_ID_T  cid;    
    pid_t           pid;    
} TAPI_GPRS_NOTIFY_DISCONNECT_MSG_S;

typedef struct  _TAPI_GPRS_QUALITY_SERVICE_S
{
    UINT8   precedence;     

    UINT8   delay;          
    UINT8   reliability;    
    UINT8   peak;           
    UINT8   mean;           
} TAPI_GPRS_QUALITY_SERVICE_S;

typedef struct  _TAPI_GPRS_RSP_ACTIVE_STATUS_GROUP_MSG_S
{
    INT32                       number; 
    TAPI_GPRS_ACTIVE_STATUS_S   status[TAPI_GPRS_MAX_PDP_CONTEXT_NUMBER +
				    TAPI_GPRS_MAX_SECONDARY_PDP_CONTEXT_NUMBER];

} TAPI_GPRS_RSP_ACTIVE_STATUS_GROUP_MSG_S;

typedef struct  _TAPI_GPRS_RSP_PDP_ADDRESS_MSG_S
{
    INT32                       number; 
    TAPI_GPRS_ADDRESS_INFO_S    pdp[TAPI_GPRS_MAX_PDP_CONTEXT_NUMBER + 
				    TAPI_GPRS_MAX_SECONDARY_PDP_CONTEXT_NUMBER];    

} TAPI_GPRS_RSP_PDP_ADDRESS_MSG_S;

typedef struct  _TAPI_GPRS_REQ_GET_PDP_ADDRESS_MSG_S
{
    UINT8   cid[TAPI_GPRS_MAX_PDP_CONTEXT_NUMBER];  
} TAPI_GPRS_REQ_GET_PDP_ADDRESS_MSG_S;

typedef struct  _TAPI_GPRS_STATUS_S
{
    TAPI_GPRS_ATTACH_STATUS_E   attachStatus;       
    TAPI_BOOL_STATUS_E          featureStatus;      
    TAPI_BOOL_STATUS_E          serverStatus;       
    BOOLEAN                     isEverAttached;     

    TAPI_GPRS_OPERATION_MODE_E  current_operation_mode;  

    TAPI_GPRS_OPERATION_MODE_E  flex_operation_mode;  
} TAPI_GPRS_STATUS_S;

typedef struct  _TAPI_EGPRS_STATUS_S
{
    TAPI_BOOL_STATUS_E  serviceStatus;          

    BOOLEAN             isTransmitOverEgprs;    
} TAPI_EGPRS_STATUS_S;

typedef struct  _TAPI_EGPRS_QUALITY_SERVICE_S
{
    TAPI_EGPRS_TRAFFIC_CLASS_E      trafficClass;       

    UINT16                          maxULRate;          
    UINT16                          maxDLRate;          
    UINT16                          guaranteeULRate;    
    UINT16                          guaranteeDLRate;    
    TAPI_EGPRS_DELIVERY_ORDER_E     deliveryOrder;      

    UINT16                          maxSduSize;         
    TAPI_EGPRS_ERROR_RATIO_A        sduErrorRatio;      

    TAPI_EGPRS_ERROR_RATIO_A        residualErrorRatio; 

    TAPI_EGPRS_DELIVERY_ERROR_SDU_E deliveryErrorSdu;   

    UINT16                          transferDelay;      
    UINT16                          trafficPrior;       

} TAPI_EGPRS_QUALITY_SERVICE_S;

typedef struct  _TAPI_GPRS_SERVICE_QUALITY_STATUS_S
{
    UINT8   cid;
    UINT32  precedence;
    UINT32  delay;
    UINT32  reliability;
    UINT32  peak;
    UINT32  mean;
} __attribute__( (packed) )  TAPI_GPRS_SERVICE_QUALITY_STATUS_S;

typedef struct  _TAPI_GPRS_ID_SERVICE_QUALITY_COUNT_S
{
    UINT32  count;
    TAPI_GPRS_SERVICE_QUALITY_STATUS_S*     pQualityServiceStatus;
} __attribute__( (packed) )  TAPI_GPRS_ID_SERVICE_QUALITY_COUNT_S;

typedef struct  _TAPI_GPRS_PDP_CONTEXT_S
{
    UINT8                   cid;
    TAPI_GPRS_PROTOCOL_E    pdptype;
    UINT8                   apn[TAPI_GPRS_MAX_NAME_LENGTH];
    UINT8                   pdpAddress[TAPI_GPRS_MAX_NAME_LENGTH];
    UINT8                   dcomp;
    UINT8                   hcomp;
} __attribute__( (packed) )  TAPI_GPRS_PDP_CONTEXT_S;

typedef struct _TAPI_GPRS_SECONDARY_PDP_CONTEXT
{ 
    TAPI_CALL_ID_T          secCid;
    TAPI_CALL_ID_T          primaryCid;
    UINT8                   dcomp; 
    UINT8                   hcomp; 
} TAPI_GPRS_SECONDARY_PDP_CONTEXT_S;

typedef struct _TAPI_GPRS_TFT_S
{
    TAPI_CALL_ID_T               secCid; 
    UINT8                        packetFilterId; 
    UINT8                        evalIndex; 
    TAPI_GPRS_IP_ADDR_AND_MASK_A srcAddrAndMask;
    UINT8                        protocolNum;
    TAPI_GPRS_PORT_RANGE_A       destPortRange;
    TAPI_GPRS_PORT_RANGE_A       srcPortRange;
    TAPI_GPRS_IPSEC_SPI_A        ipSecSpi;
    TAPI_GPRS_TOS_AND_MASK_A     tosAndMask;
    TAPI_GPRS_FLOW_LABEL_A       flowLabel;
} TAPI_GPRS_TFT_S;

typedef struct  _TAPI_GPRS_ID_RANGE_S
{
    UINT8   rangeId;    

    UINT32  minValue;   
    UINT32  maxValue;   
} __attribute__( (packed) )  TAPI_GPRS_ID_RANGE_S;

typedef struct  _TAPI_GPRS_ID_RANGE_COUNT_S
{
    UINT32                  count;
    TAPI_GPRS_ID_RANGE_S*   pIdRange;
} __attribute__( (packed) )  TAPI_GPRS_ID_RANGE_COUNT_S;

typedef struct  _TAPI_GPRS_PDP_CONTEXT_COUNT_S
{
    UINT32                      count;
    TAPI_GPRS_PDP_CONTEXT_S*    pPdp;
} __attribute__( (packed) )  TAPI_GPRS_PDP_CONTEXT_COUNT_S;

typedef struct  _TAPI_GET_NETWORK_REG_STATUS_S
{
    UINT8   n;
    UINT8   stat;
    UINT8   lac0;       
    UINT8   lac1;       
    UINT8   cid0;       
    UINT8   cid1;       
} __attribute__( (packed) )  TAPI_GET_NETWORK_REG_STATUS_S;

typedef struct  _TAPI_AT_EGPRS_QUALITY_SERVICE_S
{
    UINT8                           cid;
    TAPI_EGPRS_TRAFFIC_CLASS_E      trafficClass;       

    UINT16                          maxULRate;          
    UINT16                          maxDLRate;          
    UINT16                          guaranteeULRate;    
    UINT16                          guaranteeDLRate;    
    TAPI_EGPRS_DELIVERY_ORDER_E     deliveryOrder;      

    UINT16                          maxSduSize;         
    TAPI_EGPRS_ERROR_RATIO_A        sduErrorRatio;      

    TAPI_EGPRS_ERROR_RATIO_A        residualErrorRatio; 

    TAPI_EGPRS_DELIVERY_ERROR_SDU_E deliveryErrorSdu;   

    UINT16                          transferDelay;      
    UINT16                          trafficPrior;       

} __attribute__( (packed) )  TAPI_AT_EGPRS_QUALITY_SERVICE_S;

typedef struct  _TAPI_AT_EGPRS_GET_QOS_S
{
    UINT32                          totalNum;
    TAPI_AT_EGPRS_QUALITY_SERVICE_S qoses[TAPI_GPRS_MAX_PDP_CONTEXT_NUMBER 
					     + TAPI_GPRS_MAX_SECONDARY_PDP_CONTEXT_NUMBER];    
} __attribute__( (packed) )  TAPI_AT_EGPRS_GET_QOS_S;

typedef struct  _TAPI_GPRS_DATA_BYTES_S
{
    UINT32  sentBytes;
    UINT32  recvBytes;
} TAPI_GPRS_DATA_BYTES_S;

typedef struct  _TAPI_AT_GPRS_MTXDATA_S
{
    UINT8   ipadress[IPV4_MAX_LENGTH + 1];
    UINT16  destPort;
    UINT16  packets;
    UINT16  packets_size;
    INT16   delay;
} __attribute__( (packed) )  TAPI_AT_GPRS_MTXDATA_S;

typedef struct  _TAPI_GPRS_SESSION_INFO_S
{
    UINT8                   sessionId;
    TAPI_GPRS_DATA_BYTES_S  dataBytes;
    TAPI_CALL_TIME_S        duration;                      
    UINT8                   apn[TAPI_GPRS_MAX_APN_LENGTH]; 
} TAPI_GPRS_SESSION_INFO_S;

typedef struct  _TAPI_GPRS_SESSION_TABLE_S
{
    UINT32                   number;
    TAPI_GPRS_SESSION_INFO_S session[TAPI_GPRS_MAX_PDP_CONTEXT_NUMBER];
} TAPI_GPRS_SESSION_TABLE_S;

typedef struct  _TAPI_ATTACH_DETACH_RESULT_S
{
    TAPI_GPRS_ATTACH_STATUS_E    attach_detach; 

    TAPI_RESULT_E                result;       

} TAPI_ATTACH_DETACH_RESULT_S;

typedef struct _TAPI_GPRS_ALWAYS_ON_PLMN_S 
{ 
    TAPI_GPRS_ALWAYS_ON_PLMN_TYPE_E  plmn_type;    
    TAPI_FEATURE_E                   rau_success; 

} TAPI_GPRS_ALWAYS_ON_PLMN_S;

#ifdef __cplusplus
}
#endif 

#endif  

