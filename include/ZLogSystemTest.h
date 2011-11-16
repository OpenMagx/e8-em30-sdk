

// Copyright (c)  - 2008 Motorola, Inc. All rights reserved.


#ifndef _ZLOGSYSTEMTEST_H
#define _ZLOGSYSTEMTEST_H

#ifndef _ZLOG_H
#warning include ZLogSystem.h directly, please include ZLog.h instead!!!
#undef _ZLOGSYSTEMTEST_H
#include "ZLog.h"
#else

#ifndef UNUSED_PARAM
#define UNUSED_PARAM(v) (void)(v)
#endif

#include "ZLogLevel.h"

#define EZXLOG_LEVEL_DEFAULT      EZXLOG_LEVEL_CRIT

#ifndef EZXLOGLEVEL
#define EZXLOGLEVEL EZXLOG_LEVEL_DEFAULT
#endif

#define _EZXLOG_TMP1(name) (name##1)                
#define _EZXLOG_TMP(name)  _EZXLOG_TMP1(name)
#if (_EZXLOG_TMP(EZXLOGLEVEL) > _EZXLOG_TMP(EZXLOG_LEVEL_DEBUG)) || (_EZXLOG_TMP(EZXLOGLEVEL) < _EZXLOG_TMP(EZXLOG_LEVEL_EMERG)) 
#error wrong EZXLOGLEVEL define!!!
#undef  EZXLOGLEVEL
#define EZXLOGLEVEL EZXLOG_LEVEL_DEFAULT
#endif

#if (EZXLOGLEVEL ==  EZXLOG_LEVEL_EMERG)
#if (EZXLOGLEVEL ==  EZXLOG_LEVEL_CRIT)
#error null EZXLOGLEVEL define!!!
#undef  EZXLOGLEVEL
#define EZXLOGLEVEL EZXLOG_LEVEL_DEFAULT
#endif
#endif

static inline char * _zLogGetFile(const char * file)
{
    char * _zLog_file = (char *)file;                       
    char * _zLog_current = _zLog_file;                 
    UNUSED_PARAM(_zLogGetFile);

    while(*_zLog_current != '\0')
    {                       
        if(*_zLog_current == '/')                    
            _zLog_file = _zLog_current + 1;            
        _zLog_current++ ;                          
    }
    return _zLog_file;    
}	

