

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_UTIL_TELNO_FCNS_H   
#define TAPI_UTIL_TELNO_FCNS_H   

#ifdef __cplusplus 
extern "C" {
#endif

#define TAPI_TELNO_NUMBER_LENGTH       20

#define TAPI_TELNO_MAX_NUMBER_LENGTH       63

#define TAPI_TELNO_MAX_NUMBER_ARRAY_SIZE   (TAPI_TELNO_MAX_NUMBER_LENGTH + 1)

#define TAPI_TELNO_PAUSE_CHAR              'p'

#define TAPI_TELNO_WAIT_CHAR               'w'

#define TAPI_TELNO_NVALUE_CHAR             'n'

#define TAPI_TELNO_INTERNATIONAL_CHAR      '+'

#define TAPI_TELNO_STAR_CHAR               '*'

#define TAPI_TELNO_POUND_CHAR              '#'

#define TAPI_TELNO_SUBADDRESS_CHAR         '.'

#define TAPI_TELNO_STAR_CHAR_BCD_TRANSLATION       0x0A

#define TAPI_TELNO_POUND_CHAR_BCD_TRANSLATION      0x0B

#define TAPI_TELNO_PAUSE_CHAR_BCD_TRANSLATION      0x0C

#define TAPI_TELNO_WAIT_CHAR_BCD_TRANSLATION       0x0D

#define TAPI_TELNO_NVALUE_CHAR_BCD_TRANSLATION     0x0E

#define TAPI_TELNO_CHAR_NULL_HIGH      0xF0
#define TAPI_TELNO_CHAR_NULL_LOW       0x0F

#define TAPI_TELNO_CHAR_NULL           (TAPI_TELNO_CHAR_NULL_HIGH | TAPI_TELNO_CHAR_NULL_LOW)

#define TAPI_TELNO_CHAR_ASCII_NULL         '\0'

#define UNICODE_CHAR_DIGIT_ZERO                 0x0030
#define UNICODE_CHAR_DIGIT_NINE                 0x0039
#define UNICODE_CHAR_ASTERISK                   0x002A
#define UNICODE_CHAR_POUND_SIGN                 0x00A3
#define UNICODE_CHAR_NUMBER_SIGN                0x0023
#define UNICODE_CHAR_LATIN_SMALL_LETTER         0x0070

#define TAPI_TON_INTERNATIONAL_NUMBER_MASK 0x10

#define TAPI_TON_UNKNOWN_NUMBER_MASK       0x00

#define TAPI_NUMBER_PLAN_IDENTIFIER_MASK     0x01

#define TAPI_UTIL_GetAddressBcdLength( ascii_len ) ( ( ascii_len + 1 ) / 2 )

extern void 
TAPI_UTIL_UnpackTelNo(
                      const UINT8*    pGsmBcd,
                      const UINT8     addressValueFieldLen,
                      W_CHAR*         pUcs2Buffer,
                      const UINT8     ucs2Length 
                      );

extern void 
TAPI_UTIL_PackTelNo(
                    const W_CHAR*   pUcs2Buffer,
                    UINT8*          pGsmBcd,
                    const UINT8     addressValueLen 
                    );

extern BOOLEAN 
TAPI_UTIL_ExtractIntlChars( 
                           UINT8* pTelNo 
                           );

extern void    
TAPI_UTIL_ExtractTelNoChars(
                            W_CHAR*     pInputTelNo,
                            UINT8       inputTelNoLength,
                            W_CHAR*     pOutputTelNo,
                            UINT8       outputTelNoLength 
                            );

#ifdef __cplusplus
}
#endif 

#endif  

