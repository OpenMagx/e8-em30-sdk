

// Copyright (c) 04-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ADDRBK_ENG_GLOBAL_H
#define ADDRBK_ENG_GLOBAL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>
#include <qlist.h>
#include <qvaluelist.h>
#include "ADDRBK_ENG_Def.h"

typedef struct {
    ADDRBK_RECORD_TYPE_T recordType;
    ADDRBK_UID_T uid;
    QString name;
    QString birth;
    QString anniversary;
    QString picture;
    QString ringAlert;
    QString video;
    QString lightAlert;
    QString messageAlert;
    ADDRBK_ATTR_TYPE_T contentType;
    QString content;
    ADDRBK_RECORD_ID_T recordID;
    bool privacy;
} ADDRBK_SEARCH_RESULT_S;

typedef struct {
    ADDRBK_RECORD_TYPE_T recordType;
    ADDRBK_UID_T uid;
    QString firstName;
    QString lastName;
} ADDRBK_VR_INFO_S;

typedef struct {
    ADDRBK_RECORD_TYPE_T recordType;
    ADDRBK_UID_T uid;
    QString contactName;
    ADDRBK_RECORD_ID_T recID;
    ADDRBK_ATTR_TYPE_T type;
    QString value;
} ADDRBK_RECIPIENT_S;

typedef struct {
    ADDRBK_ATTR_TYPE_T type;
    QString number;
} ADDRBK_NUM_TYPE_S;

class ADDRBK_ENG_Content {
public :
    ADDRBK_ENG_Content();

    ADDRBK_ENG_Content(const ADDRBK_ENG_Content& con);

    ADDRBK_ENG_Content &operator=( const ADDRBK_ENG_Content & );

    ADDRBK_RECORD_ID_T recordID;
    ADDRBK_ATTR_TYPE_T attrType;
    QString attrName;
    QString content;

    UINT32 defaultFlag;
};

class ADDRBK_ENG_Address {
public :
    ADDRBK_ENG_Address();
    ADDRBK_ENG_Address(const ADDRBK_ENG_Address& address);

    ADDRBK_ENG_Address &operator=( const ADDRBK_ENG_Address & );

    bool isEmpty() const;

    ADDRBK_RECORD_ID_T      recordID;
    ADDRBK_ATTR_TYPE_T      attrType;
    QString                 addtional;
    QString                 street;
    QString                 city;
    QString                 state;
    QString                 zip;
    QString                 country;
};

class ADDRBK_ENG_SearchListResult {
public:
    ADDRBK_ENG_SearchListResult();
    friend bool operator==(
        const ADDRBK_ENG_SearchListResult& left,
        const ADDRBK_ENG_SearchListResult& right);

    ADDRBK_UID_T uid;
    QString name;
    QString nameKey;
    int pos; 
    QList<ADDRBK_NUM_TYPE_S> numbers;
};

class ADDRBK_ENG_Blocker
{
public:
    ADDRBK_ENG_Blocker();
    ~ADDRBK_ENG_Blocker();
    QString getName() const;
    QString	  name;	
    ADDRBK_UID_T  uid;
    QString	  content;	
};

#endif  
