/*****************************************************************************
 *
 *  otwrdblk.h - Defines interface to TsOtWordBlock class.
 *
 *  Copyright (C) 2005 Monotype Imaging Inc. All rights reserved.
 *
 *  $Archive:   I:/BULL/DisplayImaging/archives/wtle/product/source/include/otwrdblk.h_v  $ 
 *  $Date:   May 16 2005 15:18:26  $
 *  $Revision:   1.3  $
 *
 ****************************************************************************/

#ifndef OTWRDBLK_H
#define OTWRDBLK_H

#include "tstypes.h"

TS_BEGIN_HEADER


/*
    NOTE: NOP (or non-existent Unicode character) in following definition is
    to denote that the Word Block arrays have been expanded due to a GSUB
    Multiple lookup type, glyph IDs were added, but there is no direct Unicode
    character associated with the added Glyph ID.  Question as to what to
    use for the value.  Phil Ritari suggested zero (0), at least for now.
    ICU as of this writing does not implement the Multiple substitution.
    - Jeff Carey, 03/03/03
*/
#define TsUnicode_NOP 0


/*
    NOTE: NOP (or deleted glyph) in following definition is to denote that
    a glpyh has been forgone.  Question as to what to use for the value.
    Steven Paul has never seen 1, 2, or 3 used as valid glyph ids.
    ICU uses 0xFFFE (when "ignoring marks") and 0xFFFF (otherwise).
*/
#define TsGlyphID_NOP 0x0001


typedef enum
{
    /* initial value, no specific context */
    TS_CONTEXT_NONE,

    /* Arabic script */
    TS_ISOLATED,
    TS_INITIAL,
    TS_MEDIAL,
    TS_FINAL,

    /* Indic scripts */
    TS_BASE_CONSONANT,
    TS_VATTU,
    TS_EYELASH_RA,
    TS_RA_HALANT,
    TS_EXPLICIT_HALANT
} TsContextPosition;


typedef struct TsPositionAdjust_
{
    TsIndex   combiningIndex;  /* relative index of previous base glyph */
    TsCoord   xPlacement;      /* x placement adjustments if found in GPOS */
    TsCoord   yPlacement;      /* y placement adjustments if found in GPOS */
    TsCoord   xAdvance;        /* x advance adjustments if found in GPOS */
    TsCoord   yAdvance;        /* y advance adjustments if found in GPOS */
} TsPositionAdjust;


/*****************************************************************************
 *
 *  Set TsPositionAdjust object positioning values to default (zero).
 *
 *  Parameters:
 *      adj        - TsPositionAdjust pointer
 *
 *  Return value:
 *      None
 */
TS_EXPORT(void)
TsPositionAdjust_defaultPos(TsPositionAdjust *adj);


typedef struct TsOtWordBlockFuncs_
{
    /* number of valid elements in collection */
    TsLength (*length)(void *derived);

    /* grow collection by "count" new elements following position "index" */
    TsResult (*append)(void *derived, TsIndex index, TsLength count);

    TsUInt32 (*getUnicode)(void *derived, TsIndex index); /* debug only */

    TsUInt16 (*getGlyphID)(void *derived, TsIndex index);
    void     (*setGlyphID)(void *derived, TsIndex index, TsUInt16 gID);

    TsContextPosition (*getContext)(void *derived, TsIndex index);
    void              (*setContext)(void *derived, TsIndex index, TsContextPosition cp);

    /* this used for "get" AND "set" */
    TsPositionAdjust *(*positionAdjust)(void *derived, TsIndex index);

} TsOtWordBlockFuncs;


typedef struct TsOtWordBlock_
{
    void *derived;

    const TsOtWordBlockFuncs *funcs;

} TsOtWordBlock;


TS_EXPORT(void)
TsOtWordBlock_init(TsOtWordBlock *wb, void *data, const TsOtWordBlockFuncs *funcs);


TS_EXPORT(TsLength)
TsOtWordBlock_length(TsOtWordBlock *wb);


TS_EXPORT(TsResult)
TsOtWordBlock_append(TsOtWordBlock *wb, TsIndex index, TsLength count);


TS_EXPORT(TsUInt32)
TsOtWordBlock_getUnicode(TsOtWordBlock *wb, TsIndex index);


TS_EXPORT(TsUInt16)
TsOtWordBlock_getGlyphID(TsOtWordBlock *wb, TsIndex index);


TS_EXPORT(void)
TsOtWordBlock_setGlyphID(TsOtWordBlock *wb, TsIndex index, TsUInt16 gID);


TS_EXPORT(TsContextPosition)
TsOtWordBlock_getContext(TsOtWordBlock *wb, TsIndex index);


TS_EXPORT(void)
TsOtWordBlock_setContext(TsOtWordBlock *wb, TsIndex index, TsContextPosition cp);


TS_EXPORT(TsPositionAdjust *)
TsOtWordBlock_positionAdjust(TsOtWordBlock *wb, TsIndex index);


TS_END_HEADER

#endif /* OTWRDBLK_H */
