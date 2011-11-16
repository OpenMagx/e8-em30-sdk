

// Copyright (c) 20-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMPITCHCONTROL_H 
#define MMPITCHCONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMResult.h"
#include "MMGeneral.h"

class MMPitchControl
{
public:
    virtual MMResult setPitch (int desPitch, int& r_newPitch) = 0;

    virtual MMResult getPitch (int& r_curPitch) = 0;

    virtual MMResult getMaxPitch (int& r_maxPitch) = 0;

    virtual MMResult getMinPitch (int& r_minPitch) = 0;

protected:
    virtual ~MMPitchControl(){}

};

#endif  
