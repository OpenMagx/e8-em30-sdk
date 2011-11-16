

// Copyright (c) 09-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef _HSPLUGINDLL_H_
#define _HSPLUGINDLL_H_

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "HSPlugin.h"
#include "HSPluginContext.h"

extern "C" {

  HSPlugin* createInstance(HSPluginContext* context);

  void destroyInstance(HSPlugin* plugin);

  bool isActivated();

  bool isUserRemovable();
}

#endif  
