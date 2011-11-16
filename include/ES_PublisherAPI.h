

// Copyright (c) 26-May-07 - 2008 Motorola, Inc. All rights reserved.



#ifndef __ES_PUB_API_H__
#define __ES_PUB_API_H__

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ES_API.h"

class ES_EventPublisher
{
public:
    static int publish(
        const ES_Event &event,
        bool keepConnectionOpen = true,
        bool acknowledged = false
    );

    static int isRegistered(
        const char * topic,
        int pid = -1
    );

    static int closeConnection();
};

#endif
