

// Copyright (c) 30-Oct-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef SYNCF_PM_PROFILEMANAGERINTERFACE_H
#define SYNCF_PM_PROFILEMANAGERINTERFACE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

class SYNCF_PM_ProfileManager_Interface
{
public:
    typedef enum
    {
        RET_SUCCESS =                   0,

        RET_ERROR_CANNOT_GET_FILELOCK = 10,

        RET_ERROR_PROTOCOL_EXIST =      20,
        RET_ERROR_PROTOCOL_NO_EXIST =   21,
        RET_ERROR_PROFILE_EXIST =       22,
        RET_ERROR_PROFILE_NO_EXIST =    23,
        RET_ERROR_INVALID_PARAMETER =   24,
        RET_ERROR_KEY_NO_EXIST =        25,

        RET_ERROR_READ_ENTRY =          30,
        RET_ERROR_WRITE_ENTRY =         31,
        RET_ERROR_REMOVE_ENTRY =        32,

        RET_ERROR_INVALID_ID =          -1,
        RET_ERROR_OTHERS =              50
    }RET_ENUM_T;

    typedef enum
    {
        SYNCTYPE_NONE                   = 0,    
        SYNCTYPE_TWOWAY                 = 1,    
        SYNCTYPE_SLOW                   = 2,    
        SYNCTYPE_ONEWAY_CLIENT          = 3,    
        SYNCTYPE_BACKUP                 = 4,    
        SYNCTYPE_ONEWAY_SERVER          = 5,    
        SYNCTYPE_RESTORE                = 6,    
        SYNCTYPE_SERVER_ALERTED         = 7     
    }SYNCTYPE_ENUM_T;

public:

    static const int AIRSYNC_PROTOCOL_ID=0;

    static const int SYNCML_PROTOCOL_ID=1;

    virtual  ~SYNCF_PM_ProfileManager_Interface ()
    {
    };

    virtual RET_ENUM_T registerProtocol (const char* protocolName, int& protocolId)=0;

    virtual RET_ENUM_T deregisterProtocol (int protocolId)=0;

    virtual RET_ENUM_T getProtocolIdByName (const char* protocolName, int& protocolId) = 0;

    virtual RET_ENUM_T getProtocolNameById (int protocolId, std::string& protocolName) = 0;

    virtual RET_ENUM_T getProfileIdByName (int protocolId, const char* profileName, int& profileId) = 0;

    virtual RET_ENUM_T getProfileNameById (int profileId, std::string& profileName) = 0;

    virtual RET_ENUM_T getAllProtocolIds (std::vector<int>& protocolIds) = 0;

    virtual RET_ENUM_T registerProfile (int protocolId, const char* profileName, int& profileId, bool isVisible = true) = 0;

    virtual RET_ENUM_T deregisterProfile (int profileId) = 0;

    virtual RET_ENUM_T updateProfileName (int profileId, const char* profileName) = 0;

    virtual RET_ENUM_T getAllProfileIds (int protocolId, std::vector<int>& profileIds) = 0;

    virtual RET_ENUM_T associate (int profileId, const char* appId) = 0;

    virtual RET_ENUM_T disassociate (int profileId, const char* appId) = 0;

    virtual RET_ENUM_T disassociateAll (int profileId) = 0;

    virtual RET_ENUM_T isAssociated (const char* appId, bool& isAssociated) = 0;

    virtual RET_ENUM_T getAssociatedAppIds (int profileId, std::vector<std::string>& appIds) = 0;

    virtual RET_ENUM_T getAssociatedProfileIds (const char* appId, std::vector<int>& profileIds, bool visibleOnly = true) = 0;

    virtual RET_ENUM_T getAssociatedprotocolIds (const char* appId, std::vector<int>& protocolIds) = 0;

    virtual RET_ENUM_T getPreloadProfileNames (const char* appId, std::vector<std::string>& profileNames) = 0;

    virtual void deletePreloadProfileName (const std::string& profileName) = 0;


    virtual RET_ENUM_T updateProfileOnChangeStatus (int profileId, bool isNormalOnChange, bool isRoamingOnChange) = 0;

    virtual RET_ENUM_T getOnChangeAppIds (std::vector<std::string>& appIds) = 0;

    virtual RET_ENUM_T getOnChangeProfileIds (std::vector<int>& profileIds) = 0;

    virtual RET_ENUM_T notifyProfileChange () = 0;

};
extern "C" SYNCF_PM_ProfileManager_Interface * SYNCF_getProfileManager();
#endif 
