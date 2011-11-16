

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_MAILBOX_CLIENT_H 
#define TAPI_MAILBOX_CLIENT_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_Result.h"
#include "TAPI_SETUP_General.h"

#define TAPI_MAILBOX_NUMBER_MAX_SIZE 20

enum _TAPI_MAILBOX_GSMR4_TYPE_E
{
    TAPI_MAILBOX_GSMR4_TYPE_VOICE_EV        = 0,    
    TAPI_MAILBOX_GSMR4_TYPE_FAX_EV          = 1,    
    TAPI_MAILBOX_GSMR4_TYPE_ELECTRONIC_EV   = 2,    
    TAPI_MAILBOX_GSMR4_TYPE_OTHER_EV        = 3,    
    TAPI_MAILBOX_GSMR4_TYPE_VIDEO_EV        = 4,    
    TAPI_MAILBOX_GSMR4_MAX_TYPE_COUNT
};

typedef UINT8   TAPI_MAILBOX_GSMR4_TYPE_E;

typedef struct  _TAPI_MAILBOX_GSMR4_MAIL_COUNT_S
{
    UINT8   type;   
    UINT8   count;  
} TAPI_MAILBOX_GSMR4_MAIL_COUNT_S;

typedef TAPI_MAILBOX_GSMR4_MAIL_COUNT_S TAPI_MAILBOX_GSMR4_MAIL_COUNT_A[
    TAPI_MAILBOX_GSMR4_MAX_TYPE_COUNT];

typedef struct  _TAPI_MAILBOX_GSMR4_ENTRY_S
{
    UINT8                   type;   
    TAPI_PHONE_NUMBER_A     number; 
    TAPI_PHONEBOOK_NAME_A   name;   
} TAPI_MAILBOX_GSMR4_ENTRY_S;

typedef TAPI_MAILBOX_GSMR4_ENTRY_S      TAPI_MAILBOX_GSMR4_ENTRY_A[
    TAPI_MAILBOX_GSMR4_MAX_TYPE_COUNT];

typedef struct  _TAPI_CPHS_VOICE_MAILBOX_S
{
    UINT8                   lineNo; 
    TAPI_PHONE_NUMBER_A     number; 
    TAPI_PHONEBOOK_NAME_A   name;   
} TAPI_CPHS_VOICE_MAILBOX_S;

typedef struct _TAPI_MAILBOX_RANGE_S
{
    UINT8   maxNumberLen;           
    UINT8   maxNameLen;             
} TAPI_MAILBOX_RANGE_S;

extern TAPI_RESULT_E   
TAPI_MAILBOX_Gsmr4GetAllEntry(
                              TAPI_MAILBOX_GSMR4_ENTRY_A  mailbox 
                              );

extern TAPI_RESULT_E   
TAPI_MAILBOX_Gsmr4GetEntry(
                           const TAPI_MAILBOX_GSMR4_TYPE_E type,
                           TAPI_PHONE_NUMBER_A             number,
                           TAPI_PHONEBOOK_NAME_A           name 
                           );

extern TAPI_RESULT_E   
TAPI_MAILBOX_Gsmr4SetEntry(
                           const TAPI_MAILBOX_GSMR4_TYPE_E type,
                           TAPI_PHONE_NUMBER_A             number,
                           TAPI_PHONEBOOK_NAME_A           name 
                           );

extern TAPI_RESULT_E   
TAPI_MAILBOX_Gsmr4IsModifiable( 
                               BOOLEAN* pbModifiable 
                               );

extern TAPI_RESULT_E   
TAPI_MAILBOX_Gsmr4GetAllMailCount(
                                  TAPI_MAILBOX_GSMR4_MAIL_COUNT_A count 
                                  );

extern TAPI_RESULT_E   
TAPI_MAILBOX_Gsmr4GetMailCount(
                               const TAPI_MAILBOX_GSMR4_TYPE_E type,
                               UINT8*                          pCount 
                               );

extern TAPI_RESULT_E   
TAPI_MAILBOX_Gsmr4SetMailCount(
                               const TAPI_MAILBOX_GSMR4_TYPE_E type,
                               UINT8                           count 
                               );

extern TAPI_RESULT_E   
TAPI_MAILBOX_CphsGetVoiceMailBox(
                                 const UINT8             lineNo,
                                 TAPI_PHONE_NUMBER_A     number,
                                 TAPI_PHONEBOOK_NAME_A   name 
                                 );

extern TAPI_RESULT_E   
TAPI_MAILBOX_CphsSetVoiceMailBox(
                                 const UINT8                 lineNo,
                                 const TAPI_PHONE_NUMBER_A   number,
                                 const TAPI_PHONEBOOK_NAME_A name 
                                 );

extern TAPI_RESULT_E   
TAPI_MAILBOX_Gsmr4GetRange( TAPI_MAILBOX_RANGE_S* mRange ) ;

extern TAPI_RESULT_E
TAPI_MAILBOX_Gsmr4GetExtRange( UINT16* mExtDigitNum );

TAPI_RESULT_E TAPI_MAILBOX_Gsmr4GetExtCapacity( TAPI_PHONEBOOK_CAPACITY_S* mCapacity );

extern TAPI_RESULT_E   
TAPI_MAILBOX_Cphs_Voicemail_GetRange( TAPI_MAILBOX_RANGE_S* mRange ) ;

#ifdef __cplusplus
}
#endif 

#endif  

