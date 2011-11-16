

// Copyright (c) 25-May-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef VKM_QUERY_H_
#define VKM_QUERY_H_

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "VKM_Config.h"

class VKM_Query
{
public:
    static VKM_Query* instance();

public:
    int queryVKcode(int mode, int index);

    int queryIndex(int mode, int vkCode);

    int queryNumKeySupported(void);

    list<int> queryMorphModeSupported(void);

protected:

    VKM_Query();
    VKM_Query( const VKM_Query& );
    VKM_Query& operator= ( const VKM_Query& );

 private:

    static VKM_Query* pInstance;

    VKM_Config flex;
};

#endif 

