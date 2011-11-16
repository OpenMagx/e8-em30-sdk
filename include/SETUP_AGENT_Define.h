

// Copyright (c) 31-Mar-08 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_SETUP_AGENT_DEFINE_H  
#define PUBLIC_API_SETUP_AGENT_DEFINE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>
#include <stdlib.h>

#ifndef SETUP_GET_DIR
#define SETUP_GET_DIR(env)   (QString(getenv(env)) + "/")
#endif

#define SETUP_BASE_DIR                      SETUP_GET_DIR("EZX_APP_WRITE_PATH") + "setup/";
#define SETUP_CFG_FILE                      "ezx_system.cfg"

#define SETUP_GRP_SECURITY_STR 			"SYS_SECURITY"              
#define SETUP_GRP_POWER_STR			"SYS_POWER_MANAGEMENT"      
#define SETUP_GRP_INIT_STR			"SYS_INIT_SET"              
#define SETUP_GRP_IRDA_BT_STR			"SYS_IRDA_BT"               
#define SETUP_GRP_JAVA_STR			"SYS_JAVA"                  
#define SETUP_GRP_TIME_STAMP_STR		"ezx_timestamp"             
#define SETUP_GRP_KEYPADLOCK_TIMER_STR          "KEYPADLOCK_TIMER"          

#define SETUP_KEY_CALIBRATE_WHEN_POWER_ON        "InitCalibrateWhenPowerOn" 
#define SETUP_KEY_TIME_STAMP_STR		 "ezx_timestamp"            

#ifdef FEAT_SOFT_KEYLOCK_ENABLE
#define SETUP_KEY_KEYPADLOCKTIMER1_STR          "KeypadLockTimerValue0"     
#define SETUP_KEY_KEYPADLOCKTIMER2_STR          "KeypadLockTimerValue1"     
#define SETUP_KEY_KEYPADLOCKTIMER3_STR          "KeypadLockTimerValue2"     
#define SETUP_KEY_KEYPADLOCKTIMER4_STR          "KeypadLockTimerValue3"     
#define SETUP_KEY_KEYPADLOCKTIMERVALUEINDEX_STR "KeypadLockTimerDefaultIndex" 
#define SETUP_KEY_KEYPAD_TIMER_VALUE          "keypadlocktimervalue"     
#endif

#define SETUP_KEY_SECURITY_CODE_STR 		"SecuritySecurityCode"        
#define SETUP_KEY_PRIVATE_CODE_STR 		"SecurityPrivateCode"         
#define SETUP_KEY_UNLOCK_CODE_STR 		"SecurityUnlockCode"          
#define SETUP_KEY_AUTO_LOCK_STATUS_STR 		"SecurityAutoLockStatus"      
#define SETUP_KEY_AUTO_LOCK_FLAG_STR 	"SecurityAutoLockFlag"                
#define SETUP_KEY_AUTO_LOCK_TIMEOUT_FLAG_STR 	"SecurityAutoLockTimeoutFlag" 
#define SETUP_KEY_MIN_UNLOCK_PWD_LENGTH_STR 	"SecurityMinUnlockPwdLength"  
#define SETUP_KEY_PRIVATE_STATUS_STR 		"SecurityPrivateStatus"       
#define SETUP_KEY_FIXED_DIAL_STATUS_STR 	"SecurityFixedDialStatus"     
#define SETUP_KEY_OWNER_STATUS_STR		"InitOwnerStatus"             
#define SETUP_KEY_INSTANT_PHONELOCK_STR         "InstantPhoneLockStatus"      

#define SETUP_KEY_AUTO_POWER_OFF_STATUS_STR     "PowerOffStatus"              
#define SETUP_KEY_AUTO_POWER_OFF_TIME_HOUR_STR	"PowerOffTimeHour"            
#define SETUP_KEY_AUTO_POWER_OFF_TIME_MINUTE_STR "PowerOffTimeMinute"         

#define SETUP_KEY_DURATION_TIME_STR		"DurationTime"                

#define SETUP_KEY_LCD_SLEEP_TIME_STR          "BacklightTimeout"              

