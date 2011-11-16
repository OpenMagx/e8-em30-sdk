

// Copyright (c) 12-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMEVENTDATA_H 
#define MMEVENTDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMResult.h"
#include "MMGeneral.h"

class MMEventData
{
public:
    MMEventData(){}

    virtual ~MMEventData(){}

    virtual MMEventData * clone() = 0;

protected:

private:

};

#endif  
