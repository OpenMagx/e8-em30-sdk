

// Copyright (c) 09-Aug-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMAUDIO_FORMATCONTROL_H 
#define MMAUDIO_FORMATCONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMResult.h"
#include "MMFormatControl.h"

class MMAudioFormatControl : public MMFormatControl
{
public:
    virtual MMResult getEstimatedTotalDuration(unsigned int& r_duration) = 0;

protected:
    virtual ~MMAudioFormatControl(){}

};

#endif  
