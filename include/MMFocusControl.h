

// Copyright (c) 20-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMFOCUSCONTROL_H 
#define MMFOCUSCONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMResult.h"

#define MMFOCUS_MAX_VALUE    0

#define MMFOCUS_UNKNOWN      -1

enum MMAutoFocus
{
    MMAUTOFOCUS_AUTO = -1001,

    MMAUTOFOCUS_AUTO_LOCK = -1002,

    MMAUTOFOCUS_CONTINUE_AUTO = -1003,

    MMAUTOFOCUS_CONTINUE_AUTO_LOCK = -1004,

    MMNUM_OF_AUTOFOCUS_MODE = 4
};
typedef int MMAutoFocusType;

class MMFocusControl
{
public:
    virtual MMResult getFocus(int& r_focus) = 0;

    virtual MMResult getFocusSteps(int& r_steps) = 0;

    virtual MMResult getMacro(bool& r_macro) = 0;

    virtual MMResult getMinFocus(int& r_focus) = 0;

    virtual MMResult getSupportedAutoFocusModes(MMAutoFocusType *& pr_autoFocusList,
                                                int & r_numofMode) = 0;

    virtual MMResult isMacroSupported(bool& r_supported) = 0;

    virtual MMResult isManualFocusSupported(bool& r_supported) = 0;

    virtual MMResult setFocus(const int c_distance) = 0;

    virtual MMResult setMacro(const bool c_enable) = 0;

protected:
    virtual ~MMFocusControl(){}

};

#endif  
