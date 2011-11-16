

// Copyright (c) 12-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMCONTROLLABLE_H 
#define MMCONTROLLABLE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMInterface.h"
#include "MMResult.h"

class MMControllable
{
public:
    virtual MMResult getControl(MMInterface controlType, void*& pr_control) = 0;

    virtual MMResult getControls(MMInterface*& pr_controlList, int& r_numOfSupportedControls) = 0 ;

protected:
    virtual ~MMControllable(){}

};

#endif  
