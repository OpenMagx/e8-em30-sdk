

// Copyright (c) 04-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ADDRBK_ENG_DEF_H
#define ADDRBK_ENG_DEF_H

#include "EZX_TypeDefs.h"

#define ADDRBK_PHONECONTACT_MAX_LEN_FIRSTNAME     (50)

#define ADDRBK_PHONECONTACT_MAX_LEN_LASTNAME      (50)

#define ADDRBK_MAX_LEN_NUMBER                     (40)

#define ADDRBK_PHONECONTACT_MAX_COUNT           (-1)
#define ADDRBK_PHONECATEGORY_MAX_COUNT          (-1)

#define ADDRBK_PHONECONTACT_MAX_LEN_FIRSTNAME     (50)

#define ADDRBK_PHONECONTACT_MAX_LEN_LASTNAME      (50)
#define ADDRBK_MAX_LEN_NUMBER                     (40)

#define ADDRBK_MAX_LEN_EMAIL                      (64)

#define ADDRBK_GROUP_MAX_LEN_FIRSTNAME            (24)

#define ADDRBK_ENG_PTT_FORUI (0x00000800)
#define ADDRBK_INVALID_UID  (0)

#define ADDRBK_INVALID_RECID  (0)

#define ADDRBK_CATEGORY_UNFILED_UID  ((ADDRBK_UID_T)(-1))

#define ADDRBK_OWNER_UID (0x7FFFFFFE)

#define ADDRBK_MAX_CONTENT_TRUNCATE               (15)

#define ADDRBK_ENG_VC_DECODE_FLAG_IM                    (0x00000001)
#define ADDRBK_ENG_VC_DECODE_FLAG_IGNORE_PICTURE        (0x00010000)

#if (FEAT_NAB == TRUE)
#define ADDRBK_ENG_MAX_TRACKED_SIMS     (4)
#endif

typedef enum {
    ADDRBK_ENG_RES_SUCCESS = 0,

    ADDRBK_ENG_RES_ERR_DB_FULL = -100,
    ADDRBK_ENG_RES_ERR_REC_NOT_FOUND = -101,
    ADDRBK_ENG_RES_ERR_NOTSUPPORT = -102,
    ADDRBK_ENG_RES_ERR_OTHER = -103,
    ADDRBK_ENG_RES_ERR_PROTECTED = -104,
    ADDRBK_ENG_RES_ERR_HAVING_EXISTED = -105,
    ADDRBK_ENG_RES_ERR_NOMEMORY = -106,
    ADDRBK_ENG_RES_ERR_DB_NOT_INITIAL = -107,
    ADDRBK_ENG_RES_ERR_DB_DEADLOCK = -108,
    ADDRBK_ENG_RES_ERR_SIM_EXT_FULL = -150,

    ADDRBK_ENG_RES_ERR_FIXDIAL_ON = -151,

    ADDRBK_ENG_RES_ERR_LACK_USIM_FIELD_LOCATIONS = -152,

    ADDRBK_ENG_RES_ERR_SYNC = -200,

    ADDRBK_ENG_RES_WARN_TRUNCATED = 101,

    ADDRBK_ENG_RES_LINK_SIM_FULL = 102,

    ADDRBK_ENG_RES_ERR_STORAGE_TYPE_NOT_MATCHING = -300,
} ADDRBK_ENG_RESULT_T;

typedef enum {
    ADDRBK_ENG_STORAGE_PHONE,
    ADDRBK_ENG_STORAGE_SIM,
    ADDRBK_ENG_STORAGE_UNKNOWN = -1,
} ADDRBK_ENG_STORAGE_T;

typedef enum {
    ADDRBK_ENG_VCARD_VERSION_21,
    ADDRBK_ENG_VCARD_VERSION_30,
} ADDRBK_ENG_VCARD_VERSION_T;

typedef enum {
    ADDRBK_RECORD_TYPE_PHONECATEGORY = (UINT32)1,
    ADDRBK_RECORD_TYPE_USIMCATEGORY,
    ADDRBK_RECORD_TYPE_PHONECONTACT,
    ADDRBK_RECORD_TYPE_SIMCONTACT,
    ADDRBK_RECORD_TYPE_USIMCONTACT,
    ADDRBK_RECORD_TYPE_FDNCONTACT,
} ADDRBK_RECORD_TYPE_T;

#define  ADDRBK_ATTR_CLEAR_SPECIAL  0xFF9FFFFF

#define ADDRBK_ATTR_TEL_MASK   (ADDRBK_ATTR_TEL_MOBILE | \
                                ADDRBK_ATTR_TEL_HOME   | \
                                ADDRBK_ATTR_TEL_WORK   | \
                                ADDRBK_ATTR_TEL_FAX    | \
                                ADDRBK_ATTR_TEL_PAGER  | \
                                ADDRBK_ATTR_TEL_OTHER)

