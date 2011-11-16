
/* Copyright (C) 2005 Monotype Imaging Inc. All rights reserved. */

/* Monotype Imaging Confidential */

/*  Encoding:   US_ASCII    Tab Size:   8   Indentation:    4		*/

/* Copyright: 1987-1990 by Apple Computer, Inc., all rights reserved. */

/* $Header:   I:/BULL/raptor/raptor/object.h_v   1.95.1.0   Feb 23 2006 11:12:14   ComeauB  $ */
/* $Log:   I:/BULL/raptor/raptor/object.h_v  $
 * Add chace for mapchar
 * 
 *    Rev 1.95.1.0   Feb 23 2006 11:12:14   ComeauB
 * Motorola change to the SWAPL and SWAPW macros
 * 
 *    Rev 1.95   Jan 13 2006 15:56:06   dugganj
 * Fixed multi-processing "memptr" bug.
 * 
 *    Rev 1.94   Nov 29 2005 16:56:46   galejss
 * updates to Docomatic comments; undefine MTI_QE_TEST for shipping config
 * 
 *    Rev 1.93   Nov 21 2005 14:02:08   galejss
 * changes for 2.4 documentation
 * 
 *    Rev 1.92   Nov 21 2005 07:51:58   dugganj
 * Added a comment at the end of the FS_STATE structure.
 * 
 *    Rev 1.91   Nov 15 2005 11:46:20   galejss
 * include sfnt.h unconditionally; don't include errcodes.h (obsolete)
 * 
 *    Rev 1.90   Nov 14 2005 11:55:28   wuq
 * Fix of ITP-201.
 * 
 *    Rev 1.89   Nov 03 2005 17:55:04   galejss
 * add Confidential notice (ITP-180)
 * 
 *    Rev 1.88   Oct 11 2005 12:26:08   galejss
 * move NEW_AA to object.h (not intended for user modification); add MTI_QE_TEST directive (to use non-standard font directories)
 * 
 *    Rev 1.87   Sep 30 2005 13:09:08   dugganj
 * Added new kern structures and a new kern field in structure LFNT.
 * 
 *    Rev 1.86   Sep 26 2005 15:02:14   galejss
 * add FM_FLAGS_PFR (part of fix for ITP-128)
 * 
 *    Rev 1.85   Sep 01 2005 15:38:34   dugganj
 * Added "size" field to FS_ICON structure.
 * 
 *    Rev 1.84   Aug 16 2005 15:39:12   galejss
 * fix comment
 * 
 *    Rev 1.83   Aug 16 2005 15:37:24   galejss
 * for PFR support: added TTF.fnt_type, LFNT.fnt_type, FS_OUTLINE.polarity, 
 * FONT_METRICS.metrics_resolution; renamed LFNT.ttf to LFNT.fnt
 * 
 *    Rev 1.82   Jul 29 2005 14:55:46   galejss
 * port.h becomes fs_port.h
 * 
 *    Rev 1.81   Jul 11 2005 17:24:00   galejss
 * centralize debug flags CHECK_HEAP, GRID_DEBUG, DEBUG_DIRECT, 
 * SBIT_DEBUG, and ALDUMP
 * 
 *    Rev 1.80   Jul 08 2005 16:28:08   galejss
 * fix non-REENTRANT build; remove obsolete USE_MY_FONTS code;
 * remove redundant includes; match 2.3 default values
 * 
 *    Rev 1.79   Jun 29 2005 16:16:38   dugganj
 * Corrected macro definitions "MP...()" to resolve Alpha bug.
 * 
 *    Rev 1.78   Jun 29 2005 15:54:22   galejss
 * remove currently-unused NEW_SPACING define
 * 
 *    Rev 1.77   Jun 27 2005 15:59:18   galejss
 * add Docomatic comments to public structure definitions
 * 
 *    Rev 1.76   Jun 15 2005 13:12:58   dugganj
 * Multi-processing related changes.
 * 
 *    Rev 1.75   May 18 2005 10:56:14   WuQ
 * Added field count_added to LFNT.
 * 
 *    Rev 1.74   May 17 2005 20:17:28   galejss
 * add FLAGS_OUTLINED_1PIXEL and FLAGS_OUTLINED_2PIXEL
 * 
 *    Rev 1.73   May 16 2005 11:52:28   galejss
 * MY_FONT changes; add width & height to FS_ICON; remove apparently-unused g_index extern
 * 
 *    Rev 1.72   May 12 2005 10:35:30   wuq
 * Added vdmx_offset field in TTF;
 * 
 *    Rev 1.71   May 05 2005 16:32:38   azimaf
 * Added compatibility with 2.4 alpha
 * 
 *    Rev 1.70   May 02 2005 16:19:10   azimaf
 * Revert back to 2.3 auto hinting
 * 
 *    Rev 1.69   Apr 11 2005 15:40:42   wuq
 * Change the comment of ref_count of LFNT.
 * 
 *    Rev 1.68   Mar 28 2005 10:42:30   wuq
 * Changes (by swp).
 * 
 *    Rev 1.67   May 26 2004 14:14:34   lynchr
 * FLAGS_ICON_MAP_ON is now the default state.
 * 
 *    Rev 1.66   May 21 2004 14:58:06   lynchr
 * Corrected typo in #define CACHE_ICON.
 * 
 *    Rev 1.65   Apr 29 2004 15:02:56   GalejsS
 * change type of FS_STATE.{platform, encoding} to FS_USHORT (fix bug # 123)
 * 
 *    Rev 1.64   Apr 27 2004 11:59:28   GalejsS
 * put MINOR_VERSION back to 300 (fix bug # 113)
 * 
 *    Rev 1.63   Apr 05 2004 14:52:36   lynchr
 * Changed flags for icons from FLAGS_ICON_INDEX_ON/OFF to FLAGS_ICON_MAP_ON/OFF.
 * 
 * Default is FLAGS_ICON_MAP_ON, this will access icons by number and X&Yppm.
 * 
 *    Rev 1.62   Apr 01 2004 10:57:54   lynchr
 * Added changes in support of icon testing.
 * 
 *    Rev 1.61   Mar 29 2004 13:03:48   dugganj
 * Removed unused field "bold_pct" from FS_SERVER structure.
 * 
 *    Rev 1.60   Mar 22 2004 13:45:00   dugganj
 * MUTEX is no longer being defined as port-specific here.
 * 
 *    Rev 1.59   Mar 19 2004 14:47:50   dugganj
 * Multithreading changes.
 * 
 *    Rev 1.58   Feb 11 2004 18:58:50   Galejs
 * add "FS_BOOLEAN" field to FS_BITMAP and FS_GRAYMAP
 * 
 *    Rev 1.57   Feb 03 2004 16:53:42   Galejs
 * move NC_DEBUG define here (as we don't recommend that customers modify this setting)
 * 
 *    Rev 1.56   Jan 26 2004 18:25:50   Galejs
 * move DEBUG_TABLE_PTR define here (since it's used by two source files)
 * 
 *    Rev 1.55   Jan 26 2004 12:12:58   Galejs
 * revert to FILECHAR data type (to match published coding standards); 
 * maintain FS_CHAR synonym for FS_TINY (so that customers will not need to change implementations)
 * 
 *    Rev 1.54   Jan 13 2004 14:07:00   WuQ
 * Changes to CCC_INFO struct for VMTX and HMTX table decompression.
 * Changes related to CCC version number.
 * 
 *    Rev 1.53   Dec 16 2003 11:57:24   Paul
 * moved a typedef and some defines from
 * port.h to object.h -- out of harms way.
 * 
 *    Rev 1.52   Dec 16 2003 09:09:40   Paul
 * removed unused RGBMAP, revert to 'char' data type
 * 
 *    Rev 1.51   Dec 09 2003 09:58:58   Paul
 * removed misleading comments
 * 
 *    Rev 1.50   Dec 04 2003 16:04:44   Galejs
 * add support for FS_ICON format, some new FS_TRACE info
 * 
 *    Rev 1.49   Nov 26 2003 17:52:02   Galejs
 * changes for 2.3: multithreading changes; vertical-writing support (vhea, vmtx, FLAGS_VERTICAL_ON);
 * add MFNT and FS_RGBMAP structs; change TTF_CMAP and TTF_OS2 structs
 * 
 *    Rev 1.48   Aug 29 2003 16:49:04   platze
 * Offer os2 win ascent and descent (usWinAscent)
 * 
 *    Rev 1.47   May 15 2003 12:21:22   Galejs
 * update MAJOR_VERSION, MINOR_VERSION for release
 * 
 *    Rev 1.46   Apr 30 2003 18:07:36   Galejs
 * add new user-accessible flag for bad-wound contour detection (for al)
 * 
 *    Rev 1.45   Apr 24 2003 17:24:06   Galejs
 * centralize system include files (bug # 62)
 * 
 *    Rev 1.44   Apr 24 2003 12:41:50   WuQ
 * Fix for bug #77
 * 
 *    Rev 1.43   Apr 15 2003 10:15:20   careyj
 * MARM_ARMI -- Symbian doesn't have malloc.h
 * 
 *    Rev 1.42   Apr 11 2003 13:10:54   WuQ
 * Added stik_char field to FS_STATE
 * 
 *    Rev 1.41   Apr 03 2003 11:06:22   careyj
 * add include of malloc.h under WIN32 for _msize AND adorn exportable data types for DLL creation AND add proper macros to allow for creation of DLLs and usage under WIN32
 * 
 *    Rev 1.39.1.2   Apr 03 2003 09:23:04   careyj
 * move definition of ITYPE_API from port.h to here
 * 
 *    Rev 1.39.1.1   Apr 02 2003 14:21:50   careyj
 * merge Sandra's rev 1.40 into branch
 * 
 *    Rev 1.39.1.0   Mar 31 2003 17:31:00   CareyJ
 * adornment of API data for DLL and add include of malloc.h to repair the declaration and linkage conflict with _msize with _WIN32 under VisualStudio.NET
 * 
 *    Rev 1.39   Mar 25 2003 13:40:10   WuQ
 * GET_xWORD, GET_xLONG are moved to the file from ttf.c
 * 
 *    Rev 1.38   Mar 13 2003 14:30:20   Galejs
 * FS_BOOLEAN
 * 
 *    Rev 1.37   Mar 11 2003 11:49:56   Paul
 *  
 *    Rev 1.36   Mar 11 2003 09:35:36   Paul
 * changes for table pointers by reference
 * 
 *    Rev 1.35   Mar 06 2003 12:06:10   WuQ
 * Bug fix for #60, code related to new feature #34
 * 
 *    Rev 1.34   Feb 20 2003 14:27:10   Azima
 * flag USE_MY_FONTS  was defined
 * 
 *    Rev 1.33   Feb 14 2003 14:11:34   Azima
 * defined flag FLAGS_FIX_DROPOUTS to fix
 * the problem with dropouts
 * 
 *    Rev 1.32   Feb 14 2003 12:49:48   Azima
 * version is added to STATE struct, MAJOR_VERSION
 * and MINOR_VERSION are defined
 * 
 *    Rev 1.31   Feb 04 2003 07:37:08   Paul
 * added FLAGS_DROPOUTS_ON to #define FLAGS_USER
 *    Rev 1.30   Jan 22 2003 17:10:56   Paul
 * move FS_get_phased() to <api.c> and hook it into the cache
 * 
 *    Rev 1.29   Dec 13 2002 10:58:06   WuQ
 * Changes related to subpixel rendering, cache management and STATS (by swp)
 * 
 *    Rev 1.28   Oct 01 2002 12:20:18   Paul
 * repair of OS/2 table read and rotation invarient STATE.lpm code
 * 
 *    Rev 1.27   Sep 11 2002 16:21:50   Paul
 * added platform and encoding to LFNT 
 * 
 *    Rev 1.26   Jul 25 2002 11:19:36   WuQ
 * Changes for processing new CCC and its act3 compressed file
 * 
 *    Rev 1.25   Jul 12 2002 14:09:18   Joe
 * Replaced FS_free() reference with FS_free_char() (by swp).
 * 
 *    Rev 1.24   Jul 12 2002 11:34:04   WuQ
 * CCC information structure added to TTF
 * 
 *    Rev 1.23   Jun 28 2002 09:56:30   Joe
 * Cleanup (by swp)
 * 
 *    Rev 1.22   Jun 10 2002 14:11:50   Joe
 * Added tags for advanced Opentype tables.
 * 
 *    Rev 1.21   May 29 2002 13:21:52   WuQ
 * Changes for CCC, loca, cmap, memory management and query functions for jfd, softness effect for rjl
 * 
 *    Rev 1.19   Oct 22 2001 17:59:02   Paul
 * unconditional #includes of stdio.h, stdlib.h and string.h
 * removal of extern vars for __swapw and __swapl
 * simplified macros for SWAPW and SWAPL
 * _DS0_ now #defined as VOID_ARGS
 * 
 *    Rev 1.18   Oct 17 2001 14:57:24   Paul
 * ALIGN macro renamed FS_ALIGN,
 * removed FS_state_ptr declaration and HI_WORD and LO_WORD macros,
 * the REENTRANT C++ declarations of FS_state and my_fonts needed another 'extern',
 * 
 *    Rev 1.16   Sep 18 2001 16:35:00   Paul
 * rewrote 'sfnt_ReadSFNTMetrics' 
 * 
 *    Rev 1.15   Sep 14 2001 10:09:38   Paul
 * cosmetics, removal of '//' comments, etc..
 * 
 *    Rev 1.14   Sep 11 2001 10:01:12   Paul
 * missing REENTRANT args
 * 
 *    Rev 1.13   Sep 06 2001 15:19:34   Paul
 * changes for ACT3
 * 
 *    Rev 1.12   Aug 27 2001 14:17:12   Paul
 *  
 *    Rev 1.11   Aug 07 2001 09:09:48   Al
 * Added PSEUDO_BOLD
 * 
 *    Rev 1.10   Jul 10 2001 12:57:10   Paul
 * changes for STIK fonts
 * 
 *    Rev 1.9   Jun 13 2001 11:57:22   Paul
 * Reentrancy changes for INT_MEM
 * 
 *    Rev 1.8   May 08 2001 13:18:48   Paul
 * added Emboss, Engrave, Outline
 * 
 *    Rev 1.7   Feb 22 2001 14:40:10   Joe
 * Defined new parameter values (by swp)
 * 
 *    Rev 1.6   Jan 29 2001 17:04:06   Galejs
 * declare "path" as char* in TTF, LFNT, MY_FONT
 * 
 *    Rev 1.5   Sep 26 2000 10:56:48   galejs
 * add PVCS Header/Log strings
 *
 */

