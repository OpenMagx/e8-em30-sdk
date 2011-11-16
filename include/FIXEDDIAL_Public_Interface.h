

// Copyright (c) 04-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef FIXEDDIAL_PUBLIC_INTERFACE_H
#define FIXEDDIAL_PUBLIC_INTERFACE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#ifndef QVALUELIST_H
#include <qvaluelist.h>
#endif

#ifndef EZX_TYPEDEF_H 
#include "EZX_TypeDefs.h"
#endif

#define FDN_ENG_CHANNEL "fdn(FDN_ENG_Channel)"   
#define FDN_ENG_MSG     "fdn(FDN_ENG_Msg)"     

typedef enum
{
    FDN_RECORD_CREATED, 
    FDN_RECORD_UPDATED, 
    FDN_RECORD_DELETED, 
    FDN_RECORD_DELETED_ALL, 
}FdnMsgTypeE;

typedef enum {
     FDN_MATCH_SUCC, 
     FDN_MATCH_FAIL, 
}FdnMatchResultE;

typedef struct
{
    QString name; 
    QString number; 
    UINT16 location; 
}FdnMatchResultS;

typedef struct
{
    FdnMatchResultS match_result; 
    FdnMsgTypeE       msg_type; 
}FdnMsgS;

class FIXEDDIAL_Public_Interface
{
public:
    FIXEDDIAL_Public_Interface();

    virtual ~FIXEDDIAL_Public_Interface();

    static FdnMatchResultE  searchByNumberRTL(
                                   FdnMatchResultS& r_matchResult,
                                   const QString& cr_searchNumber);
};

#endif  
