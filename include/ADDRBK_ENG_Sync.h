

// Copyright (c) 04-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ADDRBK_ENG_SYNC_H
#define ADDRBK_ENG_SYNC_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ADDRBK_ENG_Global.h"
#include "ADDRBK_ENG_PhoneContact.h" 

class ADDRBK_ENG_TAPI;

class ADDRBK_ENG_Sync {
public:
    typedef enum {
        PHONE     = 0x0001,
        SIM       = 0x0002,
        PHONE_SIM = 0x0003,
    } STORAGE_TYPE_T;

    ADDRBK_ENG_Sync();
    ~ADDRBK_ENG_Sync();

    ADDRBK_ENG_RESULT_T getVCardRecord(
        UINT8 **ppVCard,
        int& len,
        int logicUID,
        ADDRBK_ENG_VCARD_VERSION_T version = ADDRBK_ENG_VCARD_VERSION_21,
        int pictureSize = 0);

    ADDRBK_ENG_RESULT_T getVCardRecord(
        int fd,
        int& len,
        int logicUID,
        ADDRBK_ENG_VCARD_VERSION_T version = ADDRBK_ENG_VCARD_VERSION_21,
        int maxSize = 0,
        int pictureSize = 0);

    ADDRBK_ENG_RESULT_T addVCardRecord(int& logicUID, const UINT8 *pVCard);

    ADDRBK_ENG_RESULT_T addVCardRecord(int& logicUID, int fd);

    ADDRBK_ENG_RESULT_T updateVCardRecord(int logicUID, const UINT8 *pVCard);

    ADDRBK_ENG_RESULT_T updateVCardRecord(int logicUID, int fd);

    ADDRBK_ENG_RESULT_T deleteRecord(int logicUID);

    ADDRBK_ENG_RESULT_T deleteAllRecords();

    ADDRBK_ENG_RESULT_T addRecord(
        int& logicUID,
        ADDRBK_ENG_PhoneContact& contact);

    ADDRBK_ENG_RESULT_T updateRecord(
        int logicUID,
        ADDRBK_ENG_PhoneContact& contact);

    ADDRBK_ENG_RESULT_T getRecord(
        ADDRBK_ENG_PhoneContact** ppContact,
        int logicUID);

    ADDRBK_ENG_RESULT_T getAllLUIDs(int** ppLUIDs, int& count);

    ADDRBK_ENG_RESULT_T getLUIDs(
        int** ppLUIDs,
        int& count,
        QString* pFirstName,
        QString* pLastName);

    void beginSync(int syncProfileID = -1, STORAGE_TYPE_T storage = PHONE_SIM);

    void endSync();

private:
    ADDRBK_ENG_RESULT_T checkStorageType(STORAGE_TYPE_T storage = PHONE_SIM);
    ADDRBK_ENG_RESULT_T getContact(ADDRBK_ENG_Contact*& pContact, 
        int logicUID, 
        bool toCheckProtected);

    ADDRBK_ENG_RESULT_T getUICCContact(ADDRBK_ENG_Contact*& pContact, 
                                       int logicUID);

    ADDRBK_ENG_RESULT_T combineSearchName(QString& searchName,
                                   QString* pFirstName,
                                   QString* pLastName);

    ADDRBK_ENG_RESULT_T getAllSimRecordLUIDS(
                                   QValueList<ADDRBK_UID_T>& simList);

    ADDRBK_ENG_RESULT_T deleteUICCRecord(int logicUID);

private:
    int syncProfileID;
    STORAGE_TYPE_T storage;
    bool bStorageMatched;
    ADDRBK_ENG_TAPI* tapi;
};

#endif  
