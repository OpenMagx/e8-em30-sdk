
/* Copyright (C) 2005 Monotype Imaging Inc. All rights reserved. */

/* Monotype Imaging Confidential */

/* $Header:   I:/BULL/DisplayImaging/archives/iType/product/source/port/linux/fs_port.h_v   1.4   Nov 03 2005 18:05:28   galejss  $ */

/*
* this file contains almost all the things you should need
* to change to get the AMT font scaler up and running on
* your machine; plus all the optional settings. Please
* make sure that all the entries in here make sense for
* your machine, compiler and environment.
*
* We assume ANSI standard include files. If your system
* is not compliant you may need to make additional changes.
*/

#ifndef __PORT__
#define __PORT__

/***************************************/
/*** start with system include files ***/
/***************************************/

#include <stdio.h>		/* FILE, fopen() ... fclose() */
#include <stdlib.h>		/* malloc(), free(), realloc() */
#include <string.h>		/* memcpy(), memset(), and strcmp() */
#include <errno.h>
#include <setjmp.h>
#include "fsconfig.h"

/****************************************************************/
/***** the basic data types -- make SURE these are correct ******/
/****************************************************************/

typedef signed char FS_TINY;            /* signed 8 bit integer      */
typedef unsigned char FS_BYTE;	        /* unsigned 8 bit integer    */

typedef short FS_SHORT;                 /* signed 16 bit integer     */
typedef unsigned short FS_USHORT;       /* unsigned 16 bit integer   */

typedef long FS_LONG;                   /* signed 32 bit integer     */
typedef unsigned long FS_ULONG;	        /* unsigned 32 bit integer   */

#define SIZEOF_LONG 4                   /* in bytes ... sizeof(long) */

/****************************************************************/
/**** please set the following options for your installation ****/
/****************************************************************/







/* define if you have provided assembly code for FIXMUL, FIXDIV, and MULDIV */
/* #define HAS_ASM */

/* eliminate setjmp/longjmp which has caused trouble on Symbian devices */
#undef KILL_SETJMP_LONGJMP

/* please define FS_BYTE_ORDER as either FS_BIG_ENDIAN or FS_LITTLE_ENDIAN */
#define FS_BIG_ENDIAN            0	               /* Motorola 680X0, etc */
#define FS_LITTLE_ENDIAN         1	               /* Intel 80X86, etc    */

#define FS_BYTE_ORDER      FS_LITTLE_ENDIAN

/* if you don't support 'const', comment out the lowercase 'const' */
#define CONST const		
	
/* if you don't support 'inline', comment out the lowercase 'inline' */
#define INLINE inline

/* VOID_ARGS is for functions that have no arguments eg: int foo(VOID_ARGS) */
/* if you don't support 'void', define as nothing, ie: "#define VOID_ARGS" */
#define VOID_ARGS void		

/* FS_VOID is for functions without return values, eg: "FS_VOID foo(int)" and */
/* for functions which return generic pointers, eg: "FS_VOID *foo(int)" and */
/* functions which take a generic pointer as argument, eg: foo(FS_VOID *) */
/* if you don't support 'void', define as SOME type, ie: "#define FS_VOID int" */
#define FS_VOID void


/****************************************************************/
/*********** compiler support for size of a heap item ***********/
/****************************************************************/

/* if using operating system malloc/free ... say how you get the size */
/* of a heap item. if you can't ... leave FREE_SIZE_DEFINED undefined */
#undef FREE_SIZE_DEFINED
/* #define FREE_SIZE(p)  */

/****************************************************************/
/****** processor/compiler support for 64 bit integers **********/
/****************************************************************/

/* if your compiler has a way to support 64 bit integers on 32
* bit platforms add the definition here; using the same format
* as the entries below. */

#define HAS_FS_INT64
typedef long long FS_INT64;

/*****************************************************************************
 *
 *  Build configuration option that specifies a directory that contains fonts.
 *  This is a convenience for samples and test programs.  It is not used
 *  directly by the rasterizer or layout engines.
 *
 */

#ifndef FS_FONTS_DIR
#define FS_FONTS_RELDIR "../iType/product/fontdata/"
#define FS_FONTS_DIR FsUtil_formDir(fsFontsDir, FS_FONTS_RELDIR)
#endif

/*****************************************************************************
 *
 *  Build configuration option that specifies a shared memory segment name.
 *  (Used by multi-processing code)
 *
 */
//#define FS_SHM_OPEN_NAME	"iTypeSharedHeap"
//HZD: ftok depends on a real file
#define FS_SHM_OPEN_NAME	"/tmp/lj-ui-framework-keyfile"


/*****************************************************************************/
/* Macros for system calls - most implementors will not need to modify these */
/*****************************************************************************/

#define SYS_MEMCPY(a,b,c) memcpy(a,b,c)
#define SYS_MEMSET(a,b,c) memset(a,b,c)
#define SYS_STRCPY(a,b) strcpy(a,b)
#define SYS_STRNCPY(a,b,c) strncpy(a,b,c)
#define SYS_STRLEN(a) strlen(a)
#define SYS_STRCMP(a,b) strcmp(a,b)
#define SYS_STRCAT(a,b) strcat(a,b)
#define SYS_MALLOC(a) malloc(a)
#define SYS_FREE(a) free(a)


/******************************************************************/
/* Are global static function pointers legal in your environment? */
/******************************************************************/

#define GLOBAL_STATIC_FUNCTION_PTRS_OK

#endif /* __PORT__ */
