

// Copyright (c) 12-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMVOLUMECONTROL_H 
#define MMVOLUMECONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMResult.h"
#include "MMGeneral.h"

#define MIN_VOLUME_LEVEL       0
#define MAX_VOLUME_LEVEL       100

#define MM_MIN_VOLUME_LEVEL    0

#define MM_MAX_VOLUME_LEVEL    100  

class MMVolumeControl 
{
public:
    virtual MMResult getLevel(int& r_volumeLevel) const = 0;

    virtual MMResult isMuted(bool& r_mute) = 0;

    virtual MMResult setLevel(int level) = 0;

    virtual MMResult setMute(bool muteStatus) = 0;

protected:
    virtual ~MMVolumeControl(){}
};

#endif  
