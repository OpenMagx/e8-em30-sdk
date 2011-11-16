

// Copyright (c) 29-May-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMBUFFERINGDATA_H 
#define MMBUFFERINGDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMEventData.h"

class MMBufferingData: public MMEventData
{

public:
    MMBufferingData(int bufferingPercent);

    ~MMBufferingData();

    virtual MMEventData * clone();

    int getBufferingPercent() const;

protected:

private:
    int a_percentage;
};

#endif  

