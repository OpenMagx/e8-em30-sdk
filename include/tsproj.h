/*****************************************************************************
 *
 *  tsproj.h - Project Includes and Definitions                                                            
 *
 *  Copyright (C) 2002 Monotype Imaging Inc. All rights reserved.
 *
 *  $Archive:   I:/BULL/DisplayImaging/archives/wtle/product/source/include/tsproj.h_v  $ 
 *  $Date:   May 19 2005 09:58:12  $
 *  $Revision:   1.10  $
 *
 ****************************************************************************/

#ifndef TSPROJ_H
#define TSPROJ_H

#include "tsport.h"     /* Port-specific file */
#include "tstypes.h"    /* Basic types */
#include "tsconfig.h"   /* Configuration options */
#include "tsresult.h"   /* Function return codes */


/*****************************************************************************
 * Some generic macro definitions follow.  We make an exception here to the 
 * usual "TS" prefix because these macros are so common that clarity is improved
 * by using these generic forms.
 *
 * Be careful of side effects when using any of the macros that have arguments.
 *
 */


/*****************************************************************************
 * Macro for boolean 'true'.
 */
#ifndef TRUE
#define TRUE  1
#endif


/*****************************************************************************
 * Macro for boolean 'false'.
 */
#ifndef FALSE
#define FALSE 0
#endif


/*****************************************************************************
 * Macro for NULL value.
 */
#ifndef NULL
#define NULL  (void*)0
#endif


/*****************************************************************************
 * Macro for absolute value.  Watch out for side effects!
 */
#ifndef ABS
#define ABS(x)      (((x)>0)?(x):-(x))
#endif


/*****************************************************************************
 * Macro for maximum value.  Watch out for side effects!
 */
#ifndef MAX
#define MAX(a,b)    (((a)>(b))?(a):(b))
#endif


/*****************************************************************************
 * Macro for minimum value.  Watch out for side effects!
 */
#ifndef MIN
#define MIN(a,b)    (((a)<(b))?(a):(b))
#endif


/*****************************************************************************
 * Macros for min/max integer values.
 */
#define TS_UINT32_MIN   0x00000000
#define TS_UINT32_MAX   0xFFFFFFFF
#define TS_INT32_MAX    0x7FFFFFFF
#define TS_INT32_MIN    0x80000000



#endif /* TSPROJ_H */
