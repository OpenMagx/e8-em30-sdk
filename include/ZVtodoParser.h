

// Copyright (c) 30-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ZVtodoParser_H
#define ZVtodoParser_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qlist.h>
#include <qstring.h>
#include <qglist.h>
#include <qcollection.h>
#include <qcstring.h>

#include "ZTASK_ENG_Task.h"
#include "vobject.h"
#include "ical.h"

#define TASKS_DATETIME_NULL "30001231T235959"

typedef struct VObject VObject;

class ZVtodoParser
{
public:

    ZVtodoParser();

    ~ZVtodoParser();

    void writeVtodo(const QString& filename, QList<ZTASK_ENG_Task>& list, TASK_VTODO_VERSION_T version=TASK_VTODO_VERSION_VCAL);

    void writeVtodo(const QString& filename, ZTASK_ENG_Task* pData, TASK_VTODO_VERSION_T version=TASK_VTODO_VERSION_VCAL);

    void readVtodo(const QString& filename, QList<ZTASK_ENG_Task>& list);

    void readVtodo(const QCString& str, QList<ZTASK_ENG_Task>& list);

    bool isVtodo(const QString& filename);

private:
    int getPriorityValue(QCString value);
    int getStatusValue(QCString value);

    void *vCalHandle;
    void *iCalHandle;

    VObject * newVObject_d(const char *id);
    void initPropIterator_d(VObjectIterator *i, VObject *o);
    int moreIteration_d(VObjectIterator *i);
    VObject* nextVObject_d(VObjectIterator *i);
    const char* vObjectName_d(VObject *o);
    const char* vObjectStringZValue_d(VObject *o);
    const char* vObjectUStringZValue_d(VObject *o);
    void writeVObject_d(FILE *fp, VObject *o);
    void cleanVObject_d(VObject *o);
    VObject* nextVObjectInList_d(VObject *o);
    VObject* Parse_MIME_FromFileName_d(char* fname);
    VObject* Parse_MIME_FromString_d(char* string, unsigned long len);
    VObject * safeAddPropValue( VObject *obj, const char *prop, const QString& value );
    VObject* safeAddProp(VObject* o, const char* prop);
    QString parseVObjectText(VObject* obj, QCString& propText);

    void writeVtodoToVCal(const QString& filename,  QList<ZTASK_ENG_Task> &list);
    void readVtodoFromVCal(const QString& filename, QList<ZTASK_ENG_Task>&list);
    void readVtodoFromVCal(const QCString& str, QList<ZTASK_ENG_Task>& list);
    VObject* toVtodo(QList<ZTASK_ENG_Task>& list);
    ZTASK_ENG_Task* toTaskRec(VObject* obj);    

    TASK_VTODO_VERSION_T getVTodoVersion(const QString &filename);
    TASK_VTODO_VERSION_T getVTodoVersion(const QCString &str);

    icalparser* icalparser_new_d(void);
    void icalparser_free_d(icalparser* parser);
    void icalparser_set_gen_data_d(icalparser* parser, void* data);
    char* icalparser_get_line_d(icalparser* parser, char* (*line_gen_func)(char *s, size_t size, void *d));
    icalcomponent* icalparser_add_line_d(icalparser* parser, char* str );
    icalcomponent* icalcomponent_new_d(icalcomponent_kind kind);
    void icalcomponent_free_d(icalcomponent* component);
    void icalcomponent_add_component_d(icalcomponent* parent, icalcomponent* child);
    void icalcomponent_add_property_d(icalcomponent* component, icalproperty* property);
    void icalcomponent_set_summary_d(icalcomponent* comp, const char* v);
    void icalcomponent_set_due_d(icalcomponent* comp, struct icaltimetype v);
    void icalcomponent_set_status_d(icalcomponent* comp, enum icalproperty_status v);
    void icalcomponent_set_description_d(icalcomponent* comp, const char* v);
    char* icalcomponent_as_ical_string_d(icalcomponent* component);
    const char* icalcomponent_get_summary_d(icalcomponent* comp);
    struct icaltimetype icalcomponent_get_due_d(icalcomponent* comp);
    enum icalproperty_status icalcomponent_get_status_d(icalcomponent* comp);
    int icalproperty_get_priority_d(const icalproperty* prop);
    const char* icalcomponent_get_description_d(icalcomponent* comp);
    icalcomponent* icalcomponent_get_first_component_d(icalcomponent* component, icalcomponent_kind kind);    
    icalproperty* icalcomponent_get_first_property_d(icalcomponent* component, icalproperty_kind kind);
    icalproperty* icalproperty_new_version_d(const char* v);
    icalproperty* icalproperty_new_prodid_d(const char* v);
    icalproperty* icalproperty_new_completed_d(struct icaltimetype v);
    icalproperty* icalproperty_new_priority_d(int v);
    void icalproperty_free_d(icalproperty* prop);
    struct icaltimetype icaltime_null_time_d(void);
	struct icaltimetype icalproperty_get_completed_d(const icalproperty* prop);

    void writeVtodoToICal(const QString& filename, QList<ZTASK_ENG_Task> & list);
    void readVtodoFromICal(const QString& filename, QList<ZTASK_ENG_Task>& list);
    void readVtodoFromICal(const QCString& str, QList<ZTASK_ENG_Task>& list);
    ZTASK_ENG_Task* icalendar2Task (icalcomponent *comp);
};

#endif

