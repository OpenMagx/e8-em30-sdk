

// Copyright (c) 09-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ADDRBK_ENG_USIMCONTACT_H
#define ADDRBK_ENG_USIMCONTACT_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ADDRBK_ENG_Contact.h"
#include <qmap.h>

class ADDRBK_ENG_C2C;

class ADDRBK_ENG_USimContact : public ADDRBK_ENG_Contact
{
public:
    ADDRBK_ENG_USimContact(ADDRBK_UID_T uid = 0);

    ADDRBK_ENG_USimContact(const ADDRBK_ENG_USimContact& usimContact);

    virtual ~ADDRBK_ENG_USimContact();

    virtual ADDRBK_ENG_Contact* clone();

    virtual ADDRBK_RECORD_TYPE_T getType() const;

    virtual const QString& getPrintName() const;

    virtual ADDRBK_ENG_RESULT_T commit(int profileID = -1);

    ADDRBK_ENG_Content* getDefault(ADDRBK_DEFAULT_TYPE_T defaultType) const;
protected:
    virtual bool isSupportedField(ADDRBK_FIELD_TYPE_T field) const;

    virtual bool isSupportedContent(ADDRBK_FIELD_TYPE_T field) const;

private:
    ADDRBK_ENG_RESULT_T add(int profileID);
    ADDRBK_ENG_RESULT_T update(int profileID);
    ADDRBK_ENG_RESULT_T updateUsimCategory(ADDRBK_ENG_C2C& c2c,
           const QMap<QString, ADDRBK_UID_T>& map, bool update);
    ADDRBK_ENG_RESULT_T hasEnoughFields();
#ifdef _FEAT_LJP2P_VT
    ADDRBK_ENG_RESULT_T updateBlockList(ADDRBK_ENG_Contact& oldContact);
#endif
};

#endif  
