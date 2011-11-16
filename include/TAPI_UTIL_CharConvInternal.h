

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef _TAPI_CHAR_CONV_INTERNAL_H_   
#define _TAPI_CHAR_CONV_INTERNAL_H_ 

#ifdef __cplusplus 
extern "C" {
#endif

#define TAPI_UTIL_GSM_TO_UCS2_CODE_CONVERT_TABLE_1_BEGIN  0x00 

#define TAPI_UTIL_GSM_TO_UCS2_CODE_CONVERT_TABLE_1_END    0x1F 

#define TAPI_UTIL_GSM_TO_UCS2_CODE_CONVERT_TABLE_2_BEGIN  0x5B 

#define TAPI_UTIL_GSM_TO_UCS2_CODE_CONVERT_TABLE_2_END    0x60 

#define TAPI_UTIL_GSM_TO_UCS2_CODE_CONVERT_TABLE_3_BEGIN  0x7B 

#define TAPI_UTIL_GSM_TO_UCS2_CODE_CONVERT_TABLE_3_END    0x7F 

#define TAPI_UCS2_TO_CODE_AREA_1_BEGIN   0x0000 

#define TAPI_UCS2_TO_CODE_AREA_1_END     0x00FF 

#define TAPI_UCS2_TO_CODE_AREA_2_BEGIN   0x0390 

#define TAPI_UCS2_TO_CODE_AREA_2_END     0x03CF 

#define TAPI_UCS2_TO_CODE_AREA_3_BEGIN   0x0100 

#define TAPI_UCS2_TO_CODE_AREA_3_END     0x017F 

#define TAPI_UCS2_HYFEN_CHARACTER (8208)

typedef struct
{
    UINT8   gsm_code;
    UINT16  ucs2Code;
} TAPI_UTIL_GSM_UCS2_CODE_CONVERT_MAPPING;

extern UINT16  
TAPI_UTIL_GetWordAtOddAddress( 
                              UINT8* pInputString 
                              );

extern void    
TAPI_UTIL_PutWordAtOddAddress(
                              UINT16  inputWord,
                              UINT8*  pOutputString 
                              );

#ifdef __cplusplus
}
#endif 

#endif  

