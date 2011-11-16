

// Copyright (c) 04-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ADDRBK_UI_SETTING_H 
#define ADDRBK_UI_SETTING_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#define ADDRBK_UI_SETTING_CHANNEL  "EZX/addrbk-ui-setting-channel"   
#define ADDRBK_UI_SETTING_MSG      "addrbk-ui-setting(int)"          

class ADDRBK_UI_Setting
{

public:

    typedef enum {
         VIEW,             
         SORT_ORDER,       
         MEMORY_LOCATION,   
    }
	SETTING_TYPE;

    typedef enum {
         FIRST_NAME,  
         LAST_NAME,   
    }
	SORT_TYPE;
};
#endif 
