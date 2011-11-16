

// Copyright (c) 13-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef WORLDCLOCK_TYPEDEFS_H
#define WORLDCLOCK_TYPEDEFS_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "EZX_TypeDefs.h"
#include <qstring.h>

class GMTOffset
{
public:  
    static const INT32 BeginZone = -12;  
    static const INT32 EndZone = 13;     

public:
    INT32 hour;     
    INT32 minute;   
    INT32 second;   

private:
    static const INT32 InvalidHour = -14;

    INT32 hourSign() const
    {
        return ( hour > 0 ? 1 : ( hour < 0 ? -1 : 0 ) );
    }

public:

    GMTOffset(const INT32 h = InvalidHour, const INT32 m = 0, const INT32 s = 0)
        : hour(h), minute(m), second(s) { }

    bool isInvalid() const
    {
        return (hour == InvalidHour);
    }

    INT32 toMinutes() const
    {
        return (hour * 60 + hourSign() * (minute + second / 60));
    }

    INT32 toSeconds() const
    {
        return (hour * 3600 + hourSign() * (minute * 60 + second));
    }

    static GMTOffset fromMinutes(const INT32 minutes)
    {
        GMTOffset gmt;

        gmt.hour = minutes / 60;
        gmt.minute = minutes % 60;
        if (gmt.minute < 0) gmt.minute = -gmt.minute;
        return gmt;
    }

    static GMTOffset fromSeconds(const INT32 seconds)
    {
        GMTOffset gmt;

        gmt.hour = seconds / 3600;
        INT32 remainder = seconds % 3600;
        if (remainder != 0)
        {
            if (remainder < 0) remainder = -remainder;
            gmt.minute = remainder / 60;
            gmt.second = remainder % 60;
        }
        return gmt;
    }

    bool operator== (const GMTOffset& p) const
    {
        return (hour == p.hour && minute == p.minute && second == p.second);
    }

    bool operator!= (const GMTOffset& p) const
    {
        return (hour != p.hour || minute != p.minute || second != p.second);
    }
};

class DSTInfo
{
private:
    static const int InvalidOffset = -20;

public:
    QString startRule; 
    QString endRule;   
    double  offset;    

    DSTInfo(const QString& srule = "", const QString& erule = "", const double o = InvalidOffset)
        : startRule(srule), endRule(erule), offset(o) { }

    bool isInvalid() const
    {
        int delta = (int) ((offset - InvalidOffset) * 60);
	return (delta == 0);
    }

    bool operator== (const DSTInfo& p) const
    {
        return (startRule == p.startRule && endRule == p.endRule && offset == p.offset);
    }

    bool operator!= (const DSTInfo& p) const
    {
        return (startRule != p.startRule || endRule != p.endRule || offset != p.offset);
    }
};

class CityInfo
{
public:
    QString   cityName;  
    GMTOffset gmt;       
    DSTInfo   dst;       

    bool isInvalid() const
    {
        return (gmt.isInvalid() && dst.isInvalid());
    }
};

struct LocationInfo
{
    CityInfo ci;  
    bool inDst;   
};

QDataStream& operator<<(QDataStream& s, const CityInfo& ci);

QDataStream& operator>>(QDataStream& s, CityInfo& ci);

#endif 
