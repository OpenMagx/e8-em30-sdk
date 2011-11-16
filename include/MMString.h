

// Copyright (c) 19-Jul-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMSTRING_H 
#define MMSTRING_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"

class MMString 
{
public:
    MMString();

    MMString(const char * cp_buf);

    MMString(const MMString& cr_other);

    ~MMString();

    MMString& operator=(const MMString& cr_other);

    MMString& operator=(const char* cp_other);

    bool operator==(const MMString& cr_other) const;

    bool operator==(const char* cp_buf) const;

    bool operator!=(const MMString& cr_other) const;

    char operator[](int index) const;

    MMString& operator+(const char* cp_other);

    MMString& operator+=(const char* cp_other);

    MMString& operator+(const MMString& cr_other);

    MMString& operator+=(const MMString& cr_other);

    MMString& toLowerCase();

    MMString& toUpperCase();

    unsigned int length() const;

    bool isNull() const;

    bool isEmpty() const;

    operator const char*() const;

MM_PRIVATE:
    char * ap_buf;
};        

#endif 

