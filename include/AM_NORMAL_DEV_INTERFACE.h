#ifndef AM_NORMAL_DEV_INTERFACE_H_
#define AM_NORMAL_DEV_INTERFACE_H_

#include "AM_VIRTUAL_DEV_BASE_CLASS.h"
enum SOUNDM_AUDIO_NORMALDEV_TYPE_ENUM_T
{
SOUNDM_AUDIOLVL_NORMALOUT_2  = 0x02
};
enum AUD_RULE_SET_T
{

};
enum SOUNDM_AUDIO_SYSTEMDEV_TYPE_ENUM_T
{

};
enum AAL_STATUS_ENUM_T
{

};
class AM_NORMAL_DEV_INTERFACE : public AM_VIRTUAL_DEV_BASE_CLASS
{
    char data[212];
	AM_VIRTUAL_CODEC_CLASS *pVirtualCodec;//0xD4
	char data2[72];
public:
    AM_NORMAL_DEV_INTERFACE(AUD_RULE_SET_T);
	AM_NORMAL_DEV_INTERFACE(SOUNDM_AUDIO_NORMALDEV_TYPE_ENUM_T);
	AM_NORMAL_DEV_INTERFACE(SOUNDM_AUDIO_NORMALDEV_TYPE_ENUM_T, AUD_RULE_SET_T);
	AM_NORMAL_DEV_INTERFACE(SOUNDM_AUDIO_NORMALDEV_TYPE_ENUM_T, unsigned int freq = 44100, unsigned int channels = 2, unsigned int bytespersample = 2);
	AM_NORMAL_DEV_INTERFACE(SOUNDM_AUDIO_NORMALDEV_TYPE_ENUM_T, unsigned int freq = 44100, unsigned int channels = 2, unsigned int bytespersample = 2, AUD_RULE_SET_T);
	AM_NORMAL_DEV_INTERFACE(SOUNDM_AUDIO_SYSTEMDEV_TYPE_ENUM_T, unsigned int freq = 44100, unsigned int channels = 2, unsigned int bytespersample = 2, AUD_RULE_SET_T);
	AM_NORMAL_DEV_INTERFACE();
	virtual ~AM_NORMAL_DEV_INTERFACE();
public:
    virtual int read(short* pBuffer, unsigned int length);
	virtual int write(short* pBuffer, unsigned int length);
	virtual int canWrite();
	virtual int canRead();
	virtual int bytesWritten() const;
	virtual int channels() const;
	virtual int frequency() const;
	virtual int bytesPerSample() const;
	virtual int bufferSize() const;
	virtual int getVolume(unsigned int& left, unsigned int& right, bool& muted);
	virtual bool isMuted();
	virtual int increaseVolume();
	virtual int decreaseVolume();
	virtual int setVolume(int level);
    virtual int setMMVolume(int level);
	virtual int volumeChanged(bool muted);
	virtual int setAudioDevice(unsigned int, unsigned int, unsigned int);
	virtual int checkDevState();
    virtual int flush();
	virtual int bytesRendered() const;
	virtual int refresh();
	virtual int open();
	virtual int close();
	virtual int lock();
	virtual int unlock();
	virtual int pause();
	virtual int resume();
	int recordStartTime(struct timeval &startTime);
	int SetPathRule(AUD_RULE_SET_T);
	int writeAlignedData(short*, unsigned int, AAL_STATUS_ENUM_T*);
private:
    int am_normdev_init(SOUNDM_AUDIO_NORMALDEV_TYPE_ENUM_T, unsigned int, unsigned int, unsigned int, AUD_RULE_SET_T);
	/*
VRSetHWIGain(int)
VRDuringRecord(bool)
vr_notify_enabled(bool)
defaultRuleSet
adjustDataLength(short*, unsigned int, unsigned int*, unsigned int*)
am_check_priority(SOUNDM_AUDIO_NORMALDEV_TYPE_ENUM_T)
am_check_priority(SOUNDM_AUDIO_SYSTEMDEV_TYPE_ENUM_T)

am_normdev_verify_freq(unsigned int)
*/
};

#endif