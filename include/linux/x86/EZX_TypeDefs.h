#ifndef EZX_TYPEDEFINE_H
#define EZX_TYPEDEFINE_H
/*================================================================================

(c) Copyright Motorola 1999-2008, All Rights Reserved

================================================================================*/

/*================================================================================
                                      CONSTANTS
================================================================================*/
#ifndef TRUE
#define    TRUE                 1
#define    FALSE                0
#endif

#ifndef NULL
#ifdef  __cplusplus
#define    NULL                 0
#else
#define    NULL                 ((void *)0)
#endif
#endif

/*================================================================================
                                      TYPEDEFS
================================================================================*/

#ifndef SU_BASICTYPES_H

typedef    unsigned char        UINT8;
typedef    signed char          INT8;
typedef    unsigned short int   UINT16;
typedef    signed short int     INT16;
typedef    unsigned  int        UINT32;
typedef    signed int           INT32;
typedef    UINT8                BOOLEAN;

/* BOOL Boolean Value by YWT/w19539*/
#ifndef BOOL 
typedef int  BOOL ;
#endif


#ifndef _W_CHAR
#define _W_CHAR
typedef unsigned short W_CHAR;
#endif

/*Define ended*/

#endif

typedef    UINT8*                   P_UINT8;
typedef    INT8*                    P_INT8;
typedef    UINT16*              P_UINT16;
typedef    INT16*               T_INT16;
typedef    UINT32*              P_UINT32;
typedef    INT32*               P_INT32;

// modified by Bingqi Zhao in order to integration
// because there is a conflict with tapi define

/*==============================================================================*/
#endif  /* EZX_TYPEDEFINE_H */
