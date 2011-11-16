/*****************************************************************************
 *
 *  tstext.h - defines interface to the TsText class.
 *
 *  Copyright (C) 2002-2005 Monotype Imaging Inc. All rights reserved.
 *
 *  $Archive:   I:/BULL/DisplayImaging/archives/wtle/product/source/privincl/tstext.h_v  $ 
 *  $Date:   Jun 21 2005 06:45:48  $
 *  $Revision:   1.40  $
 *
 ****************************************************************************/

#ifndef TSTEXT_H
#define TSTEXT_H

#include "tsproj.h"
#include "tsunienc.h"
#include "tstextat.h"
#include "tsfontst.h"

TS_BEGIN_HEADER

struct TsText_;
typedef struct TsText_ TsText;

struct TsAttrib_;
typedef struct TsAttrib_ TsAttrib;

/* Private: These functions are not fully supported for export in Version 2.0. */


TS_EXPORT(TsResult)
TsText_setCharSpacing(TsText *t, TsFixed value, TsInt32 startIndex, TsInt32 endIndex);

TS_EXPORT(TsResult)
TsText_setAttrib(TsText *t, TsAttrib *attrib, void *value, TsInt32 startIndex, TsInt32 endIndex);

TS_EXPORT(void *)
TsText_getAttrib(TsText *t, TsAttrib *attrib, TsInt32 index, TsInt32 *startIndexIndex, TsInt32 *endIndex);

TS_EXPORT(TsFixed)
TsText_getCharSpacing(TsText *t, TsInt32 index, TsInt32 *startIndex, TsInt32 *endIndex);

TS_EXPORT(TsResult)
TsText_setStrikeout(TsText *t, TsStrikeOutStyle value, TsInt32 startIndex, TsInt32 endIndex);

TS_EXPORT(TsResult)
TsText_setStrikeoutColor(TsText *t, TsColor value, TsInt32 startIndex, TsInt32 endIndex);


/* end of private */



#define TS_START_OF_TEXT    (TS_INT32_MIN + 10) /* +- 10 to avoid wrapping edge */
#define TS_END_OF_TEXT      (TS_INT32_MAX - 10)
#define TS_START_OF_PARA    (TS_START_OF_TEXT)
#define TS_END_OF_PARA      (TS_END_OF_TEXT)


/*****************************************************************************
 *
 *  Creates and initializes a TsText object.
 *
 *  Parameters:
 *      none
 *
 *  Return value:
 *      Pointer to new TsText object
 *
 *  <GROUP tstext>
 */
TS_EXPORT(TsText *)
TsText_new(void);


/*****************************************************************************
 *
 *  Destroys a TsText object.
 *
 *  Parameters:
 *      t           - [in] this
 *
 *  Return value:
 *      none
 *
 *  <GROUP tstext>
 */
TS_EXPORT(void)
TsText_delete(TsText *t);


/*****************************************************************************
 *
 *  Initializes an existing TsText object.
 *
 *  Parameters:
 *      t           - [in] this
 *
 *  Return value:
 *      result      
 *
 *  <GROUP tstext>
 */
TS_EXPORT(TsResult)
TsText_init(TsText *t);


/*****************************************************************************
 *
 *  Denitializes a TsText object.
 *
 *  Parameters:
 *      t           - [in] this
 *
 *  Return value:
 *      result
 *
 *  <GROUP tstext>
 */
TS_EXPORT(void)
TsText_done(TsText *t);


/*****************************************************************************
 *
 *  Inserts a text run by copy to a TsText object. 
 *
 *  Description:
 *      This function inserts a text run into the text object. The data is 
 *      copied.
 *
 *      The text is inserted before the 'insertIndex'. 
 *      If insertIndex is TS_END_OF_TEXT then the new text is appended. 
 *
 *      It is a checked run-time error to mix copied and referenced
 *      text within the same TsText object.
 *
 *  Parameters:
 *      t           - [in] this
 *      run         - [in] pointer to a run of text
 *      nUnits      - [in] length of the text run in code units
 *      encoding    - [in] encoding of the text in the run
 *      insertIndex - [in] the new text run is inserted before this index
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP tstext>
 */
