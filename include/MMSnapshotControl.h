

// Copyright (c) 15-Jun-07 - 2008 Motorola, Inc. All rights reserved.



#ifndef MMSNAPSHOTCONTROL_H 
#define MMSNAPSHOTCONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMResult.h"
#include "MMGeneral.h"
#include "MMString.h"

#define MM_FREEZE_AND_CONFIRM     10001

class MMSnapshotControl 
{
public:

    virtual MMResult setImageLocation(const MMString & cr_locator) = 0;

	virtual MMResult start(int maxShots) = 0;

	virtual MMResult stop() = 0;

    virtual MMResult unfreeze() = 0;

    virtual MMResult enableSendPreviewData(bool b_enable) = 0;

    virtual MMResult prepareCapture() = 0;

protected:
    virtual ~MMSnapshotControl(){}

};

#endif  

