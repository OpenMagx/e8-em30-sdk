

// Copyright (c) 20-Jun-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMSEEKINGDONEDATA_H 
#define MMSEEKINGDONEDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMEventData.h"

class MMSeekingDoneData: public MMEventData
{

public:
    MMSeekingDoneData(MMTime mediaTime);

    ~MMSeekingDoneData();

    virtual MMEventData * clone();

    MMTime getMediaTime() const;

protected:

private:
    MMTime a_mediaTime;
};

#endif  

