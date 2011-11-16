

// Copyright (c) 24-Aug-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMZOOMCHANGEDDATA_H 
#define MMZOOMCHANGEDDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMEventData.h"

class MMZoomChangedData: public MMEventData
{

public:
    MMZoomChangedData(int currentZoom);

    ~MMZoomChangedData();

    virtual MMEventData * clone();

    int getCurrentZoom() const;

protected:

private:
    int a_currentZoom;

};

#endif  

