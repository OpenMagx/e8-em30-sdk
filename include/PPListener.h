

// Copyright (c) 11-Jul-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PP_LISTENER_H 
#define PP_LISTENER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "PPTypes.h"
#include "ImpsObject.h"

class PPListener : public virtual ImpsObject
{
public:

    virtual void
    onPresenceUpdate() = 0;

    virtual void
    onRequestComplete(const PP_REQUEST_RESPONSE_T& cr_requestResponseInfo) = 0;

};

#endif  
