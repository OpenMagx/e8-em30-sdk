

// Copyright (c) 15-Jun-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMSHUTTERFEEDBACKCONTROL_H  
#define MMSHUTTERFEEDBACKCONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMResult.h"
#include "MMString.h"

class MMShutterFeedbackControl
{
public:
    virtual MMResult enableShutterFeedback(const bool c_enable) = 0;

    virtual MMResult isShutterFeedbackEnabled(bool& r_enable ) = 0;

    virtual MMResult customizeShutterSound(const MMString & cr_locator) = 0;

    virtual MMResult getCustomizedShutterSound (MMString& r_locator)= 0;

    virtual MMResult beginShutterFeedback() = 0;

    virtual MMResult playTimerSound(const MMString & cr_locator) = 0;

    virtual MMResult cancelTimerSound() = 0;

protected:
    virtual ~MMShutterFeedbackControl(){}
};

#endif  
