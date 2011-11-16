

// Copyright (c) 31-Jul-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMSNAPSHOTSHOOTSTOPPEDDATA_H 
#define MMSNAPSHOTSHOOTSTOPPEDDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMEventData.h"

class MMSnapshotShootStoppedData: public MMEventData
{

public:
    MMSnapshotShootStoppedData(const char* lastFileName, int nameLength);

    ~MMSnapshotShootStoppedData();

    virtual MMEventData * clone();

    char* getFileName() const;

    int getFileNameLength() const;

protected:

private:
    char* ap_lastFileName;
    int a_nameLength;
};

#endif  

