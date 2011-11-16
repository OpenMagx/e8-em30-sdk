

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PHONE_SERVICEINTERFACE_H
#define PHONE_SERVICEINTERFACE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#define POWER_ON_MODE_NOTIFY_CLI_CHANNEL "/PowerOn/notify/Cli/Channel"
#define POWER_ON_MODE_NOTIFY_ALARM_CHANNEL "/PowerOn/Alarm/notify/Channel"
#define POWER_ON_MODE_NOTIFY_CHARGE_ONLY_CHANNEL "/PowerOn/Alarm/notify/Channel"

#define POWER_ON_MODE_NOTIFY_CLI_MSG "CLI MESSAGE"
#define POWER_ON_MODE_NOTIFY_CLI_MSG_AIRPLANE_ON_BY_PHONE "/PowerOn/notify/Cli/Msg/Airplane/On/ByPhone"
#define POWER_ON_MODE_NOTIFY_CLI_MSG_AIRPLANE_OFF_BY_PHONE "/PowerOn/notify/Cli/Msg/Airplane/Off/ByPhone"
#define POWER_ON_MODE_NOTIFY_CLI_MSG_AIRPLANE_ON_BY_CLI "/PowerOn/notify/Cli/Msg/Airplane/On/ByCli"
#define POWER_ON_MODE_NOTIFY_CLI_MSG_AIRPLANE_OFF_BY_CLI "/PowerOn/notify/Cli/Msg/Airplane/Off/ByCli"
#define POWER_ON_MODE_NOTIFY_ALARM_MSG_BEGIN "/PowerOn/notify/Alarm/Msg/Begin"
#define POWER_ON_MODE_NOTIFY_ALARM_MSG_END "/PowerOn/notify/Alarm/Msg/End"
#define POWER_ON_MODE_NOTIFY_CHARGE_ONLY_TO_NORMAL "/PowerOn/notify/ChargeOnly/ToNormal"

void PHONE_SetRFMode( bool open_RF );   

void PHONE_SetTAPILanguage( int languageCode );

void PHONE_LaunchDialingSetup();

#endif 