#define SETUP_KEY_BACKLIGHT_STR                 "Brightness"                  

#define UNIQUE_HARD_VOLUME                                                    
#ifdef UNIQUE_HARD_VOLUME
#define SETUP_KEY_SYSTEM_VOLUME_STR		"SystemVolume"                
#define SETUP_KEY_RINGTONE_VOLUME_LINE1_STR	SETUP_KEY_SYSTEM_VOLUME_STR   
#define SETUP_KEY_RINGTONE_VOLUME_LINE2_STR	SETUP_KEY_SYSTEM_VOLUME_STR   
#define SETUP_KEY_SPEAKER_VOLUME_STR		"SpeakerVolume"               
#define SETUP_KEY_ALERT_VOLUME_STR		SETUP_KEY_SYSTEM_VOLUME_STR   
#else
#define SETUP_KEY_SYSTEM_VOLUME_STR		"SystemVolume"                
#define SETUP_KEY_RINGTONE_VOLUME_LINE1_STR	"RingtoneVolumeLine1"         
#define SETUP_KEY_RINGTONE_VOLUME_LINE2_STR	"RingtoneVolumeLine2"         
#define SETUP_KEY_SPEAKER_VOLUME_STR		"SpeakerVolume"               
#define SETUP_KEY_ALERT_VOLUME_STR		"AlertVolume"                 
#endif

#ifdef FEAT_FTR_HAPTICS
#define SETUP_KEY_VIBRATION_STYLE_STR           "VibrationStyle"              
#endif

#ifdef FEAT_FTR_FUN_LIGHTS
#define SETUP_CHARGING_LIGHT_STR                "ChargingLight"                
#endif

#define SETUP_KEY_MISSED_EVENT_STATUS_STR   "MissedEventStatus"            
#define SETUP_KEY_GENERAL_ALERT_STATUS_STR  "GeneralAlertStatus"           
#define SETUP_KEY_MESSAGE_ALERT_STATUS_STR  "MessageAlertStatus"           

#define SETUP_KEY_NETWORK_LANGUAGE_STR      "NetworkLanguageType"          
#define SETUP_KEY_DEFAULT_LANGUAGE_STR      "DefaultLanguageType"          

#define SETUP_KEY_PRESS_HOLD_INDICATOR_STR  "PressHoldIndicator"           
#define SETUP_KEY_RINGTONE_FILE_NAME_STR        "RingToneFileName"             
#define SETUP_KEY_RINGTONE_TYPE_STR             "RingToneType"                 

#define SETUP_KEY_BT_NAME_STR           "BluetoothName"                
#define SETUP_KEY_BT_STATUS_STR         "BluetoothStatus"              
#define SETUP_KEY_BT_NOTIFY_STR         "BluetoothNotify"              
#define SETUP_KEY_IRDA_STATUS_STR           "IrDaStatus"                   
#define SETUP_KEY_USB_STATUS_STR            "USBStatus"                    
#define SETUP_KEY_WALLPAPER_TRANSPARENCY_STR    "WallpaperTransparency"        
#define SETUP_KEY_PDA_ONLY_ON_SUBSIDY_LOCKED    "PdaOnlyOnSubsidyLocked"       
#define SETUP_KEY_DISABLE_PDA_ON_SUBSIDY_LOCKED_NO_SIM "DisablePdaOnSubsidyLockedNoSim" 

#define SETUP_KEY_KEYLOCK_STATUS_STR            "KeyLockStatus"                

#define SETUP_KEY_VR_TALKINGPHONE_STR	        "TTSTalkingPhone"              
#define SETUP_KEY_VR_COMMAND_TONE_STR	        "VRCommandTone"                
#define SETUP_KEY_VR_HELP_STR		        "VRHelpFlex"                   

#define SETUP_KEY_VP_STATUS_STR                 "VPStatusFlex"                 
#define SETUP_KEY_VP_LAUNCH_STATUS_STR          "VPLaunchStatusFlex"           
#define SETUP_KEY_VP_VERIFY_STATUS_STR          "VPVerifyStatusFlex"           

