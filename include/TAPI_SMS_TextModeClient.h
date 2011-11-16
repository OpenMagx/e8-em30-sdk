

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_SMS_TEXTMODEAPI_H   
#define TAPI_SMS_TEXTMODEAPI_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_General.h"
#include "TAPI_Result.h"
#include "TAPI_SMS_GsmDefs.h"

#define TAPI_SMS_MAX_SM_LENGTH                    160

#define TAPI_SMS_MAX_SM_PACKET_NUMBER             20

#define TAPI_SMS_MAX_SM_CONTENT_LENGTH    (TAPI_SMS_MAX_SM_LENGTH*TAPI_SMS_MAX_SM_PACKET_NUMBER)

typedef enum    _TAPI_SMS_RECV_MODE_E
{
    TAPI_SMS_RECV_MODE_PDU_EV,
    TAPI_SMS_RECV_MODE_TEXT_EV,
} TAPI_SMS_RECV_MODE_E;

enum _TAPI_SMS_PROTOCOL_E
{
    TAPI_SMS_PROTOCOL_TEXT_EV                   = 0x00,
    TAPI_SMS_PROTOCOL_IMPLICIT_EV               = 0x00,
    TAPI_SMS_PROTOCOL_TELEX_EV                  = 0x21,
    TAPI_SMS_PROTOCOL_G3_TELEFAX_EV             = 0x22,
    TAPI_SMS_PROTOCOL_G4_TELEFAX_EV             = 0x23,
    TAPI_SMS_PROTOCOL_VOICE_TELEPHONE           = 0x24,
    TAPI_SMS_PROTOCOL_ERMES_EV                  = 0x25,
    TAPI_SMS_PROTOCOL_PAGING_EV                 = 0x26,
    TAPI_SMS_PROTOCOL_VIDEOTEX_EV               = 0x27,
    TAPI_SMS_PROTOCOL_TELETEX_EV                = 0x28,
    TAPI_SMS_PROTOCOL_PSPDN_TELETEX_EV          = 0x29,
    TAPI_SMS_PROTOCOL_CSPDN_TELETEX_EV          = 0x2A,
    TAPI_SMS_PROTOCOL_PSTN_TELETEX_EV           = 0x2B,
    TAPI_SMS_PROTOCOL_ISDN_TELETEX_EV           = 0x2C,
    TAPI_SMS_PROTOCOL_UCI_EV                    = 0x2D,
    TAPI_SMS_PROTOCOL_SC_HANDLE_EV              = 0x30,
    TAPI_SMS_PROTOCOL_X400_EV                   = 0x31,
    TAPI_SMS_PROTOCOL_EMAIL_EV                  = 0x32,
    TAPI_SMS_PROTOCOL_UMTS_MS_EV                = 0x3F,
    TAPI_SMS_PROTOCOL_TYPE_ZERO_EV              = 0x40,
    TAPI_SMS_PROTOCOL_REPLACE_TYPE_1_EV         = 0x41,
    TAPI_SMS_PROTOCOL_REPLACE_TYPE_2_EV         = 0x42,
    TAPI_SMS_PROTOCOL_REPLACE_TYPE_3_EV         = 0x43,
    TAPI_SMS_PROTOCOL_REPLACE_TYPE_4_EV         = 0x44,
    TAPI_SMS_PROTOCOL_REPLACE_TYPE_5_EV         = 0x45,
    TAPI_SMS_PROTOCOL_REPLACE_TYPE_6_EV         = 0x46,
    TAPI_SMS_PROTOCOL_REPLACE_TYPE_7_EV         = 0x47,
    TAPI_SMS_PROTOCOL_EMS_EV                    = 0x5E,
    TAPI_SMS_PROTOCOL_RETURN_CALL_EV            = 0x5F,
    TAPI_SMS_PROTOCOL_ANSI_136R_DATA_EV         = 0x7C,
    TAPI_SMS_PROTOCOL_ME_DATA_DOWNLOAD_EV       = 0x7D,
    TAPI_SMS_PROTOCOL_ME_DEPERSONALIZATION_EV   = 0x7E,
    TAPI_SMS_PROTOCOL_SIM_DATA_DOWNLOAD_EV      = 0x7F,
    TAPI_SMS_PROTOCOL_UNSPECIFIED_EV
};

typedef UINT8   TAPI_SMS_PROTOCOL_E;

typedef enum    _TAPI_SMS_MT_TYPE_E
{
    TAPI_SMS_MT_TYPE_DEFAULT_EV                 = 0,    
    TAPI_SMS_MT_TYPE_SIM_SPECIFIC_EV,                    
    TAPI_SMS_MT_TYPE_ME_SPECIFIC_EV,                    

    TAPI_SMS_MT_TYPE_IMMEDIATE_EV,                      
    TAPI_SMS_MT_TYPE_TE_SPECIFIC_EV                     

} TAPI_SMS_MT_TYPE_E;

