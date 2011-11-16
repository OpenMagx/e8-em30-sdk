

// Copyright (c) 06-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMPOSITIONCHANGEDDATA_H 
#define MMPOSITIONCHANGEDDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMEventData.h"

class MMPositionChangedData: public MMEventData
{

public:
    MMPositionChangedData(MMTime position, MMTime length);

    ~MMPositionChangedData();

    virtual MMEventData * clone();

    MMTime getPosition() const;

    MMTime getLength() const;

protected:

private:
    MMTime a_position;
    MMTime a_length;
};

#endif  

