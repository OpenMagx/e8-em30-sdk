

// Copyright (c) 16-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef _SETUP_SECURITY_UTIL_H_
#define _SETUP_SECURITY_UTIL_H_

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>
#include <quuid.h>
#include "EZX_TypeDefs.h"
#include "ZMessageDlg.h"
#include <qwidget.h>
#include <qthread.h>
#include "TAPI_Result.h"

#define  WAIT_NOTICE_RESOURCEID "in_progress_ani_pop.g" 

typedef enum{
    PIN_OK=0,
    PIN_INVALID,

    SIM_PIN_LAST_TRY,
    SIM_PIN1_BLOCKED,             
    SIM_PIN1_PERMANENT_BLOCKED,   

    SIM_PIN2_BLOCKED,             
    SIM_PIN2_PERMANENT_BLOCKED,   

    SIM_UPIN_BLOCKED,             
    SIM_UPIN_PERMANENT_BLOCKED,   

    SET_SIM_WRONG,
    SET_SIM_FAILURE,
    SET_SIM_NOT_INSERTED,
    SET_SIM_PIN_REQUIRED,
    SET_SIM_PUK_REQUIRED,
    SET_SIM_PIN2_REQUIRED,
    SET_SIM_PUK2_REQUIRED,

    SET_USIM_PUK_REQUIRED,   
    SET_NO_NETWORK_SERVICE, 
    SET_NETWORK_BUSY,       
    SET_NETWORK_TIMEOUT,
    SET_NETWORK_NOT_ALLOWED,
    SET_NETWORK_ACCESS_FAILURE,              
    SET_PASSWD_OPERATION_NOT_SUPPORTED,      
    SET_PASSWD_OPERATION_NOT_ALLOWED,
    SET_SERVICE_OPTION_NOT_SUPPORTED,   

    SET_MEMORY_FULL,
    SET_UNKNOWN
}SETUP_PIN_ERR_T;

typedef enum{
    SETUP_SECURITY_SIMPIN_EV=0,
    SETUP_SECURITY_SIMPIN2_EV,
    SETUP_SECURITY_UNLOCKCODE_EV,
    SETUP_SECURITY_SECURITYCODE_EV,
    SETUP_SECURITY_CALLBARRINGPWD_EV,
    SETUP_SECURITY_SIMLOCK_EV,
    SETUP_SECURITY_LOCKNOW_EV,
    SETUP_SECURITY_LOCKATPOWERON_EV,
    SETUP_SECURITY_SECURITYCODE_VIEWPRIVATECONTACT_EV,
    SETUP_SECURITY_SECURITYCODE_SAVEPRIVATECONTACT_EV,
    SETUP_SECURITY_LOCKAPPLICATION_EV,
    SETUP_SECURITY_SAVE_HIDDENKEY_EV,
    SETUP_SECURITY_VIEW_HIDDENKEY_EV,
    SETUP_SECURITY_APP_PIN_EV,
    SETUP_SECURITY_APP_PIN2_EV,
    SETUP_SECURITY_UPIN_EV,
    SETUP_SECURITY_PINTYPE_UNKNOWN_EV
}SETUP_SECURITY_PINTYPE_E;

typedef enum{
    SETUP_SECURITY_SK_OK_EV=0,
    SETUP_SECURITY_SK_VERIFY_EV,
    SETUP_SECURITY_SK_SAVE_EV,
    SETUP_SECURITY_SK_LOCK_EV,
    SETUP_SECURITY_SK_UNLOCK_EV,
    SETUP_SECURITY_SK_LOCKNOW_EV,
    SETUP_SECURITY_SK_LOCKATPOWERON_EV,
    SETUP_SECURITY_SK_LOCKAPPLICATION_EV,
    SETUP_SECURITY_SK_UNLOCKAPPLICATION_EV,
    SETUP_SECURITY_SK_SUBMIT_EV,
    SETUP_SECURITY_SK_ENTER_EV
}SETUP_SECURITY_SKTYPE_E;

typedef enum{
    SETUP_SECURITY_VALIDATION_OK_EV=0,
    SETUP_SECURITY_VAILDATION_FAILED_EV,
    SETUP_SECURITY_USER_CANCEL_EV,
    SETUP_SECURITY_SIM_PIN1_BLOCKED_EV,
    SETUP_SECURITY_SIM_PIN2_BLOCKED_EV,    
    SETUP_SECURITY_SIM_PIN2_PERMANENT_BLOCKED_EV,    
    SETUP_SECURITY_SET_UNKNOWN_EV
}SETUP_SECURITY_PINVERIFY_ERR_E;

typedef enum{
    SETUP_SECURITY_APP_UNLOCKED_EV=0,
    SETUP_SECURITY_APP_LOCKED_EV,
    SETUP_SECURITY_APP_VIEWONLY_EV,
    SETUP_SECURITY_APP_UNKNOWN_EV
}SETUP_SECURITY_APPLOCK_SETTING_E;   

class SETUP_SECURITY_Util: public QObject
{
   Q_OBJECT

public:
    SETUP_SECURITY_Util();

    virtual ~SETUP_SECURITY_Util();

    static void showCallBarringUI();

    static bool verifyPin(SETUP_SECURITY_PINTYPE_E& pinType,
                        const SETUP_SECURITY_SKTYPE_E& skType,
                        SETUP_SECURITY_PINVERIFY_ERR_E& value,QWidget* parent=0);

    static bool getAppLockSetting(const QUuid& app_ID,
        SETUP_SECURITY_APPLOCK_SETTING_E& value);    

    void  appLockCheck(const QUuid& app_ID,SETUP_SECURITY_APPLOCK_SETTING_E checkType=SETUP_SECURITY_APP_LOCKED_EV);

    static bool  appLockCheck_modelUI(const QUuid& app_ID,SETUP_SECURITY_APPLOCK_SETTING_E checkType=SETUP_SECURITY_APP_LOCKED_EV);

    static bool isSupportViewOnly(QUuid item);

    bool verifyPin_modelessUI(SETUP_SECURITY_PINTYPE_E& pinType,
                        const SETUP_SECURITY_SKTYPE_E& skType,
                        SETUP_SECURITY_PINVERIFY_ERR_E& value,QWidget* parent=0);

protected slots:
    void verifyAccept();

    void verifyCancel(); 

    void slotVerifyResult(SETUP_SECURITY_PINTYPE_E,SETUP_SECURITY_PINVERIFY_ERR_E);

signals:
    void verifySuccess();

    void verifyFail();

    void verifyResult(SETUP_SECURITY_PINTYPE_E,SETUP_SECURITY_PINVERIFY_ERR_E);

private:
    void verifyUnlockCode(const QUuid &appId,SETUP_SECURITY_PINVERIFY_ERR_E& value, bool isModel);

    bool checkPinBlock(SETUP_SECURITY_PINTYPE_E& pinType,SETUP_SECURITY_PINVERIFY_ERR_E& value);
    QWidget * ptrDlg;         
    ZMessageDlg * ptrMsgDlg;                                      
};

extern "C"
{
    bool  SETUP_SECURITY_Util_appLockCheck_modelUI(const char * appUid, int checkType = 1 );

}

#endif 
