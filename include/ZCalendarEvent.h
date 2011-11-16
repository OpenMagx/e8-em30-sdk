

// Copyright (c) 30-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef __ZCALENDAREVENT_H__ 
#define __ZCALENDAREVENT_H__

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qvaluelist.h>
#include <qstring.h>

#include "EZX_TypeDefs.h"

#include  "ZCalendarRepeat.h"
#include "ZCalendarTypeDefs.h"

class ZCalendarEvent
{
public:
    ZCalendarEvent();

    ZCalendarEvent(const ZCalendarEvent &e);

    ~ZCalendarEvent();

    enum CalendarEventField_T
    {
        LOCATION = (UINT32)0,    
        NOTE,                    
        SUMMARY,                 
        UUID,                    
        CATEGORY,                
        START_DATE,              
        REVISION,                
        TIMESTAMP,               
        END_DATE,                
        OCCUR_DATE,              
        IS_ALL_DAY,              
        ALARM,                   
        CLASS,                   
        PROFILE,                 
        BUSY_STATUS,             
        MEETING_STATUS,          
        COMMENTS,                
        PART_STATE,              
        BODY_TRUNCATED,          
        RECORD_TRUNCATED,        
        HAS_SENT,                
        IMAGE_PATH,              
        MEDIA_PATH               
    } ;

     enum BusyStatus_T
     {
        FREE = 0,          
        BUSY_TENTATIVE,    
        BUSY,              
        OUT_OF_OFFICE      
     };

     enum MeetingStatus_T 
     {
        NOT_MEETING = 0,      
        IS_ORGANIZER,         
        IS_MEETING_REPSONSE,  
        IS_ATTENDEE,          
        UNKNOWN_STATUS,       
        IS_CANCELLED          
     };

     enum Class_T
     {
        CLASS_UNKNOWN = -1, 
        PUBLIC = 0,         
        PRIVATE,            
        CONFIDENTIAL,       
        NORMAL,             
        PERSONAL            
     };

     enum Role_T 
     { 
        CHAIR =1,                 
        REQUIRED_PARTICIPANT,     
        OPTIONAL_PARTICIPANT      
     };

     enum PartState_T 
     { 
        UNKNOWN = -2,       
        DECLINED,           
        TENTATIVE,          
        ACCEPTED,           
        CANCELLATION        
     };

     struct Attendee_T
     {
        Attendee_T()  { name = ""; emailAddress = ""; role =REQUIRED_PARTICIPANT; part = UNKNOWN;}

        Attendee_T(QString n, QString email, Role_T r, PartState_T p) { name = n; emailAddress = email; role = r; part = p;}

        bool operator ==(const Attendee_T &right ) const 
        {
            return (right.emailAddress.lower() == emailAddress.lower());
        }

        Attendee_T(const Attendee_T &right)  
        {
            *this = right;
        }

        Attendee_T & operator=(const Attendee_T & right) 
        {
            name = right.name;
            emailAddress = right.emailAddress;
            role = right.role;
            part = right.part;
            return (*this);
        }

        QString name;            
        QString emailAddress;    
        Role_T role;             
        PartState_T part;        
     };

     void setRepeat(ZCalendarRepeat *value);

     ZCalendarRepeat * getRepeat() const;

    bool isRepeat() const;

    void setUID( const UINT32 id );

    const UINT32 getUID() const;

    void setExceptID( const UINT32 id );

    const UINT32 getExceptID() const;

    bool hasExceptID() const;

    bool hasOccurDate() const;

    ZCalendarResult_T setDate(CalendarEventField_T field, ZCalendarTime_T value);

    ZCalendarResult_T getDate(CalendarEventField_T field, ZCalendarTime_T &value) const;

    ZCalendarResult_T setString(CalendarEventField_T field, const QString& value);

    ZCalendarResult_T getString(CalendarEventField_T field, QString &value) const;

    ZCalendarResult_T setBoolean(CalendarEventField_T field, bool value);

    ZCalendarResult_T getBoolean(CalendarEventField_T field, bool &value) const;

    ZCalendarResult_T setInt(CalendarEventField_T field, int value);

    ZCalendarResult_T getInt(CalendarEventField_T field, int &value) const;

    ZCalendarResult_T commit();

    ZCalendarResult_T getAttendees(QValueList<Attendee_T> &attendees) const;

    ZCalendarResult_T setAttendees(QValueList<Attendee_T> &attendees);

    QString getAttendees() const;

    ZCalendarResult_T setAttendees(const QString &value);

    ZCalendarResult_T addAttendee(Attendee_T &attendee);

    ZCalendarResult_T setCategories(QValueList<QString> &categories);

    ZCalendarResult_T setCategories(QString &value, QString delimiter= ";");

    ZCalendarResult_T removeFromCategory(QString &cat);

    QString getCategoryName() const;

    ZCalendarResult_T setOrganizer(Attendee_T &value);

    bool getOrganizer(Attendee_T &value) const;

    bool setOrganizer(QString &value);

    QString getOrganizer() const;

    bool isOrganizer() const;

    bool isMeetingRequest() const;

    UINT32 getDurationMinutes() const;

    ZCalendarResult_T setTimeZone(const ZCalendarTimeZone_T &tz);

    ZCalendarResult_T getTimeZone(ZCalendarTimeZone_T &tz) const;

    ZCalendarResult_T setTimeZone(QString &strTimeZone);

    QString getTimeZone() const;

    bool hasTimeZone() const; 


    ZCalendarEvent & operator=(const ZCalendarEvent &e);

    bool operator < (const ZCalendarEvent &right ) 
    {
        return ((start < right.start) || (start == right.start && 
                 end < right.end));
    }

    bool operator > (const ZCalendarEvent &right ) 
    {
        return ((start > right.start) || (start == right.start && 
                 end > right.end));
    }

    bool operator >= (const ZCalendarEvent &right ) 
    {
        return !(*this < right);
    }

    bool operator <= (const ZCalendarEvent &right ) 
    {
        return !(*this > right);
    }

    bool hasAlarm() const
    {
        return (alarm >= 0);
    }

    bool isPrivate() const
    {
        return (classification == PRIVATE || classification == CONFIDENTIAL);
    }

protected:

private:

    bool checkTimeZone(const ZCalendarTimeZone_T &tz) const;

    QString location;       

    QString note;                

    QString summary;        

    int categoryID;

    QString uuid;                       

    ZCalendarTime_T start;                

    ZCalendarTime_T end;                 

    ZCalendarTime_T revision;        

    ZCalendarTime_T timeStamp;        

    INT32 alarm;                   

    INT8 classification;        

    bool isAllDay;

    INT32 profile;              

    INT8 busyStatus;         

    INT8 meetingStatus;  

    ZCalendarTime_T occurDate; 

    ZCalendarRepeat *repeat;  

    UINT32 uid;                          

    UINT32 exceptID;            

    QValueList<Attendee_T> attendees; 

    Attendee_T organizer;

    QString comments;

    int partState;

    bool bodyTruncated;

    bool recordTruncated;

    bool hasSent;

    ZCalendarTimeZone_T timeZone; 

    QString imagePath;

    QString mediaPath;
};

#endif  
