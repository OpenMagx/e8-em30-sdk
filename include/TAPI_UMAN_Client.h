

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef _TAPI_UMAN_CLIENT_H      
#define _TAPI_UMAN_CLIENT_H 

#ifdef __cplusplus 
extern "C" {
#endif

#include "EZX_TypeDefs.h"
#include "TAPI_Result.h"

#define TAPI_UMAN_SERVICE_ZONE_NAME_LENGTH   (33)

typedef enum    _TAPI_UMAN_NETWORK_MODE_E
{
    TAPI_UMAN_NETWORK_MODE_GSM_ONLY_EV              = 0x00,
    TAPI_UMAN_NETWORK_MODE_ACCESS_POINT_ONLY_EV     = 0x01,
    TAPI_UMAN_NETWORK_MODE_GSM_PREFERRED_EV         = 0x02,
    TAPI_UMAN_NETWORK_MODE_ACCESS_POINT_PREFERRED_EV= 0x03,
    TAPI_UMAN_NETWORK_MODE_MAX_EV                   = TAPI_UMAN_NETWORK_MODE_ACCESS_POINT_PREFERRED_EV
} TAPI_UMAN_NETWORK_MODE_E;

typedef struct _TAPI_UMAN_SERVICE_ZONE_PARAMS_S
{
    UINT8 service_zone_indicator;
    UINT8 service_zone_name[TAPI_UMAN_SERVICE_ZONE_NAME_LENGTH];
} TAPI_UMAN_SERVICE_ZONE_PARAMS_S;

extern TAPI_RESULT_E   
TAPI_UMAN_GetNetworkSelectionMode(
                                  TAPI_UMAN_NETWORK_MODE_E*   pMode 
                                  );

extern TAPI_RESULT_E   
TAPI_UMAN_SetNetworkSelectionMode(
                                  TAPI_UMAN_NETWORK_MODE_E    mode 
                                  );

#ifdef __cplusplus
}
#endif 

#endif  