#ifndef __OBJECTS__
#define __OBJECTS__

#include "fs_port.h"
#include "bitio.h"
#include "sfnt.h"


/****************************************************************/
/* things users probably don't ever need to ever touch */
/****************************************************************/
/* to allow direct drawing (versus filling) of small stik characters */
#undef FS_DIRECT

/* define to use interim AA-like autohinting code */
/* leave undefined to get iType 2.3 bitmap compatibility */
#undef NEW_AA

/* define to access QE test data in non-shipping directory */
/* undefine in shipping product */
#undef MTI_QE_TEST

/***************************/
/* various debugging flags */
/***************************/

/* define to get LOTS of information from each TrueType instruction */
#undef FS_TRACE

/* define to get LOTS of information in tableptr.c and xmalloc.c */
#undef DEBUG_TABLE_PTR

/* define to get LOTS of information in fsglue.c */ 
#undef NC_DEBUG

/* define to get LOTS of information about autohinting */
#undef GRID_DEBUG

/* define for direct draw debugging in stik.c */
#undef DEBUG_DIRECT

/* define for embedded-bitmap debugging in sbit.c */
#undef SBIT_DEBUG

/* set to 1 for pseudo-bold debugging in outline.c */
#define ALDUMP 0

/* define to perform debugging of INT_MEM heap in xmalloc.c */
/* do NOT enable in production code - will slow down the code severely */
#undef CHECK_HEAP		

/****************************************************************/
/* things users don't ever need to ever touch */
/****************************************************************/
typedef FS_LONG FS_FIXED;			/* as 16.16 */
typedef FS_LONG FRACT;				/* as 2.30 */
typedef FS_LONG F26DOT6;			/* as 26.6 */
typedef FS_SHORT SHORTFRACT;		/* as 2.14 */

#ifdef FS_TRACE
#define FS_DEBUG 
extern int in_char;
extern int indent_is;
#endif /* FS_TRACE */

#ifdef FS_DEBUG
extern FS_ULONG scale_types[4];
#endif

typedef FS_BYTE FS_BOOLEAN;
typedef FS_TINY FS_CHAR; 	/* provided for compatibility with pre-2.3 iType releases */
 
/* Use the FILECHAR datatype where you need to match the system-defined "char" type
(i.e. to pass to system I/O or string functions) - if you use this datatype
rather than an unadorned "char", the semantics are clearer. */
typedef char FILECHAR;


/* 2.14 UNIT VECTOR */
typedef struct {
	SHORTFRACT x,y;
	} SHORT_UNIT_VECTOR;

/* 2.30 UNIT VECTOR */
typedef struct {
	FRACT x,y;
	} UNIT_VECTOR;

typedef struct {
	F26DOT6 x,y;
	} F26DOT6_VECTOR;

typedef struct {
	FS_FIXED x,y;
	} FIXED_VECTOR;

typedef struct {
	FS_FIXED        transform[3][3];
	} transMatrix;

/* some useful macros -- watch out for side effects */
#ifndef ABS
#define ABS(x)      (((x)>0)?(x):-(x))
#endif

#ifndef MAX
#define MAX(a,b)    (((a)>(b))?(a):(b))
#endif

#ifndef MIN
#define MIN(a,b)    (((a)<(b))?(a):(b))
#endif

/* byte swapping macros  */
#if FS_BYTE_ORDER == FS_LITTLE_ENDIAN
#if 0
#define NEED_TO_SWAP 1
#define SWAPW(x) swapw(x)
#define SWAPL(x) swapl(x)
#else
#define NEED_TO_SWAP 1
#define SWAPW(x) ( (((x) >> 8) & 0x00FF) | (((x) << 8) & 0xFF00) )
#define SWAPL(x) ( (((x) >> 24) & 0x000000FF) | (((x) >> 8) & 0x0000FF00) | (((x) << 8) & 0x00FF0000) | (((x) << 24) & 0xFF000000))
#endif

#else /* BYTEORDER==FS_BIG_ENDIAN */
#define NEED_TO_SWAP 0
#define SWAPW(x) (x)
#define SWAPL(x) (x)
#endif /* BYTEORDER */


#ifdef STIK
#define LATIN 1
#define CJK 2
#define GENERIC 3
#define OTHER 4

