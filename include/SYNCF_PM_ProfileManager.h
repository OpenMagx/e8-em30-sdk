

// Copyright (c) 23-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef SYNCF_PM_PROFILEMANAGER_H
#define SYNCF_PM_PROFILEMANAGER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <string>
#include <vector>

#include "SYNCF_PM_ProfileManagerInterface.h"

class SYNCF_PM_RecordLocking;
class ConfigManager;

class SYNCF_PM_ProfileManager: public SYNCF_PM_ProfileManager_Interface
{
public:
    SYNCF_PM_ProfileManager ();

    ~SYNCF_PM_ProfileManager ();

    RET_ENUM_T registerProtocol (const char* protocolName, int& protocolId);

    RET_ENUM_T deregisterProtocol (int protocolId);

    RET_ENUM_T getProtocolIdByName (const char* protocolName, int& protocolId);

    RET_ENUM_T getProtocolNameById (int protocolId, std::string& protocolName);

    RET_ENUM_T getAllProtocolIds (std::vector<int>& protocolIds);

    RET_ENUM_T getProfileIdByName (int protocolId, const char* profileName, int& profileId);

    RET_ENUM_T getProfileNameById (int profileId, std::string& profileName);

    RET_ENUM_T getAllProfileIds (int protocolId, std::vector<int>& profileIds);

    RET_ENUM_T registerProfile (int protocolId, const char* profileName, int& profileId, bool isVisible = true);

    RET_ENUM_T deregisterProfile (int profileId);

    RET_ENUM_T updateProfileName (int profileId, const char* profileName);

    RET_ENUM_T associate (int profileId, const char* appId);

    RET_ENUM_T disassociate (int profileId, const char* appId);

    RET_ENUM_T disassociateAll (int profileId);

    RET_ENUM_T isAssociated (const char* appId, bool& isAssociated);

    RET_ENUM_T getAssociatedAppIds (int profileId, std::vector<std::string>& appIds);

    RET_ENUM_T getAssociatedProfileIds (const char* appId, std::vector<int>& profileIds, bool visibleOnly = true);

    RET_ENUM_T getAssociatedprotocolIds (const char* appId, std::vector<int>& protocolIds);

    RET_ENUM_T getPreloadProfileNames (const char* appId, std::vector<std::string>& profileNames);

    void deletePreloadProfileName (const std::string& profileName);


    RET_ENUM_T updateProfileOnChangeStatus (int profileId, bool isNormalOnChange, bool isRoamingOnChange);

    RET_ENUM_T getOnChangeAppIds (std::vector<std::string>& appIds);

    RET_ENUM_T getOnChangeProfileIds (std::vector<int>& profileIds);

    RET_ENUM_T notifyProfileChange ();

private:
    RET_ENUM_T readProfileConfig ();

    RET_ENUM_T getKeyByData(const std::string& group, const std::string& data, std::string& key);

    RET_ENUM_T isKeyInGroup(const char* group, const char* key, bool& isInGroup);

    RET_ENUM_T getIdsInGroup(const char* group, std::vector<int>& Ids);

    void checkConfigFolder();

    int createProfileConfigFile(const char *filePath);

    int generateProtocolId(const char *protocolName);

    int generateProfileId(int protocolId);

    SYNCF_PM_ProfileManager(const SYNCF_PM_ProfileManager &prof);

    const SYNCF_PM_ProfileManager & operator=(const SYNCF_PM_ProfileManager &prof);

private:

    ConfigManager* m_pConfig;

    SYNCF_PM_RecordLocking* m_pRecordLocking;

    std::string m_settingFileDirectory;
};

#endif 
