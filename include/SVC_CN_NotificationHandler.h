

// Copyright (c) 23-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef SVC_CN_NOTIFICATIONHANDLER_H
#define SVC_CN_NOTIFICATIONHANDLER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <vector>

#include "SVC_CT_ChangeInfo.h"

class SVC_CN_NotificationHandler
{
public:

    virtual ~SVC_CN_NotificationHandler() {};
    virtual int onChange (SVC_CT_ChangeInfo& changeInfo) = 0;

    virtual int onChanges (std::vector<SVC_CT_ChangeInfo>& changeInfos) = 0;

};

#endif 

