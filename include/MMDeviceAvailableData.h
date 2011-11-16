

// Copyright (c) 23-May-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMDEVICEAVAILABLEDATA_H 
#define MMDEVICEAVAILABLEDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMEventData.h"

class MMDeviceAvailableData: public MMEventData
{

public:
    MMDeviceAvailableData(const char* cp_deviceName);

    ~MMDeviceAvailableData();

    virtual MMEventData * clone();

    const char * getDeviceName() const;

protected:

private:
    char * ap_deviceName;
};

#endif  

