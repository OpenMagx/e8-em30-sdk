

// Copyright (c) 17-Jul-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PP_SETTINGS_H 
#define PP_SETTINGS_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ImpsObject.h"
#include "EZX_TypeDefs.h"

class PPSettings : public ImpsObject
{
public:

    static PPSettings* getNewInstance();

    virtual void setMinNotificationRate(UINT32 notificationRate) = 0;

    virtual UINT32 getMinNotificationRate() const = 0;
};

#endif  