#define _zLog_print_with_function(level, fmt, arg...)                 \
    do{                                      \
        fprintf(stderr, "{%d} %s:%d, %s()\t"fmt"\n", level, (char *)_zLogGetFile(__FILE__), __LINE__, __FUNCTION__, ##arg);   \
    }while(0)

#define _zLog_print(level, fmt, arg...)                 \
    do{                                                 \
        fprintf(stderr, "{%d} %s:%d\t"fmt"\n", level, _zLogGetFile(__FILE__), __LINE__, ##arg);   \
    }while(0)

#define _zLog_print_short(level, fmt, arg...)          \
    do{                                                 \
        fprintf(stderr, "{%d} "fmt"\n", level, ##arg);   \
    }while(0)

#define zLog(level, fmt, arg...)             \
    do{                                      \
        if (((level) <= EZXLOGLEVEL) && ((level) != EZXLOG_LEVEL_DEBUG) && ((level) != EZXLOG_LEVEL_EMERG))  \
        {                                                       \
                _zLog_print(level, fmt, ##arg);                 \
        }                                                       \
        if (((level) <= EZXLOGLEVEL) && ((level) == EZXLOG_LEVEL_DEBUG) && ((level) != EZXLOG_LEVEL_EMERG))  \
        {                                                        \
                _zLog_print_with_function(level, fmt, ##arg);     \
        }		\
    }while(0)      

#define EZXLOG_EMERGENCY_STORAGE "/proc/emg"
static inline void _zLog_record(unsigned long errorInfo)
{
    int fd;
    fd = open(EZXLOG_EMERGENCY_STORAGE, O_RDWR);
    if (fd < 0)
         return;
    write(fd, &errorInfo, sizeof(errorInfo));
    close(fd);
}

#define EZXLOG_EMERG_MAKE_INFO(componentId, subComponentId, errorCode) \
        (((componentId) << 24) & 0xff000000) | (((subComponentId) << 16)& 0xff0000) | ((errorCode)& 0xffff)

#if (EZXLOG_LEVEL_EMERG == EZXLOGLEVEL)
static inline void zEmergency(unsigned char componentId, unsigned char subComponentId, unsigned short errorCode, char *errorDescription)
{
     UNUSED_PARAM(errorDescription);
     _zLog_record(EZXLOG_EMERG_MAKE_INFO(componentId, subComponentId, errorCode)); 
}     
#elif(EZXLOG_LEVEL_EMERG < EZXLOGLEVEL)
static inline void zEmergency(unsigned char componentId, unsigned char subComponentId, unsigned short errorCode, char *errorDescription)
{
     _zLog_print_short(EZXLOG_LEVEL_EMERG, "%d %d %d %s", componentId, subComponentId, errorCode, errorDescription);
     _zLog_record(EZXLOG_EMERG_MAKE_INFO(componentId, subComponentId, errorCode));  
}
#else
    #define zEmergency(componentId, subComponentId, errorCode, errorDescription) do{}while(0)
#endif 

#if (EZXLOG_LEVEL_CRIT <= EZXLOGLEVEL)
    #define zCritical(fmt, arg...)    _zLog_print(EZXLOG_LEVEL_CRIT, fmt, ##arg)
#else
    #define zCritical(fmt, arg...) do{}while(0)
#endif

#if (EZXLOG_LEVEL_ERR <= EZXLOGLEVEL)
    #define zError(fmt, arg...)     _zLog_print(EZXLOG_LEVEL_ERR, fmt, ##arg)
#else
    #define zError(fmt, arg...)  do{}while(0)
#endif

#if (EZXLOG_LEVEL_WARNING <= EZXLOGLEVEL)
    #define zWarning(fmt, arg...) _zLog_print(EZXLOG_LEVEL_WARNING, fmt, ##arg) 
#else
    #define zWarning(fmt, arg...)  do{}while(0)
#endif

#if (EZXLOG_LEVEL_INFO <= EZXLOGLEVEL)
    #define zInfo(fmt,arg...)    _zLog_print(EZXLOG_LEVEL_INFO, fmt, ##arg) 
#else
    #define zInfo(fmt,arg...)   do{}while(0)
#endif

#if (EZXLOG_LEVEL_DEBUG <= EZXLOGLEVEL)
    #define zDbg(fmt, arg...)   _zLog_print_with_function(EZXLOG_LEVEL_DEBUG, fmt, ##arg)
#else
    #define zDbg(fmt, arg...)  do{}while(0)
#endif 

#if (EZXLOG_LEVEL_ERR <= EZXLOGLEVEL)
#define zAssert(x)                              \
        do{                                     \
            if(!(x))                            \
            {                                   \
                zError("ezx assert failed !\n");\
                abort();                       \
            }                                   \
        }while(0)
#else
#define zAssert(x)
#endif      

#define zEnter(fmt, arg...) zDbg("ENTER\t"fmt, ##arg)
#define zLeave(fmt, arg...) zDbg("LEAVE\t"fmt, ##arg)

static inline void _zLogFputchex(unsigned char n, FILE * file)
{
    unsigned char tmp;

    tmp = n/16;
    (tmp < 10)?fputc(tmp+'0', file):fputc(tmp-10+'a', file);
    tmp = n%16;
    (tmp < 10)?fputc(tmp+'0', file):fputc(tmp-10+'a', file);

    return ;	
}	

static inline void _zLogBinary(int level, int level_limit,unsigned char * buf, int cnt, char * file, int line, char * function)
{
    if ((level < EZXLOG_LEVEL_EMERG) && (EZXLOG_LEVEL_DEBUG < level))
	return;

    if ( level > level_limit )
        return ;

    if ( cnt <= 0 )
	return;

    fprintf(stdout, "{%d} %s:%d, %s()\t", level, file, line, function);

    do{
        _zLogFputchex(*buf, stdout);
        fputc(' ', stdout);
        cnt --;
        buf ++;
    }while(cnt > 0);
    fputc('\n', stdout);
    fflush(stdout);

    return;
}       

#define zLogBinary(level, buf, cnt)            \
        do{                                     \
            _zLogBinary(level, EZXLOGLEVEL, buf, cnt, (unsigned char *)_zLogGetFile(__FILE__), __LINE__, __FUNCTION__);    \
        }while(0)

#if (EZXLOG_LEVEL_DEBUG <= EZXLOGLEVEL)
    #define zSDbg(fmt, arg...)   _zLog_print_short(EZXLOG_LEVEL_DEBUG, fmt, ##arg)
#else
    #define zSDbg(fmt, arg...) do{}while(0)
#endif      

#endif
#endif
