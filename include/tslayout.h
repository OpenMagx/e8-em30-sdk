/*****************************************************************************
 *
 *  tslayout.h  - Defines the interface to the TsLayout class.
 *
 *  Copyright (C) 2002-2005 Monotype Imaging Inc. All rights reserved.
 *
 *  $Archive:   I:/BULL/DisplayImaging/archives/wtle/product/source/include/tslayout.h_v  $ 
 *  $Date:   Oct 21 2005 14:06:50  $
 *  $Revision:   1.11.1.0  $
 *
 ****************************************************************************/

#ifndef TSLAYOUT_H
#define TSLAYOUT_H

#include "tstext.h"
#include "tslayctl.h"
#include "tslayopt.h"
#include "tsunienc.h"
#include "ts2d.h"
#include "tsdc.h"

TS_BEGIN_HEADER

struct TsLayout_;


/*****************************************************************************
 *
 *  A text layout object.
 *      
 *  Description:
 *
 *      The TsLayout object is a rich text layout object.
 *
 *  <GROUP layout>
 */
typedef struct TsLayout_ TsLayout;


/*****************************************************************************
 *
 *  A structure for returning information about a layout.
 *
 *  <GROUP layout>
 */
typedef struct
{
    TsLength numLines;          /* number of lines in the layout */
    TsRect boundingBox;         /* text layout bounding box */
    TsPoint nextLayoutOrigin;   /* origin of the next layout */       
    TsPoint nextCharOrigin;     /* origin of the next character */
} TsLayoutInfo;


/*****************************************************************************
 *
 *  A structure with information about a TsLayout line.
 *
 *  <GROUP layout>
 */
typedef struct
{
    TsInt32 numGlyphs;  /* number of glyphs on the line */
    TsRect boundingBox; /* actual "inked" area of the line */
    TsRect advanceBox;  /* box spanning origin to next advance point */
    TsInt32 startIndex; /* TsText character index of first character in line */
    TsInt32 endIndex;   /* TsText character index of last character in line */
	TsUInt8 bidiBaseLevel;	/* base bidi level of paragraph */
} TsLineInfo;


/*****************************************************************************
 *
 *  A structure with information about a TsLayout glyph.
 *
 *  <GROUP layout>
 */
typedef struct
{
    TsInt32 sourceIndex; /* character index in TsText block */
    TsInt32 glyphIndex;  /* glyph index in font */
    TsCoord x;           /* the x coordinate */ 
    TsCoord y;           /* the y coordinate */
    TsRect boundingBox;  /* bounding box */
} TsGlyphInfo;


/*****************************************************************************
 *
 *  Creates a new TsLayout object.
 *
 *  Parameters:
 *      text        - [in] rich text source data
 *      control     - [in] layout control object
 *      options     - [in] layout options
 *
 *  Return value:
 *      Pointer to new TsLayout object or NULL upon error.
 *
 *  <GROUP layout>
 */
TS_EXPORT(TsLayout *)           
TsLayout_new(TsText *text, TsLayoutControl *control, TsLayoutOptions *options);


/*****************************************************************************
 *
 *  Frees a TsLayout object.
 *
 *  Parameters:
 *      layout      - [in] this
 *
 *  Return value:
 *      none    
 *
 *  <GROUP layout>
 */             
TS_EXPORT(void)            
TsLayout_delete(TsLayout *layout);


/*****************************************************************************
 *
 *  Composes the entire rich text block.
 *
 *  Description:
 *      This function composes the entire rich text block.
 *
 *  Parameters:
 *      layout      - [in]  this
 *      lineWidth   - [in]  line width, including indents, in layout coordinates
 *      layoutInfo  - [out] returns information about the layout results is returned
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP layout>
 */             
TS_EXPORT(TsResult)            
TsLayout_compose(TsLayout *layout, TsCoord lineWidth, TsLayoutInfo *layoutInfo);


/*****************************************************************************
 *
 *  Returns information about a single line in the layout
 *
 *  Parameters:
 *      layout      - [in] this
 *      lineIndex   - [in] layout line number
 *      lineInfo    - [out] returns information about the line
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP layout>
 */    
TsResult
TsLayout_getLineInfo(TsLayout *layout, TsInt32 lineIndex, TsLineInfo *info);

/*****************************************************************************
 *
 *  Returns information about a single glyph in the layout
 *
 *  Parameters:
 *      layout      - [in] this
 *      lineIndex   - [in] layout line number
 *      glyphIndex  - [in] which glyph in the line
 *      glyphInfo    - [out] returns information about the glyph
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP layout>
 */    
TsResult
TsLayout_getGlyphInfo(TsLayout *layout, TsInt32 lineIndex, TsInt32 glyphIndex, TsGlyphInfo *info);