TS_EXPORT(TsResult)
TsText_insertText(TsText *t, void *run, TsInt32 nUnits, TsEncoding encoding, TsInt32 insertIndex);


/*****************************************************************************
 *
 *  Deletes text from a text object that has copied text.
 *
 *  Description:
 *      This function deletes some text from the text object. The data is 
 *      copied.
 *
 *      The 'startIndex' and 'endIndex' arguments indicate the range of text to
 *      delete. If the range is empty then this function does nothing.
 *
 *      It is a checked run-time error to mix copied and referenced
 *      text within the same TsText object.
 *
 *  Parameters:
 *      t           - [in] this
 *      startIndex  - [in] index of first deleted character
 *      endIndex    - [in] index of last deleted character
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP tstext>
 */
TS_EXPORT(TsResult)
TsText_removeText(TsText *t, TsInt32 startIndex, TsInt32 endIndex);


/*****************************************************************************
 *
 *  Insert a text run by reference.
 *
 *  Description:
 *      This function inserts a text run by reference. A text run is
 *      a contiguous block of text data. 'By reference' means that 
 *      the TsText object maintains a pointer to the run rather than
 *      copying the text data. The client should not free the
 *      run until the run has been removed from the TsText object
 *      using TsText_removeRun or TsText_changeRun, or the TsText object
 *      has been deleted using TsText_delete.
 *
 *      The text is logically inserted before the run indicated by the
 *      insertHere parameter, a pointer to another run already 
 *      referenced by the Tstext object. If insertHere is NULL
 *      then the new run is appended to the end of the text block.
 *
 *      It is a checked run-time error to mix copied and referenced
 *      text within the same TsText object.
 *
 *  Parameters:
 *      t           - [in] this
 *      run         - [in] pointer to a run of text
 *      nUnits      - [in] length of the text run in code units
 *      encoding    - [in] encoding of the text in the run
 *      insertHere  - [in] the new text run is inserted before this run
 *  
 *  Return value:
 *      TsResult
 *
 *  <GROUP tstext>
 */
TS_EXPORT(TsResult)
TsText_insertRun(TsText *t, void *run, TsInt32 nUnits, TsEncoding encoding, void *insertHere);

/*****************************************************************************
 *
 *  Change a referenced text run.
 *
 *  Description:
 *      This function changes a referenced text run. The text pointed to by
 *      oldRun is replaced by the text pointed to by newRun. The oldRun
 *      and newRun pointers can be the same. 
 *
 *      It is a checked run-time error to mix copied and referenced
 *      text within the same TsText object.
 *
 *  Parameters:
 *      t           - [in] this
 *      newRun      - [in] the new text run
 *      nUnits      - [in] length of the new text run in code units
 *      encoding    - [in] encoding of the text in the new run
 *      oldRun      - [in] the old text run that is to be changed (may be the same as old)
 *      hints       - [in] optional hints about the change
 *  
 *  Return value:
 *      TsResult
 *
 *  <GROUP tstext>
 */
TS_EXPORT(TsResult)
TsText_changeRun(TsText *t, void *newRun, TsInt32 nUnits, TsEncoding encoding, void *oldRun, TsInt32 hints);


/*****************************************************************************
 *
 *  Removes a referenced text run from a TsText object.
 *      
 *  Parameters:
 *      t           - [in] this
 *      run         - [in] the text run to remove
 *
 *  Return value:
 *      none
 *
 *  <GROUP tstext>
 */
TS_EXPORT(void)
TsText_removeRun(TsText *t, void *run);


/*****************************************************************************
 *
 *  Gets the index range of a run in a TsText.
 *      
 *  Parameters:
 *      t           - [in] this
 *      run         - [in] the text run referenced by this TsText object
 *      startIndex  - [out] returns starting index of the run
 *      endIndex    - [out] returns the ending index of the run
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP tstext>
 */
