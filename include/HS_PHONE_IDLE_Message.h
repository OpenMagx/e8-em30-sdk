

// Copyright (c) 09-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef HS_PHONE_IDLE_MESSAGE_H
#define HS_PHONE_IDLE_MESSAGE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#define IDLE_PASSTO_PHONE_CHANNEL "LJ/IdleToPhoneChannel"

#define PHONE_PASSTO_IDLE_CHANNEL "LJ/PhoneToIdleChannel"

#define MSG_RECENT_CALL  "showRecentCall"

#define MSG_SECURITY_ENTERPHONELOCK    "EnterPhoneLock"

#define MSG_SECURITY_PROMPTPIN1BLOCKED "PromptPIN1Blocked"

#define MSG_SECURITY_PROMPTPIN2BLOCKED "PromptPIN2Blocked"

#define MSG_SEND_INITIALTEXT_EMERGENCY_EDITDLG  "setInitialText"

#define MSG_SEND_KEYEVENT_EMERGENCY_EDITDLG  "sendKeyEvent"

#define MSG_SET_CHARGEONLY "setChargeOnly"

#define MSG_SET_NORMALPOWERON_MODE "setNormalPowerOnMode"

#define MSG_SHOW_IDLE_SCREEN "ShowIdleScreen"

#define MSG_SHOW_EMERGENCY_EDITDLG "showEmergencyEditDlg"

#define MSG_CLOSE_EMERGENCY_EDITDLG "closeEmergencyEditDlg"

#define MSG_CLOSE_USB_EMERGENCY_EDITDLG "closeUsbEmergencyEditDlg"

#define MSG_STK_IDLE_TEXT       "STK_IDLETEXT"

#define STK_FORIDLE_FILE  "/tmp/getstkpixmap.png"

#define MSG_PHONE_IDLE_LAUNCH_PROFILE  "launchProfile"

#ifdef FEAT_KODIAK_PTT

#define KODIAK_PTT_UI_CHANNEL "LJ/KodiakPTTUIChannel"

#define KODIAK_PTT_REQ_LAUNCH_CONTACT_LIST_MSG "KODIAK_PTT_REQ_LAUNCH_CONTACT_LIST"

#endif

#endif 
