/*****************************************************************************
 *
 *  ts2d.h                                                             
 *
 *  Defines the interface for some simple 2D graphics types and methods.
 *
 *  Copyright (C) 2002 Monotype Imaging Inc. All rights reserved.
 *
 *  $Archive:   I:/BULL/DisplayImaging/archives/wtle/product/source/include/ts2d.h_v  $ 
 *  $Date:   May 16 2005 15:18:28  $
 *  $Revision:   1.26  $
 *
 ****************************************************************************/

#ifndef TS2D_H
#define TS2D_H

#include "tstypes.h"
#include "tsfixed.h"

TS_BEGIN_HEADER


/*****************************************************************************
 *
 *  A structure denoting a two-dimensional position value (x, y).
 *
 *  <GROUP 2dgraphics>
 */
typedef struct TsPoint
{
    TsCoord x;      /* the x position */ 
    TsCoord y;      /* the y position */
} TsPoint;


/*****************************************************************************
 *
 *  Gets the x and y coordinates of a point structure.
 *
 *  Parameters:
 *      point       - [in] pointer to the point structure
 *      x           - [out] x position
 *      y           - [out] x position
 *  
 *  Return value:
 *      none
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(void)    
TsPoint_getCoords(const TsPoint *point, TsCoord *x, TsCoord *y);


/*****************************************************************************
 *
 *  Sets the x and y coordinates of a point structure.
 *
 *  Parameters:
 *      point       - [in/out] pointer to the point structure
 *      x           - [in] x position
 *      y           - [in] x position
 *  
 *  Return value:
 *      TsPoint     TsPoint structure with x and y assigned.
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(TsPoint)    
TsPoint_setCoords(TsPoint *point, TsCoord x, TsCoord y);


/*****************************************************************************
 *
 *  A structure denoting a rectangle.
 *
 *  Remarks:
 *      The coordinates define the dimensions of the rectangle.  The bottom right
 *      coordinate is outside of the rectangle.  When expressed in pixels, the x2
 *      column and y2 row are outside of the rectangle.  This effects the 
 *      interpretation of such functions as TsRect_intersect and others that
 *      take a TsRect argument.
 *
 *      Some graphics systems make the other choice, so this must be accounted
 *      for in the port-specific rendering code.
 *
 *  <GROUP 2dgraphics>
 */
typedef struct TsRect_
{
    TsCoord x1;     /* x-coordinate of upper-left corner */
    TsCoord y1;     /* y-coordinate of upper-left corner */
    TsCoord x2;     /* x-coordinate of lower-right corner */
    TsCoord y2;     /* y-coordinate of lower-right corner */
} TsRect;


/*****************************************************************************
 *
 *  Gets the two points that define a rectangle.
 *
 *  Parameters:
 *      rect        - [in] pointer to the rectangle structure
 *      p1          - [out] first point
 *      p2          - [out] second point
 *
 *  Return value:
 *      none
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(void)    
TsRect_getPoints(const TsRect *rect, TsPoint *p1, TsPoint *p2);


/*****************************************************************************
 *
 *  Initializes a rectangle using two points.
 *
 *  Description:
 *      Using this function ensures that the  rectangle is always stored
 *      such that the coordinates of p2 are greater than or equal to the
 *      coordinates of p1, in both the x and y directions.
 *
 *  Parameters:
 *      rect        - [out] pointer to the rectangle structure
 *      p1          - [in] pointer to the first point
 *      p2          - [in] pointer to the second point
 *
 *  Return value:
 *      none
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(void)    
TsRect_setPoints(TsRect *rect, const TsPoint *p1, const TsPoint *p2);


/*****************************************************************************
 *
 *  Initializes a rectangle using the four coordinates of two points.
 *
 *  Description:
 *      Using this function ensures that the  rectangle is always stored
 *      such that the coordinates of the second point are greater than or
 *      equal to the first point in both the x and y directions.
 *
 *  Parameters:
 *      rect        - [out] pointer to the rectangle structure
 *      x1          - [in] x coordinate of first point 
 *      x2          - [in] y coordinate of first point 
 *      y1          - [in] x coordinate of second point 
 *      y2          - [in] y coordinate of second point 
 *
 *  Return value:
 *      none
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(void)    
TsRect_setCoords(TsRect *rect, TsCoord x1, TsCoord y1, TsCoord x2, TsCoord y2);


/*****************************************************************************
 *
 *  Initializes a rectangle as the intersection of two other rectangles.
 *
 *  Parameters:
 *      rect        -  [out] pointer to the rectangle structure
 *      rect1       -  [in] pointer to first rectangle
 *      rect2       -  [in] pointer to second rectangle
 *
 *  Return value:
 *      TRUE if intersection is defined (has an area), else FALSE.
 *
 *  Remarks:
 *      Both rect1 and rect2 must be normalized, i.e. x2 >= x1 and y2 >= y1.
 *      This can be ensured by using any of the TsRect initializer functions
 *      to initialize those rectangles.
 *
 *      If the return value is FALSE, the intersect values will be zero.
 *
 *  See also:
 *      Remarks under TsRect.
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(TsBool)
TsRect_intersect(TsRect *rect, const TsRect *rect1, const TsRect *rect2);


/*****************************************************************************
 *
 *  Initializes a rectangle as the union of two other rectangles.
 *
 *  Parameters:
 *      rect        -  [out] pointer to the rectangle structure
 *      rect1       -  [in] pointer to first rectangle
 *      rect2       -  [in] pointer to second rectangle
 *
 *  Return value:
 *      none
 *
 *  Remarks:
 *      Both rect1 and rect2 must be normalized, i.e. x2 >= x1 and y2 >= y1.
 *      This can be ensured by using any of the TsRect initializer functions
 *      to initialize those rectangles.
 *
 *  See also:
 *      Remarks under TsRect.
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(void)
TsRect_union(TsRect *rect, const TsRect *rect1, const TsRect *rect2);


/*****************************************************************************
 *
 *  Offsets a rectangle by an amount x, y
 *
 *  Parameters:
 *      rect        - [in/out] pointer to the rectangle structure.
 *      x           - [in] amount to offset x-position.
 *      y           - [in] amount to offset y-position.
 *
 *  Return value:
 *      void
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(void)    
TsRect_offset(TsRect *rect, TsCoord x, TsCoord y);


/****************************************************************************
 *
 *  Typedef for an angle expressed in degrees as a 16.16 fixed point number.
 *
 *  <GROUP 2dgraphics>
 */
