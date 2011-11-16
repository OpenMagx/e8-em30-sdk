

// Copyright (c) 04-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ADDRBK_ENG_SEARCHLIST_H
#define ADDRBK_ENG_SEARCHLIST_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qobject.h>
#include <qlist.h>
#include <qthread.h>
#include "ADDRBK_ENG_Global.h"

#define ADDRBK_ENG_ENTRYMETHOD_CHANNEL  "addrbk-eng-entrymethod-channel"
#define ADDRBK_ENG_ENTRYMETHOD_MSG      "addrbk-eng-entrymethod-msg(int)"

class QCopChannel;
class QMutex;
class ADDRBK_ENG_Contact;
class ADDRBK_ENG_TAPI;
class iTAP_Wrapper;
struct ADDRBK_MSG_S;

class ADDRBK_ENG_SearchList : public QObject, public QThread
{
    Q_OBJECT

public:
    ADDRBK_ENG_SearchList(const QCString& NDD = "", int entryMethod = 0);

    ~ADDRBK_ENG_SearchList();

    bool isAvailable(void) { return mAvailable; }

    void searchByName(QList<ADDRBK_ENG_SearchListResult> &indexList,
        const QString &searchString);

    void searchByNumber(QList<ADDRBK_ENG_SearchListResult> &indexList,
        const QString &searchString);

    void searchByName(QList<ADDRBK_ENG_SearchListResult> &indexList,
        const QList<ADDRBK_ENG_SearchListResult> &fromIndexList,
        const QString &searchString) const;

    void searchByNumber(QList<ADDRBK_ENG_SearchListResult> &indexList,
         const QList<ADDRBK_ENG_SearchListResult> &fromIndexList,
         const QString &searchString) const;

signals:
    void refreshSearchListFinished();

protected:
    void timerEvent(QTimerEvent* e);
    virtual void run();
private:
    void connectChannels();
    void loadList();
    void generateKeys();
    void getContactName(QString& contactName, ADDRBK_ENG_Contact* contact);
    void insertContactToList(ADDRBK_RECORD_TYPE_T recordType, ADDRBK_UID_T uid);
    void removeContactFromList(ADDRBK_UID_T uid);

    void consumeMsg();
    void consumeEngineMsg(const QByteArray& data);

    bool isValidItapEntryMethod();
    static bool isKeyMatching(int& pos, const QString& searchString, const QString& key);
    static bool isItapFatalError(UINT32 itapRet);

    void receiveEngineMsg(const QByteArray& data);
    void receiveEntryMethodMsg(const QByteArray& data);
    void receiveSettingMsg(const QByteArray& data);
    void receiveFdnMsg(const QByteArray& data);

    void removeNddAndIdd(QString& str) const;

private slots:
    void slotReceiveMsg(const QCString& name, const QByteArray& data);

private:
    bool mAvailable;
    bool loadingListFailed;
    bool gettingFdnResult;
    bool onSearching;
    bool onConsumingMsg;

    bool mSyncFinish;

    QList<ADDRBK_ENG_SearchListResult> mSearchList;
    bool mSortFlag; 
    ADDRBK_ENG_STORAGE_T mStorage;
    int entryMethod;
    bool fixDialingSign;

    QCString NDD;

    QCopChannel* engChannel;
    QCopChannel* setChannel;
    QCopChannel* entryMethodChannel;
    QCopChannel* fixDialingChannel;

    QList<struct ADDRBK_MSG_S> msgList;
    int timerID;

    iTAP_Wrapper* itap;
    QMutex* mutex;
    ADDRBK_ENG_TAPI* tapi;
    ADDRBK_UICC_TYPE_T uiccType;
};

#endif  
