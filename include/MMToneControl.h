

// Copyright (c) 20-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMTONECONTROL_H 
#define MMTONECONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMResult.h"
#include "MMGeneral.h"

enum MMToneOperations
{
    MMTONE_REPEAT = -9,  
    MMTONE_SET_VOLUME = -8,   
    MMTONE_PLAY_BLOCK = -7,   
    MMTONE_BLOCK_END = -6,    
    MMTONE_BLOCK_START = -5,  
    MMTONE_RESOLUTION = -4,   
    MMTONE_TEMPO = -3,        
    MMTONE_VERSION = -2,      
    MMTONE_SILENCE = -1,      
    MMTONE_C4 = 60       
};
typedef char MMToneOperationType;

class MMToneControl 
{
public:
    virtual MMResult setSequence(const signed char *c_sequence, unsigned short length) = 0;

protected:
    virtual ~MMToneControl(){}

};

#endif  
