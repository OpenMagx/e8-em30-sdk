

// Copyright (c) 06-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMDOWNLOADPROGRESSDDATA_H 
#define MMDOWNLOADPROGRESSDDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMEventData.h"

class MMDownloadProgressData: public MMEventData
{

public:
    MMDownloadProgressData(MMTime duration, int size);

    ~MMDownloadProgressData();

    virtual MMEventData * clone();

    MMTime getDuration() const;

    int getSize() const;

protected:

private:
    MMTime a_duration;

    int a_size;
};

#endif  