/* indices into the CVT for new STIK spacing algorithm */
#define NS_CAP_ROUND	0
#define NS_CAP_SQUARE	1
#define NS_X_SQUARE		2
#define NS_X_ROUND		3
#define NS_BASE_SQUARE	4
#define NS_BASE_ROUND	5
#define NS_O_LSB		6
#define NS_O_RSB		7
#endif
/* move <p> to the next possible location of a (FS_VOID *) */
#define FS_ALIGN(p) p += (sizeof(FS_VOID *) - 1); p &= ~(sizeof(FS_VOID *) - 1)




#define GET_xWORD(a)  \
           ( ((FS_USHORT) *(FS_BYTE *)(a) << 8) |      \
              (FS_USHORT) *((FS_BYTE *)(a)+1) )

#define GET_xLONG(a)  \
           ( ((FS_ULONG) *(FS_BYTE *)(a) << 24)     |  \
             ((FS_ULONG) *((FS_BYTE *)(a)+1) << 16) |  \
             ((FS_ULONG) *((FS_BYTE *)(a)+2) << 8)  |  \
              (FS_ULONG) *((FS_BYTE *)(a)+3) ) 



#ifdef INT_MEM
typedef struct mem {
#ifdef FS_DEBUG
	FS_LONG tag;
#endif /* FS_DEBUG */
	struct mem *next;
	FS_LONG units;
	} MEM;
#endif /* INT_MEM */

/* font types */
#define TTF_TYPE 0
#define PFR_TYPE 6


/* outline element types */
#define FS_MOVETO 0
#define FS_LINETO 1
#define FS_QUADTO 2
#define FS_CUBETO 3

#ifdef STATS
extern FS_ULONG made_outl;
extern FS_ULONG cached_outl;
extern FS_ULONG made_bmap;
extern FS_ULONG cached_bmap;
extern FS_ULONG made_gmap;
extern FS_ULONG embedded_bmap;
extern FS_ULONG cached_gmap;
extern FS_ULONG uncached_too_big;
extern FS_ULONG composite;
#endif

/********************* rasterization ****************************/
/* transition array node */
typedef struct {
	FS_FIXED value;		/* coordinate of this node in singley linked list */
	FS_LONG next;		/* index of next T_NODE in the singley linked list */
	} TNODE;

/* transition array */
typedef struct { 
	FS_SHORT max;		/* y coordinate of slot[0] */
	FS_SHORT num;		/* number of slots */
	FS_LONG stop_index;	/* 1+maximum index into <nodes> */
	FS_LONG next_index;	/* next available index into <nodes> */
	FS_LONG *indices;	/* starting index into <nodes> for each coordinate */
	TNODE *nodes;		/* the singly linked list of values */
	} TLIST;


/************* TrueType Fonts ***********************************/
#define STUBCONTROL 0x10000L
#define NODOCONTROL 0x20000L

/* unpacking constants */
#define ONCURVE  			0x01
#define XSHORT   			0x02
#define YSHORT   			0x04
#define REPEAT_FLAGS    	0x08
#define SHORT_X_IS_POS   	0x10  /* flags & XSHORT */
#define NEXT_X_IS_ZERO   	0x10
#define SHORT_Y_IS_POS   	0x20  /* flags & YSHORT */
#define NEXT_Y_IS_ZERO   	0x20


/* composite glyph constants */
#define ARG_1_AND_2_ARE_WORDS		0x0001	/* if set args are words otherwise they are bytes */
#define ARGS_ARE_XY_VALUES			0x0002	/* if set args are xy values, otherwise they are points */
#define ROUND_XY_TO_GRID			0x0004	/* for the xy values if above is true */
#define WE_HAVE_A_SCALE				0x0008	/* Sx = Sy, otherwise scale == 1.0 */
#define NON_OVERLAPPING				0x0010	/* set to same value for all components */
#define MORE_COMPONENTS				0x0020	/* indicates at least one more glyph after this one */
#define WE_HAVE_AN_X_AND_Y_SCALE	0x0040	/* Sx, Sy */
#define WE_HAVE_A_TWO_BY_TWO		0x0080	/* t00, t01, t10, t11 */
#define WE_HAVE_INSTRUCTIONS		0x0100	/* instructions follow */
#define USE_MY_METRICS				0x0200	/* apply these metrics to parent glyph */

#define TTF_MAGIC 0x5F0F3CF5L

/* table tags in Motorola Byte order */
#define MAKE_TAG(a,b,c,d)	(((FS_ULONG)a<<24)|((FS_ULONG)b<<16)|((FS_ULONG)c<<8)|d)

/* if your compiler is decent these will become simple 32 bit constants */
#define TAG_ttcf	MAKE_TAG('t','t','c','f')
#define TAG_head	MAKE_TAG('h','e','a','d')
#define TAG_hhea	MAKE_TAG('h','h','e','a')
#define TAG_hmtx	MAKE_TAG('h','m','t','x')
#define TAG_maxp	MAKE_TAG('m','a','x','p')
#define TAG_loca	MAKE_TAG('l','o','c','a')
#define TAG_glyf	MAKE_TAG('g','l','y','f')
#define TAG_cmap	MAKE_TAG('c','m','a','p')
#define TAG_cvt		MAKE_TAG('c','v','t',' ')
#define TAG_fpgm	MAKE_TAG('f','p','g','m')
#define TAG_prep	MAKE_TAG('p','r','e','p')
#define TAG_EBLC	MAKE_TAG('E','B','L','C')
#define TAG_EBDT	MAKE_TAG('E','B','D','T')
#define TAG_kern	MAKE_TAG('k','e','r','n')
#define TAG_act3	MAKE_TAG('a','c','t','3')	
#define TAG_nstk	MAKE_TAG('n','s','t','k')	
#define TAG_name	MAKE_TAG('n','a','m','e')
#define TAG_post	MAKE_TAG('p','o','s','t')
#define TAG_OS2		MAKE_TAG('O','S','/','2')
#define TAG_EBSC	MAKE_TAG('E','B','S','C')
#define TAG_gasp	MAKE_TAG('g','a','s','p')
#define TAG_hdmx	MAKE_TAG('h','d','m','x')
#define TAG_LTSH	MAKE_TAG('L','T','S','H')
#define TAG_PCLT	MAKE_TAG('P','C','L','T')
#define TAG_VDMX	MAKE_TAG('V','D','M','X')
#define TAG_vhea	MAKE_TAG('v','h','e','a')
#define TAG_vmtx	MAKE_TAG('v','m','t','x')
#define TAG_GSUB	MAKE_TAG('G','S','U','B')
#define TAG_GPOS	MAKE_TAG('G','P','O','S')
#define TAG_BASE	MAKE_TAG('B','A','S','E')
#define TAG_JSTF	MAKE_TAG('J','S','T','F')
#define TAG_GDEF	MAKE_TAG('G','D','E','F')
#define TAG_Icon	MAKE_TAG('I','c','o','n')

typedef struct {
	FS_ULONG		tag;			/* eg: 'cmap' */
	FS_ULONG		checkSum;		/* for table */
	FS_ULONG		offset;			/* offset from beginning of font */
	FS_ULONG		length;			/* length (bytes) */
	} TTF_DIR;

typedef struct {
	FS_FIXED		version;		/* 0x10000 (1.0) */
	FS_USHORT		numTables;		/* number of tables */
	FS_USHORT		searchRange;	/* (max2 <= numOffsets)*16 */
	FS_USHORT		entrySelector;	/* log2(max2 <= numOffsets) */
	FS_USHORT		rangeShift;		/* numOffsets*16-searchRange*/
	TTF_DIR			tables[1];		/* table[numOffsets] */
	} TTF_HEADER;

typedef struct {
	FS_ULONG		tag;			/* should be 'ttcf' */
	FS_FIXED		version;		/* 0x10000 (1.0) */
	FS_ULONG		numFonts;		/* number of fonts in TTC file */
	FS_ULONG		offsets[1]; 	/* offsets from beginning of file to table directories */
	} TTC_HEADER;

typedef struct {
	FS_FIXED	version;			/* for this table, set to 1.0 */
	FS_FIXED	fontRevision;		/* For Font Manufacturer */
	FS_ULONG	checkSumAdjustment;
	FS_ULONG	magicNumber; 		/* signature, should always be 0x5F0F3CF5  == MAGIC */
	FS_USHORT	flags;
	FS_USHORT	unitsPerEm;			/* Specifies how many in Font Units we have per EM */
	FS_ULONG	created[2];
	FS_ULONG	modified[2];
	FS_SHORT	xMin;				/* fontwide bbox */
	FS_SHORT	yMin;
	FS_SHORT	xMax;
	FS_SHORT	yMax;
	FS_USHORT	macStyle;			/* macintosh style word */
	FS_USHORT	lowestRecPPEM; 		/* lowest recommended pixels per Em */
	FS_SHORT	fontDirectionHint;	/* 0==mixed, 1==L-R or T-B, -1==R-L or B-T , 2==like 1 + neutrals, -2 like (-1) + neutrals */
	FS_SHORT	indexToLocFormat;	/* 0== short, 1==long */
	FS_SHORT	glyphDataFormat;	/* better be 0 */
	} TTF_HEAD;

