

// Copyright (c) 04-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ADDRBK_ENG_RECORD_H
#define ADDRBK_ENG_RECORD_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qmap.h>
#include "ADDRBK_ENG_Global.h"

class ADDRBK_ENG_Record
{
public:
    ADDRBK_ENG_Record(ADDRBK_UID_T uid = 0) {
       this->uid = uid;

    }

    virtual ~ADDRBK_ENG_Record() {};

    void setUID(ADDRBK_UID_T uid) {
        this->uid = uid;
    }

    ADDRBK_UID_T getUID() const { return uid; }

    virtual ADDRBK_RECORD_TYPE_T getType() const = 0;

    void setString(ADDRBK_FIELD_TYPE_T field, const QString& value);

    const QString& getString(ADDRBK_FIELD_TYPE_T field) const;

    int sizeStrings(bool containsEmpty = true) const;

    virtual ADDRBK_ENG_RESULT_T commit(int profileID = -1) = 0;

protected:
    ADDRBK_ENG_Record(const ADDRBK_ENG_Record& record);

    void setWarnTruncate(bool bTruncate = true) {
        this->bTruncate = bTruncate;
    }

    ADDRBK_ENG_RESULT_T getWarnResult() {
        if (bTruncate) {
            return ADDRBK_ENG_RES_WARN_TRUNCATED;
        } else {
            return ADDRBK_ENG_RES_SUCCESS;
        }
    }
    virtual bool isSupportedField(ADDRBK_FIELD_TYPE_T field) const = 0;

    virtual bool isSupportEmpty() const { return false; }

private:
    ADDRBK_UID_T uid;

    bool bTruncate;

    QMap<ADDRBK_FIELD_TYPE_T, QString> mapStrings;
};

#endif  
