

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PHONE_CALLSETUPINTERFACE_H
#define PHONE_CALLSETUPINTERFACE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>

typedef enum
{
    PHONE_SETUP_CAMERA_MUTE_ALWAYS = 0,
    PHONE_SETUP_CAMERA_MUTE_ON,
    PHONE_SETUP_CAMERA_MUTE_OFF,
} PHONE_SETUP_CAMERA_MUTE_T; 

bool PHONE_isAutoFallbackVoiceCall();  

bool PHONE_GetCameraMute(PHONE_SETUP_CAMERA_MUTE_T& flag); 

bool PHONE_isAutoRecord();

QString PHONE_GetCameraOffImage();     

#endif 

