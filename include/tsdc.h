/*****************************************************************************
 *
 *  tsdc.h - Defines interface to the device context class.
 *
 *  Copyright (C) 2003-2004 Monotype Imaging Inc. All rights reserved.
 *
 *  $Archive:   I:/BULL/DisplayImaging/archives/wtle/product/source/include/tsdc.h_v  $ 
 *  $Date:   Jun 21 2005 10:49:12  $
 *  $Revision:   1.13  $
 *
 ****************************************************************************/

#ifndef TSDC_H
#define TSDC_H

#include "ts2d.h"
#include "tsimage.h"

TS_BEGIN_HEADER


/******************************************************************************
 *
 *  Private structure that contains device context object data.
 *
 *  <GROUP devicecontext>
 *
 */
typedef struct TsDC_
{
    struct TsDC_Funcs_ const *func;     

    TsRect clipRect;
    TsBool isClipRectDefined;
    void *devData;
} TsDC;


/*****************************************************************************
 *
 *  The device context virtual function table.
 *
 *  Description:
 *      This structure provides the "virtual function" pointers that are
 *      necessary for the "abstract class" TsDC to provide device 
 *      abstraction.
 *
 *  <GROUP devicecontext>
 */
typedef struct TsDC_Funcs_
{
    TsColor(*getPixel)        (TsDC *dc, TsCoord x, TsCoord y);
    void   (*setPixel)        (TsDC *dc, TsCoord x, TsCoord y, TsColor color);
    TsBool (*getDeviceClip)   (TsDC *dc, TsRect *clip);
    void   (*setDeviceClip)   (TsDC *dc, const TsRect *clip);
    void   (*fillRect)        (TsDC *dc, const TsRect *rect, TsColor color);
    void   (*highlightRect)   (TsDC *dc, const TsRect *rect);
    void   (*drawLine)        (TsDC *dc, TsCoord x1, TsCoord y1, TsCoord x2, TsCoord y2, TsColor);
    void   (*drawImage)       (TsDC *dc, TsImageType type, const void *imageData, TsCoord x, TsCoord y);
} TsDC_Funcs;


/*****************************************************************************
 *
 *  Gets the color at a given pixel.
 *
 *  Parameters:
 *      dc          - [in] this
 *      x           - [in] x coordinate
 *      y           - [in] y coordinate
 *
 *  Return value:
 *      Color at pixel location x,y
 *
 *  <GROUP devicecontext>
 */    
TsColor
TsDC_getPixel(TsDC *dc, TsCoord x, TsCoord y);


/*****************************************************************************
 *
 *  Sets the color at a given pixel.
 *
 *  Parameters:
 *      dc          - [in] this
 *      x           - [in] x coordinate
 *      y           - [in] y coordinate
 *      color       - [in] color value to set at x,y
 *
 *  Return value:
 *      None
 *
 *  <GROUP devicecontext>
 */ 
void
TsDC_setPixel(TsDC *dc, TsCoord x, TsCoord y, TsColor color);


/*****************************************************************************
 *
 *  Gets a clipping rectangle that optionally may be stored as part of
 *  the device data.
 *  
 *  Remarks:
 *      The relevence of this function depends on how device
 *      context is defined as part of port. This function is not currently
 *      used by the core WTLE software.
 *
 *  Parameters:
 *      dc          - [in] this
 *      clipRect    - [out] returns clipping rectangle
 *
 *  Return value:
 *      TRUE if device clipping rect is defined, else FALSE.
 *
 *  <GROUP devicecontext>
 */ 
TsBool
TsDC_getDeviceClip(TsDC *dc, TsRect *clipRect);


/*****************************************************************************
 *
 *  Sets a clipping rectangle that optionally may be stored as part of
 *  the device data.
 *  
 *  Remarks:
 *      The relevence of this function depends on how device
 *      context is defined as part of port. This function is not currently
 *      used by the core WTLE software.
 *
 *  Parameters:
 *      dc          - [in] this
 *      clipRect    - [in] pointer to clipping rectangle
 *
 *  Return value:
 *      None
 *
 *  <GROUP devicecontext>
 */ 
void 
TsDC_setDeviceClip(TsDC *dc, const TsRect *clipRect);


/*****************************************************************************
 *
 *  Fill a rectangle.
 *
 *  Description:
 *      The right and lower edges of the rectangle are not included as
 *      part of the fill.
 *
 *  Parameters:
 *      dc          - [in] this
 *      rect        - [in] pointer to rectangle to fill
 *      color       - [in] color value for fill
 *
 *  Return value:
 *      None
 *
 *  <GROUP devicecontext>
 */ 
void
TsDC_fillRect(TsDC *dc, const TsRect *rect, TsColor color);


