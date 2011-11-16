

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_FD_CLIENT_H 
#define TAPI_FD_CLIENT_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_SETUP_General.h"

typedef enum    _TAPI_FIXDIALING_EFDN_STATUS_E
{
    TAPI_FIXDIALING_EFDN_FEATURE_OFF_EV     = 0,    
    TAPI_FIXDIALING_EFDN_FEATURE_ON_EV      = 1,    
    TAPI_FIXDIALING_EFDN_FEATURE_UNKNOWN_EV = 255
} TAPI_FIXDIALING_EFDN_STATUS_E;

extern TAPI_RESULT_E   
TAPI_FIXDIALING_AllocateEntry( 
                              INT16* pEntryIndex 
                              );

extern TAPI_RESULT_E   
TAPI_FIXDIALING_SaveEntry(
                          const INT16                         index,
                          const TAPI_PHONE_NUMBER_A           number,
                          const TAPI_PHONEBOOK_NAME_A         name,
                          const TAPI_PHONEBOOK_WRITE_MODE_E   flag
                          );

extern TAPI_RESULT_E   
TAPI_FIXDIALING_DeleteEntry( 
                            const INT16 index 
                            );

extern TAPI_RESULT_E   
TAPI_FIXDIALING_DeleteAllEntries( 
                                 void 
                                 );

extern TAPI_RESULT_E   
TAPI_FIXDIALING_GetEntryList(
                             const UINT16                        startLocation,
                             const UINT16                        endLocation,
                             TAPI_PHONEBOOK_ENTRY_CONTENT_S*     pEntry 
                             );

extern TAPI_RESULT_E   
TAPI_FIXDIALING_GetCapacity(
                            TAPI_PHONEBOOK_CAPACITY_S*  pCapacity 
                            );

extern TAPI_RESULT_E   
TAPI_FIXDIALING_GetLimitation( 
                              TAPI_PHONEBOOK_RANGE_S* pRange 
                              );

extern TAPI_RESULT_E   
TAPI_FIXDIALING_GetExtLimitation( 
                                 UINT16* pExtDigitNum 
                                 );

extern TAPI_RESULT_E   
TAPI_FIXDIALING_GetExtAvailable( 
                                UINT16* pExtAvailNum 
                                );

extern TAPI_RESULT_E   
TAPI_FIXDIALING_SetStatus(
                          const TAPI_BOOL_STATUS_E    status,
                          const TAPI_PASSWORD_A       password 
                          );

extern TAPI_RESULT_E   
TAPI_FIXDIALING_GetStatus(
                          const TAPI_CALL_TYPE_E  callType,
                          TAPI_BOOL_STATUS_E*     pState 
                          );

extern TAPI_RESULT_E   
TAPI_FIXDIALING_GetAvailability(
                                const TAPI_CALL_TYPE_E  callType,
                                TAPI_BOOL_STATUS_E*     pAvailability 
                                );

extern TAPI_RESULT_E   
TAPI_FIXDIALING_GetSyncStatus( 
                              BOOLEAN* bSyncFinished 
                              );

extern TAPI_RESULT_E   
TAPI_FIXDIALING_GetEfdnStatus(
                              TAPI_FIXDIALING_EFDN_STATUS_E*  pEfdnStatus 
                              );

extern TAPI_RESULT_E   
TAPI_FIXDIALING_IsNumberInFixedDialList (
                                         TAPI_PHONE_NUMBER_A number,
                                         BOOLEAN ignoreWildcardChars,
                                         BOOLEAN *pInFixedDialList
                                         );

extern TAPI_RESULT_E 
TAPI_FIXDIALING_GetExtCapacity(
                               TAPI_PHONEBOOK_CAPACITY_S* pCapacity
                               );

#ifdef __cplusplus
}
#endif 

#endif  

