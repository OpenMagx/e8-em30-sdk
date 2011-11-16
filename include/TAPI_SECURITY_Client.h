

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_SECURITY_CLIENT_H   
#define TAPI_SECURITY_CLIENT_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_SETUP_General.h"

#define TAPI_PIN_STATUS_MAX_LENGTH 30

#define TAPI_SECURITY_NO_ACTIVE_USIM_APPLICATION 255

#define TAPI_SECURITY_USIM_ADF_ALPHA_TAG_LENGTH_MAX 66

#define TAPI_SECURITY_RESTORE_USIM_APPLICATION 0xFF

enum 
{
    TAPI_SECURITY_PIN_TYPE_PIN1,           
    TAPI_SECURITY_PIN_TYPE_PIN2,           
    TAPI_SECURITY_PIN_TYPE_PIN_UNIVERSAL,   
    TAPI_SECURITY_PIN_TYPE_NO_PIN        

};
typedef UINT8 TAPI_SECURITY_PIN_TYPE_E;

enum TAPI_APPLICATION_TYPE_ENUM_
{
    TAPI_APP_TYPE_GSM = 0,        
    TAPI_APP_TYPE_USIM,           
    TAPI_APP_TYPE_ISIM,           
    TAPI_APP_TYPE_WIM,            
    TAPI_APP_TYPE_PKCS15,         
    TAPI_APP_TYPE_NONE,           
    TAPI_APP_TYPE_GENERIC,        
    TAPI_APP_TYPE_ALL,            
    TAPI_APP_TYPE_UNKNOWN = 0xFF 
}; typedef UINT8 TAPI_APPLICATION_TYPE;

enum 
{
   TAPI_SECURITY_UPIN_NOT_SUPPORTED = 0, 
   TAPI_SECURITY_UPIN_SUPPORTED_USED,  
   TAPI_SECURITY_UPIN_SUPPORTED_NOT_USED 
};

typedef  UINT8 TAPI_SECURITY_UPIN_UQ_E ;

typedef UINT8 TAPI_TOTAL_PIN_STATUS_A[TAPI_PIN_STATUS_MAX_LENGTH];

typedef UINT8 TAPI_SECURITY_ADF_INDEX_T;

typedef struct _TAPI_SECURITY_SET_PIN_STATUS_S
{
   TAPI_SECURITY_PIN_TYPE_E pin_type;  
   TAPI_PASSWORD_A          password;  
   TAPI_BOOL_STATUS_E       mode;      
}TAPI_SECURITY_SET_PIN_STATUS_S;

typedef struct _TAPI_SECURITY_CHANGE_PASSWORD_S
{
   TAPI_SECURITY_PIN_TYPE_E pin_type;          
   TAPI_PASSWORD_A          oldPassword;       
   TAPI_PASSWORD_A          newPassword;       
}TAPI_SECURITY_CHANGE_PASSWORD_S;

typedef struct _TAPI_SECURITY_UNBLOCK_PASSWORD_S
{
   TAPI_SECURITY_PIN_TYPE_E pin_type;         
   TAPI_PASSWORD_A          pukPassword;      
   TAPI_PASSWORD_A          pinPassword;      
}TAPI_SECURITY_UNBLOCK_PASSWORD_S;

typedef struct _TAPI_SECURITY_VERIFY_PASSWORD_S
{
   TAPI_SECURITY_PIN_TYPE_E pin_type;     
   TAPI_PASSWORD_A          password;     
}TAPI_SECURITY_VERIFY_PASSWORD_S;

typedef struct _TAPI_SECURITY_DISABLE_W_REPLACEMENT_S
{
    TAPI_PASSWORD_A          pinpassword;     
    TAPI_PASSWORD_A          upinpassword;     
}TAPI_SECURITY_DISABLE_W_REPLACEMENT_S;

typedef struct _TAPI_SECURITY_USIM_ADF_INFO_S
{
    TAPI_SECURITY_ADF_INDEX_T adfIndex;          
    TAPI_APPLICATION_TYPE     application_type;
    UINT8                     adfAlphatagLen;    
    UINT8                     adfAlphatag[TAPI_SECURITY_USIM_ADF_ALPHA_TAG_LENGTH_MAX];

}TAPI_SECURITY_USIM_ADF_INFO_S;

typedef struct
{ 
    UINT8 number;
    TAPI_APPLICATION_TYPE application_type;
}TAPI_SECURITY_GET_APP_LIST_REQ_S;

