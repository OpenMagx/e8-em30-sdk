

// Copyright (c) 09-Aug-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMFOCUSSTATUSDATA_H 
#define MMFOCUSSTATUSDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMEventData.h"

enum MMFocusState
{
    MMFOCUS_AF_CONVERGE_FAIL = -1,

    MMFOCUS_AF_CONVERGING = 0,

    MMFOCUS_AF_CONVERGED
};
typedef int MMFocusStateType;

class MMFocusStatusData: public MMEventData
{

public:
    MMFocusStatusData(MMFocusStateType cause);

    ~MMFocusStatusData();

    virtual MMEventData * clone();

    MMFocusStateType getCurrentStatus() const;

protected:

private:
    MMFocusStateType a_currentStatus;

};

#endif  

