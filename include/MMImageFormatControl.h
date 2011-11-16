

// Copyright (c) 20-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMIMAGE_FORMATCONTROL_H 
#define MMIMAGE_FORMATCONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMResult.h"
#include "MMFormatControl.h"

class MMImageFormatControl : public MMFormatControl
{
public:
    virtual MMResult getEstimatedImageSize(int& r_size) = 0;

protected:
    virtual ~MMImageFormatControl(){}

};

#endif  
