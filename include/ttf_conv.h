
/* Copyright (C) 2005 Monotype Imaging Inc. All rights reserved. */

/* Monotype Imaging Confidential */

/* $Header:   I:/BULL/raptor/raptor/ttf_conv.h_v   1.9   Nov 03 2005 17:55:08   galejss  $ */
/* $Log:   I:/BULL/raptor/raptor/ttf_conv.h_v  $
 * 
 *    Rev 1.9   Nov 03 2005 17:55:08   galejss
 * add Confidential notice (ITP-180)
 * 
 *    Rev 1.8   Jul 08 2005 16:12:10   galejss
 * move coordEncoding[] from .h to .c file (bug # 170)
 * 
 *    Rev 1.7   Jan 26 2004 15:59:14   Galejs
 * some compilers require "static CONST" rather than "CONST static", apparently
 * 
 *    Rev 1.6   Nov 26 2003 12:11:00   Galejs
 * update copyright and header
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	FS_BYTE *ctf1; /* The ctf data  */
	FS_LONG ctfSize1;
	} ctfDescriptor;


typedef struct {
	FS_BYTE *ttf;				/* The TrueType data */
	FS_LONG ttfSize;			/* The TrueType size */

	FS_BYTE *tableStart;		/* The start of the input table */
	FS_BYTE *tableEnd;			/* Points at the first byte past the input table */
	
	ctfDescriptor ctfData;	/* ctf data descriptor */
	
	FS_SHORT convertFormat;
	FS_SHORT indexToLocFormat;
	} TTF_Converter;

typedef struct {
	FS_SHORT			byteCount;
	FS_SHORT			xBits;
	FS_SHORT			yBits;
	FS_SHORT			dxPlus;
	FS_SHORT			dyPlus;
	FS_BYTE 			xIsNegative; /* No meaning if xBits == 0 */
	FS_BYTE 			yIsNegative; /* No meaning if yBits == 0 */
} coordEncodingType;

/* Destructor */
FS_VOID MTX_TTC__Destroy( TTF_Converter *t );


/* Initializes the relative coordinate encoding technique used */
/* to store the coordinates in the CTF format. */
/*FS_VOID MTX_TTC_InitCoordEncoding( VOID_ARGS ); */


FS_SHORT READWORD_INC( FS_BYTE * *pRef );
FS_ULONG READLONG_INC( FS_BYTE * *pRef );

#ifdef __cplusplus
}
#endif
