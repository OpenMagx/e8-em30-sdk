

// Copyright (c) 09-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef _HSLAYOUTFOCUSDLL_H_
#define _HSLAYOUTFOCUSDLL_H_

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "HSLayoutMgr.h"
#include "HSFocusMgr.h"
#include "HSLayoutContext.h"
#include "HSFocusContext.h"

extern "C" {
  HSLayoutMgr* createLayoutManager(HSLayoutContext* pContext);

  void destroyLayoutManager(HSLayoutMgr* pLayoutMgr);

  HSFocusMgr* createFocusManager(HSFocusContext* pContext);

  void destroyFocusManager(HSFocusMgr* pFocusMgr);
}

#endif  
