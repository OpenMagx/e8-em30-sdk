

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_STK_CLIENT_INTERFACE_H
#define TAPI_STK_CLIENT_INTERFACE_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_STK_AppData.h"
#include "TAPI_General.h"
#include "TAPI_Result.h"

typedef enum    _TAPI_STK_IMAGE_CODING_SCHEME_E
{
    MONO_IMAGE_CODING_SCHEME_EV = 0x11,
    COLOR_IMAGE_CODING_SCHEME_EV= 0x21
} TAPI_STK_IMAGE_CODING_SCHEME_E;

typedef struct  _TAPI_STK_ICON_SIZE_S
{
    UINT8   width;
    UINT8   height;
} TAPI_STK_ICON_SIZE_S;

void*        
TAPI_STK_ConvertRawDataToAppMsg(
                                UINT8*  pRawData,
                                UINT16  len 
                                );

extern BOOLEAN         
TAPI_STK_SendResponse(
                      TAPI_APP_MSGID_T                    msgid,
                      TAPI_STK_RSP_APP_RESPONSE_MSG_S*    pAppResp 
                      );

extern BOOLEAN         
TAPI_STK_NotifyUserActivityEvent( 
                                 void 
                                 );

extern BOOLEAN         
TAPI_STK_NotifyIdleScreenAvailableEvent( 
                                        void 
                                        );

extern BOOLEAN         
TAPI_STK_NotifyBrowserTerminationEvent(
                                       TAPI_STK_BROWSER_TERMINATION_CAUSE_E    cause 
                                       );

extern BOOLEAN         
TAPI_STK_SendClassEResponse(
                            TAPI_APP_MSGID_T                        msgid,
                            const TAPI_STK_RSP_CLASS_E_APP_MSG_S*   pAppData 
                            );

extern TAPI_RESULT_E   
TAPI_STK_GetIcon(
                 UINT16                          id,
                 TAPI_STK_IMAGE_CODING_SCHEME_E  scheme,
                 TAPI_STK_ICON_SIZE_S*           pSize,
                 UINT8*                          pData,
                 UINT16*                         pDataLen,
                 UINT8*                          pClut,
                 UINT16*                         pClutLen,
                 UINT8*                          pRaster 
                 );

extern BOOLEAN         
TAPI_STK_RequestIcon( 
                     void 
                     );

extern TAPI_RESULT_E 
TAPI_STK_SoftModemReady( void );

extern TAPI_RESULT_E  
TAPI_STK_SendATResponse( 
                        UINT8 * at_response  
                        );

#ifdef __cplusplus
}
#endif 

#endif  

