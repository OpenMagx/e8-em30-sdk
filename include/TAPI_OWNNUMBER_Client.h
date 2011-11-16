

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_OWNNUMBER_CLIENT_H 
#define TAPI_OWNNUMBER_CLIENT_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_SETUP_General.h"

extern TAPI_RESULT_E   
TAPI_OWNNUMBER_SaveEntry(
                         const INT16                 index,
                         const TAPI_PHONE_NUMBER_A   number,
                         const TAPI_PHONEBOOK_NAME_A name 
                         );

extern TAPI_RESULT_E   
TAPI_OWNNUMBER_DeleteEntry( 
                           const INT16 index 
                           );

extern TAPI_RESULT_E   
TAPI_OWNNUMBER_GetEntry(
                        const UINT16                        startLocation,
                        const UINT16                        endLocation,
                        TAPI_PHONEBOOK_ENTRY_CONTENT_S*     pEntry 
                        );

extern TAPI_RESULT_E   
TAPI_OWNNUMBER_GetCapacity(
                           TAPI_PHONEBOOK_CAPACITY_S*  pCapacity 
                           );

extern TAPI_RESULT_E   
TAPI_OWNNUMBER_GetRange( 
                        TAPI_PHONEBOOK_RANGE_S* pRange 
                        );

extern TAPI_RESULT_E   
TAPI_OWNNUMBER_GetExtRange( 
                           UINT16* pExtDigitNum 
                           );

extern TAPI_RESULT_E 
TAPI_OWNNUMBER_GetExtAvailable( 
                               UINT16* pExtAvailNum 
                               );

#ifdef __cplusplus
}
#endif 

#endif  

