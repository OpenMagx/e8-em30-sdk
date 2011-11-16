

// Copyright (c) 23-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef SVC_CN_CHANGENOTIFICATION_H
#define SVC_CN_CHANGENOTIFICATION_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

class DS_CN_NotificationReceiver;
class SVC_CN_NotificationHandler;

class SVC_CN_ChangeNotification
{
public:

    SVC_CN_ChangeNotification();

    ~SVC_CN_ChangeNotification();

    int registerHandler (const char* appId, SVC_CN_NotificationHandler* handler, bool needSimChange);

    int deregisterHandler (const char* appId, SVC_CN_NotificationHandler* handler);

private:
    SVC_CN_ChangeNotification(const SVC_CN_ChangeNotification& changenotification);

    const SVC_CN_ChangeNotification& operator=(const SVC_CN_ChangeNotification& changenotification);
private:
    DS_CN_NotificationReceiver* i_pRecvNotification;
};

#endif 

