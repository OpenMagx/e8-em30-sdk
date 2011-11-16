

// Copyright (c) 26-Oct-06 - 2008 Motorola, Inc. All rights reserved.



#ifndef __LM_APP_INTERFACE_H__
#define __LM_APP_INTERFACE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#define LM_SOCKET_NAME             "/tmp/lmsock"

#define LM_SOCKET_TIMEOUT   5

#define LM_APP_SUCCESS              0
#define LM_APP_CONNECT_ERR         -1
#define LM_APP_SOCK_ERR            -2
#define LM_APP_INVALID_PARAMETER   -3
#define LM_APP_RECEIVE_ERR         -4
#define LM_APP_MALLOC_ERR          -5
#define LM_APP_INVALID_LEN_ERR     -6

#define LM_LIB_SOCK_ERR            LM_APP_SOCK_ERR

#define LMD_KEYMODE_NORMAL         0
#define LMD_KEYMODE_LOCK           1

#define LMD_DISPMODE_NORMAL        0
#define LMD_DISPMODE_LOCK          1
#define LMD_DISPMODE_DIMMED        2
#define NUM_DISPLAY_MODE           3

#define LMD_SCREENSAVER_OFF        0
#define LMD_SCREENSAVER_ON         1

#define LMD_NONEMERGENCY           0
#define LMD_EMERGENCY              1

#define LMD_LIGHT_SENSOR_MIN       0
#define LMD_LIGHT_SENSOR_MAX       1

#define LM_NO_TIMEOUT              0xFFFFFFFF

#define LM_REGION_TO_MASK(region)  (1 << (region))

#define LM_FL_REGION01_MSK         LM_REGION_TO_MASK(LM_FL_REGION_CAMERA_FLASH)
#define LM_FL_REGION02_MSK         LM_REGION_TO_MASK(LM_FL_REGION_DISPLAY_BL)
#define LM_FL_REGION03_MSK         LM_REGION_TO_MASK(LM_FL_REGION_CLI_DISPLAY_BL)
#define LM_FL_REGION04_MSK         LM_REGION_TO_MASK(LM_FL_REGION_LOGO)
#define LM_FL_REGION05_MSK         LM_REGION_TO_MASK(LM_FL_REGION_KEYPAD_NAV_BL)
#define LM_FL_REGION06_MSK         LM_REGION_TO_MASK(LM_FL_REGION_KEYPAD_NUM_BL)
#define LM_FL_REGION07_MSK         LM_REGION_TO_MASK(LM_FL_REGION_BT_LED)
#define LM_FL_REGION08_MSK         LM_REGION_TO_MASK(LM_FL_REGION_SOL_LED)
#define LM_FL_REGION09_MSK         LM_REGION_TO_MASK(LM_FL_REGION_PRIVACY_IND)
#define LM_FL_REGIONALL_MSK        0xffffffff

#define LM_FL_COLOR_BLACK       0x000000
#define LM_FL_COLOR_BLUE        0x0000ff
#define LM_FL_COLOR_GREEN       0x00ff00
#define LM_FL_COLOR_RED         0xff0000
#define LM_FL_COLOR_WHITE       0xffffff

#define LM_FL_COLOR_BLUE_SFT    0
#define LM_FL_COLOR_GREEN_SFT   8
#define LM_FL_COLOR_RED_SFT     16

#define LM_FL_CAMERA_TORCH      0x444444
#define LM_FL_CAMERA_REDEYE     0x888888
#define LM_FL_CAMERA_FLASH      0xffffff

typedef enum
{
    LM_FL_REGION_RESERVED1,                                    
    LM_FL_REGION_CAMERA_FLASH,                                 
    LM_FL_REGION_DISPLAY_BL,                                   
    LM_FL_REGION_CLI_DISPLAY_BL,                               
    LM_FL_REGION_LOGO,                                         
    LM_FL_REGION_KEYPAD_NAV_BL,                                
    LM_FL_REGION_KEYPAD_NUM_BL,                                
    LM_FL_REGION_BT_LED,                                       
    LM_FL_REGION_SOL_LED,                                      
    LM_FL_REGION_PRIVACY_IND,                                  

    LM_FL_REGION_MORPHING_START,
    LM_FL_REGION_CONTROL_AREA = LM_FL_REGION_MORPHING_START,   
    LM_FL_REGION_NUMERIC,                                      
    LM_FL_REGION_OMEGA,                                        
    LM_FL_REGION_MUSIC,                                        
    LM_FL_REGION_LAUNCH_CLEAR,                                 
    LM_FL_REGION_CAPTURE_PLAYBACK,                             
    LM_FL_REGION_STILL_VIDEO,                                  
    LM_FL_REGION_ZOOM_IN_OUT,                                  
    LM_FL_REGION_TRASH_SHARE,                                  
    LM_FL_REGION_MEDIA,                                        
    LM_FL_REGION_MORPHING_END = LM_FL_REGION_MEDIA,

    LM_FL_MAX_REGIONS
} LM_FL_REGION_T;

