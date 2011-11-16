

// Copyright (c) 04-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ADDRBK_ENG_MANAGER_H
#define ADDRBK_ENG_MANAGER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ADDRBK_ENG_Global.h"
#include "ADDRBK_ENG_PhoneCategory.h"
#include "ADDRBK_ENG_USimCategory.h"
#include "ADDRBK_ENG_PhoneContact.h"
#include "ADDRBK_ENG_Contact.h"
#include "ADDRBK_ENG_Record.h"
#include "ADDRBK_ENG_Def.h"

class QStringList;

class ADDRBK_ENG_Manager
{
public:

    static ADDRBK_ENG_RESULT_T isMemoryFull(
        bool& bFull,
        ADDRBK_RECORD_TYPE_T recordType);

    static ADDRBK_ENG_RESULT_T maxRecordCount(
        INT32& count,
        ADDRBK_RECORD_TYPE_T type);

    static ADDRBK_ENG_RESULT_T getRecordCount(
        INT32& count,
        ADDRBK_RECORD_TYPE_T type,
        bool containPrivate = true);

    static ADDRBK_ENG_RESULT_T getSIMRange(
        ADDRBK_SIM_RANGE_S& range,
        ADDRBK_RECORD_TYPE_T type);

    static ADDRBK_ENG_RESULT_T getUICCRange(
        INT32& range,
        ADDRBK_UICC_FIELD_T field);

    static ADDRBK_ENG_RESULT_T checkExist(
        ADDRBK_RECORD_TYPE_T type,
        ADDRBK_UID_T uid);

    static ADDRBK_ENG_RESULT_T isPrivateRecord(bool& bPrivate,
        ADDRBK_RECORD_TYPE_T recordType,
        ADDRBK_UID_T uid);

    static bool isNumberMatched(const QString& number1, const QString& number2);

    static ADDRBK_ENG_RESULT_T getCategories(
        QList<ADDRBK_ENG_PhoneCategory>& categories);

    static ADDRBK_ENG_RESULT_T getCategories(
        QList<ADDRBK_ENG_USimCategory>& categories);

    static ADDRBK_ENG_RESULT_T getCategory(
        ADDRBK_ENG_PhoneCategory& category,
        const QString& name);

    static ADDRBK_ENG_RESULT_T getCategory(
        ADDRBK_ENG_USimCategory& category,
        const QString& name);

    static ADDRBK_ENG_RESULT_T getRecord(ADDRBK_ENG_Record& record);

    static ADDRBK_ENG_RESULT_T getSimpleContact(
            ADDRBK_ENG_Contact*& pRecord,
            ADDRBK_RECORD_TYPE_T recordType,
            ADDRBK_UID_T uid,
            UINT32 selFlag = 0x0000000F);

    static ADDRBK_ENG_RESULT_T getContact(
        ADDRBK_ENG_Contact*& pRecord,
        ADDRBK_RECORD_TYPE_T recordType,
        ADDRBK_UID_T uid);

    static ADDRBK_ENG_RESULT_T deleteRecord(
        ADDRBK_RECORD_TYPE_T type,
        ADDRBK_UID_T uid,
        int profileID = 0);

    static ADDRBK_ENG_RESULT_T deleteAllRecords(ADDRBK_ENG_STORAGE_T storage,
        int profileID = -1,
        bool bKeepLinkedContact = false);

    static ADDRBK_ENG_RESULT_T getVRInfo(
        QList<ADDRBK_VR_INFO_S>& info,
        ADDRBK_ENG_STORAGE_T storage);

    static ADDRBK_ENG_RESULT_T getVRInfo(ADDRBK_VR_INFO_S& info);

    static BOOL vCardToContact(
        ADDRBK_ENG_Contact& contact,
        const UINT8 *pVCard,
        INT32 len = -1,
        int* pDecoderFlag = NULL);

    static BOOL contactToVcard(
        UINT8 **ppVCard,
        INT32& len,
        const ADDRBK_ENG_Contact& contact,
        ADDRBK_ENG_VCARD_VERSION_T version = ADDRBK_ENG_VCARD_VERSION_21);

    static ADDRBK_ENG_RESULT_T contactToSearchResult(
            ADDRBK_SEARCH_RESULT_S &result,
            const ADDRBK_ENG_Contact& contact,
            const QString& searchNumber = NULL);

