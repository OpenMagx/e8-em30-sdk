

// Copyright (c) 04-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ADDRBK_ENG_CONTACT_H
#define ADDRBK_ENG_CONTACT_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ADDRBK_ENG_Record.h"

class ADDRBK_ENG_Contact : public ADDRBK_ENG_Record
{
public:
    ADDRBK_ENG_Contact(ADDRBK_UID_T uid = 0, int capacity = 0);

    virtual ~ADDRBK_ENG_Contact();

    virtual ADDRBK_ENG_Contact* clone() = 0;

    const QValueList<QString>* getCategories() const;

    void addToCategory(const QString& category);

    void removeFromCategory(const QString& category);

    void clearCategories();

    void setBoolean(ADDRBK_FIELD_TYPE_T field, BOOL value);

    BOOL getBoolean(ADDRBK_FIELD_TYPE_T field) const;

    virtual const QString& getPrintName() const = 0;

    virtual ADDRBK_ENG_Content* createContent(ADDRBK_FIELD_TYPE_T field);

    virtual int sizeContent(ADDRBK_FIELD_TYPE_T field) const;

    virtual ADDRBK_ENG_Content* getContent(ADDRBK_FIELD_TYPE_T field, int index) const;

    virtual void removeContent(ADDRBK_FIELD_TYPE_T field, int index);

    virtual void clearContent(ADDRBK_FIELD_TYPE_T field);

    ADDRBK_ENG_Content* getDefault(ADDRBK_DEFAULT_TYPE_T defaultType) const;

protected:
    ADDRBK_ENG_Contact(const ADDRBK_ENG_Contact& contact);

    void truncateContent(ADDRBK_FIELD_TYPE_T field);

    virtual bool isSupportEmpty() const { return m_capacity == 1; }

    virtual bool isSupportedContent(ADDRBK_FIELD_TYPE_T field) const = 0;

    ADDRBK_FIELD_TYPE_T
    mapEnumDefaultToContent(ADDRBK_DEFAULT_TYPE_T defaultType) const;

    QString* findCategory(const QString& category) const;

    QValueList<QString>* pCategories;

private:

    QList<ADDRBK_ENG_Content>* getListContent(ADDRBK_FIELD_TYPE_T field) const;
    QList<ADDRBK_ENG_Content>** getListPointer(ADDRBK_FIELD_TYPE_T field);
    void copyContent(const ADDRBK_ENG_Contact& phoneContact,
        ADDRBK_FIELD_TYPE_T fieldType);

    int m_capacity;
    UINT32 booleanFields;
    QList<ADDRBK_ENG_Content> *pListTels;
    QList<ADDRBK_ENG_Content> *pListEmails;
    QList<ADDRBK_ENG_Content> *pListIMs;
    QList<ADDRBK_ENG_Content> *pListURLs;
};

#endif  
