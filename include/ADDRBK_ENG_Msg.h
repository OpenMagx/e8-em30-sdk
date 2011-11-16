

// Copyright (c) 04-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ADDRBK_ENG_MSG_H
#define ADDRBK_ENG_MSG_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qdatastream.h>
#include "ADDRBK_ENG_Global.h"
#define ADDRBK_ENG_CHANNEL  "addrbk-eng-channel"
#define ADDRBK_ENG_MSG      "addrbk(ADDRBK_ENG_Msg)"

#define ADDRBK_ENG_EXT_CHANNEL  "addrbk-eng-ext-channel"
#define ADDRBK_ENG_PTT_MSG     "addrbk(ADDRBK_ENG_PTT_MSG)"
#define ADDRBK_ENG_VT_MSG      "addrbk(ADDRBK_ENG_VT_MSG)"
#define ADDRBK_ENG_MYFAVE_MSG      "addrbk(ADDRBK_ENG_MYFAVE_MSG)"

typedef enum {
    ADDRBK_RECORD_CREATED = 1,
    ADDRBK_RECORD_UPDATED,
    ADDRBK_RECORD_FIELD_UPDATED,
    ADDRBK_RECORD_DELETED,
    ADDRBK_RECORD_DELETED_ALL,
    ADDRBK_RECORD_UPDATED_BLOCK,
    ADDRBK_SYNC_UPDATED,

    ADDRBK_SYNC_BEGIN = 100,
    ADDRBK_SYNC_END,
    ADDRBK_FREQUENCY_REFRESH,

    ADDRBK_MERGE_BEGIN,
    ADDRBK_MERGE_END,
} ADDRBK_MSG_TYPE_T;

class ADDRBK_ENG_Msg
{
public :
    ADDRBK_ENG_Msg(const QByteArray& data);

    ADDRBK_ENG_Msg(
        ADDRBK_MSG_TYPE_T msgType,
        ADDRBK_RECORD_TYPE_T recordType = (ADDRBK_RECORD_TYPE_T) 0,
        ADDRBK_UID_T uid = 0,
        ADDRBK_FIELD_TYPE_T  fieldType = ADDRBK_STRING_FIELD_TYPE_PICTURE);

    ADDRBK_MSG_TYPE_T getMsgType() const {
      return msgType;
    }

    ADDRBK_RECORD_TYPE_T getRecordType() const {
        return recordType;
    }

    ADDRBK_UID_T getUID() const {
       return uid;
    }

    ADDRBK_FIELD_TYPE_T getFieldType() const {
        return fieldType;
    }

    void send();

    static void directSend(const QCString& channel,
                           const QCString& msg,
                           const QString& content);
private :
    ADDRBK_MSG_TYPE_T msgType;
    ADDRBK_RECORD_TYPE_T recordType;
    ADDRBK_UID_T uid;
    ADDRBK_FIELD_TYPE_T fieldType; 
};

#endif  
