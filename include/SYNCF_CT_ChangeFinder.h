

// Copyright (c) 23-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef SYNCF_CT_CHANGEFINDER_H
#define SYNCF_CT_CHANGEFINDER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <vector>
#include <string>
#include <map>

#include "SVC_CT_ChangeInfo.h"
#include "SVC_CT_Defines.h"
#include "SYNCF_PM_ProfileManager.h"

class SYNCF_CT_ChangeLog_ChangeInfo;

class SYNCF_CT_ChangeFinder
{
public:

    SYNCF_CT_ChangeFinder();

    ~SYNCF_CT_ChangeFinder();

    SVC_CT_Defines::RET_ENUM_T begin (const char * appId, int profileId, int lastChangeId);

    SVC_CT_Defines::RET_ENUM_T end (int& lastChangeId);

    SVC_CT_Defines::RET_ENUM_T isAppDataStoreChanged (bool& changed,
                                                      SVC_CT_Defines::CHANGETYPE_ENUM_T changeType = SVC_CT_Defines::TYPE_ALL);

    SVC_CT_Defines::RET_ENUM_T getChangeCount (int& count,
                                               SVC_CT_Defines::CHANGETYPE_ENUM_T changeType = SVC_CT_Defines::TYPE_ALL);

    SVC_CT_Defines::RET_ENUM_T getNextChange (SVC_CT_ChangeInfo& changeInfo);

    SVC_CT_Defines::RET_ENUM_T getNextChanges (int number, std::vector<SVC_CT_ChangeInfo>& changeInfos);

    SVC_CT_Defines::RET_ENUM_T reportStatus (int recId);

    SVC_CT_Defines::RET_ENUM_T reportStatus ();

    SVC_CT_Defines::RET_ENUM_T getMaxChangeId (int& maxChangeId);

private:

    SVC_CT_Defines::RET_ENUM_T clearRecordsByProfileIds (const char* appId);

    bool isSlowSyncNeeded (const char* appId, int lastChangeId);

    bool needThisChange(int recId);

private:
    SYNCF_CT_ChangeFinder(const SYNCF_CT_ChangeFinder& changefinder);

    const SYNCF_CT_ChangeFinder& operator=(const SYNCF_CT_ChangeFinder& changefinder);
private:

    std::string mAppId;

    int mProfileId;

    bool mReportSuccess;

    int mLastSentChangeId;

    int mLastConfirmedChangeId;

    std::map<int,int> mMapRecId2ChangeId;

    std::vector<int> mRecordIdVector;

    SYNCF_PM_ProfileManager i_profileManager;

    SYNCF_CT_ChangeLog_ChangeInfo* m_pChangeLog_ChangeInfo;
};

#endif 
