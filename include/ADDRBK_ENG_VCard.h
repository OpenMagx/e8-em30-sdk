

// Copyright (c) 04-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ADDRBK_ENG_VCARD_H
#define ADDRBK_ENG_VCARD_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qvaluelist.h>
#include <qstringlist.h>
#include "ADDRBK_ENG_Global.h"

class ADDRBK_ENG_Contact;

class ADDRBK_ENG_VCard {
public:
    typedef enum {
        TO_PHONE,
        TO_SIM,
        TO_USIM
    } TO_DEST_T;

    static bool fromSerialFormat(
        QList<ADDRBK_ENG_Contact>& contacts,
        const char *pVCard,
        TO_DEST_T toDest = TO_PHONE, 
        const char *enc = NULL, 
        QList<QStringList>* pLIgoreProp = NULL,
        QValueList<int>* pDecoderFlags = NULL);

    static bool toSerialFormat(
        char **ppVCard,
        const ADDRBK_ENG_Contact& contact,
        ADDRBK_ENG_VCARD_VERSION_T version = ADDRBK_ENG_VCARD_VERSION_21,
        const char *enc = NULL );
};

#endif  
