

// Copyright (c) 12-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMAUDIOCONTROL_H 
#define MMAUDIOCONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMResult.h"
#include "MMGeneral.h"

enum MMAudioPaths
{
    MMAUDIO_PATH_INVALID                     = 0,  
    MMAUDIO_PATH_SPEAKERPHONE                = 1,  
    MMAUDIO_PATH_HANDSET                     = 2,  
    MMAUDIO_PATH_MONO_HEADSET                = 3,  
    MMAUDIO_PATH_STEREO_HEADSET              = 4,  
    MMAUDIO_PATH_BT_MONO_HEADSET             = 5,  
    MMAUDIO_PATH_BT_STEREO_HEADSET           = 6,  
    MMAUDIO_PATH_BT_CARKIT                   = 7,  
    MMAUDIO_PATH_EMU_MONO_HEADSET            = 8,  
    MMAUDIO_PATH_EMU_STEREO_HEADSET          = 9,  
    MMAUDIO_PATH_EMU_CARKIT                  = 10, 
    MMAUDIO_PATH_MID_CHARGR_SIHF             = 11, 
    MMAUDIO_PATH_FAST_CHARGR_SIHF            = 12, 

    MMAUDIO_PATH_BT_MONO_LOUDSPEAKER         = 13, 
    MMAUDIO_PATH_BT_STEREO_LOUDSPEAKER       = 14, 
    MMAUDIO_PATH_EMU_MONO_LOUDSPEAKER        = 15, 
    MMAUDIO_PATH_EMU_STEREO_LOUDSPEAKER      = 16, 
    MMAUDIO_PATH_HEADSET_MONO_LOUDSPEAKER    = 17, 
    MMAUDIO_PATH_HEADSET_STEREO_LOUDSPEAKER  = 18, 

    MMAUDIO_PATH_TTY                         = 19, 
    MMAUDIO_PATH_MICROPHONE                  = 20, 
    MMAUDIO_PATH_NONE                        = 21, 
    MMNUM_OF_AUDIO_PATHS                           
};
typedef int MMAudioPathType;

enum MMAudioAccyType
{
    MMAUDIO_ACCY_TYPE_INVALID               = 0,    
    MMAUDIO_ACCY_TYPE_SPEAKERPHONE          = 1,    
    MMAUDIO_ACCY_TYPE_HANDSET               = 2,    
    MMAUDIO_ACCY_TYPE_MONO_HEADSET          = 4,    
    MMAUDIO_ACCY_TYPE_STEREO_HEADSET        = 8,    
    MMAUDIO_ACCY_TYPE_BT_MONO_HEADSET       = 16,   
    MMAUDIO_ACCY_TYPE_BT_STEREO_HEADSET     = 32,   
    MMAUDIO_ACCY_TYPE_BT_CARKIT             = 64,   
    MMAUDIO_ACCY_TYPE_EMU_MONO_HEADSET      = 128,  
    MMAUDIO_ACCY_TYPE_EMU_STEREO_HEADSET    = 256,  
    MMAUDIO_ACCY_TYPE_EMU_CARKIT            = 512,  
    MMAUDIO_ACCY_TYPE_MID_CHRGR_SIHF        = 1024, 
    MMAUDIO_ACCY_TYPE_FAST_CHRGR_SIHF       = 2048, 
    MMAUDIO_ACCY_TYPE_TTY                   = 4096  
};

typedef struct MMAudioPathRule
{
    MMAudioPathType enabled_paths[MMNUM_OF_AUDIO_PATHS];

    int num_of_enabled_paths;

    MMAudioPathType disabled_paths[MMNUM_OF_AUDIO_PATHS];

    int num_of_disabled_paths;
};

class MMAudioControl 
{
public:
    virtual MMResult enableAudioStream(bool enableOrNot) = 0;

    virtual MMResult isAudioStreamEnabled(bool& r_enableStatus) = 0;

    virtual MMResult setAudioPaths(const MMAudioPathRule& cr_pathRule) = 0;

    virtual MMResult getAudioPaths(MMAudioPathRule& r_pathRule) = 0;

    virtual MMResult getAvailableAudioPaths(MMAudioPathType *& pr_availablePaths, int & r_numOfAvailablePaths) = 0;

    virtual MMResult getActiveAudioPath(MMAudioPathType & r_activePath) = 0;

    virtual MMResult notifyActivePortChange(void *cb_function_in, void *stopSem, void *cb_arg_in) = 0;

protected:
    virtual ~MMAudioControl(){}

};

#endif  