TsResult TsText_getRunRange(TsText *t, void *run, TsInt32 *startIndex, TsInt32 *endIndex);


/*****************************************************************************
 *
 *  Returns the text length in characters.
 *
 *  Parameters:
 *      t           - [in] this
 *
 *  Return value:
 *      TsInt32 
 *
 *  <GROUP tstext>
 */
TS_EXPORT(TsInt32)
TsText_length(TsText *t);


/*****************************************************************************
 *
 *  Returns the character at a given index as a UTF32 value.
 *
 *  Parameters:
 *      t           - [in] this
 *      index       - [in] index of the character to return
 *
 *  Return value:
 *      TsUInt32
 *
 *  <GROUP tstext>
 */
TS_EXPORT(TsUInt32)
TsText_getChar(TsText *t, TsInt32 index);


/*****************************************************************************
 *
 *  Sets the paragraph alignment attribute.
 *
 *  Description:
 *      TsAlignType enumerates the possible values.
 *      The default value is TS_ALIGN_LEFT.
 *
 *  Version:
 *      Version 2.0 - The startIndex and endIndex values are ignored for 
 *      this attribute. The attribute value applies to the whole text block.
 *
 *  Parameters:
 *      t           - [in] this
 *      value       - [in] attribute value
 *      startIndex  - [in] index of first character in range
 *      endIndex    - [in] index of last character in range
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP textattrib>
 */
TS_EXPORT(TsResult)
TsText_setAlignment(TsText *t, TsAlignType value, TsInt32 startIndex, TsInt32 endIndex);


/*****************************************************************************
 *
 *  Sets the bidirectional override attribute.
 *
 *  Description:
 *      This attribute forces a particular text direction, overriding the 
 *      normal direction that is derived from context. 
 *      TsTextDirection enumerates the possible values. 
 *      The default value is TS_NEUTRAL_DIRECTION, which means that
 *      the direction is not overridden.
 *
 *  Parameters:
 *      t           - [in] this
 *      value       - [in] attribute value
 *      startIndex  - [in] index of first character in range
 *      endIndex    - [in] index of last character in range
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP textattrib>
 */
TS_EXPORT(TsResult)
TsText_setBiDiOverride(TsText *t, TsTextDirection value, TsInt32 startIndex, TsInt32 endIndex);


/*****************************************************************************
 *
 *  Sets edge color attribute.
 *
 *  Description:
 *      This attribute controls the color of the edge when edge effects
 *      are applied such as 'uniform outline' and 'drop shadow'. Setting
 *      edge effect is part of the font style parameters.
 *      The default value is TS_COLOR_BLACK.
 *
 *  Parameters:
 *      t           - [in] this
 *      value       - [in] attribute value
 *      startIndex  - [in] index of first character in range
 *      endIndex    - [in] index of last character in range
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP textattrib>
 */
TS_EXPORT(TsResult)
TsText_setEdgeColor(TsText *t, TsColor value, TsInt32 startIndex, TsInt32 endIndex);


/*****************************************************************************
 *
 *  Sets the font style attribute.
 *
 *  Description:
 *      This attribute is a pointer to an abstract description of a 
 *      styled font, i.e. a font with attributes such as size, boldness,
 *      and so forth.
 *
 *      This attribute does not have a default value. The layout
 *      requires a valid setting for each character so it is recommended
 *      that this function be called such that is spans any character
 *      range using TS_START_OF_TEXT and TS_END_OF_TEXT with the 
 *      desired default value, before setting the attribute over
 *      specific ranges.
 *      
 *  Parameters:
 *      t           - [in] this
 *      value       - [in] attribute value
 *      startIndex  - [in] index of first character in range
 *      endIndex    - [in] index of last character in range
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP textattrib>
 */
TS_EXPORT(TsResult)
TsText_setFontStyle(TsText *t, TsFontStyle *value, TsInt32 startIndex, TsInt32 endIndex);


