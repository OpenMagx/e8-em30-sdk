

// Copyright (c) 31-Jul-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMSNAPSHOTPREVIEWREADYDATA_H 
#define MMSNAPSHOTPREVIEWREADYDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMEventData.h"

class MMSnapshotPreviewReadyData: public MMEventData
{

public:
    MMSnapshotPreviewReadyData(const char* perviewData, int bufferSize, int width, int height, const char* format);

    ~MMSnapshotPreviewReadyData();

    virtual MMEventData * clone();

    char* getPreviewData() const;

    int getBufferSize() const;

    void getSize(int& r_width, int& r_height);

    char* getFormat() const;

protected:

private:
    char* ap_previewData;
    int a_bufferSize;
    int a_width;
    int a_height;
    char* ap_format;
};

#endif  

