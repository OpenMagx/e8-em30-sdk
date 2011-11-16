

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_USSD_CLIENTINTERFACE_H   
#define TAPI_USSD_CLIENTINTERFACE_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_SETUP_General.h"

extern TAPI_RESULT_E   
TAPI_USSD_MakeRequest( 
                      TAPI_USSD_REQ_APP_MSG_S* pAppMsg 
                      );

extern TAPI_RESULT_E   
TAPI_USSD_VerifyBarPassword( 
                            const TAPI_PASSWORD_A password 
                            );

extern TAPI_RESULT_E   
TAPI_USSD_TranslatePublicMMIString ( 
                                    TAPI_USSD_REQ_APP_MSG_S stringInfo, 
                                    TAPI_USSD_PUB_MMI_CMD_E *pMmiAction 
                                    );

#ifdef __cplusplus
}
#endif 

#endif  
