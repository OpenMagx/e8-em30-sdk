

// Copyright (c) 20-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMBUFFERINGSTARTEDDATA_H 
#define MMBUFFERINGSTARTEDDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMEventData.h"

class MMBufferingStartedData: public MMEventData
{

public:
    MMBufferingStartedData(MMTime mediaTime);

    ~MMBufferingStartedData();

    virtual MMEventData * clone();

    MMTime getMediaTime() const;

protected:

private:
    MMTime a_mediaTime;
};

#endif  