/*****************************************************************************
 *
 *  Highlight a rectangle.
 *
 *  Description:
 *      The right and lower edges of the rectangle are not included as
 *      part of the highlight.
 *
 *  Parameters:
 *      dc          - [in] this
 *      rect        - [in] pointer to rectangle to highlight
 *
 *  Return value:
 *      None
 *
 *  <GROUP devicecontext>
 */ 
void
TsDC_highlightRect(TsDC *dc, const TsRect *rect);


/*****************************************************************************
 *
 *  Draw a line.
 *
 *  Description:
 *      The line is one pixel wide. The line is drawn from x1, y1 to
 *      x2, y2 and includes the pixel x2, y2.
 *
 *  Parameters:
 *      dc          - [in] this
 *      x1          - [in] x-coordinate of start of line
 *      x2          - [in] y-coordinate of start of line
 *      x2          - [in] x-coordinate of end of line
 *      y2          - [in] y-coordinate of end of line
 *      color       - [in] color of line
 *
 *  Return value:
 *      None
 *
 *  <GROUP devicecontext>
 */ 
void
TsDC_drawLine(TsDC *dc, TsCoord x1, TsCoord y1, TsCoord x2, TsCoord y2, TsColor color);


/*****************************************************************************
 *
 *  Draw an image.
 *
 *  Description:
 *      The upper left hand corner of the image is put at coordinate x,y.
 *      Several image types are defined, corresponding to several glyph types.
 *
 *  Parameters:
 *      dc          - [in] this
 *      type        - [in] one of several image types that are supported
 *      image       - [in] pointer to image data
 *      x           - [in] x-coordinate of image location
 *      y           - [in] x-coordinate of image location
 *
 *  Return value:
 *      None
 *
 *  <GROUP devicecontext>
 */ 
void
TsDC_drawImage(TsDC *dc, TsImageType type, const void *image, TsCoord x, TsCoord y);





/*****************************************************************************
 *
 *  Initialize a device context object.
 *
 *  Description:
 *      This function should be called by the derived class initializer.
 *      Generally, client code will not call this function.
 *
 *  Parameters:
 *      dc          - [in] this
 *      devData     - [in] pointer to device context-specific data
 *      f           - [in] pointer to function pointer arrray
 *
 *  Return value:
 *      None
 *
 *  <GROUP devicecontext>
 */ 
TsResult
TsDC_init(TsDC *dc, void *devData, const TsDC_Funcs *f);


/*****************************************************************************
 *
 *  Finished a device context object.
 *
 *  Description:
 *      This function should be called by the derived class done function.
 *      Generally, client code will not call this function.
 *
 *      This function cleans up the base class upon a "done".
 *
 *  Parameters:
 *      dc          - [in] this
 *
 *  Return value:
 *      None
 *
 *  <GROUP devicecontext>
 */ 
void
TsDC_done(TsDC *dc);


/*****************************************************************************
 *
 *  Base class function with fallback functions to draw an image.
 *
 *  Description:
 *      Optimally the derived class will implement its own drawImage
 *      funcion to handle various image types. If the derived class
 *      does not handle a particular image type then it can call this
 *      function as a fallback mechansim. Note that this function
 *      uses setPixel and getPixel, and is therefore very slow.
 *      To get good peformance, the derived class should implement its
 *      own draw (blitting) functions.
 *
 *      The upper left hand corner of the image is put at coordinate x,y.
 *      Several image types are defined, corresponding to several glyph types.
 *
 *  Parameters:
 *      dc          - [in] this
 *      type        - [in] one of several image types that are supported
 *      image       - [in] pointer to image data
 *      x           - [in] x-coordinate of image location
 *      y           - [in] x-coordinate of image location
 *
 *  Return value:
 *      None
 *
 *  <GROUP devicecontext>
 */ 
void
TsDC_base_drawImage(TsDC *dc, TsImageType type, const void *image, TsCoord x, TsCoord y);


/*****************************************************************************
 *
 *  Gets the current clipping rectangle used by the device context.
 *
 *  Remarks:
 *
 *  Parameters:
 *      dc          - [in]  handle to device context object
 *      clipRect    - [out]  clipping rectangle
 *
 *  Return value:
 *      True if rectangle is defined, else FALSE.
 *
 *  <GROUP devicecontext>
 */   
TS_EXPORT(TsBool)
TsDC_getClipRect(TsDC *dc, TsRect *clipRect);


/*****************************************************************************
 *
 *  Sets the current device context clipping rectangle.
 *
 *  Parameters:
 *      dc          - [in]  handle to device context object
 *      clipRect    - [in]  clipping rectangle 
 *
 *  Return value:
 *      none
 *
 *  <GROUP devicecontext>
 */    
TS_EXPORT(void)
TsDC_setClipRect(TsDC *dc, const TsRect *clipRect);





TS_END_HEADER


#endif /* TSDC_H */