typedef enum
{
    LM_FL_APP_CTL_DEFAULT = 0,
    LM_FL_APP_CTL_KJAVA,
    LM_FL_APP_CTL_FUN_LIGHTS,
    LM_FL_APP_CTL_ALERT_LIGHTS,
    LM_FL_APP_CTL_TST_CMDS,
    LM_FL_APP_CTL_END
} LM_FL_APP_CTL_T;

typedef unsigned int LM_FL_REGION_MSK_T;

typedef unsigned int LM_FL_COLOR_T;

typedef enum
{
    LM_FL_PATTERN_TIMING_REPETITIVE = 0,
    LM_FL_PATTERN_TIMING_ONE_SHOT,
    LM_FL_PATTERN_END
} LM_FL_PATTERN_TYPE_T;

typedef enum
{
    LM_FL_PATTERN_ID_NONE = 0,

    LM_FL_PATTERN_ID_ALL_ALERT = 127,

    LM_FL_PATTERN_ID_EVENT_START = 128,
    LM_FL_PATTERN_ID_POWER = LM_FL_PATTERN_ID_EVENT_START,  
    LM_FL_PATTERN_ID_BLUETOOTH_CONNECT = 148,
    LM_FL_PATTERN_ID_BLUETOOTH_CONNECTED = 149,
    LM_FL_PATTERN_ID_BLUETOOTH_DISCONNECT = 150,
    LM_FL_PATTERN_ID_CHARGING = 158,
    LM_FL_PATTERN_ID_CHARGING_EIGHTY_PERCENT = 159,
    LM_FL_PATTERN_ID_CHARGING_COMPLETE = 160,

    LM_FL_PATTERN_ID_ALL = 255
} LM_FL_PATTERN_ID_T;

enum
{
    LM_APP_REQUEST = 0x8001,   
    LM_APP_VOTE,               
    LM_APP_SETUP,              
    LM_APP_FL_REQUEST          
};

typedef enum
{
    LM_APP_REQ_LCD_DELAYSLEEP,
    LM_APP_REQ_EMERG_CALL_BEGIN,
    LM_APP_REQ_EMERG_CALL_END,
    LM_APP_REQ_KEY_EVENT,
    LM_APP_REQ_SCREENSAVER_KILLED
} LM_APP_REQUEST_T;

typedef enum
{
    LM_APP_VOTE_CLEAR_ALL,
    LM_APP_VOTE_KEEP_ALL
} LM_APP_VOTE_T;

typedef enum
{
    LM_APP_SETUP_DISPLAY_TIMER,
    LM_APP_SETUP_FLIP,
    LM_APP_SETUP_BKLIGHT,  
    LM_APP_SETUP_KEYLOCKMODE,
    LM_APP_SETUP_MORPHING,
    LM_APP_SETUP_SCREENSAVER,
    LM_APP_SETUP_LIGHT_SENSOR,
    LM_APP_SETUP_PROX_SENSOR,
    LM_APP_SETUP_OVERRIDE_DISPLAY_TIMER,

    LM_APP_SETUP_GET_STATUS,
    LM_APP_SETUP_ACCESSORY

} LM_APP_SETUP_T;

typedef struct
{
    LM_APP_SETUP_T id;
    union
    {
        unsigned int display_sleep_time;
        unsigned int flip_status;
        unsigned int bl_brightness;
        unsigned int screensaver_timeout;
        unsigned int light_sensor_threshold;
    } value;
    unsigned int mode;
} LM_APP_SETUP_BODY_T;

