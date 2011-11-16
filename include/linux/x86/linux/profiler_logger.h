/*
 * FILE NAME
 *             profiler_logger.h
 *
 * BRIEF MODULE DESCRIPTION:
 *            header filer for logger application and Profiler
 *
 * Copyright:  (c) Copyright Motorola 2005, All rights reserved.
 *
 * Revision History:
 *                            Modification    Tracking
 * Author                         Date         Number    Description of Changes
 * -----------------------   ------------    ---------- ----------------------
 * Wei Hao                     10/10/2005    LIBgg87860   Initial version
 *
 *
 */


#ifndef PROFILER_LOGGER_H
#define PROFILER_LOGGER_H

/* control channel command values */
typedef enum
{
	APP_START = 1,
	APP_START_ACK_SUCCESS,
        APP_START_ACK_FAILURE,
        APP_STOP,
	LOGGING_START,
	LOGGING_STOP,
	KERNEL_EXIT
} ctl_msg_type_t;


typedef struct data_channel_conf{
    unsigned int buf_size;
    unsigned int number_bufs;
    char filename[20];
}data_channel_conf_t;

#endif   /* PROFILER_LOGGER_H end */
