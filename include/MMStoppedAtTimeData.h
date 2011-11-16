

// Copyright (c) 21-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMSTOPPEDATTIMEDATA_H 
#define MMSTOPPEDATTIMEDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMEventData.h"

class MMStoppedAtTimeData: public MMEventData
{

public:
    MMStoppedAtTimeData(MMTime mediaTime);

    ~MMStoppedAtTimeData();

    virtual MMEventData * clone();

    MMTime getMediaTime() const;

protected:

private:
    MMTime a_mediaTime;
};

#endif  

