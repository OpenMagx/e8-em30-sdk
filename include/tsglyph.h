/*****************************************************************************
 *
 *  tsglyph.h - Interface to TsGlyph class.
 *
 *  Copyright (C) 2003-2005 Monotype Imaging Inc. All rights reserved.
 *
 *  $Archive:   I:/BULL/DisplayImaging/archives/wtle/product/source/privincl/tsglyph.h_v  $ 
 *  $Date:   May 16 2005 15:18:32  $
 *  $Revision:   1.16  $
 *
 ****************************************************************************/

#ifndef TSGLYPH_H
#define TSGLYPH_H

#include "tsport.h"
#include "ts2d.h"
#include "tsdc.h"

TS_BEGIN_HEADER


struct TsGlyph_;

/******************************************************************************
 *
 *  The glyph object.
 *
 *  Description:
 *      This object provides an interface to a glyph.  The TsGlyph class is
 *      an abstract class using the C++ definition, and must be derived
 *      from for concrete glyph services.
 *
 *  <GROUP glyph>
 *
 */
typedef struct TsGlyph_ TsGlyph;


/******************************************************************************
 *
 *  The glyph virtual function table.
 *
 *  Description:
 *      This structure provides the "virtual function" pointers that are
 *      necessary for the "abstract class" TsGlyph to provide glyph
 *      services.  This structure must be properly initialized and passed
 *      to the TsGlyph constructor via TsGlyph_new.
 *
 *  <GROUP glyph>
 *
 */
typedef struct TsGlyphFuncs_
{
    void (*deleteIt)(void *data);
    TsPoint  (*getAdvance)  (void *data);
    TsPoint  (*getPixelAdvance)  (void *data);
    TsRect   (*getBoundingBox)(void *data);
    TsResult (*draw)(void *data, TsCoord x, TsCoord y, TsDC *dc, TsColor tc, TsColor ec);
} TsGlyphFuncs;


/******************************************************************************
 *
 *  Creates and initializes a new TsGlyph object.
 *
 *  Parameters:
 *      funcs    - [in] a properly initialized TsGlyphFuncs structure.
 *      data     - [in] the derived class' private data.  This void pointer
 *                      will be passed as the first argument to each of the
 *                      functions defined in TsGlyphFuncs.
 *
 *  Return value:
 *      Pointer to new TsGlyph object or NULL if error.
 *
 *  <GROUP glyph>
 */
TS_EXPORT(TsGlyph *)
TsGlyph_new(const TsGlyphFuncs *funcs, void *data);


/******************************************************************************
 *
 *  Deletes a TsGlyph object.
 *
 *  Parameters:
 *      glyph       - [in] this
 *
 *  Return value:
 *      void
 *
 *  <GROUP glyph>
 */
TS_EXPORT(void)
TsGlyph_delete(TsGlyph *glyph);


/*****************************************************************************
 *
 *  Increments the reference counter of the TsGlyph object and
 *  returns the pointer to the same object.
 *
 *  Description:
 *      This function ensures proper reference counting so that the copy
 *      can be safely assigned.  Each call to this function must be matched
 *      with a subsequent call to TsGlyph_releaseHandle.
 *
 *  Parameters:
 *      glyph       - [in] this
 *     
 *  Return value:
 *      Pointer to glyph object.
 *
 *  <GROUP glyph>
 */  
TS_EXPORT(TsGlyph *)
TsGlyph_copyHandle(TsGlyph *glyph);


/*****************************************************************************
 *
 *  Decrements the reference counter of the TsGlyph object.
 *
 *  Description:
 *      This function reverses the action of TsGlyph_copyHandle.
 *
 *  Parameters:
 *      glyph       - [in] this
 *     
 *  Return value:
 *      void
 *
 *  <GROUP glyph>
 */  
TS_EXPORT(void)
TsGlyph_releaseHandle(TsGlyph *glyph);


/******************************************************************************
 *
 *  Get TsGlyph advance or escapement scaled to pixels as 
 *  a 16.16 fixed-point number. This advance should be used to determine
 *  the optimum advance without regard to the pixel grid. It is useful
 *  when determining the length of a line that would occur if glyphs could
 *  be generated and positioned at very high resolution.
 *  
 *  This function should not be used to determine actual interglyph spacing.
 *  Instead, sse TsGlyph_getPixelAdvance(), which takes into account
 *  the true pixel grid of the characters. 
 *
 *  Parameters:
 *      glyph       - [in] this
 *
 *  Return value:
 *      x and y advance as a TsPoint
 *
 *  <GROUP glyph>
 */
TS_EXPORT(TsPoint)
TsGlyph_getAdvance(TsGlyph *glyph);


/******************************************************************************
 *
 *  Get TsGlyph advance or escapement scaled to pixels as 
 *  a 16.16 fixed-point number. This advance should be used to determine
 *  the correct intercharacter spacing taking into account the true character
 *  pixel grid. Use this function to determine the actual intercharacter 
 *  spacing. 
 *
 *  Parameters:
 *      glyph       - [in] this
 *
 *  Return value:
 *      x and y integer pixel advance as a TsPoint
 *
 *  <GROUP glyph>
 */
TS_EXPORT(TsPoint)
TsGlyph_getPixelAdvance(TsGlyph *glyph);


/******************************************************************************
 *
 *  Get the glyph bounding box relative to its origin.
 *
 *  Description:
 *      The bounding box is a rectangle that encloses all of the pixels
 *      in the glyph.  The bounding box accounts for all font effects that
 *      may affect the bounding box size or location, relative to the origin.
 *      This includes the size, width, edge effects, rendering style, 
 *      superscript, subscript, and rotation. 
 *
 *  Parameters:
 *      glyph       - [in] this
 *
 *  Return value:
 *      bounding box as a TsRect
 *
 *  <GROUP glyph>
 */
TS_EXPORT(TsRect)
TsGlyph_getBoundingBox(TsGlyph *glyph);


/******************************************************************************
 *
 *  Draw the glyph on the device indicated by device context.
 *
 *  Parameters:
 *      glyph       - [in] this
 *      x           - [in] upper left x coordinate of image, in pixels
 *      y           - [in] upper left y coordinate of image, in pixels
 *      dc          - [in] pointer to device context object
 *      tc          - [in] text color to use for drawing
 *      dc          - [in] edge color to use for drawing
 *
 *  Return value:
 *      TsResult
 *
 *  <GROUP glyph>
 */
TS_EXPORT(TsResult)
TsGlyph_draw(TsGlyph *glyph,
             TsCoord x, TsCoord y, TsDC *dc, TsColor tc, TsColor ec);


TS_END_HEADER

#endif /* TSGLYPH_H */
