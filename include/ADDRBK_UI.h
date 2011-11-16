

// Copyright (c) 04-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ADDRBK_UI_H 
#define ADDRBK_UI_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ADDRBK_ENG_Global.h"
#include <qstring.h>
#include <qwidget.h>
class ADDRBK_ENG_Contact;

#define IID_IAddressBook    QUuid("{d66bd5ef-342c-4404-b465-71fc698a50d9}") 

class ADDRBK_UI{

public:
    enum FormFieldType {
        FIELD_NUMBER,        
        FIELD_PICTURE,       
        FIELD_EMAIL,         
        FIELD_IMID,          
        FIELD_VOICENOTE,     
        FIELD_WEBSITE,       
        FIELD_LOCATION,      
        FIELD_PTTNUMBER
    };

    typedef struct {
        FormFieldType field;
        QString data;
        QString additionalValue;
    } FieldData;

    static int newContact(FormFieldType field, const QString &data,
        ADDRBK_CONTACT_UID_S *uid = NULL, QWidget *parent = 0,
        QString name = QString::null);

    static int newContact();

    static int newContact(QList<FieldData>& fieldlist,
        ADDRBK_CONTACT_UID_S *uid = NULL, QWidget *parent = 0,
        QString name=QString::null);

    static int addDataToContact(FormFieldType field, const QString &data,
        ADDRBK_CONTACT_UID_S *uid = NULL, QWidget *parent = 0);

    static int addDataToContact(QList<FieldData>& fieldlist, 
        ADDRBK_CONTACT_UID_S *uid = NULL);

    static void closeFormView();

    static void viewContactDetail(const ADDRBK_ENG_Contact &rec, QWidget *parent = 0, bool viewOnly = FALSE);

    static void closeDetailView();

    static bool viewVCard(const char *vcard, const char *enc = NULL, QWidget *parent = 0);

    static bool vCardReceived(const char *vcard, const char *enc = NULL, QWidget *parent = 0);

    static void importLBSToNewContact(const char *vcard, const char *enc = "UTF-8"); 

    static void importLBSToContact(const char *vcard, const char *enc = "UTF-8");

    static void viewContactsWithAddress();

};

class ADDRBK_UI_Interface {
public:
    virtual int newContact(ADDRBK_UI::FormFieldType field, const QString &data, ADDRBK_CONTACT_UID_S *uid = NULL,
                           QWidget *parent = 0, QString name = QString::null) = 0;

    virtual int newContact() = 0;

    virtual int newContact(QList<ADDRBK_UI::FieldData>& fieldlist, 
                           ADDRBK_CONTACT_UID_S *uid = NULL,
                           QWidget *parent = 0, QString name=QString::null) = 0;

    virtual int addDataToContact(ADDRBK_UI::FormFieldType field, const QString &data,
		                         ADDRBK_CONTACT_UID_S *uid = NULL, QWidget *parent = 0) = 0;

    virtual int addDataToContact(QList<ADDRBK_UI::FieldData>& fieldlist, 
                                 ADDRBK_CONTACT_UID_S *uid = NULL) = 0;

    virtual void closeFormView() = 0;

    virtual void viewContactDetail(const ADDRBK_ENG_Contact &rec, QWidget *parent = 0, bool viewOnly = FALSE) = 0;

    virtual void closeDetailView() = 0;

    virtual bool viewVCard(const char *vcard, const char *enc = NULL, QWidget *parent = 0) = 0;

    virtual bool vCardReceived(const char *vcard, const char *enc = NULL, QWidget *parent = 0) = 0;

    virtual void importLBSToNewContact(const char *vcard, const char *enc = "UTF-8") = 0; 

    virtual void importLBSToContact(const char *vcard, const char *enc = "UTF-8") = 0;

    virtual void viewContactsWithAddress() = 0;

};

typedef ADDRBK_UI_Interface * (*GET_ADDRBK_UI)();

extern "C" ADDRBK_UI_Interface *getAddrbkUI();

#endif 
