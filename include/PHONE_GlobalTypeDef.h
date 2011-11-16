

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PHONE_GLOBALTYPEDEF_H
#define PHONE_GLOBALTYPEDEF_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

typedef enum 
{
    CALL_CATEGORY_NONE, 
    CALL_CATEGORY_ANSWERED, 
    CALL_CATEGORY_UNANSWERED,
    CALL_CATEGORY_CALLED, 
    CALL_CATEGORY_ALL_CALLS, 
    CALL_CATEGORY_FREQUENT, 
}CALL_CATEGORY_T;

typedef enum 
{
    CALL_CATEGORY_LIST_VIEW, 
    CALL_CATEGORY_MULT_VIEW, 
}CALL_CATEGORY_VIEW;

typedef enum 
{
    ORANGE_IDLE, 
    BARBADOS_IDLE, 
    UNS_DIALOG, 
}CALL_DETAIL_VIEW_T;

typedef enum 
{
    CALL_RESTRICT_ID_NONE, 
    CALL_RESTRICT_ID_ENABLE, 
    CALL_RESTRICT_ID_DISABLE, 
}CALL_RESTRICT_ID_E;

enum
{
    TTY_MODE_TYPE_TTY, 
    TTY_MODE_TYPE_VCO, 
    TTY_MODE_TYPE_HCO, 
    TTY_MODE_TYPE_VOICE, 
};

enum
{
    TTY_MODE_ON = 0, 
    TTY_MODE_OFF, 
};

typedef enum Contact_Type_T
{
    Contact_Type_NONE, 
    Contact_Type_OFFICE, 
    Contact_Type_MOBILE, 
    Contact_Type_HOME, 
    Contact_Type_FAX, 
    Contact_Type_SIM, 
    Contact_Type_OTHER, 
    Contact_Type_MYFAVE, 
}Contact_Type_T;

#endif 

