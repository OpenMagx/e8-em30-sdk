

// Copyright (c) 27-Jul-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef GLOBAL_RESULTCODE_H 
#define GLOBAL_RESULTCODE_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "EZX_TypeDefs.h"

#define RES_SEVERITY_ERROR 1  
#define RES_SEVERITY_SUCCESS 0 

#define RES_IS_ERROR(resCode) ((UINT32)(resCode) >> 31 == RES_SEVERITY_ERROR)

#define SUCCEEDED(resCode) ((ResultCodeType)(resCode) >= 0)

#define FAILED(resCode) ((ResultCodeType)(resCode) < 0)

#define RES_COMPONENT(resCode) ((ResultCodeType)(resCode) >> 16 & 0xFF)

#define RES_CODE(resCode) ((ResultCodeType)(resCode) & 0xFFFF)

typedef enum 
{
    RES_COMP_LIMO        = 0xFF, 
    RES_COMP_MAGX        = 0xFE, 
    RES_COMP_OS          = 0xFD, 
    RES_COMP_UI          = 0xFC, 
    RES_COMP_SIERRA      = 0xFB, 
    RES_COMP_AM          = 0xFA, 
    RES_COMP_DB          = 0xF9, 
    RES_COMP_DM          = 0xF8, 
    RES_COMP_DRM         = 0xF7, 
    RES_COMP_SECURITY    = 0xF6, 
    RES_COMP_JAVA        = 0xF5, 
    RES_COMP_MM_ENGINE   = 0xF4, 
    RES_COMP_MM_FINDER   = 0xF3, 
    RES_COMP_MM_IMG_UTIL = 0xF2, 
    RES_COMP_MM_MEDL     = 0xF1, 
    RES_COMP_MM_MTP      = 0xF0, 
    RES_COMP_MM_NAV      = 0xEF, 
    RES_COMP_IMS         = 0xEE, 
    RES_COMP_PTX         = 0xED, 
    RES_COMP_VR          = 0xEC, 
    RES_COMP_TAPI        = 0xEB, 
    RES_COMP_CALLING     = 0xEA, 
    RES_COMP_LOCATION    = 0xE9, 
    RES_COMP_MOTOWHERE   = 0xE8, 
    RES_COMP_SME         = 0xE7, 
    RES_COMP_MESSAGING   = 0xE6, 
    RES_COMP_EMAIL       = 0xE5, 
    RES_COMP_IM          = 0xE4, 
    RES_COMP_CONN        = 0xE3, 
    RES_COMP_CONTACTS    = 0xE2, 
    RES_COMP_CALENDAR    = 0xD1, 
    RES_COMP_TASKS       = 0xD0, 
    RES_COMP_NOTES       = 0xDF, 
    RES_COMP_USER_APPS   = 0xDE, 
    RES_COMP_SETTINGS    = 0xDD, 
    RES_COMP_UTIL        = 0xDC, 
    RES_COMP_BROWSER     = 0xDB, 
    RES_COMP_DATASYNC    = 0xDA, 
    RES_COMP_MOTOSHARE   = 0xD9, 
    RES_COMP_SCREEN3     = 0xD8, 
    RES_COMP_HOMESCREEN  = 0xF7, 
    RES_COMP_DATALOGGING = 0xD6, 
    RES_COMP_UPNP        = 0xD5, 
    RES_COMP_DATA_NTWK   = 0xD4, 
    RES_COMP_LJ_IDEN     = 0xD3, 
    RES_COMP_WLAN        = 0xD2, 
    RES_COMP_RECENTCOM   = 0xC1, 
    RES_COMP_SLIM        = 0xC0, 
    RES_COMP_ES          = 0xCF, 
    RES_COMP_INSTALL     = 0xCE, 
    RES_COMP_FAULTLINE   = 0xCD, 
    RES_COMP_RVC         = 0xCC, 
    RES_COMP_VT          = 0xCB, 
    RES_COMP_VOIP        = 0xCA, 
    RES_COMP_RESERVED    = 0x00, 
} ResultComponentType;

typedef enum
{
    OPERATION_SUCCESS     = 0,	        
    ERR_OPERATION_FAILED  = 0xFFFFFFFF, 
    ERR_FILE_NOT_FOUND    = 0xFFFFFFFE, 
    ERR_PERMISSION_DENIED = 0xFFFFFFFD, 
    ERR_ARG_LIST_TOO_LONG = 0xFFFFFFFC, 
    ERR_OUT_OF_MEMORY     = 0xFFFFFFFB, 
    ERR_OPERATION_TIMEOUT = 0xFFFFFFFA, 
    ERR_SEND_MSG          = 0xFFFFFFF9, 
    ERR_RECEIVE_MSG       = 0xFFFFFFF8, 
    ERR_INVALID_MSG       = 0xFFFFFFF7  
} LIMOErrorType;

typedef enum
{
    RES_TIMEOUT_ERROR   = 0xFFFEFFFF, 
    RES_PARAM_ERROR     = 0xFFFEFFFE, 
    RES_INVALID_STATE   = 0xFFFEFFFD, 
    RES_NOT_SUPPORT     = 0xFFFEFFFC, 
    RES_BUSY            = 0xFFFEFFFB, 
    RES_INVALID_POINTER = 0xFFFEFFFA, 
    RES_OUT_OF_BOUNDS   = 0xFFFEFFF9, 
    RES_PATH_NOT_FOUND  = 0xFFFEFFF8, 
    RES_IO_FAILED       = 0xFFFEFFF7, 
    RES_OPEN_FAILED     = 0xFFFEFFF6, 
    RES_SEEK_FAILED     = 0xFFFEFFF5, 
    RES_READ_FAILED     = 0xFFFEFFF4, 
    RES_WRITE_FAILED    = 0xFFFEFFF3, 
    RES_SECURITY_ERROR  = 0xFFFEFFF2, 
    RES_UNKNOWN         = 0xFFFE0000      
} MAGXGeneralErrorType;

typedef INT32 ResultCodeType; 

extern ResultCodeType 
getErrorString (ResultCodeType resCode,  char* p_resString, UINT8 stringSize); 

#ifdef __cplusplus
}
#endif 

#endif  
