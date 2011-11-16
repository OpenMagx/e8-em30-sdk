

// Copyright (c) 04-Mar-04 - 2008 Motorola, Inc. All rights reserved.



#ifndef SU_BASICTYPES_H
#define SU_BASICTYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif

typedef signed char INT8;
typedef unsigned char UINT8;
typedef short int INT16;
typedef unsigned short int UINT16;
typedef int INT32;
typedef unsigned int UINT32;

#ifdef _WIN32

typedef __int64 INT64;
typedef unsigned __int64 UINT64;

typedef int BOOL; 

#ifndef BOOLEAN
typedef unsigned char BOOLEAN;
#endif

#else

typedef long long int INT64;
typedef unsigned long long int UINT64;
#ifndef EZX_TYPEDEFINE_H
typedef unsigned char BOOL;
#endif
#ifndef BOOLEAN
typedef unsigned char BOOLEAN;
#endif

#endif 

#ifdef __cplusplus
}
#endif
#endif

