

// Copyright (c) 23-May-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMDEVICEUNAVAILABLEDATA_H 
#define MMDEVICEUNAVAILABLEDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMEventData.h"

class MMDeviceUnavailableData: public MMEventData
{

public:
    MMDeviceUnavailableData(const char* cp_deviceName);

    ~MMDeviceUnavailableData();

    virtual MMEventData * clone();

    const char * getDeviceName() const;

protected:

private:
    char * ap_deviceName;
};

#endif  