typedef struct {
	FS_FIXED	version;				/* for this table, set to 1.0 */
	FS_SHORT	yAscender;
	FS_SHORT	yDescender;
	FS_SHORT	yLineGap;				/* Recommended linespacing = ascender - descender + linegap */
	FS_USHORT	advanceWidthMax;	
	FS_SHORT	minLeftSideBearing;
	FS_SHORT	minRightSideBearing;
	FS_SHORT	xMaxExtent;				/* Max of ( LSBi + (XMAXi - XMINi) ), i loops through all glyphs */
	FS_SHORT	horizontalCaretSlopeNumerator;
	FS_SHORT	horizontalCaretSlopeDenominator;
	FS_SHORT	caretOffset;
	FS_USHORT	reserved1;
	FS_USHORT	reserved2;
	FS_USHORT	reserved3;
	FS_USHORT	reserved4;
	FS_SHORT	metricDataFormat;			/* set to 0 for current format */
	FS_USHORT	numberOf_LongHorMetrics;	/* if format == 0 */
	} TTF_HHEA;

typedef struct {
	FS_FIXED	version;				/* for this table, set to 1.0 */
	FS_SHORT	yAscender;
	FS_SHORT	yDescender;
	FS_SHORT	yLineGap;			
	FS_USHORT	advanceHeightMax;	
	FS_SHORT	minTopSideBearing;
	FS_SHORT	minBottomSideBearing;
	FS_SHORT	yMaxExtent;				
	FS_SHORT	horizontalCaretSlopeNumerator;
	FS_SHORT	horizontalCaretSlopeDenominator;
	FS_SHORT	caretOffset;
	FS_USHORT	reserved1;
	FS_USHORT	reserved2;
	FS_USHORT	reserved3;
	FS_USHORT	reserved4;
	FS_SHORT	metricDataFormat;			/* set to 0 for current format */
	FS_USHORT	numberOf_LongVerMetrics;	/* if format == 0 */
	} TTF_VHEA;

typedef struct {
	FS_FIXED	version;				/* for this table, set to 1.0 */
	FS_USHORT	numGlyphs;				/* number of glyphs in the file ... loca is one larger */
	FS_USHORT	maxPoints;				/* in an individual glyph */
	FS_USHORT	maxContours;			/* in an individual glyph */
	FS_USHORT	maxCompositePoints;		/* in an composite glyph */
	FS_USHORT	maxCompositeContours;	/* in an composite glyph */
	FS_USHORT	maxElements;			/* set to 2, or 1 if no twilightzone points */
	FS_USHORT	maxTwilightPoints;		/* max points in element zero */
	FS_USHORT	maxStorage;				/* max number of storage locations */
	FS_USHORT	maxFunctionDefs;		/* max number of FDEFs in any preprogram */
	FS_USHORT	maxInstructionDefs;		/* max number of IDEFs in any preprogram */
	FS_USHORT	maxStackElements;		/* max number of stack elements for any individual glyph */
	FS_USHORT	maxSizeOfInstructions;	/* max size in bytes for any individual glyph */
	FS_USHORT	maxComponentElements;	/* number of glyphs referenced at top level */
	FS_USHORT	maxComponentDepth;		/* levels of recursion, 1 for simple components */
	} TTF_MAXP;


/*****************************************************************************
 *
 *  Structure that describes the cmap platform and encoding.
 *
 *  Description:
 *      The FONT_METRICS structure returned by FS_font_metrics() contains
 *      an array of these structures.
 *
 *      The platform ID specifies a particular platform which this cmap
 *      complies.  Each platform supports a list of encodings.  For
 *      example the Windows platform = 3.  On that platform the Unicode
 *      encoding is specified as 1.
 *
 *      For more information, see the TrueType specification.
 *
 *  See Also:
 *      FONT_METRICS 
 *
 *  <GROUP itypestructs>
 */
typedef struct 
{
	FS_USHORT	platform;       /* platform ID */
	FS_USHORT	encoding;	    /* encoding ID */
	FS_ULONG	offset;		    /* offset to data (private) */
} CMAP_TAB;


typedef struct {
	FS_USHORT version;
	FS_USHORT number;
	CMAP_TAB tables[1];				/* really tables[number] */
	/* the subtable data follows here */
	} TTF_CMAP;

/* buffer size limits for TTF_CMAP and TTF_NAME structs */
#define MAX_MAPPINGS_LEN			20
#define MAX_FONT_NAME_LEN			50
#define MAX_FONT_FAMILY_NAME_LEN	50
#define MAX_COPYRIGHT_LEN			200

/* "name" table offsets */
#define NAME_NUM_REC		2
#define NAME_OFF_TO_STRS	4
#define NAME_NAMERECS		6
#define NAME_SIZE_NAMEREC	12
#define NAME_TAB_PLATID		0
#define NAME_TAB_SPECID		2
#define NAME_TAB_LANGID		4
#define NAME_TAB_NAMEID		6
#define NAME_TAB_STRLEN		8
#define NAME_TAB_STROFF		10

#define MSFT_ENC           3    /* platform ID */
#define US_ENGL       0x0409    /* language ID in name table */

typedef enum {
	name_Copyright,
	name_Family,
	name_Subfamily,
	name_UniqueName,
	name_FullName,
	name_Version,
	name_Postscript,
	name_Trademark
	} sfnt_NameIndex;

typedef struct {
	FILECHAR font_name[MAX_FONT_NAME_LEN];
	FS_BOOLEAN font_name_too_long;
	FILECHAR font_family_name[MAX_FONT_FAMILY_NAME_LEN];
	FS_BOOLEAN font_family_name_too_long;
	FILECHAR copyright[MAX_COPYRIGHT_LEN];
	FS_BOOLEAN copyright_too_long;
	} TTF_NAME;		/* abbreviated contents */

typedef struct {
	FS_USHORT	version;
	FS_SHORT	xAvgCharWidth;
	FS_USHORT	usWeightClass;
	FS_USHORT	usWidthClass;
	FS_SHORT	fsType;
	FS_SHORT	ySubscriptXSize;
	FS_SHORT	ySubscriptYSize;
	FS_SHORT	ySubscriptXOffset;
	FS_SHORT	ySubscriptYOffset;
	FS_SHORT	ySuperscriptXSize;
	FS_SHORT	ySuperscriptYSize;
	FS_SHORT	ySuperscriptXOffset;
	FS_SHORT	ySuperscriptYOffset;
	FS_SHORT	yStrikeoutSize;
	FS_SHORT	yStrikeoutPosition;
	FS_SHORT	sFamilyClass;
	FS_BYTE		panose[10];
	FS_ULONG	ulUnicodeRange1;	/* Bits 0-31 */
	FS_ULONG	ulUnicodeRange2;	/* Bits 32-63 */
	FS_ULONG	ulUnicodeRange3;	/* Bits 64-95 */
	FS_ULONG	ulUnicodeRange4;	/* Bits 96-127 */
	FILECHAR		achVendID[4];
	FS_USHORT	fsSelection;
	FS_USHORT	usFirstCharIndex;
	FS_USHORT	usLastCharIndex;
	FS_SHORT	sTypoAscender;
	FS_SHORT	sTypoDescender;
	FS_SHORT	sTypoLineGap;
	FS_USHORT	usWinAscent;
	FS_USHORT	usWinDescent;
	/* version 1 additions */
	FS_ULONG	ulCodePageRange1;	/* Bits 0-31 */
	FS_ULONG	ulCodePageRange2;	/* Bits 32-63 */
	/* version 2 additions */
	FS_SHORT sxHeight;
	FS_SHORT sCapHeight; 
	FS_USHORT usDefaultChar;
	FS_USHORT usBreakChar;
	FS_USHORT usMaxContext; 
	} TTF_OS2;

#ifdef CCC
typedef struct {
	FS_SHORT numBits_LOCA;  /* number of bits used for LOCA */
	FS_SHORT minVal_LSB, numBits_LSB;	/* mimium value for LSB and number of bits for LSB */
	FS_SHORT minVal_AW, numBits_AW;	/* mimium value for AW and number of bits for AW */
	FS_SHORT minVal_TSB, numBits_TSB;	/* mimium value for TSB and number of bits for TSB */
	FS_SHORT minVal_AH, numBits_AH;	/* mimium value for AW and number of bits for AH */
	FS_ULONG numBits_GLYF;				/* number of parts for GLYF */
	FS_BOOLEAN cccVersion7;			/* true if cccVersion 7 and up */
	} CCC_INFO;
#endif


typedef struct {
   FS_BYTE fnt_type;
	FILECHAR		*path;					/* if a disk file .. the path */
	FS_BYTE			*memptr;				/* else ROM/RAM location */
	FILE			*fp;					/* fp = FS_open(path) for disk file */
	TTC_HEADER		*ttc_header;			/* NULL if vanilla TTF */
	FS_ULONG		ttc_which;				/* current subfont of TTC */
	FS_ULONG		ttf_offset;				/* offset to TTF in TTC */
	TTF_HEADER		*ttf_header;			/* for current (sub) font */
	TTF_HEAD		*head;					/* 'head' table pointer */
	TTF_HHEA		*hhea;					/* 'hhea' table pointer */
	TTF_VHEA		*vhea;					/* 'vhea' table pointer */
	TTF_MAXP		*maxp;					/* 'maxp' table pointer */
	TTF_CMAP		*cmap;					/* 'cmap' table pointer - MOTOROLA BYTE ORDER */
	FS_BYTE			*prep;					/* 'prep' table  pointer */
	FS_LONG			num_prep;
	FS_BYTE			*fpgm;					/* 'fpgm' table pointer */
	FS_LONG			num_fpgm;
	FS_SHORT		*cvt;					/* 'cvt' table pointer */
	FS_LONG			num_cvt;
	FS_ULONG		*loca;					/* 'loca' table pointer */
	FS_ULONG		loca_offset;
	FS_ULONG		glyf_size;
	FS_ULONG		glyf_offset;			/* offset to "glyf" table */
	FS_ULONG		eblc_offset;			/* offset to "EBLC" table */
	FS_ULONG		kern_offset;			/* offset to 'kern' table */
	FS_ULONG		hmtx_offset;			/* offset to "hmtx" table */
	FS_ULONG		vmtx_offset;			/* offset to "vmtx" table */
	FS_ULONG		icon_offset;			/* offset to "Icon" table */
	TTF_OS2			*os2;					/* for current (sub) font */
	TTF_NAME		*name;					/* for current (sub) font - (abbreviated) */
	FS_VOID			*decomp;				/* (for ACT3 fonts) MTX_RA_TT_Decomp */
	FS_USHORT		*nstk;					/* array of non-stik indices */
#ifdef CCC
	CCC_INFO		ccc_info;
#endif
#ifdef MULTI_PROCESS
	FILECHAR *MF_path;
	FILECHAR *MF_name;
#endif
	FS_ULONG		vdmx_offset;
	} TTF;