    static ADDRBK_ENG_RESULT_T searchByName(
        QValueList<ADDRBK_UID_T> &resultList,
        ADDRBK_RECORD_TYPE_T recordType,
        const QString& searchString,
        bool excludeFullContact = false);

    static ADDRBK_ENG_RESULT_T searchByNumber(
        ADDRBK_SEARCH_RESULT_S& result,
        const QString& searchNumber);

    static ADDRBK_ENG_RESULT_T searchByNumber(
        ADDRBK_SEARCH_RESULT_S& result,
        const QString& searchNumber,
        bool includePrivate);

    static ADDRBK_ENG_RESULT_T searchByNumber(
        ADDRBK_SEARCH_RESULT_S& result,
        const QString& searchNumber,
        const QString& searchName);

    static ADDRBK_ENG_RESULT_T searchByEmail(
        ADDRBK_SEARCH_RESULT_S& result,
        const QString& searchEmail);

    static ADDRBK_ENG_RESULT_T searchByEmail(
        ADDRBK_SEARCH_RESULT_S& result,
        const QString& searchEmail,
        const QString& searchName);

    static ADDRBK_ENG_RESULT_T searchByIM(
        ADDRBK_ENG_PhoneContact& contact,
        const QString& IMID,
        const QString *pSearchName = NULL);

    static ADDRBK_ENG_RESULT_T searchByVR(
        ADDRBK_ENG_PhoneContact& contact,
        const QString& voiceTag);

    static ADDRBK_ENG_RESULT_T searchByUIDAndRecordType(
            ADDRBK_SEARCH_RESULT_S& result,
            const ADDRBK_UID_T& uid,
            const ADDRBK_RECORD_TYPE_T& type = ADDRBK_RECORD_TYPE_PHONECONTACT,
            const QString& searchNumber = NULL);
    static ADDRBK_ENG_RESULT_T searchInAllFields(
        QValueList<ADDRBK_UID_T> &resultList,
        ADDRBK_RECORD_TYPE_T recordType,
        const QString& searchString);

    static ADDRBK_ENG_RESULT_T searchByItem(
        QValueList<ADDRBK_UID_T>& resultList,
        const ADDRBK_ENG_Contact& contact);

    static ADDRBK_ENG_RESULT_T syncVoiceTags(QStringList& vrList);

    static ADDRBK_ENG_RESULT_T trackSIM(ADDRBK_SIM_TRACK_T& ret);

    static ADDRBK_ENG_RESULT_T getStorageType(ADDRBK_ENG_STORAGE_T& ret);

    static ADDRBK_ENG_RESULT_T getUICCType(ADDRBK_UICC_TYPE_T& type);

    static void updateMFMR(
        ADDRBK_FREQUENCY_TYPE_T type,
        const ADDRBK_RECIPIENT_S& info);

    static void updateMFMR(
        ADDRBK_FREQUENCY_TYPE_T type,
        const QList<ADDRBK_RECIPIENT_S>& infos);

    static bool getSortFlag();

    static ADDRBK_ENG_RESULT_T saveSimpleContact(QString& name, QString& number);

    static ADDRBK_ENG_RESULT_T maxCountTelsOfUsimContact(UINT32& count);

    static ADDRBK_ENG_RESULT_T maxCountEmailsOfUsimContact(UINT32& count);

    static ADDRBK_UID_T getUSimContactUID(int location);

    static ADDRBK_ENG_RESULT_T saveSimpleContact(ADDRBK_UID_T& uid,
                                     QString& name, QString& number);

    static ADDRBK_ENG_RESULT_T getPTTFlag(bool& flag, const QString& number);

    static ADDRBK_ENG_RESULT_T setPTTFlag(bool flag, const QString& number,
        bool byServer = false, ADDRBK_UID_T uid = 0, const QString& name = "");

    static ADDRBK_ENG_RESULT_T getVTFlag(bool& flag, const QString& number);

    static ADDRBK_ENG_RESULT_T setVTFlag(bool flag, const QString& number);

    static ADDRBK_ENG_RESULT_T unmarkAllPTTFlag();

    static ADDRBK_ENG_RESULT_T setMyFave(ADDRBK_UID_T uid, bool set = true);

    static ADDRBK_ENG_RESULT_T
    createMyFaveContact(ADDRBK_UID_T& uid, const QString& name,
                        const QString& number,
                        const QString& iconPath = QString::null);

