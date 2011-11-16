

// Copyright (c) 25-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef AM_launcherClient_h
#define AM_launcherClient_h

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qobject.h>
#include <quuid.h>
#include <qstring.h>
#include <qdatastream.h>
#include <qvaluelist.h>
#include "AM_Defs.h"
#include "AM_AppLnk.h"

class QCopChannel;
class AM_ActionData;
class SLauncher;

class AM_LauncherClient
{
friend class AM_LauncherChannelServer;
public:
	enum AM_LAUNCHER_INITIATOR_T
	{
	    APPLICATION = 0,
	    MAIN_MENU = 1,
	    HOME_SCREEN = 2,
	    VOICE_COMMAND = 3,
	    DEDICATED_KEY = 4
	};

    struct AM_ApplicationState {
        QString uid;
        AM_APPLICATION_STATE_T state;
    };

private:
	enum AM_LaunchOptions
	{
	  _appLockCheck 	=	1,
	  _phoneLockCheck	= 	1 << 1,
	  _raiseUI 		=	1 << 2,
	  _voice		=	1 << 3,
	  _saveAppChoice	=	1 << 4,
	  _openDocs		=	1 << 5,
	  _loadUrl		=	1 << 6,
	  _sendBridgeMsg	=	1 << 7,
	  _launchApp		=	1 << 8,
	  _launchObj		=	1 << 9,
	};
public:

    static AM_RESULT_CODE_T launchApplication(const QUuid &appId,
            const QString &args = QString::null, 
            AM_LAUNCHER_INITIATOR_T initiator = APPLICATION,
            bool appLockCheck = true, bool phoneLockCheck = true);

    static AM_RESULT_CODE_T launchAppObject(const QString &uid, 
            const QString &args = QString::null, 
            AM_LAUNCHER_INITIATOR_T initiator = APPLICATION, 
            bool appLockCheck = true, bool phoneLockCheck = true);

    static AM_RESULT_CODE_T sendBridgeMessage(const QUuid &appId, 
            const QCString &action, const QByteArray &data, 
            bool withRaise = true, bool applockCheck = true);

    static AM_RESULT_CODE_T openDocument(const QString &docFileName, 
                                         const QString &mimeType = QString::null, 
                                         bool  applockCheck = true);

    static AM_RESULT_CODE_T openDocumentWith(const QString &docFileName, 
                                             const QUuid &uid, 
                                             bool  setDefault = false, 
                                             bool  applockCheck = true);

    static AM_RESULT_CODE_T loadURL(const QString &url);

    static AM_RESULT_CODE_T invokeActionCommand(const AM_ActionData & data, const bool needReturnData = false);

    static AM_RESULT_CODE_T getAppState(const QString & uid,
            AM_APPLICATION_STATE_T & state,
            const QByteArray & criteria = 0);

    static AM_RESULT_CODE_T updateAppState(const QString & uid,
            AM_APPLICATION_STATE_T newState);

    static AM_RESULT_CODE_T getAppStates(AM_AppLnk::AppType appType, 
            QValueList<AM_ApplicationState> & list);

private:	
    static AM_RESULT_CODE_T Launch(SLauncher& launcher);

    static int initClientSocket(const char * path);
    static AM_RESULT_CODE_T sendRequestToServer(int socket,
            const char * message, const QByteArray & data);
    static AM_RESULT_CODE_T receiveResultFromServer(int socket,
            QByteArray & data);

    static AM_RESULT_CODE_T sendGetAppStateRequest(int socket,
            const QString & uid, const QByteArray & criteria);
    static AM_RESULT_CODE_T receiveGetAppStateResult(int socket,
            AM_APPLICATION_STATE_T & state);

    static AM_RESULT_CODE_T sendUpdateAppStateRequest(int socket,
            const QString & uid, AM_APPLICATION_STATE_T newState);

    static AM_RESULT_CODE_T receiveUpdateAppStateResult(int socket);

    static AM_RESULT_CODE_T sendGetAppStatesRequest(int socket,
            AM_AppLnk::AppType appType);
    static AM_RESULT_CODE_T receiveGetAppStatesResult(int socket,
            QValueList<AM_ApplicationState> & list);

};
#endif 

