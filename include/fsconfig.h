
/* Copyright (C) 2005 Monotype Imaging Inc. All rights reserved. */

/* Monotype Imaging Confidential */
 
/* $Header:   I:/BULL/DisplayImaging/archives/iType/product/source/common/fsconfig.h_v   1.6   Nov 21 2005 12:08:58   galejss  $ */
/* $Log:   I:/BULL/DisplayImaging/archives/iType/product/source/common/fsconfig.h_v  $
 * Add chace for mapchar
 * 
 *    Rev 1.6   Nov 21 2005 12:08:58   galejss
 * add PFR disclaimer
 * 
 *    Rev 1.5   Nov 03 2005 17:55:00   galejss
 * add Confidential notice (ITP-180)
 * 
 *    Rev 1.4   Oct 11 2005 12:24:28   galejss
 * move NEW_AA to object.h (not intended for user modification);
 * get rid of FS_USE_AMT_DI_ROOT directive
 * 
 *    Rev 1.3   Sep 29 2005 17:18:04   galejss
 * remove obsolete (mandatory) NEW_SCALE option; 
 * #undef ACT3 and #undef SUBPIXEL by default
 * 
 *    Rev 1.2   Aug 18 2005 11:08:04   azimaf
 * Changed PRF to PFRR to avoid conflect with PFR struct
 * 
 *    Rev 1.1   Aug 11 2005 16:27:08   galejss
 * add option for PFR support
 * 
 *    Rev 1.0   Jul 29 2005 15:17:58   galejss
 * Initial revision.
 *
 */

#ifndef __CONFIG__
#define __CONFIG__

/****************************************************************/
/**** please set the following options for your installation ****/
/****************************************************************/

/* to get a multi-process safe version, define the following -- requires REENTRANT and INT_MEM */
#define MULTI_PROCESS

/* to get a multi-thread safe version, define the following -- requires REENTRANT */
#define MULTI_THREAD

/* defined to get reentrant / multi-user code (no static read/write data) */
#define REENTRANT

/* define to use algorithmically compressed fonts */
#undef ACT3

/* define to use stroke fonts */
#undef STIK

/* define to use compressed (2nd-generation) stroke fonts */
#undef CCC

/* define to use 'phased' grayscale FS_get_phased() */
#undef PHASED

/* define to get lots of extra error checking, messages, etc. */
#undef FS_DEBUG

/* define to get extra MULTI_PROCESS-specific messages */
#undef FS_MP_DEBUG

/* define to use the dump_bitmap, dump_graymap, etc.. functions */
#undef FS_DUMP

/* define if using our local buffer [malloc/free] code */
/* leave undefined to use the operating systems [malloc/free] */
#define INT_MEM

/* maximum size (in bytes) of any single cache data entry */
/* eg: an NxM graymap is approximately 30 + (N*M)/2 bytes */
/* so a 50x50 graymap is about 1280 bytes */
/* eg: an NxM bitmap is approximately 30 + (N*M)/8 bytes */
/* so a 100x100 bitmap is about 1280 bytes */
#define CACHE_MAX_SIZE 1280

/* define to get statistics from the cache */
#undef STATS

/* Define for pseudo bold bitmaps and graymaps */
#define PSEUDO_BOLD

/* Define to enable contour winding checking related to pseudo bold */
/* Pseudo bold won't work if the contours are wound with ink-on-the-left */
/* vs. ink-on-the-right. */
#undef CONTOUR_WINDING_DETECTION

/* to enable subpixel rendering, define SUBPIXEL as one of the following: */
/* SUBPIXEL_BITMAPS, SUBPIXEL_GRAYMAPS_1 or SUBPIXEL_GRAYMAPS_2 */
/* If SUBPIXEL is undefined, you won't support subpixel rendering */
#define SUBPIXEL_BITMAPS 1	/* bitmaps, filter on the fly : smaller but slower */
#define SUBPIXEL_GRAYMAPS_1 2	/* pre-filtered bitmaps : larger but faster */
#define SUBPIXEL_GRAYMAPS_2 3	/* filtered graymaps : largest, slowest, best looking */

/*#define SUBPIXEL SUBPIXEL_BITMAPS*/
/*#define SUBPIXEL SUBPIXEL_GRAYMAPS_1*/
/*#define SUBPIXEL SUBPIXEL_GRAYMAPS_2*/
#undef SUBPIXEL 

/* define to cache each of OUTLINES, BITMAPS, or GRAYMAPS */
#undef CACHE_OUTLINES
#undef CACHE_BITMAPS
#undef CACHE_GRAYMAPS
#undef CACHE_PHASED
/* define to cache unicode to glyph index cmap values */
#define CACHE_CMAP

/* define for embedded bitmap support (EBLC, EBDT data tables) */
#undef EMBEDDED_BITMAP

/********************* IMPORTANT: Please Note:	********************** 
 iType can be used to render outline fonts encoded in PFR format, provided
 that such rendering is to be used to achieve compliance with digital TV 
 standards developed by DAVIC (ISO/IEC 16500), DVB and/or Digital TV Group.
********************* IMPORTANT: Please Note:	**********************/ 
/* define for PFR support */
#undef PFRR

/* define if your system needs to be prevented from LF-CR translation -- like MSDOS */
#define BINARY

/****************************************************************/
/****** Compiler support for necessary exportation of iType *****/
/****** API from dynamically loaded library, and importation ****/
/****** of API into an application using the DLL, if desired. ***/
/****************************************************************/

/* To build iType as a WIN32 DLL, define the following: */
/* #define FS_EXPORT_DLL comment this out for compile-time optioning */

/* To build a WIN32 application which uses the iType DLL, define this: */
/* #define FS_IMPORT_DLL comment this out for compile-time optioning */

#endif /* __CONFIG__ */

