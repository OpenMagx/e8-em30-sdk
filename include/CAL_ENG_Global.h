

// Copyright (c) 30-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef CAL_ENG_GLOBAL_H
#define CAL_ENG_GLOBAL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>
#include <qdatetime.h>
#include <EZX_TypeDefs.h>

#include "ZCalendarTypeDefs.h"

#define	CAL_EVENT_TITLE_MAX_LEN	     512    
#define	CAL_EVENT_LOCATION_MAX_LEN   512    
#define	CAL_EVENT_NOTE_MAX_LEN		1024    
#define	CAL_YEAR_MAX                2037    
#define	CAL_YEAR_MIN		        1902    
#define CAL_ALARM_TIME_MAX  20160   
#define	EZX_CAL_YEAR_MAX		           2037 
#define	EZX_CAL_YEAR_MIN		           1970 
#define CAL_MISSED_EVENT_NUM_MAX		   20   
#define CAL_CATEGORY_NUM_MAX		       50   
#define CAL_ENG_CHANNEL_NAME               "EZX_PIM_CAL_ENG_CHANNEL"
#define CAL_HSA_CHANNEL_NAME               "EZX_PIM_CAL_HSA_CHANNEL"
#define CAL_ENG_DATA_CHANGED               "CAL_ENG_dataChanged"    
#define CAL_CONFIG_FILENAME                "ezx_calendar.cfg"       
#define CAL_CONFIG_GROUP_NAME              "CALENDAR_SETUP_GROUP"   
#define CAL_CONFIG_KEY_STARTTIME           "startTime"              
#define CAL_CONFIG_KEY_ENDTIME             "endTime"                
#define CAL_CONFIG_KEY_REMOVEEVENTAFTER    "removeEventAfter"       
#define CAL_CONFIG_KEY_LUNARCALENDAR       "lunarCalendar"  
#define CAL_CONFIG_KEY_OPENVIEW            "openView"       
#define CAL_CONFIG_KEY_SNOOZE              "snooze"         
#define CAL_CONFIG_KEY_WEEKSTART           "weekStart"      
#define CAL_CONFIG_KEY_ALARMTIMEOUT        "alarmTimeOut"   
#define CAL_CONFIG_KEY_REMINDPOWEROFF      "remindPowerOff" 

#define CAL_CONFIG_KEY_SENSITIVITY         "defaultClass"   

#define CAL_ALARM_GROUP_NAME               "CAL_ALARM_GROUP"
#define CAL_UNS_GROUP_NAME                 "CAL_UNS_GROUP"  
#define CAL_ENTRY_FILE_NAME                "/Calendar.config"   
#define CAL_CONFIG_KEY_DEFAULT_DAY_VIEW            "defaultDayView"
#define CAL_CONFIG_KEY_DAYS_OF_WEEK                "daysOfWeek"
#define CAL_CONFIG_KEY_TIME_INCREMENT              "timeIncrement"
#define CAL_CONFIG_KEY_STOP_REMIND_AFTER           "afterReminderAfter"
#define CAL_CONFIG_KEY_SHOW_WEEK_NUM               "showWeekNumber"
#define CAL_CONFIG_KEY_LAST_REMINDER_TIME          "lastReminderTime"   
#define CAL_CONFIG_KEY_LAST_REGISTERED_ALARM_TIME  "lastRegisteredAlarmTime"    
#define CAL_CONFIG_KEY_MISSED_EVENTS_COUNT         "missedEventsCount"  
#define CAL_CONFIG_KEY_MISSED_EVENTS_BEGIN_TIME    "missedEventsBeginTime"  
#define CAL_CONFIG_KEY_MISSED_EVENTS_END_TIME      "missedEventsEndTime"    
#define CAL_CONFIG_KEY_APP_CHANNEL_NAME            "calendarChannelName"    
#define CAL_CONFIG_STARTTIME_DEFAULT 8
#define CAL_CONFIG_ENDTIME_DEFAULT      17            

