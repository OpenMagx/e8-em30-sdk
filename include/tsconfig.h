/*****************************************************************************
 *
 *  tsconfig.h  - Defines, build configuration values and options.                                                             
 *
 *  Copyright (C) 2002 Monotype Imaging Inc. All rights reserved.
 *
 *  $Archive:   I:/BULL/DisplayImaging/archives/wtle/product/source/port/linux/tsconfig.h_v  $ 
 *  $Date:   Apr 22 2005 07:48:46  $
 *  $Revision:   1.2  $
 *
 ****************************************************************************/

#ifndef TSCONFIG_H
#define TSCONFIG_H

#include "tstypes.h"


/*****************************************************************************
 *
 *  Build configuration option that specifies a build configuration string.
 *  Defaults to "Default".  May be redefined in order to give a name
 *  to a particular build.  If redefined then it must be as a string constant.
 *
 *  <GROUP tsconfig>
 */
#ifndef TS_CONFIG_STRING
#define TS_CONFIG_STRING "Default"
#endif


/*****************************************************************************
 *  
 *  Macros for possible options of TS_BUILD_LEVEL.
 *  
 */
#define TS_RELEASE_BUILD    1
#define TS_DEBUG_BUILD      2
#define TS_VERBOSE_BUILD    3


/*****************************************************************************
 *
 *  Build configuration option that specifies the build level.
 *  Default definition is TS_DEBUG_BUILD.  May be redefined as:
 *
 *  <TABLE>
 *      TS_RELEASE_BUILD    Release-level build.  No debugging or trace facilities available.
 *      TS_DEBUG_BUILD      Debugging-level build.  Basic debugging and trace facilities are available.
 *      TS_VERBOSE_BUILD    Verbose debugging build.  More extensive debugging and trace messages are turned on.
 *  </TABLE>
 *  
 *  <GROUP tsconfig>
 */
#ifndef TS_BUILD_LEVEL
#ifdef NDEBUG
#define TS_BUILD_LEVEL TS_RELEASE_BUILD
#else
#define TS_BUILD_LEVEL TS_DEBUG_BUILD
#endif
#endif


/*****************************************************************************
 *
 *  Build configuration option that defines the amount of RAM, in bytes,
 *  that the iType font rasterizer system initially defines as its heap.  The iType
 *  heap is used for working memory, internal font data, and the glyph cache.
 *  When iType uses external memory the heap is not a contiguous block, 
 *  but instead is just an amount of memory that iType can use before it must
 *  automatically give some of it back.
 *
 *  This value should be chosen carefully, as it must be large enough to avoid
 *  thrashing, but cannot be so large as to consume too much of the system resources.
 *
 *  <GROUP tsconfig>
 */
#ifndef ITYPE_HEAP_SIZE
#define ITYPE_HEAP_SIZE   4000000
#endif


/*****************************************************************************
 *
 *  Macro determining if macros found below (TS_TEXT_RELDIR, TS_FONTS_RELDIR,
 *  TS_UPROPS_RELDIR) are to be considered relative to either the value
 *  of the environment variable AMT_DI_ROOT or, if not set, relative to
 *  "../".   This will generally be "define"d in Windows, UNIX, and similar
 *  environments.  Embedded systems without hierarchal file systems (such
 *  as Symbian) probably want to "undef"ine this macro and put absolute
 *  path names in the TS_*_RELDIR macros.
 *
 *  <GROUP tsconfig>
 */
#define TS_USE_AMT_DI_ROOT


/*****************************************************************************
 *
 *  Build configuration options that specify where to find the Thai dictionary file.
 *  
 *  The TsThaiDict_initResource macro initializes the resource to either a memory-mapped
 *  file or a path-mapped file.
 *
 *  If TS_THAIDICT_MEM is defined then the TS_THAIDICT__ADDRESS and TS_THAIDICT_MEM macros 
 *  should be defined.  The definition may be either as constants or as callback functions
 *  that return these values.
 *
 *  If TS_THAIDICT_MEM is not defined then TS_THAIDICT_PATH should be defined as the full path
 *  to the Thai dictionary file.
 *
 *  <GROUP tsconfig>
 */


#ifdef TS_THAIDICT_MEM

#ifndef TS_THAIDICT_ADDRESS
#error "TS_THAIDICT_MEM is defined without giving a value for TS_THAIDICT_ADDRESS"
#endif

#ifndef TS_THAIDICT_LENGTH
#error "TS_THAIDICT_MEM is defined without giving a value for TS_THAIDICT_LENGTH"
#endif

#define TsThaiDict_initResource(resource) \
    TsResource_initMem(resource, TS_THAIDICT_ADDRESS, TS_THAIDICT_LENGTH)


#else

#ifndef TS_THAIDICT_PATH
#define TS_THAIDICT_NAM "thaiunidict.txt"
#define TS_THAIDICT_RELDIR "/wtle/product/source/layout/"
#define TS_THAIDICT_PATH TsFile_findThaiDict(tsThaiDictPath, TS_THAIDICT_NAM)
#endif

#define TsThaiDict_initResource(resource) \
    TsResource_initPath(resource, TS_THAIDICT_PATH)


#endif

/*****************************************************************************
 *
 *  Build configuration option that specifies a directory that contains fonts.
 *  This is a convenience for samples and test programs.  It is not used
 *  directly by the layout engine.
 *
 *  <GROUP tsconfig>
 */
#ifndef TS_FONTS_DIR
#define TS_FONTS_RELDIR "/wtle/product/fontdata/"
#define TS_FONTS_DIR TsFile_formDir(tsFontsDir, TS_FONTS_RELDIR)
#endif


/*****************************************************************************
 *
 *  Build configuration option that specifies a directory that contains text
 *  files.  This is a convenience for samples and test programs.  
 *  It is not used directly by the layout engine.
 *
 *  <GROUP tsconfig>
 */
#ifndef TS_TEXT_DIR
#define TS_TEXT_RELDIR "/wtle/product/testdata/"
#define TS_TEXT_DIR TsFile_formDir(tsTextDir, TS_TEXT_RELDIR)
#endif


#endif /* TSCONFIG_H */

