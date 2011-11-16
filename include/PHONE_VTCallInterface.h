

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PHONE_VT_CALL_INTERFACE_H 
#define PHONE_VT_CALL_INTERFACE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

void PHONE_MakeVideoCall( const char *teleNo);

extern "C" void PHONE_MAKEVIDEOCALL(const char *teleNo);

typedef void (*PHONE_MAKEVIDEOCALL_T)(const char*);

void PHONE_EndVTCall();
#endif

