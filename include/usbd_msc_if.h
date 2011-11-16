

// Copyright (c) 07-Jun-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef USBD_MEM_FUNC_H 
#define USBD_MEM_FUNC_H

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
#include <usbd_app_if.h>

#define MSC_IO "/proc/msc_io" 
#define MSC_MAGIC    'M'  
#define MSC_MOUNT            _IOWR(MSC_MAGIC, 1, msc_info) 
#define MSC_GET_UNKNOWN_CMD  _IOWR(MSC_MAGIC, 3, MSC_APP_WRAPPER) 

#define ANTIOCH_MAGIC    'M'    
#define ANT_MSC_OK           _IO(ANTIOCH_MAGIC, 31)
#define ANT_MSC_CANCEL       _IO(ANTIOCH_MAGIC, 32)

typedef struct
{
      unsigned long   Reserved[3]; 
      char   flags; 
      char   device_num; 
      char   Length; 
      char   information[16]; 
} 
__attribute__((packed)) MSC_APP_WRAPPER;

typedef struct 
{
  int     major;  
  int     minor; 
  int     lun;   
  int     writeprotect; 
  int     result; 
  int     status; 
} 
msc_info;

#ifdef __cplusplus
}
#endif 

#endif  

