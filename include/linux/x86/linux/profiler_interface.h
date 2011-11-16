/*
 * FILE NAME
 *             profiler_interface.h
 *
 * BRIEF MODULE DESCRIPTION:
 *            header filer for PMDaemon and Profiler
 *
 * Copyright:  (c) Copyright Motorola 2005, All rights reserved.
 *
 * Revision History:
 *                            Modification    Tracking
 * Author                         Date         Number    Description of Changes
 * -----------------------   ------------    ---------- ----------------------
 * Wei Hao                      06/16/2005     LIBff96376   Initial version
 *
 *
 */


#ifndef PROFILER_INTERFACE_H
#define PROFILER_INTERFACE_H

#include <linux/ioctl.h>

typedef struct profiler_threshold {
   unsigned short high_threshold;
   unsigned short low_threshold;
} profiler_threshold_t;

typedef struct profiler_interval {
   unsigned short upper_bound_interval;
   unsigned short lower_bound_interval;
} profiler_interval_t;

typedef struct profiler_event {
   unsigned short type;
   unsigned short info;
} profiler_event_t;

/* event types */
#define PROFILER_DEC_FREQ 0
#define PROFILER_INC_FREQ 1 

#define PROFILER_DEVICE_NAME "profiler"
#define PROFILER_DEVICE "/dev/"PROFILER_DEVICE_NAME

#define PROFILER_IOC_MAGIC  'K'
#define PROFILER_IOC_SET_PROF_INTERVAL _IOW(PROFILER_IOC_MAGIC,0,profiler_interval_t)
#define PROFILER_IOC_GET_PROF_INTERVAL _IOR(PROFILER_IOC_MAGIC,1,profiler_interval_t)
#define PROFILER_IOC_SET_THRESHOLD _IOW(PROFILER_IOC_MAGIC,2,profiler_threshold_t)
#define PROFILER_IOC_GET_THRESHOLD _IOR(PROFILER_IOC_MAGIC,3,profiler_threshold_t)
#define PROFILER_IOC_CLEAR_EVENTQ _IO(PROFILER_IOC_MAGIC,4)

#define PROFILER_IOC_SET_EVENT _IOW(PROFILER_IOC_MAGIC,5,profiler_event_t)


#endif   /* PROFILER_INTERFACE_H end */
