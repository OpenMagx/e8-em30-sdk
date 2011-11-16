/*****************************************************************************
 *
 *  tsfontst.h - Defines the interface to the font style class.               
 *
 *  Copyright (C) 2003-2005 Monotype Imaging Inc. All rights reserved.
 *
 *  $Archive:   I:/BULL/DisplayImaging/archives/wtle/product/source/privincl/tsfontst.h_v  $ 
 *  $Date:   Jan 31 2006 13:56:14  $
 *  $Revision:   1.21.1.0  $
 *
 ****************************************************************************/

#ifndef TSFONTST_H
#define TSFONTST_H

#include "otlayout.h"
#include "otwrdblk.h"
#include "tsglyph.h"
#include "tsport.h"
#include "tstypes.h"
#include "ts2d.h"
#include "tstag.h"
#include "tsfntref.h"
#include "tstextat.h"
#include "tstxtinf.h"

TS_BEGIN_HEADER


/*****************************************************************************
 *
 *  A structure that describes font style parameters.  This structure is
 *  used to create TsFontStyle objects; it is a parameter to the function
 *  TsFont_createFontStyle().
 *          
 *  See also: TsEmphasisStyle, TsEdgeStyle, TsBaselineStyle
 *
 *  <GROUP fontparam>
 */
typedef struct TsFontParam_
{
    TsFixed size;               /* font size in pixels per em */                    
    TsFixed width;              /* font width (as percent of font size) */
                                /* If less than or equal to 0, width is set equal to size */ 
    TsAngle orientation;        /* font angle rotated in degrees clockwise (16.16 number) */
    TsEmphasisStyle  emphasis;  /* text emphasis style */

    TsEdgeStyle edge;           /* text edge style */
    TsRenderStyle render;       /* rendering style */

    TsBaselineStyle baseline;   /* text baseline style */
} TsFontParam;


/*****************************************************************************
 *
 *  Sets up default values in a TsFontParam object.
 *
 *  Parameters:
 *      param    - [in] TsFontParam object pointer
 *
 *  Return value:
 *      void
 *
 *  <GROUP param>
 */     
TS_EXPORT(void)
TsFontParam_defaults(TsFontParam *param);



struct TsFontStyle_;

/*****************************************************************************
 *
 *  The font style object.
 *
 *  Description:
 *      This object provides an interface to a font style which primarily
 *      provides TsGlyph objects.  The TsFontStyle class is an abstract class
 *      using the C++ definition, and must be derived from for concrete
 *      font style services.
 *
 *      The TsFontStyle "is a" TsFont, in essence, containing a pointer
 *      to the TsFont from which a TsFontStyle was created.
 *
 *  <GROUP fontstyle>
 */
typedef struct TsFontStyle_ TsFontStyle;


/*****************************************************************************
 *
 *  The font style virtual function table.
 *
 *  Description:
 *      This structure provides the "virtual function" pointers that are
 *      necessary for the "abstract class" TsFontStyle to provide font style
 *      services.  This structure must be properly initialized and passed
 *      to the TsFontStyle constructor via TsFontStyle_new.
 *
 *  <GROUP fontstyle>
 */
typedef struct TsFontStyleFuncs_
{
    void (*deleteIt)(void *data);
    TsResult (*mapChar)(void *data, TsLong charID, TsLong *glyphID);
    TsResult (*getGlyphPts)(void *data, TsUInt16, TsInt16, TsUInt16 *, TsCoord *, TsCoord *);
/*    TsGlyph *(*getGlyph)(void *data, TsIndex index); */
    TsGlyph *(*getGlyph)(void *data, void *info); 
    TsFixed (*xBLOff)(void *data);
    TsFixed (*yBLOff)(void *data);
    TsFixed (*getAscender)(void *data);
    TsFixed (*getDescender)(void *data);
    TsFixed (*getLeading)(void *data);
    TsFixed (*getXSize)(void *data);
    TsFixed (*getYSize)(void *data);
    void (*designUnits2pixels)(void *data, TsInt16 xdu, TsInt16 ydu, TsFixed *xp, TsFixed *yp);
    TsBool (*isToRenderColorIcons)(void *data);
    
} TsFontStyleFuncs;


