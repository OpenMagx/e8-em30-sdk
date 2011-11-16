

// Copyright (c) 11-Jul-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PP_PRESENCE_PROVIDER_H 
#define PP_PRESENCE_PROVIDER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ImpsObject.h"

#include "PPTypes.h"
#include "PPSettings.h"
#include "PPListener.h"

class PPPresenceManager;

class PPPresenceProvider : public ImpsObject
{
public:

    static PPPresenceProvider * getInstance();

    virtual PP_RETURN_STATUS_TYPE initialize (const PPSettings* cp_presenceProviderSettings) = 0;

    virtual PP_RETURN_STATUS_TYPE finalize () = 0;

    virtual PP_RETURN_STATUS_TYPE attach (PPListener* p_clientListener) = 0;

    virtual PP_RETURN_STATUS_TYPE detach (PPListener* p_clientListener) = 0;

    virtual PP_RETURN_STATUS_TYPE getPresenceManager(PPPresenceManager** p_presenceManager_out) = 0;

    virtual const PPSettings * getPPSettings() = 0;
};

#endif  
