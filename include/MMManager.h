

// Copyright (c) 12-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMMANAGER_H 
#define MMMANAGER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMResult.h"
#include "MMGeneral.h"
#include "MMString.h"
#include "MMStringList.h"

class MMPlayer;
class MMInputStream;

#define PLAYER_LIB_RINGTONE  "libmmapi_ringtone.so.1"
#define PLAYER_LIB_HELIX     "libmmapi_helix.so.1"
#define PLAYER_LIB_GSTREAM   "libmmapi_gstreamer.so.1"
#define PLAYER_LIB_VOICENOTE "libmmapi_voicenote.so.1"
#define PLAYER_LIB_CAMERA    "libmmapi_camera.so.1"
#define PLAYER_LIB_MIDI      "libmmapi_midi.so.1"
#define PLAYER_LIB_DVBH      "libmmapi_dvbh.so.1"
#define PLAYER_LIB_DUMMY     "libmmapi_dummy.so.1"

#define PROTOCOL_MAX_LEN      7
#define MIDI_SUFFIX_LEN       4

#define LIVE_DEVICE_NUM       4

#define MM_CONTENTTYPE_NUM    13

#define MM_MAX_PLAYER_OBJS    200

enum
{
    MM_PROTOCOL_FILE = 0,
    MM_PROTOCOL_HTTP,
    MM_PROTOCOL_RTSP,
    MM_PROTOCOL_DEVICE,
    MM_PROTOCOL_TONE,
    MM_PROTOCOL_DVBH,
    MM_PROTOCOL_CAPTURE,
    MM_PROTOCOL_DUMMY,
    MM_PROTOCOL_NUM
};

enum
{
    MM_TYPE_AMR = 0,
    MM_TYPE_MP3,
    MM_TYPE_WAV,
    MM_TYPE_RM,
    MM_TYPE_3GP,
    MM_TYPE_MIDI,
    MM_TYPE_WMA,
    MM_TYPE_AAC,
    MM_TYPE_NUM
};

enum
{
    MM_PLAYER_RINGTONEPLAYER = 0,
    MM_PLAYER_HELIXPLAYER,
    MM_PLAYER_GSTREAMERPLAYER,
    MM_PLAYER_VOICENOTEPLAYER,
    MM_PLAYER_CAMERAPLAYER,
    MM_PLAYER_MIDIPLAYER,
    MM_PLAYER_DVBHPLAYER,
    MM_PLAYER_DUMMYPLAYER,
    MM_PLAYER_NUM
};

enum MMAudioDevices
{
    MMAUDIODEVICE_TYPE_NORMAL = 0, 
    MMAUDIODEVICE_TYPE_SYSTEM      
};

typedef int MMAudioPathType;

typedef int MMAudioDeviceType;

enum MMNormalDevicePriorities
{
    MMAUDIO_NORMALDEV_MICINPUT = 0,  
    MMAUDIO_NORMALDEV_PHONEINPUT,    
    MMAUDIO_NORMALDEV_MICINOUT,      
    MMAUDIO_NORMALDEV_NORMALOUT3,    
    MMAUDIO_NORMALDEV_NORMALOUT2,    
    MMAUDIO_NORMALDEV_NORMALOUT1,    
    MMAUDIO_NORMALDEV_NORMALOUT0,    
    MMAUDIO_NORMALDEV_FLASH,         
    MMAUDIO_NORMALDEV_NORMALTOUCHES, 
    MMAUDIO_NORMALDEV_JAVA_MIXDEV    
};

typedef int MMNormalAudioPriorityType;

enum MMSystemDevicePriorities
{
    MMAUDIO_SYSTEMDEV_PHONE= 0,     
    MMAUDIO_SYSTEMDEV_ALERT,        
    MMAUDIO_SYSTEMDEV_LEVEL3,       
    MMAUDIO_SYSTEMDEV_LEVEL2,       
    MMAUDIO_SYSTEMDEV_LEVEL1,       
    MMAUDIO_SYSTEMDEV_LEVEL0,       
    MMAUDIO_SYSTEMDEV_NORMAL        
};

typedef int MMSystemAudioPriorityType;

#define MMDEFAULT_AUDIO_ATTRIBUTES (MMAUDIODEVICE_TYPE_NORMAL << 16 | MMAUDIO_NORMALDEV_NORMALOUT2)

class MMManager
{
public:

    virtual ~MMManager();

    static MMResult createInstance(MMManager *& pr_inst);

    static MMResult releaseInstance(MMManager *& pr_inst);

    static MMResult getActiveAudioPath(MMAudioPathType &r_activePath);

    MMResult createPlayer(MMInputStream& r_source, MMPlayer*& pr_player, 
                          int featureHandle = MMDEFAULT_AUDIO_ATTRIBUTES);

    MMResult createPlayer(const MMString& cr_locator, MMPlayer*& pr_player, 
                          int featureHandle = MMDEFAULT_AUDIO_ATTRIBUTES);

    static MMResult getSupportedContentTypes(const MMString& cr_protocol, MMStringList& r_contentTypeList);

    static MMResult getSupportedProtocols(const MMString& cr_contentType, MMStringList& r_protocolList);

    MMResult releasePlayer(MMPlayer*& pr_player);

protected:

private:
    MMManager();

    void getTypeId(const MMString& cr_locator);

    void getLiveDeviceId(const MMString& cr_locator);

    void getPlayerId();

    MMResult executeCreatePlayer(MMPlayer*& pr_player,const MMString& cr_locator,MMInputStream* p_sourceStream,int featureHandle);

    MMResult openPlayerLib(MMPlayer*& pr_player,const MMString& cr_locator, MMInputStream* p_sourceStream, int featureHandle);

    void addRef();

    void release();

private:
    struct MMPlayerInfo
    {
        int id;
        MMPlayer * p_inst;
        bool released;
    };

    static MMManager * ap_instance;

    static const char* a_protocols[MM_PROTOCOL_NUM];

    static const char* a_liveDeviceNames[LIVE_DEVICE_NUM];

    static const char* a_libNames[MM_PLAYER_NUM];

    static const char* a_apiNames[MM_PLAYER_NUM];

    MMPlayerInfo a_playerInfo[MM_MAX_PLAYER_OBJS];

    void * a_libHandles[MM_PLAYER_NUM];

    int a_numOfPlayerInst;

    int a_protocolId;

    int a_typeId;

    int a_liveDeviceId;

    int a_playerId;

    int a_refCount;

    pthread_mutex_t a_actionMutex;
};

#endif  