/*****************************************************************************
 *
 *  Sets the amount the first line of each paragraph in the range is indented.
 *
 *  Description:
 *      The indent amount is given in fixed point pixels. The default indent is 0.
 *      The indent is in addition to any left indent or right indent settings.
 *      The effect of indent attribute depends on the alignment attribute:
 *
 *  <TABLE>
 *      <B> Alignment Value             <B>Effect
 *      TS_ALIGN_LEFT                   Indents from the left
 *      TS_ALIGN_RIGHT                  Indents from the right
 *      TS_ALIGN_CENTER                 No change
 *      TS_ALIGN_JUSTIFIED              No change
 *  </TABLE>
 *
 *  Version:
 *      Version 2.0 - The startIndex and endIndex values are ignored for 
 *      this attribute. The attribute value applies to the whole text block.
 *
 *  Parameters:
 *      t           - [in] this
 *      value       - [in] attribute value
 *      startIndex  - [in] index of first character in range
 *      endIndex    - [in] index of last character in range
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP textattrib>
 */
TS_EXPORT(TsResult)
TsText_setIndent(TsText *t, TsFixed value, TsInt32 startIndex, TsInt32 endIndex);


/*****************************************************************************
 *
 *  Sets the language attribute.
 *
 *  Description:
 *      Identifying the language of a text run can help clarify proper text
 *      layout. The default value is 0.
 *
 *  Parameters:
 *      t           - [in] this
 *      value       - [in] attribute value
 *      startIndex  - [in] index of first character in range
 *      endIndex    - [in] index of last character in range
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP textattrib>
 */
TS_EXPORT(TsResult)
TsText_setLanguage(TsText *t, TsLanguage value, TsInt32 startIndex, TsInt32 endIndex);


/*****************************************************************************
 *
 *  Sets the amount the left side of each paragraph in the range is indented.
 *
 *  Description:
 *      The left indent amount is given in fixed-point pixels.
 *      The default value is 0.
 *
 *  Version:
 *      Version 2.0 - The startIndex and endIndex values are ignored for 
 *      this attribute. The attribute value applies to the whole text block.
 *
 *  Parameters:
 *      t           - [in] this
 *      value       - [in] attribute value
 *      startIndex  - [in] index of first character in range
 *      endIndex    - [in] index of last character in range
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP textattrib>
 */
TS_EXPORT(TsResult)
TsText_setLeftIndent(TsText *t, TsFixed value, TsInt32 startIndex, TsInt32 endIndex);


/*****************************************************************************
 *
 *  Sets line spacing attribute.
 *
 *  Description:
 *      The line spacing attribute uses the TsLineSpacing enumeration.
 *      The default value is TS_SINGLE_LINE.
 *
 *  <TABLE>
 *      <B> Line Spacing Value  <B>Effect
 *      TS_SINGLE_LINE          Single line spacing
 *      TS_150_LINE             One and a half line spacing
 *      TS_DOUBLE_LINE          Double line spacing
 *      TS_EXACT_LINE_SPACING   Line spacing is given by the line spacing amount attribute
 *      TS_MULTIPLE_LINE        Line spacing is single line spacing * line spacing amount
 *
 *  Version:
 *      Version 2.0 - The startIndex and endIndex values are ignored for 
 *      this attribute. The attribute value applies to the whole text block.
 *
 *  Parameters:
 *      t           - [in] this
 *      value       - [in] attribute value
 *      startIndex  - [in] index of first character in range
 *      endIndex    - [in] index of last character in range
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP textattrib>
 */
TS_EXPORT(TsResult)
TsText_setLineSpacing(TsText *t, TsLineSpacing value, TsInt32 startIndex, TsInt32 endIndex);


/*****************************************************************************
 *
 *  Sets line spacing amount attribute.
 *
 *  Description:
 *      The affect of the line spacing amount attribute depends on the
 *      The default value is 0.  See TsText_setLineSpacing.
 *
 *  Version:
 *      Version 2.0 - The startIndex and endIndex values are ignored for 
 *      this attribute. The attribute value applies to the whole text block.
 *
 *  Parameters:
 *      t           - [in] this
 *      value       - [in] attribute value
 *      startIndex  - [in] index of first character in range
 *      endIndex    - [in] index of last character in range
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP textattrib>
 */
