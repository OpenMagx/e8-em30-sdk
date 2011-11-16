

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_CB_CLIENT_H  
#define TAPI_CB_CLIENT_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "TAPI_SETUP_General.h"

#define TAPI_INVALID_CHANNEL_VALUE       0xFFFFFFFF

#define TAPI_CB_MAX_CHANNELS_NUMBER      24

#define TAPI_CB_MAX_JAVA_CHANNELS_NUMBER 100

#define TAPI_CB_LANGUAGES_NUMBER         5

#define TAPI_CB_MAX_LANGUAGES_NUMBER     16

#define GSM_CB_MAX_NUM_SIM_DOWNLOAD_CHANNELS (5)
#define GSM_CB_MAX_NUM_CLIENT_CHANNELS       (5)
#define GSM_CB_MAX_NUM_ACTIVE_CHANNELS       (5)
#define GSM_CB_MAX_NUM_QV_CHANNELS           (1)
#define GSM_CB_MAX_NUM_LANGUAGES             (5)
#define GSM_CB_GS_MASK                       (0xc000)
#define GSM_CB_GS_SHIFT                      (14)
#define GSM_CB_MC_MASK                       (0x3ff0)
#define GSM_CB_MC_SHIFT                      (4)
#define GSM_CB_UN_MASK                       (0x0f)
#define GSM_CB_UN_SHIFT                      (0)
#define GSM_CB_GS_CELL_WIDE_IMM_DISP         (0x0000)
#define GSM_CB_GS_CELL_WIDE_NOR_DISP         (0x0003)
#define GSM_CB_LAI_WIDE                      (0x0002)
#define GSM_CB_PLMN_WIDE                     (0x0001)
#define GSM_CB_DEFAULT_MID                   (0xffff)
#define GSM_CB_MAX_NUM_OF_PAGES              (15)
#define GSM_CB_MESSAGE_SIZE                  (0x58)
#define GSM_CB_USER_CHARACTERS               (93)
#define GSM_CB_BLOCK_SIZE                    (0x16)

#define GSM_CB_MAX_MESSAGE_SIZE        ((GSM_CB_USER_CHARACTERS * GSM_CB_MAX_NUM_OF_PAGES) + 1)

#define TAPI_CB_MAX_MSG_SIZE             (GSM_CB_MAX_MESSAGE_SIZE*2)

#define GSM_CB_MAX_NUM_OF_SCREENING_CRITERIAS (GSM_CB_MAX_NUM_SIM_DOWNLOAD_CHANNELS + \
                                               GSM_CB_MAX_NUM_CLIENT_CHANNELS + \
                                               GSM_CB_MAX_NUM_ACTIVE_CHANNELS + \
                                               GSM_CB_MAX_NUM_QV_CHANNELS)

typedef enum    _TAPI_CB_DCS_LANGUAGE_E
{
    TAPI_CB_DCS_LANGUAGE_GERMAN_EV      = 0,    
    TAPI_CB_DCS_LANGUAGE_ENGLISH_EV,            
    TAPI_CB_DCS_LANGUAGE_ITALIAN_EV,            
    TAPI_CB_DCS_LANGUAGE_FRENCH_EV,             
    TAPI_CB_DCS_LANGUAGE_SPANISH_EV,            
    TAPI_CB_DCS_LANGUAGE_DUTCH_EV,              
    TAPI_CB_DCS_LANGUAGE_SWEDISH_EV,            
    TAPI_CB_DCS_LANGUAGE_DANISH_EV,             
    TAPI_CB_DCS_LANGUAGE_PORTUAGUESE_EV,        
    TAPI_CB_DCS_LANGUAGE_FINNISH_EV,            
    TAPI_CB_DCS_LANGUAGE_NORWEGIAN_EV,          
    TAPI_CB_DCS_LANGUAGE_GREEK_EV,              
    TAPI_CB_DCS_LANGUAGE_TURKISH_EV,            
    TAPI_CB_DCS_LANGUAGE_HUNGARIAN_EV,          
    TAPI_CB_DCS_LANGUAGE_POLISH_EV,             
    TAPI_CB_DCS_LANGUAGE_AUTO_EV ,              

    TAPI_CB_DCS_LANGUAGE_CZECH_EV       = 0x20, 
} TAPI_CB_DCS_LANGUAGE_E;

