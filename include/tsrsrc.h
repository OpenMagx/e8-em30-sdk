/*****************************************************************************
 *
 *  tsrsrc.h - Defines interface to TsResource structure.
 *
 *  Copyright (C) 2003-2005 Monotype Imaging Inc. All rights reserved.
 *
 *  $Archive:   I:/BULL/DisplayImaging/archives/wtle/product/source/include/tsrsrc.h_v  $ 
 *  $Date:   May 16 2005 15:18:36  $
 *  $Revision:   1.8  $
 *
 ****************************************************************************/

#ifndef TSRSRC_H
#define TSRSRC_H

#include "tsproj.h"

TS_BEGIN_HEADER


/*****************************************************************************
 *
 *  An enumeration of resource types.
 *
 *  <GROUP resource>
 */
typedef enum TsResourceType
{
    TS_RESOURCETYPE_PATH = 0,    /* resource is a file with a file system path */
    TS_RESOURCETYPE_MEMORY = 1   /* resource is a memory-mapped file */
} TsResourceType;


/*****************************************************************************
 *
 *  A structure that describes a memory unit (location and length in bytes)
 *
 *  <GROUP resource>
 */
struct TsMemLoc
{
    void *address;              /* address */
    TsLength length;            /* length in bytes */
};


/*****************************************************************************
 *
 *  A structure that describes a resource stored in a file or memory.
 *
 *  <GROUP resource>
 */
typedef struct TsResource
{
    TsResourceType type;
    union
    {
        struct TsMemLoc mem;    /* memory location and length */
        TsChar *path;           /* file path */
    } file;
} TsResource;


/*****************************************************************************
 *
 *  Compares two TsResource objects for equality.
 *
 *  Parameters:
 *      r1          - [in] pointer to first of two resource structures
 *      r2          - [in] pointer to second of two resource structures
 *
 *  Return value:
 *      TsBool TRUE if two resources are considered equal, FALSE otherwise
 *
 *  <GROUP resource>
 */
TS_EXPORT(TsBool)
TsResource_isEqual(TsResource *r1, TsResource *r2);


/*****************************************************************************
 *
 *  Initializes a TsResource structure as a file path.
 *
 *  Parameters:
 *      resource    - [in/out] pointer to resource structure
 *      path        - [in] pointer to full file path
 *
 *  Return:
 *      none
 *
 *  Notes:
 *      The path argument is a string indicating the full path to a file
 *      stored on a file system.  This function copies the pointer, but
 *      does not copy the data that it points to.  The calling routine
 *      must not use this structure after freeing this pointer.
 *
 *  <GROUP resource>
 */
TS_EXPORT(void)
TsResource_initPath(TsResource *resource, TsChar *path);


/*****************************************************************************
 *
 *  Intialize a TsResource structure as a memory location.
 *
 *  Parameters:
 *      resource    - [in/out] pointer to resource structure
 *      address     - [in] address of memory-mapped file
 *      length      - [in] length of memory-mapped file in bytes.
 *
 *  Return:
 *      none
 *
 *  <GROUP resource>
 */
TS_EXPORT(void)
TsResource_initMem(TsResource *resource, void *address, TsLength length);


TS_END_HEADER

#endif /* TSRSRC_H */
