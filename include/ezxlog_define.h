

// Copyright (c)  - 2008 Motorola, Inc. All rights reserved.


#ifndef _ZLOG_H
#define _ZLOG_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ZLogComList.h"

#if (EZXLOGLEVEL==-1)
#include "ZLogNone.h"
#else
#include "ZLogSystemTest.h"
#endif

#endif

