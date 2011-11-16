

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_UTIL_BCD_TO_ASCII_H 
#define TAPI_UTIL_BCD_TO_ASCII_H 

#ifdef __cplusplus 
extern "C" {
#endif

extern char*   
TAPI_UTIL_ConvertGsmBcdStringToAsciiString(
                                           const void*     bcd_number_ptr,
                                           INT16           digitNumber,
                                           void*           pMemSpace,
                                           BOOLEAN         isIntegerRestrict 
                                           );

#ifdef __cplusplus
}
#endif 

#endif  

