

// Copyright (c) 04-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ADDRBK_ENG_SIMCONTACT_H
#define ADDRBK_ENG_SIMCONTACT_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ADDRBK_ENG_Contact.h"

class ADDRBK_ENG_SimContact : public ADDRBK_ENG_Contact
{
public:
    ADDRBK_ENG_SimContact(ADDRBK_UID_T uid = 0);

    ADDRBK_ENG_SimContact(const ADDRBK_ENG_SimContact& simContact);

    virtual ~ADDRBK_ENG_SimContact();

    virtual ADDRBK_ENG_Contact* clone();

    virtual ADDRBK_RECORD_TYPE_T getType() const;

    virtual const QString& getPrintName() const;

    virtual ADDRBK_ENG_RESULT_T commit(int profileID = -1);

    ADDRBK_ENG_Content* getDefault(ADDRBK_DEFAULT_TYPE_T defaultType) const;

protected:
    virtual bool isSupportedField(ADDRBK_FIELD_TYPE_T field) const;

    virtual bool isSupportedContent(ADDRBK_FIELD_TYPE_T field) const;
};

#endif  
