

// Copyright (c) 26-May-07 - 2008 Motorola, Inc. All rights reserved.



#ifndef __ES_SUB_API_H__
#define __ES_SUB_API_H__

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ES_API.h"

class ES_EventHandler
{
public:
    virtual ~ES_EventHandler(){}

    virtual void handleEvent(const ES_Event &event) = 0;
};

class ES_EventSubscriber
{
public:
    static int subscribe (
        const char * eventType,
        bool bPrefix,
        ES_EventHandler * handler,
        const char * defaultFilterConstraint = "",
        const char * filter = "",
        const char * filterConstraint = "",
        bool bUnique = false
    );

    static int unsubscribe(
        const char * eventType,
        ES_EventHandler * handler
    );

    static int unsubscribe(
        const char * eventType
    );

    static int unsubscribe (
        int nSID
    );

    static int subscribe (
        const char * eventType,
        bool bPrefix,
        const char * defaultFilterConstraint = "",
        const char * filter = "",
        const char * filterConstraint = "",
        int * pSID = 0,
        bool bUnique = false
    );

    static int registerStartup (
        const char * correlationID,
        const void * pAMstartupBlob,
        int nAMstartupBlobLen,
        const char * eventType,
        bool bPrefix,
        const char * defaultFilterConstraint = "",
        const char * filter = "",
        const char * filterConstraint = "",
        bool bUnique = false,
        bool bPersistent = false
    );

    static int connectStartup(
        const char * correlationID,
        int * pSID = 0,
        bool bOnlyOneEvent = false
    );

    static int connectStartup(
        const char * correlationID,
        ES_EventHandler * handler,
        bool bOnlyOneEvent = false
    );

    static int unregisterStartup(
        const char * correlationID,
        const char * eventType
    );

    static int getReadFD();

    static const ES_Event * getEvent(
        int * pErrorCode = 0,
        int * pSID = 0
    );

    static int Done();
};

#endif
