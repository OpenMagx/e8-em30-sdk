

// Copyright (c) 20-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMVOLUMECHANGEDDATA_H 
#define MMVOLUMECHANGEDDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMEventData.h"

class MMVolumeChangedData: public MMEventData
{

public:
    MMVolumeChangedData(int volumeLevel);

    ~MMVolumeChangedData();

    virtual MMEventData * clone();

    int getVolumeLevel() const;

protected:

private:
    int a_volumeLevel;

};

#endif  
