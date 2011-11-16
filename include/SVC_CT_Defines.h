

// Copyright (c) 23-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef SVC_CT_DEFINES_H
#define SVC_CT_DEFINES_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

class SVC_CT_Defines
{
public:
    typedef enum
    {
        RET_SUCCESS         = 0,  
        RET_END_REACHED     = -1, 
        RET_SLOWSYNC_NEEDED = -2, 
        RET_ERROR           = -3, 
        RET_NOSPACE         = -4, 
        RET_NORAM           = -5  
    }
    RET_ENUM_T;

    typedef enum
    {
        TYPE_ALL,        
        TYPE_ADD,        
        TYPE_UPDATE,     
        TYPE_DELETE,     
        TYPE_MOVE,       
        TYPE_SOFT_DELETE 
    }
    CHANGETYPE_ENUM_T;

    typedef enum
    {
        STORAGE_TYPE_UNKNOWN   = 0,  
        STORAGE_TYPE_PHONE_SIM = 1,  
        STORAGE_TYPE_PHONE     = 2,  
        STORAGE_TYPE_SIM       = 3   
    }
    STORAGE_TYPE_ENUM_T;

};

#endif 
