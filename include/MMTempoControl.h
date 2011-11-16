

// Copyright (c) 20-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMTEMPOCONTROL_H 
#define MMTEMPOCONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMRateControl.h"

class MMTempoControl : public MMRateControl
{
public:
    virtual MMResult setTempo (int desTempo, int& r_newTempo) = 0;

    virtual MMResult getTempo (int& r_curTempo) = 0;

protected:
    virtual ~MMTempoControl(){}

};

#endif  