typedef struct {
	FS_LONG num_tables;
	FS_LONG version;	/* reserved */
} KERN;

typedef struct {
	FS_USHORT *data;
} KERN_ENTRY;

/************* loaded/available fonts ***************************/
typedef struct _lfnt {
	FILECHAR	*name;					/* the proper name of the font */
	FILECHAR	*path;					/* if on DISK ... the complete path name */
	FS_BYTE		*memptr;				/* else if in RAM/ROM ... the address */
	FS_ULONG	index;					/* index of <name> in a TT collection */
#ifdef CACHE_CMAP
	FS_USHORT	cmap_unicode[128];		/* cmap cache unicode values             */
	FS_USHORT	cmap_index[128];		/* cmap cache glyph index values         */
#endif
	FS_ULONG	ref_count;				/* number of clients who have LFNT as current font */
	FS_ULONG    count_added;			/* number of clients load/add this font successfully */
	FS_VOID			*fnt;					/* if loaded ... here's the essential data */
   FS_BYTE    fnt_type;          /* specifies ttf or pfr etc. */
	KERN        *kerning;				/* the address to the kerning data */
										/* (if FS_get_kerning() is called) */
	struct _lfnt *prev,*next;			/* linked list goo */
	} LFNT;
#ifdef MULTI_PROCESS
/************* loaded/available file-mapped fonts ***************************/
typedef struct _mappedfnt {
	FILECHAR	*name;					/* the proper name of the font */
	FILECHAR	*path;					/* on DISK (by definition) ... the complete path name */
	FS_BYTE		*memptr;				/* starting address of the mapped file */
	FS_ULONG	index;					/* index of <name> in a TT collection */
	FS_VOID		*hfnt;					/* handle to mapped file */
	struct _mappedfnt *prev,*next;		/* linked list goo */
	} MAPPEDFNT;
#endif	/* MULTI_PROCESS */

/************* scaled font enviromnent **************************/
typedef struct {
	FS_FIXED user_scale[4];				/* scale matrix in 1/65536-the of PIXELS */
	FS_USHORT xppm;						/* meaningful only for 'vanilla' characters */
	FS_USHORT yppm;						/* used to match sizes for embedded bitmaps */ 
	FS_USHORT lpm;						/* rotation invarient measure of character size */
	FS_SHORT vanilla;					/* ? no rotation, skewing, or mirroring */
#ifdef STIK
	FS_FIXED stroke_pct;
	FS_SHORT stroke_width;
/*  following unused with AA autohinter */
	FS_FIXED cap_round;					/* for stik font autohinter */
	FS_FIXED cap_square;
	FS_FIXED x_round;
	FS_FIXED x_square;
	FS_FIXED base_round;
	FS_FIXED base_square; 
	FS_FIXED lsb;
	FS_FIXED rsb;
	FS_SHORT language;	
#endif
#ifdef PSEUDO_BOLD
	FS_FIXED bold_pct;					/* percent of em to embolden */
	FS_SHORT bold_width;
#endif

	FS_VOID * ttkey;					/* the TT scale information */

	FS_BOOLEAN subpixel;		/* for nested composite subpixel characters */
								/* managed within fsg_Gridfit */
	} SENV;

/************* scaled font instance *****************************/
/* so fonts with different SCALE's can share the same LFNT */
typedef struct _sfnt {
	LFNT *lfnt;							/* the loaded font */
	SENV *senv;							/* scale enviromnent */
	FS_ULONG cache_count;				/* number of things in cache */
	FS_ULONG active_count;				/* number of ACTIVE things in cache */
	struct _sfnt *prev,*next;			/* linked list goo */
	} SFNT;


/*************** cache ******************************************/
/* if cache is VERY large, you may wish to increase this to
* improve cache performance. The value must be a prime number
* less than 65536
*/
#define CACHE_MOD 127

/* the largest N prime numbers < 32768  (Knuth V2 p390) */
#define CACHE_OUTLINE	(FS_USHORT)(32768L - 19)
#define CACHE_GRAYMAP	(FS_USHORT)(32768L - 49)
#define CACHE_BITMAP	(FS_USHORT)(32768L - 51)
#define CACHE_PHASE0	(FS_USHORT)(32768L - 55)
#define CACHE_PHASE1	(FS_USHORT)(32768L - 61)
#define CACHE_PHASE2	(FS_USHORT)(32768L - 75)
#define CACHE_PHASE3	(FS_USHORT)(32768L - 81)
#define CACHE_ICON		(FS_USHORT)(32768L - 115)

typedef struct _cache_entry {
	FS_USHORT		type;		/* CACHE_OUTLINE, CACHE_BITMAP, CACHE_GRAYMAP */
	FS_USHORT		index;		/* glyph index of the <data> */
	FS_ULONG		flags;		/* user accessible flags */
	FS_BYTE			*data;		/* the FS_OUTLINE*, FS_BITMAP*, or FS_GRAYMAP* */
	SFNT			*sfnt;		/* the scaled font it came from */
#ifdef STIK
	FS_SHORT		stroke_width;
#endif /* STIK */

#ifdef PSEUDO_BOLD
	FS_SHORT		bold_width;
#endif /* PSEUDO_BOLD */

	struct _cache_entry *prev,*next;
	FS_ULONG ref_counter;
	} CACHE_ENTRY;


/************* the global state *********************************/
/* internal flags */
#define FLAGS_GRAY_LIMIT	(FS_ULONG)0x00000001
#define FLAGS_STIK			(FS_ULONG)0x00000002
#define FLAGS_ACT3			(FS_ULONG)0x00000004
#define FLAGS_CCC			(FS_ULONG)0x00000008
#define FLAGS_FIX_DROPOUTS	(FS_ULONG)0x00000010
#define FLAGS_IS_GRAY		(FS_ULONG)0x00000020

/* accessible interpreter flags */
#define FLAG_DO_DROPOUTS	(FS_ULONG)0x00000100
#define FLAGS_DROPOUTS_ON	FLAG_DO_DROPOUTS
#define FLAGS_DROPOUTS_OFF  (FS_ULONG)(~FLAGS_DROPOUTS_ON)
#define FLAGS_NO_HINTS		(FS_ULONG)0x00000200
#define FLAGS_HINTS_OFF		FLAGS_NO_HINTS
#define FLAGS_HINTS_ON		(FS_ULONG)(~FLAGS_HINTS_OFF)

/* accessible bitmap/graymap flags */
#define FLAGS_EMBOSSED		(FS_ULONG)0x00000400
#define FLAGS_ENGRAVED		(FS_ULONG)0x00000800
#define FLAGS_OUTLINED		(FS_ULONG)0x00001000
#define FLAGS_OUTLINED_1PIXEL		(FS_ULONG)0x00001000	/* synonym, for backwards compatibility */
#define FLAGS_OUTLINED_2PIXEL		(FS_ULONG)0x00100000
#define FLAGS_NO_EFFECT		(FS_ULONG)(~(FLAGS_EMBOSSED | FLAGS_ENGRAVED | FLAGS_OUTLINED_1PIXEL | FLAGS_OUTLINED_2PIXEL))

/* accessible graymap flags */
#define FLAGS_SOFTENED      (FS_ULONG)0x00002000
#define FLAGS_SOFTENED_ON   (FS_ULONG)0x00002000
#define FLAGS_SOFTENED_OFF  (FS_ULONG)(~FLAGS_SOFTENED_ON)
#define FLAGS_PHASED		(FS_ULONG)0x00004000
#define FLAGS_PHASED_ON		FLAGS_PHASED
#define FLAGS_PHASED_OFF	(FS_ULONG)(~FLAGS_PHASED_ON)
#define FLAGS_NO_GRAYMAP_EFFECT (FS_ULONG)(~(FLAGS_SOFTENED_ON | FLAGS_PHASED_ON))

/* Major and Minor versions: note that the MINOR_VERSION value is 
		(released minor version * 100), 
	to allow for numbering of interim patch releases */
#define MAJOR_VERSION 2
#define MINOR_VERSION 400

/* accessible subpixel flags */
#define FLAGS_SUBPIXEL		(FS_ULONG)0x00008000
#define FLAGS_SUBPIXEL_ON	FLAGS_SUBPIXEL
#define FLAGS_SUBPIXEL_OFF	(FS_ULONG)(~FLAGS_SUBPIXEL_ON)

#define FLAGS_CMAP_OFF	(FS_ULONG)0x00010000
#define FLAGS_CMAP_ON	(FS_ULONG)(~FLAGS_CMAP_OFF)

