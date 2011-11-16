

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_UTIL_ASCII_TO_BCD_H
#define TAPI_UTIL_ASCII_TO_BCD_H

#ifdef __cplusplus
extern "C"
{
#endif

UINT8*  TAPI_UTIL_AsciiStringToGsmBcdString(
            const char*     pAsciiStr,
            const INT16     bcdNumber,
            UINT8 *const    pBcdSpace );

#ifdef __cplusplus
}

#endif
#endif  

