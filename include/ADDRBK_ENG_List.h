

// Copyright (c) 04-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ADDRBK_ENG_LIST_H
#define ADDRBK_ENG_LIST_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ADDRBK_ENG_Contact.h"

class ADDRBK_ENG_List
{
public:
    ADDRBK_ENG_List(ADDRBK_FILTER_TYPE_T filterType,
        bool containGroup = true,
        ADDRBK_UID_T categoryUID = 0,
        bool containPrivate = false,
        ADDRBK_ENG_STORAGE_T storageType = ADDRBK_ENG_STORAGE_UNKNOWN
        );

    ~ADDRBK_ENG_List();

    int getIndex(const ADDRBK_CONTACT_UID_S &contactUID) const;

    bool getContactUID(ADDRBK_CONTACT_UID_S &contactUID, int index) const;

    bool getContact(ADDRBK_ENG_Contact &contact) const;

    int count() const;

    bool remove(const ADDRBK_CONTACT_UID_S &contactUID);

    int searchByName(const QString &searchString) const;

    bool getSortedName(QString& sortedName,
                                        const ADDRBK_CONTACT_UID_S& contactUID);
    void setName(const QString &name) { this->mName = name; }

    QString getName() const { return mName; }

    ADDRBK_FILTER_TYPE_T getFilterType() const { return mFilterType; }

    bool getGroupFlag() const { return mContainGroup; }

    ADDRBK_UID_T getCategoryUID() const { return mCategoryUID; }

    bool getPrivateFlag() const { return mContainPrivate; }

    const QList<ADDRBK_CONTACT_UID_S>* getList() const {return pListContactUID;}

private:
    QList<ADDRBK_CONTACT_UID_S> *pListContactUID; 
    QList<QString> *pSortedName; 
    QString mName; 

    ADDRBK_FILTER_TYPE_T mFilterType; 
    bool mContainGroup; 
    bool mContainPrivate; 
    ADDRBK_UID_T mCategoryUID; 

};

#endif  