/*****************************************************************************
 *
 *  Displays the entire rich text block on a device. 
 *
 *  Parameters:
 *      layout      - [in] this
 *      dc          - [in] device context
 *      x           - [in] x-coordinate of layout origin in device coordinates
 *      y           - [in] y-coordinate of layout origin in device coordinates
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP layout>
 */             
TS_EXPORT(TsResult)            
TsLayout_display(TsLayout *layout, TsDC *dc, TsCoord x, TsCoord y);


/*****************************************************************************
 *
 *  Macro that defines invalid caret position. 
 *
 *  <GROUP layoutedit>
 */
#define TS_INVALID_CARET 0xffffffff  


/*****************************************************************************
 *
 *  Enumeration of possible caret positions
 *
 *  <GROUP layoutedit>
 */
typedef enum
{
    TS_NEXT_LOGICAL_GRAPHEME,       /* next grapheme cluster boundary in logical direction */
    TS_NEXT_VISUAL_GRAPHEME,        /* next grapheme cluster boundary in visual direction (i.e. right) */
    TS_PREVIOUS_LOGICAL_GRAPHEME,   /* previous grapheme cluster boundary in logical direction */
    TS_PREVIOUS_VISUAL_GRAPHEME,    /* previous grapheme cluster boundary in visual direction (i.e. left) */
 
    TS_NEXT_LOGICAL_WORD,           /* next word boundary in logical direction */
    TS_NEXT_VISUAL_WORD,            /* next word boundary in visual direction (i.e. right) */
    TS_PREVIOUS_LOGICAL_WORD,       /* previous word boundary in logical direction */
    TS_PREVIOUS_VISUAL_WORD,        /* previous word boundary in visual direction (i.e. left) */
 
    TS_NEXT_LOGICAL_LINE_BREAK,     /* next potential line break in logical direction */
    TS_NEXT_VISUAL_LINE_BREAK,      /* next potential line break in visual direction (i.e. right) */
    TS_PREVIOUS_LOGICAL_LINE_BREAK, /* previous potential line break in logical direction */
    TS_PREVIOUS_VISUAL_LINE_BREAK,  /* previous potential line break in visual direction (i.e. left) */
 
    TS_NEXT_LINE,                   /* same horizontal position in next line */
    TS_PREVIOUS_LINE,               /* same horizontal position in previous line */
 
    TS_START_TEXT,                  /* before first character in text block */
    TS_END_TEXT,                    /* after last character in text block  */
 
    TS_BEGIN_LOGICAL_LINE,          /* logical beginning of line */
    TS_BEGIN_VISUAL_LINE,           /* visual beginning of line */
    TS_END_LOGICAL_LINE,            /* logical end of line */
    TS_END_VISUAL_LINE              /* visual end of line */

} TsCaretPosition;


/*****************************************************************************
 *
 *  Enumeration of arrow cursor possibilities
 *
 *  <GROUP layoutedit>
 */
typedef enum
{
    TS_ARROW_LOGICAL,   /* move in logical direction */
    TS_ARROW_PHYSICAL   /* move in visual direction */
} TsArrowKeyDirection;



/*****************************************************************************
 *
 *  Sets the highlighting range.
 *
 *  Description:
 *      The client application calls this function to give information 
 *      about where to draw the text caret or selection highlight.
 *      The mark and point refer to logical positions between characters
 *      in the text. If the mark and point are the same, a text caret will
 *      be drawn - otherwise a highlight will be drawn over the selection
 *      at display time.
 *
 *  Parameters:
 *      layout      - [in] this
 *      markIndex   - [in] character index of the mark position
 *      pointIndex  - [in] character index of the point position
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP layoutedit>
 */             
TS_EXPORT(TsResult)            
TsLayout_setSelection(TsLayout *layout, TsInt32 markIndex, TsInt32 pointIndex);


/*****************************************************************************
 *
 *  Gets the currently selected characters.
 *
 *  Parameters:
 *      layout      - [in] this
 *      markIndex   - [out] returns character index of the mark position
 *      pointIndex  - [out] returns character index of the point position
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP layoutedit>
 */     
TS_EXPORT(TsResult)            
TsLayout_getSelection(TsLayout *layout, TsInt32 *markIndex, TsInt32 *pointIndex);


/*****************************************************************************
 *
 *  Returns the nearest character index after a move.
 *
 *  Parameters:
 *      layout      - [in] this
 *      startIndex  - [in] character index before the move
 *      type        - [in] type of movement relative to startIndex
 *      resultIndex - [out] returns character index after the move
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP layoutedit>
 */