/* accessible check contour winding flag */
#define FLAGS_CHECK_CONTOUR_WINDING      (FS_ULONG)0x00020000
#define FLAGS_CHECK_CONTOUR_WINDING_ON   FLAGS_CHECK_CONTOUR_WINDING
#define FLAGS_CHECK_CONTOUR_WINDING_OFF  (FS_ULONG)(~FLAGS_CHECK_CONTOUR_WINDING_ON)

/* Vertical Writing */
#define FLAGS_VERTICAL_ON				(FS_ULONG)0x00040000
#define FLAGS_VERTICAL_OFF				(FS_ULONG)(~FLAGS_VERTICAL_ON)

/* accessible Icon flags */
#define FLAGS_ICON_MAP_OFF		(FS_LONG)0x00080000
#define FLAGS_ICON_MAP_ON	(FS_LONG)(~FLAGS_ICON_MAP_OFF)

/* NOTE: this value is used above: don't reuse */
/* #define FLAGS_OUTLINED_2PIXEL		(FS_ULONG)0x00100000 */

/* all user accessible flags */
#define FLAGS_USER (FLAGS_EMBOSSED | FLAGS_ENGRAVED \
	| FLAGS_OUTLINED_1PIXEL | FLAGS_OUTLINED_2PIXEL \
	| FLAGS_SOFTENED_ON | FLAGS_PHASED_ON | FLAGS_SUBPIXEL_ON \
	| FLAGS_HINTS_OFF | FLAGS_DROPOUTS_ON | FLAGS_CHECK_CONTOUR_WINDING_ON \
	| FLAGS_VERTICAL_ON )


/* different private values for ttf->head->glyphDataFormat */
#define STIK_FORMAT (FS_SHORT)(0x9654)
#define STIK_FORMAT_CCC(a)  ( ( a >= (FS_SHORT)(0x0200) ) &&  ( a <= (FS_SHORT)(0x02FF) ) )
#define TTF_FORMAT_CCC(a)   ( ( a >= (FS_SHORT)(0x0400) ) &&  ( a <= (FS_SHORT)(0x04FF) ) )

/* When we're processing a STIK font, we use bit 7 of the
* first TrueType glyph flag byte to say that this character
* REALLY is an outline character. It also appears in the byte
* FS_OUTLINE->type[0] with the same meaning */
#define OUTLINE_CHAR		0x80


/* Both FS_BITMAP and FS_GRAYMAP have the same basic structure. */
/* the only thing that differs is the number of bits per pixel. */
/* and therefore the number of bytes per line <bpl> in each */

/*****************************************************************************
 *
 *  Structure that describes a scaled and rasterized glyph as a
 *  1-bit-per-pixel bitmap.
 *   
 *  Description:
 *      This structure contains glyph metrics and image data.
 *  
 *      The metrics define glyph size and position, and the relative
 *      position of the next glyph.
 *  
 *      The lo_x and hi_y values define the upper left coordinate of
 *      the glyph relative to the <I>origin</I>, which is the point,
 *      generally along the baseline, that the glyph is to be
 *      positioned.
 *  
 *      The <I>advance</I> is the distance from the current origin to
 *      that of the next character. This structure supplies the
 *      advance in two forms: (1) integer and (2) fractional pixels.
 *      Most of the time, the integer pixel advance will give the
 *      best intercharacter spacing results. You must use the
 *      fractional pixel advance whenever both i_dx and i_dy are both
 *      zero as happens when the text is rotated or skewed. See the
 *      iType User Guide for a detailed explanation of text layout
 *      issues.
 *  
 *      The image data is stored in the bits[] array. It is a simple
 *      bit-mapped representation of a glyph: each bit represents a
 *      pixel, high-order bit comes first, bits are mapped
 *      left-to-right and then top-to-bottom. Rows are padded, if
 *      necessary, so that each ends on a byte boundary. A bit value
 *      of "1" means that the pixel is on or "inked".
 *  
 *      The number of bytes in a row is usually, but not necessarily,
 *      equal to (7 + width)/8. The actual length of the bits array
 *      is height * bpl.
 *
 *
 *
 *
 *
 *  
 *      For example consider a glyph of simple representation of the
 *      character "F":
 *      <CODE>
 *
 *
 *                       ****
 *                       *
 *                       ***
 *                       *
 *      baseline--->     *    * <---next character's origin
 * 
 *             0123456789012345678901234567890
 *
 *      </CODE>
 *      The FS_BITMAP would have these values (i_dx and dx are just example values):
 *
 *      <TABLE>
 *          lo_x     0 
 *          hi_y     4
 *          i_dx     5
 *          i_dy     0
 *          dx       340787 (5.2 as 16.16)
 *          dy       0 (0.0 as 16.16 format)
 *          width    4
 *          height   5
 *          bpl      1
 *          bits{}   {F0, 80, E0, 80, 80}
 *      </TABLE>
 *
 *  See Also:
 *      FS_get_bitmap, FS_get_subpixel_bitmap
 *
 *  <GROUP itypestructs>
 */
typedef struct {
	CACHE_ENTRY *cache_ptr;	/* cache-info structure (private) */
	FS_LONG size;			/* size of structure in bytes, including bits array */
	FS_SHORT lo_x;			/* pixel coordinate of left column, relative to origin */
	FS_SHORT hi_y;			/* pixel coordinate of upper row, relative to origin */
	FS_SHORT i_dx;			/* x-advance in pixels - 0 if rotated or skewed */
	FS_SHORT i_dy;			/* y-advance in pixels - 0 if rotated or skewed */
	FS_FIXED dx;			/* x-advance in fractional pixels (16.16 format) */
	FS_FIXED dy;			/* y-advance in fractional pixels (16.16 format) */
	FS_SHORT width;			/* width of the bitmap in pixels */
	FS_SHORT height;		/* height of the bitmap in pixels */
	FS_SHORT bpl;			/* bytes per line (row) of bitmap data */
	FS_BOOLEAN embedded;	/* was this taken from an embedded bitmap? */
	FS_BYTE  bits[1];		/* bitmap data packed in left-to-right, top-to-bottom order */
	} FS_BITMAP;


/*****************************************************************************
 *
 *  Structure that describes a scaled and rasterized glyph
 *  as a 4-bit-per-pixel graymap.
 *
 *  Description:
 *      This structure contains glyph metrics and image data.
 *
 *      The metrics define glyph size and position, and the relative
 *      position of the next glyph.
 *      
 *      The lo_x and hi_y values define the upper left coordinate of
 *      the glyph relative to the <I>origin</I>, which is the point,
 *      generally along the baseline, that the glyph is to be
 *      positioned.
 *
 *      The <I>advance</I> is the distance from the current origin to that of
 *      the next character.  This structure supplies the advance in two forms:
 *      (1) integer and (2) fractional pixels.  Most of the time, the integer
 *      pixel advance will give the best intercharacter spacing results.  
 *      You must use the fractional pixel advance whenever both i_dx and i_dy
 *      are both zero as happens when the text is rotated or skewed.  See the
 *      iType User Guide for a detailed explanation of text layout issues.
 *
 *      The image data is stored in the bits[] array. It is a simple gray-mapped
 *      representation of a glyph: each nibble represents a pixel, high-order nibble
 *      comes first, nibbles are mapped left-to-right and then top-to-bottom.
 *      Rows are padded, if necessary, so that each ends on a byte boundary.
 *
 *      The gray level values (0 to 15) represent the relative intensities of the
 *      text display color.  You will probably need to use different color values when 
 *      writing to your frame buffer.  See the discussion in the User Guide.
 *
 *      The number of bytes in a row is usually, but not necessarily, equal
 *      to (1 + width)/2.  The actual length of the bits array is height * bpl.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *      For example consider a glyph of simple representation of the character "F":
 *
 *      <CODE>
 *                       ****
 *                       *
 *                       ***
 *                       *
 *      baseline--->     *    * <---next character's origin
 * 
 *             0123456789012345678901234567890
 *      </CODE>
 *
 *      The FS_GRAYMAP would have these values (i_dx and dx are just example values):
 *      <TABLE>
 *          lo_x        0
 *          hi_y        4
 *          i_dx        5
 *          i_dy        0
 *          dx          340787 (5.2 as 16.16)
 *          dy          0  (0.0 as 16.16 format)
 *          width       4
 *          height      5
 *          bpl         2
 *          bits{}      {FF, FF, F0, 00, FF, F0, F0, 00, F0, 00}
 *      </TABLE>
 *
 *  See also:
 *      FS_get_graymap, FS_get_subpixel_graymap, FS_get_phased
 *
 *  <GROUP itypestructs>
 */
typedef struct {
    CACHE_ENTRY *cache_ptr; /* cache-info structure (private) */
    FS_LONG size;           /* size of structure in bytes, including bits array */
    FS_SHORT lo_x;          /* pixel coordinate of left column, relative to origin */
    FS_SHORT hi_y;          /* pixel coordinate of upper row, relative to origin */
	FS_SHORT i_dx;			/* x-advance in pixels - 0 if rotated or skewed */
	FS_SHORT i_dy;			/* y-advance in pixels - 0 if rotated or skewed */
    FS_FIXED dx;            /* x-advance in fractional pixels (16.16 format) */
    FS_FIXED dy;            /* y-advance in fractional pixels (16.16 format) */
	FS_SHORT width;			/* width of the graymap in pixels */
	FS_SHORT height;		/* height of the graymap in pixels */
    FS_SHORT bpl;           /* bytes per line (row) of graymap data */
	FS_BOOLEAN embedded;	/* was this taken from an embedded graymap? */
    FS_BYTE bits[1];        /* graymap data packed in left-to-right, top-to-bottom order */
	} FS_GRAYMAP;


