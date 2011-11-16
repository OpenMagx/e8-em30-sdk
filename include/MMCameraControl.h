

// Copyright (c) 20-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMCAMERACNTROL_H 
#define MMCAMERACNTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMResult.h"
#include "MMString.h"

enum MMCameraExposureModes
{
	 MMCAMERA_EXPOSURE_AUTO = 0, 

	 MMCAMERA_EXPOSURE_MANUAL,

	 MMCAMERA_EXPOSURE_AUTO_BRACKET,  

	 MMCAMERA_EXPOSURE_LANDSC, 

	 MMCAMERA_EXPOSURE_SNOW,

	 MMCAMERA_EXPOSURE_BEACH,  

	 MMCAMERA_EXPOSURE_SUNSET, 

	 MMCAMERA_EXPOSURE_NIGHT, 

	 MMCAMERA_EXPOSURE_FIREWORKS, 

	 MMCAMERA_EXPOSURE_PORTRAIT, 

	 MMCAMERA_EXPOSURE_BACKLIGHT, 

	 MMCAMERA_EXPOSURE_SPOTLIGHT, 

	 MMCAMERA_EXPOSURE_SPORTS, 

	 MMCAMERA_EXPOSURE_TEXT, 

	 MMCAMERA_EXPOSURE_UNKNOWN,

         MMNUM_OF_EXPOSURE_MODE
};
typedef int MMCameraExposureModeType;

enum MMCameraRotations
{
	 MMCAMERA_ROTATION_NONE = 1,

	 MMCAMERA_ROTATION_LEFT  = 2,

	 MMCAMERA_ROTATION_RIGHT = 3,

	 MMCAMERA_ROTATION_UNKNOWN = -1004
};
typedef int MMCameraRotationType;

typedef int* MMCameraResolutionType;

enum MMCameraDevices
{
	MM_CAMERA_DEVICE_EXTERNAL = 0,

	MM_CAMERA_DEVICE_INTERNAL = 1,

        MMNUM_OF_CAMERA_DEVICE
};
typedef int MMCameraDeviceType;

enum MMCameraFlips
{
	MM_CAMERA_FLIP_NONE = 0,

	MM_CAMERA_FLIP_HORIZONTAL = 1,

	MM_CAMERA_FLIP_VERTICAL = 2,

	MM_CAMERA_FLIP_BOTH = 3,

        MMNUM_OF_FLIP_TYPE
};
typedef int MMCameraFlipType;

enum MMCameraModes
{
        MMCAMERA_PHOTO_MODE = 0, 
        MMCAMERA_VIDEO_MODE = 1, 
        MMCAMERA_COMPATIBLE_MODE = 2, 
        MMNUM_OF_CAMERA_MODE
};
typedef int MMCameraModeType;

enum MMUIModes
{
    MMCAMERA_PORTRAIT =0, 
    MMCAMERA_LANDSCAPE =1, 
    MMNUM_OF_UI_MODE
};
typedef int MMUIModeType;

class MMCameraControl
{
public:
    virtual MMResult getCameraRotation(MMCameraRotationType& r_rotation) = 0;

    virtual MMResult getExposureMode(MMCameraExposureModeType& r_mode) = 0;

    virtual MMResult getSupportedExposureModes(MMCameraExposureModeType *& pr_list, 
                                               int& r_numOfMode) = 0;

    virtual MMResult setExposureMode(const MMCameraExposureModeType c_mode) = 0;

    virtual MMResult getStillResolution(int& r_resIndex) = 0;

    virtual MMResult getSupportedStillResolutions(MMCameraResolutionType& r_resolution, 
                                                int& r_size
                                              ) = 0;

    virtual MMResult setStillResolution(const int c_resIndex) = 0;

    virtual MMResult getSupportedVideoResolutions(MMCameraResolutionType& r_resolution, 
                                               int& r_size) = 0;

    virtual MMResult getVideoResolution(int& r_resIndex) = 0;

    virtual MMResult setVideoResolution(const int c_resIndex) = 0;

    virtual MMResult setCameraDeviceType(const MMCameraDeviceType c_deviceType) = 0;

    virtual MMResult getCameraDeviceType(MMCameraDeviceType& r_deviceType) = 0;

    virtual MMResult setCameraFlipType(const MMCameraFlipType c_flipType) = 0;

    virtual MMResult getCameraFlipType(MMCameraFlipType& r_flipType) = 0;

    virtual MMResult enableImageStabilization(bool b_enable) = 0;

    virtual MMResult setCameraType(const MMCameraModeType c_mode) = 0;

    virtual MMResult getCameraType(MMCameraModeType &r_mode) = 0;

    virtual MMResult getSupportedCameraTypes(MMCameraModeType *& pr_modeList, int& r_numOfMode) = 0;

    virtual MMResult setUIMode(const MMUIModeType c_mode) = 0;

protected:
    virtual ~MMCameraControl(){}

};

#endif  
