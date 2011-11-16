

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PHONE_VOICE_CALL_INTERFACE_H 
#define PHONE_VOICE_CALL_INTERFACE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <TAPI_CALL_General.h>
#include <RC_MsgInterface.h>
#include <qstring.h>
#include <PHONE_CopChannels.h>
#include <ADDRBK_ENG_Def.h>
typedef enum
{
    PHONE_MAKE_CALL_CLIR_TYPE_NONE = 0,
    PHONE_MAKE_CALL_CLIR_TYPE_SHOW,
    PHONE_MAKE_CALL_CLIR_TYPE_HIDE,
}PHONE_MAKE_CALL_CLIR_T;

void 
PHONE_MakeVoiceCall(
                char *teleNo, 
                const QString &displayName=QString::null, 
                bool isFromFixedDial=FALSE, 
                PHONE_MAKE_CALL_CLIR_T CLIRType=PHONE_MAKE_CALL_CLIR_TYPE_NONE,
                TAPI_CALL_LINE_E line =  TAPI_CALL_LINE_CURRENT_EV ,
                const ADDRBK_UID_T& uid = 0
                );

void 
PHONE_MakeRichVoiceCall(
                char *teleNo, 
                const QString &displayName=QString::null, 
                bool isFromFixedDial=FALSE, 
                PHONE_MAKE_CALL_CLIR_T CLIRType=PHONE_MAKE_CALL_CLIR_TYPE_NONE
                );

void PHONE_EndVoiceCall();

bool PHONE_IsEmergencyCallNumber(char *teleNo);

bool PHONE_IsInputtingEmergencyCall(const QString & input);

void PHONE_EditBeforeMakeCall(const QString &teleNo=QString::null,int changeMode=1);

extern "C" void PHONE_MAKEVOICECALL(
                char *teleNo, const QString &displayName, bool isFromFixedDial,
                PHONE_MAKE_CALL_CLIR_T CLIRType, TAPI_CALL_LINE_E line , 
                const ADDRBK_UID_T& uid
                );

typedef void (*PHONE_MAKEVOICECALL_T)(
                char *,const QString &, bool,
                PHONE_MAKE_CALL_CLIR_T,TAPI_CALL_LINE_E , 
                const ADDRBK_UID_T &
                );

extern "C" bool RCMSG_InterfaceShowUI(RC_PAGE_ID_T pageID);

typedef bool (*RCMSG_INTERFACESHOWUI_T)(RC_PAGE_ID_T);

extern "C" void RCMSG_InterfaceHideUI();

typedef void (*RCMSG_INTERFACEHIDEUI_T)();
#endif

