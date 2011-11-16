/*****************************************************************************
 *
 *  tsport.h  - Port-specific definitions           
 *
 *  Copyright (C) 2002 Monotype Imaging Inc. All rights reserved.
 *
 *  $Archive:   I:/BULL/DisplayImaging/archives/wtle/product/source/port/linux/tsport.h_v  $ 
 *  $Date:   Aug 02 2005 11:20:18  $
 *  $Revision:   1.2  $
 *
 ****************************************************************************/

#ifndef TSPORT_H
#define TSPORT_H

/*****************************************************************************
 *
 *  Include the system header files that are needed by the base library.
 * 
 *  There are environments where the contents of these files are put in
 *  other files.  If necessary, MODIFY the include statements so that the
 *  appropriate files are included.
 *
 ****************************************************************************/

#include <stdarg.h>     /* Variable argument macro definitions */
#include <stddef.h>     /* Common Definitions and Types: NULL, size_t, etc. */
#include <stdlib.h>     /* General Utilities: memory management */
#include <malloc.h>     /* Memory management */
#include <stdio.h>      /* Input/output: FILE, fopen() ... fclose() */
#include <string.h>     /* String handling and memcpy(), memset() */
#include <limits.h>     /* Sizes of integer types */
#include <assert.h>     /* Diagnostics: assert macro */


/*****************************************************************************
 *
 *  Macros for system calls. Most implementors will not need to modify these.
 *  Modify these macros only if the target platform has defined 
 *  other methods for these standard operations
 */
#define TS_MEMCPY(a,b,c)    memcpy(a,b,c)
#define TS_MEMSET(a,b,c)    memset(a,b,c)
#define TS_STRCPY(a,b)      strcpy(a,b)
#define TS_STRNCPY(a,b,c)   strncpy(a,b,c)
#define TS_STRLEN(a)        strlen(a)
#define TS_STRCMP(a,b)      strcmp(a,b)
#define TS_STRCAT(a,b)      strcat(a,b)
#define TS_MALLOC(a)        malloc(a)
#define TS_FREE(a)          free(a)
#define TS_CALLOC(a,b)      calloc(a,b)
#define TS_REALLOC(a,b)     realloc(a,b)


/*****************************************************************************
 *
 *  Here we define a set of types in terms of the C-language basic types.
 *  These new types are not used directly, instead, they are intermediate forms
 *  used by the API code to define the actual basic types used throughout the
 *  API and code.  The intermediate forms are defined in order
 *  to insulate the API from the portability code.
 *
 *  MODIFY these types as necessary to match the system's basic types.
 *
 ****************************************************************************/

typedef signed char     TsInt8_t;   /*   signed  8-bit integer */
typedef signed short    TsInt16_t;  /*   signed 16-bit integer */
typedef signed long     TsInt32_t;  /*   signed 32-bit integer */
typedef unsigned char   TsUInt8_t;  /* unsigned  8-bit integer */
typedef unsigned short  TsUInt16_t; /* unsigned 16-bit integer */
typedef unsigned long   TsUInt32_t; /* unsigned 32-bit integer */

typedef ptrdiff_t       TsPtrDiff_t;/* to be used for pointer math */
typedef size_t          TsSize_t;   /* used with sizeof operator */
typedef wchar_t         TsWChar_t;  /* wide character type */


/*****************************************************************************
 *
 *  Here we define macros to decorate functions, and headers.
 *
 *  MODIFY these as necessary for your platform.
 *
 ****************************************************************************/


#ifdef TS_EXPORT_DLL
#define TS_DECLSPEC /* __declspec(dllexport) */
#elif defined (TS_IMPORT_DLL)
#define TS_DECLSPEC /* __declspec(dllimport) */
#else
#define TS_DECLSPEC 
#endif

#ifdef __cplusplus

#define TS_BEGIN_HEADER extern "C" {
#define TS_END_HEADER   }  
#define TS_CDECL        extern "C"
#define TS_EXPORT(x)  TS_CDECL TS_DECLSPEC x      

#else

#define TS_BEGIN_HEADER
#define TS_END_HEADER  
#define TS_CDECL        
#define TS_EXPORT(x)  TS_DECLSPEC x

#endif


/*****************************************************************************
 *
 *  Macro that wraps the "inline" keyword.
 *
 *  Uncomment "inline" if supported and desired.
 *
 *  <GROUP port>
 */  
#define TS_INLINE   /* inline */


/*****************************************************************************
 *
 *  Macro that defines whether writable static data is allowed.  
 *
 *  Description:
 *      Some embedded environments that build code for ROM use and that
 *      do not have an associated data segment.  This means that no variable 
 *      declarations can occur outside of functions.
 *
 *      Undefine this macro if writable static data is NOT allowed.
 *
 *  Note:
 *      constant static values are allowed, even if writable statics are not.
 *
 *  <GROUP port>
 */
#define TS_WRITABLE_STATICS_ALLOWED


/*****************************************************************************
 *
 *  Macros that define the particular byte order options supported.
 *  Don't change these.
 *  
 ****************************************************************************/

#define TS_BIG_ENDIAN      0                   /* Motorola 680X0, etc */
#define TS_LITTLE_ENDIAN   1                   /* Intel 80X86, etc    */


/*****************************************************************************
 *
 *  Macro that define the byte order for this build.  Should be defined
 *  as one of the byte order options defined above.  
 *
 *  MODIFY this macro to match the endianess of your platform.
 *
 *  <GROUP port>
 */
#define TS_BYTE_ORDER TS_LITTLE_ENDIAN



#endif /* TSPORT_H */