#define SETUP_KEY_JAVA_HEAP_SIZE_STR		        "JavaHeapSize"         
#define SETUP_KEY_JAVA_OTA_TIMEOUT_STR		        "JavaOtaTimeout"       

#define INVL_BLOG_GRPSTR_PROFILES     "Invl_Blog_Profile_List"  
#define INVL_PIC_GRPSTR_PROFILES     "Invl_Pic_Profile_List"      
#define INVL_AUD_GRPSTR_PROFILES     "Invl_Aud_Profile_List"  
#define INVL_VID_GRPSTR_PROFILES     "Invl_Vid_Profile_List"  
#define INVL_GAME_GRPSTR_PROFILES    "Invl_Game_Profile_List"  
#define INVL_KEYSTR_SERVICEADDR  "ServiceAddress"  
#define INVL_KEYSTR_URL          "Url"  

#define SETUP_KEY_HAPTIC_STR                     "HapticStatus"            
#define SETUP_BACKLIGHT_COLOR_STR                "BacklightColor"       
#define SETUP_STATUS_LIGHT_STR                   "StatusLight"         
#define SETUP_FONT_SIZE_STR                      "FontSize"     
#define SETUP_CONTRAST_STR                       "Contrast"     
#define SETUP_BRIGHTNESS_STR                     "Brightness"     
#define SETUP_CALLERID_READOUT_STR               "CallerIDReadout"     
#define SETUP_MENU_READOUT_STR                   "MenuReadout"     
#define SETUP_CONTACTS_READOUT_STR               "ContactsReadout"     
#define SETUP_DIGITS_READOUT_STR                 "DigitsReadout"     
#define SETUP_EMAIL_READOUT_STR                  "EmailReadout"     
#define SETUP_MESSAGE_READOUT_STR                "MessageReadout"     
#define SETUP_PERSONAL_DICTIONARY_LOCK_STR       "PDLockStatus"     
#define SETUP_PERSONAL_DICTIONARY_LOCK_PASSWORD_STR "PDLockPassword"     
#define SETUP_PROXIMITY_SOUND_STR                "ProximitySound"   

#define SETUP_GRP_PROPERTIES_STR        "SYS_PROPERTIES" 
#define SETUP_APFLEXVERSION_STR         "APFlexVersion" 
#define SETUP_BPFLEXVERSION_STR         "BPFlexVersion" 
#define SETUP_APSWVERSION_STR           "APSwVersion" 
#define SETUP_BPSWVERSION_STR           "BPSwVersion" 
#define SETUP_TECHNOLOGY_STR            "Technology" 
#define SETUP_DSPVERSION_STR            "DspVersion" 
#define SETUP_LANGUAGELIST_STR          "LanguageList" 
#define SETUP_DATAREADY_STR             "DataReady" 
#define SETUP_SYNCREADY_STR             "SyncReady" 
#define SETUP_BROWSERREADY_STR          "BrowserReady" 
#define SETUP_MP3READY_STR              "Mp3Ready" 
#define SETUP_SMSREADY_STR              "SmsReady" 
#define SETUP_EMSREADY_STR              "EmsReady" 
#define SETUP_FAXREADY_STR              "FaxReady" 
#define SETUP_BROWSERINFO_STR           "BrowserInfo" 
#define SETUP_ESNVERSION_STR            "ESNVersion" 
#define SETUP_PRLVERSION_STR            "PRLVersion"
#define SETUP_PRICHECKSUM_STR           "PRIChecksum"

#define SETUP_GRP_BROWSERNAME_STR       "BROWSER"        
#define SETUP_BROWSERNAME_KEY           "browserName"    

#define SETUP_AUTO_ANSWER_STR           "Auto-Answer"       
#define SETUP_VOICE_DIAL_STR            "VoiceDial"         
#define SETUP_TTY_STR "TTY"                           

