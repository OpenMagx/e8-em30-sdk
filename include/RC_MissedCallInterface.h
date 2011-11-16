

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef RC_MISSEDCALLINTERFACE_H
#define RC_MISSEDCALLINTERFACE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qglobal.h>
#include <qstring.h>
#include <qdatetime.h>
#include <qvaluelist.h>
#include <qobject.h>
#include <RC_RecordInterface.h>

struct RC_MissedCallData
{
	QDateTime callDt;
	QString callerNumber;
	QString callerName;
	int   callIndex;
	RC_CALL_TYPE_T callType;
        int contactType;
};
class RC_MissedCallInterfaceData;

class RC_MissedCallInterface : public QObject
{
	Q_OBJECT
	public:
		static RC_MissedCallInterface* instance();
		static void destruction();
                QValueList<RC_MissedCallData> getAllMissedCalls();

		QValueList<RC_MissedCallData> getUnreadMissedCalls(); 

signals:
		void dataUpdate();    
	private:
		RC_MissedCallInterface();
		~RC_MissedCallInterface();
		RC_MissedCallInterface(const RC_MissedCallInterface&);
		RC_MissedCallInterface& operator=(const RC_MissedCallInterface&);
	private:
		RC_MissedCallInterfaceData *d;   

};

#endif  

