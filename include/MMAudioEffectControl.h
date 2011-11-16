

// Copyright (c) 11-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMAUDIOEFFECTCONTROL_H 
#define MMAUDIOEFFECTCONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMResult.h"
#include "MMGeneral.h"

enum MMGEQProfiles
{
    MM_GEQ_PROFILE_MIN = 1, 
    MM_GEQ_PROFILE_2,       
    MM_GEQ_PROFILE_3,       
    MM_GEQ_PROFILE_4,       
    MM_GEQ_PROFILE_5,       
    MM_GEQ_PROFILE_6,       
    MM_GEQ_PROFILE_7,       
    MM_GEQ_PROFILE_8,       
    MM_GEQ_PROFILE_9,       
    MM_GEQSV_LEVEL_MAX      
};
typedef int MMGEQProfileType;

enum MMAIELevels
{
    MM_AIE_LEVEL_MIN  = 1,  
    MM_AIE_LEVEL_2,         
    MM_AIE_LEVEL_3,         
    MM_AIE_LEVEL_4,         
    MM_AIE_LEVEL_5,         
    MM_AIE_LEVEL_6,         
    MM_AIE_LEVEL_MAX        
};
typedef int MMAIELevelType;

enum MMBELevels
{
    MM_BE_LEVEL_MIN = 1,   
    MM_BE_LEVEL_2,         
    MM_BE_LEVEL_3,         
    MM_BE_LEVEL_4,         
    MM_BE_LEVEL_5,         
    MM_BE_LEVEL_6,         
    MM_BE_LEVEL_MAX        
};
typedef int MMBELevelType;

enum MMSurroundEffect
{
    MM_SURROUND_EFFECT_MIN = 0,
    MM_SURROUND_EFFECT_3D_STEREO,
    MM_SURROUND_EFFECT_VIRTUAL_STUDIO,
    MM_SURROUND_EFFECT_AUDITION_ROOM,
    MM_SURROUND_EFFECT_VIRTUAL_HOME_THEATER,
    MM_SURROUND_EFFECT_VIRTUAL_CONCERT
};
typedef int MMSurroundEffectType;

class MMAudioEffectControl 
{
public:
    virtual MMResult enableGEQ(bool enableOrNot) = 0;

    virtual MMResult isGEQEnabled(bool& r_enableStatus) = 0;

    virtual MMResult setGEQProfile(MMGEQProfileType profileId) = 0;

    virtual MMResult getGEQProfile(MMGEQProfileType& r_profileId) = 0;

    virtual MMResult enableAIE(bool enableOrNot) = 0;

    virtual MMResult isAIEEnabled(bool& r_enableStatus) = 0;

    virtual MMResult setAIELevel(MMAIELevelType level) = 0;

    virtual MMResult getAIELevel(MMAIELevelType& r_level) = 0;

    virtual MMResult enableBE(bool enableOrNot) = 0;

    virtual MMResult isBEEnabled(bool& r_enableStatus) = 0;

    virtual MMResult setBELevel(MMBELevelType level) = 0;

    virtual MMResult getBELevel(MMBELevelType& r_level) = 0;

    virtual MMResult setSurroundEffect(MMSurroundEffectType effect) = 0;

    virtual MMResult getSurroundEffect(MMSurroundEffectType& r_effect) = 0;

    virtual MMResult setSVStatus(bool enableOrNot) = 0;

    virtual MMResult isSVEnabled(bool& r_enableStatus) = 0;

    virtual MMResult getSVData(short *& pSVData, int& GEQBandNum) = 0;

protected:
    virtual ~MMAudioEffectControl(){}

};

#endif  
