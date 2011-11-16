

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef RC_RECORDINTERFACE_H
#define RC_RECORDINTERFACE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>
#include <qdatetime.h>
#include <time.h>

#define SIP_URI_MAX_LEN 100

typedef enum
{
	RC_CALL_CATEGORY_NONE ,  
	RC_CALL_CATEGORY_ANSWERED ,
	RC_CALL_CATEGORY_UNANSWERED ,
	RC_CALL_CATEGORY_CALLED ,
	RC_CALL_CATEGORY_ALL_CALLS ,
	RC_CALL_CATEGORY_FREQUENT ,
}RC_CALL_CATEGORY_T;

typedef enum
{
	RC_CALL_TYPE_NONE=0,
	RC_CALL_TYPE_VOICECALL,
	RC_CALL_TYPE_VTCALL,
	RC_CALL_TYPE_PTT_OMA,
	RC_CALL_TYPE_PTT_KODIAK,
	RC_CALL_TYPE_ALL,
}RC_CALL_TYPE_T;

typedef enum
{
	RC_PTT_CALL_TYPE_NORMAL=0,
	RC_PTT_CALL_TYPE_IVM,
	RC_PTT_CALL_TYPE_IVB,
}RC_PTT_CALL_TYPE_T;

typedef enum
{
	RC_PTT_PARTY_TYPE_NONE=-1,
	RC_PTT_PARTY_TYPE_INDIVIDUAL,
	RC_PTT_PARTY_TYPE_PRESET_GROUP,
	RC_PTT_PARTY_TYPE_ADHOC_GROUP,
	RC_PTT_PARTY_TYPE_DYNAMIC_GROUP, 
	RC_PTT_PARTY_TYPE_PERSONAL_INVITE,
	RC_PTT_PARTY_TYPE_TYPE_CHAT_GROUP, 
}RC_PTT_PARTY_TYPE_T;

typedef enum
{
	RC_PTT_ID_MSISDN,
	RC_PTT_ID_TEL_URI,
	RC_PTT_ID_SIP_URI,
}RC_PTT_ID_T;

typedef enum
{
	RC_PTT_CLI_TYPE_PRIVATE,
	RC_PTT_CLI_TYPE_NAME,
	RC_PTT_CLI_TYPE_UNKNOWN,
}RC_PTT_CLI_TYPE_T;

typedef int RC_UID_T;
typedef struct 
{
	QString number;
	RC_PTT_CLI_TYPE_T cliType;
	QDateTime startDateTime;
	int duration;
	RC_CALL_CATEGORY_T category;
	bool bCompleted;
	RC_PTT_ID_T pttIDType;
	RC_PTT_CALL_TYPE_T pttCallType; 
	RC_PTT_PARTY_TYPE_T pttPartyType;
	QString pttSessionID;
}RC_PttInfo_T;

class RC_RecordInterface;

class RC_RecordIfcFactory 
{ 
public: 
    static RC_RecordInterface* createPttOMARCRecord(const RC_PttInfo_T& pttInfo);

    static RC_RecordInterface* createPttKodiakRCRecord(const RC_PttInfo_T& pttInfo);

    static RC_RecordInterface* createVTRCRecord(const QString & num, const QDateTime& startDt,int t);

    static RC_RecordInterface* createVTRCRecord();

    static void destroyRCRecord(RC_RecordInterface* p);

private:    
    RC_RecordIfcFactory();
    ~RC_RecordIfcFactory();
	RC_RecordIfcFactory(const RC_RecordIfcFactory&);
	RC_RecordIfcFactory& operator=(const RC_RecordIfcFactory&);
}; 
class RC_RecordInterface 
{
public:

	virtual void setCategory(RC_CALL_CATEGORY_T cat)=0;

	virtual RC_CALL_CATEGORY_T getCategory() const=0;

	virtual void setPhoneNumber(const QString & number)=0;
	virtual QString getPhoneNumber() const=0;

	virtual void setStartDateTime(const QDateTime & startDt)=0;
	virtual QDateTime getStartDateTime() const=0;

	virtual void setDuration(int duration)=0;
	virtual int getDuration() const=0;
	virtual void setCompletedStatus(bool completed)=0;
	virtual bool getCompletedStatus()const=0;

	virtual bool isRead() const=0;
	virtual void setRead(bool read)=0;
	virtual RC_UID_T getUID() const=0;
	virtual RC_CALL_TYPE_T getCallType()const=0;

    virtual ~RC_RecordInterface(){};

};

#endif  