typedef struct _TAPI_SECURITY_PIN_STATUS_IND_S
{
    TAPI_SECURITY_PIN_TYPE_E pinType ; 
    TAPI_SECURITY_PIN_STATUS_E pinStatus ; 
}TAPI_SECURITY_PIN_STATUS_IND_S;

extern TAPI_RESULT_E   
TAPI_SECURITY_SetPinStatus(
                           const TAPI_SECURITY_PIN_TYPE_E pin_type,
                           const TAPI_PASSWORD_A       simPassword,
                           const TAPI_BOOL_STATUS_E    mode 
                           );

extern TAPI_RESULT_E   
TAPI_SECURITY_SetPin1Status(
                            const TAPI_PASSWORD_A       simPassword,
                            const TAPI_BOOL_STATUS_E    mode 
                            );

extern TAPI_RESULT_E   
TAPI_SECURITY_GetPin1Status(
                            const TAPI_CALL_TYPE_E  callType,
                            TAPI_BOOL_STATUS_E*     pStatus 
                            );

extern TAPI_RESULT_E   
TAPI_SECURITY_GetPin2Status(
                            TAPI_SECURITY_PIN2_STATUS_E*    pStatus 
                            );

extern TAPI_RESULT_E   
TAPI_SECURITY_ChangeBarPassword(
                                const TAPI_PASSWORD_A   oldPassword,
                                const TAPI_PASSWORD_A   newPassword 
                                );

extern TAPI_RESULT_E   
TAPI_SECURITY_ChangePinPassword(
                                const TAPI_SECURITY_PIN_TYPE_E pin_type,
                                const TAPI_PASSWORD_A   oldPassword,
                                const TAPI_PASSWORD_A   newPassword 
                                );

extern TAPI_RESULT_E   
TAPI_SECURITY_ChangePin1Password(
                                 const TAPI_PASSWORD_A   oldPassword,
                                 const TAPI_PASSWORD_A   newPassword 
                                 );

extern TAPI_RESULT_E   
TAPI_SECURITY_ChangePin2Password(
                                 const TAPI_PASSWORD_A   oldPassword,
                                 const TAPI_PASSWORD_A   newPassword 
                                 );

extern TAPI_RESULT_E   
TAPI_SECURITY_UnblockPinPassword(
                                 const TAPI_SECURITY_PIN_TYPE_E pinType,
                                 const TAPI_PASSWORD_A   pukPassword,
                                 const TAPI_PASSWORD_A   pinPassword 
                                 );

extern TAPI_RESULT_E   
TAPI_SECURITY_UnblockPin1Password(
                                  const TAPI_PASSWORD_A   pukPassword,
                                  const TAPI_PASSWORD_A   pinPassword 
                                  );

extern TAPI_RESULT_E   
TAPI_SECURITY_UnblockPin2Password(
                                  const TAPI_PASSWORD_A   pukPassword,
                                  const TAPI_PASSWORD_A   pinPassword 
                                  );

extern TAPI_RESULT_E   
TAPI_SECURITY_VerifyPinPassword(
                                const TAPI_SECURITY_PIN_TYPE_E pin_type,
                                const TAPI_PASSWORD_A   password 
                                );

extern TAPI_RESULT_E   
TAPI_SECURITY_VerifyPin1Password(
                                 const TAPI_PASSWORD_A   password 
                                 );

extern TAPI_RESULT_E   
TAPI_SECURITY_VerifyPin2Password(
                                 const TAPI_PASSWORD_A   password 
                                 );

extern TAPI_RESULT_E 
TAPI_SECURITY_GetActivePin(
                           TAPI_SECURITY_PIN_TYPE_E *pPinType
                           );

extern TAPI_RESULT_E 
TAPI_SECURITY_GetNumOfUsim(
                           UINT8 *numOfUsim
                           );

extern TAPI_RESULT_E 
TAPI_SECURITY_GetUsimList(
                          TAPI_SECURITY_ADF_INDEX_T* adfIndex,
                          UINT8                      number,
                          TAPI_SECURITY_USIM_ADF_INFO_S *pAdfInfo
                          );

extern TAPI_RESULT_E 
TAPI_SECURITY_SelectUsim(
                         TAPI_SECURITY_ADF_INDEX_T adfIndex
                         );