#ifdef MAKE_UISTYLE_CHAMELEON
#define CAL_CONFIG_REMOVEEVENTAFTER_DEFAULT     0x02000002      
#define CAL_CONFIG_REMINDPOWEROFF_DEFAULT       0       
#endif

#define CAL_CONFIG_LUNARCALENDAR_DEFAULT        0              
#define CAL_CONFIG_SNOOZE_DEFAULT       5              
#define CAL_CONFIG_OPENVIEW_DEFAULT     0                    
#define CAL_CONFIG_WEEKSTART_DEFAULT    7       
#define CAL_CONFIG_ALARMTIMEOUT_DEFAULT  0      


#define CAL_CONFIG_DEFAULT_DAY_VIEW_DEFAULT   0       
#define CAL_CONFIG_DAYS_OF_WEEK_DEFAULT       7  

#define CAL_CONFIG_TIME_INCREMENT_DEFAULT     1     
#define CAL_CONFIG_STOP_REMIND_AFTER_DEFAULT  0     
#define CAL_CONFIG_SHOW_WEEK_NUM_DEFAULT      1     

#define CAL_CONFIG_ALARM_SETTING_UNIT               3600    
#define CAL_CONFIG_ALARM_ALARM_UNIT                 60      
#define CAL_CONFIG_ALARM_SNOOZE_TIME                5*60    

#define CAL_CONFIG_SENSITIVITY_DEFAULT        1

#define CAL_HALF_DAY_SECONDS                 15 * 3600      

#define CAL_ACCELERATE_POPUP_DIALOG 2

#define USER_DISMISS  100

#ifndef IID_CALENDAR_ALARM
#define IID_CALENDAR_ALARM QUuid("{1faef3af-c2c4-4377-82d2-8390f8d168aa}")      
#endif

typedef enum
{
    CAL_NOTE_TYPE_NO_NOTE,             
    CAL_NOTE_TYPE_NOTE_NOT_TRUNCATED,  
    CAL_NOTE_TYPE_NOTE_TRUNCATED       
}CAL_NOTE_TYPE_T;

