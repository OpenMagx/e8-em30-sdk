

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PHONE_DIALPREFIXINTERFACE_H 
#define PHONE_DIALPREFIXINTERFACE_H 

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "qstring.h"

class PHONE_DialPrefixInterface
{

private:
    PHONE_DialPrefixInterface();
    ~PHONE_DialPrefixInterface();

public:

    enum AutoChangeType 
    {
        OFF = 0,
        ADD,    
        REPLACE_OR_ADD 
    };

     static int  getAutoChangeType();

     static QString getAutoChangeTypeString();

     static QString getSelectedOperatorName();

     static QString getSelectedOperatorPrefix();

    static void showUI();
};

#endif 

