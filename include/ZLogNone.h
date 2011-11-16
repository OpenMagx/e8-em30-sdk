

// Copyright (c)  - 2008 Motorola, Inc. All rights reserved.


#ifndef _ZLOGNONE_H
#define _ZLOGNONE_H

#ifndef UNUSED_PARAM
#define UNUSED_PARAM(v) (void)(v)
#endif

#include "ZLogLevel.h"

#if (EZXLOGLEVEL == -1)
    #define zDbg(fmt, arg...)
    #define	zInfo(fmt, arg...)
    #define	zWarning(fmt, arg...)
    #define	zError(fmt, arg...)
    #define	zCritical(fmt, arg...)
    #define	zEmergency(comid, sub_comid, err_code, fmt, arg...)
    #define	zLog(level, fmt, arg...)
    #define	zAssert(x)
    #define	zEnter(fmt, arg...)
    #define	zLeave(fmt, arg...)
    #define	zLogBinary(level, buf, len) 
    #define	zSDbg(fmt, arg...)
#else
#error EZXLOGLEVEL is not -1 !!!
#endif

#endif

