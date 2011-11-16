

// Copyright (c) 04-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ADDRBK_ENG_PHONECATEGORY_H
#define ADDRBK_ENG_PHONECATEGORY_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstrlist.h>
#include "ADDRBK_ENG_Category.h"

class ADDRBK_ENG_C2C;

class ADDRBK_ENG_PhoneCategory : public ADDRBK_ENG_Category
{
public:
    ADDRBK_ENG_PhoneCategory(ADDRBK_UID_T uid = 0);

    ADDRBK_ENG_PhoneCategory(const ADDRBK_ENG_PhoneCategory& phoneCategory);

    virtual ~ADDRBK_ENG_PhoneCategory();

    virtual ADDRBK_RECORD_TYPE_T getType() const;

    virtual ADDRBK_ENG_RESULT_T commit(int profileID = -1);

    static ADDRBK_ENG_RESULT_T isCategory(BOOL& isCategory,
                                          const QString& category);

    static ADDRBK_ENG_RESULT_T addCategory(const QString& category);

    static ADDRBK_ENG_RESULT_T deleteCategory(
        const QString& category,
        BOOL deleteUnassignedMember);

    static ADDRBK_ENG_RESULT_T renameCategory(
        const QString& currentCategory,
        const QString& newCategory);

    static ADDRBK_ENG_RESULT_T addCategoryMembers(
        ADDRBK_UID_T cateUID,
        QValueList<ADDRBK_UID_T>& memberUIDs,
        bool bMerge = false);

    static ADDRBK_ENG_RESULT_T findCategoryUID(
        ADDRBK_UID_T& cateUID,
        const QString& name);
protected:
    virtual bool isSupportedField(ADDRBK_FIELD_TYPE_T field) const;

private:
    ADDRBK_ENG_RESULT_T updateC2C(bool bUpdate = false);

    static ADDRBK_ENG_RESULT_T reportChange(ADDRBK_UID_T uid);

    static void reportChange(
            QValueList<ADDRBK_UID_T>& uidList,
            bool bDelete = true);

    static void sendMsg(ADDRBK_UID_T uid,
            QValueList<ADDRBK_UID_T>& uidList,
            BOOL deleteUnassignedMember);

    static ADDRBK_ENG_RESULT_T deleteUnassignedMembers(
        QStrList& vrList,
        QStrList& calEventList,
        QValueList<ADDRBK_UID_T>& uidList);

    static void deleteVRLocal(const QStrList& vrList);

    static void deleteCalEvent(const QStrList& CalEventList);

    ADDRBK_ENG_RESULT_T handleCommitNewCategory(ADDRBK_UID_T tmpUID);

    static ADDRBK_ENG_RESULT_T addLinkedUSimCateMembers(
                       ADDRBK_UID_T cateUID,
                       QValueList<ADDRBK_UID_T>& memberUIDs);
};

#endif  
