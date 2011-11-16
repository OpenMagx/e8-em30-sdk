//
// Writen by Ant-ON, 2010
//
// email: prozanton@gmail.com
//

#ifndef PUBLIC_API_SETUP_UTIL_H 
#define PUBLIC_API_SETUP_UTIL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "SETUP_UTIL_Define.h"
#include "SETUP_SET_Manager.h"
#include <qstring.h>
#include <qstringlist.h>
#include <qmap.h>

//For change SDK for ZN5/U9/Z6W
#include "ZMyConfig.h"

class STRU_IATC_PROFILE_RING_TONE_D;

struct ALERTSTYLE_DATA_S
{
    // ...
};

struct PROFILE_DATA_S
{
    // ...
};

struct JAVA_SYSTEM_S
{
    QString midp;
    QString cldt;
    QString s1;
    QString s2;
    QString heapSize;
    QString cdc;
};

enum ENUM_PRELOADED_PROFILE_E
{
};

struct SETUP_SYSTEM_INFORMATION
{
	QString s;//???
    // ...	
};

struct PROFILE_CONFIG_S
{
    QString id;
    QString name;
    // ...
};

class SETUP_Utility_Impl
{
public:
	void copyProfileValue(QString const&, SETUP_SET_Manager&, PROFILE_CONFIG_S&);	 
	void getAdjustAlertValue(int&);	 
	void getBackupProfileConfigInfo(PROFILE_CONFIG_S&, QString const&);	 
	void getFlexBitFileName(unsigned short);	 
	void getFlexBitFromBP(void*, unsigned char, unsigned char*);	 
	void getGroupNameFromAlertStyle(QString&, int);	 
	void getHeapSizeStr(int);	 
	void getProfileIconString(ENUM_ALERT_STYLE, QString&, bool);	 
	void getShortcutFileName();	 
	void getTimestampFileName();	 
	void getTRProfileName(int, bool);	 
	void resetBackupProfile();	 
	void writeProfileValue(QString&, SETUP_SET_Manager&, PROFILE_CONFIG_S const&);
};

class SETUP_Utility
{
public:
	SETUP_Utility();
	~SETUP_Utility();

	void dcSetupInit();	 
	QString defaultLightPatternFile();	 
	QString defaultPictureFile();	 
	QString defaultSoundFile();	 
	void getActiveAlertStyle(ENUM_ALERT_STYLE&);	 
	void getActiveProfileID(int&);	 
	void getActiveProfile(int&);	 
	void getActiveProfileRingTone(ENUM_ALERT_TYPE, QString&);	 
	void getActiveProfileRingTone(STRU_IATC_PROFILE_RING_TONE_D*);	 
	void getAlertStyle(ENUM_ALERT_STYLE&);	 
	void getAlertStyle(int, ENUM_ALERT_STYLE&);	 
	void getAlertStyleList(QMap<int, ALERTSTYLE_DATA_S>&, bool);	 
	void getAlertStyleName(QString&, bool);	 
	void getAlertTone(ENUM_ALERT_TYPE, QString&);	 
	void getAlertTone(int, ENUM_ALERT_TYPE, QString&);	 
	void getAllProfileIDs(QValueList<int>&);	 
	void getAutoAnswerTime(int&);	 
	void getBackLightDimIntensity();	 
	void getBackLightInLockDurationTool(SETUP_SET_Manager&);	 
	void getBackLightInLockDuration();	 
	void getBackLightInLockIntensityTool(SETUP_SET_Manager&);	 
	void getBackLightInLockIntensity();	 
	void getBackLightValue(int&);	 
	void getBackLightValueTool(SETUP_SET_Manager&, int&);	 
	void getBackupProfile(int&);	 
	void getBlendingColor(unsigned int&);	 
	void getBlendingPercentage(int&);	 
	void getBrowserFeatureValue(BROWSER_FEATURE_VALUE_T, unsigned int&);	 
	void getChargingLightStatus(bool&);	 
	void getContrast(int&);	 
	void getDimDisplayTimer();	 
	void getDisplayTimer();	 
	void getFlexBit(unsigned short, bool&);	 
	void getHapticStatus(bool&);	 
	bool getImsiChangedFlag();	 
	void getInstantPhoneLockStatus(bool&);	 
	void getInstantPhoneLockStatusTool(SETUP_SET_Manager&, bool&);	 
	void getInvLProfiles(ENUM_INVL_T);	 
	void getJavaHeapSize(int&);	 
	void getJavaOTATimeout(int&);	 
	void getJavaSystemInfo(JAVA_SYSTEM_S&);	 
	void getLcdBacklightColor(int&);	 
	void getLcdSleepTime(int&);	 
	void getLightPattern(ENUM_ALERT_TYPE, QString&);	 
	void getMaxBrightnessRange(int&);	 
	void getMaxBrightnessRangeTool(SETUP_SET_Manager&, int&);	 
	void getMaxFileNameLength(ENUM_THEME_PROFILE_ELEMENT_TYPE);	 
	void getMinBrightnessRange(int&);	 
	void getMinBrightnessRangeTool(SETUP_SET_Manager&, int&);	 
	void getMinUnlockCodeLength(unsigned int&);	 
	void getMissedNotificationStatus(int&);	 
	void getPersonalDictionaryLockPassword(QString&);	 
	void getPersonalDictionaryLockStatus(bool&);	 
	void getPhoneAutoLockStatus(bool&);	 
	void getPhoneAutoLockTime(int&);	 
	void getPowerDownImage(QString&);	 
	void getPowerUpDownLightPattern(QString&);	 
	void getPowerUpImage(QString&);	 
	void getPreviouseActiveProfile(int&);	 
	void getPreviouseAlertStyle(ENUM_ALERT_STYLE&);	 
	void getProfileFlexOffList();	 
	void getProfileIcon(int, QString&);	 
	void getProfileList(QMap<int, PROFILE_DATA_S>&, bool);	 
	void getProfileList(QMap<int, QString>&, bool);	 
	void getProfileName(int, QString&, bool);	 
	void getProfileName(QString&, bool);	 
	void getProximitySoundStatus();	 
	void getScreensaverStatus();	 
	void getScreensaverTimer();	 
	void getScrSaver(QString&);	 
	void getServerAddrByInvLProfile(ENUM_INVL_T, QString);	 
	void getSetupSystemInformation(SETUP_SYSTEM_INFORMATION&);	 
	void getSliderTone(QString&, QString&);	 
	void getSoundVolume(ENUM_SOUND_TYPE_E, int&);	 
	void getSoundVolume(int, ENUM_SOUND_TYPE_E, int&);	 
	void getSpeakerVolume(int&);	 
	void getStatusLight(bool&);	 
	void getSystemSetupManager();	 
	void getTalkingPhoneStatus(ENUM_TALKINGPHONE_READOUT_TYPE, int&);	 
	void getTimeout(ENUM_TIMER_TYPE, int&);	 
	void getTTYType(int&);	 
	void getUSBStatus(int&);	 
	void getUserDefinedLanguageType(QString&);	 
	void getUserDefinedLanguageTypeTool(SETUP_SET_Manager&, QString&);	 
	void getVibratePattern(ENUM_ALERT_TYPE, ENUM_VIBRATE_PATTERN_E&);	 
	void getVibratePattern(int, ENUM_ALERT_TYPE, ENUM_VIBRATE_PATTERN_E&);	 
	void getVoiceDialStatus(bool&);	 
	void getVRTalkingPhone(bool&);	 
	void getWallpaperFileName(QString&);	 
	void getWallpaper(QString&);	 
	void getWallpaperTransparency(bool&);	 
	
