

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef RC_MSGCLIENT_H
#define RC_MSGCLIENT_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qobject.h>
#include <RC_RecordInterface.h>

typedef enum{
	RC_PAGE_ID_LIST_ALL_CALL,
	RC_PAGE_ID_LIST_MISSED_CALL, 
	RC_PAGE_ID_LIST_ANSWERED_CALL, 
	RC_PAGE_ID_LIST_DIALED_CALL, 
	RC_PAGE_ID_LIST_FREQUENT_CALL, 
	RC_PAGE_ID_LIST_PICKER, 
}RC_PAGE_ID_T;

#define RECENTCALL_RCOMREPORTER_CHANNEL "RecentCall_RcomRepoter_Channel"

#define RECENTCALL_MISSED_CALL_REPORTER "RecentCall_Missed_Call_Reporter"

class RC_MsgInterfaceData;

class RC_MsgInterface: public QObject
{
    Q_OBJECT
public:

	static  RC_MsgInterface *instance();
	static void destruction();
    bool requestShowUI(RC_PAGE_ID_T pageID=RC_PAGE_ID_LIST_ALL_CALL);
    bool showRecordDetail(int id,RC_CALL_CATEGORY_T cat);
    static void hideUI();
signals:
    void rcFinished(bool selected,const QString& number);

private:
    RC_MsgInterface();
    RC_MsgInterface(const RC_MsgInterface&);
    RC_MsgInterface& operator=(const RC_MsgInterface&);
    ~RC_MsgInterface();
private slots:  
    void slotExitPicker(bool,const QString&);
private:
    RC_MsgInterfaceData *d;

};

#endif 