#define SETUP_BACKLIGHTINLOCK_INTENSITY_STR    "BackLightInLockIntensity" 
#define SETUP_BACKLIGHTINLOCK_DURATION_STR     "BackLightInLockDuration"  
const unsigned int SETUP_BACKLIGHTINLOCK_INTENSITY_DEFAULT = 45;                        
const unsigned int SETUP_BACKLIGHTINLOCK_DURATION_DEFAULT = 4000;         
const char* const SETUP_KEY_SCREENSAVER_STATUS = "ScreensaverStatus";
const char* const SETUP_KEY_SCREENSAVER_TIMER = "ScreenSaverTimeout";
const unsigned int SETUP_SCREENSAVER_TIMER_DEFAULT = 20;
const char* const SETUP_KEY_DISPLAY_TIMER = "DisplayTimeout";
const unsigned int SETUP_DISPLAY_TIMER_DEFAULT = 10;
const char* const SETUP_KEY_DISPLAY_TIMER_DIMMED = "DimTimeout";
const unsigned int SETUP_DISPLAY_TIMER_DIMMED_DEFAULT = 20;
const char* const SETUP_KEY_BACKLIGHT_DIM_INTENSITY = "DimIntensity";
const unsigned int SETUP_BACKLIGHT_DIM_INTENSITY_DEFAULT = 30;

#define SETUP_MAXBRIGHTNESSFORPM_STR "MaxBrightnessForPM"           
#define SETUP_MINBRIGHTNESSFORPM_STR "MinBrightnessForPM"           
const int SETUP_MAXBRIGHTNESSFORPM_DEFAULT = 100;            
const int SETUP_MINBRIGHTNESSFORPM_DEFAULT = 0;              
const int SETUP_MAXUISCALE = 7;                              
const int SETUP_CHAMELEON_SCALE = SETUP_MAXUISCALE + 1;      
const int SETUP_MAXBRIGHTNESS = 100;                         

#define SETUP_SLIDECLOSEDSETTING_STR "SlideClosed"
#define SETUP_SLIDE_OPEN_TONE "SlideOpenTone"
#define SETUP_SLIDE_CLOSE_TONE "SlideCloseTone"

#define    SYSTEM_SETUP_CHANNEL                "/systemsetup/broadcast"   

#define    MSG_ACTIVE_ALERTSTYLE_CHANGE        "alertstyleChange"   
#define    MSG_ALERT_VOLUME_CHANGE             "alertVolumeChange"   
#define    MSG_SYSTEM_VOLUME_CHANGE            "systemVolumeChange"   
#define    MSG_SLIDE_TONE_CHANGE               "slideToneChange"   
#define    MSG_ALERTSTYLE_DELETE               "alertStyleDelete"
#define    MSG_ALERTSTYLE_ADD                  "alertStyleAdd"
#define    MSG_ALERTSTYLE_CHANGENAME           "alertStyleChangeName"
#define    MSG_PROXIMITY_SOUND                 "proximity_sound_setting(int)"

#ifdef FEAT_UISTYLE_CHAMELEON
#ifdef  FEAT_SOFT_KEYLOCK_ENABLE
#define PHONE_IDLE_KEYPAD_CHANNEL "/Phone/Idle/keypad/channel"         
#define MSG_TIMER_VALUE_CHANGED   "timer_value(int)" 
#endif 
#endif 

#define   DISPLAY_NAME_KEY    "DisplayName"    
#define   OPEN_TONE_KEY       "OpenTone"       
#define   CLOSE_TONE_KEY      "CloseTone"      

#define DC_SETUP_BASE                        QString(getenv("EZX_RES_PATH")) + QString("/")
#define USR_SETUP_BASE                       QString(getenv("EZX_SETUP_PATH")) + QString("/")
#define THEME_RINGTONE_DIR                   QString(getenv("EZX_RES_SOUNDS_RINGTONES_PATH")) + QString("/")
#define THEME_PICTURE_DIR 		             QString(getenv("EZX_RES_PICTURE_PATH")) + QString("/")    
#define POWERON_ANIMATION_DIR                QString(getenv("EZX_RES_POWERUPANIMATION_PATH")) + QString("/") 
#define POWEROFF_ANIMATION_DIR               QString(getenv("EZX_RES_POWEROFFANIMATION_PATH")) + QString("/") 

