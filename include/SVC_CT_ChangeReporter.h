

// Copyright (c) 23-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef SVC_CT_CHANGEREPORTER_H
#define SVC_CT_CHANGEREPORTER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "SVC_CT_ChangeReporterInterface.h"
#include "SVC_CT_ChangeInfo.h"
#include "SVC_CT_Defines.h"
#include "SYNCF_PM_ProfileManager.h"

class SYNCF_CT_ChangeLog_ChangeInfo;

class SVC_CT_ChangeReporter: public SVC_CT_ChangeReporter_Interface
{
public:
    SVC_CT_ChangeReporter();

    ~SVC_CT_ChangeReporter();

    SVC_CT_Defines::RET_ENUM_T reportChange (const SVC_CT_ChangeInfo& changeInfo, int profileId = -1);

    SVC_CT_Defines::RET_ENUM_T reportMultiChanges (const SVC_CT_ChangeInfo* pChangeInfo, int number, int profileId = -1);

private:

    bool isAppChangeNeeded(const char* appId, int profileId);

private:
    SVC_CT_ChangeReporter(const SVC_CT_ChangeReporter &cr);

    const SVC_CT_ChangeReporter & operator=(const SVC_CT_ChangeReporter &cr);

private:

    SYNCF_PM_ProfileManager i_profileManager;

    SYNCF_CT_ChangeLog_ChangeInfo* m_pChangeLog_ChangeInfo;

};

#endif 

