/*****************************************************************************
 *
 *  tsresult.h - Defines result and error codes.
 *
 *  Copyright (C) 2003-2005 Monotype Imaging Inc. All rights reserved.
 *
 *  $Archive:   I:/BULL/DisplayImaging/archives/wtle/product/source/include/tsresult.h_v  $ 
 *  $Date:   Jul 27 2005 10:04:08  $
 *  $Revision:   1.26  $
 *
 ****************************************************************************/

#ifndef TSRESULT_H
#define TSRESULT_H

TS_BEGIN_HEADER

/* No error */
#define TS_OK                                         0

#define TS_ERR                                        1
#define TS_ERR_ARGUMENT_IS_NULL_PTR                   2
#define TS_ERR_ARGUMENT_OUT_OF_RANGE                  3

/* Layout module errors 100+ */
#define TS_ERR_POINT_NOT_IN_LAYOUT                  101
#define TS_ERR_FONT_STYLE_NOT_SET                   102

/* Base module errors 200+*/

/* Memory errors */
#define TS_ERR_MALLOC_FAIL                          201
#define TS_ERR_REALLOC_FAIL                         202
#define TS_ERR_FREE_FAIL                            203
#define TS_ERR_FREE_BAD_PTR                         204
#define TS_ERR_REALLOC_BAD_PTR                      205
#define TS_ERR_RESIZE_FAIL                          206

/* Mutex errors */
#define TS_ERR_MUTEX_WAIT_TIMEOUT                   221
#define TS_ERR_MUTEX_WAIT_ABANDONED                 222
#define TS_ERR_INVALID_RESOURCE_TYPE                223

/* Font Services module errors 400+ */
#define TS_ERR_FM_INIT_FONT_ENGINE_FAILED           401
#define TS_ERR_FM_DONE_FONT_ENGINE_FAILED           402
#define TS_ERR_FM_INIT_FONT_FAILED                  403
#define TS_ERR_FM_DONE_FONT_FAILED                  404
#define TS_ERR_FM_INIT_STYLE_FAILED                 405
#define TS_ERR_FM_DONE_STYLE_FAILED                 406
#define TS_ERR_FM_GET_TABLE_FAILED                  407
#define TS_ERR_FM_RELEASE_TABLE_FAILED              408
#define TS_ERR_FM_MAPCHAR_FAILED                    409
#define TS_ERR_FM_INIT_GLYPH_FAILED                 410
#define TS_ERR_FM_DONE_GLYPH_FAILED                 411
#define TS_ERR_FM_GET_GLYPH_PTS_FAILED              412
#define TS_ERR_FM_INVALID_CHARID                    413
#define TS_ERR_FM_INVALID_FONTID                    414
#define TS_ERR_FM_CMAP_PROBLEM                      415                                          


TS_END_HEADER

#endif /* TSRESULT_H */
