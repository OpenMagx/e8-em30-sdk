

// Copyright (c) 11-Jun-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ADDRBK_ENG_CATEGORY_H
#define ADDRBK_ENG_CATEGORY_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ADDRBK_ENG_Record.h"

class ADDRBK_ENG_Category : public ADDRBK_ENG_Record
{
public:
    ADDRBK_ENG_Category(ADDRBK_UID_T uid = 0);

    virtual ~ADDRBK_ENG_Category();

    static ADDRBK_ENG_Category* createCategory(
        ADDRBK_RECORD_TYPE_T recordType,
        ADDRBK_UID_T uid = 0);

    void setMembers(const QList<ADDRBK_RECIPIENT_S>& recipients);

    const QList<ADDRBK_RECIPIENT_S>& getMembers(int recipType) const;

    int getMemberCount(int recipType) const;

    void setToUpdateMembers(BOOL toUpdateMembers) {
        m_bToUpdateMembers = toUpdateMembers;
    }

protected:
    ADDRBK_ENG_Category(const ADDRBK_ENG_Category& category);

    BOOL m_bToUpdateMembers;

    QList<ADDRBK_RECIPIENT_S> m_recipients;

private:

    void copyMembersDeeply(const QList<ADDRBK_RECIPIENT_S>& srcList);

    void divideMembers();

    QList<ADDRBK_RECIPIENT_S> m_msgRecipients;

    QList<ADDRBK_RECIPIENT_S> m_numberRecipients;

    QList<ADDRBK_RECIPIENT_S> m_emailRecipients;
};

#endif  
