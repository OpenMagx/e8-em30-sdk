

// Copyright (c) 04-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ADDRBK_ENG_FDNCONTACT_H
#define ADDRBK_ENG_FDNCONTACT_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ADDRBK_ENG_SimContact.h"

class ADDRBK_ENG_FdnContact : public ADDRBK_ENG_SimContact
{
public:
    ADDRBK_ENG_FdnContact(ADDRBK_UID_T uid = 0);

    ADDRBK_ENG_FdnContact(const ADDRBK_ENG_FdnContact& fdnContact);

    virtual ~ADDRBK_ENG_FdnContact();

    virtual ADDRBK_ENG_Contact* clone();

    virtual ADDRBK_RECORD_TYPE_T getType() const;

    virtual ADDRBK_ENG_RESULT_T commit(int profileID = -1);

};

#endif  