TS_EXPORT(TsResult)
TsText_setLineSpacingAmount(TsText *t, TsFixed value, TsInt32 startIndex, TsInt32 endIndex);


/*****************************************************************************
 *
 *  Sets the amount the right side of each paragraph in the range is indented.
 *
 *  Description:
 *      The right indent amount is given in fixed-point pixels.
 *      The default value is 0.
 *
 *  Version:
 *      Version 2.0 - The startIndex and endIndex values are ignored for 
 *      this attribute. The attribute value applies to the whole text block.
 *
 *  Parameters:
 *      t           - [in] this
 *      value       - [in] attribute value
 *      startIndex  - [in] index of first character in range
 *      endIndex    - [in] index of last character in range
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP textattrib>
 */
TS_EXPORT(TsResult)
TsText_setRightIndent(TsText *t, TsFixed value, TsInt32 startIndex, TsInt32 endIndex);


/*****************************************************************************
 *
 *  Sets the extra space after each paragraph.
 *
 *  Description:
 *      The space after amount is given in fixed-point pixels.
 *      The default value is 0.
 *
 *  Version:
 *      Version 2.0 - The startIndex and endIndex values are ignored for 
 *      this attribute. The attribute value applies to the whole text block.
 *
 *  Parameters:
 *      t           - [in] this
 *      value       - [in] attribute value
 *      startIndex  - [in] index of first character in range
 *      endIndex    - [in] index of last character in range
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP textattrib>
 */
TS_EXPORT(TsResult)
TsText_setSpaceAfter(TsText *t, TsFixed value, TsInt32 startIndex, TsInt32 endIndex);


/*****************************************************************************
 *
 *  Sets the extra space before a paragraph.
 *
 *  Description:
 *      The space before amount is given in fixed-point pixels.
 *      The default value is 0.
 *
 *  Version:
 *      Version 2.0 - The startIndex and endIndex values are ignored for 
 *      this attribute. The attribute value applies to the whole text block.
 *
 *  Parameters:
 *      t           - [in] this
 *      value       - [in] attribute value
 *      startIndex  - [in] index of first character in range
 *      endIndex    - [in] index of last character in range
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP textattrib>
 */
TS_EXPORT(TsResult)
TsText_setSpaceBefore(TsText *t, TsFixed value, TsInt32 startIndex, TsInt32 endIndex);


/*****************************************************************************
 *
 *  Sets text color attribute.
 *
 *  Description:
 *      This attribute controls the color of the text.
 *      The default value is TS_COLOR_BLACK.
 *
 *  Parameters:
 *      t           - [in] this
 *      value       - [in] attribute value
 *      startIndex  - [in] index of first character in range
 *      endIndex    - [in] index of last character in range
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP textattrib>
 */
TS_EXPORT(TsResult)
TsText_setTextColor(TsText *t, TsColor value, TsInt32 startIndex, TsInt32 endIndex);


/*****************************************************************************
 *
 *  Sets the paragraph base text direction attribute.
 *
 *  Description:
 *      The default value is 0.
 *
 *  Version:
 *      Version 2.0 - The startIndex and endIndex values are ignored for 
 *      this attribute. The attribute value applies to the whole text block.
 *
 *  Parameters:
 *      t           - [in] this
 *      value       - [in] attribute value
 *      startIndex  - [in] index of first character in range
 *      endIndex    - [in] index of last character in range
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP textattrib>
 */
TS_EXPORT(TsResult)
TsText_setTextDirection(TsText *t, TsTextDirection value, TsInt32 startIndex, TsInt32 endIndex);

/*****************************************************************************
 *
 *  Sets text underline attribute.
 *
 *  Description:
 *      This attribute controls whether and how text is underlined.
 *      It uses the TsUnderLineStyle enumeration.
 *      The default value is TS_UNDERLINE_NONE.
 *
 *  Parameters:
 *      t           - [in] this
 *      value       - [in] attribute value
 *      startIndex  - [in] index of first character in range
 *      endIndex    - [in] index of last character in range
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP textattrib>
 */
