

// Copyright (c) 30-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef __ZCALENDARREPEAT_H__
#define __ZCALENDARREPEAT_H__

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qdatetime.h>
#include <qvaluelist.h>
#include <qstring.h>

#include "EZX_TypeDefs.h"

#include "ZCalendarTypeDefs.h"

class ZCalendarRepeat
{
public:
    ZCalendarRepeat();

    ZCalendarRepeat(const ZCalendarRepeat &rp);

    ~ZCalendarRepeat();

    enum CalendarRepeatField_T
    {
        REPEAT_TYPE = (UINT32)200,    
        INTERVAL,                     
        COUNT,                        
        DAY_IN_WEEK,                  
        DAY_IN_MONTH,                 
        WEEK_IN_MONTH,                
        MONTH_IN_YEAR,                
        END_TYPE,                     
        END                           
    };
    enum  RepeatEndType_T
    {
        NO_END=0,                    
        END_BY_COUNT,                
        END_BY_DATE                  
    };

    enum  RepeatType_T
    {
        NO_REPEAT = 0,               
        DAILY,                       
        DAILY_ON_WEEKDAY,            
        WEEKLY,                      
        MONTHLY_ON_DATE,             
        MONTHLY_ON_DAY,              
        YEARLY_ON_DATE,              
        YEARLY_ON_DAY                
    };

    enum DayInWeek_T
    {

        MON = 0x01,                  
        TUE = 0x02,                  
        WED = 0x04,                  
        THU = 0x08,                  
        FRI =  0x10,                 
        SAT = 0x20,                  
        SUN = 0x40,                  
        MONTH_DAY = MON | TUE | WED | THU |FRI | SAT | SUN,   
        WEEK_DAY = MON | TUE | WED | THU | FRI,               
        WEEK_END_DAY = SAT | SUN                              
    };

    enum WeekInMonth_T
    {
        LAST = -1,                   
        FIRST = 1,                   
        SECOND,                      
        THIRD,                       
        FOURTH                       
    };

    enum ExceptionType_T
    {
        EDIT_EXCEPTION = 0,          
        DELETE_EXCEPTION             
    };

    ZCalendarResult_T setDate(CalendarRepeatField_T field, ZCalendarTime_T value);

    ZCalendarResult_T getDate(CalendarRepeatField_T field, ZCalendarTime_T &value) const;

    ZCalendarResult_T setInt(CalendarRepeatField_T field, int value);

    ZCalendarResult_T getInt(CalendarRepeatField_T field, int &value) const;

    ZCalendarResult_T addExceptDate(ZCalendarTime_T dt, ExceptionType_T type);

    ZCalendarResult_T removeExceptDate(ZCalendarTime_T dt, ExceptionType_T type);

    bool isExceptDate(ZCalendarTime_T dt, ExceptionType_T type) const;

    bool hasExceptDate(ExceptionType_T type) const;

    ZCalendarResult_T getExceptDates(ExceptionType_T type, QValueList<ZCalendarTime_T> &dates) const; 

    ZCalendarResult_T setExceptDates(ExceptionType_T type, QValueList<ZCalendarTime_T> &dates);

    ZCalendarResult_T clearExceptDates(ExceptionType_T type);

    ZCalendarResult_T getOccurrences(ZCalendarTime_T &startDate,                     
                                     ZCalendarTime_T &subsetBegin,                  
                                     ZCalendarTime_T &subsetEnd, 
                                     int durationMinutes, 
                                     ZCalendarTimeZone_T &tz,                
                                     QValueList<ZCalendarTime_T> &occurDates);

    bool operator ==( const ZCalendarRepeat &right ) const;

    bool getNextOccurrence(ZCalendarTime_T &startDate, ZCalendarTime_T &from,
                           ZCalendarTimeZone_T &tz, ZCalendarTime_T &next) const;

    bool getNextOccurrenceEx(ZCalendarTime_T &startDate, ZCalendarTime_T &from, 
                           ZCalendarTimeZone_T &tz, ZCalendarTime_T &next) const;                   

    ZCalendarResult_T getEndDate(ZCalendarTime_T &startDate, const int count, 
                        ZCalendarTimeZone_T &tz, ZCalendarTime_T &endDate) const;
    ZCalendarResult_T getCount(ZCalendarTime_T &startDate, ZCalendarTime_T &endDate, 
                               ZCalendarTimeZone_T &tz, int &count) const;


    int getWeekDay(int p_dayInWeek) const;

    ZCalendarResult_T getEndDate(QDateTime &startDate, const int count, QDateTime &endDate) const;

    ZCalendarResult_T getCount(QDateTime &startDate, QDateTime  &endDate, int &count) const;

    ZCalendarRepeat & operator=(const ZCalendarRepeat &rp);

    bool  isValidOccurDate(ZCalendarTime_T &startDate, ZCalendarTimeZone_T &timeZone, ZCalendarTime_T occurDate);

protected:

private:

    ZCalendarResult_T getOccurrences(QDateTime &startDate,                     
                                     QDateTime &subsetBegin,
                                     QDateTime &subsetEnd,
                                     int durationMinutes,
                                     QValueList<QDateTime> &occurDates) const;

    bool getNextOccurrence(QDateTime &startDate, QDateTime &form, QDateTime &next) const;

    int getDateInMonth(int year, int month) const;

    INT8 repeatType; 

    INT32 interval;

    INT32 count;

    ZCalendarTime_T repeatEndDate;

    INT8 repeatEndType;

    INT32 dayInWeek;

    INT8 dayInMonth;

    INT8 weekInMonth;

    INT8 monthInYear;

    QValueList<ZCalendarTime_T> editExceptDates;

    QValueList<ZCalendarTime_T> deleteExceptDates;
};

#endif  
