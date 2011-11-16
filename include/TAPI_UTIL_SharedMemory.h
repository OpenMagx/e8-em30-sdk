

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef _TAPI_SHAREDMEMORY_H_ 
#define _TAPI_SHAREDMEMORY_H_ 

#ifdef __cplusplus 
extern "C" {
#endif

#include <sys/ipc.h>
#include <sys/types.h>
#include "EZX_TypeDefs.h"
#include "TAPI_Result.h"

#define TAPI_SHARED_MEMORY_DATA_READY    0x02

enum
{
    TAPI_SIM_CERTIFICATE_SHARED_MEMORY_KEY_EV   = 0xbabababa,
    TAPI_SIM_PROVISION_SHARED_MEMORY_KEY_EV,
    TAPI_STK_ICON_SHARED_MEMORY_KEY_EV,
};

typedef enum _SHM_RESULT_E
{
    SHM_RESULT_SUCC,
    SHM_RESULT_FAIL,
    SHM_RESULT_OPEN_ERROR,
    SHM_RESULT_CLOSE_ERROR,
    SHM_RESULT_ATTACH_ERROR,
    SHM_RESULT_DETACH_ERROR,
    SHM_RESULT_DATA_NOT_READY
} SHM_RESULT_E;

extern BOOLEAN          
TAPI_SHM_IsDataReady( 
                     UINT8* pFlag 
                     );

extern void             
TAPI_SHM_SetDataReadyBit( 
                         UINT8* pFlag 
                         );

extern void           
TAPI_SHM_ClearDataReadyBit( 
                           UINT8* pFlag 
                           );

extern SHM_RESULT_E    
TAPI_SHM_Close( 
               INT32 id 
               );

extern SHM_RESULT_E    
TAPI_SHM_Open(
               INT32*  pId,
               key_t   key,
               size_t  size,
               INT32   flag 
               );

extern SHM_RESULT_E    
TAPI_SHM_Detach( 
                const void* pAddr 
                );

extern SHM_RESULT_E    
TAPI_SHM_Attach(
                void**          ppAddr,
                INT32           id,
                const void*     pShmAddr,
                INT32           flag 
                );

extern BOOLEAN          
TAPI_SHM_IsOverflow(
                    UINT32  sizeUsed,
                    UINT32  sizeAdd,
                    INT32   shmid 
                    );

extern BOOLEAN         
TAPI_SHM_GetSize(
                 INT32       shmid,
                 UINT32*     pSize 
                 );

extern BOOLEAN         
TAPI_SHM_Reallocate(
                    INT8**          ppNewAddr,
                    INT32*          pNewId,
                    const INT8*     pOldAddr,
                    INT32           oldId,
                    INT32           key,
                    UINT32          addSize 
                    );

#ifdef __cplusplus
}

#endif
#endif 