/*****************************************************************************
 *
 *  Structure that describes a glyph as quadratic outlines.
 *
 *  Description:
 *      This structure contains glyph metrics and image data.
 *
 *      The lo_x and hi_y values define the upper left coordinate of the glyph
 *      relative to the origin, which is the point, generally along the baseline,
 *      that the glyph is to be positioned.
 *
 *      For example, the character "F" could be represented as:
 *      <TABLE>
 *          num         11
 *          type[]      {FS_MOVETO, FS_LINETO, ..., FS_LINETO}
 *          x[]         {0, 0, 196608, 196608, 65536, 65536, 131072, 131072, 65536, 65536, 0}
 *          y[]         {0, 327680, 327680, 262144, 262144, 196608, 196608, 131072, 131072, 0, 0}
 *          i_x[]       {0, 0, 3, 3, 1, 1, 2, 2, 1, 1, 0}
 *          i_y[]       {0, 5, 5, 4, 4, 3, 3, 2, 2, 0, 0}
 *      </TABLE>
 *
 *      Even though FS_OUTLINE contains pointers to structures, it is allocated
 *      as one piece of contiguous memory.  Any FS_OUTLINE structure
 *      returned by FS_get_outline() should be freed using FS_free_char().
 *
 *  See Also:
 *      FS_get_outline()
 *
 *  <GROUP itypestructs>
 */ 
typedef struct {
    CACHE_ENTRY *cache_ptr; /* cache-info structure (private) */
    FS_LONG size;           /* size of structure in bytes */
    FS_FIXED lo_x;          /* smallest x coordinate */
	FS_FIXED hi_x;			/* largest x coordinate */
	FS_FIXED lo_y;			/* smallest y coordinate */
	FS_FIXED hi_y;			/* largest y coordinate */
	FS_SHORT i_dx;			/* x-advance in pixels - 0 if rotated or skewed */
	FS_SHORT i_dy;			/* y-advance in pixels - 0 if rotated or skewed */
    FS_FIXED dx;            /* x-advance in fractional pixels (16.16 format) */
    FS_FIXED dy;            /* y-advance in fractional pixels (16.16 format) */
	FS_SHORT nc;        	/* number of contours */
    FS_SHORT num;           /* number of curve elements (moves, lines, or quadratics) */
    FS_SHORT polarity;		/* which side is "ink" on? (for emboldening) */
    FS_BYTE *type;          /* respective type of curve elements (one of FS_MOVETO, FS_LINETO, FS_QUADTO) */
    FS_FIXED *x;            /* x-coordinates of the elements in fractional pixels (16.16 format) */
    FS_FIXED *y;            /* y-coordinates of the elements in fractional pixels (16.16 format) */
	} FS_OUTLINE;

	/* note: OUTLINEs are allocated in one contiguous piece, so you can delete
	* them with <FS_free_char>. The pointers are set in creation or by <copy_outline>
	*/

/*****************************************************************************
 *
 *  Structure that describes a glyph as an icon.
 *
 *  Description:
 *      This structure contains icon glyph metrics and image data.
 *
 *      An icon is an actual image of some self-tagged format, coupled
 *      with size and offset information that allows the icon to be inserted
 *		into the text stream by the user's application, allowing the icon to 
 *		flow with the regular text.
 *
 *  See Also:
 *      FS_get_icon()
 *
 *  <GROUP itypestructs>
 */ 
typedef struct {
    CACHE_ENTRY *cache_ptr;		/* cache-info structure (private) */
	FS_LONG size;				/* size of structure in bytes, including bits array */
	FS_SHORT width;				/* width of the icon in pixels */
	FS_SHORT height;			/* height of the icon in pixels */
	FS_SHORT vert_bearing_x;    /* x-dir vertical bearing */
	FS_SHORT vert_bearing_y;    /* y-dir vertical bearing */
	FS_SHORT vert_advance;      /* vertical advance */
	FS_SHORT hori_bearing_x;    /* x-dir horizontal bearing */
	FS_SHORT hori_bearing_y;    /* y-dir horizontal bearing */
	FS_SHORT hori_advance;      /* horizontal advance */
	FS_BYTE data[1];		    /* any self tagged, transparent capable image format here */
} FS_ICON;


/*** table pointers ***/
typedef struct table_ptr_rec {
	LFNT *lfnt;				/* the LFNT the table was read from */
	FS_BYTE *ptr;			/* pointer to the data (internal or external) */
	FS_ULONG tag;			/* the table tag we read */
	FS_ULONG ref_count;		/* number of 'users' of the pointer */
	FS_BOOLEAN external;	/* if external==true, we can 'free' the pointer */
	struct table_ptr_rec *prev,*next;
	} TABLE_PTR_REC;


/*** the SERVER -- iType guts ***/
typedef void*  MUTEX;
struct FS_STATE;
typedef struct  {
	SFNT *scaled_fonts;		/* linkied list - all scaled fonts */
	LFNT *loaded_fonts;		/* linkied list - all available/loaded fonts */
	TLIST *tlist;			/* the current transition list -- for the rasterizer */
	TLIST *drop;			/* the current dropout list -- for the rasterizer */
	
#ifdef STIK
	FS_BITMAP *bmap;		/* for direct stik font rendering */
	FS_FIXED pixel_aspect;	/* displays aspect ratio: (xdpi << 16) / ydpi */
#endif /* STIK */
	
#ifdef CONTOUR_WINDING_DETECTION
	/* Array of TNODE indices of the start of loops 1 through outl->nnc */
	/* The array is indexed by contour number */
	/* nextLoopTX[0] is the starting TNODE index of the contour 1 */
	/* nextLoopTX[number of contours - 1] is the TNODE index just after the last */
	/* TNODE in the last contour */
	FS_LONG *nextLoopTX;
#endif
	
#ifdef REENTRANT
	FS_VOID (*line)(struct FS_STATE*, FS_FIXED,FS_FIXED,FS_FIXED,FS_FIXED);
#else
	FS_VOID (*line)(FS_FIXED,FS_FIXED,FS_FIXED,FS_FIXED);
#endif /* REENTRANT */
	
	CACHE_ENTRY *cache[CACHE_MOD];		/* cached things for all SFNT's */

	FS_ULONG heap_size;			/* amount of memory we can use */
	FS_ULONG allocated;			/* high water mark of memory allocation */

#ifdef INT_MEM
	/* we malloc(heapsize), then work within that lump */
	/* Why?  it keeps from fragmenting the system heap */
	MEM base;					/* empty to get things rolling */
	MEM *allocp;				/* the last allocated block */
	MEM *memory;				/* allocated in FS_init() */
#endif /* INT_MEM */

	TABLE_PTR_REC *table_ptrs;	/* for tables by reference */

	FS_ULONG version;			/* Major and Minor version  */
	LFNT *dup_lfnt;				/* LFNT with the same "font name" as that of the font added	with "NULL" name */

	FS_ULONG client_count;		/* number of active clients ... don't call FS_exit() until it's 0 */
#ifdef MULTI_PROCESS
/*	FS_VOID *mapToAddress; */
	FS_ULONG total_size;
	FS_LONG proc_count;	/* number of clients sharing heap */
#endif
	} FS_SERVER;


/*** the STATE (client info) ***/
typedef struct  FS_STATE {
	SFNT *cur_sfnt;			/* the current scaled font = LFNT + SCALE */
	LFNT *cur_lfnt;			/* the current named LFNT */
	FS_USHORT *cur_cmap;	/* the current subtable pointer in memory, in MOTOROLA byte order */
	FS_USHORT platform;		/* platform and encoding are needed */
	FS_USHORT encoding;		/* to restore cur_cmap */
	FS_ULONG error;			/* the most recent error code */
	FS_ULONG flags;			/* for FS_set_flags ... */
	FS_FIXED scale[4];		/* needed to rebuild SFNT from LFNT */
	FS_FIXED stroke_pct;
	FS_FIXED bold_pct;
	FS_ULONG heap_size;		/* the additional memory requested by this client */
	FS_BYTE level;
	FS_BYTE components;		/* number of components in top level character */
	FS_BYTE any_hints;
	FS_BYTE outl_char;		/* this char in STIK font is really an outline */
	FS_USHORT lpm;
	FS_ULONG ref_count;
	FS_SERVER *server;		/* pointer to the guts of iType */
#ifdef MULTI_PROCESS
	/* File-mapped and shared memory data can potentially be mapped to a */
	/* different location in memory for each process. As a result, each  */
	/* process needs its own LFNT list and shared memory pointer.        */
	MAPPEDFNT *mappedfnts;		/* process's file-mapped list */
	FS_BYTE *shared_mem;		/* process's pointer to shared memory */
	FS_LONG hshared_mem;		/* process's handle to shared memory */
	FS_BOOLEAN my_shared_mem;	/* TRUE if shared mem seg was created by this process */
/*	FS_BOOLEAN my_shared_sem; */	/* TRUE if semaphore was created by this process */
#endif
	/* NOTE: The "process_num" and "FS_mutex_ptr" fields must be  */
	/* the last two fields of the FS_STATE structure in order for */
	/* multi-threading and multi-processing to work properly!     */
	FS_LONG process_num;		/* number of process associated with this state */
	MUTEX FS_mutex_ptr;		/* the mutex used for multi-threading */
	} FS_STATE;
	

/*****************************************************************************
 *
 *  Structure that describes the name, location, and index of a font. 
 *  Used to store the list of fonts available at startup time.
 *
 *  <GROUP itypestructs>
 */
