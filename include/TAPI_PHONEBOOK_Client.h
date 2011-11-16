

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_PHONEBOOK_CLIENT_H 
#define TAPI_PHONEBOOK_CLIENT_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_SETUP_General.h"

extern TAPI_RESULT_E   
TAPI_PHONEBOOK_AllocateEntry( 
                             INT16* pEntryIndex 
                             );

extern TAPI_RESULT_E   
TAPI_PHONEBOOK_SaveEntry(
                         const INT16                         index,
                         const TAPI_PHONE_NUMBER_A           number,
                         const TAPI_PHONEBOOK_NAME_A         name,
                         const TAPI_PHONEBOOK_WRITE_MODE_E   flag 
                         );

extern TAPI_RESULT_E   
TAPI_PHONEBOOK_DeleteEntry( 
                           const INT16 index 
                           );

extern TAPI_RESULT_E   
TAPI_PHONEBOOK_GetEntryList(
                            const UINT16                        startLocation,
                            const UINT16                        endLocation,
                            TAPI_PHONEBOOK_ENTRY_CONTENT_S*     pEntry 
                            );

extern TAPI_RESULT_E   
TAPI_PHONEBOOK_GetCapacity(
                           TAPI_PHONEBOOK_CAPACITY_S*  pCapacity 
                           );

extern TAPI_RESULT_E   
TAPI_PHONEBOOK_GetRange( 
                        TAPI_PHONEBOOK_RANGE_S* pRange 
                        );

extern TAPI_RESULT_E   
TAPI_PHONEBOOK_GetExtRange( 
                           UINT16* pExtDigitNum 
                           );

extern TAPI_RESULT_E   
TAPI_PHONEBOOK_GetExtAvailable( 
                               UINT16* pExtAvailNum 
                               );

extern TAPI_RESULT_E   
TAPI_PHONEBOOK_GetSyncStatus( 
                             BOOLEAN* bSyncFinished 
                             );

extern TAPI_RESULT_E   
TAPI_PHONEBOOK_DeleteAllEntries( 
                                void 
                                );

extern TAPI_RESULT_E 
TAPI_PHONEBOOK_GetExtCapacity( 
                              TAPI_PHONEBOOK_CAPACITY_S* pCapacity 
                              );

#ifdef __cplusplus
}
#endif 

#endif  