enum _TAPI_CB_STATUS_E
{
    TAPI_CB_STATUS_OFF_EV,
    TAPI_CB_STATUS_ON_EV,
    TAPI_CB_STATUS_GENERAL_ON_EV,
    TAPI_CB_STATUS_PERSONAL_OFF_EV,
    TAPI_CB_STATUS_PERSONAL_ON_EV,
    TAPI_CB_STATUS_GENERAL_OFF_EV,
};
typedef UINT8   TAPI_CB_STATUS_E;

typedef UINT32  TAPI_CB_CHANNEL_A[TAPI_CB_MAX_CHANNELS_NUMBER];

typedef UINT8   TAPI_CB_LANGUAGE_A[TAPI_CB_MAX_LANGUAGES_NUMBER];

typedef struct  _TAPI_CB_DUPLICATE_INFO_S
{
    UINT16  sequenceNumber;     
    UINT16  messageIdentifier;  
    UINT8   pageParameter;      
} __attribute__( (packed) )  TAPI_CB_DUPLICATE_INFO_S;

typedef struct  _TAPI_CB_APP_MSG_S
{
    UINT16  serialNumber;                       
    UINT16  channelNumber;                      
    UINT8   cbContent[TAPI_CB_MAX_MSG_SIZE];    
} TAPI_CB_APP_MSG_S;

typedef struct  _TAPI_CB_EDIT_CHANNEL_S
{
    UINT32  channel;        
    UINT8   channelIndex;   
} TAPI_CB_EDIT_CHANNEL_S;

typedef struct  _TAPI_CB_EDIT_LANGUAGE_S
{
    UINT16  languageIndex;  
    UINT16  language;       
} TAPI_CB_EDIT_LANGUAGE_S;

extern TAPI_RESULT_E   
TAPI_CB_AddChannel( 
                   const UINT16 channel 
                   );

extern TAPI_RESULT_E   
TAPI_CB_DeleteChannel( 
                      const UINT16 channel 
                      );

extern TAPI_RESULT_E   
TAPI_CB_RegisterChannel( 
                        const UINT16 channel 
                        );

extern TAPI_RESULT_E   
TAPI_CB_DeregisterChannel( 
                          const UINT16 channel 
                          );

extern TAPI_RESULT_E   
TAPI_CB_GetChannels(
                    INT32*              pnCount,
                    TAPI_CB_CHANNEL_A   channels 
                    );

extern TAPI_RESULT_E   
TAPI_CB_GetChannelsEx(
                      INT32*      pnCount,
                      UINT32**    ppChannel 
                      );

extern TAPI_RESULT_E
TAPI_CB_GetRange(
                 UINT8*  pRange
                );

extern TAPI_RESULT_E   
TAPI_CB_SetChannel(
                    const UINT8     index,
                    const UINT32    channel 
                    );

extern TAPI_RESULT_E   
TAPI_CB_GetLanguages(
                     INT32*              pnCount,
                     TAPI_CB_LANGUAGE_A  languages 
                     );

extern TAPI_RESULT_E   
TAPI_CB_GetLanguagesEx(
                       INT32*      pnCount,
                       UINT8**     ppLanguage 
                       );

extern TAPI_RESULT_E   
TAPI_CB_SetLanguage(
                    const UINT16    index,
                    const UINT16    language 
                    );

extern TAPI_RESULT_E   
TAPI_CB_GetStatus( 
                  TAPI_CB_STATUS_E* pStatus 
                  );

extern TAPI_RESULT_E   
TAPI_CB_SetStatus( 
                  const TAPI_CB_STATUS_E status 
                  );

#ifdef __cplusplus
}

#endif
#endif 
