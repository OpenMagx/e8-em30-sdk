

// Copyright (c) 11-Oct-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef IMPSOBJECT_H_
#define IMPSOBJECT_H_

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <memory.h>
#include "EZX_TypeDefs.h"

class ImpsObject
{

public:

    void *
    operator new(size_t size);

    void *
    operator new[](size_t size);

    void 
    operator delete(void *pPointer);

    void 
    operator delete[](void *pPointer);

    virtual 
    ~ImpsObject();

    virtual BOOL 
    equals(const ImpsObject *pObject) const;

    virtual void 
    print() const;

};

#endif 