#define DOWNLOAD_THEME_CONFIG_PATH        SETUP_GET_DIR("EZX_INSTALLED_THEME_PATH")	 
#define PRELOAD_APPS_PATH		      SETUP_GET_DIR("EZX_LANG")+"preloadapps/"   

#define SETUP_GRP_THEME_STR                 "SYS_THEME_SET"

#define SETUP_GRP_SYS_STR                   "SYS_SYSTEM_SET"
#define SETUP_GRP_FONT_STR                  "SYS_LANG_FONT_SIZE"
#define SETUP_GRP_FLEX_TABLE_STR            "SYS_FLEX_TABLE"
#define SETUP_GRP_IM_STR                    "SYS_INPUTMETHOD_SET"

#define THEME_GRP_CONFIG_STR                "THEME_GROUP_LOG"

#define THEME_GRP_COLOR_PALETTE_STR         "THEME_COLOR_PALETTE_TABLE"
#define THEME_GRP_MULTI_LANG_NAME_STR       "THEME_MULTI_LANG_NAME"

#define SETUP_KEY_TOUCH_SCREEN_VOLUME_STR   "TouchScreenVolume"
#define SETUP_KEY_TOUCH_SCREEN_TYPE_STR     "TouchScreenType"

#define SETUP_KEY_LANGUAGE_STR              "LanguageType"
#define SETUP_KEY_USER_DEFINED_LANGUAGE_STR "UserDefinedLanguageType"

#define SETUP_KEY_SITE_STR          "SiteType"

#define SETUP_KEY_ITAP_ORDER "TSiTapOrder"
#define SETUP_KEY_PRIMARY_INPUT_STR "TSPreferredInputMethod"
#define SETUP_KEY_PREFERED_INPUT_LANGUAGE_STR  "TSFirstInputLanguage"
#define SETUP_KEY_SECONDARY_INPUT_LANGUAGE_STR "TSSecondInputLanguage"
#define SETUP_KEY_WRITING_HAND_STR          "TSWritingHand"
#define SETUP_KEY_WRITING_RECOG_STR         "Handwriting Recog"
#define SETUP_KEY_WRITING_SPEED_STR         "TSWritingSpeed"
#define SETUP_KEY_WORD_COMPLETION_STR       "WordCompletion"
#define SETUP_KEY_NEXT_WORD_PREDICT_STR       "NextWordPredict"
#define SETUP_KEY_USER_DICT_STR             "UserDict"
#define SETUP_KEY_WATER_MARK_STR            "TSWaterMark"
#define SETUP_KEY_TOOL_TIP_STR            "TSToolTip"

#define SETUP_KEY_DATE_FORMAT_STR           "DateFormat"
#define SETUP_KEY_TIME_FORMAT_STR           "TimeFormat"
#define SETUP_KEY_LARGE_FONT_SIZE_STR       "LargeFontSize"
#define SETUP_KEY_MEDIUM_FONT_SIZE_STR      "MediumFontSize"
#define SETUP_KEY_SMALL_FONT_SIZE_STR       "SmallFontSize"

#define THEME_KEY_COLOR_PALETTE_INDEX_STR   "ThemeColorPaletteIndex"
#define THEME_KEY_COLOR_PALETTE_NAME_STR    "ThemeColorPaletteName"

#define THEME_KEY_TEXT_SIZE_STR             "ThemeTextSize"

#define THEME_KEY_SKIN_FILE_STR             "ThemeSkinFile"
#define THEME_KEY_LOGO_ICON_STR             "ThemeLogoIcon"
#define THEME_KEY_BLENDING_PERCENTAGE_STR       "BlendingPercentage"
#define THEME_KEY_BLENDING_COLOR_STR       "BlendingColor"
#define THEME_KEY_BLENDING_GNB_STR       "BlendingGNB"
#define THEME_KEY_BLENDING_CST_STR       "BlendingCST"
#define THEME_KEY_BLENDING_STATUSBAR_STR       "BlendingStatusBar"
#define THEME_KEY_BLENDING_SCROLLBAR_STR       "BlendingScrollBar"