enum _TAPI_SMS_SIM_STORE_SM_STATUS_E
{
    TAPI_SMS_SIM_STORE_SM_STATUS_MT_UNREAD_EV   = 0x00, 
    TAPI_SMS_SIM_STORE_SM_STATUS_MT_READ_EV     = 0x01, 
    TAPI_SMS_SIM_STORE_SM_STATUS_MO_UNSENT_EV   = 0x02, 
    TAPI_SMS_SIM_STORE_SM_STATUS_MO_SENT_EV     = 0x03, 
    TAPI_SMS_SIM_STORE_SM_STATUS_ALL_EV         = 0x04  
};

typedef UINT8   TAPI_SMS_SIM_STORE_SM_STATUS_E;

typedef enum    _TAPI_SMS_TYPE_E
{
    TAPI_SMS_TYPE_UCS2_TEXT_EV,     
    TAPI_SMS_TYPE_ASCII_TEXT_EV,    
    TAPI_SMS_TYPE_DATA_EV           
} TAPI_SMS_TYPE_E;

typedef enum    _TAPI_SMS_WAITING_LINE_E
{
    TAPI_SMS_WAITING_LINE_1_EV,
    TAPI_SMS_WAITING_LINE_2_EV,
    TAPI_SMS_WAITING_LINE_UNSPECIFIED_EV
} TAPI_SMS_WAITING_LINE_E;

enum _TAPI_SMS_ACK_CODE_T
{
    TAPI_SMS_ACK_CODE_SUCCESS = 0,
    TAPI_SMS_ACK_CODE_MEMORY_FULL,
    TAPI_SMS_ACK_CODE_OTHER_ERROR
};
typedef UINT8   TAPI_SMS_ACK_CODE_T;

typedef struct  _TAPI_SMS_UCS2_CONTENT
{
    UINT16  msgLength;                    

    W_CHAR  msgBody[TAPI_SMS_MAX_SM_CONTENT_LENGTH + 1];
} TAPI_SMS_UCS2_CONTENT;

typedef struct  _TAPI_SMS_ASCII_CONTENT
{
    UINT16  msgLength;                   

    UINT8   msgBody[TAPI_SMS_MAX_SM_CONTENT_LENGTH + 1];
} TAPI_SMS_ASCII_CONTENT;

typedef struct  _TAPI_SMS_DATA_CONTENT
{
    UINT16  msgLength;                   

    UINT8   msgBody[TAPI_SMS_MAX_SM_CONTENT_LENGTH + 1];
} TAPI_SMS_DATA_CONTENT;

typedef struct  _TAPI_SMS_SM_BASE_S
{
    TAPI_SMS_PROTOCOL_E protocol;           
    BOOLEAN             isReplyPathValid;   

    TAPI_PHONE_NUMBER_A scAddress;          
    TAPI_PHONE_NUMBER_A peerAddress;        

    TAPI_SMS_TYPE_E     encodeType;         
    union
    {
        TAPI_SMS_UCS2_CONTENT   ucs2Content;    
        TAPI_SMS_ASCII_CONTENT  asciiContent;   
        TAPI_SMS_DATA_CONTENT   dataContent;    
    };

         /**< Short message content(UCS2 string,ascii 
                                                     string or binary data)  */
} TAPI_SMS_SM_BASE_S;

typedef struct  _TAPI_SMS_TIME_STAMP_S
{
    UINT16  year;       
    UINT8   month;      
    UINT8   day;        
    UINT8   hour;       
    UINT8   minute;     
    UINT8   second;     
    INT32   timeZone;   
} TAPI_SMS_TIME_STAMP_S;

typedef struct  _TAPI_SMS_MO_SM_S
{
    TAPI_SMS_SM_BASE_S  smBase;         
    UINT8               expirePeriod;   

    BOOLEAN             isNeedAck;      
    UINT8               msgRefNumber;   
} TAPI_SMS_MO_SM_S;

typedef struct  _TAPI_SMS_MT_SM_S
{
    TAPI_SMS_SM_BASE_S      smBase;     
    UINT8                   dcs;        
    TAPI_SMS_TIME_STAMP_S   timeStamp;  
} TAPI_SMS_MT_SM_S;

typedef struct  _TAPI_SMS_NOTIFY_RECV_NEW_SM_S
{
    UINT32              sequenceNumber; 
    TAPI_SMS_MT_TYPE_E  smType;         
    BOOLEAN             isConcatenated; 

    TAPI_SMS_MT_SM_S    mtSm;           
} TAPI_SMS_NOTIFY_RECV_NEW_SM_S;