/******************************************************************************
 *
 *  Creates and initializes a new TsFontStyle object.
 *
 *  Parameters:
 *      font        - [in] TsFont pointer of "parent" font
 *      fontParam   - [in] font attributes
 *      funcs       - [in] a properly initialized TsFontStyleFuncs structure.
 *      data        - [in] the derived class' private data.  This void pointer
 *                     will be passed as the first argument to each of the
 *                     functions defined in TsFontStyleFuncs.
 *
 *  Return value:
 *      Pointer to TsFontStyle object, or NULL if error
 *
 *  <GROUP fontstyle>
 */
TS_EXPORT(TsFontStyle *)
TsFontStyle_new(TsFont *font, TsFontParam *fontParam,
                const TsFontStyleFuncs *funcs, void *data);


/******************************************************************************
 *
 *  Deletes a TsFontStyle object.
 *
 *  Parameters:
 *      style       - [in] TsFontStyle pointer
 *
 *  Return value:
 *      void
 *
 *  <GROUP fontstyle>
 */
TS_EXPORT(void)
TsFontStyle_delete(TsFontStyle *style);


/*****************************************************************************
 *
 *  Increments the reference counter of the TsFontStyle object and
 *  returns the pointer to the same object.
 *
 *  Description:
 *      This function ensures proper reference counting so that the copy
 *      can be safely assigned.  Each call to this function must be matched
 *      with a subsequent call to TsFontStyle_releaseHandle.
 *
 *  Parameters:
 *      fontStyle   - [in] pointer to TsFontStyle object
 *     
 *  Return value:
 *      Pointer to font style object.
 *
 *  <GROUP fontstyle>
 */  
TS_EXPORT(TsFontStyle *)
TsFontStyle_copyHandle(TsFontStyle *fontStyle);


/*****************************************************************************
 *
 *  Decrements the reference counter of the TsFontStyle object.
 *
 *  Description:
 *      This function reverses the action of TsFontStyle_copyHandle.
 *
 *  Parameters:
 *      fontStyle   - [in] pointer to TsFontStyle object
 *     
 *  Return value:
 *      void
 *
 *  <GROUP fontstyle>
 */  
TS_EXPORT(void)
TsFontStyle_releaseHandle(TsFontStyle *fontStyle);


/*****************************************************************************
 *
 *  Compares two TsFontSyle objects for equality.
 *
 *  Description:
 *      This function will compare two TsFontStyle objects and return an
 *      indication as to whether they both refer to the same font style.
 *
 *  Parameters:
 *      s1     - [in] pointer to first TsFontStyle object
 *      s2     - [in] pointer to second TsFontStyle object
 *     
 *  Return value:
 *      TsBool value, TRUE if TsFontSpec objects are equal, FALSE otherwise.
 *
 *  <GROUP font>
 */  
TS_EXPORT(TsBool)
TsFontStyle_compare(TsFontStyle *s1, TsFontStyle *s2);  


/******************************************************************************
 *
 *  Gets the X baseline offset, in fixed-point pixels per em, 
 *  of the glyphs being generated with this style.
 *
 *  Parameters:
 *      style   - [in] pointer to TsFontStyle object
 *
 *  Return value:
 *      TsFixed X baseline offset
 *
 *  <GROUP fontstyle>
 */
TS_EXPORT(TsFixed)
TsFontStyle_getXbaselineOffset(TsFontStyle *style);


/******************************************************************************
 *
 *  Gets the Y baseline offset, in fixed-point pixels per em, 
 *  of the glyphs being generated with this style.
 *
 *  Parameters:
 *      style   - [in] pointer to TsFontStyle object
 *
 *  Return value:
 *      TsFixed Y baseline offset
 *
 *  <GROUP fontstyle>
 */
TS_EXPORT(TsFixed)
TsFontStyle_getYbaselineOffset(TsFontStyle *style);


/******************************************************************************
 *
 *  Finds and returns the OpenType table layout object associated with
 *  the script and language system, if present, for the TsFontStyle.
 *
 *  Parameters:
 *      style   - [in] pointer to TsFontStyle object
 *      script  - [in] script
 *      langSys - [in] language system
 *
 *  Return value:
 *      TsOtLayout pointer
 *
 *  <GROUP fontstyle>
 */
