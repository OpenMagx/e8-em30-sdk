

// Copyright (c) 24-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef UTIL_ACTIONGLOBAL_H
#define UTIL_ACTIONGLOBAL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <stdio.h>
#define AM_ACTION_CMD_STATUS_OK 0
#define AM_ACTION_CMD_STATUS_ERROR 1
#define AM_ACTION_CMD_STATUS_CHANNEL_IN_USE 2
#define AM_ACTION_CMD_STATUS_INVOKED 3
#define ACTION_CMD_RETURN_CHANNEL "action_cmd_return_channel_name"
#define ACTION_CMD_RETURN_MSG "action_cmd_return_msg"
#define ACTION_CMD_RETURN_PID_CHANNEL "action_cmd_return_pid_channel_name"
#define ACTION_CMD_RETURN_PID "action_cmd_return_pid"

#define ACTION_CMD_NONQT_FLAG "qtflag"
#define UTIL_ACTION_COMMAND_SERVER_CHANNEL "b781cfe2-72a9-4405-a8ef-928391ba2497"
#define UTIL_ACTION_COMMAND_MSG_INVOKE_ACTION "272e5795-9498-4574-b959-139bde2c71e0"
#define UTIL_ACTION_REGISTER_FILE "ActionRegistry"
#define UTIL_ACTION_ENVIRON_NAME "ACTION_COMMAND"
#define UTIL_ACTION_COMMAND_SEND_ACTION "89de0eb6-9155-42c9-9720-c89bcf81a2b5"

#endif  

