/*****************************************************************************
 *
 *  tstextat.h - Declares text attributes.               
 *
 *  Copyright (C) 2005 Monotype Imaging Inc. All rights reserved.
 *
 *  $Archive:   I:/BULL/DisplayImaging/archives/wtle/product/source/include/tstextat.h_v  $ 
 *  $Date:   Jun 01 2005 09:12:46  $
 *  $Revision:   1.6  $
 *
 ****************************************************************************/

#ifndef TSTEXTAT_H
#define TSTEXTAT_H

#include "tsproj.h"
#include "tsfixed.h"
#include "ts2d.h"

TS_BEGIN_HEADER


/*****************************************************************************
 *
 *  A typedef that defines a language tag.
 *  
 *  Description
 *      Generally this value should be zero, indicating default
 *      handling, unless the specific language of the run is
 *      known.  TsLanguage follows the same rules as the
 *      OpenType layout language system tags.  Macros for
 *      producing these tags are given in otlangs.h.
 * 
 *  <GROUP textattrib>
 */ 
typedef TsLong TsLanguage;

 
/*****************************************************************************
 *
 *  An enumeration of text emphasis styles.
 *
 *  <GROUP textattrib>
 */
typedef enum
{
    TS_EMPHASIS_NORMAL = 0,         /* normal */
    TS_EMPHASIS_BOLD,               /* bold */
    TS_EMPHASIS_ITALIC,             /* italic */
    TS_EMPHASIS_BOLDITALIC          /* bold italic */
} TsEmphasisStyle;


/*****************************************************************************
 *
 *  An enumeration of text edge styles.
 *
 *  Remarks:
 *      The appearance and colors of edge effects may vary with the capabilities
 *      of the font engine and associated rendering code.
 *
 *      The iType rendering code works this way:
 *
 *      In general, glyphs are rendered using the textColor attribute to define the fill color,
 *      and the edgeColor to define the edge or shadow color, if present.  
 *      The TS_EDGE_OUTLINE style is an exception: it uses the textColor for the outline edge; it does
 *      not fill the text with any color.  The TS_EDGE_UNIFORM style, on the other hand,
 *      uses textColor to fill the text, and edgeColor to fill the outline around the text.
 *
 *  <GROUP textattrib>
 */
typedef enum
{
    TS_EDGE_NORMAL = 0,             /* normal text without any edge effect */
    TS_EDGE_EMBOSSED,               /* text has a raised appearance */
    TS_EDGE_ENGRAVED,               /* text has a depressed appearance */
    TS_EDGE_OUTLINED,               /* text is just an outline  */
    TS_EDGE_DROP_SHADOW,            /* text has a shadow */
    TS_EDGE_RAISED,                 /* similar to embossed, but more of a shadow effect */
    TS_EDGE_DEPRESSED,              /* similar to engraved, but more of a shadow effect */
    TS_EDGE_UNIFORM                 /* normal text with a colored edge around it, "cartoon style" */
} TsEdgeStyle;


/*****************************************************************************
 *
 *  An enumeration of baseline styles.
 *
 *  <GROUP textattrib>
 */
typedef enum
{
    TS_BASELINE_NORMAL = 0,         /* normal baseline */
    TS_BASELINE_SUPERSCRIPT,        /* superscript */
    TS_BASELINE_SUBSCRIPT           /* subscript */
} TsBaselineStyle;


/*****************************************************************************
 *
 *  An enumeration of rendering styles.
 *
 *  Description:
 *      Rendering style refers to the method by which the glyph is generated
 *      and by which the glyph is transferred to the display device.
 *      For example, TS_RENDER_BINARY means that the glyph is a binary image
 *      with pixels set to the 'on' color or not set.  TS_RENDER_GRAYSCALE
 *      means that the glyph has several levels of grayscale for each 
 *      'on' pixel.  Upon rendering the gray levels are generally mapped
 *      to interpolated colors between the text color and the background.
 *      This produces an antialiasing effect.
 *
 *      Like all attributes, the rendering style is treated as the requested
 *      style.  The actual style may be different due to limitations of
 *      the font, font engine, or rendering sytem.
 *      
 *  <GROUP textattrib>
 */
typedef enum
{
    TS_RENDER_DEFAULT = 0,          /* default for current font engine */
    TS_RENDER_BINARY,               /* binary rendering */
    TS_RENDER_GRAYSCALE,            /* grayscale antialiasing */
    TS_RENDER_PHASED,               /* phased grayscale antialiasing */
    TS_RENDER_SUBPIXEL_BINARY,      /* subpixel rendering, binary mode */
    TS_RENDER_SUBPIXEL_GRAYSCALE,   /* subpixel rendering, grayscale mode */
    TS_RENDER_COLORED_ICON          /* colored icon rendering */
} TsRenderStyle;


/*****************************************************************************
 *
 *  An enumeration of underline styles.
 *
 *  <GROUP textattrib>
 */
typedef enum
{
    TS_UNDERLINE_NONE = 0,          /* no underline */
    TS_UNDERLINE_SINGLE             /* single underline */
} TsUnderlineStyle;


/*****************************************************************************
 *
 *  An enumeration of strikeout styles.
 *
 *  <GROUP textattrib>
 */
typedef enum
{
    TS_STRIKEOUT_NONE = 0,          /* no strikeout */
    TS_STRIKEOUT_SINGLE,            /* single strikeout */
    TS_STRIKEOUT_DOUBLE             /* double strikeout */
} TsStrikeOutStyle;


/*****************************************************************************
 *
 *  An enumeration of text alignment types.
 *
 *
 *  <GROUP textattrib>
 */
typedef enum
{
    TS_ALIGN_LEFT,          /* left alignment */
    TS_ALIGN_CENTER,        /* center alignment */
    TS_ALIGN_RIGHT,         /* right alignment */
    TS_ALIGN_JUSTIFIED      /* justified paragraph */
} TsAlignType;


 /*****************************************************************************
 *
 *  An enumeration of line spacing settings.
 *
 *  <GROUP textattrib>
 */
typedef enum 
{
    TS_SINGLE_LINE,         /* single spacing */
    TS_150_LINE,            /* one and a half line spacing */
    TS_DOUBLE_LINE,         /* double spacing */
    TS_EXACT_LINE_SPACING,  /* set size set to a sepcific amount (lineSpacingAmount) */
    TS_MULTIPLE_LINE        /* set size is point size multiplied by the lineSpacingAmount */
} TsLineSpacing;


/*****************************************************************************
 *
 *  Enumeration of text flow directions.
 *       
 *  <GROUP textattri>>
 */
typedef enum 
{
    TS_NEUTRAL_DIRECTION = 0,   /* text with no inherent direction */
    TS_LTR_DIRECTION,           /* left-to-right text */
    TS_RTL_DIRECTION            /* right-to-left text */
} TsTextDirection;



TS_END_HEADER

#endif /* TSTEXTAT_H */
