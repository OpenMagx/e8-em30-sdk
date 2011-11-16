

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef TAPI_UTIL_STRING_H  
#define TAPI_UTIL_STRING_H  

#ifdef __cplusplus 
extern "C" {
#endif

extern UINT32     
TAPI_UCS2_strlen( 
                 const W_CHAR* s 
                 );

extern W_CHAR*     
TAPI_UCS2_strcpy(
                 W_CHAR*         dest,
                 const W_CHAR*   source 
                 );

extern W_CHAR*     
TAPI_UCS2_strncpy(
                  W_CHAR*         dest,
                  const W_CHAR*   source,
                  UINT32          num 
                  );

extern W_CHAR*     
TAPI_UCS2_strcat(
                 W_CHAR*         dest,
                 const W_CHAR*   source 
                 );

extern W_CHAR*     
TAPI_UCS2_strchr(
                 const W_CHAR*   s,
                 W_CHAR          c 
                 );

extern INT32       
TAPI_UCS2_strcmp(
                 const W_CHAR*   s1,
                 const W_CHAR*   s2 
                 );

extern INT32       
TAPI_UCS2_strncmp(
                  const W_CHAR*   s1,
                  const W_CHAR*   s2,
                  UINT32          num 
                  );

extern W_CHAR      
TAPI_UCS2_GetChar( 
                  const W_CHAR* s 
                  );

extern void        
TAPI_UTIL_PutChar(
                  W_CHAR*     dest,
                  W_CHAR      c 
                  );

extern INT32       
TAPI_UCS2_atol( 
               const W_CHAR* string 
               );

extern BOOLEAN     
TAPI_UCS2_IsDigit( W_CHAR character );

extern BOOLEAN     
TAPI_UCS2_IsSpace( 
                  W_CHAR character 
                  );

extern void        
TAPI_UTIL_InverseString( 
                        W_CHAR* string 
                        );

#ifdef __cplusplus
}
#endif 

#endif  

