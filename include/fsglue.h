
/* Copyright (C) 2005 Monotype Imaging Inc. All rights reserved. */

/* Monotype Imaging Confidential */

/* Copyright: 1987-1990 by Apple Computer, Inc., all rights reserved. */

/* $Header:   I:/BULL/raptor/raptor/fsglue.h_v   1.16   Nov 03 2005 17:55:02   galejss  $ */
/* $Log:   I:/BULL/raptor/raptor/fsglue.h_v  $
 * 
 *    Rev 1.16   Nov 03 2005 17:55:02   galejss
 * add Confidential notice (ITP-180)
 * 
 *    Rev 1.15   Jul 08 2005 14:14:08   galejss
 * remove pre-NC_REWRITE code
 * 
 *    Rev 1.14   Jun 15 2005 13:09:00   dugganj
 * Multi-processing related changes.
 * 
 *    Rev 1.13   Mar 28 2005 10:26:38   wuq
 * Changes (by swp).
 * 
 *    Rev 1.12   Jun 01 2004 12:09:04   GalejsS
 * get rid of all vestiges of bogus SETJUMP macro
 * 
 *    Rev 1.10   Feb 11 2004 07:25:34   WuQ
 * Changes for fix core dumps in MIPS and SUN.
 * 
 *    Rev 1.9   Nov 26 2003 15:00:58   Galejs
 * nested-composite rewrite: NC_REWRITE ifdef, new phantom points
 * 
 *    Rev 1.8   Mar 13 2003 14:28:02   Galejs
 * FS_BOOLEAN
 * 
 *    Rev 1.7   Mar 06 2003 11:56:50   WuQ
 * Bug fix for #60
 * 
 *    Rev 1.6   May 29 2002 11:45:14   WuQ
 * Type changes for tnumPoints, tnumContours.
 * 
 *    Rev 1.5   Mar 04 2002 11:33:22   WuQ
 * Extra Fields for composite glyph
 * 
 *    Rev 1.4   Oct 23 2001 13:31:18   Paul
 * End the files with a single newline
 * 
 *    Rev 1.3   Jan 30 2001 15:44:20   Galejs
 * remove unused mirror_char
 * 
 *    Rev 1.2   Sep 26 2000 10:56:44   galejs
 * add PVCS Header/Log strings
 *
 */

#ifndef __FSGLUE__
#define __FSGLUE__


/* two routines need _DS_ arguments */
#include "object.h"

#define POINTSPERINCH				72
#define MAX_ELEMENTS				2
#define MAX_TWILIGHT_CONTOURS		1

#define TWILIGHTZONE 0 /* The point storage */
#define GLYPHELEMENT 1 /* The actual glyph */

#define USE_INTEGER_SCALING		0x0008

/* public phantom points start here */
#define LEFTSIDEBEARING 0
#define RIGHTSIDEBEARING 1
#define TOPSIDEBEARING 2
#define BOTTOMSIDEBEARING 3

/* private phantom points start here */
#define ORIGINPOINT 4
#define LEFTEDGEPOINT 5
#define TOPORIGINPOINT 6
#define TOPEDGEPOINT 7

#define PHANTOMCOUNT 8

typedef struct {
	FS_SHORT xMin;
	FS_SHORT yMin;
	FS_SHORT xMax;
	FS_SHORT yMax;
} sfnt_BBox;

typedef struct {
	FS_SHORT 		numberContours;
	FS_SHORT 		*endPoints;				/** vector: indexes into x[], y[] **/
	FS_SHORT 		numberInstructions;
	FS_BYTE  		*instructions;			/** vector **/
	FS_BYTE 		*flags;					/** vector **/
	sfnt_BBox		bbox;
} sfnt_PackedSplineFormat;

typedef struct {
	FS_USHORT advanceWidth;
	FS_SHORT leftSideBearing;
	} HMTX;

typedef struct {
	FS_USHORT advanceHeight;
	FS_SHORT topSideBearing;
	} VMTX;

/*** Offset table ***/
typedef struct {
	FS_LONG			interpreterFlagsOffset;
	FS_LONG			startPointOffset;
	FS_LONG			endPointOffset;
	FS_LONG			oldXOffset;
	FS_LONG			oldYOffset;
	FS_LONG			scaledXOffset;
	FS_LONG			scaledYOffset;
	FS_LONG			newXOffset;
	FS_LONG			newYOffset;
	FS_LONG			onCurveOffset;
} fsg_OffsetInfo;


/*  #define COMPSTUFF  */

/*** Element Information ***/
typedef struct {
	FS_LONG				stackBaseOffset;
	fsg_OffsetInfo		offsets[MAX_ELEMENTS];
	fnt_ElementType 	interpreterElements[MAX_ELEMENTS];
} fsg_ElementInfo;

typedef struct {
    FS_ULONG  Offset;
    FS_ULONG  Length;
} fsg_OffsetLength;

