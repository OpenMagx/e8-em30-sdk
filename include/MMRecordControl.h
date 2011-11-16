

// Copyright (c) 19-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMRECORDCONTROL_H 
#define MMRECORDCONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMResult.h"
#include "MMGeneral.h"
#include "MMString.h"

#define MMRECORD_CONTROL_LIMIT_RESET (0)

class MMOutputStream;

class MMRecordControl 
{
public:
    virtual MMResult commit(void) = 0;

    virtual MMResult getContentType(MMString& r_contentType) const = 0;

    virtual MMResult reset(void) = 0;

    virtual MMResult setRecordLocation(const MMString & cr_locator) = 0;

    virtual MMResult setRecordSizeLimit(unsigned int size) = 0;

    virtual MMResult setRecordTimeLimit(unsigned int seconds) = 0;

    virtual MMResult setRecordStream(MMOutputStream* p_stream) = 0;

    virtual MMResult startRecord(void) = 0;

    virtual MMResult stopRecord(void) = 0;

    virtual MMResult enableSendPreviewData(bool b_enable) = 0;

protected:
    virtual ~MMRecordControl(){}

};

#endif  
