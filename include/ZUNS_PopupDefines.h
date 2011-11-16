

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef _ZUNS_POPUPDEFINES_H_
#define _ZUNS_POPUPDEFINES_H_

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

enum UNS_PRIO_T
{
    UNS_NONE,

    UNS_SYSTEM,                 
    UNS_EVENT,                  
    UNS_TIME_CRITICAL,          
    UNS_INCOMING_CALL,          

    UNS_BOUNDARY,               
};

enum UNS_DISMISSED_REASON_T
{
    UNS_LSK_CLICKED     = -1,   
    UNS_RSK_CLICKED     = -2,   
    UNS_END_PRESSED     = -3,   
    UNS_TIMED_OUT       = -4,   
    UNS_INTERRUPTED     = -5,   
    UNS_FAIL_TO_SHOW    = -6,   
    UNS_FLIP_CLOSED     = -7,   
    UNS_SLIDER_CLOSED   = -8,   
};

#define UNS_QWSSOCKET_FILE "/tmp/uns_qwssocket"

#endif  
