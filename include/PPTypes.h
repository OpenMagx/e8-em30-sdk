

// Copyright (c) 17-Jul-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PP_TYPES_H 
#define PP_TYPES_H

#include "EZX_TypeDefs.h"
#include "ImpsExternalTypes.h"
#include "ImpsResultCodes.h"

#define PP_TRANS_ID_INVALID  0

typedef enum 
{
    PP_REQ_SUMMARY_FAILURE,
    PP_REQ_SUMMARY_SUCCESS,
    PP_REQ_SUMMARY_UNDEFINED, 
} PP_REQUEST_SUMMARY_T; 

typedef UINT32 PP_TRANS_ID_T;

typedef struct 
{
    PP_TRANS_ID_T          transactionId;
    PP_REQUEST_SUMMARY_T   summary;
} PP_REQUEST_RESPONSE_T; 

#endif  
