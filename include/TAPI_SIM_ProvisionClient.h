

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef _TAPI_SIM_PROVISIONCLIENT_H_
#define _TAPI_SIM_PROVISIONCLIENT_H_

#ifdef __cplusplus 
extern "C" {
#endif

#include "EZX_TypeDefs.h"
#include "TAPI_Result.h"

#define TAPI_SIM_PROVISION_DATA_MAX_LENGTH      512

enum    _TAPI_SIM_PROVISION_FILE_TYPE_E
{
    TAPI_SIM_PROVISION_BOOTSTRAP_FILE_EV= 1,
    TAPI_SIM_PROVISION_CONFIG1_FILE_EV,
    TAPI_SIM_PROVISION_CONFIG2_FILE_EV
};
typedef UINT8 TAPI_SIM_PROVISION_FILE_TYPE_E;

extern TAPI_RESULT_E    
TAPI_SIM_GetProvisionInfo(
                          TAPI_SIM_PROVISION_FILE_TYPE_E  fileType,
                          UINT8*                          pRawDataBuf,
                          UINT32*                         pDataLen 
                          );

extern BOOLEAN          
TAPI_SIM_RequestProvision( 
                          void 
                          );

#ifdef __cplusplus
}
#endif 

#endif  