extern TAPI_RESULT_E 
TAPI_SECURITY_GetNumberOfPINAttemptsLeft(
                                         TAPI_SECURITY_PIN_TYPE_E pinType, 
                                         UINT8 * pNum
                                         );

extern TAPI_RESULT_E 
TAPI_SECURITY_GetNumberOfPUKAttemptsLeft(
                                         TAPI_SECURITY_PIN_TYPE_E pinType, 
                                         UINT8 * pNum
                                         );

extern TAPI_RESULT_E 
TAPI_SECURITY_GetUPINUsageQualifier( 
                                    TAPI_SECURITY_UPIN_UQ_E *pusageQualifier
                                    );

extern TAPI_RESULT_E 
TAPI_SECURITY_DisablePin1WithReplacement(
                                         const TAPI_PASSWORD_A   pinPassword,
                                         const TAPI_PASSWORD_A   upinPassword 
                                         );

extern TAPI_RESULT_E   
TAPI_SECURITY_VerifySubsidyPassword(
                                    const TAPI_PASSWORD_A               password,
                                    TAPI_SECURITY_SUBSIDY_UNLOCK_E*     pStatus 
                                    );

extern TAPI_RESULT_E   
TAPI_SECURITY_GetPinStatus(
                           TAPI_SECURITY_PIN_STATUS_E*     pStatus 
                           );

extern TAPI_RESULT_E   
TAPI_SECURITY_GetAnyPinStatus(
                              TAPI_SECURITY_PIN_TYPE_E        pin_type,
                              TAPI_SECURITY_PIN_STATUS_E*     pStatus 
                              );

extern TAPI_RESULT_E   
TAPI_SECURITY_IsNeedVerifyPinPassword( 
                                      BOOLEAN* bNeedPin 
                                      );

extern TAPI_RESULT_E   
TAPI_SECURITY_GetTotalPinStatus(
                                TAPI_TOTAL_PIN_STATUS_A pinStatus 
                                );

extern TAPI_RESULT_E  
TAPI_SECURITY_SubsidyLockReset(
                               TAPI_SECURITY_SUBSIDY_RESET_STATUS_E  *pStatus
                               ); 

extern TAPI_RESULT_E 
TAPI_SECURITY_SubsidyAirtelLockIdStatus(
                                        UINT8 lock_id, 
                                        TAPI_SECURITY_SUBSIDY_AIRTEL_LOCKID_STATUS_E    *pStatus
                                        );

extern TAPI_RESULT_E  
TAPI_SECURITY_SubsidyAirtelDeactivate(
                                      UINT8 lock_id,  
                                      TAPI_PASSWORD_A password,  
                                      TAPI_SECURITY_SUBSIDY_AIRTEL_LOCK_DEACTIVATE_S *deact_status
                                      );

extern TAPI_RESULT_E  
TAPI_SECURITY_SubsidyAirtelActivate (
                                     UINT8 lock_id,
                                     TAPI_PASSWORD_A password,
                                     TAPI_SECURITY_SUBSIDY_AIRTEL_LOCKID_STATUS_E *pStatus
                                     );

extern TAPI_RESULT_E  
TAPI_SECURITY_SubsidyVerifyResetPassword(
                                         BOOL rearm_unlock,
                                         TAPI_PASSWORD_A  password,
                                         TAPI_SECURITY_SUBSIDY_UNLOCK_E  *pStatus
                                         ); 

extern TAPI_RESULT_E 
TAPI_SECURITY_SubsidyQueryResetStatus(
                                      TAPI_SECURITY_SUBSIDY_LOCK_RESET_LOCK_STATUS_E *pStatus
                                      );

extern TAPI_RESULT_E 
TAPI_SECURITY_SubsidyIsAirtelOn(
                                TAPI_SECURITY_SUBSIDY_IS_AIRTEL_ON_S *is_airtel_on
                                );

extern TAPI_RESULT_E 
TAPI_SECURITY_GetAppList(
                         TAPI_SECURITY_ADF_INDEX_T *lastSelectedUsimApp, 
                         UINT8 number,
                         TAPI_APPLICATION_TYPE appType,
                         TAPI_SECURITY_USIM_ADF_INFO_S *pAdfInfo
                         );

extern TAPI_RESULT_E 
TAPI_SECURITY_GetNumOfApps(
                           UINT8 *numOfApps, 
                           TAPI_APPLICATION_TYPE appType
                           ); 

#ifdef __cplusplus
}
#endif 

#endif  