TS_EXPORT(TsOtLayout *)
TsFontStyle_findOtLayout(TsFontStyle *style, TsTag script, TsTag langSys);


/******************************************************************************
 *
 *  Use OpenType tables that are available to shape some text.
 *
 *  Parameters:
 *      style   - [in] pointer to TsFontStyle object
 *      word    - [in/out] pointer to TsWordBlock of text to be shaped
 *      layout  - [in] OpenType layout object as returned from TsFontStyle_findOtLayout
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP fontstyle>
 */
TS_EXPORT(TsResult)
TsFontStyle_otShape(TsFontStyle *style, TsOtWordBlock *word, TsOtLayout *layout);


/******************************************************************************
 *
 *  Returns indication as to wheter this TsFontStyle object handles
 *  rendering of colored icons.
 *
 *  Parameters:
 *      style   - [in] pointer to TsFontStyle object
 *
 *  Return value:
 *      TsBool, TRUE is TsFontStyle renders colored icons, FALSE otherwise.
 *
 *  <GROUP fontstyle>
 */
TS_EXPORT(TsBool)
TsFontStyle_isToRenderColorIcons(TsFontStyle *style);


/******************************************************************************
 *
 *  Maps a character through the font cmap to produce a glyphID.
 *
 *  Description:
 *      This function is similar to TsFont_mapChar, except it accounts
 *      for mapping that may be a function of style.  In particular,
 *      if the rendering style is set to TS_RENDER_COLORED_ICON, it
 *      does not use the normal cmap.
 *
 *  Parameters:
 *      style   - [in] handle to this font style object
 *      charID  - [in] character value.
 *      glyphID - [out] function returns the glyphID here.
 *
 *  Return value:
 *      TS_OK on success, else error code.
 *
 *  <GROUP fontstyle>
 */
TS_EXPORT(TsResult)
TsFontStyle_mapChar(TsFontStyle *style, TsLong charID, TsLong *glyphID);


/******************************************************************************
 *
 *  Gets a TsGlyph associated with a fontStyle and a glyph index value.
 *
 *  Description:
 *      Gets the glyph at 'index' in the font style represented by fontStyle.
 *      The index value must have been obtained using the
 *      TsFontStyle_mapChar method, or, if not a colored icon using the
 *      TsFont_mapChar method of the TsFont that is the "parent" of
 *      the TsFontStyle object.
 *
 *  Parameters:
 *      style     - [in] pointer to TsFontStyle object
 *      index     - [in] glyph index within font (value after character mapping).
 *
 *  Return value:
 *      Pointer to TsGlyph object or NULL if error.
 *
 *  <GROUP fontstyle>
 */
TS_EXPORT(TsGlyph *)
/*TsFontStyle_getGlyph(TsFontStyle *style, TsIndex index);*/
TsFontStyle_getGlyph(TsFontStyle *style, TsTextProcessInfo * info);


/******************************************************************************
 *
 *  Converts x and y values from font design units to pixels.
 *
 *  Description:
 *
 *  Parameters:
 *      style   - [in] pointer to TsFontStyle object
 *      xdu     - [in] x value in design units
 *      ydu     - [in] y value in design units
 *      xp      - [out] equivalent x value in fixed point pixels
 *      yp      - [out] equivalent y value in fixed point pixels
 *
 *  Return value:
 *      none
 *
 *  <GROUP fontstyle>
 */
TS_EXPORT(void) 
TsFontStyle_designUnits2pixels(TsFontStyle *style, TsInt16 xdu, TsInt16 ydu, TsFixed *xp, TsFixed *yp);


/******************************************************************************
 *
 *  Gets the true x-dimension size, in fixed-point pixels per em, 
 *  of the glyphs being generated with this style.
 *
 *  Description:
 *      The size attributes that are passed in to a font engine are
 *      indicate requested size of a full size glyph.  The true
 *      size may be different due to superscript/subscript settings,
 *      width adjustment, or size substition, if the glyphs in the
 *      font are not scalable.
 *
 *  Parameters:
 *      style   - [in] pointer to TsFontStyle object
 *
 *  Return value:
 *      TsFixed X size
 *
 *  <GROUP fontstyle>
 */
TS_EXPORT(TsFixed)
TsFontStyle_getXSize(TsFontStyle *style);


