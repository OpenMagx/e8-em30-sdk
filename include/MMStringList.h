

// Copyright (c) 19-Jul-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMSTRINGLIST_H 
#define MMSTRINGLIST_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"

class MMStringList 
{
public:
    MMStringList();

    MMStringList(const MMStringList& cr_other);

    ~MMStringList();

    MMStringList& operator=(const MMStringList& cr_other);

    const char * operator[](int index) const;

    bool insert(const char * cp_buf);

    void clear();

    int  count() const;

MM_PRIVATE:
    int a_numOfBufs;
    int a_storage;
    char ** ap_bufs;
};        

#endif 

