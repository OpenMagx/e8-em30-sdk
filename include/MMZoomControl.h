

// Copyright (c) 20-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMZOOMCONTROL_H 
#define MMZOOMCONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMResult.h"

enum MMZoomLevels
{
    MMZOOM_LEVEL_NEXT = -1001,

    MMZOOM_LEVEL_PREVIOUS = -1002,

    MMZOOM_LEVEL_UNKNOWN = -1004

};
typedef int MMZoomLevelType;

class MMZoomControl
{
public:
    virtual MMResult getDigitalZoom(int& r_zoom) = 0;

    virtual MMResult getDigitalZoomLevels(int& r_numOfLevels) = 0;

    virtual MMResult getMaxDigitalZoom(int& r_maxZoom) = 0;

    virtual MMResult getMaxOpticalZoom(int& r_maxZoom) = 0;

    virtual MMResult getMinFocalLength(int& r_length) = 0;

    virtual MMResult getOpticalZoom(int& r_zoom) = 0;

    virtual MMResult getOpticalZoomLevels(int& r_numOfLevels) = 0;

    virtual MMResult setDigitalZoom(const int c_level) = 0;

    virtual MMResult setOpticalZoom(const int c_level) = 0;

    virtual MMResult startSmoothZoom(const int c_speed, const int c_targetZoom, const int c_notifyInterval) = 0;

    virtual MMResult stopSmoothZoom() = 0;

    virtual MMResult getRealPhotoResolution(int& r_width, int& r_height) = 0;

protected:
    virtual ~MMZoomControl(){}

};

#endif  
