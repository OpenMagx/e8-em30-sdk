

// Copyright (c) 07-Jun-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef USBD_APP_IF_H            
#define USBD_APP_IF_H

#ifdef __cplusplus 
extern "C" {
#endif

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>

#define USBD_SOCKET_NAME "/tmp/usbsocket"  

#define USBD_MAX_APPS 20 

#define USB_MEM_TARGET_DEVICE_RAM       (0x0001) 
#define USB_MEM_TARGET_DEVICE_BLK0      (0x0002) 
#define USB_MEM_TARGET_DEVICE_BLK1      (0x0004) 
#define USB_MEM_TARGET_DEVICE_NAND00    (0x0008) 
#define USB_MEM_TARGET_DEVICE_MTP       (0x0010) 
#define USB_MEM_TARGET_DEVICE_RESERVED  (0xFFE0) 

#define USB_MEM_ERR_INVALID_DEVICE      (-1) 
#define USB_MEM_ERR_MOUNT_PROBLEM       (-2) 
#define USB_MEM_ERR_UNMOUNT_PROBLEM     (-3) 

#define USB_STATUS_NONE         (-1)     
#define USB_STATUS_MODEM        0       
#define USB_STATUS_NET          1       
#define USB_STATUS_USBLAN       USB_STATUS_NET 
#define USB_STATUS_STORAGE      2       
#define USB_STATUS_ACM_TOOLS    3       
#define USB_STATUS_MTP          4       
#define USB_STATUS_PICTBRIDGE   5       
#define USB_STATUS_PTP          6       
#define USB_STATUS_CHGEONLY     7       
#define USB_STATUS_ALYSASK      8       
#define USB_STATUS_MAX          USB_STATUS_ALYSASK

#define USB_CABLE_ATTACHED 1
#define USB_CABLE_DETACHED 0

typedef enum
{
    USBD_APPID_MIN = 0, 
    USBD_APPID_QTSVR = USBD_APPID_MIN, 
    USBD_APPID_OTHER, 
    USBD_APPID_USBD,  
    USBD_APPID_MTPAPP, 
    USBD_APPID_SETUP, 
    USBD_APPID_MAX = USBD_APPID_SETUP 
} USBD_APPID_T;

typedef enum
{
    USBDSOCK_MSG_UDISK_ENTER, 
    USBDSOCK_MSG_UDISK_ENTER_OK, 
    USBDSOCK_MSG_UDISK_EXIT,  
    USBDSOCK_MSG_UDISK_EXIT_OK 
} USBDSOCK_MSG_T;

typedef enum
{
    USBDSOCK_MEMTYPE_MSC, 
    USBDSOCK_MEMTYPE_MTP  
} USBDSOCK_MEM_T;

typedef enum
{
    USBDSOCK_CMDTYPE_IDREPORT =1,   
    USBDSOCK_CMDTYPE_RES_USBMODE,  
    USBDSOCK_CMDTYPE_RET_USBMODE,  
    USBDSOCK_CMDTYPE_REQ_USBMODE,  
    USBDSOCK_CMDTYPE_GET_USBMODE,  
    USBDSOCK_CMDTYPE_ACCY_EVENT_MSG, 
    USBDSOCK_CMDTYPE_GETMEMSTATE, 
    USBDSOCK_CMDTYPE_MEMSTART,   
    USBDSOCK_CMDTYPE_MEMSTOP,    
    USBDSOCK_CMDTYPE_MTPSSTART,  
    USBDSOCK_CMDTYPE_UDISK_MSG,  
    USBDSOCK_CMDTYPE_UNLOAD_DISK,    
    USBDSOCK_CMDTYPE_GET_USBCABLE,  
    USBDSOCK_CMDTYPE_RET_USBCABLE,  
    USBDSOCK_CMDTYPE_MTP_WIFI,  
    USBDSOCK_CMDTYPE_ERROR      
} USBDSOCK_CMDTYPE_T;

typedef enum
{
    MTP_WIFI_STATUS_ACTIVE,
    MTP_WIFI_STATUS_INACTIVE,
    MTP_WIFI_STATUS_SWITCH2MTP_MODE,
    MTP_WIFI_STATUS_CANCEL_MODESWITCH_REQUEST
} MTP_WIFI_STATUS_T;

typedef enum
{
    USBDSOCK_RES_OK,   
    USBDSOCK_RES_BUSY,  
    USBDSOCK_RES_LOCK, 
    USBDSOCK_RES_ERROR  
} USBDSOCK_RES_T;

typedef struct
{
      USBD_APPID_T appid;         
      USBDSOCK_CMDTYPE_T cmdtype; 
      int data;                    
} USBDSOCK_PACKET_T;

extern int 
USBD_connect_daemon  ( 
                        USBD_APPID_T app_id 
                        );

extern int 
USBD_disconnect_daemon  ( 
                           int app_fd 
                           );

extern int 
USBD_get_usb_mode  ( 
                      int app_fd,
                      USBD_APPID_T app_id 
                      );

extern int 
USBD_get_usb_mode_blocked ( 
                            int app_fd,
                            USBD_APPID_T app_id 
			    );

extern int 
USBD_req_usb_mode  ( 
                      int app_fd,
                      USBD_APPID_T app_id,
                      int data  
                      );

extern int 
USBD_req_usb_mode_blocked ( 
                            int app_fd, 
                            USBD_APPID_T app_id,
                            int data 
                            );

extern unsigned int 
USBD_get_active_memory_devices( 
                               void 
                               );

extern int
GetUsbInterface(void);

extern int
USBD_get_usb_cable_blocked (
                            int app_fd,
                            USBD_APPID_T app_id
              );

extern void
USBD_set_mtpoverwifi_state (
                                 int app_fd,
                                 USBD_APPID_T app_id,
                                 int data
                );

#define get_Active_USB_Memory_Devices(void)  USBD_get_active_memory_devices() 

#ifdef __cplusplus
}
#endif 

#endif  

