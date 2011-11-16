

// Copyright (c) 09-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef _HSPLUGINSETTINGDLL_H_
#define _HSPLUGINSETTINGDLL_H_

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "HSPluginSettingInfo.h"

extern "C" {
    HSPluginSettingInfo* getSettingInfo(QWidget* parent = 0);

}

#endif  
