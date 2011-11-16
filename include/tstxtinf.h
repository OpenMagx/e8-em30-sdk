/*****************************************************************************
 *
 *  tstxtinf.h - Defines interface to TsTextProcessInfo class.
 *
 *  Copyright (C) 2005 Monotype Imaging Inc. All rights reserved.
 *
 *  $Archive:   I:/BULL/DisplayImaging/archives/wtle/product/source/privincl/tstxtinf.h_v  $ 
 *  $Date:   Jul 12 2005 11:02:40  $
 *  $Revision:   1.5  $
 *
 ****************************************************************************/

#include "otwrdblk.h"
#include "tsfixed.h"
#include "ts2d.h"
#include "tsunicde.h"

#ifndef TSTXTINF_H
#define TSTXTINF_H

TS_BEGIN_HEADER

struct TsTextProcessInfo_
{
    TsUInt32 character;             /* Unicode character */
    TsUInt16 glyphIndex;            /* glyph ID */

    TsUInt8 level;                  /* BiDi embedding level */
    TsUInt16 boundaryFlags;         /* boundaries at this character position */

    TsIndex sourceIndex;            /* index of char in orig source data */
    TsIndex logicalOrder;           /* logical order after shaping, etc., but before BiDi reordering */

    TsIndex runIndex;               /* run index in which character falls */

    TsBidiCharClass type;           /* Bidi char type */
    TsFixed xAdvance;               /* glyph x advance */
    TsFixed yAdvance;               /* glyph y advance */
    TsRect boundingBox;             /* glyph "paint" bounding box */

    TsContextPosition context;
    TsPositionAdjust posDelta;      /* GPOS information */
};


typedef struct TsTextProcessInfo_ TsTextProcessInfo;


TsResult
TsTextProcessInfoArray_append(void *derived, TsIndex index, TsLength count);

TsResult
TsTextProcessInfoArray_insert(void *derived, TsIndex index, TsLength count);


extern TS_DECLSPEC const TsOtWordBlockFuncs textProcessInfoArray_otWordBlockFuncs;


TS_END_HEADER

#endif /* TSTXTINF_H */
