/*****************************************************************************
 *
 *  tslayopt.h  - LayoutOptions object interface.
 *
 *  Copyright (C) 2005 Monotype Imaging Inc. All rights reserved.
 *
 *  $Archive:   I:/BULL/DisplayImaging/archives/wtle/product/source/include/tslayopt.h_v  $
 *  $Date:   Feb 02 2006 17:39:32  $
 *  $Revision:   1.7.1.1  $
 *
 ****************************************************************************/

#ifndef TSLAYOUTOPTIONS_H
#define TSLAYOUTOPTIONS_H

#include "tstypes.h"

TS_BEGIN_HEADER

/* Private structure, do not access */
struct TsLayoutOptions_
{
    TsUInt32 flags;
};


/******************************************************************************
 *
 *  Enumeration of origin options values. 
 *
 */
enum
{
    TS_ORIGIN_UPPER_LEFT = 1,
    TS_ORIGIN_FIRST_BASELINE
};


/******************************************************************************
 *
 *  Enumeration of cursor model values.
 *
 */
enum
{
    TS_CURSOR_BOTH_LEADING = 1,
    TS_CURSOR_LEFT_LEADING,
    TS_CURSOR_RIGHT_LEADING,
    TS_CURSOR_NONE_LEADING
};


/******************************************************************************
 *
 *  Enumeration of layout option tags. 
 *
 */
typedef enum
{
    TS_DISABLE_BIDI = 1,
    TS_DISABLE_COMPLEX_SHAPING,
    TS_DISABLE_DIACRITICS_POSITIONING,
    TS_DISABLE_NORMALIZATION,
    TS_DISABLE_OPENTYPE_LAYOUT,
    TS_DISABLE_THAI_LINE_BREAKING,
    TS_DRAW_LINE_ADVANCE_BOX,
    TS_DRAW_LINE_BOUNDING_BOX,
    TS_DRAW_TEXT_DIRECTION,
    TS_DRAW_POTENTIAL_LINE_BREAKS,
    TS_DRAW_WORD_BOUNDARIES,
    TS_DRAW_SCRIPT_BOUNDARIES,
    TS_LAYOUT_ORIGIN,
    TS_CURSOR_MODEL
} TsLayoutOptionsTag;


/*****************************************************************************
 *
 *  Layout options object.
 *
 *  Description:
 *      The TsLayoutOptions object manages layout options.
 *
 *      This table lists the options tags and possible values, with the
 *      default setting shown first. "DRAW" options only have an
 *      effect with debug builds.
 *
 *  <TABLE>
 *      <B> TsLayoutOptionsTag          <B>Possible Values
 *      TS_CURSOR_MODEL                 TS_CURSOR_LEADING
 *                                      TS_CURSOR_MIXED
 *      TS_LAYOUT_ORIGIN                TS_ORIGIN_UPPER_LEFT,
 *                                      TS_ORIGIN_FIRST_BASELINE
 *      TS_DISABLE_BIDI                 FALSE, TRUE
 *      TS_DISABLE_COMPLEX_SHAPING      FALSE, TRUE
 *      TS_DISABLE_DIACRITICS_POSITIONING FALSE, TRUE
 *      TS_DISABLE_NORMALIZATION        FALSE, TRUE
 *      TS_DISABLE_OPENTYPE_LAYOUT      FALSE, TRUE
 *      TS_DISABLE_THAI_LINE_BREAKING   FALSE, TRUE
 *      TS_DRAW_LINE_ADVANCE_BOX        FALSE, TRUE
 *      TS_DRAW_LINE_BOUNDING_BOX       FALSE, TRUE
 *      TS_DRAW_TEXT_DIRECTION          FALSE, TRUE
 *      TS_DRAW_POTENTIAL_LINE_BREAKS   FALSE, TRUE
 *      TS_DRAW_WORD_BOUNDARIES         FALSE, TRUE
 *      TS_DRAW_SCRIPT_BOUNDARIES       FALSE, TRUE
 *  </TABLE> *  <GROUP layoutoptions>
 */
typedef struct TsLayoutOptions_ TsLayoutOptions;


/*****************************************************************************
 *
 *  Creates a new TsLayoutOptions object.
 *
 *  Parameters:
 *      none
 *
 *  Return value:
 *      Pointer to new TsLayoutOptions object.
 *
 *  <GROUP layoutoptions>
 */
TS_EXPORT(TsLayoutOptions *)
TsLayoutOptions_new();


/*****************************************************************************
 *
 *  Initializes a TsLayoutOptions object to default values.
 *
 *  Parameters:
 *      options     - [in] this
 *
 *  Return value:
 *      none
 *
 *  <GROUP layoutoptions>
 */
TS_EXPORT(void)
TsLayoutOptions_defaults(TsLayoutOptions *options);


/*****************************************************************************
 *
 *  Copies a TsLayoutOptions object.
 *
 *  Parameters:
 *      dest        - [in] source is copied here
 *      source      - [in] source data that is copied    
 *
 *  Return value:
 *      none
 *
 *  <GROUP layoutoptions>
 */
TS_EXPORT(void)
TsLayoutOptions_copy(TsLayoutOptions *dest, TsLayoutOptions *source);


/*****************************************************************************
 *
 *  Frees a TsLayoutOptions object.
 *
 *  Parameters:
 *     options      - [in] this 
 *
 *  Return value:
 *      none
 *
 *  <GROUP layoutoptions>
 */
TS_EXPORT(void)
TsLayoutOptions_delete(TsLayoutOptions *options);


/*****************************************************************************
 *
 *  Sets the value of a single TsLayoutOptions option.
 *
 *  Description:
 *      Th
 *  
 *
 *  Parameters:
 *      options     - [in] this
 *      tag         - [in] tag that indicates which option is being set
 *      value       - [in] value of option 
 *     
 *  Return value:
 *      none
 *
 *  <GROUP layoutoptions>
 */
TS_EXPORT(void)
TsLayoutOptions_set(TsLayoutOptions *options, TsLayoutOptionsTag tag, TsInt32 value);


/*****************************************************************************
 *
 *  Gets the value of a single TsLayoutOptions option.
 *
 *  Parameters:
 *      options         - [in] this
 *      tag             - [in] tag that indicates which option to get
 *
 *  Return value:
 *      Option value
 *
 *  <GROUP layoutoptions>
 */
TS_EXPORT(TsInt32)
TsLayoutOptions_get(TsLayoutOptions *options, TsLayoutOptionsTag tag);


TS_END_HEADER

#endif /* TSLAYOUTOPTIONS_H */

