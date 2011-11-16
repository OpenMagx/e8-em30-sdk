

// Copyright (c) 25-Jun-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMRECORDEDTOTALLENGTHDATA_H 
#define MMRECORDEDTOTALLENGTHDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMEventData.h"

class MMRecordedTotalLengthData: public MMEventData
{

public:
    MMRecordedTotalLengthData(unsigned long lengthInByte);

    ~MMRecordedTotalLengthData();

    virtual MMEventData * clone();

    unsigned long getLength() const;

protected:

private:
    unsigned long a_lengthInByte;
};

#endif  

