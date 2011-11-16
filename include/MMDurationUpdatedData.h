

// Copyright (c) 20-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMDURATIONUPDATEDDATA_H 
#define MMDURATIONUPDATEDDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMEventData.h"

class MMDurationUpdatedData: public MMEventData
{

public:
    MMDurationUpdatedData(MMTime newDuration);

    ~MMDurationUpdatedData();

    virtual MMEventData * clone();

    MMTime getDuration() const;

protected:

private:

    MMTime a_newDuration;
};

#endif  

