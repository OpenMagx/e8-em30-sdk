

// Copyright (c) 11-Apr-08 - 2008 Motorola, Inc. All rights reserved.


#ifndef RC_CONNECTIVITY_H 
#define RC_CONNECTIVITY_H

#ifdef __cplusplus 
extern "C" {
#endif

#define PUBLIC_INTERNET      "PublicInternet"

#define ROOT                 "Root"
#define CONSTRAINT           "Constraint"
#define SERVICE_NAME         "ServiceName"

#define TRANSPORTPREFERENCE  "TransportPreference"

#define WIFIONLY_VALUE       "WiFiOnly"
#define WIFIPREFERRED_VALUE  "WiFiPreferred"
#define CELLULAR_VALUE       "CellularOnly"

#define RC_NOTIFICATION_BASE 0x1000

typedef INT8* RcServiceType;

enum
{
    RC_DEVICE_NAME,              
    RC_IP_ADDRESS                
};

typedef INT32 RcDevInfoType;

enum
{
    RC_MSG_CONNECT_SUCCESS_IND = RC_NOTIFICATION_BASE + 1,  
    RC_MSG_CONNECT_FAIL_IND,                              
    RC_MSG_DISCONNECT_SUCCESS_IND,                          
    RC_MSG_DISCONNECT_FAIL_IND,                           
    RC_MSG_LINK_TERMINATED_IND                              
};

extern INT32 RC_Init(INT32* p_appInstanceId);

extern void RC_Fini(INT32 appInstanceId);

extern INT32 RC_Connect(RcServiceType p_serviceRequested,
                                     INT8* p_rules,
                                     INT32 appInstanceId,
                                     INT32* p_requestId);

extern INT32 RC_Disconnect(INT32 requestId);

extern INT32 RC_BindSocket2Link(INT32 socketId, INT32 requestId);

extern INT32 RC_DnsResolverConfig(INT32 requestId);

extern INT32 RC_GetDeviceInfo(INT32 requestId,
                                RcDevInfoType request,
                                void* p_param,
                                UINT32 paramLength);

extern INT32 RC_ProcessAsyncMsg(INT32 appAsyncFd,
                                       UINT16* p_msgId,
                                       UINT32* p_appMsgLen,
                                       INT8** pp_appMsg);

#ifdef __cplusplus
}
#endif 

#endif  
