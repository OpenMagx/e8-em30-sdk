

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef _TAPI_GPRS_CLIENT_H 
#define  _TAPI_GPRS_CLIENT_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_AppMsgId.h"
#include "TAPI_Result.h"
#include "TAPI_CALL_General.h"
#include "TAPI_GPRS_AppData.h"

extern TAPI_RESULT_E   
TAPI_GPRS_ConnectGprs(
                      TAPI_CALL_ID_T*                 pCid,
                      TAPI_GPRS_SET_CONTEXT_S*        pContext,
                      TAPI_GPRS_ACTIVE_CONTEXT_S*     pActiveContext,
                      TAPI_GPRS_QUALITY_SERVICE_S*    pReqQos,
                      TAPI_GPRS_QUALITY_SERVICE_S*    pMinQos 
                      );

extern TAPI_RESULT_E   
TAPI_GPRS_DisconnectGprs( 
                         TAPI_CALL_ID_T cid 
                         );

extern TAPI_RESULT_E   
TAPI_GPRS_SetContext(
                     TAPI_CALL_ID_T              cid,
                     TAPI_GPRS_SET_CONTEXT_S*    pContext 
                     );

extern TAPI_RESULT_E   
TAPI_GPRS_SetRequiredQoS(
                         TAPI_CALL_ID_T                  cid,
                         TAPI_GPRS_QUALITY_SERVICE_S*    pQos 
                         );

extern TAPI_RESULT_E   
TAPI_GPRS_SetMinimumQoS(
                        TAPI_CALL_ID_T                  cid,
                        TAPI_GPRS_QUALITY_SERVICE_S*    pQos 
                        );

extern TAPI_RESULT_E   
TAPI_GPRS_AuthenticateAndActivate(
                                  TAPI_CALL_ID_T                  cid,
                                  TAPI_GPRS_ACTIVE_CONTEXT_S*     pContext 
                                  );

extern TAPI_RESULT_E   
TAPI_GPRS_SetOn( 
                void 
                );

extern TAPI_RESULT_E   
TAPI_GPRS_SetOff( 
                 void 
                 );

extern TAPI_RESULT_E   
TAPI_GPRS_GetStatus( 
                    TAPI_GPRS_STATUS_S* pStatus 
                    );

extern TAPI_RESULT_E   
TAPI_EGPRS_GetStatus( 
                     TAPI_EGPRS_STATUS_S* pStatus 
                     );

extern TAPI_RESULT_E   
TAPI_GPRS_Attach( 
                 void 
                 );

extern TAPI_RESULT_E   
TAPI_GPRS_Detach( 
                 void 
                 );

extern TAPI_RESULT_E   
TAPI_GPRS_GetAttachStatus( 
                          TAPI_GPRS_ATTACH_STATUS_E* pStatus 
                          );

extern TAPI_RESULT_E   
TAPI_GPRS_ActivateContext( 
                          TAPI_CALL_ID_T cid 
                          );

extern TAPI_RESULT_E   
TAPI_GPRS_DeactivateContext( 
                            TAPI_CALL_ID_T cid 
                            );

extern TAPI_RESULT_E   
TAPI_GPRS_ActivateAllContext( 
                             void 
                             );

extern TAPI_RESULT_E   
TAPI_GPRS_DeactivateAllContext( 
                               void 
                               );

extern TAPI_RESULT_E   
TAPI_GPRS_GetActivateStatus(
                            TAPI_GPRS_RSP_ACTIVE_STATUS_GROUP_MSG_S*    pStatus 
                            );

extern TAPI_RESULT_E   
TAPI_GPRS_GetPDPAddress( 
                        TAPI_GPRS_RSP_PDP_ADDRESS_MSG_S* pPdp 
                        );

extern TAPI_RESULT_E   
TAPI_EGPRS_SetRequiredQoS(
                          TAPI_CALL_ID_T                  cid,
                          TAPI_EGPRS_QUALITY_SERVICE_S*   pQos 
                          );

extern TAPI_RESULT_E   
TAPI_EGPRS_SetMinimumQoS(
                         TAPI_CALL_ID_T                  cid,
                         TAPI_EGPRS_QUALITY_SERVICE_S*   pQos 
                         );

extern TAPI_RESULT_E   
TAPI_EGPRS_ConnectEGprs(
                    TAPI_CALL_ID_T*                 pCid,
                    TAPI_GPRS_SET_CONTEXT_S*        pContext,
                    TAPI_GPRS_ACTIVE_CONTEXT_S*     pActiveContext,
                    TAPI_GPRS_QUALITY_SERVICE_S*    pReqQos,
                    TAPI_GPRS_QUALITY_SERVICE_S*    pMinQos,
                    TAPI_EGPRS_QUALITY_SERVICE_S*   pEgprsReqQos,
                        TAPI_EGPRS_QUALITY_SERVICE_S*   pEgprsMinQos 
                        );

extern TAPI_RESULT_E   
TAPI_GPRS_OpenDataChannel(
                          TAPI_CALL_ID_T  cid,
                          INT32*          pFd 
                          );

extern TAPI_RESULT_E   
TAPI_GPRS_GetTotalDataBytes(
                    UINT32*     pTotalBytes,
                    UINT32*     pRecvBytes,
                            UINT32*     pSentBytes 
                            );

extern TAPI_RESULT_E   
TAPI_GPRS_GetSessionDataBytes(
                    const UINT8 sessionId,
                    UINT32*     pSessionBytes,
                    UINT32*     pRecvBytes,
                              UINT32*     pSentBytes 
                              );