typedef TsFixed TsAngle;


/*****************************************************************************
 *
 *  Calculates the sine of an angle.
 *
 *  Parameters:
 *      a           - [in] angle in degrees as a 16.16 fixed point number
 *
 *  Return value:
 *      sin(a) as a 16.16 fixed point number.  
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(TsFixed)               
TsAngle_sin(TsAngle a);


/*****************************************************************************
 *
 *  Calculates the cosine of an angle.
 *
 *  Parameters:
 *      a           - [in] angle in degrees as a 16.16 fixed point number
 *
 *  Return value:
 *      cos(a) as a 16.16 fixed point number
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(TsFixed)           
TsAngle_cos(TsAngle a);


/*****************************************************************************
 *
 *  Calculates the tangent of an angle.
 *
 *  Parameters:
 *      a           - [in] angle in degrees as a 16.16 fixed point number
 *
 *  Return value:
 *      tan(a) as a 16.16 fixed point number  
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(TsFixed)               
TsAngle_tan(TsAngle a);


/*****************************************************************************
 *
 *  A structure denoting a 2x2 matrix.
 *
 *  Description:
 *      Coefficients are entered as 16.16
 *      because the matrix coordinates are generally real numbers where the
 *      integer portion is on the order of the point size.  If greater
 *      range is needed then don't use this structure.
 *
 *  <GROUP 2dgraphics>
 */
typedef struct TsMatrix
{
    TsFixed        a;   /* row1, column 1 */
    TsFixed        b;   /* row1, column 2 */
    TsFixed        c;   /* row2, column 1 */
    TsFixed        d;   /* row2, column 2 */
} TsMatrix;


