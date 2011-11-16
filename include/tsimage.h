/*****************************************************************************
 *
 *  tsimage.h - Defines interface to TsGlyphImage class
 *
 *  Copyright (C) 2004 Monotype Imaging Inc. All rights reserved.
 *
 *  $Archive:   I:/BULL/DisplayImaging/archives/wtle/product/source/include/tsimage.h_v  $ 
 *  $Date:   May 16 2005 15:18:32  $
 *  $Revision:   1.4  $
 *
 ****************************************************************************/

#ifndef TSIMAGE_H
#define TSIMAGE_H

#include "tstypes.h"

TS_BEGIN_HEADER

/******************************************************************************
 *
 *  Enumeration of image types.
 *
 *  <GROUP render>
 *
 */
typedef enum TsImageType_
{
    TS_IMAGE_BINARY,
    TS_IMAGE_GRAYSCALE,
    TS_IMAGE_ICON
} TsImageType;


/******************************************************************************
 *
 *  Enumeration of image compression types.
 *
 *  <GROUP render>
 *
 */
typedef enum TsCompressionType_
{
    TS_IMAGE_COMPRESSION_NONE = 0,
    TS_IMAGE_COMPRESSION_UFST
} TsCompressionType;


typedef struct TsGlyphImage_
{
    TsInt16 width;          /* image width in pixels*/
    TsInt16 height;         /* image height in pixels */
    TsInt16 bpl;            /* bytes per line (if applicable) */
    TsInt16 org;            /* image organization */
    TsCompressionType comp; /* compression technique */
    TsByte bitsPerPixel;    /* bits per pixel */
    TsColor color;          /* color for 'on' pixels */
    TsByte *bits;           /* image data */
} TsGlyphImage;


TS_END_HEADER


#endif /* TSIMAGE_H */
