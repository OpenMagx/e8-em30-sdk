

// Copyright (c) 25-Jul-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMCAMERAVFDATACONTROL_H 
#define MMCAMERAVFDATACONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMResult.h"
#include "MMString.h"
#include "MMStringList.h"

class MMCameraVFDataControl
{
public:
    virtual MMResult setFormat(const int c_formatIndex) = 0;

    virtual MMResult getSupportedFormat(MMStringList &r_formatlist) = 0;

    virtual MMResult setFramerate(const int c_fps) = 0;

    virtual MMResult getMaxFramerate(int &r_fps) = 0;

    virtual MMResult startSendFrames() = 0;

    virtual MMResult stopSendFrames() = 0;

protected:
    virtual ~MMCameraVFDataControl(){}

};

#endif  

