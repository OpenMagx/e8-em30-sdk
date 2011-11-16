

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PHONE_SET_MYSIMNUMBERINTERFACE_H
#define PHONE_SET_MYSIMNUMBERINTERFACE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <dlfcn.h>
class PHONE_MySIMNumberInterface
{

public:
	  typedef void(*show_t)();

	  typedef void(*destroy_t)();
    static void showUI()
    {
        void *lib;
        show_t show;
        lib = dlopen("libezxcallsetup.so",RTLD_LAZY);
        if( lib != 0 )
        {
            show = (show_t)dlsym(lib,"PHONE_MySIMNumber_showUI");
            if( show != 0 )
            {
                (*show)();
            }
        }
    }

    static void destroyUI()
    {
        void *lib;
        destroy_t destroy;
        lib = dlopen("libezxcallsetup.so",RTLD_LAZY);
        if( lib != 0 )
        {
            destroy = (destroy_t)dlsym(lib,"PHONE_MySIMNumber_DestroyUI");
            if( destroy != 0 )
            {
                (*destroy)();
            }
        }
    }

};

#endif  

