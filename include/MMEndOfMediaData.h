

// Copyright (c) 21-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMENDOFMEDIADATA_H 
#define MMENDOFMEDIADATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMEventData.h"

class MMEndOfMediaData: public MMEventData
{

public:
    MMEndOfMediaData(MMTime mediaTime);

    ~MMEndOfMediaData();

    virtual MMEventData * clone();

    MMTime getMediaTime() const;

protected:

private:
    MMTime a_mediaTime;
};

#endif  

