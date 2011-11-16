

// Copyright (c) 27-Jan-04 - 2008 Motorola, Inc. All rights reserved.


#ifndef MOT_BLEND_H
#define MOT_BLEND_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qpaintdevice.h>
#include <qpoint.h>
#include <qsize.h>
#include <qcolor.h>

void blendBlt(QPaintDevice* dst, const QPoint& dstp,
              const QPaintDevice *src1, const QPoint& src1p, int src1Percent,
              const QPaintDevice *src2, const QPoint& src2p, int src2Percent,
              const QSize& size, bool ignoreMask = false);

void blendBlt(QPaintDevice* dst, int dstx, int dsty, 
              const QPaintDevice *src1, int src1x, int src1y, int src1Percent,
              const QPaintDevice *src2, int src2x, int src2y, int src2Percent,
              int w, int h, bool ignoreMask = false);

void blendFill(QPaintDevice* dst, const QRect& dstRegion,
               const QPaintDevice *src, const QPoint& srcp, int srcPercent,
               const QColor& fillColor, int fillColorPercent,
               bool ignoreMask = false);

void blendFill(QPaintDevice* dst, int dstx, int dsty,  int w, int h,
               const QPaintDevice *src1, int srcx, int srcy, int srcPercent,
               const QColor& fillColor, int fillColorPercent,
               bool ignoreMask = false);

#endif 