typedef struct 
{
	FILECHAR *name;		/* null terminated string that defines name of the font */
	FILECHAR *path;		/* path name of font (when font is file system based) */
	FS_BYTE *memptr;	/* address of font (when font is memory-mapped) */
	FS_ULONG index;		/* index of font (this should be set to 0, unless font is a collection) */
} MY_FONT;


/*****************************************************************************
 *
 *  Structure that describes a bounding box.
 *
 *  Description:
 *      A bounding box describes the extent of a character or character set.
 *
 *      The y-coordinate increases from bottom-to-top.
 *
 *  See Also:
 *      FONT_METRICS 
 *
 *  <GROUP itypestructs>
 */
typedef struct 
{
	FS_SHORT xMin;              /* left */
	FS_SHORT yMin;              /* bottom */
	FS_SHORT xMax;              /* right */
	FS_SHORT yMax;              /* top */
} BBOX;


/* bit values for "font_type" field */
#define FM_FLAGS_TTF	0x0001
#define FM_FLAGS_STIK	0x0002
#define FM_FLAGS_CCC	0x0004
#define FM_FLAGS_ACT3	0x0008
#define FM_FLAGS_TTC	0x0010
#define FM_FLAGS_PFR	0x0020


/*****************************************************************************
 *
 *  Structure that describes metrics that apply to entire font.
 *
 *  Description:
 *      In general, if a numeric field or table is not present in the font,
 *      the corresponding field will be set to NOT_DEFINED.
 *
 *      There are three sets of ascender/descender/leading values.  Refer
 *      to the <I>User Guide</I> for discussion of how to use these.
 *      There is no os2_win_leading value.
 *
 *		For PFR fonts (which do not have TrueType tables), the same set of 
 *		values is used for all three sets of ascender/descender/leading values,
 *		and the cmap values will be null. The metrics_resolution value is 
 *		used only for PFR fonts - it will be null for all TrueType fonts.
 *
 *      The font_type bit field bits settings are:
 *      <TABLE>
 *      <B>Bit</>   <B>Type</B>
 *      0           TTF TrueType font
 *      1           STF (Stroke font)
 *      2           CCC compressed font
 *      3           ACT compressed font
 *      4           TTC TrueType collection
 *		5			PFR Format 0 font
 *	    6-15		Reserved 
 *      </TABLE>
 *
 *      The <I>mappings</I> array describes the set of available cmaps.  Each
 *      array entry is a CMAP_TAB structure, which stores cmap platform
 *      and encoding information.  The number of valid mappings[] entries
 *      is given by num_cmap_tables.
 *
 *  See Also:
 *      FS_font_metrics(), CMAP_TAB, BBOX
 *
 *  <GROUP itypestructs>
 */
typedef struct {
	FS_USHORT unitsPerEm;       /* design units from 'head' table -> unitsPerEm */
	FS_SHORT os2_win_ascent;    /* ascender from 'OS/2' table -> usWinAscent */
	FS_SHORT os2_win_descent;   /* descender from 'OS/2' table -> usWinDescent */
	FS_SHORT os2_ascent;        /* ascender from 'OS/2' table -> sTypoAscender */
	FS_SHORT os2_descent;       /* descender from 'OS/2' table -> sTypoDescender */
	FS_USHORT os2_leading;      /* line gap from 'OS/2' table -> sTypoLineGap */
	FS_SHORT hhea_ascent;       /* ascender from 'hhea' table -> Ascender */
	FS_SHORT hhea_descent;      /* descender from 'hhea' table -> Descender */
	FS_USHORT hhea_leading;     /* line gap from 'hhea' table -> LineGap */
	FS_USHORT embedding_bits;   /* font embedding licensing rights from 'OS/2' table -> fsType */
	BBOX font_bbox;       		/* exact value of font bounding box */
	FS_USHORT font_type;		/* bit field that describes type */
	FS_USHORT num_cmap_tables;		/* number of valid entries in the <I>mappings</I> array (from "cmap" table) */
	CMAP_TAB mappings[MAX_MAPPINGS_LEN];	/* array of cmap descriptions (from "cmap" table) */
	FS_ULONG numFontsInTTC;	   /* number of fonts in file (valid only if file is a TrueType collection) */
	FS_ULONG indexInTTC;       /* index in TTC file of current font (valid only if file is a TrueType collection) */
	FILECHAR font_name[MAX_FONT_NAME_LEN];		/* font name */
	FILECHAR font_family_name[MAX_FONT_FAMILY_NAME_LEN];  /* font family name (from 'name' table) */
	FILECHAR copyright[MAX_COPYRIGHT_LEN];		/* font copyright (from 'name' table) */
    FS_USHORT metricsResolution;  /* pfr only */
	} FONT_METRICS;


#define FS_MP_SEM_NAME		"iTypeSemaphore"
/* To convert a pointer to shared memory to an offset */
#ifdef MULTI_PROCESS
#define MP_memOFF(a) ((!(a)) ? NULL : (FS_VOID *)((FS_BYTE *)(a) - (FS_BYTE *)real_memptr) )
#define MP_OFF(a) ((!(a)) ? NULL : (FS_VOID *)((FS_BYTE *)(a) - (FS_BYTE *)STATE.server) )
#define MPsp_OFF(a) ((!(a)) ? NULL : (FS_VOID *)((FS_BYTE *)(a) - (FS_BYTE *)sp->server) )
#define MPgs_OFF(a) ((!(a)) ? NULL : (FS_VOID *)((FS_BYTE *)(a) - (FS_BYTE *)gs->server) )
#else
#define MP_memOFF(a) a
#define MP_OFF(a) a
#define MPsp_OFF(a) a
#define MPgs_OFF(a) a
#endif
 
/* To convert an offset to a pointer to shared memory */
#ifdef MULTI_PROCESS
/* DO NOT CHANGE "(long)" CAST BELOW - NEEDED FOR ALPHA */
#define MP_memPTR(a) ((!(a)) ? NULL : (FS_VOID *)((long)(a) + (FS_BYTE *)real_memptr) )
#define MP_PTR(a) ((!(a)) ? NULL : (FS_VOID *)((long)(a) + (FS_BYTE *)STATE.server) )
#define MPsp_PTR(a) ((!(a)) ? NULL : (FS_VOID *)((long)(a) + (FS_BYTE *)sp->server) )
#define MPgs_PTR(a) ((!(a)) ? NULL : (FS_VOID *)((long)(a) + (FS_BYTE *)gs->server) )
#else
#define MP_memPTR(a) a	
#define MP_PTR(a) a
#define MPsp_PTR(a) a
#define MPgs_PTR(a) a
#endif

/****************************************************************/
/*
* if REENTRANT is defined, the calling program must
* declare and allocate the state pointer using the	
* name "FS_state_ptr".  Then this  pointer will be
* passed by the _PS_ and _PS0_ macros. for example
*
*  main()
*	{
*	// other local variables 
*	#ifdef REENTRANT
*	FS_STATE *FS_state_ptr;
*	FS_state_ptr = (FS_STATE *) malloc(sizeof(FS_STATE));
*	#endif	
*	
*	FS_init(_PS_ heap_SIZE);
*	// other code
*   }
* if REENTRANT is undefined, the state is kept in the
* static variable FS_state, defined in the file api.c
* and the _PS_ and _PS0_ macros pass nothing.
*
* In this way you can write code which does not care
* whether REENTRANT is defined or not. For example here
* are sample prototypes of two functions that work either way:
*   int foo(_DS0_);
*   int goo(_DS_ arg);
*
* And the sample calls of these functions that work either way:
*   r = foo(_PS0_);
*   r = goo(_PS_ arg);
*/


#ifdef REENTRANT
#define STATE (*FS_state_ptr)			/* dereference passed pointer */
#define _DS0_ FS_STATE *FS_state_ptr	/* define state pointer as the only argument */
#define _DS_  FS_STATE *FS_state_ptr,	/* define state pointer as the first argument */
#define _PS0_ FS_state_ptr				/* pass state pointer as the only argument */
#define _PS_  FS_state_ptr,				/* pass state pointer as the first argument */

#else
#define STATE FS_state					/* just reference the global variable */
#define _DS0_ VOID_ARGS					/* define no arguments */
#define _DS_							/* define nothing */
#define _PS0_							/* pass nothing */
#define _PS_							/* pass nothing */

#endif /* REENTRANT */

#ifdef ACT3
#include "radecomp.h"
#include "tablecmp.h"
#include "ttf_conv.h"
#include "ra_ttf.h"
#endif


/* Define an appropriate ITYPE_API for both export and import   */
/* following model below, if necessary.  Most architectures can */
/* probably ignore this, not needing any special adornment.     */
/* Will need to define FS_EXPORT_DLL or FS_IMPORT_DLL (port.h)  */
/* during compile in order to activate these declarations.      */

#ifdef _WIN32
#if defined(FS_EXPORT_DLL)
#define ITYPE_API __declspec(dllexport)
#elif defined(FS_IMPORT_DLL)
#define ITYPE_API __declspec(dllimport)
#endif
#endif /* _WIN32 */

/* default case...empty definition */
#ifndef ITYPE_API
#define ITYPE_API
#endif

/* where does FS_STATE info live ?	*/
#ifdef __cplusplus
extern "C" {extern ITYPE_API FS_STATE FS_state;}
#else
extern ITYPE_API FS_STATE FS_state;
#endif /* __cplusplus */

#endif /* __OBJECTS__ */
