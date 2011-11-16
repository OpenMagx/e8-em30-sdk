

// Copyright (c) 20-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMBUFFERINGSTOPPEDDATA_H 
#define MMBUFFERINGSTOPPEDDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMEventData.h"

class MMBufferingStoppedData: public MMEventData
{

public:
    MMBufferingStoppedData(MMTime mediaTime);

    ~MMBufferingStoppedData();

    virtual MMEventData * clone();

    MMTime getMediaTime() const;

protected:

private:
    MMTime a_mediaTime;
};

#endif  