typedef enum
{
    LM_APP_FL_REQ_START,
    LM_APP_FL_REQ_STOP,
    LM_APP_FL_REQ_SET_CONTROL,
    LM_APP_FL_REQ_SET_CONTROL_IN_CUR_STATE,
    LM_APP_FL_REQ_UPDATE
} LM_APP_FL_REQUEST_T;

typedef struct
{
    LM_FL_PATTERN_ID_T pattern_id;
    LM_FL_PATTERN_TYPE_T pattern_type;
} LM_APP_PATTERN_T;

typedef struct
{
    LM_FL_APP_CTL_T nApp;
    LM_FL_REGION_MSK_T nRegionMsk;
} LM_APP_UPDATE_T;

typedef struct
{
    LM_APP_FL_REQUEST_T id;
    union
    {
        LM_APP_PATTERN_T pattern;
        LM_APP_UPDATE_T update;
    } fl_req;  
    LM_FL_COLOR_T nColor[LM_FL_MAX_REGIONS];
} LM_APP_FL_REQUEST_BODY_T;

typedef enum
{
    LM_KEY_EVENT_KEY,
    LM_KEY_EVENT_FLIP
} LM_KEY_EVENT_T;

typedef struct
{
    bool screensaver_enabled:1;
    bool prox_sensor:1;
    unsigned int screensaver_timeout;
    unsigned int display_timeout_normal;
    unsigned int display_timeout_keylock;
    unsigned int display_timeout_dimmed;
    unsigned int bklight_brightness_normal;
    unsigned int bklight_brightness_keylock;
    unsigned int bklight_brightness_dimmed;
    unsigned int light_sensor_min_threshold;
    unsigned int light_sensor_max_threshold;
} LM_CONFIG;

typedef enum
{ 
    LM_PRIVACY_BRIGHTNESS_LEVELOFF =0,
    LM_PRIVACY_BRIGHTNESS_LEVEL10,
    LM_PRIVACY_BRIGHTNESS_LEVEL20,
    LM_PRIVACY_BRIGHTNESS_LEVEL30,
    LM_PRIVACY_BRIGHTNESS_LEVEL40,
    LM_PRIVACY_BRIGHTNESS_LEVEL50,
    LM_PRIVACY_BRIGHTNESS_LEVEL60,
    LM_PRIVACY_BRIGHTNESS_LEVEL70,
    LM_PRIVACY_BRIGHTNESS_LEVEL80,
    LM_PRIVACY_BRIGHTNESS_LEVEL90,
    LM_PRIVACY_BRIGHTNESS_LEVEL100 = LM_PRIVACY_BRIGHTNESS_LEVEL90,
    LM_PRIVACY_NUM_BRIGHTNESS_LEVEL
} LM_PRIVACY_BRIGHTNESS_T;

int LM_app_connect();

int LM_app_sendMsg(int fd, unsigned short id, void *buf, unsigned short len);

void LM_app_disconnect(int fd);

int LM_app_reqSend(LM_APP_REQUEST_T req);

int LM_setDisplayTimer(unsigned int mode, unsigned int time);

int LM_setupFlipStatus(unsigned int open);

int LM_setupRelativeBklightBrightness(unsigned int relative_brightness); 

int LM_setupBklightBrightness(unsigned int brightness);

int LM_setKeyLockMode(unsigned int mode);

int LM_AppStartFunlight(LM_FL_PATTERN_ID_T pattern_id, LM_FL_PATTERN_TYPE_T pattern_type);

int LM_AppStopFunlight(LM_FL_PATTERN_ID_T pattern_id);

int LM_setMorphingMode(unsigned int mode);

int LM_sendKeyPress(int fd, LM_KEY_EVENT_T key_event, int status);

int LM_app_FLUpdate(LM_FL_APP_CTL_T nApp, LM_FL_REGION_MSK_T nRegionMsk, LM_FL_COLOR_T* nColor);

int LM_app_FLSetcontrol(LM_FL_APP_CTL_T nApp, LM_FL_REGION_MSK_T nRegionMsk);

int LM_app_FLSetcontrolInCurState(LM_FL_APP_CTL_T nApp, LM_FL_REGION_MSK_T nRegionMsk);

int LM_setScreensaverStatus(unsigned int status);

int LM_setConfig(LM_CONFIG config);

int LM_overrideDisplayTimer(unsigned int time);

int LM_setProxSensor(unsigned int status);

#ifdef __cplusplus
}
#endif

#endif  
