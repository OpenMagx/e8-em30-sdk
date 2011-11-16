#ifndef AM_VIRTUAL_CODEC_CLASS_H_
#define AM_VIRTUAL_CODEC_CLASS_H_

#include "AM_VIRTUAL_DEV_BASE_CLASS.h"
class AM_VIRTUAL_DEV_BASE_CLASS;  
class AM_VIRTUAL_CODEC_CLASS
{
public:
    AM_VIRTUAL_CODEC_CLASS();
	~AM_VIRTUAL_CODEC_CLASS();
	int getGEQStatus(bool& enabled);
	int setGEQStatus(bool enabled);
	int getAIEValue(int& currentLevel, int& maxLevel);
    int setAIEValue(int currentLevel, int maxLevel);
    int getAIEStatus(bool& enabled);
	int setAIEStatus(bool enabled);
    int getCodecType(int& codecType);
    int setCodecType(int codecType);
	int getBassboostValue(int& currentLevel, int& maxLevel);
	int setBassboostValue(int currentLevel, int maxLevel);
    int getGEQGainProfile(int& profileIndex);
    int setGEQGainProfile(int profileIndex);
    int getBassboostStatus(bool& enabled);
	int setBassboostStatus(bool enabled);
    int am_virtcodec_set_ptr(AM_VIRTUAL_DEV_BASE_CLASS* base);
    int am_virtcodec_set_params();
private:
    AM_VIRTUAL_DEV_BASE_CLASS *ptr;
    bool GEQ_enabled;//0x04 : 0
    int GEQ_profile;//0x08 : 1
    int GEQ_profile2;//0x0c : 0 == GEQ_profile
    bool AIE_enabled;//0x10 : 0
    int AIE_currentLevel;//0x14 : 1
    int AIE_maxLevel;//0x18 : 7
    int unknown;//0x1c : 0
    bool Bassboost_enabled;//0x20 : 0
    int Bassboost_currentLevel;//0x24 : 1
    int Bassboost_maxLevel;//0x28 : 7 
    int unknown2;//0x2c : 0
    int codecType;//0x30 : 3
};
#endif