/*** The Internal Key ***/
typedef struct fsg_SplineKey {
	SFNT			*sfnt;
	TTF_MAXP		*maxp;					/* shortcut for sfnt->lfnt->ttf->maxp */

	FS_USHORT		glyphIndex;				/* */
	FS_USHORT		elementNumber;			/* Character Element */

    FS_BYTE*		memoryBases[4];        /* array of memory handles */

	fsg_ElementInfo	elementInfoRec;			/* element info structure */

	FS_USHORT		emResolution;			/* used to be FS_LONG <4> */

	FS_FIXED		fixedPointSize;			/* user point size */
	FS_FIXED		interpScalar;			/* scalar for instructable things */
	FS_FIXED		metricScalar;			/* scalar for metric things */

	transMatrix		currentTMatrix;			/* Current Transform Matrix */
	transMatrix		localTMatrix;			/* Local Transform Matrix */
	FS_BYTE			identityTransformation;
    FS_SHORT        indexToLocFormat;       /* from FontHeader */

	FS_USHORT		fontFlags;				/* copy of header.flags */

	FS_FIXED		pixelDiameter;
	FS_USHORT		nonScaledAW;
	FS_SHORT		nonScaledLSB;
	FS_USHORT		nonScaledAH;
	FS_SHORT		nonScaledTSB;

    FS_USHORT       state;                  /* for error checking purposes */
	FS_LONG			scanControl;			/* flags for dropout control etc.  */
	
	/* for key->memoryBases[PRIVATE_FONT_SPACE_BASE] */
	FS_LONG			offset_storage;
	FS_LONG			offset_functions;
	FS_LONG			offset_instrDefs;		/* <4> */
	FS_LONG			offset_controlValues;
	FS_LONG			offset_globalGS;

    FS_LONG			glyphLength;            /* for comp chars, sum of pieces */
	
	FS_LONG			cvtCount;

	FS_USHORT		numberOf_LongHorMetrics;

	/* new for nested-composite rewrite */
	FS_SHORT num_comps;
	FS_SHORT num_contours;
	FS_LONG  num_points;
	FS_BYTE			localTIsIdentity;
	
	FIXED_VECTOR	tInfo;
	FS_LONG			instructControl;		/* set to inhibit execution of instructions */	
	
	FS_BYTE			executePrePgm;
	FS_BYTE			executeFontPgm;
	FS_BYTE			read_programs;			/* read 'fpgm' and 'prep' ? */
	FS_BYTE			useMyMetrics;
    
	} fsg_SplineKey;


/*Hou Zhidong: name conflict */
/* for the key->state field */
#define ITYPE_INITIALIZED     0x0001
#define ITYPE_NEWSFNT 	0x0002
#define ITYPE_NEWTRANS	0x0004
#define ITYPE_GOTGLYPH	0x0010


#define GLOBALGSTATE(key0)    (fnt_GlobalGraphicStateType*) \
                    ((FS_BYTE *)MP_PTR(key0->memoryBases[PRIVATE_FONT_SPACE_BASE]) + key0->offset_globalGS )

/***************/
/** INTERFACE **/
/***************/

extern FS_ULONG fsg_PrivateFontSpaceSize(_DS_ fsg_SplineKey *key);
extern FS_LONG fsg_GridFit(_DS_ fsg_SplineKey *key, FS_BOOLEAN useHints);

/***************/


/* matrix routines */

/*
 * ( x1 y1 1 ) = ( x0 y0 1 ) * matrix;
 */

extern FS_VOID fsg_FixXYMul( FS_FIXED* x, FS_FIXED* y, transMatrix* matrix );

/*
 *   B = A * B;		<4>
 *
 *         | a  b  0  |
 *    B =  | c  d  0  | * B;
 *         | 0  0  1  |
 */
extern FS_VOID fsg_MxConcat2x2(transMatrix* matrixA, transMatrix* matrixB);

/*
 * scales a matrix by sx and sy.
 *
 *              | sx 0  0  |
 *    matrix =  | 0  sy 0  | * matrix;
 *              | 0  0  1  |
 */
extern FS_VOID fsg_MxScaleAB(FS_FIXED sx, FS_FIXED sy, transMatrix *matrixB);

extern FS_VOID fsg_ReduceMatrix(fsg_SplineKey* key);

/*
 *	Used in FontScaler.c and MacExtra.c, lives in FontScaler.c
 */
FS_LONG fsg_RunFontProgram(_DS_ fsg_SplineKey* key );


/* 
** Other externally called functions.  Prototype calls added on 4/5/90
*/
FS_VOID fsg_IncrementElement(fsg_SplineKey *key, FS_LONG n, FS_LONG numPoints, FS_LONG numContours);

FS_VOID fsg_InitInterpreterTrans(_DS_ fsg_SplineKey *key  );

FS_LONG fsg_InnerGridFit(_DS_ fsg_SplineKey *key, FS_SHORT useHints,
	sfnt_BBox *bbox, FS_LONG sizeOfInstructions, FS_BYTE *instructionPtr, FS_LONG finalCompositePass);

FS_VOID fsg_SetUpElement(_DS_ fsg_SplineKey *key, FS_LONG n);

FS_ULONG fsg_WorkSpaceSetOffsets(_DS_ fsg_SplineKey *key);

FS_LONG fsg_SetDefaults(_DS_ fsg_SplineKey* key );

FS_LONG fsg_RunPreProgram(_DS_ fsg_SplineKey *key);


#endif  /* __FSGLUE__ */
