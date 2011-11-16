

// Copyright (c) 20-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMMIDICONTROL_H 
#define MMMIDICONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMResult.h"
#include "MMGeneral.h"
#include "MMString.h"

enum MMMidiControls
{
    MMMIDI_CONTROL_CHANGE = 0xB0,  
    MMMIDI_NOTE_ON = 0x90          

};
typedef int MMMidiControlType;

class MMMidiControl 
{
public:
    virtual MMResult isBankQuerySupported(bool& r_supported) = 0;

    virtual MMResult getBankList(bool custom, int*& pr_bank, unsigned short& r_length) = 0;

    virtual MMResult getProgram(unsigned short channel, unsigned short& r_bank, unsigned short& r_program) = 0;

    virtual MMResult getProgramList(int bank,int*& pr_programlist, unsigned short& r_length) = 0;

    virtual MMResult getProgramName(unsigned short bank, unsigned short prog, MMString& r_program_name, unsigned short& r_length) = 0;

    virtual MMResult getKeyName(unsigned short bank, unsigned short prog, unsigned short key, MMString& r_key_name, unsigned short& r_length) = 0;

    virtual MMResult getChannelVolume(unsigned short channel, unsigned short& r_volume) = 0;

    virtual MMResult setChannelVolume(unsigned short channel, unsigned short volume) = 0;

    virtual MMResult setProgram(unsigned short channel, unsigned short bank, unsigned short program) = 0;

    virtual MMResult shortMidiEvent(MMMidiControlType type, unsigned short data1, unsigned short data2) = 0;

    virtual MMResult longMidiEvent(const MMString& cr_data, unsigned short offset, unsigned short length, unsigned short& r_actual_length) = 0;

protected:
    virtual ~MMMidiControl(){}

};

#endif  
