

// Copyright (c) 30-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef __ZCALENDARTYPEDEFS_H__
#define __ZCALENDARTYPEDEFS_H__

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <time.h>
#include <qstring.h>

#define ZCALENDAR_INVALID_UID            0xFFFFFFFF                
#define ZCALENDAR_INVALID_DATE           ((ZCalendarTime_T)-1)     
#define ZCALENDAR_INVALID_CATEGORY_ID    0                         
#define ZCALENDAR_INVALID_PROFILE        -1                        
#define ZCALENDAR_INVALID_ALARM          -1                        
#define ZCALENDAR_INVALID_TZOFFSET       1500                      

#define ZCALENDAR_DATE_MIN               ((ZCalendarTime_T)0x80173fc0) 

#define ZCALENDAR_DATE_MAX               ((ZCalendarTime_T)0x7fe8c03f)  

typedef enum 
{
    ZCALENDAR_RESULT_SUCCESS = 0,       
    ZCALENDAR_RESULT_NOT_FOUND,         
    ZCALENDAR_RESULT_MEMORY_FULL,       
    ZCALENDAR_RESULT_TOO_LARGE,         
    ZCALENDAR_RESULT_INVALID_FIELD,     
    ZCALENDAR_RESULT_INVALID_VALUE,     
    ZCALENDAR_RESULT_FIELD_NOT_SET,     
    ZCALENDAR_RESULT_FIELD_TRUNCATED,   
    ZCALENDAR_RESULT_OTHER_ERROR        
} ZCalendarResult_T;

typedef enum
{
   ZCALENDAR_SEARCH_TYPE_STARTING = 0,  
   ZCALENDAR_SEARCH_TYPE_ENDING,        
   ZCALENDAR_SEARCH_TYPE_OCCURING       
}ZCalendarSearchType_T;

struct ZCalendarTimeZone_T
{
    ZCalendarTimeZone_T()                                   
    {
        tzID=""; 
        tzOffset=ZCALENDAR_INVALID_TZOFFSET; 
        dstStart=""; 
        dstEnd=""; 
        dstBias=0; 
        dstEnabled=false;
    }

    ZCalendarTimeZone_T & operator=(const ZCalendarTimeZone_T & right)  
    {
      tzID = right.tzID;
      tzOffset = right.tzOffset;
      dstStart = right.dstStart;
      dstEnd = right.dstEnd;
      dstBias = right.dstBias;
      dstEnabled = right.dstEnabled;
      return (*this);
    }

    bool operator==(const ZCalendarTimeZone_T & right)                   
    {
      if (tzID != right.tzID) return false;
      if (tzOffset != right.tzOffset) return false;
      if (dstStart != right.dstStart) return false;
      if (dstEnd != right.dstEnd) return false;
      if (dstBias != right.dstBias) return false;
      if (dstEnabled != right.dstEnabled) return false;
      return true;
    }

    QString tzID;      
    int tzOffset;      
    QString dstStart;  
    QString dstEnd;    
    int dstBias;       
    bool dstEnabled;   
};

typedef time_t ZCalendarTime_T;

#endif  

