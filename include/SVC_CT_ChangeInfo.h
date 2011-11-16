

// Copyright (c) 23-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef SVC_CT_CHANGEINFO_H
#define SVC_CT_CHANGEINFO_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <string>

#include "SVC_CT_Defines.h"

class SVC_CT_ChangeInfo
{
public:
    SVC_CT_ChangeInfo():
        changeId   (0),
        appId      (""),
        recId      (0),
        changeType (SVC_CT_Defines::TYPE_ALL),
        profileIds (0)
    {
    }

    ~SVC_CT_ChangeInfo()
    {
    }

public:
    int changeId;

    std::string appId;

    int recId;

    SVC_CT_Defines::CHANGETYPE_ENUM_T changeType;

    int profileIds;
};

#endif 

