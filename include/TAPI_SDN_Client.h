

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_SDN_CLIENT_H
#define TAPI_SDN_CLIENT_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_SETUP_General.h"

extern TAPI_RESULT_E   
TAPI_SDN_GetEntryList(
                      const UINT16                        startLocation,
                      const UINT16                        endLocation,
                      TAPI_PHONEBOOK_ENTRY_CONTENT_S*     pEntry 
                      );

extern TAPI_RESULT_E   
TAPI_SDN_GetCapacity( 
                     TAPI_PHONEBOOK_CAPACITY_S* pCapacity 
                     );

extern TAPI_RESULT_E   
TAPI_SDN_GetRange( 
                  TAPI_PHONEBOOK_RANGE_S* pRange 
                  );

extern TAPI_RESULT_E   
TAPI_SDN_GetSyncStatus( 
                       BOOLEAN* bSyncFinished 
                       );

extern TAPI_RESULT_E   
TAPI_SDN_GetAvailability( 
                         TAPI_BOOL_STATUS_E* pAvailability 
                         );

#ifdef __cplusplus
}
#endif 

#endif  