    static ADDRBK_ENG_RESULT_T isMyFaveNumber(bool& flag, const QString& number);

    static ADDRBK_ENG_RESULT_T isInMyFaveContact(bool& flag,
                                                 const QString& number);

    static ADDRBK_ENG_RESULT_T addBlock(ADDRBK_UID_T uid, const QString& content);

    static ADDRBK_ENG_RESULT_T isBlocked(bool & blocked, const QString & content, bool inPb = false);

    static ADDRBK_ENG_RESULT_T isBlocked(bool & blocked, ADDRBK_UID_T uid);

    static ADDRBK_ENG_RESULT_T removeBlock(const QString & content);

    static ADDRBK_ENG_RESULT_T removeBlock(ADDRBK_UID_T uid);

    static ADDRBK_ENG_RESULT_T removeBlock(const ADDRBK_ENG_Blocker& blocker);

    static ADDRBK_ENG_RESULT_T getBlockerList(QList<ADDRBK_ENG_Blocker>& qBlockList);

#ifdef _FEAT_LJP2P_VT
    static ADDRBK_ENG_RESULT_T isBlocked(bool& result, const QString&);
#endif

    static ADDRBK_ENG_RESULT_T getNumbers(QList<ADDRBK_RECIPIENT_S>& numberlist, 
                                          int maxlimit = 0);

private:

    static ADDRBK_ENG_RESULT_T deleteNumberInBlockList(
                                        ADDRBK_ENG_STORAGE_T storage,
                                        ADDRBK_UICC_TYPE_T type);

    static ADDRBK_ENG_RESULT_T
    myFaveUpdateHandler(ADDRBK_UID_T& uid,
                        const QString& name,
                        const QString& number,
                        const QString& iconPath);

    static ADDRBK_ENG_RESULT_T
    createNewMyFave(ADDRBK_UID_T& uid,
                    const QString& name,
                    const QString& number,
                    const QString& iconPath);

    static ADDRBK_ENG_RESULT_T
    myFaveNameMatchedHandler(ADDRBK_UID_T& uid,
                             const QValueList<ADDRBK_UID_T>& uidList,
                             const QString& name,
                             const QString& number,
                             const QString& iconPath);

    static ADDRBK_ENG_RESULT_T
    myFaveNameNotMatchedHandler(ADDRBK_UID_T& uid,
                                const QString& name,
                                const QString& number,
                                const QString& iconPath);

    static ADDRBK_ENG_RESULT_T
    getContactWithFreeNumberRoom(ADDRBK_UID_T& dstUID,
                                 const QValueList<ADDRBK_UID_T>& uidList);

    static void updateMyFaveNickName(ADDRBK_ENG_PhoneContact& phoneContact);

    static void getSubUIDSet(QValueList<ADDRBK_UID_T>& uidSet,
                             const QValueList<ADDRBK_UID_T>& uidList1,
                             const QValueList<ADDRBK_UID_T>& uidList2);

    static ADDRBK_ENG_RESULT_T
    getSimpleUSimContact(ADDRBK_ENG_Contact* pRecord, UINT32 selFlag);

    static ADDRBK_ENG_RESULT_T 
    getSimplePhoneContact(ADDRBK_ENG_Contact* pRecord,  UINT32 selFlag);

    static ADDRBK_ENG_RESULT_T
    handleMyFaveNameMatch(ADDRBK_UID_T& uid,
                          const QValueList<ADDRBK_UID_T>& uidList,
                          const QString& name,
                          const QString& number,
                          const QString& iconPath);

    static ADDRBK_ENG_RESULT_T
    handleMyFaveNameMatchByUID(ADDRBK_UID_T& uid,
                               ADDRBK_UID_T uid_t,
                               const QString& number,
                               const QString& iconPath);

    static ADDRBK_ENG_RESULT_T
    preDeleteAllRecords(QValueList<ADDRBK_UID_T>& simUIDs,
                        ADDRBK_RECORD_TYPE_T& rectype,
                        ADDRBK_UICC_TYPE_T& type,
                        ADDRBK_ENG_STORAGE_T storage,
                        int profileID);

    static void 
    searchBy_isNameMatch(ADDRBK_SEARCH_RESULT_S& result,
                         ADDRBK_ENG_RESULT_T& ret,
                         const QString& searchName,
                         QList<ADDRBK_SEARCH_RESULT_S>& results);

};

#endif  
