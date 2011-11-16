

// Copyright (c) 23-May-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef VKM_CONFIG_H_
#define VKM_CONFIG_H_

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <map>
#include <list>
#include <string>

#include <errno.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <moto_input/vkm_ext.h>

#define MOTO_INPUT_KEY_TOTAL_KEY_SUPPORTED 128

using namespace std;

class MorphModeDef_t
{
public:
    MOTO_INPUT_KEY_BITMASK_T bitmask;   
    unsigned char vkMap[MOTO_INPUT_KEY_TOTAL_KEY_SUPPORTED];       
};

typedef map<int, MorphModeDef_t*> MorphDefTable_t;

typedef map<string, int> StartIndexTable_t;

class VKM_Config
{
public:
    VKM_Config();
    bool parse(void);
    int getMorphModeCount(void) { return this->morphModeCount; }    
    list<int> getMorphModeList(void);    
    int getKeyCount(void) { return this->keyCount; }
    MOTO_INPUT_KEY_BITMASK_ENTRY_T* getHapticMask() { return this->hapticBitmask; }
    MOTO_INPUT_AUTO_KEY_FILTER_T* getAutoFilterMask() { return &this->autoKeyBitmask; }
    MorphModeDef_t* getMorphDef( int modeId );
#if #FEAT_FORM_FACTOR(clamshell) || #FEAT_FORM_FACTOR(slider)
    MOTO_INPUT_AUTO_KEY_FILTER_T* getAutoFilterMask1() { return &this->autoKeyBitmask1; }
#endif

protected:
    bool readByte(int fd, unsigned char* pByte);
    bool readByteBuffer(int fd, unsigned char* pBuf, int size);
    string readString(int fd, int size);

    bool getDeviceInfo(void);

private:
    int keyCount;                       
    int morphModeCount;                 

    MOTO_INPUT_KEY_BITMASK_T hapticBitmask;         
    MOTO_INPUT_AUTO_KEY_FILTER_T autoKeyBitmask;    
#if #FEAT_FORM_FACTOR(clamshell) || #FEAT_FORM_FACTOR(slider)    
    MOTO_INPUT_AUTO_KEY_FILTER_T autoKeyBitmask1;    
#endif    
    MorphDefTable_t morphDefTable;                  
    list<int> morphModeList;                        

private:
    StartIndexTable_t startIndexTable;  
    int keyDeviceCountDriver;           

};

#endif 
