

// Copyright (c) 30-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef CAL_ENG_ICALENDAR_H
#define CAL_ENG_ICALENDAR_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>
#include <qfile.h>

#include "ZCalendarEvent.h"
#include "CAL_ENG_Global.h"

typedef struct icalcomponent_impl icalcomponent;

typedef struct icalproperty_impl icalproperty;

typedef enum
{
    ICALENDAR_METHOD_UNKNOWN = 0,
    ICALENDAR_METHOD_REQUEST,
    ICALENDAR_METHOD_REPLY,
    ICALENDAR_METHOD_CANCEL,
    ICALENDAR_METHOD_PUBLISH
} CAL_ICALENDAR_METHOD_ENUM_T;

typedef enum
{
    ICALENDAR_RESPONSE_DECLINE = -1,
    ICALENDAR_RESPONSE_TENTATIVE = 0,
    ICALENDAR_RESPONSE_ACCEPT,
    ICALENDAR_RESPONSE_CANCEL
} CAL_ICALENDAR_RESPONSE_ENUM_T;

typedef enum                     
{
    ICALENDAR_RES_SUCCEED = 0,         
    ICALENDAR_RES_FAILED_OPEN_FILE,    
    ICALENDAR_RES_NULL_POINTER,        
    ICALENDAR_RES_INVALID,             
    ICALENDAR_RES_USER_NOT_FOUND,      
    ICALENDAR_RES_MEETING_TOO_OLD,     
    ICALENDAR_RES_PARENT_NOT_FOUND,    
    ICALENDAR_RES_MEMORY_FULL,         
    ICALENDAR_RES_DBERROR_OTHER,       
    ICALENDAR_RES_ERROR_OTHER          
} CAL_ICALENDAR_RESULT_ENUM_T;

class CAL_ENG_ICalendar
{
public:
    CAL_ENG_ICalendar();   

    ~CAL_ENG_ICalendar();

    CAL_ICALENDAR_RESULT_ENUM_T readICalendar(const QString & fileName,         \
                                                     const QString & userEmail, \
                                                     ZCalendarEvent &event,     \
                                                     CAL_ICALENDAR_METHOD_ENUM_T & method, \
                                                     bool noValidation=FALSE,
                                                     const bool callFromSyncML = false);

    CAL_ICALENDAR_RESULT_ENUM_T writeMeetingRequest(ZCalendarEvent & e,  \
                         const QString & fileName,                       \
                         CAL_ICALENDAR_METHOD_ENUM_T method = ICALENDAR_METHOD_REQUEST);

    CAL_ICALENDAR_RESULT_ENUM_T writeMeetingResponse(ZCalendarEvent & e,             \
                                                     const QString & responseFile,   \
                                                     CAL_ICALENDAR_RESPONSE_ENUM_T responseType, \
                                                     const QString receiverEmail = QString::null);

    CAL_ICALENDAR_RESULT_ENUM_T toMeetingResponse(ZCalendarEvent & e,             \
                                                  CAL_ICALENDAR_RESPONSE_ENUM_T responseType, \
                                                  const QString receiverEmail = QString::null, \
                                                  QString summary = QString::null, \
                                                  QString comments = QString::null);

    CAL_ICALENDAR_RESULT_ENUM_T processMeetingRequst(ZCalendarEvent &event,  \
                                 CAL_ICALENDAR_RESPONSE_ENUM_T responseType);

    CAL_ICALENDAR_RESULT_ENUM_T checkMeetingRequestOutdated( ZCalendarEvent &event );   

    CAL_ICALENDAR_RESULT_ENUM_T removeMeetingRequest(ZCalendarEvent &event); 

    CAL_ICALENDAR_RESULT_ENUM_T getMeetingRequestString(ZCalendarEvent& event, QString& mrString, \
                                     CAL_ICALENDAR_METHOD_ENUM_T method);

    bool getWhenString( ZCalendarEvent& event, QString& whenString );

    bool getWhenString( ZCalendarEvent& event, QString& strStartTime, QString& strEndTime, \
                        QString& strTimeZone, QString& strRepeatPattern, QString& strUntil);

    static bool getRepeatPatternString(ZCalendarEvent & event, QString& strRepeatPattern);

    bool writeICalendar(const QString &filename, ZCalendarEvent &event);

    bool readICalendar(const QString &filename, ZCalendarEvent &event, const bool callFromSyncML = false);

    bool fromICalendar(QByteArray &ical, ZCalendarEvent &event, const bool callFromSyncML = false);

    bool toICalendar(ZCalendarEvent &event, QByteArray &iCal);

    static void convertAllDayToSimpleEvent (ZCalendarEvent &event);

    CAL_VCAL_VERSION_T getVCalVersion(const QString &filename);

    CAL_VCAL_VERSION_T getVCalVersion(const QByteArray &vcal);

    int convertToEmailMethodType(CAL_ICALENDAR_METHOD_ENUM_T type);

    int convertToEmailResponseType(CAL_ICALENDAR_RESPONSE_ENUM_T type);

private:
    CAL_ICALENDAR_RESULT_ENUM_T icalendar2Event(ZCalendarEvent & e, 
                                              icalcomponent * comp, 
                                              const QString & userEmail=QString::null,
                                              bool noValidation=FALSE,
                                              const bool callFromSyncML = false);

    CAL_ICALENDAR_RESULT_ENUM_T event2icalendar(ZCalendarEvent & e, 
                      icalcomponent * eventComp,
                      CAL_ICALENDAR_METHOD_ENUM_T method = ICALENDAR_METHOD_REQUEST,
                      CAL_ICALENDAR_RESPONSE_ENUM_T responseType = ICALENDAR_RESPONSE_ACCEPT,
                      const QString userEmail = QString::null);

    CAL_ICALENDAR_RESULT_ENUM_T saveMeetingRequest(ZCalendarEvent &event);

    CAL_ICALENDAR_RESULT_ENUM_T writeICalendar(ZCalendarEvent &event, 
                      const QString & fileName,
                      CAL_ICALENDAR_METHOD_ENUM_T method, 
                      CAL_ICALENDAR_RESPONSE_ENUM_T responseType = ICALENDAR_RESPONSE_ACCEPT,
                      const QString userEmail = QString::null);

    int getDayInWeek(short *byDay);

    CAL_ICALENDAR_RESULT_ENUM_T writeProperty(icalproperty *p, QFile *f);

    CAL_ICALENDAR_RESULT_ENUM_T writeVTimeZone(QFile *f, ZCalendarEvent &event);

};

#endif 

