

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PHONE_SPEED_DIAL_INTERFACE_H 
#define PHONE_SPEED_DIAL_INTERFACE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstringlist.h> 
#include <dlfcn.h>
class PHONE_SpeedDialInterface
{
public:
	typedef void(*show_t)();
    static void showUI()
    {
        void *lib;
        show_t show;
        lib = dlopen("libezxcallsetup.so",RTLD_LAZY);
        if( lib != 0 )
        {
            show = (show_t)dlsym(lib,"PHONE_SpeedDial_showUI");
            if( show != 0 )
            {
                (*show)();
            }
        }
    }

};

#endif

