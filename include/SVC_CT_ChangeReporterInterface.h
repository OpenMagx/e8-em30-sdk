

// Copyright (c) 31-Aug-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef SVC_CT_CHANGEREPORTERINTF_H
#define SVC_CT_CHANGEREPORTERINTF_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "SVC_CT_Defines.h"
#include "SVC_CT_ChangeInfo.h"

class SVC_CT_ChangeReporter_Interface
{
public:
    virtual ~SVC_CT_ChangeReporter_Interface() {}

    virtual SVC_CT_Defines::RET_ENUM_T reportChange (const SVC_CT_ChangeInfo& changeInfo, int profileId) = 0;

    virtual SVC_CT_Defines::RET_ENUM_T reportMultiChanges (const SVC_CT_ChangeInfo* pChangeInfo, int number, int profileId) = 0;

};

typedef SVC_CT_ChangeReporter_Interface * (*SVC_GET_ChangeReporter)();

extern "C" SVC_CT_ChangeReporter_Interface * SVC_getChangeReporter();

#endif 
