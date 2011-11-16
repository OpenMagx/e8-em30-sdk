

// Copyright (c) 30-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ZTASK_ENG_Model_H
#define ZTASK_ENG_Model_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <time.h>
#include <qvaluelist.h>

#include <EZX_TypeDefs.h>
#include <qshared.h>
#include <qstring.h>

#include"ZTASK_ENG_Task.h"
class SVC_CT_ChangeReporter;

typedef unsigned short uchar_t;

#define IID_TASK_ALARM QUuid("{4ae0f2da-a3f4-413f-801b-1962f913308a}")
#define TASK_ENG_CHANNEL_NAME           "EZX_PIM_TASK_ENG_CHANNEL"
#define TASK_ENG_DATA_CHANGED           "TASK_ENG_dataChanged"

class ZTASK_ENG_Model
{
public:

    ZTASK_ENG_Model(void);

    ~ZTASK_ENG_Model();

    enum TASK_RET
    {
        TASK_RET_SUCCESS = 0,          
        TASK_RET_MEMORY_FULL,          
        TASK_RET_INVALID_VALUE,        
        TASK_RET_RECORD_NOT_FOUND,     
        TASK_RET_RECORD_TOO_LARGE,     
        TASK_RET_SYSTEM_NOT_SUPPORT,   
        TASK_RET_OTHER_ERROR,          
        TASK_RET_DB_NOT_ALIVE,         
        TASK_RET_RECORD_DUPLICATED     
    };

    enum TASK_CATEGORY
    {
        TASK_CATEGORY_ALL = 0,         
        TASK_CATEGORY_DUE,             
        TASK_CATEGORY_INCOMPLETED,     
        TASK_CATEGORY_COMPLETED        
    };

    enum TASK_SORT_FIELD
    {
        TASK_SORT_FIELD_BYDUEDATE = 0,  
        TASK_SORT_FIELD_BYPRIORITY      
    };

    TASK_RET removeAll(void); 

    TASK_RET addTask(ZTASK_ENG_Task &task);

     TASK_RET removeTask(const UINT32 uid);

     TASK_RET removeTasks(QValueList<UINT32> &uidList);

     TASK_RET updateTask(ZTASK_ENG_Task &task);

     TASK_RET getTask(UINT32 uid, ZTASK_ENG_Task &task);   

     TASK_RET getAllIDs(QValueList<UINT32> &uidList);

     TASK_RET getAllIDs(QValueList<UINT32> &uidList, TASK_CATEGORY category, TASK_SORT_FIELD sortfield);

     TASK_RET getCount(int &count);

     TASK_RET getCount(int &count, TASK_CATEGORY category);

     TASK_RET getMatchTasks(QValueList<ZTASK_ENG_Task> &taskList, ZTASK_ENG_Task &matchTask);

     TASK_RET getMatchTasks(QValueList<ZTASK_ENG_Task> &taskList, QString &matchString);

    TASK_RET getTasks(QValueList<ZTASK_ENG_Task> &taskList, QString &category);

    TASK_RET getTasks(QValueList<ZTASK_ENG_Task> &taskList, ZTASK_ENG_Task::TASK_FIELD_T field, 
                     time_t start, time_t end);            

    TASK_RET getTasks(QValueList<ZTASK_ENG_Task> &taskList, ZTASK_ENG_Task &task, 
                     int num, TASK_CATEGORY category, TASK_SORT_FIELD sortfield);

     TASK_RET  addCategory(QString &cat, UINT32 &uid);

     TASK_RET getCategory(int id, QString &name);

     TASK_RET getAllCategories(QValueList<QString> &catList);

     TASK_RET getCategoryId(QString &name, int &id);
     TASK_RET  removeCategory(QString &cat, bool removeFlag);

     TASK_RET  renameCategory(QString &oldName, QString &newName);        

     QString generateUUID();

     bool getTaskWritePath(QString &path);

     bool writeRegisteAlarmTime(int time);

     void setSyncProfileId(int syncProfileId = -1);


    static void shareTaskByBT(ZTASK_ENG_Task* pTask);

    static void shareTaskByMMS(ZTASK_ENG_Task* pTask);

private:

    bool isDBAlive;
    QString alarmFile;

    TASK_RET registerReminder(void);

    TASK_RET createTaskTable(void);
    TASK_RET createCategoryTable(void);
    TASK_RET initTaskDB(void);

    TASK_RET removeTasksWithCategoryId(int catId);
    TASK_RET getAll(QValueList < ZTASK_ENG_Task > &taskList);        

    void stringToUChar(QString s, uchar_t * uch);
    QString ucharToString(const uchar_t * uch);

    int mSyncProfileId;
    SVC_CT_ChangeReporter *changeReporter;


    static QString getFileName(ZTASK_ENG_Task *pTask, bool icalFlex);
};

#endif

