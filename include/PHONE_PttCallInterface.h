

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PHONE_PTTCALLINTERFACE_H
#define PHONE_PTTCALLINTERFACE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <RC_RecordInterface.h>
#include <qstring.h>
#include <TAPI_CALL_General.h>

#define PTT_MAX_PHONE_NUMBERS 25 
typedef enum
{
	CALL_TYPE_PTT_NORMAL = 0,
	CALL_TYPE_PTT_IVM,
	CALL_TYPE_PTT_IVB,
}CALL_TYPE_PTT_T;

typedef enum
{ 
	PTT_CALLING_PARTY_TYPE_INDIVIDUAL = 0, 
	PTT_CALLING_PARTY_TYPE_PRESET_GROUP, 
	PTT_CALLING_PARTY_TYPE_ADHOC_GROUP, 
	PTT_CALLING_PARTY_TYPE_DYNAMIC_GROUP, 
	PTT_CALLING_PARTY_TYPE_PERSONAL_INVITE,
	PTT_CALLING_PARTY_TYPE_CHAT_GROUP, 
	PTT_CALLING_PARTY_TYPE_INSTANT_PERSONAL_ALERT 
} PTT_CALLING_PARTY_TYPE_T;

typedef struct {

	QString calleeName[PTT_MAX_PHONE_NUMBERS];

	QString numberList[PTT_MAX_PHONE_NUMBERS];

	unsigned char numberCount;

	CALL_TYPE_PTT_T callType;

	PTT_CALLING_PARTY_TYPE_T callingPartyType;

} PTT_CALL_INFO_T;

bool PHONE_MakePttCall(const PTT_CALL_INFO_T& pttcallInfo);

bool PHONE_AnswerPttCall(const TAPI_CALL_ID_T callId);

bool PHONE_HoldPttCall(const TAPI_CALL_ID_T callId);

bool PHONE_SwitchPttCall(const TAPI_CALL_ID_T toHoldCallId, const TAPI_CALL_ID_T toRetrieveCallId);

bool PHONE_DropPttCall(const TAPI_CALL_ID_T callId=0);

bool PHONE_DropAllCalls(void);

extern "C" bool PHONE_MAKEPTTCALL(const PTT_CALL_INFO_T pttcallInfo);

typedef bool (*PHONE_MAKEPTTCALL_T)(const PTT_CALL_INFO_T );
#endif  

