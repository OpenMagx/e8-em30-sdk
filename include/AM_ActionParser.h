

// Copyright (c) 24-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef UTIL_ACTIONPARSER_H
#define UTIL_ACTIONPARSER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "AM_Global.h"

class AM_ActionData;

class AM_ActionParser
{
public:
    AM_ActionParser();                         
    ~AM_ActionParser();                        

    const AM_ActionData *   action();

private:
    AM_ActionData * pAction;
};

#endif  

