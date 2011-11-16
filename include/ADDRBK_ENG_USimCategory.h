

// Copyright (c) 09-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ADDRBK_ENG_USIMCATEGORY_H
#define ADDRBK_ENG_USIMCATEGORY_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstrlist.h>
#include "ADDRBK_ENG_Category.h"

class ADDRBK_ENG_C2C;

class ADDRBK_ENG_USimCategory : public ADDRBK_ENG_Category
{
public:

    ADDRBK_ENG_USimCategory(ADDRBK_UID_T uid = 0);

    ADDRBK_ENG_USimCategory(const ADDRBK_ENG_USimCategory& usimCategory);
    virtual ~ADDRBK_ENG_USimCategory();

    virtual ADDRBK_RECORD_TYPE_T getType() const;

    virtual ADDRBK_ENG_RESULT_T commit(int profileID = -1);

    static ADDRBK_ENG_RESULT_T isCategory(BOOL& isCategory,
                                          const QString& category);

    static ADDRBK_ENG_RESULT_T addCategory(QString& category);

    static ADDRBK_ENG_RESULT_T deleteCategory(const QString& category,
                                              BOOL deleteUnassignedMember = FALSE);

    static ADDRBK_ENG_RESULT_T renameCategory(
        const QString& currentCategory,
        QString& newCategory);

    static ADDRBK_ENG_RESULT_T addCategoryMembers(
        ADDRBK_UID_T cateUID,
        QValueList<ADDRBK_UID_T>& memberUIDs);

    static ADDRBK_ENG_RESULT_T findCategoryUID(
        ADDRBK_UID_T& cateUID,
        const QString& name);

protected:
    virtual bool isSupportedField(ADDRBK_FIELD_TYPE_T field) const;

private:
    static void reportChange(const QList<ADDRBK_ENG_C2C>& list);

    static ADDRBK_ENG_RESULT_T deleteUnassignedContacts(
        const QValueList<ADDRBK_UID_T>& contactUIDs);
    ADDRBK_ENG_RESULT_T updateC2C(bool bUpdate = false);
};

#endif  
