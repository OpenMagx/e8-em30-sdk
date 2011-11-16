

// Copyright (c) 16-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMINPUTSTREAM_H
#define MMINPUTSTREAM_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMResult.h"
#include "MMString.h"

class MMInputStream
{

public:
    MMInputStream(){}

    virtual ~MMInputStream(){}

    virtual MMResult available(int & r_availableSize) = 0;

    virtual MMResult close() = 0;

    virtual MMResult mark(const int c_readLimit) = 0;

    virtual MMResult isMarkSupported(bool & r_supportingStatus) = 0; 

    virtual MMResult read(char* p_result) = 0;

    virtual MMResult read(char* p_buffer, const int c_lenToRead, int* p_actualReadedLen) = 0;

    virtual MMResult reset() = 0;

    virtual MMResult skip(const int c_bytesToSkip, int* p_actualLen) = 0;

    virtual MMResult getContentType(MMString& r_contentType) = 0;
};

#endif
