
/* Copyright (C) 2005 Monotype Imaging Inc. All rights reserved. */

/* Monotype Imaging Confidential */

/* $Header:   I:/BULL/raptor/raptor/bitio.h_v   1.8   Nov 03 2005 17:54:56   galejss  $ */
/* $Log:   I:/BULL/raptor/raptor/bitio.h_v  $
 * 
 *    Rev 1.8   Nov 03 2005 17:54:56   galejss
 * add Confidential notice (ITP-180)
 * 
 *    Rev 1.7   Nov 26 2003 11:09:02   Galejs
 * update copyright & header
 *
 */

#ifndef __BITIO__
#define __BITIO__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct {
	FS_BYTE *array;	/* the array of FS_BYTE */
	FS_LONG index;		/* next available bit index */
	FS_LONG max;		/* maximum bit index */
	FS_LONG high;		/* high water mark - for written arrays */
	} BITIO;

#define MTX_BITIO_ftell(t) (t)->index
#define MTX_BITIO_fseek(t,pos) (t)->index = (pos)

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __BITIO__ */