typedef struct  _TAPI_SMS_NOTIFY_RECV_VM_SM_S
{
    UINT32                  sequenceNumber; 
    UINT8                   vmInfo;         
    UINT8                   vmCount;        
    TAPI_SMS_WAITING_LINE_E waitingLine;    
    BOOLEAN                 isNeedToStore;  
    TAPI_SMS_MT_SM_S        mtSm;           
} TAPI_SMS_NOTIFY_RECV_VM_SM_S;

typedef struct  _TAPI_SMS_NOTIFY_RECV_ORANGE_MOSES_SM_S
{
    UINT16              simIndex;           
    TAPI_SMS_MT_SM_S    mtSm;               
} TAPI_SMS_NOTIFY_RECV_ORANGE_MOSES_SM_S;

typedef union   _TAPI_SMS_SM_U
{
    TAPI_SMS_MO_SM_S    moSm;   
    TAPI_SMS_MT_SM_S    mtSm;   
} TAPI_SMS_SM_U;

typedef struct  _TAPI_SMS_SIM_STORE_SM_S
{
    TAPI_SMS_SIM_STORE_SM_STATUS_E  smStatus;   
    TAPI_SMS_SM_U                   smBody;     
} TAPI_SMS_SIM_STORE_SM_S;

typedef struct  _TAPI_SMS_SEND_RESP_S
{
    UINT32          sequenceNumber;  
    UINT8           msgRefNumber;   
    TAPI_RESULT_E   sentResult;     
} TAPI_SMS_SEND_RESP_S;

typedef struct  _TAPI_SMS_STATUS_REPORT_S
{
    UINT8                       msgRefNumber;     
    TAPI_PHONE_NUMBER_A         recipientAddress; 
    TAPI_SMS_DELIVER_STATUS_E   status;           
    TAPI_SMS_TIME_STAMP_S       deliverTime;      
} TAPI_SMS_STATUS_REPORT_S;

typedef struct  _TAPI_SMS_SEND_PORT_SM_S
{
    TAPI_SMS_TYPE_E     type;               
    UINT8               expirePeriod;       

    UINT16              srcPort;            
    UINT16              destPort;           
    TAPI_PHONE_NUMBER_A scAddress;          
    TAPI_PHONE_NUMBER_A peerAddress;        
    BOOLEAN             isReplyPathValid;   

    TAPI_SMS_PROTOCOL_E protocol;           
    BOOLEAN             isNeedAck;          
    UINT16              msgBufLength;       

    UINT8*              msgBuf;             
} TAPI_SMS_SEND_PORT_SM_S;

typedef struct  _TAPI_SMS_NOTIFY_RECV_PORT_SM_S
{
    UINT32                  sequenceNumber;     
    TAPI_SMS_TYPE_E         type;               
    UINT16                  srcPort;            
    UINT16                  destPort;           
    TAPI_PHONE_NUMBER_A     scAddress;          
    TAPI_PHONE_NUMBER_A     peerAddress;        
    BOOLEAN                 isReplyPathValid;   

    TAPI_SMS_PROTOCOL_E     protocol;           
    TAPI_SMS_TIME_STAMP_S   timeStamp;          
    UINT16                  msgLength;          

    UINT8                   msgBody[TAPI_SMS_MAX_SM_LENGTH *
	TAPI_SMS_MAX_SM_PACKET_NUMBER + 1];         
} TAPI_SMS_NOTIFY_RECV_PORT_SM_S;

typedef struct  _TAPI_SMS_PORTNUMBER_SM_DATA_S
{
    TAPI_SMS_TYPE_E encodingType;   
    UINT16          msgLength;      

    UINT8*          pMsgBody;       
} TAPI_SMS_PORTNUMBER_SM_DATA_S;

typedef struct  _TAPI_SMS_SM_ENCODE_INFO_S
{
    TAPI_SMS_TYPE_E encodingType;               
    UINT8           pduNumber;                  
    UINT8           spareCharNumberInLastPdu;   

} TAPI_SMS_SM_ENCODE_INFO_S;

extern TAPI_RESULT_E   
TAPI_SMS_SendSmUnblockMode(
                           const TAPI_SMS_MO_SM_S*     pMoSm,
                           UINT32*                     pSeqNumber 
                           );

extern TAPI_RESULT_E   
TAPI_SMS_SendSmBlockMode(
                         const TAPI_SMS_MO_SM_S*     pMoSm,
                         UINT8*                      pMsgRefNumber 
                         );

extern TAPI_RESULT_E   
TAPI_SMS_AckRecvSmStoreInMe(
                            UINT32  seqNumber,
                            BOOLEAN isRecvOK 
                            );

extern TAPI_RESULT_E   
TAPI_SMS_AckRecvSmInsertInSim(
                              UINT32      seqNumber,
                              UINT16*     pSimIndex 
                              );

