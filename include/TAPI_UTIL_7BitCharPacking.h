

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_UTIL_7BIT_CHAR_PACKING_H
#define TAPI_UTIL_7BIT_CHAR_PACKING_H

#ifdef __cplusplus
extern "C"
{
#endif

UINT8           TAPI_UTIL_Pack7BbitChar(
                    UINT8*  pUnpackedString,
                    UINT8*  pPackedString,
                    UINT8   charNumber,
                    BOOLEAN isGsm );

extern UINT8    TAPI_UTIL_Pack7BitCharFromOffset(
                    const UINT8*    unpackedBuffer,
                    UINT8*          packedBuffer,
                    UINT8           charNumber,
                    BOOLEAN         isGsm,
                    UINT8           fillBits );

UINT16          TAPI_UTIL_Unpack7BitString(
                    const UINT8*    pPackedString,
                    UINT8*          pUnpackedString,
                    UINT16          charNumber );

void            TAPI_UTIL_Unpack7BitShortMsg(
                    UINT8*  pPackedString,
                    UINT8*  pUnpackedString,
                    UINT8   charNumber,
                    UINT8   skipChar );

extern void     TAPI_UTIL_Unpack7BitStringFromOffset(
                    const UINT8*    packedBuffer,
                    UINT8*          unpackedBuffer,
                    UINT8           charNumber,
                    UINT8           fillBits );

UINT16 TAPI_UTIL_Unpack7BitStringToAsciiString(
        const UINT8*    pPackedString,
        UINT8*          pUnpackedString,
        UINT16          charNumber );

#ifdef __cplusplus
}

#endif
#endif  

