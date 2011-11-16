

// Copyright (c) 15-Jun-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMVIDEOFORMATCONTROL_H 
#define MMVIDEOFORMATCONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMResult.h"
#include "MMFormatControl.h"

class MMVideoFormatControl : public MMFormatControl
{
public:
    virtual MMResult getEstimatedVideoTotalDuration(unsigned int& r_duration) = 0;

    virtual MMResult setContainerFormat(const MMString & cr_format) = 0;

    virtual MMResult getContainerFormat(MMString& r_format) = 0;

    virtual MMResult getSupportedContainerFormats(MMStringList& r_formatList) = 0;

protected:
    virtual ~MMVideoFormatControl(){}

};

#endif  
