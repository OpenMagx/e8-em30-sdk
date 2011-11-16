

// Copyright (c) 20-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMRATECONTROL_H 
#define MMRATECONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMResult.h"
#include "MMGeneral.h"

class MMRateControl
{
public:
    virtual MMResult setRate(int desRate, int& r_newRate) = 0;

    virtual MMResult getRate(int& r_curRate) = 0;

    virtual MMResult getMaxRate(int& r_maxRate) = 0;

    virtual MMResult getMinRate(int& r_minRate) = 0;

protected:
    virtual ~MMRateControl(){}

};

#endif  
