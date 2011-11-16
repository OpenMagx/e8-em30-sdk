

// Copyright (c) 16-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_THEMEAPI_H
#define PUBLIC_API_THEMEAPI_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>
#include <qpixmap.h>

namespace SETUP_THEME
{
  extern const char* const noneSetting; 

  enum THEME_ELEMENT
  {
    THEME_NAME = 0,        
    CALL_ALERT_LINE_1,     
    CALL_ALERT_LINE_2,     
    VIDEO_CALL,            
    PTT_CALL,              
    MSG_ALERT,             
    EMAIL_ALERT,           
    IM_ALERT,              
    VM_ALERT,              
    PTT_ALERT,             
    SLIDE_TONE,            
    CALENDAR_ALARM,        
    WALL_PAPER,            
    WALL_PAPER_LAYOUT,     
    SCREEN_SAVER,          
    CLI_SCREEN_SAVER,      
    POWER_ON_SCREEN,       
    POWER_OFF_SCREEN,      
    SKIN,                  
    THEME_SIZE,            
    CREATE_DATE,           
    LIST_ICON,             
    GRID_ICON,             
    COPYRIGHT,             
    PACKAGE_PATH,          
    PARENT_PATH            
  }; 

  enum ELEMENT_TYPE 
  {
    TYPE_IMAGE,     
    TYPE_AUDIO,     
    TYPE_VIDEO      
  };

  enum THEME_ERROR_NUM
  {
    ERR_OK = 0,                            
    ERR_CANCEL = 0x00180008,               

    ERR_NORMAL = 1,                        
    ERR_OMADRM_RESTRICTION = 0x00180004,           

    ERR_FORMAT_INVALID          = 0x00180001,   
    ERR_WMDRM_NO_PLAY           = 0x00180006,   
    ERR_BYDEPENDENCY            = 0x00180007,   
    ERR_MEMFULL                 = 10            
  };

  extern THEME_ERROR_NUM ErrorNum;

  QString getThemeValue(THEME_ELEMENT element);

  bool isRingTone(const QString& sPath);

  THEME_ERROR_NUM applyRingTone(const QString& sPath);

  THEME_ERROR_NUM updateTheme(SETUP_THEME::THEME_ELEMENT element, const QString& sValue);

  THEME_ERROR_NUM applyElement(THEME_ELEMENT element, const QString& sValue, ELEMENT_TYPE type);
  THEME_ERROR_NUM setWallpaper(QString const&);

    bool isWallpaperFile(const QString & filePath);
}

extern "C"{
typedef int (* applyElement_T)(int element, const char* value, int type);
int applyElement_c(int element, const char* value, int type);

typedef int (* applyRingTone_T)(const char* sPath);

int applyRingTone_c(const char* sPath);

}

#endif
