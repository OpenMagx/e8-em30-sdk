
/* Copyright (C) 2005 Monotype Imaging Inc. All rights reserved. */

/* Monotype Imaging Confidential */

/* Encoding:   US_ASCII    Tab Size:   8   Indentation:    4  */

/* $Header:   I:/BULL/raptor/raptor/function.h_v   1.72   Nov 29 2005 17:16:20   galejss  $ */
/* $Log:   I:/BULL/raptor/raptor/function.h_v  $
 * 
 *    Rev 1.72   Nov 29 2005 17:16:20   galejss
 * many updates to Docomatic comments for 2.4 version of API Reference
 * 
 *    Rev 1.71   Nov 18 2005 08:51:50   dugganj
 * Removed "ITYPE_API" prefix for prototypes for functions getpagesize(), FS_create_shared_mem(), FS_attach_shared_mem(), FS_detach_shared_mem(), FS_delete_shared_mem() and FS_open_shared_mem(). Removed prototype for obsolete function FS_attach_shared_mem_at_this_addr().
 * 
 *    Rev 1.70   Nov 03 2005 17:55:02   galejss
 * add Confidential notice (ITP-180)
 * 
 *    Rev 1.69   Sep 30 2005 13:07:32   dugganj
 * Added prototypes for new kern functions.
 * 
 *    Rev 1.68   Sep 20 2005 13:55:28   dugganj
 * Cleanup and warning removal.
 * 
 *    Rev 1.67   Aug 25 2005 10:45:32   dugganj
 * Changed the "name" arg of the FS_create_shared_mem() and FS_open_shared_mem() functions to "FILECHAR *" to resolve compiler warnings.
 * 
 *    Rev 1.66   Aug 23 2005 13:00:24   dugganj
 * Changed the prototype for function "swapw" to "extern" if building with neither "FS_IMPORT_DLL"  nor "FS_EXPORT_DLL" enabled.
 * 
 *    Rev 1.65   Aug 18 2005 11:02:42   dugganj
 * More PFR changes.
 * 
 *    Rev 1.64   Aug 16 2005 18:19:18   galejss
 * changes for PFR support
 * 
 *    Rev 1.63   Aug 10 2005 11:06:12   azimaf
 * changed the swapl prototype to handle build of the itypetst
 * progran.
 * 
 *    Rev 1.62   Jul 29 2005 15:02:36   galejss
 * remove redundant port.h include (also included in object.h)
 * 
 *    Rev 1.61   Jul 19 2005 07:26:32   dugganj
 * Conditionally compiled the multi-process versions of the dump prototypes based on MULTI_PROCESS instead of FS_MP_DEBUG.
 * 
 *    Rev 1.60   Jul 11 2005 17:20:58   galejss
 * add dump_hints() declaration
 * 
 *    Rev 1.59   Jul 08 2005 14:57:02   galejss
 * remove obsolete USE_MY_FONTS code
 * 
 *    Rev 1.58   Jun 27 2005 16:03:42   galejss
 * add Docomatic comments to API function declarations
 * 
 *    Rev 1.57   Jun 17 2005 16:19:04   dugganj
 * Moved the prototypes for swapw and swapl back from PORT.H
 * 
 *    Rev 1.56   Jun 15 2005 13:11:10   dugganj
 * Multi-processing related changes.
 * 
 *    Rev 1.55   May 17 2005 20:15:08   galejss
 * outline_bitmap becomes outline1_bitmap and outline2_bitmap
 * 
 *    Rev 1.54   May 17 2005 13:48:46   galejss
 * make IDIV and IMOD part of ITYPE_API
 * 
 *    Rev 1.53   May 12 2005 10:27:40   wuq
 * Added prototypes for new functions FS_get_vdmx_pair() and FSS_get_vdmx_pair().
 * 
 *    Rev 1.52   May 06 2005 11:11:24   wuq
 * Added prototypes for new functions FS_get_table_structure()
 * and FSS_get_table_structure(), FS_get_heap_used() and FSS_get_heap_used().
 * 
 *    Rev 1.51   May 05 2005 16:32:08   azimaf
 * Added compatibility with 2.4 alpha
 * 
 *    Rev 1.50   May 02 2005 16:19:00   azimaf
 * Revert back to 2.3 auto hinting
 * 
 *    Rev 1.49   Apr 13 2005 10:12:46   azimaf
 * Enclosed the swapl and swapw by NEED_TO_SWAP
 * 
 *    Rev 1.48   Mar 28 2005 14:19:50   dugganj
 * Added missing prototype for FSS_load_font().
 * 
 *    Rev 1.47   Mar 28 2005 10:27:06   wuq
 * Changes (by swp).
 * 
 *    Rev 1.46   Apr 27 2004 11:52:10   GalejsS
 * remove copy_outline() utility function (not multithreading-safe)
 * 
 *    Rev 1.45   Apr 26 2004 11:27:56   lynchr
 * Added prototypes for dump_icon and FS_get_flags functions.
 * 
 *    Rev 1.44   Apr 16 2004 09:53:46   DugganJ
 * Added prototypes for new functions FS_load_font()
 * and FSS_load_font().
 * 
 *    Rev 1.43   Apr 14 2004 09:48:24   azimaf
 * fixed the linkage problem with swapl
 * when this function is declared as inline 
 * 
 *    Rev 1.42   Mar 24 2004 10:50:34   dugganj
 * Removed extra declaration of function FSS_get_icon() to resolve "dll linkage" compiler warning.
 * 
 *    Rev 1.41   Mar 19 2004 16:46:10   Galejs
 * fix comment in #else (bug # 100)
 * 
 *    Rev 1.40   Mar 18 2004 11:09:48   dugganj
 * Removed second declarations of FS_free() and FS_realloc()
 * within MULTI_THREAD section. Removed declaration of
 * FS_new_state() entirely.
 * 
 *    Rev 1.39   Jan 26 2004 12:28:14   Galejs
 * revert to FILECHAR data type (to match published coding standards)
 * 
 *    Rev 1.38   Dec 16 2003 09:04:58   Paul
 * restored 'char' datatype
 * 
 *    Rev 1.37   Dec 09 2003 09:56:28   Paul
 * added FS_get_gpos_pts, removed FS_get_rgbmap
 * 
 *    Rev 1.36   Dec 04 2003 15:43:22   Galejs
 * add FS/FSS_get_icon
 * 
 *    Rev 1.35   Dec 02 2003 17:51:12   Galejs
 * add FS_get_kerning, trim_graymap
 * 
 *    Rev 1.34   Nov 26 2003 15:30:28   Galejs
 * major restructure to support MULTI_THREAD option
 * 
 *    Rev 1.33   Apr 24 2003 17:17:24   Galejs
 * centralize system include files (bug # 62)
 * 
 *    Rev 1.32   Apr 09 2003 13:46:42   careyj
 * export make_outline to windows DLL for WTLEngine GPOS
 * 
 *    Rev 1.31.1.0   Apr 09 2003 11:14:00   careyj
 * make_outline necessary for GPOS handling in WTLE
 * 
 *    Rev 1.31   Apr 04 2003 09:46:56   Paul
 * removed ITYPE_API status for FS_quad
 * 
 *    Rev 1.29   Apr 03 2003 10:51:06   careyj
 * adorn API functions with DLL creation ITYPE_API label
 * 
 *    Rev 1.28.1.1   Apr 02 2003 12:09:36   careyj
 * need map_char as part of API, as well
 * 
 *    Rev 1.28.1.0   Mar 31 2003 17:10:18   CareyJ
 * appropriate adornment for DLL creation
 * 
 *    Rev 1.28   Mar 25 2003 16:59:32   Galejs
 * mask[] -> fs_mask[], char -> FILECHAR
 * 
 *    Rev 1.27   Mar 13 2003 17:07:46   Galejs
 * remove copyright symbol (portability issue)
 * 
 *    Rev 1.26   Mar 13 2003 10:55:38   Paul
 * put the function IMOD() back
 * 
 *    Rev 1.25   Mar 11 2003 11:49:54   Paul
 *   
 *    Rev 1.24   Mar 11 2003 11:07:18   Paul
 * move <mask> to api.c with linkage in function.h
 * move <Lmask> and <Rmask> back to bitmap.c
 * 
 *    Rev 1.23   Mar 11 2003 09:35:36   Paul
 * changes for table pointers by reference
 * 
 *    Rev 1.22   Mar 06 2003 11:56:52   WuQ
 *  
 *    Rev 1.21   Feb 14 2003 12:51:24   Azima
 * FS_get_version is defined to return the
 * major and minor version number.
 * 
 *    Rev 1.20   Feb 03 2003 12:51:30   PrakasV
 * remove include file symbianapi.h
 * 
 *    Rev 1.19   Jan 30 2003 16:57:02   Azima
 * Added new FS_get_version definition
 * 
 *    Rev 1.18   Jan 22 2003 17:10:56   Paul
 * move FS_get_phased() to <api.c> and hook it into the cache
 * 
 *    Rev 1.17   Dec 13 2002 10:42:44   WuQ
 * New functions added related to subpixel rendering, pseudo bold and cache management (by swp)
 * 
 *    Rev 1.16   Nov 14 2002 12:38:58   PrakasV
 * move global static const mask[] from .c files to this file.
 * Include conditional include file SymbianApi.h for symbian port
 * 
 *    Rev 1.15   Oct 01 2002 12:20:06   Paul
 * repair of OS/2 table read and rotation invarient STATE.lpm code
 * 
 *    Rev 1.14   Jul 12 2002 14:02:22   Joe
 * Replaced FS_free() prototype with FS_free_char() prototype.
 * Replaced FS_free_ptr() prototype with FS_free() prototype (by swp).
 * 
 *    Rev 1.13   Jul 12 2002 09:03:52   Joe
 * Replaced function prototype FS_table_info() with FS_get_table().
 * Added function prototype FS_free_table() (by swp).
 * 
 *    Rev 1.12   Jul 11 2002 09:27:32   Joe
 * Removed duplicate function prototype for FS_free().
 * 
 *    Rev 1.11   Jun 28 2002 09:56:28   Joe
 * Cleanup (by swp)
 * 
 *    Rev 1.10   May 29 2002 11:46:48   WuQ
 * Changes for CCC, cmap, memory management and query function for JFD
 * 
 *    Rev 1.8   Oct 22 2001 17:52:08   Paul
 * consistent use of FS_VOID, added swapw() and swapl() prototypes
 * 
 *    Rev 1.7   Jul 27 2001 18:23:36   Galejs
 * change type for get_outline/bitmap/graymap
 * 
 *    Rev 1.6   Jul 10 2001 12:56:26   Paul
 * changes for STIK fonts
 * 
 *    Rev 1.5   Jun 13 2001 11:57:22   Paul
 * Reentrancy changes for INT_MEM
 * 
 *    Rev 1.4   Jan 29 2001 17:14:28   Galejs
 * use char* path in FS_add_font, load_to_ram, load_ttf, FS_create, FS_open
 * 
 *    Rev 1.3   Sep 26 2000 10:56:48   galejs
 * add PVCS Header/Log strings
 *
 */


