

// Copyright (c) 20-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMFLASHCONTROL_H 
#define MMFLASHCONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMResult.h"

enum MMFlashModes
{
	 MMFLASH_MODE_UNKNOWN = 0,

	 MMFLASH_OFF = 1,

	 MMFLASH_AUTO = 2,

	 MMFLASH_AUTO_WITH_REDEYEREDUCE = 3,

	 MMFLASH_FORCE = 4,

	 MMFLASH_FORCE_WITH_REDEYEREDUCE = 5,

	 MMFLASH_FILLIN = 6,

       MMFLASH_ON = 7,                      

         MMNUM_OF_FLASH_MODE
};
typedef int MMFlashModeType;

class MMFlashControl
{
public:
    virtual MMResult getMode(MMFlashModeType& r_mode) = 0;

    virtual MMResult getSupportedModes(MMFlashModeType *& pr_modeList, 
                                     int& r_numOfMode
                                   ) = 0;

    virtual MMResult isFlashReady(bool& r_ready) = 0;

    virtual MMResult setMode(const MMFlashModeType c_mode) = 0;

protected:
    virtual ~MMFlashControl(){}

};

#endif  
