

// Copyright (c) 31-Jul-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMVIEWFINDERFRAMEREADYDATA_H 
#define MMVIEWFINDERFRAMEREADYDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMEventData.h"

class MMViewfinderFrameReadyData: public MMEventData
{

public:
    MMViewfinderFrameReadyData(const char* viewfinderData, int bufferSize);

    ~MMViewfinderFrameReadyData();

    virtual MMEventData * clone();

    char* getViewfinderData() const;

    int getBufferSize() const;

protected:

private:
    char* ap_viewfinderData;
    int a_bufferSize;
};

#endif  

