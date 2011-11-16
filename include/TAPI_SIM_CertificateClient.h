

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef _TAPI_SIM_CERTIFICATECLIENT_H_
#define _TAPI_SIM_CERTIFICATECLIENT_H_

#ifdef __cplusplus 
extern "C" {
#endif

#include <time.h>
#include "EZX_TypeDefs.h"
#include "TAPI_UTIL_SharedMemory.h"
#include "TAPI_Result.h"

#define TAPI_SIM_CERTIFICATE_ENTRY_MAX_NUMBER   11

enum _TAPI_CERTIFICATE_TYPE_E
{
    TAPI_CERTIFICATE_TYPE_TRUSTED_OPERATOR_EV,
    TAPI_CERTIFICATE_TYPE_TRUSTED_THIRD_PARTY_EV
};
typedef UINT8   TAPI_CERTIFICATE_TYPE_E;

extern TAPI_RESULT_E   
TAPI_SIM_GetCertificateRefreshTime( 
                                   time_t* pTimeStamp 
                                   );

extern TAPI_RESULT_E   
TAPI_SIM_GetCertificateEntryInfo(
                                 TAPI_CERTIFICATE_TYPE_E*    pType,
                                 UINT16*                     pOidLen,
                                 UINT16*                     pDataLen,
                                 UINT8                       index 
                                 );

extern TAPI_RESULT_E   
TAPI_SIM_GetCertificateOid(
                           UINT8*  pOidBuf,
                           UINT16  oidBufLen,
                           UINT8   index 
                           );

extern TAPI_RESULT_E   
TAPI_SIM_GetCertificateData(
                            UINT8*  pDataBuf,
                            UINT16  dataBufLen,
                            UINT8   index 
                            );

extern TAPI_RESULT_E   
TAPI_SIM_GetCertificateCount( 
                             UINT8* pCount 
                             );

extern BOOLEAN         
TAPI_SIM_RequestCertificate( 
                            void 
                            );

#ifdef __cplusplus
}
#endif 

#endif  

