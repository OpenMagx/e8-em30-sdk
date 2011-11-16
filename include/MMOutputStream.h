

// Copyright (c) 19-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMOUTPUTSTREAM_H 
#define MMOUTPUTSTREAM_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMResult.h"
#include "MMGeneral.h"

class MMOutputStream 
{
public:
    MMOutputStream(){}

    virtual ~MMOutputStream(){}

    virtual MMResult close(void) = 0;

    virtual MMResult flush(void) = 0;

    virtual MMResult write(const char* cp_dataBuf, int length) = 0;

    virtual MMResult write(const char* cp_dataBuf, int offset, int length) = 0;

    virtual MMResult write(char byteToWrite) = 0;
};

#endif  
