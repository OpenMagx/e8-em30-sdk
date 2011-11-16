/********************************************************************
* Copyright (C) 2006, 2007 Motorola, Inc. 
* 
* File Name: libaplog.h
*
* General Description: Macros and requirements for libaplog shared library
*
*
* This program is licensed under a BSD license with the following terms:
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are
* met:
*
*   o Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
*
*   o Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in the
*     documentation and/or other materials provided with the distribution.
*
*   o Neither the name Motorola nor the names of its contributors may be
*     used to endorse or promote products derived from this software without
*     specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
* OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
* PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*
*
* Revision History
*   Date          Author         Description
* ----------    --------------  ------------------------------------------
* 11/21/2006    Motorola        Initial creation
* 01/03/2007    Motorola        Fixed for C++ programs
* 01/10/2007    Motorola        License fixes
* 01/19/2007    Motorola        Corrected issues in binary logging; made
*                               aplog_open_port match the API document.
* 01/22/2007    Motorola        Moved to shared library only
* 02/21/2007    Motorola        Dynamic log configuration and capture
* 03/28/2007    Motorola        Added new macros for EzX Style Logging
* 09/07/2007    Motorola        Modify the default log level
*
*********************************************************************/


#ifndef _LIBAPLOG_H_
#define _LIBAPLOG_H_

/*****************************
 * Includes
 *****************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>

#if (FEAT_LIBAPLOG_DYNAMIC == 1)

/*****************************
 * Log Level Defines
 *****************************/
#define APLOG_EMERG     1
#define APLOG_ALERT     2
#define APLOG_CRIT      3
#define APLOG_ERR       4
#define APLOG_WARNING   5
#define APLOG_NOTICE    6
#define APLOG_INFO      7
#define APLOG_DEBUG     8

/* Extra Level Defines */
#define APLOG_INVALID       -2
#define APLOG_UNSET         -1
#define APLOG_OFF           0
#define APLOG_DEBUG_MODE    99

/*****************************
 * Compile time configuration
 *****************************/
#if (!defined(FEAT_LIBAPLOG_LEVEL))
#define FEAT_LIBAPLOG_LEVEL APLOG_INVALID
#warning Invalid log level defined
#endif /* Not defined FEAT_LIBAPLOG_LEVEL */

#if (FEAT_LIBAPLOG_LEVEL == APLOG_EMERG)    /* EMERG and up */
#define _LIBAPLOG_COMPILE_LEVEL APLOG_EMERG
#elif (FEAT_LIBAPLOG_LEVEL == APLOG_ALERT)  /* ALERT and up */  
#define _LIBAPLOG_COMPILE_LEVEL APLOG_ALERT
#elif (FEAT_LIBAPLOG_LEVEL == APLOG_CRIT)   /* CRIT and up */
#define _LIBAPLOG_COMPILE_LEVEL APLOG_CRIT
#elif (FEAT_LIBAPLOG_LEVEL == APLOG_ERR)    /* ERR and up */
#define _LIBAPLOG_COMPILE_LEVEL APLOG_ERR
#elif (FEAT_LIBAPLOG_LEVEL == APLOG_WARNING) /* WARNING and up */
#define _LIBAPLOG_COMPILE_LEVEL APLOG_WARNING
#elif (FEAT_LIBAPLOG_LEVEL == APLOG_NOTICE) /* NOTICE and up */
#define _LIBAPLOG_COMPILE_LEVEL APLOG_NOTICE
#elif (FEAT_LIBAPLOG_LEVEL == APLOG_INFO)   /* INFO and up */
#define _LIBAPLOG_COMPILE_LEVEL APLOG_INFO
#elif (FEAT_LIBAPLOG_LEVEL == APLOG_DEBUG)  /* DEBUG and up */
#define _LIBAPLOG_COMPILE_LEVEL APLOG_DEBUG    
#elif (FEAT_LIBAPLOG_LEVEL == APLOG_OFF)    /* No Logging */
#define _LIBAPLOG_COMPILE_LEVEL APLOG_OFF    
#elif (FEAT_LIBAPLOG_LEVEL == APLOG_DEBUG_MODE) /* Debugging mode */
#define _LIBAPLOG_COMPILE_LEVEL APLOG_DEBUG
#define LIBAPLOG_DEBUG
#elif (TEST_ENGBLD == 1)
#define _LIBAPLOG_COMPILE_LEVEL APLOG_ERR    /* Slightly more logging for LJAP builds */
#else
#define _LIBAPLOG_COMPILE_LEVEL APLOG_CRIT    /* Only log what is really important in production. */
#endif

/*****************************
 * Constants
 *****************************/

/* Maximum character length of port names (including NULL teriminator). */
/* This value must be a multiple of 4 to maintain word alignment. */
#define APLOG_MAX_PORT_NAME_LEN 32

/* Maximum length of log messages in bytes. This number is 0xFFFF minus 32.
 * Maximum length of socket data is the max in a 2 byte field minus header.
 */
#define APLOG_MAX_MSG_LEN 65503

/* Currently supported values for the port flags (these are set by API callers.*/ 
#define APLOG_PORT_OPT_NONBLOCK  0x01

#define APLOG_PORT_ALL_OPT  (APLOG_PORT_OPT_NONBLOCK)

/* Currently supported values for the conf flags (these are set by host tools.*/ 
#define APLOG_PORT_CONF_APP_TRACE 0x01
#define APLOG_PORT_CONF_LIB_ONLY  0x02

#define APLOG_PORT_ALL_CONF  (APLOG_PORT_CONF_APP_TRACE | \
                              APLOG_PORT_CONF_LIB_ONLY)

/*****************************
 * Data types
 *****************************/
/* These are only here to allow 'pointers' of these types to be created.
 * They are NOT used yet. */
struct aplog_port_struct
{
    unsigned int port_flags;
    unsigned int conf_flags;
    int ref_count;
    unsigned short less_child_id;
    unsigned short more_child_id;
    unsigned short port_id;
    signed char port_log_level;
    char reserved;
    char port_name[APLOG_MAX_PORT_NAME_LEN];
};


/*****************************
 * Internal Macro Defines
 *****************************/
