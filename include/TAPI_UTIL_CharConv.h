

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef _TAPI_CHAR_CONV_UTIL_H_ 
#define _TAPI_CHAR_CONV_UTIL_H_ 

#ifdef __cplusplus 
extern "C" {
#endif

#define TAPI_GSM_UNRECOGNIZED_CODE            0x00

#define TAPI_UCS2_UNRECOGNIZED_CODE 0x220E

# define TAPI_UTIL_INVALID_STRING 0xFFFF

#define TAPI_GSM_EXTENSION_ESCAPE   0x1B

extern UINT16  
TAPI_UTIL_ConvertUcs2StringToGsmString(
                                       const UINT8*    pSource,
                                       UINT16          sourceLength,
                                       UINT8*          pTarget,
                                       UINT16          targetBufLength 
                                       );

extern UINT16  
TAPI_UTIL_ConvertGsmStringToUcs2String(
                                       const UINT8*    pSource,
                                       UINT16          sourceLength,
                                       UINT8*          pTarget,
                                       UINT16          targetBufLength 
                                       );

extern BOOLEAN 
TAPI_UTIL_ConvertUcs2ToGsmCode(
                               UINT16  ucs2Code,
                               UINT8*  pGsmCode 
                               );

extern UINT16  
TAPI_UTIL_ConvertAsciiStringToUcs2String(
                                         const UINT8*    pSource,
                                         UINT16          sourceLength,
                                         UINT8*          pTarget,
                                         UINT16          targetBufLength 
                                         );

extern UINT16  
TAPI_UTIL_ConvertUcs2StringToAsciiString(
                                         const UINT8*    pSource,
                                         UINT16          sourceLength,
                                         UINT8*          pTarget,
                                         UINT16          targetBufLength 
                                         );

extern BOOLEAN 
TAPI_UTIL_AsciiToUnicode(
                         UINT8*      pAsciiBuf,
                         UINT16*     pTextBuf 
                         );   

extern BOOLEAN 
TAPI_UTIL_BigEndianToLittleEndian(
                                  UINT8*  pUnicodeData,
                                  UINT16  dataLen 
                                  );

extern BOOL
TAPI_UTIL_is_little_endian (void);

extern  void
TAPI_UTIL_convert_nbytes_endian (
                                 const UINT8 * input_ptr, 
                                 UINT8 * output_ptr,
                                 UINT8 field_size
                                 );

extern  void
TAPI_UTIL_check_and_convert_endian_format_for_string(
                                                     UINT8 * input_ptr,
                                                     W_CHAR *output_ptr,
                                                     UINT16 num_bytes
                                                     );

#ifdef __cplusplus
}
#endif 

#endif  

