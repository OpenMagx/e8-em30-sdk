/*****************************************************************************
 *
 *  tstag.h - TsTag type definition and method declarations.
 *
 *  Copyright (C) 2002 Monotype Imaging Inc. All rights reserved.
 *
 *  $Archive:   I:/BULL/DisplayImaging/archives/wtle/product/source/privincl/tstag.h_v  $ 
 *  $Date:   May 16 2005 15:18:38  $
 *  $Revision:   1.6  $
 *
 ****************************************************************************/

#ifndef TSTAG_H
#define TSTAG_H

#include "tstypes.h"

TS_BEGIN_HEADER

/*****************************************************************************
 *
 *  Represents the four byte TrueType "Tag" data type.
 *
 *  All tags are 4-byte character strings composed of a limited set of
 *  ASCII characters in the 0x20-0x7E range. If a tag consists of three
 *  or less valid ASCII characters, the letters are followed by the requisite
 *  number of spaces (0x20), each consisting of a single byte.
 *
 *  <GROUP tag>
 */
typedef TsUInt32 TsTag;             /* four bytes */


/******************************************************************************
 *
 *  Given four character arguments, make a TsTag value.
 *
 *  <GROUP truetypetag>
 */
#define TsMakeTag(a,b,c,d) (TsTag)((a << 24) | (b << 16) | (c << 8) | d)


/******************************************************************************
 *
 *  Convert TsTag to a TsChar * string.  Result will be terminated
 *  properly with a NULL character.  TsChar * array is assumed to be
 *  atleast five (5) charaters long.
 *
 *  Parameters:
 *      tag         - [in] tag to convert to string
 *      string      - [out] array of at least five (5) characters for result.
 *
 *  Return value:
 *      TsChar * string pointer to provided, passed-in string.
 *
 *  <GROUP truetypetag>
 */
TS_EXPORT(TsChar *)
TsTag_toString(TsTag tag, TsChar *string);


/******************************************************************************
 *
 *  Convert TsChar * string to a TsTag.
 *
 *  Parameters:
 *      string      - [in] string to convert to tag
 *
 *  Return value:
 *      TsTag tag
 *
 *  <GROUP truetypetag>
 */
TS_EXPORT(TsTag)
TsTag_fromString(const TsChar *string);

TS_END_HEADER

#endif /* TSTAG_H */