#include "fnt.h"
#include "fsglue.h"


#ifdef __cplusplus
extern "C" {
#endif

#ifndef false
#define false 0
#endif

#ifndef true
#define true 1
#endif

#ifndef NULL
#define NULL 0
#endif

#if defined(CCC) || defined(ACT3)
#define COMPRESSED
#endif

#if defined(CACHE_BITMAPS) || defined(CACHE_GRAYMAPS) || defined(CACHE_OUTLINES) || defined(CACHE_PHASED)
#define CACHE
#endif

/* "mode" values for FS_get_table() */
#define TBL_QUERY		(FS_BYTE)1
#define TBL_EXTRACT		(FS_BYTE)2

/* mask values */
extern CONST FS_BYTE fs_mask[8];

/*** the API calls ... application level calls, static link or library ***/
#ifdef FS_DUMP
#ifndef MULTI_PROCESS
ITYPE_API FS_VOID dump_bitmap(FS_BITMAP *p);
ITYPE_API FS_VOID dump_graymap(FS_GRAYMAP *gmap);
ITYPE_API FS_VOID dump_outline(FS_OUTLINE *outl);
#else
/*****************************************************************************
 *
 *  Prints contents of FS_BITMAP including metrics and an ASCII 
 *  representation of glyph.
 *      
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      p        	- [in] reference to a bitmap glyph
 *
 *  Return Value:
 *      None
 *
 *  <GROUP fsdump>
 */
ITYPE_API FS_VOID dump_bitmap(_DS_ FS_BITMAP *p);


/*****************************************************************************
 *
 *  Prints contents of FS_GRAYMAP including metrics and an ASCII
 *  representation of glyph.
 *
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      gmap        - [in] reference to a graymap glyph
 *
 *  Return Value:
 *      None
 *
 *  <GROUP fsdump>
 */
ITYPE_API FS_VOID dump_graymap(_DS_ FS_GRAYMAP *gmap);


/*****************************************************************************
 *
 *  Prints contents of FS_OUTLINE as a list of curve elements and associated
 *  coordinates.
 *      
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      outl        - [in] reference to an outline glyph
 *
 *  Return Value:
 *      None
 *
 *  <GROUP fsdump>
 */
ITYPE_API FS_VOID dump_outline(_DS_ FS_OUTLINE *outl);
#endif


/*****************************************************************************
 *
 *  Prints contents of FS_ICON structure.
 *      
 *  Parameters:
 *      icon        - [in] reference to an icon structure
 *
 *  Return Value:
 *      None
 *
 *  <GROUP fsdump>
 */
ITYPE_API FS_VOID dump_icon(FS_ICON *icon);


#endif /* FS_DUMP */

#ifdef MULTI_PROCESS
#if defined( _WIN32 ) && !defined(__MARM_ARMI__)
FS_LONG getpagesize();
#endif
FS_LONG FS_create_shared_mem(_DS_ FS_LONG size, FILECHAR *name);
FS_VOID *FS_attach_shared_mem(_DS_ FS_LONG hMapObject, FS_LONG size);
FS_LONG FS_detach_shared_mem(_DS_ FS_VOID *shared_mem, FS_LONG size);
FS_VOID FS_delete_shared_mem(_DS_ FS_LONG hMapObject);
FS_LONG FS_open_shared_mem(_DS_ FS_LONG size, FILECHAR *name);
FS_BYTE *MF_get_mapped_font(_DS_ FILECHAR *path, FILECHAR *name);
FS_BYTE *MF_map_font(_DS_ FILECHAR *path, FILECHAR *name);
#endif /* FS_DUMP */

#ifdef MULTI_THREAD
/* multi-threaded API calls */

/*****************************************************************************
 *
 *  Constructs an iType server and initializes the 'master client's' data
 *
 *  Description:
 *      This function should generally be called only once per server, 
 *      upon startup of whichever system controls iType.
 *		There are some differences in the MULTI_PROCESS case.
 *      The corresponding shutdown function is FS_exit().
 *
 *      FS_init does the following:
 *      - validates the basic data types defined in port.h
 *      - validates certain configuration options defined in port.h
 *      - constructs and initializes the server
 *      - initializes the master client's data, stored in FS_STATE
 *      
 *      Constructing the server involves:
 *      - allocating the server structure using malloc
 *      - constructing the heap (see Notes section below) 
 *
 *      The heap is used to store data that is shared among clients:
 *      - list of loaded fonts
 *      - loaded font data
 *      - scaled font data and cache
 *      - glyph cache
 *       
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      heap_size   - [in] the maximum amount of RAM, in bytes, that this 
 *                         iType engine will use for its heap
 *
 *  Return value:
 *      SUCCESS, or an error code if the engine could not be initialized.
 *
 *  Notes:
 *		If MULTI_PROCESS is defined, FS_init() is called by each new process,
 *		in order to create the shared memory segment (or attach to an
 *		existing shared memory segment). When creating the shared memory
 *		segment, the server is also constructed and initialized.
 *		
 *      If MULTI_THREAD is defined only the master client should 
 *      call FS_init().  Other threads should call FS_new_client().
 *
 *      If REENTRANT is defined, the master client must allocate an 
 *      FS_STATE structure and pass in a pointer to that structure.
 *      A reentrant build allows multiple iType engines.
 *
 *      If INT_MEM is defined, then the heap is constructed by allocating
 *      a contiguous buffer of heap_size bytes.  If INT_MEM is not 
 *      defined then system memory will be used as needed, up to heap_size bytes,
 *      but no contiguous buffer is allocated here. 
 *
 *      It is an unchecked run-time error to call FS_init() twice for the same
 *      FS_STATE structure without first having called FS_exit.
 *
 *  See also:
 *      FS_exit(), FS_new_client(), FS_end_client(), FS_STATE
 *  
 *  <GROUP admin>
 */
ITYPE_API FS_LONG FS_init(_DS_ FS_ULONG heap_size);


/*****************************************************************************
 *
 *  Returns the last error code encountered by an iType function.
 *
 *  Description:
 *      This function is useful in conjunction with functions that
 *      do not return an error code.
 *
 *      For example, if FS_get_bitmap() returns NULL rather than a valid pointer to
 *      an FS_BITMAP structure, this indicates an error.  The client
 *      would then call FS_error() to get the error.
 *
 *      Each FS_STATE structure stores its own last error, so the last
 *      error refers only to calls made using this FS_STATE structure.
 *    
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *
 *  Return value
 *      Error code
 *      
 *  <GROUP admin>
 */
ITYPE_API FS_LONG FS_error(_DS0_);


/*****************************************************************************
 *
 *  Sets the current font.  
 *
 *  Description:
 *      This function sets the 'current' font.
 *      The current font is the one used for subsequent calls to get font
 *      information, get glyphs, or get other character/glyph-specific
 *      information.  The current font remains active until another font is 
 *      set, or the current font is deleted.
 *
 *      Each client maintains its own value for current font.
 *
 *      The first time a particular font is set, iType validates
 *      the file and loads vital font tables.
 *      
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      name        - [in] font name as null terminated string
 *                         This is the name that was used with FS_add_font().
 *
 *  Return Value:
 *      SUCCESS, or error code if font could not be set.
 *
 *      <TABLE>
 *      Return values           Reason
 *      ------------------      --------------------------------
 *      ERR_FONT_NOT_FOUND      font by that name is not found
 *      ERR_FONT_NOT_VALID      current font file is not a valid font
 *      ERR_MALLOC_FAIL         not enough memory to load font.
 *      ERR_NOT_A_TTF           font is not a TTF font
 *      ERR_ACT3_DISK           font is a disk-based ACT3 compressed font
 *      ERR_ACT3_UNDEF          font is ACT3 compressed but ACT3 configuration not defined
 *      ERR_PFR_UNDEF           font is in PFR format but PFR configuration not defined
 *      </TABLE>
 *      
 *  <GROUP statecontrol>
 */ 
ITYPE_API FS_LONG FS_set_font(_DS_ FILECHAR *name);


/*****************************************************************************
 *
 *  Sets or clears a flag.
 *
 *  Description:
 *      This function is used to set certain flags that affect how the
 *      various FS_get_<I>glyph</I> functions work and how glyphs are made.
 *      Each call to FS_set_flags() sets one flag.  There are two types 
 *      of flags: (1) edge effect flags, and (2) on/off flag pairs. 
 *
 *      The edge effect flags are mutually exclusive, as only one edge effect
 *      is applied at a time.  The default setting is FLAGS_NO_EFFECT, a normal
 *      glyph with no edge.  Once an edge effect is set it remains in effect 
 *      until FS_set_flag() is called with a different edge effect.  
 *      The edge effects are:
 *      <TABLE>
 *      Flag                        Effect on glyph 
 *      ---------------------       ----------------------------
 *      FLAGS_NO_EFFECT (default)   Normal glyph                    
 *      FLAGS_EMBOSSED              Appears raised
 *      FLAGS_ENGRAVED              Appears depressed or etched
 *      FLAGS_OUTLINED              Appears as unfilled outlines (1 pixel wide)
 *      FLAGS_OUTLINED_1PIXEL       Appears as unfilled outlines (1 pixel wide)
 *      FLAGS_OUTLINED_2PIXEL       Appears as unfilled outlines (2 pixels wide)
 *      </TABLE>
 *     
 *      Glyphs made with the embossed, engraved, or outlined effects   
 *      are unfilled, and they appear as an outline around/near 
 *      the edges set by the normal glyph. These effects work for
 *		both bitmaps and graymaps. 
 *		For bitmaps, the edge is one pixel wide.  
 *		For graymaps, the edge is nominally one pixel wide, 
 *		but may be more because the edge is gray.
 *
 *      For example, to set the edge effect to embossed:
 *      <CODE>
 *          FS_set_flags(state, FLAGS_EMBOSSED);
 *      </CODE>
 *
 *      The on/off flag pairs each control a certain aspect of glyph
 *      generation.  Flags are initialized to their defaults. After that
 *      the current setting is the last one set; a flag remains set until 
 *      a call to FS_set_flags() turns it on or off.  FS_set_flags() can be 
 *      called at any time.  The flags pairs are:
 *      <TABLE>
 *      Flag                                Default              
 *      ---------------------               ---------
 *      FLAGS_CHECK_CONTOUR_WINDINGS_ON     
 *      FLAGS_CHECK_CONTOUR_WINDINGS_OFF	X
 *      FLAGS_CMAP_ON                       X
 *      FLAGS_CMAP_OFF
 *      FLAGS_DROPOUTS_ON              
 *      FLAGS_DROPOUTS_OFF                  X
 *      FLAGS_HINTS_ON                      X
 *      FLAGS_HINTS_OFF
 *      FLAGS_ICON_MAP_ON                   X
 *      FLAGS_ICON_MAP_OFF
 *      FLAGS_SOFTENED_ON
 *      FLAGS_SOFTENED_OFF                  X
 *      FLAGS_VERTICAL_ON               
 *      FLAGS_VERTICAL_OFF                  X
 *      </TABLE>
 *
 *		The CHECK_CONTOUR_WINDINGS flag pair controls whether the 
 *		FS_get_<I>glyph</I> functions perform a check for invalid contour
 *		windings.  See the User Guide for a discussion of this issue.
 *
 *      The CMAP flag pair controls whether the <I>id</I> argument to the
 *      various FS_get_<I>glyph</I> functions is treated as a character code
 *      (FLAGS_CMAP_ON), or a glyph index (FLAGS_CMAP_OFF).  Similarly, it
 *      affects the interpretation of the <I>id</I> arguments to 
 *      FS_get_kerning().  By default, the flag is on.  This flag
 *		does not affect the FS_map_char function.  
 *      Turn off the flag when you are working with glyph indices
 *      directly.  For example, you may wish to first call FS_map_char 
 *		then later call FS_get_<I>glyph</I>.  This is needed when implementing
 *		glyph subsitution methods.
 *  
 *      The DROPOUTS flag pair controls whether to apply extra dropout
 *      protection.  Normally (FLAGS_DROPOUTS_OFF) dropouts are processed
 *      as specified by the font or by an individual character.  To force the
 *      rasterizer to use extra dropout protection, despite what a font or
 *      character specifies, set FLAGS_DROPOUTS_ON.
 *
 *      The HINTS flag pair controls whether hinting is enabled when 
 *      generating characters.  Normally, hinting is enabled 
 *      (FLAGS_HINTING_ON).  To disable hinting set FLAGS_HINTING_OFF.
 *      Disabling hinting may be appropriate in some use cases such as
 *      when displaying moving text.
 *
 *      The ICON_MAP flag pair controls whether the <I>id</I> argument to the
 *      FS_get_<I>icon</I> function is treated as an icon character code
 *      (FLAGS_ICON_MAP_ON), or an ICON table index (FLAGS_ICON_MAP_OFF).  
 *      By default, the icon map is on.  Turning off this map is most
 *      useful for testing purposes.
 *
 *      The SOFTENED flag pair controls whether special filtering is applied
 *		to graymaps: this filtering serves to soften all edges.  
 *		Normally this effect is off.  Set FLAGS_SOFTENED_ON
 *      to obtain this special effect.  Note that the softness effect
 *      cannot be used with phased graymaps.
 *      a special filtering effect.
 *
 *      The VERTICAL flag pair controls whether the glyphs returned
 *      by the FS_get_<I>glyph</I> functions are intended for vertical
 *      layout.  The default is horizontal layout (FLAGS_VERTICAL_OFF).
 *      If FLAGS_VERTICAL_ON is set then glyph metrics are defined
 *      according to vertical, top-to-bottom layout.  An exception
 *      is that this flag does not affect glyphs returned by FS_get_icon().
 *
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      flag        - [in] flag value
 *
 *  Return Value:
 *      SUCCESS, or error code if input is invalid.
 *
 *  Note:
 *      This function sets one flag at a time.  Do not try to set
 *      multiple flags using a bitwise OR on the flags.  Instead,
 *      make one call for each flag that you wish to set.
 *      
 *  <GROUP statecontrol>
 */
ITYPE_API FS_LONG FS_set_flags(_DS_ FS_ULONG flag);


/*****************************************************************************
 *
 *  Sets the amount of emboldening to use (default is 0).
 *
 *  Description:
 *      This function sets the amount of emboldening used when generating
 *      glyphs.  The normal, default value is 0. The function is optional;
 *      if not called glyphs have the normal boldness.
 *
 *      The bold value is expressed as a percentage of the em box in
 *      16.16 fixed point units.  The recommended range is 0-20%.
 *      The valid range is 0-100%.  Thinning the glyph below normal is not
 *      supported.
 *
 *      The emboldening effect achieved here is called 'pseudo bold'.  This
 *      is in contrast to a true bold font which is bold by design.
 *      Pseudo bold is used to save font memory, or when a bold design
 *      of a particular font is not available.  This function will
 *      affect both outline and stroke fonts.
 *
 *      This function must be called before FS_set_scale() to have any
 *      effect.  To change the current boldness you must first call
 *      FS_set_bold_pct() then call FS_set_scale(), even if the scaling
 *      parameters have not changed.
 *
 *      If PSEUDO_BOLD is not defined then then this function will return ERR_BOLD_UNDEF.
 *      
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      pct         - [in] boldness value in 16.16 fixed point notation.
 *
 *  Return Value:
 *      SUCCESS, or ERR_BAD_PERCENT if pct is outside valid range (0-100%).
 *
 *  Version:
 *      Prior to Version 2.1 this function had no effect on stroke fonts.
 *
 *  Examples:
 *      To set the bold percentage to 10% (6554 is 10% of 65536):
 *      <CODE>
 *      FS_set_bold_pct(6554);
 *      </CODE>
 *
 *  Version:
 *		Prior to Version 2.4, if PSEUDO_BOLD was not defined this function would still return SUCCESS.
 *
 *  <GROUP statecontrol>
 */
ITYPE_API FS_LONG FS_set_bold_pct(_DS_ FS_FIXED pct);


/*****************************************************************************
 *
 *  Sets the stroke width as a percentage of the em square (default is 0).
 *
 *  Description:
 *      This function set the stroke width as a percentage of the em square.
 *      The stroke width only affects stroke fonts.  iType uses the
 *      percent value here to compute the actual stroke width, ensuring
 *      that the minimum stroke width is one pixel.
 *
 *      This value should be adjusted to achieve the desired normal weight
 *      of the font.  To get a bold effect, use this function in combination
 *      with FS_set_bold_pct().
 *
 *      The recommended range is 0-12%.  The valid range is 0-50%.
 *
 *      This function must be called before FS_set_scale() to have any
 *      effect.  To change the current boldness you must first call
 *      FS_set_stroke_pct() then call FS_set_scale(), even if the scaling
 *      parameters have not changed.
 *
 *      If STIK is not defined then this function will return ERR_STIK_UNDEF.
 *
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      pct         - [in] stroke width value in 16.16 fixed point notation.
 *
 *  Return Value:
 *      SUCCESS, or error code if input is invalid.
 *
 *  Version:
 *		Prior to Version 2.4, if STIK was not defined this function would still return SUCCESS.
 *
 *  <GROUP statecontrol>
 */
ITYPE_API FS_LONG FS_set_stroke_pct(_DS_ FS_FIXED pct);


/*****************************************************************************
 *
 *  Sets the current scaling matrix. 
 *
 *  Description:
 *      The four arguments form a 2x2 scaling matrix.
 *
 *      The coordinates are computed as follows:
 *          -   x' = x*s00 + y*s01
 *          -   y' = x*s10 + y*s11
 *
 *      For example, the call FS_set_scale(12L<<16, 0, 0, 12L<<16)
 *      specifies a 12 pixel-per-em font, with no rotation or skewing.
 *
 *      For help in creating generalized matrices, look at the
 *      function CSettings::calculate_matrix() in 
 *      samples/win32/wintest/glyphsettings.cpp.
 *      
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      s00         - [in] row 0, column 0
 *      s01         - [in] row 0, column 1
 *      s10         - [in] row 1, column 0
 *      s11         - [in] row 1, column 1
 *
 *  Return Value:
 *      SUCCESS, or error code.
 *
 *      <TABLE>
 *      Error                   Reason
 *      -------------------     -------------------------------------
 *      ERR_NO_CURRENT_LFNT     no current loaded font
 *      ERR_SCALE_LIMIT         characters scale would exceed limit of +/- 16,384).
 *      ERR_SCALE_DEGENERATE    matrix is degenerate
 *      </TABLE>
 *
 *  <GROUP statecontrol>
 */
ITYPE_API FS_LONG FS_set_scale(_DS_ FS_FIXED s00,FS_FIXED s01,FS_FIXED s10,FS_FIXED s11);


/*****************************************************************************
 *
 *  Sets the current cmap table (default is no cmap). 
 *
 *  Description:
 *      The cmap defines the mapping of character value to glyph index.  
 *      The default is 'no cmap', which treats character value as 
 *      glyph index.  This can be useful for testing, but most users
 *      will want to choose a valid cmap.
 *
 *      Choose a cmap based on how you encode characters and on what
 *      cmaps are available in the font, which can be found using FS_font_metrics().
 *      Fonts now typically have a cmap for the Microsoft platform - Unicode encoding, 
 *      designated as platform 3, encoding 1.
 *
 *		Note that the platform does not refer to your target platform, but instead
 *		to one of the platforms registered with the TrueType specification.
 *
 *      If an unsupported cmap is specified, this function returns ERR_CMAP_UNSUPPORTED, and
 *      sets the current cmap to 'no cmap'.  If 'no cmap' is actually desired, then
 *      you may call this function with known invalid values, such as 9999,9999.
 *      The ERR_CMAP_UNSUPPORTED error is still returned, but you will know to ignore it.
 *      Alternatively, note that any call to FS_set_scale() reverts the cmap to its
 *      default 'no cmap' setting.
 *
 *  Parameters:
 *      state       	- [in] pointer to FS_STATE structure
 *		platform		- [in] cmap corresponds with this platform
 *		encoding_type	- [in] cmap encoding (encoding types are platform specific)
 *
 *  Return Value:
 *      SUCCESS, or error code.
 *
 *  Version:
 *      In Version 2.2 and earlier
 *
 *  <GROUP statecontrol>
 */
ITYPE_API FS_LONG FS_set_cmap(_DS_ FS_USHORT platform, FS_USHORT encoding_type);


/*****************************************************************************
 *
 *  Returns a scaled outline glyph.
 *
 *  Description:
 *      This function returns a glyph as a scaled outline.  This glyph form
 *      may be useful for some users, but most will want to use one of the 
 *      functions that also rasterize the glyph such as FS_get_bitmap()
 *      or FS_get_graymap().
 *
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      id          - [in] character value or glyph index
 *
 *  Return Value:
 *      Pointer to FS_OUTLINE structure, or NULL upon error.
 *
 *  See Also:
 *      FS_OUTLINE, FS_free_char(), FS_get_bitmap(), FS_get_graymap()
 *
 *  <GROUP getglyphs>
 */ 
ITYPE_API FS_OUTLINE *FS_get_outline(_DS_ FS_ULONG id);


/*****************************************************************************
 *
 *  Gets pixel coordinates for one or more points that define a scaled
 *  outline glyph.
 *
 *  Description:
 *      This function receives a glyph index and an array of one or more point
 *      indices.  It returns the F26.6 pixel coordinates of the points at
 *      those indices, when the glyph is scaled using the current 
 *      scaling matrix.  The coordinates are returned as arrays.
 *
 *      The user must allocate space for the arrays.
 *
 *      This function is likely used when processing GPOS tables, which reference
 *      by index certain points on the glyph.  The glyph points here are the
 *      original ones stored in the font's glyph table for that glyph index.  You
 *      cannot use an FS_OUTLINE glyph for this purpose because the points may
 *      have been modified from the original.
 *    
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      index       - [in] glyph index
 *      num         - [in] number of points in <I>pts</I>, <I>x</I>, and <I>y</I> arrays
 *      pts         - [in] array of glyph point indices
 *      x_coord     - [out] array of F26DOT6 x-coordinates corresponding with indices in <I>pts</I> array
 *      y_coord     - [out] array of F26DOT6 y-coordinates corresponding with indices in <I>pts</I> array
 *
 *  Return Value:
 *      SUCCESS, or NULL upon error.
 *
 *  <GROUP getglyphinfo>
 */
ITYPE_API FS_LONG FS_get_gpos_pts(_DS_ FS_USHORT index, FS_USHORT num, FS_USHORT *pts, FS_LONG *x_coord, FS_LONG *y_coord);


/*****************************************************************************
 *
 *  Returns a scaled bitmap glyph.
 *
 *  Description
 *      This function returns a glyph as a scaled bitmap.
 *
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      id          - [in] character value or glyph index
 *
 *  Return Value:
 *      Pointer to FS_BITMAP structure, or NULL upon error.
 *
 *  See Also:
 *      FS_BITMAP, FS_free_char() 
 *
 *  <GROUP getglyphs>
 */ 
ITYPE_API FS_BITMAP *FS_get_bitmap(_DS_ FS_ULONG id);


/*****************************************************************************
 *
 *  Returns a scaled graymap glyph.
 *
 *  Description:
 *      This function returns a glyph as a scaled graymap.
 *
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      id          - [in] character value or glyph index
 *
 *  Return Value:
 *      Pointer to FS_GRAYMAP structure, or NULL upon error.
 *
 *  See Also:
 *      FS_GRAYMAP, FS_free_char()
 *
 *  <GROUP getglyphs>
 */ 
ITYPE_API FS_GRAYMAP *FS_get_graymap(_DS_ FS_ULONG id);


/*****************************************************************************
 *
 *  Returns a scaled subpixel bitmap glyph.
 *
 *  Description:
 *      This function returns a glyph as a scaled subpixel bitmap.  
 *      To use this function, SUBPIXEL must be set to SUBPIXEL_BITMAPS.
 *
 *      The subpixel bitmap is a super-sampled bitmap with a 3:1 X-Y 
 *      aspect ratio.  The client must filter this bitmap back to
 *      output format (1:1 X-Y ratio) at display time.  For an example, see 
 *      show_subpixel_bitmap() in <I>samples/win32/wintest</I>.
 *      It was written for clarity rather than speed; it needs to be
 *      optimized for the target graphics environment.
 *
 *      Subpixel rendering (SPR) is a patented technique to obtain higher 
 *      effective resolution on certain types of displays.  The SUBPIXEL setting
 *      and this technique can only be used with a specific subpixel rendering
 *      license from Monotype Imaging.  See the <I>User Guide</I> for more
 *      information regarding SPR.
 *
 *      If SUBPIXEL is not defined as SUBPIXEL_BITMAPS, this function returns 
 *		ERR_SUBPIXEL_UNDEF or ERR_SUBPIXEL_BITMAP_UNDEF.
 *
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      id          - [in] character value or glyph index
 *
 *  Return Value:
 *      Pointer to FS_BITMAP structure, or NULL upon error.
 *
 *  See Also:
 *      FS_BITMAP, FS_free_char()
 *
 *	Version:
 *		Prior to Version 2.4, if SUBPIXEL was not defined as SUBPIXEL_BITMAPS, 
 *		this function returned NULL.
 *
 *  <GROUP getglyphs>
 */ 
ITYPE_API FS_BITMAP *FS_get_subpixel_bitmap(_DS_ FS_ULONG id);


/*****************************************************************************
 *
 *  Returns a scaled subpixel graymap glyph.
 *
 *  Description
 *      This function returns a glyph as a scaled subpixel graymap.
 *      To use this function SUBPIXEL must be set to SUBPIXEL_GRAYMAPS_1 or
 *      SUBPIXEL_GRAYMAPS_2.  The SUBPIXEL setting controls how the 
 *      graymap is generated, and how it should be used.
 *
 *      For SUBPIXEL_GRAYMAPS_1 it creates a super-sampled bitmap with a 
 *      3:1 X-Y ratio, then filters it into a standard iType FS_GRAYMAP
 *      structure with 1:1 X-Y ratio.  This map can be displayed directly.
 *      This type of subpixel rendering (SPR) is the most time-efficient
 *      because filtering is performed only once.  It uses more cache space
 *      than SUBPIXEL_BITMAP because graymaps are larger than bitmaps.
 *
 *      For SUBPIXEL_GRAYMAPS_2 it creates a super-sampled graymap with a 
 *      3:1 X-Y ratio, then filters it into a standard iType FS_GRAYMAP
 *      structure with 1:1 X-Y ratio.  This map can be displayed directly.
 *      This type of SPR produces the highest quality output, but is 
 *      slower than SUBPIXEL_GRAYMAPS_1 because the filtering is more
 *      complex.  SUBPIXEL_GRAYMAPS_1 and SUBPIXEL_GRAYMAPS_2 use the
 *      same cache space.
 *
 *      For an example of how to display the graymaps returned by this 
 *      function, see show_subpixel_graymap() in <I>samples/win32/wintest</I>.
 *      It was written for clarity rather than speed; it needs to be
 *      optimized for the target graphics environment.
 *
 *      Subpixel rendering (SPR) is a patented technique to obtain higher 
 *      effective resolution on certain types of displays.  The SUBPIXEL setting
 *      and this technique can only be used with a specific subpixel rendering
 *      license from Monotype Imaging.  See the <I>User Guide</I> for more
 *      information regarding SPR.
 *
 *      If SUBPIXEL is not defined as SUBPIXEL_GRAYMAPS_1 or SUBPIXEL_GRAYMAPS_2,
 *		this function returns ERR_SUBPIXEL_UNDEF or ERR_SUBPIXEL_GRAYMAP_UNDEF.
 *
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      id          - [in] character value or glyph index
 *
 *  Return Value:
 *      Pointer to FS_GRAYMAP structure, or NULL upon error.
 *
 *  See Also:
 *      FS_GRAYMAP, FS_free_char()
 *
 *	Version:
 *		Prior to Version 2.4, if SUBPIXEL was not defined as 
 *		SUBPIXEL_GRAYMAPS_1 or SUBPIXEL_GRAYMAPS_2, this function returned NULL.
 *
 *  <GROUP getglyphs>
 */ 
ITYPE_API FS_GRAYMAP *FS_get_subpixel_graymap(_DS_ FS_ULONG id);


/*****************************************************************************
 *
 *  Returns a scaled, phased graymap glyph.
 *
 *  Description:
 *      This function returns a glyph as a graymap that was generated using
 *      the "phased" grayscale algorithm (phasing).
 *
 *      Phasing effectively allows apparent character positioning at ¼ pixel
 *      intervals, and stem weight resolution of ¼ pixel.  In order to obtain this effect,
 *      the line composition algorithm must pass a high-resolution x-position parameter
 *      to FS_get_phased() – this parameter is used to select the appropriate version
 *      of the phased gray map for the character.
 *
 *      Phasing may be appropriate for certain types of display devices.
 *      It is not recommended for general use, however, as it eliminates most
 *      of the benefits of hinting.
 *
 *      Phasing is not the same thing as subpixel rendering.
 *
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      id          - [in] character value or glyph index
 *      xpos        - [in] x axis position of the origin in fractional pixels
 *
 *  Return Value:
 *      Pointer to FS_GRAYMAP structure, or NULL upon error.
 *
 *  See Also:
 *      FS_GRAYMAP, FS_free_char()
 *
 *  Notes:
 *      To use this function, turn on the PHASED build option.  If PHASED is not 
 *      defined, this function returns a ERR_PHASED_UNDEF error.
 *
 *  <GROUP getglyphs>
 */ 
ITYPE_API FS_GRAYMAP *FS_get_phased(_DS_ FS_ULONG id, FS_FIXED xpos);


/*****************************************************************************
 *
 *  Returns an icon glyph.
 *
 *  Description:
 *      This function returns a glyph as an icon.  This function will
 *      return an error if the current font does not contain an ICON
 *      table.  See FS_ICON and the <I>User's Guide</I> for a more on 
 *      the icons feature.
 *
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      id          - [in] character value or glyph index
 *
 *  Return Value:
 *      Pointer to FS_ICON structure, or NULL upon error.
 *
 *  See Also:
 *      FS_ICON, FS_free_char()
 *
 *  <GROUP getglyphs>
 */ 
ITYPE_API FS_ICON *FS_get_icon(_DS_ FS_ULONG id);


/*****************************************************************************
 *
 *  Releases a glyph reference.
 *
 *  Description:
 *      The user must call this function to release a glyph that was
 *      obtained using any of the get_<I>glyph</I> functions.
 *
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      p           - [in] reference to a glyph
 *
 *  Return Value:
 *      SUCCESS, or NULL upon error.
 *
 *  <GROUP getglyphs>
 */
ITYPE_API FS_LONG FS_free_char(_DS_ FS_VOID *p);


/*****************************************************************************
 *
 *  Attempts to resize the engine heap.
 *
 *  Description:
 *      This function changes the maximum amount of RAM that can
 *      be used by the engine heap when using the external memory
 *      model.
 *
 *      The heap size can be increased or decreased.  Increasing
 *      heap size changes the maximum allowed value.  It does 
 *      not actually allocate any memory.  Decreasing heap size
 *      frees memory as necessary to meet the requested size. 
 *      It does this by trimming the font and glyph caches
 *      until the heap usage is less than the requested heap size.
 *
 *      When using the INT_MEM (internal) memory model,
 *      this function returns an error.  To resize the heap
 *      you must exit using FS_exit() then restart using FS_init()
 *      with the new size.  All fonts would need to be added again.
 *    
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      new_size    - [in] the requested new amount of maximum amount of RAM,
 *                         in bytes, that the engine should use for its heap
 *
 *  Return value:
 *      SUCCESS, or ERR_RESIZE_FAILED if the heap could not be reduced
 *      to the requested size, or if the INT_MEM model is being used.
 *  
 *  <GROUP admin>
 */
ITYPE_API FS_LONG FS_resize(_DS_ FS_ULONG new_size);


/*****************************************************************************
 *
 *  Shuts down an iType server.
 *
 *  Description:
 *      This function should generally be called 
 *		only once per server,
 *      upon shutdown of whichever system was used
 *      to call FS_init(). There are some differences in
 *		the MULTI_PROCESS case.
 *
 *      FS_exit does the following
 *		(unconditionally, in the non-MULTI_PROCESS case):
 *		- deletes all cached and temporary objects
 *      - closes all font files
 *      - destroys the server, which frees all heap memory and frees
 *        the server structure.
 *
 *		In the MULTI_PROCESS case, all mapped fonts are deleted, but the
 *		remaining cleanup takes place only when it is the last active process
 *		that calls FS_exit().
 *
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *
 *  Return value:
 *      Always returns SUCCESS.
 *
 *  Notes:     
 *		If MULTI_PROCESS is defined then each process will call FS_exit()
 *		when it completes. The behavior of FS_exit() will vary depending on
 *		whether there are any active processes other than the process that
 *		called FS_exit().
 *       
 *		If MULTI_THREAD is defined then only the master client
 *      should call FS_exit().  Other clients must first call FS_end_client().
 *      It is an unchecked run-time error for a non-master client
 *      to call FS_exit().
 *
 *      If REENTRANT is defined, the master client is responsible for
 *      deleting the FS_STATE structure after calling FS_exit().
 *
 *      It is an unchecked run-time error to make any iType call
 *      after having called FS_exit() for a particular iType instance.
 *
 *  See also:
 *      FS_init(), FS_new_client(), FS_end_client(), FS_STATE
 *
 *  <GROUP admin>
 */   
ITYPE_API FS_LONG FS_exit(_DS0_);


/*****************************************************************************
 *
 *  Adds a font to the current list of known fonts.
 *
 *  Description:
 *      The iType engine maintains a list of known fonts.  This function is
 *      used to add a font to that list.
 *
 *      For our purposes, a "font" is a file that complies with the TrueType
 *      format, or any of the TrueType extensions supported by iType, 
 *		or a PFR Format 0 font.
 *
 *      The file may be file system-based or memory mapped.  iType works
 *      more efficiently with memory-mapped files, both in terms of speed
 *      and heap usage.  This is true even if the file system is memory-based,
 *      which is common with embedded systems.
 *
 *      The name parameter is a client-supplied string.  The string must
 *      be used later to set the current font, using FS_set_font(), or to 
 *      delete a font using FS_delete_font().
 *
 *		If an application calls FS_add_font() with a NULL name, iType will use 
 *		FS_font_name() to obtain an appropriate name for the font, and add it
 *		under that name.  However, it would be preferable to use FS_load_font()
 *		in such cases, or for the application to call FS_font_name() directly
 *		to obtain a font name, and pass that name to FS_add_font().
 *		      
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      name        - [in] user supplied null terminated string that
 *                         defines name of the font.
 *      path        - [in] path name of font when font is file system based.
 *                         If memptr is defined this argument should be NULL.
 *      memptr      - [in] address of font when font is memory-mapped in FLASH_ROM, ROM, or RAM.
 *                         If path is defined then this argument should be NULL.
 *      index       - [in] generally this should be set to 0, unless the font is a 
 *                         TrueType collection, in which case this should be set to the
 *                         index of the desired font within the collection.
 *
 *  Return Value:
 *      SUCCESS, or error code if font could not be added.
 *
 *      <TABLE>
 *      Return values           	Reason
 *      ------------------      	--------------------------------
 *      ERR_FONT_NOT_FOUND      	Both the 'path' and 'memptr' inputs were NULL
 *		ERR_FONT_NAME_IN_USE		A different font (with the same name) is already in the list of known fonts
 *      ERR_FONT_NAME_NOT_UNIQUE    The same font (with a different nane) is already in the list of known fonts
 *      </TABLE>
 *
 *  Notes:
 *      iType treats each font within a TrueType collection as a separate font.
 *      You may call this function once for each of the fonts in the collection, 
 *      using the same path or memptr argument.  Each call requires a unique font
 *      <I>name</I> as well as the unique collection <I>index</I> for that font.
 *      The number of fonts in a collection can be found the FONT_METRICS structure
 *      returned by FS_font_metrics().
 *
 *  See Also:
 *      FS_delete_font(), FS_font_name(), FS_load_font()
 *
 *  <GROUP fontmanagement>
 */  
ITYPE_API FS_LONG FS_add_font(_DS_ FILECHAR *name, FILECHAR *path, FS_BYTE *memptr, FS_ULONG index);


/*****************************************************************************
 *
 *  Return font name given in the font's name table
 *
 *  Description:
 *		The function FS_font_name() returns the name in a font's name table. 
 *		This function can be used by an application (or by iType, internally)
 *		to obtain an appropriate name for a font to be added to the list of
 *		known fonts, via FS_add_font() or FS_load_font().
 *
 *      The caller must allocate space for the <I>name</I> name-buffer.
 *      The <I>name_len</I> should be at least 2 bytes although a larger
 *      value is recommended, up to MAX_FONT_NAME_LEN.
 *
 *		An error will be returned if the font could not be loaded, if the 
 *		allocated buffer was too small, or if no name was found.
 *    
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      path        - [in] path name of font when font is file system based.
 *                         If memptr is defined this argument should be NULL.
 *      memptr      - [in] address of font when font is memory-mapped in ROM or RAM.
 *                         If path is defined then this argument should be NULL.
 *      index       - [in] generally this should be set to 0, unless the font is a 
 *                         TrueType collection, in which case this should be set to the
 *                         index of the desired font within the collection.
 *      name_len    - [in] length of <I>name</I> buffer in bytes, min = 2, max = MAX_FONT_NAME_LEN
 *      name        - [out] buffer that will contain returned font name as null terminated string
 *							(allocated by caller)

 *  Return value:
 *      Error code
 *      
 *  See Also:
 *      FS_add_font(), FS_load_font()
 *
 *  Version:
 *      This function was new with iType 2.4. 
 *
 *  <GROUP fontmanagement>
 */
ITYPE_API FS_LONG FS_font_name(_DS_ FILECHAR *path, FS_BYTE *memptr, FS_ULONG index, FS_ULONG name_len, FILECHAR *name);


/*****************************************************************************
 *
 *  Adds a font to the current list of known fonts and returns font name.
 *
 *  Description:
 *      The iType engine maintains a list of known fonts.  This function is
 *      used to add a font to that list.  It is similar to FS_add_font()
 *      except that instead of specifying a name for the font, the name is 
 *      extracted from the font itself (by calling FS_font_name()), 
 *		and returned via an argument.
 *
 *      The caller must allocate space for the <I>name</I> name-buffer.
 *      The <I>name_len</I> should be at least 2 bytes although a larger
 *      value is recommended, up to MAX_FONT_NAME_LEN.  The name 
 *      is guaranteed to be different from that of other loaded/added fonts.
 *      The font name is ideally the name found in the font, but it may have
 *      be modified to be made unique or to fit into the <I>name</I> buffer.
 *
 *      In the very unlikely event that the name cannot be unique and fit into
 *      the buffer, the function returns an error, and will not unload the font.
 *      
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      path        - [in] path name of font when font is file system based.
 *                         If memptr is defined this argument should be NULL.
 *      memptr      - [in] address of font when font is memory-mapped in ROM or RAM.
 *                         If path is defined then this argument should be NULL.
 *      index       - [in] generally this should be set to 0, unless the font is a 
 *                         TrueType collection, in which case this should be set to the
 *                         index of the desired font within the collection.
 *      name_len    - [in] length of <I>name</I> buffer in bytes, min = 2, max = MAX_FONT_NAME_LEN
 *      name        - [out] buffer containing returned font name as null terminated string
 *
 *  Return Value:
 *      SUCCESS, or error code if font could not be added.
 *
 *      <TABLE>
 *      Return values           	Reason
 *      ------------------      	--------------------------------
 *      ERR_FONT_NOT_FOUND      	Both the 'path' and 'memptr' inputs were NULL
 *      ERR_FONT_BUFFER_TOO_SMALL   Buffer supplied is too small to hold the font name that was generated
 *      ERR_DUPLICATED_FONT_NAME    Could not generate a font name (internal error)
 *      </TABLE>
 *
 *  See Also:
 *      FS_add_font(), FS_delete_font()
 *
 *  <GROUP fontmanagement>
 */  
ITYPE_API FS_LONG FS_load_font(_DS_ FILECHAR *path, FS_BYTE *memptr, FS_ULONG index, FS_ULONG name_len, FILECHAR *name);


/*****************************************************************************
 *
 *  Deletes a font from the current list of known fonts.
 *
 *  Description:
 *      The iType engine maintains a list of known fonts.  This function is
 *      used to delete a font from that list. Actually, the reference count of
 *		the font is decremented - the font will be eligible for deletion after
 *		its reference count goes to zero (so that the same font can be used
 *		safely by multiple clients).     
 *
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      name        - [in] font name as null terminated string.
 *                         This is the name that was used with FS_add_font().
 *
 *  Return Value:
 *      SUCCESS, or error code if font could not be deleted.
 *
 *      <TABLE>
 *      Return values           Reason
 *      ------------------      --------------------------------
 *      ERR_FONT_NOT_FOUND      font by that name is not found
 *      ERR_DELETE_FONT         reference count for that font is already zero
 *      </TABLE>
 *
 *  See Also:
 *      FS_set_font(), FS_add_font().
 *
 *  <GROUP fontmanagement>
 */ 
ITYPE_API FS_LONG FS_delete_font(_DS_ FILECHAR *name);


/*****************************************************************************
 *
 *  Gets font-specific metrics. 
 *
 *  Description:
 *      This function initializes a FONT_METRICS structure using the
 *      current font.  The structure must be allocated by the calling program.
 *
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      fm          - [out] pointer to a font metrics structure declared by caller.
 *
 *  Return Value:
 *      SUCCESS, or error code.
 *
 *  See Also:
 *      FONT_METRICS.
 *
 *  <GROUP fontinfo>
 */
ITYPE_API FS_LONG FS_font_metrics(_DS_ FONT_METRICS *fm);


/*****************************************************************************
 *
 * Get parsed table contents for some TrueType tables
 *
 *  Description:
 *		This function returns TrueType table information for certain tables
 *		(as parsed data structures, rather than as raw TrueType tables).
 *		This table information is already used by iType internally - we simply
 *		give the user's application access to the same information (in order
 *		to perform composition and layout operations, for example). 
 *
 *		The calling application is responsible for allocating a pointer to an
 *		area of the appropriate size, and freeing the memory when it is done: 
 *		iType will simply copy the requested information into that area.
 *
 *		An error will be returned if there is no current loaded font, or 
 *		if the requested table was not found.  
 *    
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      tag         - [in] 4-byte character tag for table to be retrieved:
 *					  one of TAG_head, TAG_hhea, TAG_vhea, TAG_maxp, TAG_OS2,
 *					  or TAG_name
 *		tableptr	- [out] pointer to area that will hold table information: 
 *					  allocated as one of sizeof(TTF_HEAD), sizeof(TTF_HHEA),
 *					  sizeof(TTF_VHEA), sizeof(TTF_MAXP), sizeof(TTF_OS2),  
 *					  or sizeof(TTF_NAME).
 *
 *  Return value:
 *      Error code
 *
 *	Notes:
 *		The tables that can currently be retrieved are: 
 *			head, hhea, vhea, maxp, OS/2, and name.
 * 
 *		The information in the name-table structure is not a complete copy of
 *		the TrueType name table; rather, it is the portion of the table that
 *		is used by iType. If you need access to the complete name table, you
 *		will need to load the table via FS_get_table(), and parse it yourself.
 *
 *	See Also:
 *		FS_get_table()
 *      
 *  Version:
 *      This function was new with iType 2.4. 
 *
 *  <GROUP fontinfo>
 */
ITYPE_API FS_LONG FS_get_table_structure(_DS_ FS_ULONG tag, FS_VOID *tableptr);


/*****************************************************************************
 *
 *  Get effective minimum and maximum Y values
 *
 *  Description:
 *		The API function FS_get_vdmx_pair() will get the ymin and ymax
 *		pair, if any exists, from the VDMX table in the current font at the
 *		current scale. These values are the highest ascender and 
 *		lowest descender that will be returned for any glyph.
 *    
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *		yMax		- [out] pointer to maximum Y value obtained
 *		yMin		- [out] pointer to minimum Y value obtained
 *
 *  Return Value:
 *      SUCCESS, or error code if information could not be obtained.
 *
 *      <TABLE>
 *      Return values             Reason
 *      ------------------------  ----------------------------------
 *      ERR_NO_CURRENT_LFNT       No current loaded font
 *		ERR_NO_CURRENT_SFNT		  No current scaled font
 *		ERR_TABLE_NOT_FOUND		  The font does not have a VDMX table
 *		ERR_TABLE_UNSUPPORTED	  The PFR format does not support VDMX information
 *		ERR_VDMX_RATIO			  Current x/y aspect ratio is not in the table	
 *      ERR_yPelHeight_NOT_FOUND  Current y scaling (in pixels) is not in the table
 *      ERR_NOT_VANILLA           Current scaling is rotated or obliqued
 *      </TABLE>
 *
 *	Notes:
 *		Because values such as usWinAscent and usWinDescent can be inaccurate
 *		due to TrueType instructions causing rounding and hinting differences,
 *		the VDMX table was defined. This table, if it exists in a font, can 
 *		provide exact y-dimension max and min for a given size. The values
 *		returned are the same as if the user rendered each every glyph in the
 *		font at the current size and recorded the highest and lowest y-values.
 *		There can be multiple sets of data in the table for a single font, 
 *		so a match must be found based on the current scaling.
 *
 *		The values in the VDMX table are not guaranteed to be reliable if 
 *		rotation or obliquing is in effect, so an error code is returned
 *		if any of these are enabled when the VDMX query function is called.
 *
 *  Version:
 *      This function was new with iType 2.4. 
 *
 *  <GROUP getglyphinfo>
 */
ITYPE_API FS_LONG FS_get_vdmx_pair(_DS_ FS_SHORT *yMax, FS_SHORT *yMin);


/*****************************************************************************
 *
 *  Returns the current version of iType. 
 *
 *  Description:
 *      The version is returned as a single FS_ULONG.  The upper 16 bits
 *      give the major version, typically a small integer.  The lower
 *      16 bits give the minor version as a multiple of 100 to allow
 *      for interim releases.
 *
 *      For example, in version 2.4 the major version is set to 2 and the
 *      minor version is set to 400.
 *    
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *
 *  Return value:
 *      Version number
 *      
 *  <GROUP admin>
 */
ITYPE_API FS_ULONG FS_get_version(_DS0_);


/*****************************************************************************
 *
 *  How much runtime-allocated memory are we using?
 *    
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *
 *  Return value:
 *      Current amount of heap used (in bytes)
 *      
 *  Version:
 *      This function was new with iType 2.4. 
 *
 *  <GROUP fsmemmgr>
 */
ITYPE_API FS_ULONG FS_get_heap_used(_DS0_);


/*****************************************************************************
 *
 *  Maps a character value through current cmap, returning a glyph index.
 *
 *  Description:
 *      This function is used to translate an input character id 
 *      (typically a Unicode value) into a glyph-index value. 
 *      The current font and current cmap are used to obtain the glyph-index
 *      value.
 *
 *      If a cmap entry for this id does not exist, it returns the
 *      'missing glyph index', which is usually 0.  This function is not 
 *      affected by the status of the FLAGS_CMAP_OFF/FLAGS_CMAP_ON flags.
 *
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      id          - [in] character value
 *
 *  Return Value:
 *      Glyph index.
 *
 *  <GROUP getglyphinfo>
 */
ITYPE_API FS_USHORT FS_map_char(_DS_ FS_ULONG id);


/*****************************************************************************
 *
 *  Returns the kerning adjustment for a character pair.
 *
 *  Description:
 *      Kerning is an adjustment to nominal glyph spacing that takes
 *      into account the character pair.  The <I>id</I> arguments are
 *      treated as character value if FLAGS_CMAP_ON is set (the default),
 *      and as glyph index if FLAGS_CMAP_OFF is set.
 *
 *      This kerning applies to horizontal text layout.  Assuming no text
 *      rotation, the <I>id1</I> argument is always the character to the left, 
 *      regardless of whether the text reads left-to-right or right-to-left.
 *
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      id1         - [in] character value or glyph index of first character
 *      id2         - [in] character value or glyph index of second character
 *      _dx         - [out] returns x-direction kerning adjustment as 16.16 fixed point number 
 *      _dy         - [out] returns y-direction kerning adjustment as 16.16 fixed point number
 *
 *  Return Value:
 *      SUCCESS, or NULL upon error.
 *
 *  <GROUP getglyphinfo>
 */
ITYPE_API FS_LONG FS_get_kerning(_DS_ FS_ULONG id1, FS_ULONG id2, FS_FIXED *_dx, FS_FIXED *_dy);


/*****************************************************************************
 *
 *  Resizes a block of memory within the iType heap.
 *      
 *  Description:
 *      This function resizes a block of memory that was obtained
 *      using a previous call to FS_malloc(), FS_calloc(), or FS_resize().
 *
 *      If this function is successful, the contents of the old block
 *      are copied to the new memory block.  If the function fails
 *      then the old pointer is still valid.
 *
 *  Notes:     
 *      You must use FS_free() to release this memory.
 *
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      p           - [in] pointer to existing block of memory
 *      n           - [in] new size in bytes
 *
 *  Return Value:
 *      Pointer to a block of memory, or NULL if the new block
 *      could not be allocated.
 *
 *  <GROUP fsmemmgr>
 */
ITYPE_API FS_BYTE *FS_realloc(_DS_ FS_VOID * p, FS_ULONG n);


/*****************************************************************************
 *
 *  Frees a block of memory within the iType heap.
 *      
 *  Description:
 *      This function frees a block of memory that was obtained
 *      using a previous call to FS_malloc(), FS_calloc(), or FS_resize().
 *
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      p           - [in] pointer to memory block
 *
 *  Return Value:
 *      SUCCESS, or error code.
 *
 *  <GROUP fsmemmgr>
 */
ITYPE_API FS_LONG FS_free(_DS_ FS_VOID *p);


/*****************************************************************************
 *
 *  Returns a reference to a font table.
 *
 *  Description:
 *      When <I>mode</I> is defined as TBL_EXTRACT
 *      this function allows the user to retrieve the raw data of any 
 *      TrueType table, specified by <I>tag</I>, from the current font.
 *      The function returns a reference to the table, not a copy.
 *      If the return value is NULL then there was an error.  Use
 *      FS_error() to determine what went wrong.
 *
 *      When finished, the user must release the reference using
 *      TS_free_table().  Do not use FS_free.
 *
 *      When <I>mode</I> is defined as TBL_QUERY
 *      this function allows the user to query whether a 
 *      TrueType table, specified by <I>tag</I>, exists in the 
 *      current font.  The function returns '1' if the table exists,
 *      else it returns '0'.
 *      
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      tag         - [in] 4-byte character tag value
 *      mode        - [in] indicates mode of this call 
 *      len         - [out] pointer to size of table in bytes
 *
 *  Return Value:
 *      Reference to a font table, or boolean value.
 *
 *	See Also:
 *		FS_get_table_structure()
 *
 *  <GROUP fontinfo>
 */
ITYPE_API FS_BYTE *FS_get_table(_DS_ FS_ULONG tag, FS_BYTE mode, FS_ULONG *len);


/*****************************************************************************
 *
 *  Frees a font table reference.
 *
 *  Description:
 *      This function frees a table reference that was returned by 
 *      FS_font_table() using the TBL_EXTRACT mode.
 *      
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      p           - [in] pointer to font table
 *
 *  Return Value:
 *      SUCCESS, or error code.
 *
 *  <GROUP fontinfo>
 */
ITYPE_API FS_LONG FS_free_table(_DS_ FS_VOID *p);


/*****************************************************************************
 *
 *  Constructs a new iType client.
 *
 *  Description:
 *      This function constructs a new iType client.  You must pass
 *      it a pointer to a valid, previously initialized client.
 *      That "seed" client may have come from a previous call to FS_init()
 *      or FS_new_client().
 *
 *      This function allocates a new client (FS_STATE) structure using iType heap
 *      memory, initializes the new client data, attaches to the
 *      same iType server as used by the "seed" client, and returns a pointer
 *      to the new client.  This function must be matched with a call to
 *      the destructor, FS_end_client().
 *
 *      This function is only available when MULTI_THREAD is defined.
 *      It can be used to support multiple threads with shared data.  It is
 *      also useful within a single thread, when the client application has
 *      an object model that benefits from each graphics object having its
 *      own iType client, while sharing the same server data.
 *
 *  Parameters:
 *      state       - [in] pointer to a valid, previously initialized FS_STATE structure
 *      heapsize   - [in] the increase in heap_size recommended by this client
 *
 *  Return value:
 *      Pointer to the new client, an FS_STATE structure.
 *
 *  Notes:
 *       This function is only available if MULTI_THREAD is defined.
 *
 *      The heap size parameter is the reocmmended increase in the server's current
 *      heap size.  The function adds this value to the current heap size and attempts
 *      to resize the heap to the total.  In most cases, this value should be 0, because
 *      the contents of the heap are shared among the various clients.
 *
 *  See also:
 *      FS_end_client(), FS_init(), FS_STATE
 *
 *  Version:
 *      This function was new with iType 2.3. 
 *  
 *  <GROUP admin>
 */
ITYPE_API FS_STATE *FS_new_client(_DS_ FS_ULONG heapsize);


/*****************************************************************************
 *
 *  Destroys an iType client.
 *
 *  Description:
 *      This function is the destructor for iType clients that were 
 *      constructed using FS_new_client().
 *
 *      Before calling this function, all glyph and table references that
 *      were returned by this client, must be freed using FS_free_char() 
 *      and FS_free_table(), respectively.  If these references are not
 *      freed, the memory associated with them will remain un-available
 *      until the iType is completely exited using FS_exit().
 *
 *      Once this function is called, the state pointer is invalid.  If it
 *      is to remain in scope, it should be assigned to NULL.
 *
 *  Parameters:
 *      state       - [in] pointer to the FS_STATE structure to be destroyed
 *
 *  Return value:
 *      SUCCESS, or an iType error code if the engine could not be destroyed.
 *
 *  Notes:
 *      This function is only available if MULTI_THREAD is defined.
 *
 *  See also:
 *      FS_new_client(), FS_init(), FS_STATE
 *
 *  Version:
 *      This function was new with iType 2.3. 
 *  
 *  <GROUP admin>
 */
ITYPE_API FS_ULONG FS_end_client(_DS0_);


/*****************************************************************************
 *
 *  Obtains a block of memory from the iType heap and
 *  initializes it to zeros.
 *      
 *  Notes:
 *      You must use FS_free() to release this memory.
 *
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      n           - [in] size of block to allocate, in bytes
 *
 *  Return Value:
 *      Pointer to a block of memory, or NULL if error.
 *
 *  <GROUP fsmemmgr>
 */
ITYPE_API FS_BYTE *FS_calloc(_DS_ FS_ULONG n);


/*****************************************************************************
 *
 *  Obtains a block of memory from the iType heap.
 *      
 *  Notes:
 *      You must use FS_free() to release this memory.
 *
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *      n           - [in] size of block to allocate, in bytes
 *
 *  Return Value:
 *      Pointer to a block of memory, or NULL on error.
 *
 *  <GROUP fsmemmgr>
 */
ITYPE_API FS_BYTE *FS_malloc(_DS_ FS_ULONG n);


/*****************************************************************************
 *
 *  Retrieves the current set of flags in effect.
 *
 *  Parameters:
 *      state       - [in] pointer to FS_STATE structure
 *
 *  Return value:
 *      Current flags word (user will need to parse bit values)
 * 
 *	See Also:
 *		FS_set_flags()
 *      
 *  <GROUP statecontrol>
 */
ITYPE_API FS_LONG FS_get_flags(_DS0_);


/* also ... need to see the single thread versions too, but they are not part of API */
FS_LONG FSS_init(_DS_ FS_ULONG heapsize);
FS_LONG FSS_error(_DS0_);
FS_LONG FSS_set_font(_DS_ FILECHAR *name);
FS_LONG FSS_set_flags(_DS_ FS_ULONG flag);
FS_LONG FSS_set_bold_pct(_DS_ FS_FIXED pct);
FS_LONG FSS_set_stroke_pct(_DS_ FS_FIXED pct);
FS_LONG FSS_set_scale(_DS_ FS_FIXED s00,FS_FIXED s01,FS_FIXED s10,FS_FIXED s11);
FS_LONG FSS_set_cmap(_DS_ FS_USHORT platform, FS_USHORT encoding);
FS_OUTLINE *FSS_get_outline(_DS_ FS_ULONG id);
FS_LONG FSS_get_gpos_pts(_DS_ FS_USHORT index, FS_USHORT num, FS_USHORT *pts, FS_LONG *x, FS_LONG *y);
FS_BITMAP *FSS_get_bitmap(_DS_ FS_ULONG id);
FS_GRAYMAP *FSS_get_graymap(_DS_ FS_ULONG id);
FS_BITMAP *FSS_get_subpixel_bitmap(_DS_ FS_ULONG id);
FS_GRAYMAP *FSS_get_subpixel_graymap(_DS_ FS_ULONG id);
FS_GRAYMAP *FSS_get_phased(_DS_ FS_ULONG id, FS_FIXED xpos);
FS_ICON *FSS_get_icon(_DS_ FS_ULONG id);
FS_VOID FSS_free_char(_DS_ FS_VOID *p);
FS_LONG FSS_resize(_DS_ FS_ULONG newsize);
FS_LONG FSS_exit(_DS0_);
FS_LONG FSS_add_font(_DS_ FILECHAR *name, FILECHAR *path, FS_BYTE *memptr, FS_ULONG index);
FS_LONG FSS_font_name(_DS_ FILECHAR *path, FS_BYTE *memptr, FS_ULONG index, FS_ULONG name_len, FILECHAR *name);
FS_LONG FSS_load_font(_DS_ FILECHAR *path, FS_BYTE *memptr, FS_ULONG index, FS_ULONG name_len, FILECHAR *name);
FS_LONG FSS_delete_font(_DS_ FILECHAR *name); 
FS_LONG FSS_font_metrics(_DS_ FONT_METRICS *fm);
FS_LONG FSS_get_table_structure(_DS_ FS_ULONG tag, FS_VOID *tableptr);
FS_LONG FSS_get_vdmx_pair(_DS_ FS_SHORT *yMax, FS_SHORT *yMin);
FS_ULONG FSS_get_version(_DS0_);
FS_ULONG FSS_get_heap_used(_DS0_);
FS_USHORT FSS_map_char(_DS_ FS_ULONG id);
FS_LONG FSS_get_kerning(_DS_ FS_ULONG id1, FS_ULONG id2, FS_FIXED *_dx, FS_FIXED *_dy);
FS_BYTE *FSS_get_table(_DS_ FS_ULONG tag, FS_BYTE mode, FS_ULONG *len);
FS_LONG FSS_free_table(_DS_ FS_VOID *p);
FS_BYTE *FSS_calloc(_DS_ FS_ULONG n);
FS_BYTE *FSS_malloc(_DS_ FS_ULONG n);
FS_BYTE *FSS_realloc(_DS_ FS_VOID *p, FS_ULONG n);
FS_LONG FSS_free(_DS_ FS_VOID * p);
FS_LONG FSS_get_flags(_DS0_);

#else /* single threaded */
/* single threaded API calls */
ITYPE_API FS_LONG FSS_init(_DS_ FS_ULONG heapsize);
ITYPE_API FS_LONG FSS_error(_DS0_);
ITYPE_API FS_LONG FSS_set_font(_DS_ FILECHAR *name);
ITYPE_API FS_LONG FSS_set_flags(_DS_ FS_ULONG flag);
ITYPE_API FS_LONG FSS_set_bold_pct(_DS_ FS_FIXED pct);
ITYPE_API FS_LONG FSS_set_stroke_pct(_DS_ FS_FIXED pct);
ITYPE_API FS_LONG FSS_set_scale(_DS_ FS_FIXED s00,FS_FIXED s01,FS_FIXED s10,FS_FIXED s11);
ITYPE_API FS_LONG FSS_set_cmap(_DS_ FS_USHORT platform, FS_USHORT encoding);
ITYPE_API FS_OUTLINE *FSS_get_outline(_DS_ FS_ULONG id);
ITYPE_API FS_LONG FSS_get_gpos_pts(_DS_ FS_USHORT index, FS_USHORT num, FS_USHORT *pts, FS_LONG *x, FS_LONG *y);
ITYPE_API FS_BITMAP *FSS_get_bitmap(_DS_ FS_ULONG id);
ITYPE_API FS_GRAYMAP *FSS_get_graymap(_DS_ FS_ULONG id);
ITYPE_API FS_BITMAP *FSS_get_subpixel_bitmap(_DS_ FS_ULONG id);
ITYPE_API FS_GRAYMAP *FSS_get_subpixel_graymap(_DS_ FS_ULONG id);
ITYPE_API FS_GRAYMAP *FSS_get_phased(_DS_ FS_ULONG id, FS_FIXED xpos);
ITYPE_API FS_ICON *FSS_get_icon(_DS_ FS_ULONG id);
ITYPE_API FS_VOID FSS_free_char(_DS_ FS_VOID *p);
ITYPE_API FS_LONG FSS_resize(_DS_ FS_ULONG newsize);
ITYPE_API FS_LONG FSS_exit(_DS0_);
ITYPE_API FS_LONG FSS_add_font(_DS_ FILECHAR *name, FILECHAR *path, FS_BYTE *memptr, FS_ULONG index);
ITYPE_API FS_LONG FSS_font_name(_DS_ FILECHAR *path, FS_BYTE *memptr, FS_ULONG index, FS_ULONG name_len, FILECHAR *name);
ITYPE_API FS_LONG FSS_load_font(_DS_ FILECHAR *path, FS_BYTE *memptr, FS_ULONG index, FS_ULONG name_len, FILECHAR *name);
ITYPE_API FS_LONG FSS_delete_font(_DS_ FILECHAR *name); 
ITYPE_API FS_LONG FSS_font_metrics(_DS_ FONT_METRICS *fm);
ITYPE_API FS_LONG FSS_get_table_structure(_DS_ FS_ULONG tag, FS_VOID *tableptr);
ITYPE_API FS_LONG FSS_get_vdmx_pair(_DS_ FS_SHORT *yMax, FS_SHORT *yMin);
ITYPE_API FS_ULONG FSS_get_version(_DS0_);
ITYPE_API FS_ULONG FSS_get_heap_used(_DS0_);
ITYPE_API FS_USHORT FSS_map_char(_DS_ FS_ULONG id);
ITYPE_API FS_LONG FSS_get_kerning(_DS_ FS_ULONG id1, FS_ULONG id2, FS_FIXED *_dx, FS_FIXED *_dy);
ITYPE_API FS_BYTE *FSS_get_table(_DS_ FS_ULONG tag, FS_BYTE mode, FS_ULONG *len);
ITYPE_API FS_LONG FSS_free_table(_DS_ FS_VOID *p);
ITYPE_API FS_BYTE *FSS_calloc(_DS_ FS_ULONG n);
ITYPE_API FS_BYTE *FSS_malloc(_DS_ FS_ULONG n);
ITYPE_API FS_BYTE *FSS_realloc(_DS_ FS_VOID *p, FS_ULONG n);
ITYPE_API FS_LONG FSS_free(_DS_ FS_VOID * p);
ITYPE_API FS_LONG FSS_get_flags(_DS0_);

/* change the name to protect the innocent */
#define FS_init FSS_init
#define FS_error FSS_error
#define FS_set_font FSS_set_font
#define FS_set_flags FSS_set_flags
#define FS_set_bold_pct FSS_set_bold_pct
#define FS_set_stroke_pct FSS_set_stroke_pct
#define FS_set_scale FSS_set_scale
#define FS_set_cmap FSS_set_cmap
#define FS_get_outline FSS_get_outline
#define FS_get_gpos_pts FSS_get_gpos_pts
#define FS_get_bitmap FSS_get_bitmap
#define FS_get_graymap FSS_get_graymap
#define FS_get_subpixel_bitmap FSS_get_subpixel_bitmap
#define FS_get_subpixel_graymap FSS_get_subpixel_graymap
#define FS_get_phased FSS_get_phased
#define FS_get_icon FSS_get_icon
#define FS_free_char FSS_free_char
#define FS_resize FSS_resize
#define FS_exit FSS_exit
#define FS_add_font FSS_add_font
#define FS_font_name FSS_font_name
#define FS_load_font FSS_load_font
#define FS_delete_font FSS_delete_font
#define FS_font_metrics FSS_font_metrics
#define FS_get_vdmx_pair FSS_get_vdmx_pair
#define FS_get_table_structure FSS_get_table_structure
#define FS_get_version FSS_get_version
#define FS_get_heap_used FSS_get_heap_used
#define FS_map_char FSS_map_char
#define FS_get_kerning FSS_get_kerning
#define FS_get_table FSS_get_table
#define FS_free_table FSS_free_table
#define FS_calloc FSS_calloc
#define FS_malloc FSS_malloc
#define FS_realloc FSS_realloc
#define FS_free FSS_free
#define FS_get_flags FSS_get_flags
#endif


/* exports from "api.c" */
/* not really part of the api ... but they live here */
#if defined(_WIN32) && !defined(FS_EXPORT_DLL) && !defined(FS_IMPORT_DLL)
ITYPE_API extern FS_ULONG swapl(FS_ULONG);/* added the extern declaration */
ITYPE_API extern FS_USHORT swapw(FS_USHORT);/* to fix the linkage problem */
#else
ITYPE_API FS_ULONG swapl(FS_ULONG);
ITYPE_API FS_USHORT swapw(FS_USHORT);/* to fix the linkage problem */
#endif
ITYPE_API /*extern INLINE*/ int IDIV(int n,int d); /* when these functions declared */ 
ITYPE_API /*extern INLINE*/ int IMOD(int n,int d);/* inline  4/14/4 FA */
FS_BYTE *load_to_ram(FILECHAR *path);
FILECHAR *FS_strdup(_DS_ FILECHAR *s);
int FS_streq(FILECHAR *a, FILECHAR *b);
FS_LONG check_sfnt(_DS0_);
#ifdef MULTI_PROCESS
FS_VOID MF_delete_mappedfnt(_DS_ MAPPEDFNT *mappedfnt);
#endif

/* exports from "autohint.c" */
void autohint_other_AA(fnt_LocalGraphicStateType *gs);
void autohint_latin_AA(fnt_LocalGraphicStateType *gs);
void autohint_asian_AA(fnt_LocalGraphicStateType *gs);

void autohint_outline(_DS_ fsg_SplineKey *key);
void autohint_generic_NEW(_DS_ fsg_SplineKey *key);
void autohint_latin_NEW(_DS_ fsg_SplineKey *key);
#ifdef FS_DIRECT
static void autohint_other_sub_NEW(FS_SHORT n_pts, FS_SHORT sw, F26DOT6 *v);
static void autohint_latin_x_NEW(_DS_ FS_USHORT n_pts, FS_SHORT xw, F26DOT6 *x);
static void autohint_latin_y_NEW(_DS_ FS_SHORT n_pts, FS_SHORT yw, F26DOT6 *y);
static void autohint_asian_sub_NEW(FS_SHORT n_pts, FS_SHORT w, F26DOT6 *v);
static F26DOT6 rtg_rthg_NEW(F26DOT6 z, FS_SHORT sw);
static void sort_long_NEW(int n, FS_LONG  *vec);
static void rnd_vec_26_6_NEW(int n_pts, F26DOT6 limit, F26DOT6 *vec, FS_SHORT sw);
#endif
void autohint_asian_NEW(_DS_ fsg_SplineKey *key);

FS_VOID *load_fnt(_DS_ FILECHAR *path, FS_BYTE *memptr, FS_ULONG index, FILECHAR *name);
FS_VOID unload_fnt(_DS_ FS_VOID *fnt);
#ifdef GRID_DEBUG
void dump_hints(int n, F26DOT6 *old, F26DOT6 *new);
#endif

/* exports from "xmalloc.c" */
int get_some_back(_DS0_);

/* exports from "scale.c" */
FS_LONG scale_font(_DS_ SFNT *sfnt,FS_FIXED s00,FS_FIXED s01,FS_FIXED s10,FS_FIXED s11);
FS_LONG scale_font_ttf(_DS_ SFNT *sfnt,FS_FIXED s00,FS_FIXED s01,FS_FIXED s10,FS_FIXED s11);

/* exports from "ttf.c" */
TTF *load_ttf(_DS_ FILECHAR *path, FS_BYTE *memptr, FS_ULONG index, FILECHAR *name);
FS_VOID unload_ttf(_DS_ TTF *ttf);
FS_BYTE *ttf_read(_DS_ TTF *ttf, FS_ULONG offset, FS_ULONG size);
FS_VOID ttf_read_buf(_DS_ TTF *ttf, FS_ULONG offset, FS_ULONG size, FS_BYTE *buf);
FS_BYTE *get_ttf_table(_DS_ TTF *ttf, FS_ULONG tag);
int get_ttf_table_info(_DS_ TTF *ttf, FS_ULONG tag, FS_ULONG *off, FS_ULONG *len);

/* exports from "fio.c" */
FILE *FS_create(_DS_ FILECHAR *path);
FILE *FS_open(_DS_ FILECHAR *path);
FS_ULONG FS_tell(_DS_ FILE *fp);
FS_VOID FS_close(_DS_ FILE *fp);
FS_ULONG FS_seek(_DS_ FILE *fp, FS_ULONG offset, int whence);
FS_ULONG FS_read(_DS_ FILE *fp, FS_BYTE *buf, FS_ULONG size);
FS_ULONG FS_write(_DS_ FILE *fp, FS_BYTE *buf, FS_ULONG size);

/* exports from "outline.c" */
FS_OUTLINE *make_outline(_DS_ SFNT *sfnt, FS_ULONG index);
FS_OUTLINE *make_outline_ttf(_DS_ SFNT *sfnt, FS_ULONG index);
#ifdef PSEUDO_BOLD
FS_OUTLINE *embolden_outline(_DS_ FS_OUTLINE *outl,FS_LONG *n_types, FS_LONG *n_points); 
#endif

/* exports from line.c */
FS_VOID line_simple(_DS_ FS_FIXED x0, FS_FIXED y0, FS_FIXED x1, FS_FIXED y1);
FS_VOID line_dropout(_DS_ FS_FIXED x0, FS_FIXED y0, FS_FIXED x1, FS_FIXED y1);
FS_VOID FS_quad(_DS_ FS_FIXED x0, FS_FIXED y0, FS_FIXED x1, FS_FIXED y1, FS_FIXED x2, FS_FIXED y2);
FS_VOID FS_cube(_DS_ FS_FIXED x0, FS_FIXED y0, FS_FIXED x1, FS_FIXED y1, FS_FIXED x2, FS_FIXED y2,FS_FIXED x3, FS_FIXED y3);

/* exports from tlist.c */
TLIST *new_tlist(_DS_ FS_SHORT max, FS_SHORT num);
FS_VOID delete_tlist(_DS_ TLIST *list);
FS_VOID append_tlist(_DS_ FS_FIXED x, FS_SHORT y, TLIST *list);
FS_VOID dump_tlist(FILECHAR *s, TLIST *list);

/* exports from "bitmap.c" */
FS_BITMAP *trim_bitmap(_DS_ FS_BITMAP *bmap);
FS_BITMAP *new_bitmap(_DS_ FS_OUTLINE *outl);
FS_BITMAP *copy_bitmap(_DS_ FS_BITMAP *p);
FS_BITMAP *make_bitmap(_DS_ FS_OUTLINE *p);
FS_VOID runs_3x(FS_BITMAP *bmap);
FS_VOID nzw_runs(_DS_ FS_BITMAP *bitmap, TLIST *list);
FS_BITMAP *emboss_bitmap(_DS_ FS_BITMAP *old);
FS_BITMAP *engrave_bitmap(_DS_ FS_BITMAP *old);
FS_BITMAP *outline_1bitmap(_DS_ FS_BITMAP *old);
FS_BITMAP *outline_2bitmap(_DS_ FS_BITMAP *old);
FS_LONG ttf_font_metrics(_DS_ TTF *ttf, FONT_METRICS *fm, FS_BYTE *real_memptr);

#ifdef STIK
void draw_stik(_DS_ FS_OUTLINE *outl);
#endif

/* exports from "graymap.c" */
FS_GRAYMAP *copy_graymap(_DS_ FS_GRAYMAP *p);
FS_GRAYMAP *new_graymap(_DS_ FS_OUTLINE *outl);
FS_GRAYMAP *make_graymap(_DS_ FS_OUTLINE *outl);
FS_GRAYMAP *trim_graymap(_DS_ FS_GRAYMAP *gmap);

/* exports from "cache.c" */
FS_VOID delete_cache(_DS_ SFNT *sfnt);
FS_BYTE *find_in_cache(_DS_ FS_USHORT type, FS_ULONG index);
FS_OUTLINE* find_outline_in_cache(_DS_ FS_ULONG index);
FS_BITMAP* find_bitmap_in_cache(_DS_ FS_ULONG index);
FS_GRAYMAP* find_graymap_in_cache(_DS_ FS_ULONG index);
FS_GRAYMAP* find_phased_in_cache(_DS_ FS_ULONG index, FS_SHORT phase);
FS_LONG save_to_cache(_DS_ FS_USHORT type, FS_ULONG index, FS_BYTE *p);
FS_LONG save_outline_to_cache(_DS_ FS_ULONG index, FS_OUTLINE *p);
FS_LONG save_bitmap_to_cache(_DS_ FS_ULONG index, FS_BITMAP *p);
FS_LONG save_graymap_to_cache(_DS_ FS_ULONG index, FS_GRAYMAP *p);
FS_LONG save_phased_to_cache(_DS_ FS_ULONG index, FS_SHORT phase, FS_GRAYMAP *p);

/* exports from "sbit.c" */
FS_BITMAP *get_embedded_bitmap(_DS_ SFNT *sfnt, FS_USHORT gIndex);
FS_GRAYMAP *get_embedded_graymap(_DS_ SFNT *sfnt, FS_USHORT gIndex);

/* exports from "cmap.c" */
FS_LONG map_font(_DS_ FS_USHORT platform, FS_USHORT encoding);
FS_USHORT map_char(_DS_ FS_ULONG id);

/* exports from "fsglue.c" */
FS_VOID delete_key(_DS_ FS_VOID * p);
int get_dropout_control(FS_VOID * p);

/* exports from "stik.c" */
#ifdef STIK
FS_OUTLINE *expand_stik(_DS_ FS_OUTLINE *stik, FS_LONG *_nt, FS_LONG *_np);
FS_BITMAP *make_stik_bitmap(_DS_ FS_OUTLINE *stik);
#endif

/* exports from "bitio.c" */
BITIO *MTX_BITIO_Create( _DS_ FS_VOID* memPtr, FS_LONG memSize );
FS_ULONG MTX_BITIO_ReadValue( BITIO *t, FS_LONG numberOfBits );
FS_ULONG MTX_BITIO_Read32( BITIO *t);
FS_ULONG MTX_BITIO_Read8( BITIO *t);

/* exports from "tableptr.c" */
FS_VOID kill_table_ptrs(_DS0_);

#ifdef PFRR
/* exports from "pfr.c" */
FS_LONG scale_font_pfr(_DS_ SFNT *sfnt,FS_FIXED s00,FS_FIXED s01,FS_FIXED s10,FS_FIXED s11);
FS_VOID *load_pfr(_DS_ FILECHAR *path, FS_BYTE *memptr, FS_ULONG index, FILECHAR *name,
           FILE *fp, FILECHAR *MF_path);
FS_VOID unload_pfr(_DS_ FS_VOID *pfr);
FS_OUTLINE *make_outline_pfr(_DS_ SFNT *sfnt, FS_ULONG index);
FS_LONG pfr_font_metrics(_DS_ FS_VOID *pfr, FONT_METRICS *fm);
#endif /* PFR */

/* exports from "kern.c" */
FS_USHORT *get_kern_table_entry(_DS_ KERN *kerning, FS_USHORT index);
FS_VOID delete_kern(_DS_ LFNT *lfnt);
FS_LONG load_kern(_DS0_);

#ifdef __cplusplus
	}
#endif