#if defined(LIBAPLOG_DEBUG)                 /* Debug; Logging Enabled*/
#define _aplog_ascii(port_ptr, level, format, args...)                \
    printf("port_ptr: 0x%08X; level: %d\n", (unsigned int) port_ptr,    \
            level);                                                     \
    _aplog_configured_printf(level, format, ##args)
#elif (_LIBAPLOG_COMPILE_LEVEL == APLOG_OFF)    /* Logging Disabled */
#define _aplog_ascii(port_ptr, level, format, args...)
#else                                           /* Logging Enabled */
#define _aplog_ascii(port_ptr, level, format, args...)                \
    _aplog_configured_printf(level, format, ##args)
#endif

#if defined(LIBAPLOG_DEBUG)                 /* Debug */
#define _aplog_binary(port_ptr, level, msg_id, data, size)             \
    printf("Binary! port_ptr: 0x%08X; level: %d; msg_id: 0x%08X; Data: 0x%08X; Size = %d\n",  \
            port_ptr, level, msg_id, data, size);                      \
    _aplog_configured_binlog(level, data, size)
#elif (_LIBAPLOG_COMPILE_LEVEL == APLOG_OFF)    /* Logging Disabled */
#define _aplog_binary(port_ptr, level, msg_id, data, size)
#else                                           /* Logging Enabled */
#define _aplog_binary(port_ptr, level, msg_id, data, size)              \
    _aplog_configured_binlog(level, data, size)
#endif

/*****************************
 * API Macro Defines
 *****************************/

/* Setup / Shutdown */
#define aplog_startup _aplog_init
#define aplog_shutdown _aplog_exit

/* 'Syslog' Macros; ASCII and Binary */
#if (APLOG_EMERG <= _LIBAPLOG_COMPILE_LEVEL)  
#define aplog(level, format, args...)                                   \
    aplog_port(NULL, level, format, ##args)
#else
#define aplog(level, format, args...)
#endif

#if (APLOG_EMERG <= _LIBAPLOG_COMPILE_LEVEL)  
#define aplog_port _aplog_port_log_ascii
#else
#define aplog_port
#endif

#if (APLOG_EMERG <= _LIBAPLOG_COMPILE_LEVEL)  
#define aplog_bin(level, msg_id, ptr, size)                             \
    aplog_port_bin(NULL, level, msg_id, ptr, size)
#else
#define aplog_bin(level, msg_id, ptr, size)
#endif

#if (APLOG_EMERG <= _LIBAPLOG_COMPILE_LEVEL)  
#define aplog_port_bin _aplog_port_log_bin
#else
#define aplog_port_bin
#endif

/* ASCII logging; Specified port */
#if (APLOG_EMERG <= _LIBAPLOG_COMPILE_LEVEL)  
#define aplog_port_emerg(port_ptr, format, args...)                     \
    aplog_port(port_ptr, APLOG_EMERG, format, ##args)
#else
#define aplog_port_emerg(port_ptr, format, args...)
#endif

#if (APLOG_ALERT <= _LIBAPLOG_COMPILE_LEVEL)
#define aplog_port_alert(port_ptr, format, args...)                     \
    aplog_port(port_ptr, APLOG_ALERT, format, ##args)
#else
#define aplog_port_alert(port_ptr, format, args...)
#endif

#if (APLOG_CRIT <= _LIBAPLOG_COMPILE_LEVEL)
#define aplog_port_crit(port_ptr, format, args...)                      \
    aplog_port(port_ptr, APLOG_CRIT, format, ##args)
#else
#define aplog_port_crit(port_ptr, format, args...)
#endif

#if (APLOG_ERR <= _LIBAPLOG_COMPILE_LEVEL)
#define aplog_port_err(port_ptr, format, args...)                       \
    aplog_port(port_ptr, APLOG_ERR, format, ##args)
#else
#define aplog_port_err(port_ptr, format, args...)
#endif

#if (APLOG_WARNING <= _LIBAPLOG_COMPILE_LEVEL)
#define aplog_port_warning(port_ptr, format, args...)                   \
    aplog_port(port_ptr, APLOG_WARNING, format, ##args)
#else
#define aplog_port_warning(port_ptr, format, args...)
#endif

#if (APLOG_NOTICE <= _LIBAPLOG_COMPILE_LEVEL)
#define aplog_port_notice(port_ptr, format, args...)                    \
    aplog_port(port_ptr, APLOG_NOTICE, format, ##args)
#else
#define aplog_port_notice(port_ptr, format, args...)
#endif

#if (APLOG_INFO <= _LIBAPLOG_COMPILE_LEVEL)
#define aplog_port_info(port_ptr, format, args...)                      \
    aplog_port(port_ptr, APLOG_INFO, format, ##args)
#else
#define aplog_port_info(port_ptr, format, args...)
#endif

#if (APLOG_DEBUG <= _LIBAPLOG_COMPILE_LEVEL)
#define aplog_port_debug(port_ptr, format, args...)                     \
    aplog_port(port_ptr, APLOG_DEBUG, format, ##args)
#else
#define aplog_port_debug(port_ptr, format, args...)
#endif

/* ASCII logging; Default port */
#define aplog_emerg(format, args...)                                    \
    aplog_port_emerg(NULL, format, ##args)

#define aplog_alert(format, args...)                                    \
    aplog_port_alert(NULL, format, ##args)

#define aplog_crit(format, args...)                                     \
    aplog_port_crit(NULL, format, ##args)

#define aplog_err(format, args...)                                      \
    aplog_port_err(NULL, format, ##args)

#define aplog_warning(format, args...)                                  \
    aplog_port_warning(NULL, format, ##args)

#define aplog_notice(format, args...)                                   \
    aplog_port_notice(NULL, format, ##args)

#define aplog_info(format, args...)                                     \
    aplog_port_info(NULL, format, ##args)

#define aplog_debug(format, args...)                                    \
    aplog_port_debug(NULL, format, ##args)

/* ASCII logging; File & line included */
#define _FILE_LINE_PREFIX     "(%s:%d)"
#define _FILE_LINE_ARGS       __FILE__,__LINE__

#define aplog_port_fileline(port_ptr, level, format, args...)               \
    aplog_port(port_ptr, level, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS,  \
            ##args)
#define aplog_fileline(level, format, args...)                    \
    aplog_port_fileline(NULL, level, format, ##args)

/*** Port specified */
#define aplog_port_emerg_fileline(port_ptr, format, args...)                \
    aplog_port_emerg(port_ptr, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS,   \
            ##args)

#define aplog_port_alert_fileline(port_ptr, format, args...)                \
    aplog_port_alert(port_ptr, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS,   \
            ##args)

#define aplog_port_crit_fileline(port_ptr, format, args...)                 \
    aplog_port_crit(port_ptr, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS,    \
            ##args)

#define aplog_port_err_fileline(port_ptr, format, args...)                  \
    aplog_port_err(port_ptr, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS,     \
            ##args)

#define aplog_port_warning_fileline(port_ptr, format, args...)              \
    aplog_port_warning(port_ptr, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS, \
            ##args)

#define aplog_port_notice_fileline(port_ptr, format, args...)               \
    aplog_port_notice(port_ptr, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS,  \
            ##args)

#define aplog_port_info_fileline(port_ptr, format, args...)                 \
    aplog_port_info(port_ptr, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS,    \
            ##args)

#define aplog_port_debug_fileline(port_ptr, format, args...)                \
    aplog_port_debug(port_ptr, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS,   \
            ##args)

/*** Default port */
#define aplog_emerg_fileline(format, args...)                               \
    aplog_port_emerg(NULL, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS, ##args)

#define aplog_alert_fileline(format, args...)                               \
    aplog_port_alert(NULL, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS, ##args)

#define aplog_crit_fileline(format, args...)                                \
    aplog_port_crit(NULL, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS, ##args)

#define aplog_err_fileline(format, args...)                                 \
    aplog_port_err(NULL, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS, ##args)

#define aplog_warning_fileline(format, args...)                             \
    aplog_port_warning(NULL, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS, ##args)

#define aplog_notice_fileline(format, args...)                              \
    aplog_port_notice(NULL, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS, ##args)

#define aplog_info_fileline(format, args...)                                \
    aplog_port_info(NULL, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS, ##args)

#define aplog_debug_fileline(format, args...)                               \
    aplog_port_debug(NULL, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS, ##args)

/* ASCII logging; Func & line included */
#define _FUNC_LINE_PREFIX     "(%s:%d)"
#define _FUNC_LINE_ARGS       __FUNCTION__,__LINE__

#define aplog_port_funcline(port_ptr, level, format, args...)           \
    aplog_port(port_ptr, level, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS, \
            ##args)
#define aplog_funcline(level, format, args...)                          \
    aplog_port_funcline(NULL, level, format, ##args)

/*** Port specified */
#define aplog_port_emerg_funcline(port_ptr, format, args...)                \
    aplog_port_emerg(port_ptr, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS,   \
            ##args)

#define aplog_port_alert_funcline(port_ptr, format, args...)                \
    aplog_port_alert(port_ptr, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS,   \
            ##args)

#define aplog_port_crit_funcline(port_ptr, format, args...)                 \
    aplog_port_crit(port_ptr, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS,    \
            ##args)

#define aplog_port_err_funcline(port_ptr, format, args...)                  \
    aplog_port_err(port_ptr, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS,     \
            ##args)

#define aplog_port_warning_funcline(port_ptr, format, args...)              \
    aplog_port_warning(port_ptr, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS, \
            ##args)

#define aplog_port_notice_funcline(port_ptr, format, args...)               \
    aplog_port_notice(port_ptr, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS,  \
            ##args)

#define aplog_port_info_funcline(port_ptr, format, args...)                 \
    aplog_port_info(port_ptr, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS,    \
            ##args)

#define aplog_port_debug_funcline(port_ptr, format, args...)                \
    aplog_port_debug(port_ptr, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS,   \
            ##args)

/*** Default port */
#define aplog_emerg_funcline(format, args...)                               \
    aplog_port_emerg(NULL, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS, ##args)

#define aplog_alert_funcline(format, args...)                               \
    aplog_port_alert(NULL, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS, ##args)

#define aplog_crit_funcline(format, args...)                                \
    aplog_port_crit(NULL, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS, ##args)

#define aplog_err_funcline(format, args...)                                 \
    aplog_port_err(NULL, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS, ##args)

#define aplog_warning_funcline(format, args...)                             \
    aplog_port_warning(NULL, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS, ##args)

#define aplog_notice_funcline(format, args...)                              \
    aplog_port_notice(NULL, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS, ##args)

#define aplog_info_funcline(format, args...)                                \
    aplog_port_info(NULL, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS, ##args)

#define aplog_debug_funcline(format, args...)                               \
    aplog_port_debug(NULL, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS, ##args)

/* ASCII logging; EzX File/Line/Func included */
#define _ZLOG_PREFIX     "%s:%d,%s  "
#define _ZLOG_ARGS       __FILE__,__LINE__,__FUNCTION__
#define _ZLOG_SUFFIX     "\n"

#define aplog_port_zlog(port_ptr, level, format, args...)               \
    aplog_port(port_ptr, level, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)
#define aplog_zlog(level, format, args...)                              \
    aplog_port_zlog(NULL, level, format, ##args)

/*** Port specified */
#define aplog_port_emerg_zlog(port_ptr, format, args...)                \
    aplog_port_emerg(port_ptr, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_port_alert_zlog(port_ptr, format, args...)                \
    aplog_port_alert(port_ptr, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_port_crit_zlog(port_ptr, format, args...)                 \
    aplog_port_crit(port_ptr, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_port_err_zlog(port_ptr, format, args...)                  \
    aplog_port_err(port_ptr, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_port_warning_zlog(port_ptr, format, args...)              \
    aplog_port_warning(port_ptr, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_port_notice_zlog(port_ptr, format, args...)               \
    aplog_port_notice(port_ptr, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_port_info_zlog(port_ptr, format, args...)                 \
    aplog_port_info(port_ptr, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_port_debug_zlog(port_ptr, format, args...)                \
    aplog_port_debug(port_ptr, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

/*** Default port */
#define aplog_emerg_zlog(format, args...)                               \
    aplog_port_emerg(NULL, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_alert_zlog(format, args...)                               \
    aplog_port_alert(NULL, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_crit_zlog(format, args...)                                \
    aplog_port_crit(NULL, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_err_zlog(format, args...)                                 \
    aplog_port_err(NULL, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_warning_zlog(format, args...)                             \
    aplog_port_warning(NULL, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_notice_zlog(format, args...)                              \
    aplog_port_notice(NULL, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_info_zlog(format, args...)                                \
    aplog_port_info(NULL, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_debug_zlog(format, args...)                               \
    aplog_port_debug(NULL, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

/* Binary logging macros; Port specified */
#if (APLOG_EMERG <= _LIBAPLOG_COMPILE_LEVEL)
#define aplog_port_bin_emerg(port_ptr, msg_id, data, size)              \
    aplog_port_bin(port_ptr, APLOG_EMERG, msg_id, data, size)
#else
#define aplog_port_bin_emerg(port_ptr, msg_id, data, size)
#endif

#if (APLOG_ALERT <= _LIBAPLOG_COMPILE_LEVEL)
#define aplog_port_bin_alert(port_ptr, msg_id, data, size)              \
    aplog_port_bin(port_ptr, APLOG_ALERT, msg_id, data, size)
#else
#define aplog_port_bin_alert(port_ptr, msg_id, data, size)
#endif

#if (APLOG_CRIT <= _LIBAPLOG_COMPILE_LEVEL)
#define aplog_port_bin_crit(port_ptr, msg_id, data, size)               \
    aplog_port_bin(port_ptr, APLOG_CRIT, msg_id, data, size)
#else
#define aplog_port_bin_crit(port_ptr, msg_id, data, size)
#endif

#if (APLOG_ERR <= _LIBAPLOG_COMPILE_LEVEL)
#define aplog_port_bin_err(port_ptr, msg_id, data, size)                \
    aplog_port_bin(port_ptr, APLOG_ERR, msg_id, data, size)
#else
#define aplog_port_bin_err(port_ptr, msg_id, data, size)
#endif

#if (APLOG_WARNING <= _LIBAPLOG_COMPILE_LEVEL)
#define aplog_port_bin_warning(port_ptr, msg_id, data, size)            \
    aplog_port_bin(port_ptr, APLOG_WARNING, msg_id, data, size)
#else
#define aplog_port_bin_warning(port_ptr, msg_id, data, size)
#endif

#if (APLOG_NOTICE <= _LIBAPLOG_COMPILE_LEVEL)
#define aplog_port_bin_notice(port_ptr, msg_id, data, size)             \
    aplog_port_bin(port_ptr, APLOG_NOTICE, msg_id, data, size)
#else
#define aplog_port_bin_notice(port_ptr, msg_id, data, size)
#endif

#if (APLOG_INFO <= _LIBAPLOG_COMPILE_LEVEL)
#define aplog_port_bin_info(port_ptr, msg_id, data, size)               \
    aplog_port_bin(port_ptr, APLOG_INFO, msg_id, data, size)
#else
#define aplog_port_bin_info(port_ptr, msg_id, data, size)
#endif

#if (APLOG_DEBUG <= _LIBAPLOG_COMPILE_LEVEL)
#define aplog_port_bin_debug(port_ptr, msg_id, data, size)              \
    aplog_port_bin(port_ptr, APLOG_DEBUG, msg_id, data, size)
#else
#define aplog_port_bin_debug(port_ptr, msg_id, data, size)
#endif

/* Binary logging macros, Default port */
#define aplog_bin_emerg(msg_id, data, size)                             \
    aplog_port_bin_emerg(NULL, msg_id, data, size)
#define aplog_bin_alert(msg_id, data, size)                             \
    aplog_port_bin_alert(NULL, msg_id, data, size)
#define aplog_bin_crit(msg_id, data, size)                              \
    aplog_port_bin_crit(NULL, msg_id, data, size)
#define aplog_bin_err(msg_id, data, size)                               \
    aplog_port_bin_err(NULL, msg_id, data, size)
#define aplog_bin_warning(msg_id, data, size)                           \
    aplog_port_bin_warning(NULL, msg_id, data, size)
#define aplog_bin_notice(msg_id, data, size)                            \
    aplog_port_bin_notice(NULL, msg_id, data, size)
#define aplog_bin_info(msg_id, data, size)                              \
    aplog_port_bin_info(NULL, msg_id, data, size)
#define aplog_bin_debug(msg_id, data, size)                             \
    aplog_port_bin_debug(NULL, msg_id, data, size)

/* Port Macros */
#define aplog_open_port(port_name, options)                             \
    _aplog_port_open(port_name, options)
#define aplog_close_port(port_ptr)                                      \
    _aplog_port_close(port_ptr)
#define aplog_get_primary_port()              _aplog_get_primary_port()
#define aplog_set_primary_port(port_ptr)      _aplog_set_primary_port(port_ptr)
#define aplog_get_log_level(port_ptr)         _aplog_get_port_log_level(port_ptr)
#define aplog_set_log_level(port_ptr, log_level) _aplog_set_port_log_level(port_ptr, log_level)

/* EzX Legacy Macros */
/* Assert Macros */
#define aplog_port_assert(port_ptr, cond)                               \
{                                                                       \
    if (!(cond))                                                        \
    {                                                                   \
        aplog_port_alert_fileline(port_ptr, "Assert failed!\n"); \
        assert(cond);                                                   \
    }                                                                   \
}                                                                       \

#define aplog_assert(cond)  aplog_port_assert(NULL, cond)

/* Enter / Exit Functions */
#define aplog_port_func_enter(port_ptr)                                 \
    aplog_port_debug(port_ptr, "Entering function %s\n", __FUNCTION__);

#define aplog_func_enter()                                              \
    aplog_port_func_enter(NULL)

#define aplog_port_func_exit(port_ptr)                                  \
    aplog_port_debug(port_ptr, "Exiting function %s\n", __FUNCTION__);

#define aplog_func_exit()                                               \
    aplog_port_func_exit(NULL)

#define aplog_port_func_enter_print(port_ptr, format, args...)          \
    aplog_port_debug(port_ptr, "Entering function %s\n" format,         \
            __FUNCTION__, ##args);

#define aplog_func_enter_print(format, args...)                         \
    aplog_port_func_enter_print(NULL, format, ##args)

#define aplog_port_func_exit_print(port_ptr, format, args...)           \
    aplog_port_debug(port_ptr, "Exiting function %s\n" format,          \
            __FUNCTION__, ##args);

#define aplog_func_exit_print(format, args...)                          \
    aplog_port_func_exit_print(NULL, format, ##args)

/* Enter / Exit Functions with EzX-Style Logging Info */
#define aplog_port_func_enter_zlog(port_ptr)                            \
    aplog_port_debug_zlog(port_ptr, "Entering function");

#define aplog_func_enter_zlog()                                         \
    aplog_port_func_enter_zlog(NULL)

#define aplog_port_func_exit_zlog(port_ptr)                             \
    aplog_port_debug_zlog(port_ptr, "Exiting function");

#define aplog_func_exit_zlog()                                          \
    aplog_port_func_exit_zlog(NULL)

#define aplog_port_func_enter_print_zlog(port_ptr, format, args...)     \
    aplog_port_debug_zlog(port_ptr, "Entering function: " format,       \
            ##args);

#define aplog_func_enter_print_zlog(format, args...)                    \
    aplog_port_func_enter_print_zlog(NULL, format, ##args)

#define aplog_port_func_exit_print_zlog(port_ptr, format, args...)      \
    aplog_port_debug_zlog(port_ptr, "Exiting function: " format,        \
            ##args);

#define aplog_func_exit_print_zlog(format, args...)                     \
    aplog_port_func_exit_print_zlog(NULL, format, ##args)

/****************************************
 *  Dynamically linked library functions
 ****************************************/
#ifdef  __cplusplus
extern "C"
{
#endif /* __cplusplus */

int _aplog_init(const char *, unsigned int);
int _aplog_exit(unsigned int);
struct aplog_port_struct * _aplog_port_open(const char *, unsigned int);
int _aplog_port_close(struct aplog_port_struct *);
void _aplog_port_log_ascii(struct aplog_port_struct *, int, const char *, ...);
void _aplog_port_vlog_ascii(struct aplog_port_struct*, int, const char*, va_list);
void _aplog_port_log_bin(struct aplog_port_struct *, int, unsigned int, void *, size_t);
struct aplog_port_struct* _aplog_get_primary_port(void);
int _aplog_set_primary_port(struct aplog_port_struct*);
int _aplog_get_port_log_level(struct aplog_port_struct*);
int _aplog_set_port_log_level(struct aplog_port_struct*, int);


#ifdef  __cplusplus
}
#endif /* __cplusplus */

#else /* FEAT_LIBAPLOG_DYNAMIC */

/*
 *****************************************************************************
 * What follows is the "original" libaplog code, which is here only for
 * compatibility for components supporting the new methods.
 ******************************************************************************
 */

/*****************************
 * Log Level Defines
 *****************************/
#define APLOG_EMERG     1
#define APLOG_ALERT     2
#define APLOG_CRIT      3
#define APLOG_ERR       4
#define APLOG_WARNING   5
#define APLOG_NOTICE    6
#define APLOG_INFO      7
#define APLOG_DEBUG     8

/* Extra Level Defines */
#define APLOG_INVALID       -1
#define APLOG_OFF           0
#define APLOG_DEBUG_MODE    99

/*****************************
 * Compile time configuration
 *****************************/
#if (!defined(FEAT_LIBAPLOG_LEVEL))
#define FEAT_LIBAPLOG_LEVEL APLOG_INVALID
#warning Invalid log level defined
#endif /* Not defined FEAT_LIBAPLOG_LEVEL */

#if (FEAT_LIBAPLOG_LEVEL == APLOG_EMERG)    /* EMERG and up */
#define _LIBAPLOG_COMPILE_LEVEL APLOG_EMERG
#elif (FEAT_LIBAPLOG_LEVEL == APLOG_ALERT)  /* ALERT and up */  
#define _LIBAPLOG_COMPILE_LEVEL APLOG_ALERT
#elif (FEAT_LIBAPLOG_LEVEL == APLOG_CRIT)   /* CRIT and up */
#define _LIBAPLOG_COMPILE_LEVEL APLOG_CRIT
#elif (FEAT_LIBAPLOG_LEVEL == APLOG_ERR)    /* ERR and up */
#define _LIBAPLOG_COMPILE_LEVEL APLOG_ERR
#elif (FEAT_LIBAPLOG_LEVEL == APLOG_WARNING) /* WARNING and up */
#define _LIBAPLOG_COMPILE_LEVEL APLOG_WARNING
#elif (FEAT_LIBAPLOG_LEVEL == APLOG_NOTICE) /* NOTICE and up */
#define _LIBAPLOG_COMPILE_LEVEL APLOG_NOTICE
#elif (FEAT_LIBAPLOG_LEVEL == APLOG_INFO)   /* INFO and up */
#define _LIBAPLOG_COMPILE_LEVEL APLOG_INFO
#elif (FEAT_LIBAPLOG_LEVEL == APLOG_DEBUG)  /* DEBUG and up */
#define _LIBAPLOG_COMPILE_LEVEL APLOG_DEBUG    
#elif (FEAT_LIBAPLOG_LEVEL == APLOG_OFF)    /* No Logging */
#define _LIBAPLOG_COMPILE_LEVEL APLOG_OFF    
#elif (FEAT_LIBAPLOG_LEVEL == APLOG_DEBUG_MODE) /* Debugging mode */
#define _LIBAPLOG_COMPILE_LEVEL APLOG_DEBUG
#define LIBAPLOG_DEBUG
#else                                       /* Deafault: INFO and up */
#define _LIBAPLOG_COMPILE_LEVEL APLOG_INFO
#warning Using default libaplog level
#endif

/*****************************
 * Data types
 *****************************/
/* These are only here to allow 'pointers' of these types to be created.
 * They are NOT used yet. */
struct aplog_port_struct
{
    char not_implemented;
};

/* The aplog_general_struct struct should NOT be used by components */
struct aplog_general_struct
{
    char not_implemented;
};

/*****************************
 * External variables
 *****************************/
#if (_LIBAPLOG_COMPILE_LEVEL != APLOG_OFF)
extern FILE * libaplog_to_module_ptr;
#endif /* _LIBAPLOG_COMPILE_LEVEL != APLOG_OFF */

/*****************************
 * Compile-time Configurability Inline
 * Note: these inlines will be replaced by the shared library once it is
 * finished
 *****************************/
static inline void _aplog_configured_printf(int level, char * format, ...)
{
#if (_LIBAPLOG_COMPILE_LEVEL != APLOG_OFF)
    if (level <= _LIBAPLOG_COMPILE_LEVEL)
    {
        va_list libaplog_printf_args;
        va_start(libaplog_printf_args, format);
        if (libaplog_to_module_ptr != NULL)
        {
            vfprintf(libaplog_to_module_ptr, format, libaplog_printf_args);
        }
        else
            vprintf(format, libaplog_printf_args);
        va_end(libaplog_printf_args);
    }
#endif /* _LIBAPLOG_COMPILE_LEVEL != APLOG_OFF */
    return;
}

static inline void _aplog_configured_binlog(int level, void * data,
        size_t size)
{
#if (_LIBAPLOG_COMPILE_LEVEL != APLOG_OFF)
    if (level <= _LIBAPLOG_COMPILE_LEVEL && libaplog_to_module_ptr != NULL)
    {
        size_t libaplog_bytes_written = 0;
        int libaplog_ret_val = 0;
        while (libaplog_bytes_written < size)
        {
            libaplog_ret_val = fwrite(
                    (void *)((char *)data + libaplog_bytes_written),
                    1, size - libaplog_bytes_written,
                    libaplog_to_module_ptr);
            if (libaplog_ret_val < 0)
            {
                if (errno == -EINTR)
                    continue;
                else
                    return;
            }
            libaplog_bytes_written += libaplog_ret_val;
        }
    }
#endif /* _LIBAPLOG_COMPILE_LEVEL != APLOG_OFF */
    return;
}


/*****************************
 * Internal Macro Defines
 *****************************/
#if defined(LIBAPLOG_DEBUG)                 /* Debug; Logging Enabled*/
#define _aplog_ascii(port_ptr, level, format, args...)                  \
    printf("port_ptr: 0x%08X; level: %d\n", (unsigned int) port_ptr,    \
            level);                                                     \
    _aplog_configured_printf(level, format, ##args)
#elif (_LIBAPLOG_COMPILE_LEVEL == APLOG_OFF)    /* Logging Disabled */
#define _aplog_ascii(port_ptr, level, format, args...)
#else                                           /* Logging Enabled */
#define _aplog_ascii(port_ptr, level, format, args...)                  \
    _aplog_configured_printf(level, format, ##args)
#endif

#if defined(LIBAPLOG_DEBUG)                 /* Debug */
#define _aplog_binary(port_ptr, level, msg_id, data, size)             \
    printf("Binary! port_ptr: 0x%08X; level: %d; msg_id: 0x%08X; Data: 0x%08X; Size = %d\n",  \
            port_ptr, level, msg_id, data, size);                      \
    _aplog_configured_binlog(level, data, size)
#elif (_LIBAPLOG_COMPILE_LEVEL == APLOG_OFF)    /* Logging Disabled */
#define _aplog_binary(port_ptr, level, msg_id, data, size)
#else                                           /* Logging Enabled */
#define _aplog_binary(port_ptr, level, msg_id, data, size)              \
    _aplog_configured_binlog(level, data, size)
#endif

/*****************************
 * API Macro Defines
 *****************************/

/* Setup / Shutdown */
#define aplog_startup _aplog_init_orig
#define aplog_shutdown _aplog_exit_orig

/* 'Syslog' Macros; ASCII and Binary */
#define aplog(level, format, args...)                                   \
    aplog_port(NULL, level, format, ##args)

#define aplog_port _aplog_ascii

#define aplog_bin(level, msg_id, ptr, size)                             \
    aplog_port_bin(NULL, level, msg_id, ptr, size)

#define aplog_port_bin _aplog_binary

/* ASCII logging; Specified port */
#define aplog_port_emerg(port_ptr, format, args...)                     \
    aplog_port(port_ptr, APLOG_EMERG, format, ##args)

#define aplog_port_alert(port_ptr, format, args...)                     \
    aplog_port(port_ptr, APLOG_ALERT, format, ##args)

#define aplog_port_crit(port_ptr, format, args...)                      \
    aplog_port(port_ptr, APLOG_CRIT, format, ##args)

#define aplog_port_err(port_ptr, format, args...)                       \
    aplog_port(port_ptr, APLOG_ERR, format, ##args)

#define aplog_port_warning(port_ptr, format, args...)                   \
    aplog_port(port_ptr, APLOG_WARNING, format, ##args)

#define aplog_port_notice(port_ptr, format, args...)                    \
    aplog_port(port_ptr, APLOG_NOTICE, format, ##args)

#define aplog_port_info(port_ptr, format, args...)                      \
    aplog_port(port_ptr, APLOG_INFO, format, ##args)

#define aplog_port_debug(port_ptr, format, args...)                     \
    aplog_port(port_ptr, APLOG_DEBUG, format, ##args)

/* ASCII logging; Default port */
#define aplog_emerg(format, args...)                                    \
    aplog_port_emerg(NULL, format, ##args)

#define aplog_alert(format, args...)                                    \
    aplog_port_alert(NULL, format, ##args)

#define aplog_crit(format, args...)                                     \
    aplog_port_crit(NULL, format, ##args)

#define aplog_err(format, args...)                                      \
    aplog_port_err(NULL, format, ##args)

#define aplog_warning(format, args...)                                  \
    aplog_port_warning(NULL, format, ##args)

#define aplog_notice(format, args...)                                   \
    aplog_port_notice(NULL, format, ##args)

#define aplog_info(format, args...)                                     \
    aplog_port_info(NULL, format, ##args)

#define aplog_debug(format, args...)                                    \
    aplog_port_debug(NULL, format, ##args)

/* ASCII logging; File & line included */
#define _FILE_LINE_PREFIX     "(%s:%d)"
#define _FILE_LINE_ARGS       __FILE__,__LINE__

#define aplog_port_fileline(port_ptr, level, format, args...)               \
    aplog_port(port_ptr, level, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS,  \
            ##args)
#define aplog_fileline(level, format, args...)                    \
    aplog_port_fileline(NULL, level, format, ##args)

/*** Port specified */
#define aplog_port_emerg_fileline(port_ptr, format, args...)                \
    aplog_port_emerg(port_ptr, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS,   \
            ##args)

#define aplog_port_alert_fileline(port_ptr, format, args...)                \
    aplog_port_alert(port_ptr, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS,   \
            ##args)

#define aplog_port_crit_fileline(port_ptr, format, args...)                 \
    aplog_port_crit(port_ptr, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS,    \
            ##args)

#define aplog_port_err_fileline(port_ptr, format, args...)                  \
    aplog_port_err(port_ptr, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS,     \
            ##args)

#define aplog_port_warning_fileline(port_ptr, format, args...)              \
    aplog_port_warning(port_ptr, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS, \
            ##args)

#define aplog_port_notice_fileline(port_ptr, format, args...)               \
    aplog_port_notice(port_ptr, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS,  \
            ##args)

#define aplog_port_info_fileline(port_ptr, format, args...)                 \
    aplog_port_info(port_ptr, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS,    \
            ##args)

#define aplog_port_debug_fileline(port_ptr, format, args...)                \
    aplog_port_debug(port_ptr, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS,   \
            ##args)

/*** Default port */
#define aplog_emerg_fileline(format, args...)                               \
    aplog_port_emerg(NULL, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS, ##args)

#define aplog_alert_fileline(format, args...)                               \
    aplog_port_alert(NULL, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS, ##args)

#define aplog_crit_fileline(format, args...)                                \
    aplog_port_crit(NULL, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS, ##args)

#define aplog_err_fileline(format, args...)                                 \
    aplog_port_err(NULL, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS, ##args)

#define aplog_warning_fileline(format, args...)                             \
    aplog_port_warning(NULL, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS, ##args)

#define aplog_notice_fileline(format, args...)                              \
    aplog_port_notice(NULL, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS, ##args)

#define aplog_info_fileline(format, args...)                                \
    aplog_port_info(NULL, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS, ##args)

#define aplog_debug_fileline(format, args...)                               \
    aplog_port_debug(NULL, _FILE_LINE_PREFIX format, _FILE_LINE_ARGS, ##args)

/* ASCII logging; Func & line included */
#define _FUNC_LINE_PREFIX     "(%s:%d)"
#define _FUNC_LINE_ARGS       __FUNCTION__,__LINE__

#define aplog_port_funcline(port_ptr, level, format, args...)           \
    aplog_port(port_ptr, level, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS, \
            ##args)
#define aplog_funcline(level, format, args...)                          \
    aplog_port_funcline(NULL, level, format, ##args)

/*** Port specified */
#define aplog_port_emerg_funcline(port_ptr, format, args...)                \
    aplog_port_emerg(port_ptr, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS,   \
            ##args)

#define aplog_port_alert_funcline(port_ptr, format, args...)                \
    aplog_port_alert(port_ptr, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS,   \
            ##args)

#define aplog_port_crit_funcline(port_ptr, format, args...)                 \
    aplog_port_crit(port_ptr, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS,    \
            ##args)

#define aplog_port_err_funcline(port_ptr, format, args...)                  \
    aplog_port_err(port_ptr, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS,     \
            ##args)

#define aplog_port_warning_funcline(port_ptr, format, args...)              \
    aplog_port_warning(port_ptr, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS, \
            ##args)

#define aplog_port_notice_funcline(port_ptr, format, args...)               \
    aplog_port_notice(port_ptr, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS,  \
            ##args)

#define aplog_port_info_funcline(port_ptr, format, args...)                 \
    aplog_port_info(port_ptr, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS,    \
            ##args)

#define aplog_port_debug_funcline(port_ptr, format, args...)                \
    aplog_port_debug(port_ptr, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS,   \
            ##args)

/*** Default port */
#define aplog_emerg_funcline(format, args...)                               \
    aplog_port_emerg(NULL, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS, ##args)

#define aplog_alert_funcline(format, args...)                               \
    aplog_port_alert(NULL, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS, ##args)

#define aplog_crit_funcline(format, args...)                                \
    aplog_port_crit(NULL, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS, ##args)

#define aplog_err_funcline(format, args...)                                 \
    aplog_port_err(NULL, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS, ##args)

#define aplog_warning_funcline(format, args...)                             \
    aplog_port_warning(NULL, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS, ##args)

#define aplog_notice_funcline(format, args...)                              \
    aplog_port_notice(NULL, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS, ##args)

#define aplog_info_funcline(format, args...)                                \
    aplog_port_info(NULL, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS, ##args)

#define aplog_debug_funcline(format, args...)                               \
    aplog_port_debug(NULL, _FUNC_LINE_PREFIX format, _FUNC_LINE_ARGS, ##args)

/* ASCII logging; EzX File/Line/Func included */
#define _ZLOG_PREFIX     "%s:%d,%s  "
#define _ZLOG_ARGS       __FILE__,__LINE__,__FUNCTION__
#define _ZLOG_SUFFIX     "\n"

#define aplog_port_zlog(port_ptr, level, format, args...)               \
    aplog_port(port_ptr, level, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)
#define aplog_zlog(level, format, args...)                              \
    aplog_port_zlog(NULL, level, format, ##args)

/*** Port specified */
#define aplog_port_emerg_zlog(port_ptr, format, args...)                \
    aplog_port_emerg(port_ptr, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_port_alert_zlog(port_ptr, format, args...)                \
    aplog_port_alert(port_ptr, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_port_crit_zlog(port_ptr, format, args...)                 \
    aplog_port_crit(port_ptr, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_port_err_zlog(port_ptr, format, args...)                  \
    aplog_port_err(port_ptr, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_port_warning_zlog(port_ptr, format, args...)              \
    aplog_port_warning(port_ptr, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_port_notice_zlog(port_ptr, format, args...)               \
    aplog_port_notice(port_ptr, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_port_info_zlog(port_ptr, format, args...)                 \
    aplog_port_info(port_ptr, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_port_debug_zlog(port_ptr, format, args...)                \
    aplog_port_debug(port_ptr, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

/*** Default port */
#define aplog_emerg_zlog(format, args...)                               \
    aplog_port_emerg(NULL, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_alert_zlog(format, args...)                               \
    aplog_port_alert(NULL, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_crit_zlog(format, args...)                                \
    aplog_port_crit(NULL, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_err_zlog(format, args...)                                 \
    aplog_port_err(NULL, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_warning_zlog(format, args...)                             \
    aplog_port_warning(NULL, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_notice_zlog(format, args...)                              \
    aplog_port_notice(NULL, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_info_zlog(format, args...)                                \
    aplog_port_info(NULL, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

#define aplog_debug_zlog(format, args...)                               \
    aplog_port_debug(NULL, _ZLOG_PREFIX format _ZLOG_SUFFIX, _ZLOG_ARGS, ##args)

/* Binary logging macros; Port specified */
#define aplog_port_bin_emerg(port_ptr, msg_id, data, size)              \
    aplog_port_bin(port_ptr, APLOG_EMERG, msg_id, data, size)
#define aplog_port_bin_alert(port_ptr, msg_id, data, size)              \
    aplog_port_bin(port_ptr, APLOG_ALERT, msg_id, data, size)
#define aplog_port_bin_crit(port_ptr, msg_id, data, size)               \
    aplog_port_bin(port_ptr, APLOG_CRIT, msg_id, data, size)
#define aplog_port_bin_err(port_ptr, msg_id, data, size)                \
    aplog_port_bin(port_ptr, APLOG_ERR, msg_id, data, size)
#define aplog_port_bin_warning(port_ptr, msg_id, data, size)            \
    aplog_port_bin(port_ptr, APLOG_WARNING, msg_id, data, size)
#define aplog_port_bin_notice(port_ptr, msg_id, data, size)             \
    aplog_port_bin(port_ptr, APLOG_NOTICE, msg_id, data, size)
#define aplog_port_bin_info(port_ptr, msg_id, data, size)               \
    aplog_port_bin(port_ptr, APLOG_INFO, msg_id, data, size)
#define aplog_port_bin_debug(port_ptr, msg_id, data, size)              \
    aplog_port_bin(port_ptr, APLOG_DEBUG, msg_id, data, size)

/* Binary logging macros, Default port */
#define aplog_bin_emerg(msg_id, data, size)                             \
    aplog_port_bin(NULL, APLOG_EMERG, msg_id, data, size)
#define aplog_bin_alert(msg_id, data, size)                             \
    aplog_port_bin(NULL, APLOG_ALERT, msg_id, data, size)
#define aplog_bin_crit(msg_id, data, size)                              \
    aplog_port_bin(NULL, APLOG_CRIT, msg_id, data, size)
#define aplog_bin_err(msg_id, data, size)                               \
    aplog_port_bin(NULL, APLOG_ERR, msg_id, data, size)
#define aplog_bin_warning(msg_id, data, size)                           \
    aplog_port_bin(NULL, APLOG_WARNING, msg_id, data, size)
#define aplog_bin_notice(msg_id, data, size)                            \
    aplog_port_bin(NULL, APLOG_NOTICE, msg_id, data, size)
#define aplog_bin_info(msg_id, data, size)                              \
    aplog_port_bin(NULL, APLOG_INFO, msg_id, data, size)
#define aplog_bin_debug(msg_id, data, size)                             \
    aplog_port_bin(NULL, APLOG_DEBUG, msg_id, data, size)

/* Port Macros */
#define aplog_open_port(port_name, options)                             \
    _aplog_port_open_orig(port_name, options)
#define aplog_close_port(port_ptr)                                      \
    _aplog_port_close_orig(port_ptr)
#define aplog_get_primary_port()                NULL
#define aplog_set_primary_port(port_ptr)        0
#define aplog_get_log_level(port_ptr)           _LIBAPLOG_COMPILE_LEVEL
#define aplog_set_log_level(port_ptr, log_level)

/* EzX Legacy Macros */
/* Assert Macros */
#define aplog_port_assert(port_ptr, cond)                               \
{                                                                       \
    if (!(cond))                                                        \
    {                                                                   \
        aplog_port_alert_fileline(port_ptr, "Assert failed!\n"); \
        assert(cond);                                                   \
    }                                                                   \
}                                                                       \

#define aplog_assert(cond)  aplog_port_assert(NULL, cond)

/* Enter / Exit Functions */
#define aplog_port_func_enter(port_ptr)                                 \
    aplog_port_debug(port_ptr, "Entering function %s\n", __FUNCTION__);

#define aplog_func_enter()                                              \
    aplog_port_func_enter(NULL)

#define aplog_port_func_exit(port_ptr)                                  \
    aplog_port_debug(port_ptr, "Exiting function %s\n", __FUNCTION__);

#define aplog_func_exit()                                               \
    aplog_port_func_exit(NULL)

#define aplog_port_func_enter_print(port_ptr, format, args...)          \
    aplog_port_debug(port_ptr, "Entering function %s\n" format,         \
            __FUNCTION__, ##args);

#define aplog_func_enter_print(format, args...)                         \
    aplog_port_func_enter_print(NULL, format, ##args)

#define aplog_port_func_exit_print(port_ptr, format, args...)           \
    aplog_port_debug(port_ptr, "Exiting function %s\n" format,          \
            __FUNCTION__, ##args);

#define aplog_func_exit_print(format, args...)                          \
    aplog_port_func_exit_print(NULL, format, ##args)

/* Enter / Exit Functions with EzX-Style Logging Info */
#define aplog_port_func_enter_zlog(port_ptr)                            \
    aplog_port_debug_zlog(port_ptr, "Entering function");

#define aplog_func_enter_zlog()                                         \
    aplog_port_func_enter_zlog(NULL)

#define aplog_port_func_exit_zlog(port_ptr)                             \
    aplog_port_debug_zlog(port_ptr, "Exiting function");

#define aplog_func_exit_zlog()                                          \
    aplog_port_func_exit_zlog(NULL)

#define aplog_port_func_enter_print_zlog(port_ptr, format, args...)     \
    aplog_port_debug_zlog(port_ptr, "Entering function: " format,       \
            ##args);

#define aplog_func_enter_print_zlog(format, args...)                    \
    aplog_port_func_enter_print_zlog(NULL, format, ##args)

#define aplog_port_func_exit_print_zlog(port_ptr, format, args...)      \
    aplog_port_debug_zlog(port_ptr, "Exiting function: " format,        \
            ##args);

#define aplog_func_exit_print_zlog(format, args...)                     \
    aplog_port_func_exit_print_zlog(NULL, format, ##args)

/*****************************
 * File paths
 *****************************/
#define LIBAPLOG_TO_MODULE_PATH "/dev/aplog_input"

/*****************************
 * Staticly compiled library functions
 *****************************/
#ifdef  __cplusplus
extern "C"
{
#endif /* __cplusplus */

int _aplog_init_orig(const char *, unsigned int);
int _aplog_exit_orig(unsigned int);
struct aplog_port_struct * _aplog_port_open_orig(const char *, unsigned int);
int _aplog_port_close_orig(struct aplog_port_struct *);

#ifdef  __cplusplus
}
#endif /* __cplusplus */


#endif /* FEAT_LIBAPLOG_DYNAMIC */

#endif /* ifndef _LIBAPLOG_H_ */
