
/* Copyright (C) 2005 Monotype Imaging Inc. All rights reserved. */

/* Monotype Imaging Confidential */

/* $Header:   I:/BULL/raptor/raptor/ra_ttf.h_v   1.9   Nov 03 2005 17:55:06   galejss  $ */
/* $Log:   I:/BULL/raptor/raptor/ra_ttf.h_v  $
 * 
 *    Rev 1.9   Nov 03 2005 17:55:06   galejss
 * add Confidential notice (ITP-180)
 * 
 *    Rev 1.8   Nov 26 2003 12:17:46   Galejs
 * update copyright
 *
 */

/*
 * converts between TTF and CTF formats
 */


#ifndef __RA_TTF__
#define __RA_TTF__

typedef struct {
	FS_ULONG glyf_OffsetStart;		/* Offset to first byte. */
    FS_ULONG glyf_OffsetEnd;		/* One past the last byte .*/
    FS_SHORT headerLength;
    FS_ULONG uncmpSize;
    FS_ULONG cmpSize;
    MTX_TABLE_COMPRESS *tc;
	FS_BYTE *cmpStart;               /* Compressed font start (after the header) */
    FS_BYTE *cmpEnd;                 /* just past the last byte of compressed data */
	} MTX_RA_TT_Decomp;

/* prototypes */
MTX_RA_TT_Decomp *MTX_RA_TT_Create( _DS_ FS_BYTE *compressedData);
int MTX_TT_Converter( FS_BYTE *nameIn, FS_BYTE *nameOut, int TT_TO_CT );
MTX_RA_TT_Decomp *MTX_RA_TT_ReadRom( _DS_ MTX_RA_TT_Decomp *t, FS_BYTE* data );
FS_ULONG MTX_RA_TT_getUncompressedFileSize(FS_VOID * t);	
FS_BYTE *MTX_RA_Get_TTF_FragmentPtr(_DS_ MTX_RA_TT_Decomp *t, FS_ULONG position, FS_ULONG *byteCountPtr );
FS_VOID MTX_RA_ReleaseTTF_Fragment(_DS_ MTX_RA_TT_Decomp *t, FS_VOID * data );
FS_VOID MTX_RA_TT_Destroy(_DS_ MTX_RA_TT_Decomp *t);

#endif /* __RA_TTF__ */