/*****************************************************************************
 *
 *  Sets the matrix coefficients to values reflecting the identity matrix.
 *
 *  Parameters:
 *      matrix      - [out] pointer to the matrix structure
 *
 *  Return value:
 *      void
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(void)
TsMatrix_ident(TsMatrix *matrix);

/*****************************************************************************
 *
 *  Copies one matrix to another.
 *
 *  Parameters:
 *      matrix      - [out] pointer to the destination matrix structure
 *      source      - [in] pointer to the source matrix structure
 *
 *  Return value:
 *      void
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(void)
TsMatrix_copy(TsMatrix *matrix, const TsMatrix *source);

/*****************************************************************************
 *
 *  Compares two matrices, returning boolean representing equality.
 *
 *  Parameters:
 *      matrix      - [in] pointer to the first matrix structure
 *      source      - [in] pointer to the second matrix structure
 *
 *  Return value:
 *      TsBool -- boolean TRUE or FALSE if matrices are equal or not, resp.
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(TsBool)
TsMatrix_equal(const TsMatrix *matrix, const TsMatrix *source);

/*****************************************************************************
 *
 *  Gets the matrix coefficients.
 *
 *  Parameters:
 *      matrix      - [in] pointer to the matrix structure
 *      a           - [out] row1, column 1
 *      b           - [out] row1, column 2
 *      c           - [out] row2, column 1
 *      d           - [out] row2, column 2
 *
 *  Return value:
 *      void
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(void)    
TsMatrix_get(const TsMatrix *matrix, TsFixed *a, TsFixed *b, TsFixed *c,  TsFixed *d);


/*****************************************************************************
 *
 *  Sets the matrix coefficients.
 *
 *  Parameters:
 *      matrix      - [out] pointer to the matrix structure
 *      a           - [in] row1, column 1
 *      b           - [in] row1, column 2
 *      c           - [in] row2, column 1
 *      d           - [in] row2, column 2
 *
 *  Return value:
 *      void
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(void)    
TsMatrix_set(TsMatrix *matrix, TsFixed a, TsFixed b, TsFixed c,  TsFixed d);


/*****************************************************************************
 *
 *  Sets the matrix coefficients to values reflecting scale on X and Y axes.
 *
 *  Parameters:
 *      matrix      - [out] pointer to the matrix structure
 *      scaleX      - [in] scale factor along X axis
 *      scaleY      - [in] scale factor along Y axis
 *
 *  Return value:
 *      void
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(void)
TsMatrix_scale(TsMatrix *matrix, TsFixed scaleX, TsFixed scaleY);


/*****************************************************************************
 *
 *  Sets the matrix coefficients to values reflecting rotation about "z" axis.
 *
 *  Parameters:
 *      matrix      - [out] pointer to the matrix structure
 *      angle       - [in] rotation angle in degrees
 *
 *  Return value:
 *      void
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(void)
TsMatrix_rotate(TsMatrix *matrix, TsAngle angle);


/*****************************************************************************
 *
 *  Sets the matrix coefficients to values reflecting skew on X and Y axes.
 *
 *  Parameters:
 *      matrix      - [out] pointer to the matrix structure
 *      skewX       - [in] angle of skew on X axis in degrees
 *      skewY       - [in] angle of skew on Y axis in degrees
 *
 *  Return value:
 *      void
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(void)
TsMatrix_skew(TsMatrix *matrix, TsAngle skewX, TsAngle skewY);

/*****************************************************************************
 *
 *  Transform a point from x,y to u,v coordinates using transform matrix.
 *  Values are passed as TsPoint structures.
 *
 *  Parameters:
 *      matrix      - [in] pointer to the matrix structure
 *      p           - [in] pointer to original point
 *      t           - [out] pointer to transformed point
 *
 *  Return value:
 *      void
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(void)
TsMatrix_transform(const TsMatrix *matrix, const TsPoint *p, TsPoint *t);


/*****************************************************************************
 *
 *  Transform a point from x,y to u,v coordinates using transform matrix.
 *  Values are passed as fixed-point coordinates.
 *
 *  Parameters:
 *      matrix      - [in] pointer to the matrix structure
 *      x           - [in] x value
 *      y           - [in] y value
 *      u           - [out] u value
 *      v           - [out] v value
 *
 *  Return value:
 *      void
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(void)
TsMatrix_transform2(const TsMatrix *matrix, TsFixed x, TsFixed y, TsFixed *u, TsFixed *v);


/******************************************************************************
 *
 *  Multiply two matrices storing the product in a third matrix.
 *
 *  Parameters:
 *      C       - [out] pointer to matrix structure for result
 *      A       - [in] pre-multiplicand matrix pointer
 *      B       - [in] post-multiplicand matrix pointer
 *
 *  Return value:
 *      void
 *
 *  Remarks:
 *      Matrix A premultiplies matrix B.
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(void)
TsMatrix_multiply(TsMatrix *C, const TsMatrix *A, const TsMatrix *B);

/*****************************************************************************
 *
 *  Initializes the matrix given certain font spatial characteristics.
 *
 *  Parameters:
 *      matrix      - [out] pointer to the initialized matrix structure.
 *      scaleX      - [in] font size in x-direction pixels per em
 *      scaleY      - [in] font size in y-direction pixels per em
 *      angle       - [in] rotation angle in degrees
 *      skewX       - [in] character X skew angle in degrees.
 *
 *  Return value:
 *      void
 *
 *  Remarks:
 *      Set skew to 15 degrees for pseudo-italic.
 *
 *      Angles and scale values are 16.16 fixed point numbers.
 *
 *  <GROUP 2dgraphics>
 */
TS_EXPORT(void)    
TsMatrix_init(TsMatrix *matrix, TsFixed scaleX, TsFixed scaleY, TsAngle angle, TsAngle skewX);


