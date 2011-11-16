

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef _TAPI_SIM_INTERNALAPPDATA_
#define _TAPI_SIM_INTERNALAPPDATA_

#include "TAPI_SIM_ProvisionClient.h"
#include "TAPI_SIM_CertificateClient.h"

typedef enum _TAPI_SIM_EXT_FILE_E
{
    TAPI_SIM_EXT1_FILE_EV = 1,
    TAPI_SIM_EXT2_FILE_EV,
    TAPI_SIM_EXT6_FILE_EV,
    TAPI_SIM_EXT_FILE_END 
} TAPI_SIM_EXT_FILE_E;

typedef struct  _TAPI_CERTIFICATE_ENTRY_S
{
    TAPI_CERTIFICATE_TYPE_E type;
    UINT16                  oidOffset;
    UINT16                  oidLen;
    UINT16                  dataOffset;
    UINT16                  dataLen;
} __attribute__( (packed) )  TAPI_CERTIFICATE_ENTRY_S;

typedef struct  _TAPI_SIM_CERTIFICATE_HEAD_S
{
    UINT8                       flag;

    time_t                      timeStamp;

    TAPI_CERTIFICATE_ENTRY_S    entry[TAPI_SIM_CERTIFICATE_ENTRY_MAX_NUMBER];
} __attribute__( (packed) )  TAPI_SIM_CERTIFICATE_HEAD_S;

typedef struct  _TAPI_PROVISION_DATA_HEAD_S
{
    TAPI_SIM_PROVISION_FILE_TYPE_E  type;
    UINT32                          size;
} __attribute__( (packed) )  TAPI_PROVISION_DATA_HEAD_S;

extern TAPI_RESULT_E TAPI_SIM_GetExtFileRange(TAPI_SIM_EXT_FILE_E extFile,  
                                              UINT16 *pDigitNums);

extern TAPI_RESULT_E TAPI_SIM_GetExtFileAvailable(TAPI_SIM_EXT_FILE_E extFile, 
                                                  UINT16 *pUnused);

#endif 

