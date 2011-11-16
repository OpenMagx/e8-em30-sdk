

// Copyright (c)  - 2008 Motorola, Inc. All rights reserved.



#ifndef _NETMUX_DIRECT_H_
#define _NETMUX_DIRECT_H_

#include "types.h"
#include "errorcodes.h"
#include "utility.h"
#include "mux.h"

#include <linux/devfs_fs_kernel.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/fcntl.h>
#include <linux/errno.h>
#include <linux/poll.h>
#include <asm/uaccess.h>

#define DIRECT_DYNAMIC_MAJOR_ASSIGNMENT 0

#define DIRECT_STATE_DEFAULT       0
#define DIRECT_STATE_READY         1
#define DIRECT_STATE_EVENT         2
#define DIRECT_STATE_EVENT_SUCCESS 4

typedef struct DIRECT_MAJOR_LIST
{
    int32                   major;
    struct DIRECTINTERFACE* directif;

    struct DIRECT_MAJOR_LIST* next;
}DIRECT_MAJOR_LIST;

typedef struct DIRECT_CHANNELDATA
{
    int32 refcount;
    int32 state;
    int32 client_interface;
    int32 burstsize;
    int32 maxdata;
    int32 host_byte_credit;
    int32 host_send_credit;

    wait_queue_head_t event_wait;
    wait_queue_head_t close_wait;
    wait_queue_head_t rdevent;
    wait_queue_head_t wrevent;

    COMMBUFFQUEUE receive_queue;

    sint8 device_file[PACKET_MAXNAME_LENGTH];
}DIRECT_CHANNELDATA;

typedef struct DIRECTINTERFACE
{
    int32 major;
    int32 channel_min;
    int32 channel_max;
    int32 host_interface;

    DIRECT_CHANNELDATA* channel_data;
    MUX*                mux;
    CRITICALSECTION     lock;

    sint8  device_directory[PACKET_MAXNAME_LENGTH];
    sint8  interface_name[PACKET_MAXNAME_LENGTH];

    struct file_operations operations;
}DIRECTINTERFACE;

int32 DirectInform  (void*, void*);
int32 DirectReceive (COMMBUFF*, void*);

int32 CreateDirectInterface  (sint8*, sint8*, int32, int32, int32, MUX*, DIRECTINTERFACE**);
int32 DestroyDirectInterface (DIRECTINTERFACE*);

int          DirectOpen  (struct inode*, struct file*);
int          DirectClose (struct inode*, struct file*);
unsigned int DirectPoll  (struct file*, poll_table*);
ssize_t      DirectRead  (struct file*, char*, size_t, loff_t*);
ssize_t      DirectWrite (struct file*, const char*, size_t, loff_t*);

#endif