TS_EXPORT(TsResult)
TsText_setUnderline(TsText *t, TsUnderlineStyle value, TsInt32 startIndex, TsInt32 endIndex);


/*****************************************************************************
 *
 *  Sets underline color attribute.
 *
 *  Description:
 *      This attribute controls the color of the text.
 *      The default value is TS_COLOR_BLACK.
 *
 *  Parameters:
 *      t           - [in] this
 *      value       - [in] attribute value
 *      startIndex  - [in] index of first character in range
 *      endIndex    - [in] index of last character in range
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP textattrib>
 */
TS_EXPORT(TsResult)
TsText_setUnderlineColor(TsText *t, TsColor value, TsInt32 startIndex, TsInt32 endIndex);







TS_EXPORT(TsAlignType)
TsText_getAlignment(TsText *t, TsInt32 index, TsInt32 *startIndex, TsInt32 *endIndex);


TS_EXPORT(TsTextDirection)
TsText_getBiDiOverride(TsText *t, TsInt32 index, TsInt32 *startIndex, TsInt32 *endIndex);


TS_EXPORT(TsColor)
TsText_getEdgeColor(TsText *t, TsInt32 index, TsInt32 *startIndex, TsInt32 *endIndex);


TS_EXPORT(TsFontStyle *)
TsText_getFontStyle(TsText *t, TsInt32 index, TsInt32 *startIndex, TsInt32 *endIndex);


TS_EXPORT(TsFixed)
TsText_getIndent(TsText *t, TsInt32 index, TsInt32 *startIndex, TsInt32 *endIndex);


TS_EXPORT(TsLanguage)
TsText_getLanguage(TsText *t, TsInt32 index, TsInt32 *startIndex, TsInt32 *endIndex);


TS_EXPORT(TsLineSpacing)
TsText_getLineSpacing(TsText *t, TsInt32 index, TsInt32 *startIndex, TsInt32 *endIndex);


TS_EXPORT(TsFixed)
TsText_getLineSpacingAmount(TsText *t, TsInt32 index, TsInt32 *startIndex, TsInt32 *endIndex);


TS_EXPORT(TsFixed)
TsText_getLeftIndent(TsText *t, TsInt32 index, TsInt32 *startIndex, TsInt32 *endIndex);


TS_EXPORT(TsFixed)
TsText_getRightIndent(TsText *t, TsInt32 index, TsInt32 *startIndex, TsInt32 *endIndex);


TS_EXPORT(TsFixed)
TsText_getSpaceAfter(TsText *t, TsInt32 index, TsInt32 *startIndex, TsInt32 *endIndex);


TS_EXPORT(TsFixed)
TsText_getSpaceBefore(TsText *t, TsInt32 index, TsInt32 *startIndex, TsInt32 *endIndex);


TS_EXPORT(TsFixed)
TsText_getStrikeout(TsText *t, TsInt32 index, TsInt32 *startIndex, TsInt32 *endIndex);


TS_EXPORT(TsColor)
TsText_getStrikeoutColor(TsText *t, TsInt32 index, TsInt32 *startIndex, TsInt32 *endIndex);


TS_EXPORT(TsColor)
TsText_getTextColor(TsText *t, TsInt32 index, TsInt32 *startIndex, TsInt32 *endIndex);


TS_EXPORT(TsTextDirection)
TsText_getTextDirection(TsText *t, TsInt32 index, TsInt32 *startIndex, TsInt32 *endIndex);


TS_EXPORT(TsUnderlineStyle)
TsText_getUnderline(TsText *t, TsInt32 index, TsInt32 *startIndex, TsInt32 *endIndex);


TS_EXPORT(TsColor)
TsText_getUnderlineColor(TsText *t, TsInt32 index, TsInt32 *startIndex, TsInt32 *endIndex);





TS_END_HEADER

#endif /* TSTEXT_H */