/******************************************************************************
 *
 *  Gets the true y-dimension size, in fixed-point pixels per em, 
 *  of the glyphs being generated with this style.
 *
 *  Description:
 *      The size attributes that are passed in to a font engine are
 *      indicate requested size of a full size glyph.  The true
 *      size may be different due to superscript/subscript settings,
 *      width adjustment, or size substition, if the glyphs in the
 *      font are not scalable.
 *
 *  Parameters:
 *      style   - [in] pointer to TsFontStyle object
 *
 *  Return value:
 *      TsFixed Y size
 *
 *  <GROUP fontstyle>
 */
TS_EXPORT(TsFixed)
TsFontStyle_getYSize(TsFontStyle *style);


/*****************************************************************************
 *
 *  Returns the scaled font ascender value in fixed point pixel units. 
 *
 *  Parameters:
 *      fStyle      - [in] pointer to TsFontStyle object.
 *    
 *  Return value:
 *      TsFixed ascender value
 *
 *  <GROUP fontstyle>
 */
TS_EXPORT(TsFixed)
TsFontStyle_getAscender(TsFontStyle *fStyle);


/*****************************************************************************
 *
 *  Returns the scaled font descender value in fixed point pixel units. 
 *
 *  Parameters:
 *      fStyle      - [in] pointer to TsFontStyle object.
 *    
 *  Return value:
 *      TsFixed descender value
 *
 *  <GROUP fontstyle>
 */  
TS_EXPORT(TsFixed)
TsFontStyle_getDescender(TsFontStyle *fStyle);


/*****************************************************************************
 *
 *  Returns the scaled font leading value in fixed point pixel units. 
 *
 *  Parameters:
 *      style      - [in] pointer to TsFontStyle object.
 *    
 *  Return value:
 *      TsFixed leading value
 *
 *  <GROUP fontstyle>
 */  
TS_EXPORT(TsFixed) 
TsFontStyle_getLeading(TsFontStyle *style);


/*****************************************************************************
 *
 *  Retrieves the cached X and Y coordinate values of the point at index
 *  "pointIndex" for the glyph at index "glyphIndex".  The point is scaled
 *  and styled per the TsFontStyle provided.  The coordinates returned are
 *  in 26.6 fixed point pixels.
 *
 *  Parameters:
 *      style      - [in] pointer to TsFontStyle object.
 *      glyphIndex - [in] index to glyph in font referenced in style.
 *      pointIndex - [in] index to original design point in glyph outline.
 *      x          - [out] pointer to TsCoord in 26.6 fixed point pixels.
 *      y          - [out] pointer to TsCoord in 26.6 fixed point pixels.
 *    
 *  Return value:
 *      TsBool     - TRUE if point was available in cache, FALSE otherwise.
 *
 *  <GROUP fontstyle>
 */  
TS_EXPORT(TsBool)
TsFontStyle_getGPOSpoint(TsFontStyle *style, TsUInt16 glyphIndex,
                         TsUInt16 pointIndex, TsCoord *x, TsCoord *y);


/*****************************************************************************
 *
 *  Adds the X and Y coordinate values of the points indexed in the point
 *  index array "pointIndices" to the internal point cache structure.
 *  The cached points may be retrieved using the above-mentioned method
 *  TsFontStyle_getGPOSpoint().  The points are original design points on
 *  the glyph outline of glyph at index "glyphIndex".  The points are scaled
 *  and styled per the TsFontStyle provided.  The number of points and length
 *  of the point index array is specified with the argument "numPts".
 *
 *  Parameters:
 *      style        - [in] pointer to TsFontStyle object.
 *      glyphIndex   - [in] index to glyph in font referenced in style.
 *      numPts       - [in] number of point indices provided.
 *      pointIndices - [in] indices of original design points on glyph outline.
 *    
 *  Return value:
 *      TsResult     - TS_ERR if cache cannot be allocated, the result of
 *                     the TsFontStyleFuncs call getGlyphPts(), otherwise.
 *
 *  <GROUP fontstyle>
 */  
TS_EXPORT(TsResult)
TsFontStyle_addGPOSpoints(TsFontStyle *style, TsUInt16 glyphIndex,
                          TsInt16 numPts, TsUInt16 *pointIndices);


TS_END_HEADER

#endif /* TSFONTST_H */