#define ADDRBK_ATTR_EMAIL_MASK (ADDRBK_ATTR_EMAIL_HOME | \
                                ADDRBK_ATTR_EMAIL_WORK | \
                                ADDRBK_ATTR_EMAIL_OTHER)

typedef enum {
    ADDRBK_ATTR_TEL_MOBILE = (UINT32)0x00000100,
    ADDRBK_ATTR_TEL_HOME   = (UINT32)0x00000200,
    ADDRBK_ATTR_TEL_WORK   = (UINT32)0x00000400,
    ADDRBK_ATTR_TEL_FAX    = (UINT32)0x00000800,
    ADDRBK_ATTR_TEL_PAGER  = (UINT32)0x00001000,
    ADDRBK_ATTR_TEL_OTHER  = (UINT32)0x00002000,
    ADDRBK_ATTR_TEL_P2P    = (UINT32)0x00004000,

    ADDRBK_ATTR_EMAIL_HOME  = (UINT32)0x00010000,
    ADDRBK_ATTR_EMAIL_WORK  = (UINT32)0x00020000,
    ADDRBK_ATTR_EMAIL_OTHER = (UINT32)0x00040000,

    ADDRBK_ATTR_IM = (UINT32)0x00100000,

    ADDRBK_ATTR_VIDEOCALL = (UINT32)0x00200000,
    ADDRBK_ATTR_PTT = (UINT32)0x00400000,

    ADDRBK_ATTR_MYFAVE = (UINT32)0x00800000,

    ADDRBK_ATTR_ADDRESS_HOME  = (UINT32)0x01000000,
    ADDRBK_ATTR_ADDRESS_WORK  = (UINT32)0x02000000,
    ADDRBK_ATTR_ADDRESS_OTHER = (UINT32)0x08000000,

    ADDRBK_ATTR_URL_HOME  = (UINT32) 0x10000000,
    ADDRBK_ATTR_URL_WORK  = (UINT32) 0x20000000,
    ADDRBK_ATTR_URL_OTHER = (UINT32) 0x40000000,

    ADDRBK_ATTR_UNKNOWN = (UINT32)0,

} ADDRBK_ATTR_TYPE_T;

typedef enum {
    ADDRBK_STRING_FIELD_TYPE_FIRST = (UINT32)0,
    ADDRBK_STRING_FIELD_TYPE_FIRSTNAME,
    ADDRBK_STRING_FIELD_TYPE_LASTNAME,
    ADDRBK_STRING_FIELD_TYPE_NICKNAME,
    ADDRBK_STRING_FIELD_TYPE_COMPANYNAME,
    ADDRBK_STRING_FIELD_TYPE_ORGNAME,
    ADDRBK_STRING_FIELD_TYPE_PICTURE,
    ADDRBK_STRING_FIELD_TYPE_VOICETAG,
    ADDRBK_STRING_FIELD_TYPE_VOICENOTE,
    ADDRBK_STRING_FIELD_TYPE_NOTES,
    ADDRBK_STRING_FIELD_TYPE_TITLE,
    ADDRBK_STRING_FIELD_TYPE_MANAGERNAME,
    ADDRBK_STRING_FIELD_TYPE_ASSISTANTNAME,
    ADDRBK_STRING_FIELD_TYPE_SPOUSENAME,
    ADDRBK_STRING_FIELD_TYPE_CHILDRENNAME,
    ADDRBK_STRING_FIELD_TYPE_BIRTHDAY,
    ADDRBK_STRING_FIELD_TYPE_ANNIVERSARY,
    ADDRBK_STRING_FIELD_TYPE_RINGALERT,
    ADDRBK_STRING_FIELD_TYPE_VIDEO,
    ADDRBK_STRING_FIELD_TYPE_WEBSITE,
    ADDRBK_STRING_FIELD_TYPE_DISPLAYNAME,
    ADDRBK_STRING_FIELD_TYPE_ZODIAC,
    ADDRBK_STRING_FIELD_TYPE_ALARMBIRTHDAY,
    ADDRBK_STRING_FIELD_TYPE_ALARMANNIVERSARY,
    ADDRBK_STRING_FIELD_TYPE_MESSAGEALERT,
    ADDRBK_STRING_FIELD_TYPE_LIGHTALERT,
    ADDRBK_STRING_FIELD_TYPE_LOCATION,
    ADDRBK_STRING_FIELD_TYPE_LAST,

    ADDRBK_CONTENT_FIELD_TYPE_EMAIL,
    ADDRBK_CONTENT_FIELD_TYPE_IM,
    ADDRBK_CONTENT_FIELD_TYPE_TEL,
    ADDRBK_CONTENT_FIELD_TYPE_URL,

    ADDRBK_ADDRESS_FIELD_TYPE_ADDRESS,

    ADDRBK_BOOL_FIELD_TYPE_BODYTRUNCATE = 0x01000000,
#if(FEAT_NAB == TRUE)
    ADDRBK_BOOL_FIELD_TYPE_HIDDEN = 0x08000000,
#endif
    ADDRBK_BOOL_FIELD_TYPE_PRIVATE = 0x10000000,
    ADDRBK_BOOL_FIELD_TYPE_PROTECTED = 0x20000000,
    ADDRBK_BOOL_FIELD_TYPE_CORPORATE = 0x40000000,
    ADDRBK_BOOL_FIELD_TYPE_MYFAVE = 0x80000000,

} ADDRBK_FIELD_TYPE_T;