/****************************************************************************
 *
 *  Typedef for a color value.
 *
 *  Description:
 *      This value represents a color value.  The current implementation
 *      supports ARGB8888 or indexed color.  Do not access these TsColor
 *      values directly, as the implementation may change.
 *      Always use the macros to set and get color values.
 *
 *  <GROUP 2dgraphics>
 */
typedef TsUInt32 TsColor;

#define TSBYTEMASK  (0xFF)
#define TS7BITMASK  (0x7F)
#define TS23BITMASK (0x00FFFFFF)


/****************************************************************************
 *
 *  A macro that returns TRUE if the TsColor parameter is an indexed color,
 *  else returns FALSE, indicating the TsColor is a 
 *
 *  <GROUP 2dgraphics>
 */
#define TS_COLOR_IS_INDEXED(color) (((color)) >> 31) ? TRUE : FALSE)


/****************************************************************************
 *
 *  A macro that returns the alpha component of a TsColor value.
 *
 *  <GROUP 2dgraphics>
 */
#define TS_GET_ALPHA(color) ((TsByte)(((color) >> 24) & TS7BITMASK) << 1)


/****************************************************************************
 *
 *  A macro that returns the red component of a TsColor value.
 *
 *  <GROUP 2dgraphics>
 */
#define TS_GET_RED(color)  (TsByte)(((color) >> 16) & TSBYTEMASK)


/****************************************************************************
 *
 *  A macro that returns the green component of a TsColor value.
 *
 *  <GROUP 2dgraphics>
 */
#define TS_GET_GREEN(color) (TsByte)(((color) >> 8) & TSBYTEMASK)


/****************************************************************************
 *
 *  A macro that returns the blue component of a TsColor value.
 *
 *  <GROUP 2dgraphics>
 */
#define TS_GET_BLUE(color) (TsByte)((color) & TSBYTEMASK)


/****************************************************************************
 *
 *  A macro that returns the index of a TsColor value.
 *
 *  <GROUP 2dgraphics>
 */
#define TS_GET_INDEX(color) (TsByte)((color) & TS23BITMASK)


/****************************************************************************
 *
 *  A macro that returns a TsColor value initialized with 8-bit
 *  alpha, red, green, blue components.
 *
 *  <GROUP 2dgraphics>
 */
#define TS_COLOR_ARGB(a,r,g,b) ((TsColor)((((TsByte)(a))>>1) << 24)   | \
                                (TsColor)(((TsByte)(r)) << 16)        | \
                                (TsColor)(((TsByte)(g)) <<  8)        | \
                                (TsColor)(((TsByte)(b))))


/****************************************************************************
 *
 *  A macro that returns a TsColor value initialized with 8-bit
 *  red, green, blue components.
 *
 *  <GROUP 2dgraphics>
 */
#define TS_COLOR_RGB(r,g,b) TS_COLOR_ARGB(255, r, g, b)
 

/****************************************************************************
 *
 *  A macro that returns a TsColor value initialized with an index value.
 *  The index can range from 0 to 2^23.
 *
 *  <GROUP 2dgraphics>
 */
#define TS_COLOR_INDEX(index) (((index) & 0x00FFFFFF) | (A0000000))

 
 /****************************************************************************
 *
 *  Macro that returns a TsColor value set to black (ARGB).
 *
 *  <GROUP 2dgraphics>
 */
#define TS_COLOR_BLACK TS_COLOR_RGB(0, 0, 0)


/****************************************************************************
 *
 *  Macro that returns a TsColor value set to white (ARGB).
 *
 *  <GROUP 2dgraphics>
 */
#define TS_COLOR_WHITE TS_COLOR_RGB(255, 255, 255)


/****************************************************************************
 *
 *  Macro that returns a TsColor value set to dark gray (ARGB).
 *
 *  <GROUP 2dgraphics>
 */
#define TS_COLOR_DARK_GRAY TS_COLOR_RGB(0x77, 0x77, 0x77)


/****************************************************************************
 *
 *  Macro that returns a TsColor value set to red (ARGB).
 *
 *  <GROUP 2dgraphics>
 */
#define TS_COLOR_RED TS_COLOR_RGB(255, 0, 0)


/****************************************************************************
 *
 *  Macro that returns a TsColor value set to green (ARGB).
 *
 *  <GROUP 2dgraphics>
 */
#define TS_COLOR_GREEN TS_COLOR_RGB(0, 255, 0)


/****************************************************************************
 *
 *  Macro that returns a TsColor value set to blue (ARGB).
 *
 *  <GROUP 2dgraphics>
 */
#define TS_COLOR_BLUE TS_COLOR_RGB(0, 0, 255)



TS_END_HEADER


#endif /* TS2D_H */
