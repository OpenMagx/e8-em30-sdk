

// Copyright (c) 19-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMSTOPTIMECONTROL_H 
#define MMSTOPTIMECONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMResult.h"
#include "MMGeneral.h"

#define MMSTOPTIME_CONTROL_RESET (0)

class MMStopTimeControl 
{
public:
    virtual MMResult getStopTime(MMTime& r_stopTime) const = 0;

    virtual MMResult setStopTime(MMTime stopTime) = 0;

protected:
    virtual ~MMStopTimeControl(){}

};

#endif  