typedef enum
{
    ADDRBK_SEARCH_TYPE_PHONE,
    ADDRBK_SEARCH_TYPE_SMS,
    ADDRBK_SEARCH_TYPE_EMAIL,
    ADDRBK_SEARCH_TYPE_P2P,
    ADDRBK_SEARCH_TYPE_IM,
} ADDRBK_SEARCH_TYPE_T;

typedef enum {
    ADDRBK_DEFAULT_PRIMARY = (UINT32) 0x00000001,
    ADDRBK_DEFAULT_SMS = (UINT32) 0x00000040,
    ADDRBK_DEFAULT_EMAIL = (UINT32) 0x00000080,
    ADDRBK_DEFAULT_IM = (UINT32) 0x00000100,
    ADDRBK_DEFAULT_IM_REGISTER = (UINT32) 0x00002000,
    ADDRBK_DEFAULT_URL = (UINT32) 0x00004000,
} ADDRBK_DEFAULT_TYPE_T;

typedef enum {
    FREQUENCY_TYPE_CALL = (UINT32)0,
    FREQUENCY_TYPE_EMAIL = (UINT32)1,
    FREQUENCY_TYPE_MSG = (UINT32)2,
    FREQUENCY_TYPE_POSTCARD = (UINT32)3,
} ADDRBK_FREQUENCY_TYPE_T;

typedef enum {
    ADDRBK_FILTER_TYPE_PHONE,
    ADDRBK_FILTER_TYPE_SIM,
    ADDRBK_FILTER_TYPE_FIXDIAL,
    ADDRBK_FILTER_TYPE_ADDRESS_SELECTION,
    ADDRBK_FILTER_TYPE_CALL_SELECTION,
    ADDRBK_FILTER_TYPE_EMAIL_SELECTION,
    ADDRBK_FILTER_TYPE_MSG_SELECTION,
    ADDRBK_FILTER_TYPE_MFMR_CALL,
    ADDRBK_FILTER_TYPE_MFMR_EMAIL,
    ADDRBK_FILTER_TYPE_MFMR_MSG,
    ADDRBK_FILTER_TYPE_MFMR_ADDRESS,
    ADDRBK_FILTER_TYPE_LINKEDSIM,
    ADDRBK_FILTER_TYPE_OWNER_CONTACT,
    ADDRBK_FILTER_TYPE_NOT_MYFAVE_CONTACT,
    ADDRBK_FILTER_TYPE_MYFAVE_CANDIDATE,

} ADDRBK_FILTER_TYPE_T;

typedef enum
{
    ADDRBK_SIM_TRACK_LASTUSED,
    ADDRBK_SIM_TRACK_NEW,
    ADDRBK_SIM_TRACK_PREVIOUSUSED,
} ADDRBK_SIM_TRACK_T;

typedef enum {
    ADDRBK_UICC_NAME,
    ADDRBK_UICC_NUMBER,
    ADDRBK_UICC_EXT1,
    ADDRBK_UICC_EMAIL,
    ADDRBK_UICC_NICKNAME,
    ADDRBK_UICC_CATEGORY,
    ADDRBK_UICC_NUMBER_TYPE_STR,
    ADDRBK_UICC_PRIVATE,
} ADDRBK_UICC_FIELD_T;

typedef enum {
    ADDRBK_UICC_TYPE_UNKNOWN,
    ADDRBK_UICC_TYPE_SIM,
    ADDRBK_UICC_TYPE_USIM
} ADDRBK_UICC_TYPE_T;

typedef enum {
    ADDRBK_SEL_BASIC   = 0x00000001,
    ADDRBK_SEL_CONTENT = 0x00000002,
    ADDRBK_SEL_ADDR    = 0x00000004,
    ADDRBK_SEL_VR      = 0x00000008,
} ADDRBK_SELECTION_T;

typedef enum {
    ADDRBK_RECIP_MSG    = 0x00000001,
    ADDRBK_RECIP_NUMBER = 0x00000002,
    ADDRBK_RECIP_EMAIL  = 0x00000004,
    ADDRBK_RECIP_ALL    = 0x00000008,
} ADDRBK_RECIPIENT_T;

typedef INT32 ADDRBK_UID_T;

typedef INT32 ADDRBK_RECORD_ID_T;

typedef struct {
    INT32  maxNameLen;
    INT32  maxNumberLen;
} ADDRBK_SIM_RANGE_S;

typedef struct {
    ADDRBK_RECORD_TYPE_T recordType;
    ADDRBK_UID_T uid;
} ADDRBK_CONTACT_UID_S;

#endif  