	#ifdef EZX_Z6W
	void getKeyPadLockTimerTool(SETUP_SET_Manager&);
	int getKeyPadLockTimer();
	
	enum SLIDE_CLOSED_SETTING_E
	{
	};
	SLIDE_CLOSED_SETTING_E getSlideClosedSetting();
	bool setSlideClosedSetting(SLIDE_CLOSED_SETTING_E);
	#endif
	
	bool isAirplaneModeOn();	 
	bool isFeatureAvailable(unsigned short);	 
	bool isOSSLicense(QString);	 
	bool isSetByThemeStatus(ENUM_ALERT_TYPE);	 
	bool isSimpleProfileView();	 
	
	void md5Encrypt(unsigned char* src, unsigned short length, char* des);	 
	void restoreActiveProfile();	 
	bool setActiveAlertStyleByATC(ENUM_ALERT_STYLE);	 
	bool setActiveAlertStyle(ENUM_ALERT_STYLE);	 
	bool setActiveProfielRingTone(ENUM_ALERT_TYPE, QString const&);	 
	bool setActiveProfileByATC(int);	 
	bool setActiveProfile(ENUM_PRELOADED_PROFILE_E, bool);	 
	bool setActiveProfile(int, bool);	 
	bool setAirplaneMode(bool);	 
	bool setAsRingTone(QString);	 
	bool setAsWallpaper(QString);	 
	bool setAutoAnswerTime(int);	 
	bool setBacklightValue();	 
	bool setByThemeStatus(ENUM_ALERT_TYPE);	 
	bool setChargingLightStatus(bool);	 
	bool setContrast(int);	 
	bool setDisplayTimer(unsigned int);	 
	bool setHapticStatus(bool);	 
	bool setInstantPhoneLockStatus(bool);	 
	bool setLanguageType(QString);	 
	bool setLcdBacklightColor(int);	 
	bool setMinUnlockCodeLength(unsigned int);	 
	bool setPersonalDictionaryLockPassword(QString);	 
	bool setPersonalDictionaryLockStatus(bool);	 
	bool setPhoneAutoLockTime(SETUP_PHONELOCK_TYPE_T);	 
	bool setPhoneLockCode(QString const&);	 
	bool setPhoneLockFlag(bool);	 
	bool setPhoneLockTimeOutFlag(bool);	 
	bool setProximitySoundStatus(bool);	 
	bool setScreensaverStatus(bool);	 
	bool setScrSaver(QString const&);	 
	bool setSilentStatus(bool);	 
	bool setSoundVolume(ENUM_SOUND_TYPE_E, int);	 
	bool setSpeakerVolume(int);	 
	bool setStatusLight(bool);	 
	bool setTalkingPhoneStatus(ENUM_TALKINGPHONE_READOUT_TYPE, bool);	 
	bool setTimeout(ENUM_TIMER_TYPE, int);	 
	bool setupInitialize();	 
	bool setUSBStatus(int);	 
	bool setVibrateStatus(bool);	 
	bool setVoiceDialStatus(bool);	 
	bool setWallPaper(QString const&);	 
	bool verifyAutoLanguageCode(int);	 
	bool verifyPersonalDictionaryLockPassword(QString);	 
	void verifySecurityCode(QString const&, bool&);	 
	void verifyUnlockCode(QString const&, bool&);	 
};

#endif  