extern TAPI_RESULT_E   
TAPI_GPRS_ResetTotalDataBytes( 
                              void 
                              );

extern TAPI_RESULT_E   
TAPI_GPRS_GetServiceQualityStatus(
                                  TAPI_GPRS_SERVICE_QUALITY_STATUS_S*     pGprsServiceStatus,
                                  UINT32*                             pCount 
                                  );

extern TAPI_RESULT_E   
TAPI_GPRS_GetServiceQualityParam(
                                 TAPI_GPRS_ID_RANGE_S*   pIdRange,
                                 UINT32*                 pCount 
                                 );

extern TAPI_RESULT_E   
TAPI_GPRS_GetMinServiceQuality(
                               TAPI_GPRS_SERVICE_QUALITY_STATUS_S*     pGprsServiceStatus,
                               UINT32*                             pCount 
                               );

extern TAPI_RESULT_E   
TAPI_GPRS_GetMinServiceQualityParam(
                                    TAPI_GPRS_ID_RANGE_S*   pIdRange,
                                    UINT32*                 pCount 
                                    );

extern TAPI_RESULT_E   
TAPI_GPRS_GetAvailableDataTransferParamList(
                                            TAPI_GPRS_ID_RANGE_S*   pIdRange,
                                            UINT32*                 pCount 
                                            );

extern TAPI_RESULT_E   
TAPI_GPRS_GetPdpContext(
                    TAPI_GPRS_PDP_CONTEXT_S*    pPdp,
                        UINT32*                     pCount 
                        );

extern TAPI_RESULT_E   
TAPI_EGPRS_GetRequiredQoS( 
                          TAPI_AT_EGPRS_GET_QOS_S* pQoses 
                          );

extern TAPI_RESULT_E   
TAPI_EGPRS_GetMinQoS( 
                     TAPI_AT_EGPRS_GET_QOS_S* pQoses 
                     );

extern TAPI_RESULT_E   
TAPI_GPRS_SetCgreg( 
                   UINT16 kind 
                   );

extern TAPI_RESULT_E   
TAPI_GPRS_GetCgreg( 
                   TAPI_GET_NETWORK_REG_STATUS_S* pRegStatus 
                   );

extern TAPI_RESULT_E   
TAPI_GPRS_SetMtxdata( 
                     const TAPI_AT_GPRS_MTXDATA_S* pMtxdata 
                     );

extern TAPI_RESULT_E   
TAPI_GPRS_SetContextEx(
                       TAPI_CALL_ID_T*             pCid,
                       TAPI_GPRS_SET_CONTEXT_S*    pContext 
                       );

extern TAPI_RESULT_E   
TAPI_GPRS_SetRequiredQoSEx(
                           TAPI_CALL_ID_T*                 pCid,
                           TAPI_GPRS_QUALITY_SERVICE_S*    pQos 
                           );

extern TAPI_RESULT_E   
TAPI_GPRS_SetMinimumQoSEx(
                          TAPI_CALL_ID_T*                 pCid,
                          TAPI_GPRS_QUALITY_SERVICE_S*    pQos 
                          );

extern TAPI_RESULT_E   
TAPI_GPRS_AuthenticateAndActivateEx(
                                    TAPI_CALL_ID_T*                 pCid,
                                    TAPI_GPRS_ACTIVE_CONTEXT_S*     pContext 
                                    );

extern TAPI_RESULT_E   
TAPI_EGPRS_SetRequiredQoSEx(
                            TAPI_CALL_ID_T*                 pCid,
                            TAPI_EGPRS_QUALITY_SERVICE_S*   pQos 
                            );

extern TAPI_RESULT_E   
TAPI_EGPRS_SetMinimumQoSEx(
                           TAPI_CALL_ID_T*                 pCid,
                           TAPI_EGPRS_QUALITY_SERVICE_S*   pQos 
                           );

extern TAPI_RESULT_E   
TAPI_GPRS_ResetTotalDuration( 
                             void 
                             );

extern TAPI_RESULT_E   
TAPI_GPRS_GetTotalDuration( 
                           TAPI_CALL_TIME_S * pGprsDuration 
                           );

extern TAPI_RESULT_E   
TAPI_GPRS_GetAllSessionInfo( 
                            TAPI_GPRS_SESSION_TABLE_S * pSessionTable 
                            );

extern TAPI_RESULT_E   
TAPI_ACL_IsACLEnabled(
					  BOOLEAN *bAclStatus
                      );

extern TAPI_RESULT_E   
TAPI_ACL_IsAPNInAPNControlList(
							   TAPI_GPRS_NAME_A apn, 
							   BOOLEAN *bApnPresentInACL
							   );

extern TAPI_RESULT_E 
TAPI_GPRS_SetSecondaryContext( 
                                                  TAPI_CALL_ID_T secCid, 
                                                  TAPI_GPRS_SET_SECONDARY_CONTEXT_S* pSecContext 
						  );

extern TAPI_RESULT_E
TAPI_GPRS_GetSecondaryPdpContext( 
                                                  TAPI_GPRS_SECONDARY_PDP_CONTEXT_S* pSecPdp,
                                                  UINT32* pCount
						  );

extern TAPI_RESULT_E 
TAPI_GPRS_SetTft(
                                                  TAPI_CALL_ID_T secCid, 
                                                  TAPI_GPRS_SET_TFT_S* pTft 
						  );

extern TAPI_RESULT_E 
TAPI_GPRS_GetTft( 
                                                           TAPI_GPRS_TFT_S*  pTft, 
                                                           UINT32* pCount
							   );
#ifdef __cplusplus
}
#endif 

#endif  

