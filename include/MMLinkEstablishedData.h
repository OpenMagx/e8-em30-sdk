

// Copyright (c) 10-Jul-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMLINKESTABLISHEDDATA_H 
#define MMLINKESTABLISHEDDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMEventData.h"

class MMLinkEstablishedData: public MMEventData
{

public:
    MMLinkEstablishedData(const char* cp_profileName);

    ~MMLinkEstablishedData();

    virtual MMEventData * clone();

    const char * getProfileName() const;

protected:

private:
    char * ap_profileName;
};

#endif  

