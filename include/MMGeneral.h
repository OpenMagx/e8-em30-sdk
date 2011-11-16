

// Copyright (c) 12-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMGENERAL_H
#define MMGENERAL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>

#define MM_PRD_FILESIZE               "mm_prd_filesize"
#define MM_DLNA_CONTENTFLAG           "mm_dlna_contentflag"
#define MM_NETWORK_PROFILE            "mm_network_profile"
#define MM_NETWORK_SERVER_UNAME       "mm_network_server_uname"
#define MM_NETWORK_SERVER_PASSWD      "mm_network_server_passwd"
#define MM_NETWORK_PROXY              "mm_network_proxy"
#define MM_NETWORK_PROXY_PORT         "mm_network_proxy_port"
#define MM_NETWORK_PROXY_UNAME        "mm_network_proxy_uname"
#define MM_NETWORK_PROXY_PASSWD       "mm_network_proxy_passwd"

#define MM_COMMON_ARRAY_LEN       256

#define MM_LOCATOR_LEN       4096

#define MMTime unsigned int

#ifdef MMAPI_UNIT_TEST
    #define MM_PROTECTED public
    #define MM_PRIVATE public
#else
    #define MM_PROTECTED protected
    #define MM_PRIVATE private
#endif

enum FileProperty 
{
    MPE_FILEPROP_NORMAL = 0,
    MPE_FILEPROP_WMDRM_OUTPUTLEVEL,
    MPE_FILEPROP_WMDRM_NORMAL_LICENSE,
    MPE_FILEPROP_OMA_BULETOOTH,
};

#endif

