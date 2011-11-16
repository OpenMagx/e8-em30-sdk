

// Copyright (c) 04-Mar-04 - 2008 Motorola, Inc. All rights reserved.



#ifndef BRW_ENG_WBMPFORMATTYPE_H

#define BRW_ENG_WBMPFORMATTYPE_H

#include "qasyncimageio.h"

class BRW_ENG_WBMPFormatType : public QImageFormatType
{
public:
  QImageFormat* decoderFor( const unsigned char* buffer, 
                            int length);
  const char* formatName() const;
};

#endif 
