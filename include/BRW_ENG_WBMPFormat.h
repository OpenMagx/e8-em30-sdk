

// Copyright (c) 04-Mar-04 - 2008 Motorola, Inc. All rights reserved.



#ifndef BRW_ENG_WBMPFORMAT_H

#define BRW_ENG_WBMPFORMAT_H

#include <wbmp_basictypes.h>
#include <qimage.h>
#include <qasyncimageio.h>
#include <qrect.h>

enum {

  WBMP_TYPE_0         = 0x00,
  WBMP_TYPE_RESERVED1,
  WBMP_TYPE_RESERVED2,
  WBMP_TYPE_RESERVED3,
  WBMP_TYPE_RESERVED4,
  WBMP_TYPE_RESERVED5,
  WBMP_TYPE_RESERVED6,
  WBMP_TYPE_RESERVED7

};

typedef unsigned short int WBMP_TYPE;

enum {

  WBMP_ERR_INVALID_VERSION=0x00,
  WBMP_ERR_SIZ,
  WBMP_ERR_NONE,
  WBMP_ERR_NOT_A_WBMP
};

typedef unsigned short int WBMP_RETURN_STATUS_T;

#define WBMP_FRAME_DELAY 200

class BRW_ENG_WBMPFormat : public QImageFormat
{
public:
  BRW_ENG_WBMPFormat();
  ~BRW_ENG_WBMPFormat();
  WBMP_RETURN_STATUS_T decodeHeader(const unsigned char *buffer, 
                                    int length);
  int decode ( QImage &img, 
               QImageConsumer * consumer, 
               const unsigned char *buffer, 
               int length);

private:
  const unsigned char *buffer_;
  QImageConsumer *consumer_;
  int bytesDecoded_;
  int bytesDecodedFrame_;
  UINT32 imageWidth_;
  UINT32 height_;
  UINT32 width_;
  UINT32 heightBytes_;
  UINT32 widthBytes_;
  int headerSiz_ ;
  int imageSiz_;
  int noOfFrames_;
  int noOfFramesDecoded_;
  int xScanLine_;
  int yScanLine_;
  bool animatedImage_; 

  WBMP_RETURN_STATUS_T handleMultiByteInteger(UINT32 * value, 
                                              UINT8* bytesRead );
  WBMP_RETURN_STATUS_T handleExtensionHeader(UINT8 type, 
                                             UINT8* bytesRead);
};

#endif 
