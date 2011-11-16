

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_SMS_PDUMODEAPI_H      
#define TAPI_SMS_PDUMODEAPI_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "EZX_TypeDefs.h"
#include "TAPI_Result.h"
#include "TAPI_SMS_TextModeClient.h"

#define TAPI_MAX_SMS_PDU_LENGTH                    191

typedef enum    _TAPI_SMS_LIST_PDU_MODE_E
{
    TAPI_SMS_LIST_PDU_MODE_CHANGE_STATUS_EV,
    TAPI_SMS_LIST_PDU_MODE_NOT_CHANGE_STATUS_EV,
} TAPI_SMS_LIST_PDU_MODE_E;

typedef struct  _TAPI_SMS_PDU_SM_S
{
    BOOLEAN disableFDN;                        
    UINT8   tpduLength;                       
    UINT8   pduLength;                        
    UINT8   pduBuf[TAPI_MAX_SMS_PDU_LENGTH];  
} TAPI_SMS_PDU_SM_S;

typedef struct  _TAPI_SMS_NOTIFY_RECV_PDU_S
{
    UINT32              sequenceNumber;         
    TAPI_SMS_PDU_SM_S   pduSm;                  
} TAPI_SMS_NOTIFY_RECV_PDU_S;

typedef struct  _TAPI_SMS_SIM_PDU_SM_S
{
    TAPI_SMS_SIM_STORE_SM_STATUS_E  smStatus;
    TAPI_SMS_PDU_SM_S               pdu;
} TAPI_SMS_SIM_PDU_SM_S;

typedef struct  _TAPI_SMS_SIM_PDU_LIST_S
{
    UINT16                  index;      
    TAPI_SMS_SIM_PDU_SM_S   simSmPdu;   
} __attribute__( (packed) )  TAPI_SMS_SIM_PDU_LIST_S;

extern TAPI_RESULT_E   
TAPI_SMS_SendPduBlockMode(
                          const TAPI_SMS_PDU_SM_S*    pPduSm,
                          UINT8*                      pMsgRefNumber 
                          );

extern TAPI_RESULT_E   
TAPI_SMS_SendPduUnblockMode(
                            const TAPI_SMS_PDU_SM_S*    pPduSm,
                            UINT32*                     pSeqNumber 
                            );

extern TAPI_RESULT_E   
TAPI_SMS_ReadSimPdu(
                    UINT16                  simIndex,
                    TAPI_SMS_SIM_PDU_SM_S*  pSimPdu 
                    );

extern TAPI_RESULT_E   
TAPI_SMS_InsertPduToSim(
                        const TAPI_SMS_SIM_PDU_SM_S*    pSimPdu,
                        UINT16*                         pSimIndex 
                        );

extern TAPI_RESULT_E   
TAPI_SMS_UpdatePduToSim(
                        const TAPI_SMS_SIM_PDU_SM_S*    pSimPdu,
                        UINT16                          simIndex 
                        );

extern TAPI_RESULT_E   
TAPI_SMS_ListSimPdu(
                    TAPI_SMS_SIM_STORE_SM_STATUS_E  stat,
                    TAPI_SMS_LIST_PDU_MODE_E        mode,
                    UINT16*                         pMsgCount,
                    TAPI_SMS_SIM_PDU_LIST_S*        pSimSmList 
                    );

extern TAPI_RESULT_E   
TAPI_SMS_SendTpduBlockMode(
                           UINT8           scAddressLength,
                           const UINT8*    scAddress,
                           UINT8           tpduLength,
                           const UINT8*    pTpdu,
                           UINT8*          pMsgRefNumber 
                           );

extern TAPI_RESULT_E   
TAPI_SMS_SetRecvMode( 
                     TAPI_SMS_RECV_MODE_E recvMode 
                     );

extern TAPI_RESULT_E   
TAPI_SMS_SendKodiakTpduUnblockMode(
                    UINT8           scAddressLength,
                    const UINT8*    scAddress,
                    UINT8           destAddressLength,
                    const UINT8*    destAddress,
                    UINT8           msgLength,
                    const UINT8*    pMsg,
                    UINT32*         pMsgRefNumber );

TAPI_RESULT_E TAPI_SMS_SendCommand(const UINT8     firstOctect,
                                   const UINT8     cmdType,
                                   const UINT8     pid,
                                   const UINT8     msgNumber,
                                   const UINT8*    destAddress,
                                   const UINT8     cmdLength,
                                   const UINT8*    cmdData,
                                   UINT32*         pSeqNumber );

TAPI_RESULT_E TAPI_SMS_SendCommandBlockMode(const UINT8     firstOctect,
                                            const UINT8     cmdType,
                                            const UINT8     pid,
                                            const UINT8     msgNumber,
                                            const UINT8*    destAddress,
                                            const UINT8     cmdLength,
                                            const UINT8*    cmdData,
                                            UINT8*          pMsgRefNumber );

#ifdef __cplusplus
}
#endif 

#endif  

