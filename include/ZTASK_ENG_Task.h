

// Copyright (c) 30-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ZTASK_ENG_Task_H
#define ZTASK_ENG_Task_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>
#include <qdatetime.h>
#include <EZX_TypeDefs.h>

 #define ZTASK_INVALID_DATE_TIME          0x7fffffff

typedef enum
{
    TASK_VTODO_VERSION_INVALID, 
    TASK_VTODO_VERSION_VCAL,    
    TASK_VTODO_VERSION_ICAL,    
} TASK_VTODO_VERSION_T;

class ZTASK_ENG_Task
{
public:

    ZTASK_ENG_Task(void);

    ZTASK_ENG_Task(const ZTASK_ENG_Task &task);

    ~ZTASK_ENG_Task();

    enum TASK_PRIORITY
    {
        TASK_DEFAULT_PRIORITY = 0,  
        TASK_HIGH = 1,              
        TASK_NORMAL = 5,            
        TASK_LOW = 9,               
        TASK_OTHER_PRIORITY         
    };

    enum TASK_STATUS
    {
        TASK_STATUS_COMPLETED = 0,      
        TASK_STATUS_INCOMPLETED,        
        TASK_STATUS_OTHER_STATUS = 8    
    };

    enum TASK_FIELD_T
    {
        UID = 0,         
        CATEGORY_NAME,   
        NOTE,            
        SUMMARY,         
        UUID,            
        ALARM,           
        DUE,             
        END,             
        REVISION,        
        STATUS,          
        PRIORITY         
    };

    ZTASK_ENG_Task & operator = (const ZTASK_ENG_Task &task);

     QDateTime getDateTime(TASK_FIELD_T field);

     void setDateTime(TASK_FIELD_T field, QDateTime value);
     QString getString(TASK_FIELD_T field);

     void setString(TASK_FIELD_T field, QString value);    

     UINT32 getUINT32(TASK_FIELD_T field);

    void setUINT32(TASK_FIELD_T field, UINT32 value);    

     TASK_PRIORITY getPriority();

     int getPriorityValue();

     void setPriority(int value);

     TASK_STATUS getStatus();

     int getStatusValue();

    void setStatus(int value);            

private:

    UINT32 uid;    

    int priority;
    int status;

    QString  note;
    QString  summary;
    QString  uuid;
    QDateTime due; 
    QDateTime revision;
} ;

#endif