TS_EXPORT(TsResult)            
TsLayout_getValidPosition(TsLayout *layout, TsInt32 startIndex,
                          TsCaretPosition type, TsInt32 *resultIndex);


/*****************************************************************************
 *
 *  Gets the index of character nearest a point in layout coordinates.
 *
 *  Description:
 *      Use this function to position the caret after a mouse click or to
 *      to determine the mark or point values for TsLayout_setSelection().
 *
 *  Parameters:
 *      layout      - [in] this
 *      x           - [in] x-coordinate in layout coordinates
 *      y           - [in] y-coordinate in layout coordinates
 *      index       - [out] returns index of character nearest the point
 *
 *  Return value:
 *      TsResult - TS_OK if the point could be mapped to a character position. 
 *
 *  <GROUP layoutedit>
 */             
TS_EXPORT(TsResult)            
TsLayout_getIndexForXY(TsLayout *layout, TsCoord x, TsCoord y, TsInt32 *index);


/*****************************************************************************
 *
 *  Gets the layout coordinates nearest a character.
 *
 *  Parameters:
 *      layout      - [in] this
 *      index       - [in] index of character
 *      x           - [out] returns x coordinate of nearest character
 *      y           - [out] returns y coordinate of nearest character
 *
 *  Return value:
 *      TsResult - TS_OK if the point could be mapped to a character index.  
 *
 *  <GROUP layoutedit>
 */             
TS_EXPORT(TsResult)            
TsLayout_getXYForIndex(TsLayout *layout, TsInt32 index, TsCoord *x, TsCoord *y);


/*****************************************************************************
 *
 *  Gets the character index after moving with a left arrow keypress.
 *
 *  Parameters:
 *      layout      - [in] this
 *      startIndex  - [in] character index before the move
 *      type        - [in] use logical or physical arrow direction
 *      resultIndex - [out] returns character index after the move
 *
 *  Return value:
 *      Character index after the move.
 *
 *  <GROUP layoutedit>
 */             
TS_EXPORT(TsResult)            
TsLayout_arrowLeft(TsLayout *layout, TsInt32 startIndex,
                   TsArrowKeyDirection type, TsInt32 *resultIndex);


/*****************************************************************************
 *
 *  Gets the character index after moving with a right arrow keypress.
 *
 *  Parameters:
 *      layout      - [in] this
 *      startIndex  - [in] character index before the move
 *      type        - [in] use logical or physical arrow direction
 *      resultIndex - [out] returns character index after the move
 *
 *  Return value:
 *      Character index after the move.
 *
 *  <GROUP layoutedit>
 */             
TS_EXPORT(TsResult)            
TsLayout_arrowRight(TsLayout *layout, TsInt32 startIndex, 
                    TsArrowKeyDirection type, TsInt32 *resultIndex);


/*****************************************************************************
 *
 *  Gets the character index after moving with an up arrow keypress.
 *
 *  Parameters:
 *      layout      - [in] this
 *      startIndex  - [in] character index before the move
 *      axis        - [in] find index closest to this axis
 *      resultIndex - [out] returns character index after the move
 *
 *  Return value:
 *      Character index after the move.
 *
 *  <GROUP layoutedit>
 */             
TS_EXPORT(TsResult)            
TsLayout_arrowUp(TsLayout *layout, TsInt32 startIndex, 
                 TsCoord axis, TsInt32 *resultIndex);


/*****************************************************************************
 *
 *  Gets the character index after moving with a down arrow keypress.
 *
 *  Parameters:
 *      layout      - [in] this
 *      startIndex  - [in] character index before the move
 *      axis            - [in] find caret closest to this axis
 *      resultIndex - [out] returns character index after the move
 *
 *  Return value:
 *      Character index after the move.
 *
 *  <GROUP layoutedit>
 */             
TS_EXPORT(TsResult)            
TsLayout_arrowDown(TsLayout *layout, TsInt32 startIndex, 
                   TsCoord axis, TsInt32 *resultIndex);



/*****************************************************************************
 *
 *  A structure for returning information about suggested caret.
 *
 *  <GROUP layoutedit>
 */
typedef struct
{
    TsCoord x;
    TsCoord y;
    TsCoord width;
    TsCoord height;
    TsCoord isItalic;
    TsTextDirection direction;
} TsCaretInfo;


/*****************************************************************************
 *
 *  Get information for making a caret or cursor.
 *
 *  Parameters:
 *      layout      - [in] this
 *      charIndex   - [in] character index corresponding to caret point
 *      info        - [out] returns information about caret
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP layoutedit>
 */
TS_EXPORT(TsResult)
TsLayout_getCaretInfo(TsLayout *layout, TsInt32 charIndex, TsCaretInfo *info);


TS_END_HEADER

#endif /* TSLAYOUT_H */
