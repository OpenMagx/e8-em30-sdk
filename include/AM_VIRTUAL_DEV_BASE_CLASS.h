#ifndef AM_VIRTUAL_DEV_BASE_CLASS_H
#define AM_VIRTUAL_DEV_BASE_CLASS_H
#include "AM_VIRTUAL_CODEC_CLASS.h"

class AM_VIRTUAL_DEV_BASE_CLASS
{
public:
    AM_VIRTUAL_DEV_BASE_CLASS();
	virtual ~AM_VIRTUAL_DEV_BASE_CLASS();
	virtual int read(short * pBuffer, unsigned int length);
	virtual int write(short * pBuffer, unsigned int length);
	virtual int canWrite() = 0;
	virtual int canRead() = 0;
	virtual int bytesWritten() const;
	virtual int channels() const;
	virtual int frequency() const;
	virtual int bytesPerSample() const;
	virtual int bufferSize() const = 0;
	virtual int getVolume(unsigned int& left, unsigned int& right, bool& muted) = 0;
	virtual bool isMuted() = 0;
	virtual int increaseVolume() = 0;
	virtual int decreaseVolume() = 0;
	virtual int setVolume(int level) = 0;
	virtual int setMMVolume(int level) = 0;
	virtual int volumeChanged(bool muted) = 0;
	virtual int setAudioDevice(unsigned int, unsigned int, unsigned int) = 0;
	virtual int checkDevState();
	virtual int flush(void);
	virtual int bytesRendered() const;
	virtual int refresh(void);
	virtual int open();
	virtual int close();
	virtual int lock();
	virtual int unlock();
	virtual int pause();
	virtual int resume();
private:
    //AM_VIRTUAL_CODEC_CLASS *ptr;//0xD4;
};
#endif

