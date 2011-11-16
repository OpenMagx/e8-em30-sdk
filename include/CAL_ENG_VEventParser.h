

// Copyright (c) 30-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef CAL_ENG_VEVENTPARSER_H
#define CAL_ENG_VEVENTPARSER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <stdio.h>

#include <qstring.h>
#include <qcstring.h>

#include "ZCalendarEvent.h"
#include "CAL_ENG_Global.h"

typedef struct VObject VObject;
typedef struct VObjectIterator VObjectIterator;

class CAL_ENG_VEventParser
{
public:
    CAL_ENG_VEventParser();

    ~CAL_ENG_VEventParser();

    bool writeVEvent( const QString &filename, 
                      ZCalendarEvent &event,
                      CAL_VCAL_FORMAT_T fmt = CAL_VCAL_FORMAT_STANDARD);

    bool readVEvent(const QString &filename, ZCalendarEvent &event, const bool callFromSyncML = false);

    bool fromVCalendar(QByteArray &vCal, ZCalendarEvent &event, const bool callFromSyncML = false);

    bool toVCalendar(ZCalendarEvent &event, QByteArray &vCal,        \
         CAL_VCAL_FORMAT_T fmt = CAL_VCAL_FORMAT_STANDARD);

protected:

private:
    bool parseVObject( VObject *obj, ZCalendarEvent &e, ZCalendarTimeZone_T *tz, const bool callFromSyncML= false );
    void getNextVobject(VObject * obj);
    bool parseRepeatRule(ZCalendarEvent & e, QCString & s, ZCalendarTimeZone_T *tz );
    QString parseVObjectText(VObject * obj, QCString & propText);
    VObject *createVObject(ZCalendarEvent &e, CAL_VCAL_FORMAT_T fmt = CAL_VCAL_FORMAT_STANDARD);
    inline VObject *safeAddProp( VObject *o, const char *prop);
    inline VObject *safeAddPropValue( VObject *o, const char *prop, const char *);

    bool parseWeeklyDays (char **s, ZCalendarRepeat * rp);
    bool parseRepeatDuration (char **s, ZCalendarRepeat * rp, ZCalendarTimeZone_T *tz);
    bool parseRepeatInterval (char **s, ZCalendarRepeat * rp);
    bool parseMonthlyDays (char **s, ZCalendarRepeat * rp);
    bool parseMonthlyByPosition(char **s, ZCalendarRepeat * rp);
    bool parseYearlyByMonth (char **s, int & month);
    bool parseDSTRule(const char *s, ZCalendarTimeZone_T &timeZone);
    void getNextVobject_d(VObject * obj);

    VObject * newVObject_d(const char *id);
    void initPropIterator_d(VObjectIterator *i, VObject *o);
    int moreIteration_d(VObjectIterator *i);
    VObject* nextVObject_d(VObjectIterator *i);
    const char* vObjectName_d(VObject *o);
    const char* vObjectStringZValue_d(VObject *o);
    const char* vObjectUStringZValue_d(VObject *o);
    void writeVObject_d(FILE *fp, VObject *o);
    void cleanVObject_d(VObject *o);
    void cleanStrTbl_d();
    VObject* Parse_MIME_FromFileName_d(char* fname);
    VObject* nextVObjectInList_d(VObject *o);
    const char * wCharToChar (const wchar_t *u);
    void parseTimeZone(ZCalendarTimeZone_T &tz, VObject *o ); 
    bool parseEventProperty(ZCalendarTimeZone_T &tz, QCString &strDSTRule, ZCalendarEvent &event, VObject *o,bool &found, const bool callFromSyncML = false); 

    void *vCalHandle;

    CAL_VCAL_FORMAT_T mVCalFormat;
};

#endif  
