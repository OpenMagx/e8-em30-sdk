

// Copyright (c) 04-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ADDRBK_ENG_PHONECONTACT_H
#define ADDRBK_ENG_PHONECONTACT_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qmap.h>
#include "ADDRBK_ENG_Contact.h"

class ADDRBK_ENG_DEL_INFO;
class ADDRBK_ENG_DLOpen;

class ADDRBK_ENG_PhoneContact : public ADDRBK_ENG_Contact
{
public:
    ADDRBK_ENG_PhoneContact(ADDRBK_UID_T uid = 0, int capacity = 0);

    ADDRBK_ENG_PhoneContact(const ADDRBK_ENG_PhoneContact& phoneContact);

    virtual ~ADDRBK_ENG_PhoneContact();

    virtual ADDRBK_ENG_Contact* clone();

    virtual ADDRBK_RECORD_TYPE_T getType() const;

    virtual const QString& getPrintName() const;

    ADDRBK_ENG_Content* getDefaultNumberByMFMR() const;

    ADDRBK_ENG_Address* createAddress();

    int sizeAddress() const;

    ADDRBK_ENG_Address* getAddress(int index) const;

    void removeAddress(int index);

    void clearAddress();

    virtual ADDRBK_ENG_RESULT_T commit(int profileID = -1);

    ADDRBK_ENG_RESULT_T commitDefault(
        ADDRBK_DEFAULT_TYPE_T defaultType,
        ADDRBK_RECORD_ID_T recordID);

    ADDRBK_ENG_Content* getDefault(ADDRBK_DEFAULT_TYPE_T defaultType) const;

protected:
    ADDRBK_ENG_RESULT_T directCommit();

    virtual bool isSupportedField(ADDRBK_FIELD_TYPE_T field) const;

    virtual bool isSupportedContent(ADDRBK_FIELD_TYPE_T field) const;

private:

    ADDRBK_ENG_RESULT_T add();
    ADDRBK_ENG_RESULT_T update();
    ADDRBK_ENG_RESULT_T updateCategory(bool bUpdate = false);
    ADDRBK_RECORD_ID_T getRecIDForCate();

    void truncateAddress();
    void removeOldVoiceTag(ADDRBK_ENG_DEL_INFO& alarmInfo);
    void removeAlarmBirthday(ADDRBK_ENG_DEL_INFO& alarmInfo,ADDRBK_ENG_DLOpen& calendarLib);
    void removeAlarmAnniversary(ADDRBK_ENG_DEL_INFO& alarmInfo,ADDRBK_ENG_DLOpen& calendarLib);

    void removeOldExtInfo(ADDRBK_ENG_DEL_INFO& alarmInfo);

    void copyAddress(const ADDRBK_ENG_PhoneContact& phoneContact);

    ADDRBK_ENG_RESULT_T ownerContactHandler(bool& bCreate);
    ADDRBK_ENG_RESULT_T pttHandler();

    ADDRBK_ENG_RESULT_T preDirectCommit(bool& bCreate);
    ADDRBK_ENG_RESULT_T updateTable(ADDRBK_ENG_PhoneContact& tmpContact);
    ADDRBK_ENG_RESULT_T addTable();

    QList<ADDRBK_ENG_Address>  *pListAddresses;
    int                        mProfileID;
    mutable QString            printedName;
};

#endif  