struct CAL_LITE_EVENT_T
{
    bool operator <(CAL_LITE_EVENT_T &right ) 
    {
        if (qStart < right.qStart)
        {
            return true;
        }
        else if (qStart > right.qStart)
        {
            return false;
        }

        if( qEnd < right.qEnd)
        {
            return true;
        }
        else if (qEnd > right.qEnd)
        {
            return false;
        }

        if(revision < right.revision)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator >(CAL_LITE_EVENT_T &right ) 
    {
        if (qStart > right.qStart)
        {
            return true;
        }
        else if (qStart < right.qStart)
        {
            return false;
        }

        if( qEnd > right.qEnd)
        {
            return true;
        }
        else if (qEnd < right.qEnd)
        {
            return false;
        }

        if(revision > right.revision)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator >=(CAL_LITE_EVENT_T &right ) 
    {
        return !(*this < right);
    }

    bool operator <=(CAL_LITE_EVENT_T &right ) 
    {
        return !(*this > right);
    }   

    CAL_LITE_EVENT_T()
    {
        startDT= ZCALENDAR_INVALID_DATE;
        endDT= ZCALENDAR_INVALID_DATE;
        revision = ZCALENDAR_INVALID_DATE;
        timeStamp = ZCALENDAR_INVALID_DATE;
        category=0;
        isAllDay=false;
        repeat=false;
        repeatType = 0; 
        isOrganizer = false;
        isMeeting = false;
        isPrivate = false;
        profile=-1;
        alarm=-1;
        uid=ZCALENDAR_INVALID_UID;
        exceptID=ZCALENDAR_INVALID_UID;
        location="";
        title="";
        imagePath = "";
        mediaPath = "";
        noteType = CAL_NOTE_TYPE_NO_NOTE;
    }

    CAL_LITE_EVENT_T(const CAL_LITE_EVENT_T &right)
    {
          *this = right;
    }

    CAL_LITE_EVENT_T & operator=(const CAL_LITE_EVENT_T &right)
    {
        startDT=right.startDT;
        endDT=right.endDT;
        revision = right.revision;
        timeStamp = right.timeStamp;
        qStart = right.qStart;
        qEnd = right.qEnd;
        qRevision = right.qRevision;
        category=right.category;
        isAllDay=right.isAllDay;
        repeat=right.repeat;
        repeatType = right.repeatType;
        isOrganizer = right.isOrganizer;
        isMeeting = right.isMeeting;
        isPrivate = right.isPrivate;
        profile=right.profile;
        alarm=right.alarm;
        uid=right.uid;
        exceptID=right.exceptID;
        location=right.location;
        title=right.title;
        imagePath = right.imagePath;
        mediaPath = right.mediaPath;
        noteType = right.noteType;
        return (*this);
    }
    ZCalendarTime_T startDT;
    ZCalendarTime_T endDT;
    ZCalendarTime_T revision;     
    ZCalendarTime_T timeStamp;    
    QDateTime qStart;
    QDateTime qEnd;
    QDateTime qRevision;
    int category;
    bool isAllDay;                      
    bool repeat;                     
    int repeatType;                 
    bool isOrganizer;                
    bool isMeeting;   
    bool isPrivate;
    int profile;                       
    int alarm;                      
    UINT32 uid;                    
    UINT32 exceptID;  
    QString location;
    QString title;
    QString imagePath;
    QString mediaPath;
    CAL_NOTE_TYPE_T noteType;
};

struct CAL_SEARCH_RESULT_T
{
    CAL_SEARCH_RESULT_T() 
    {
        startDT=ZCALENDAR_INVALID_DATE;
        endDT=ZCALENDAR_INVALID_DATE;
        category=0;
        isAllDay=false;
    }

    CAL_SEARCH_RESULT_T(const CAL_SEARCH_RESULT_T &right)
    {
        *this = right;
    }

    CAL_SEARCH_RESULT_T & operator=(const CAL_SEARCH_RESULT_T &right)
    {
        startDT=right.startDT;
        endDT=right.endDT;
        qStart = right.qStart;
        qEnd = right.qEnd;
        category=right.category;
        isAllDay=right.isAllDay;
        return (*this);
    }

    bool operator <(CAL_SEARCH_RESULT_T &right ) 
    {
        return ((qStart<right.qStart) || (qStart==right.qStart && qEnd < right.qEnd));
    }

    bool operator >(CAL_SEARCH_RESULT_T &right ) 
    {
        return ((qStart>right.qStart) || (qStart==right.qStart && qEnd > right.qEnd));
    }

    bool operator >=(CAL_SEARCH_RESULT_T &right ) 
    {
        return !(*this < right);
    }

    bool operator <=(CAL_SEARCH_RESULT_T &right ) 
    {
        return !(*this > right);
    }

    ZCalendarTime_T startDT;  
    ZCalendarTime_T endDT;
    QDateTime qStart;
    QDateTime qEnd;
    int category;      
    bool isAllDay;
};

struct CAL_ENG_CATEGORY_T
{
    CAL_ENG_CATEGORY_T()
    {
        categoryID = 0;
        categoryName = "";
        isPredefined = false;
    }

    CAL_ENG_CATEGORY_T(const CAL_ENG_CATEGORY_T &right)
    {
        *this = right;
    }

    CAL_ENG_CATEGORY_T & operator=(const CAL_ENG_CATEGORY_T &right)
    {
        categoryID = right.categoryID;
        categoryName = right.categoryName;   
        isPredefined = right.isPredefined;
        return *this;     
    }

    bool operator==(CAL_ENG_CATEGORY_T &right)
    {
        return !(categoryName.upper().stripWhiteSpace().compare(right.categoryName.upper().stripWhiteSpace()));
    }
    int categoryID;         
    QString categoryName;   
    bool isPredefined;      
};

typedef enum
{
    CAL_SETUP_DEFAULT_VIEW = 0,            
    CAL_SETUP_DEFAULT_DAY_VIEW,            
    CAL_SETUP_DAYS_OF_WEEK,                
    CAL_SETUP_WEEK_START,                  
    CAL_SETUP_START_TIME,                  
    CAL_SETUP_END_TIME,                    
    CAL_SETUP_TIME_INCREMENT,              
    CAL_SETUP_REMOVE_AFTER,                
    CAL_SETUP_STOP_REMIND_AFTER,           
    CAL_SETUP_SHOW_WEEK_NUM,               
    CAL_SETUP_LUNAR_CALENDAR,              
    CAL_SETUP_SNOOZE_TIME,                 
    CAL_SETUP_REMINDER_POWER_OFF,          
    CAL_SETUP_LAST_REMINDER_TIME,          
    CAL_SETUP_LAST_REGISTERED_ALARM_TIME,  
    CAL_SETUP_MISSED_EVENTS_COUNT,         
    CAL_SETUP_MISSED_EVENTS_BEGIN_TIME,    
    CAL_SETUP_MISSED_EVENTS_END_TIME,      
    CAL_SETUP_APP_CHANNEL_NAME,            
    CAL_SETUP_DEFAULT_SENSITIVITY          
} CAL_SETUP_T;

typedef ZCalendarResult_T CAL_ENG_RESULT_T;

typedef enum
{
   CAL_DATE_CHANGE =0,          
   CAL_TIME_CHANGE,             
   CAL_DATE_FORMAT_CHANGE,      
   CAL_TIME_FORMAT_CHANGE,      
   CAL_TIMEZONE_CHANGE,         
   CAL_DST_CHANGE               
}CAL_DATE_TIME_CHANGE_T;

typedef enum
{
    CAL_QUICK_TEXT_SUMMARY = 0,   
    CAL_QUICK_TEXT_LOCATION       
}CAL_QUICK_TEXT_T;

typedef enum
{        
    CAL_ALARM_FIRST = 0,      
    CAL_ALARM_ALARM_SNOOZE,   
    CAL_ALARM_EVENT_START,    
    CAL_ALARM_EVENT_END,      
    CAL_ALARM_AUTO_DELETE,    
    CAL_ALARM_HSA_CHANGE      
}CAL_ALARM_TYPE_T;

typedef enum
{
    CAL_SIMPLE = 10,        
    CAL_RECURRENT = 20,     
    CAL_EXCEPTION = 30      
}CAL_EVENT_TYPE_T;

typedef enum
{
    CAL_VCAL_FORMAT_STANDARD = 0,  
    CAL_VCAL_FORMAT_OMA            
}CAL_VCAL_FORMAT_T;

typedef enum
{
    CAL_ISO8601_FORMAT_STANDARD = 0, 
    CAL_ISO8601_FORMAT_OMA_ALL_DAY   
}CAL_ISO8601_FORMAT_T;

enum CAL_UNS_SUBTYPE
{
    CAL_UNS_REMINDER_DLG = 0,  
    CAL_UNS_MISSEDEVENT_DLG    
};

enum CAL_CATEGORY
{
    CAL_CATEGORY_NONE = 0,      
    CAL_CATEGORY_MEETING,       
    CAL_CATEGORY_APPOINTMENT,   
    CAL_CATEGORY_PRESENTATION,  
    CAL_CATEGORY_CONFERENCECALL,
    CAL_CATEGORY_BREAKFAST,     
    CAL_CATEGORY_LUNCH,         
    CAL_CATEGORY_DINNER,        
    CAL_CATEGORY_ANNIVERSARY,   
    CAL_CATEGORY_BIRTHDAY,      
    CAL_CATEGORY_FLIGHT,        
    CAL_CATEGORY_PARTY,         
    CAL_CATEGORY_VACATION,      
};

typedef enum
{
    CAL_VCAL_VERSION_INVALID,   
    CAL_VCAL_VERSION_VCAL,      
    CAL_VCAL_VERSION_ICAL,      
} CAL_VCAL_VERSION_T;

#endif  

