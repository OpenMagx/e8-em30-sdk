

// Copyright (c) 15-Jun-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMEFFECTCONTROL_H
#define MMEFFECTCONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMResult.h"

enum MMEffectControlScopes
{    
    MMEFFECT_SCOPE_LIVE_AND_RECORD = 0,

    MMEFFECT_SCOPE_LIVE_ONLY,

    MMEFFECT_SCOPE_RECORD_ONLY,

    MMNUM_OF_SCOPE

};
typedef int MMEffectControlScopeType;

enum MMEffectControlPresets
{
    MMEFFECT_CONTROL_IMAGE_EFFECT_MONO = 0,  
    MMEFFECT_CONTROL_IMAGE_EFFECT_NEGATIVE,  
    MMEFFECT_CONTROL_IMAGE_EFFECT_SEPIA,     
    MMEFFECT_CONTROL_IMAGE_EFFECT_REDDISH,   
    MMEFFECT_CONTROL_IMAGE_EFFECT_GREENISH,  
    MMEFFECT_CONTROL_IMAGE_EFFECT_BLUISH,    
    MMEFFECT_CONTROL_IMAGE_EFFECT_OVERLAY,   
    MMEFFECT_CONTROL_IMAGE_EFFECT_TRANSFORM, 
    MMEFFECT_CONTROL_IMAGE_EFFECT_COLOR,     
    MMEFFECT_CONTROL_IMAGE_EFFECT_ANTIQUE,   
    MMEFFECT_CONTROL_IMAGE_EFFECT_SOLARIZED, 
    MMEFFECT_CONTROL_IMAGE_EFFECT_EMBOSSED,  
    MMEFFECT_CONTROL_IMAGE_EFFECT_BLACK_WHITE,   

    MMEFFECT_CONTROL_PRESET_NULL=0x80000000,
    MMNUM_OF_EFFECT_PRESET = MMEFFECT_CONTROL_IMAGE_EFFECT_BLACK_WHITE +2,
};
typedef int MMEffectControlPresetType;

class MMEffectControl
{
public:
    virtual MMResult getPreset(MMEffectControlPresetType& r_preset) = 0;

    virtual MMResult getPresets(MMEffectControlPresetType*& pr_presetList, int& r_numOfPreset) = 0;

    virtual MMResult  getScope(MMEffectControlScopeType& r_scope) = 0;

    virtual MMResult isEnabled(bool &r_enabled) = 0;

    virtual MMResult isEnforced(bool &r_enforce) = 0;

    virtual MMResult setEnabled(const bool enable) = 0;

    virtual MMResult setEnforced(const bool c_enforced) = 0;

    virtual MMResult setPreset(const MMEffectControlPresetType c_preset) = 0;

    virtual MMResult setScope(const MMEffectControlScopeType c_scope) = 0;

protected:
    virtual ~MMEffectControl(){}
};

#endif
