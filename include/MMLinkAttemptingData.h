

// Copyright (c) 12-Jul-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMLINKATTEMPTINGDATA_H 
#define MMLINKATTEMPTINGDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMEventData.h"

class MMLinkAttemptingData: public MMEventData
{

public:
    MMLinkAttemptingData(const char* cp_profileName);

    ~MMLinkAttemptingData();

    virtual MMEventData * clone();

    const char * getProfileName() const;

protected:

private:
    char * ap_profileName;
};

#endif  