#define THEME_KEY_ICON_DIR_STR              "CurrentSkin"

#define THEME_KEY_NAME_STR                  "ThemeName"

#define THEME_KEY_CURRENT_USE_STR           "ThemeCurrentUse"

#define THEME_FOREGROUND_STR                "ThemeForeground"
#define THEME_BACKGROUND_STR                "ThemeBackground"
#define THEME_BUTTON_STR                    "ThemeButton"
#define THEME_BUTTON_TEXT_STR               "ThemeButtonText"
#define THEME_HIGHLIGHT_STR                 "ThemeHighlight"
#define THEME_HIGHLIGHT_TEXT_STR            "ThemeHighlightedText"
#define THEME_BRIGHT_TEXT_STR               "ThemeBrightText"
#define THEME_DISABLED_TEXT_STR           "ThemeDisabledText"
#define THEME_AMBOTTOM_HIGHTLIGHT_STR  "ThemeAMBottomHighlight"
#define THEME_AMBOTTOM_HIGHTLIGHT_TEXT_STR "ThemeAMBottomHighlightText"

#define SETUP_KEY_CARKIT_AUTO_ANSWER_VALUES_STR           "CarkitAutoAnswerValues"
#define SETUP_KEY_CARKIT_AUTO_ANSWER_STR                  "CarkitAutoAnswer"
#define SETUP_KEY_CARKIT_AUTO_HANDSFREE_STR               "CarkitAutoHandsfree"
#define SETUP_KEY_CARKIT_POWER_OFF_DELAY_STR              "CarkitPowerOffDelay"
#define SETUP_KEY_CARKIT_CHARGE_TIME_STR                  "CarkitChargeTime"
#define SETUP_KEY_CARKIT_PREV_MODE_STR                    "CarkitPrevMode"

#define DEFAULT_LANGUAGE_CODE               "en-us"
#define LANGUAGE_DES_CONFIG_FILE            "readme.cfg"

#define SETUP_DATETIME_FORMAT_CHANNEL       "EZX/Setup/DateTimeFormatChanged"
#define SETUP_DATE_FORMAT_CHANGED           "Setup/DateFormatChanged"
#define SETUP_TIME_FORMAT_CHANGED           "Setup/TimeFormatChanged"

#define THEME_CFG_FILE                      "ezx_skin.cfg"                     
#define COLOR_CFG_FILE                      "colorpalette.cfg"
#define ALERTSTYLE_CFG_FILE                 "ezx_alertstyle.cfg"

#define THEME_KEY_SKINNABLEPROP_FILE_STR    "ThemeSkinnablePropFile"

#define SETUP_TIMESTAMP_FILE                "ezx_timestamp.cfg"
#define THEME_TIMESTAMP_FILE                "skin_timestamp.cfg"       

#define TMP_SETUP_FILE                      "/tmp/ezx_system.cfg"

#define TMP_FIXED_DIAL_FILE                 "/tmp/ezx_fixeddial.cfg"
#define TMP_COLOR_PAL_FILE                  "/tmp/colorpalette.cfg"

#define TMP_SETUP_DIR                       "/tmp/"

#define SETUP_KEY_AIRPLANE_MODE_STR        "AirplaneModeStatus"        
#define SETUP_KEY_AIRPLANE_MODE_PROMPT_STR          "AirplaneModePromptStatus"   

#define SETUP_GRP_OSS_LICENSE                   "OSS_License"               
#define SETUP_KEY_OSSLICENSE_USEOTHERLICFILE    "UseOtherLicFile"           
#define SETUP_KEY_OSSLICENSE_OTHERLICFILEPATH   "OtherLicFilePath"          
#define PHONESETTING_OSSLICENSE_FILEPATH_CONFIG    ZConfig::getSettingDirectory()+"lj_oss.cfg"     
#define PHONESETTING_OSSLICENSE_DEFAULTFILE     "/usr/SYSqtapp/systemsetup/defaultossfile/oss_license_notice.html"        
#endif  

