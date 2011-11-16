

// Copyright (c) 30-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef CAL_ENG_MANAGER_H
#define CAL_ENG_MANAGER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qdatetime.h>
#include <qvaluelist.h>
#include <qstring.h>
#include <qobject.h>
#include <qcopchannel_qws.h>

#include <EZX_TypeDefs.h>

#include "WORLDCLOCK_TypeDefs.h"
#include "WORLDCLOCK_ITimeClient.h"
#include  "ZCalendarEvent.h"
#include "ZCalendarTypeDefs.h"
#include "CAL_ENG_Global.h"

#include <SETUP_UTIL_Define.h>

typedef enum
{
    CAL_REMOVAL_TYPE_NEVER_REMOVE = 0,    
    CAL_REMOVAL_TYPE_DAY = 0x01,          
    CAL_REMOVAL_TYPE_WEEK = 0x02,         
    CAL_REMOVAL_TYPE_MONTH = 0x03,        
    CAL_REMOVAL_TYPE_YEAR = 0x04          
} CAL_REMOVAL_TYPE_T;

struct CAL_PROFILE_PARAM_STRUCT_T
{
    CAL_PROFILE_PARAM_STRUCT_T()
    {
        profileID = -1;
    }

    int profileID;                             
};

class CAL_ENG_DB;
class CAL_ENG_ReportChange;
class CAL_ENG_ServiceThread;
class CAL_ENG_ResetAllAlarmThead;

class CAL_ENG_Manager : public QObject
{
    Q_OBJECT

public:

    CAL_ENG_Manager();

    ~CAL_ENG_Manager();

    CAL_ENG_RESULT_T addEvent(ZCalendarEvent &e, bool checkFlag = true);

    CAL_ENG_RESULT_T updateEvent(ZCalendarEvent &e, bool checkFlag = true);

    CAL_ENG_RESULT_T removeEvent(const UINT32 uid);

    CAL_ENG_RESULT_T removeAll();

    CAL_ENG_RESULT_T getEvent(const UINT32 uid, ZCalendarEvent &e);

    CAL_ENG_RESULT_T getEvent(const QString &uuid, ZCalendarEvent &e);

    CAL_ENG_RESULT_T getEvents(const ZCalendarTime_T &start, const ZCalendarTime_T &end, QValueList<CAL_SEARCH_RESULT_T> &events);

    CAL_ENG_RESULT_T getEvents(QDateTime &start, QDateTime &end, QValueList<CAL_SEARCH_RESULT_T> &events);

    CAL_ENG_RESULT_T getEvents(const ZCalendarTime_T &start, const ZCalendarTime_T &end, QValueList<CAL_LITE_EVENT_T> &events);

    CAL_ENG_RESULT_T getEvents(QDateTime &start, QDateTime &end, QValueList<CAL_LITE_EVENT_T> &events);

    CAL_ENG_RESULT_T copyEvent(const ZCalendarEvent &e, ZCalendarTime_T *startDate, ZCalendarEvent &newEvent);

    CAL_ENG_RESULT_T addEventEditExcept(ZCalendarEvent & e, bool checkFlag = TRUE);

    CAL_ENG_RESULT_T updateEventEditExcept(ZCalendarEvent & e, bool checkFlag = TRUE);

    CAL_ENG_RESULT_T deleteEventEditExcept(const UINT32 exceptID, \
                                           bool createDeleteExcept = false);

    CAL_ENG_RESULT_T deleteEventEditExcepts(const UINT32 uid);

    CAL_ENG_RESULT_T getEventEditExcepts(const UINT32 uid, QValueList<ZCalendarEvent> &excepts);

    CAL_ENG_RESULT_T getEventEditExcept(const UINT32 exceptID, ZCalendarEvent &except);

    CAL_ENG_RESULT_T getEventEditExcept(const UINT32 uid, ZCalendarTime_T &occurDate, ZCalendarEvent &except);

    CAL_ENG_RESULT_T eventToVCal(ZCalendarEvent &event, QByteArray &vcal, CAL_VCAL_FORMAT_T fmt = CAL_VCAL_FORMAT_STANDARD);

    CAL_ENG_RESULT_T vCalToEvent(QByteArray &vcal, ZCalendarEvent  &event);

    CAL_ENG_RESULT_T eventToICal(ZCalendarEvent &event, QByteArray &ical);

    CAL_ENG_RESULT_T iCalToEvent(QByteArray &ical, ZCalendarEvent  &event);

    CAL_ENG_RESULT_T getAllIDs(QValueList<UINT32> &uids);

    CAL_ENG_RESULT_T addEventDeleteExceptByDate(UINT32 uid, ZCalendarTime_T occurDate);

    static CAL_ENG_RESULT_T setSetupInfo(CAL_SETUP_T setupItem, int value);

    static CAL_ENG_RESULT_T getSetupInfo(CAL_SETUP_T setupItem, int &value);

    static int getSyncProfileId(void);

#ifdef MAKE_UISTYLE_CHAMELEON
    CAL_ENG_RESULT_T getMissedAlarms(QValueList<CAL_LITE_EVENT_T> &events);
#endif