extern TAPI_RESULT_E   
TAPI_SMS_AckRecvSmReplaceInSim(
                               UINT32  seqNumber,
                               UINT16  simIndex 
                               );

extern TAPI_RESULT_E   
TAPI_SMS_SetSimSmAsRead( 
                        UINT16 simIndex 
                        );

extern TAPI_RESULT_E   
TAPI_SMS_DeleteSimSm( 
                     UINT16 simIndex 
                     );

extern TAPI_RESULT_E   
TAPI_SMS_InsertMoSmToSim(
                         const TAPI_SMS_MO_SM_S*     pMoSm,
                         BOOLEAN                     isSent,
                         UINT16*                     pSimIndex 
                         );

extern TAPI_RESULT_E   
TAPI_SMS_InsertMtSmToSim(
                         const TAPI_SMS_MT_SM_S*     pMtSm,
                         BOOLEAN                     isRead,
                         UINT16*                     pSimIndex 
                         );

extern TAPI_RESULT_E   
TAPI_SMS_UpdateMoSmInSim(
                         const TAPI_SMS_MO_SM_S*     pMoSm,
                         BOOLEAN                     isSent,
                         UINT16                      simIndex 
                         );

extern TAPI_RESULT_E   
TAPI_SMS_UpdateMtSmInSim(
                         const TAPI_SMS_MT_SM_S*     pMtSm,
                         BOOLEAN                     isRead,
                         UINT16                      simIndex 
                         );

extern TAPI_RESULT_E   
TAPI_SMS_ReadSimSm(
                   UINT16                      simIndex,
                   TAPI_SMS_SIM_STORE_SM_S*    pSimSm 
                   );

extern TAPI_RESULT_E   
TAPI_SMS_NotifyMeStorageFull( 
                             void 
                             );

extern TAPI_RESULT_E   
TAPI_SMS_NotifyMeStorageAvail( 
                              void 
                              );

extern TAPI_RESULT_E   
TAPI_SMS_SendPortNumberSmUnblockMode(
                                     const TAPI_SMS_SEND_PORT_SM_S*  pPortSm,
                                     UINT32*                         pSeqNumber 
                                     );

extern TAPI_RESULT_E   
TAPI_SMS_SendPortNumberSmBlockMode(
                                   const TAPI_SMS_SEND_PORT_SM_S*  pPortSm,
                                   UINT8*                          pMsgRefNumber 
                                   );

extern TAPI_RESULT_E   
TAPI_SMS_RegisterPortNumber(
                            UINT16                  destPort,
                            TAPI_SMS_RECV_MODE_E    recvMode 
                            );

extern TAPI_RESULT_E   
TAPI_SMS_DeregisterPortNumber( 
                              UINT16 destPort 
                              );

extern TAPI_RESULT_E   
TAPI_SMS_RegisterKeyWord(
                         const UINT8*            keyWord,
                         UINT8                   keyWordLength,
                         TAPI_SMS_RECV_MODE_E    recvMode 
                         );

extern TAPI_RESULT_E   
TAPI_SMS_DeregisterKeyWord(
                           const UINT8*    keyWord,
                           UINT8           keyWordLength 
                           );

extern TAPI_RESULT_E   
TAPI_SMS_CaculateSm(
                    const TAPI_SMS_UCS2_CONTENT*    pSm,
                    TAPI_SMS_SM_ENCODE_INFO_S*      pEncodeInfo 
                    );

extern TAPI_RESULT_E   
TAPI_SMS_CaculatePortNumberSm(
                              const TAPI_SMS_PORTNUMBER_SM_DATA_S*    pSm,
                              TAPI_SMS_SM_ENCODE_INFO_S*              pEncodeInfo 
                              );

extern INT32           
TAPI_SMS_TimeStampToUnixTimeT(
                              TAPI_SMS_TIME_STAMP_S*  pTimeStamp 
                              );

extern TAPI_RESULT_E   
TAPI_SMS_UnixTimeTToTimeStamp(
                              INT32                   time,
                              TAPI_SMS_TIME_STAMP_S*  pTimeStamp 
                              );

extern UINT16          
TAPI_SMS_GetSmsLengthInSmBase(
                              const TAPI_SMS_SM_BASE_S*   pSmBase 
                              );

extern UINT16          
TAPI_SMS_GetSmsBufferLengthInSmBase(
                                    const TAPI_SMS_SM_BASE_S*   pSmBase 
                                    );

extern UINT8*          
TAPI_SMS_GetSmsBodyPtrFromSmBase( 
                                 TAPI_SMS_SM_BASE_S* pSmBase 
                                 );

extern TAPI_RESULT_E    
TAPI_SMS_AckRecvSm( TAPI_SMS_ACK_CODE_T ack_code );

#ifdef __cplusplus
}
#endif 

#endif  

