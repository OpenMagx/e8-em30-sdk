

// Copyright (c) 20-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMDISPLAYCONTROL_H 
#define MMDISPLAYCONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMResult.h"
#include "MMGeneral.h"

enum MMDisplayDevices
{
    MMDISPLAY_DEVICE_MAIN_DISPLAY = 0,     
    MMDISPLAY_DEVICE_SECOND_DISPLAY = 1,   
    MMNUM_OF_DISPLAY_DEVICES               
};
typedef int MMDisplayDeviceType;

enum MMRotationModes
{
    MMDISPLAY_ROTATION_0 = 0, 
    MMDISPLAY_ROTATION_90,    
    MMDISPLAY_ROTATION_180,   
    MMDISPLAY_ROTATION_270    
};
typedef int MMRotationModeType;

enum MMDisplayModes
{
    MM_VID_SCALING_MODE_NONE = 0, 
    MM_VID_SCALING_MODE_FIT_TO_WINDOW, 
    MM_VID_SCALING_MODE_SHRINK_TO_WINDOW, 
    MM_VID_SCALING_MODE_STRETCH_TO_WINDOW, 
};
typedef int MMDisplayModeType;

class MMDisplayControl
{
public:
    virtual MMResult getDisplayHeight(int& r_height) = 0;

    virtual MMResult getDisplayWidth(int& r_width) = 0;

    virtual MMResult getDisplayX(int& r_pointX) = 0;

    virtual MMResult getDisplayY(int& r_pointY) = 0;

    virtual MMResult getSnapshot(char* p_imageType, char*& pr_buffer, int& r_size) = 0;

    virtual MMResult getSourceHeight(int& r_sourceHeight) = 0;

    virtual MMResult getSourceWidth(int& r_sourceWidth) = 0;

    virtual MMResult setDisplayLocation(int x, int y) = 0;

    virtual MMResult setDisplaySize(int width, int height) = 0;

    virtual MMResult setVisible(bool visible) = 0;

    virtual MMResult setDisplayArea(int x, int y, int width, int height,
                                    MMDisplayDeviceType device,
                                    MMDisplayModeType mode,
                                    MMRotationModeType rotation
                                    ) = 0;

    virtual MMResult getVirtualColorKey(int& r_virtualColorKey) = 0;

    virtual MMResult setDisplayDevice(const MMDisplayDeviceType c_deviceType) = 0;

    virtual MMResult getDisplayDevice(MMDisplayDeviceType& r_deviceType) = 0;

    virtual MMResult setDisplayMode(MMDisplayModeType mode) = 0;

    virtual MMResult getDisplayMode(MMDisplayModeType& r_mode) = 0;

    virtual MMResult setRotationMode(MMRotationModeType mode) = 0;

    virtual MMResult getRotationMode(MMRotationModeType& r_mode) = 0;

    virtual MMResult setLockAspectRatio(bool lock) = 0;

    virtual MMResult isAspectRatioLocked(bool& r_lockStatus) = 0;

protected:
    virtual ~MMDisplayControl(){}

};

#endif 