    CAL_ENG_RESULT_T  addCategory(QString &cat);

    CAL_ENG_RESULT_T  getCategoryName(UINT32 id, QString &cat);

    CAL_ENG_RESULT_T  removeCategory(QString &cat, bool removeFlag);

    CAL_ENG_RESULT_T  renameCategory(QString &oldName, QString &newName);

    CAL_ENG_RESULT_T  getAllCategories(QValueList<QString> &catList);

    CAL_ENG_RESULT_T  getAllCategories(QValueList<CAL_ENG_CATEGORY_T> &catList);

    int  getCategoryID(QString &catName);

    CAL_ENG_RESULT_T getCategoryByName(QString &catName, CAL_ENG_CATEGORY_T &cat);


    void beginSync(int syncProfileId = -1);

    void endSync();

    ZCalendarResult_T getAllEvents(QValueList<ZCalendarEvent> &events);

    ZCalendarResult_T getEventsByCategory(UINT32 catID, QValueList<ZCalendarEvent> &events);

    ZCalendarResult_T searchEvents(ZCalendarSearchType_T searchType,
                            ZCalendarTime_T &startDT,
                            ZCalendarTime_T &endDT,
                            bool  initialEventOnly,
                            QValueList<ZCalendarEvent> &events);

    ZCalendarResult_T getNextAlarmedEvents(ZCalendarTime_T &time, QValueList<ZCalendarEvent> &events);

#ifdef MAKE_UISTYLE_CHAMELEON
    ZCalendarResult_T getTopPriorityProfile(ZCalendarTime_T &time, int & profileID);

    ZCalendarResult_T searchSimpleEvents(ZCalendarTime_T &time, int& profileID, ENUM_ALERT_STYLE& topAlertsAlertStyle, ENUM_ALERT_STYLE &topIncomingCallAlertStyle);
    ZCalendarResult_T searchRepeatEvents(ZCalendarTime_T &time, int& profileID, ENUM_ALERT_STYLE& topAlertsAlertStyle, ENUM_ALERT_STYLE &topIncomingCallAlertStyle);

#endif

    ZCalendarResult_T autoDeleteEvents();

    ZCalendarResult_T resetAllAlarms();

    ZCalendarResult_T updateNewTimeZone(const std::vector<CityInfo>& vCityInfo);

    ZCalendarResult_T updateEditExcepTimeZone(const std::vector<CityInfo>& vCityInfo,QValueList<ZCalendarEvent> &editExceptions);

    ZCalendarResult_T addNewAlarm(const ZCalendarEvent & e, bool isReset = false);

    bool isExistingEvent(const UINT32 uid, const UINT32 exceptID);

    ZCalendarResult_T getEvent(const UINT32 uid, const UINT32 exceptID,
                      ZCalendarTime_T * occurDate, ZCalendarEvent &e);

    ZCalendarResult_T saveEvent(ZCalendarEvent &e);

    void enableNotifyDataChange(bool flag);

    ZCalendarTimeZone_T * getLocalTimeZone();

    void toLiteEvent(ZCalendarEvent &event, CAL_LITE_EVENT_T &liteEvent);

    bool toLocalTime(ZCalendarTime_T uTime, QDateTime &qTime, bool isUTC = false);

    bool fromLocalTime(QDateTime &qTime, ZCalendarTime_T &uTime, bool isUTC = false);

    bool getRemoveAfterDateTime( QDateTime &removalDateTime );

    ZCalendarResult_T getEventsByAlarmType(CAL_ALARM_TYPE_T alarmType, QDateTime &time, QValueList<CAL_LITE_EVENT_T> &events);

    int onProfileChanged(CAL_PROFILE_PARAM_STRUCT_T param);

#ifdef MAKE_UISTYLE_CHAMELEON
    CAL_ENG_RESULT_T addHSAAlarm(QDateTime &dt);

    CAL_ENG_RESULT_T removeHSAAlarm();

    void resetProfile(ZCalendarTime_T alarmTime = 0);
#endif


protected:

private:

    void toSearchResult(ZCalendarEvent &event, CAL_SEARCH_RESULT_T &searchResult);

    void registerNewAlarm(ZCalendarEvent &event, QDateTime alarmTime,
                          CAL_ALARM_TYPE_T alarmType, bool registerNext = false);

    void dbDataChanged(bool resetAll = true);

    QCopChannel * mpTimeZoneChannel;

    CAL_ENG_DB *mpDB;
    bool mDBChanged;

    ZCalendarTimeZone_T * mpLocalTimeZone;

    bool mNotifyDataChange;

    bool mIsSyncing;

    static int mSyncProfileId;

    CAL_ENG_ReportChange * mpReportChange;

    CAL_ENG_ServiceThread* m_resetAllAlarmsThread;

    friend class CAL_ENG_ResetAllAlarmThead;

signals:
    void eventAdded(int uid);
    void eventUpdated(int uid);
    void eventRemoved(int uid);
    void eventsAllRemoved();

private slots:
    void slotReceived(const QCString &, const QByteArray &);
};

#endif  

