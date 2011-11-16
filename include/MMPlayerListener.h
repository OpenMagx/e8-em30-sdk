

// Copyright (c) 12-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMPLAYERLISTENER_H 
#define MMPLAYERLISTENER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMEvent.h"

class MMPlayer;

class MMPlayerListener
{
public:
    virtual void playerUpdate(const MMPlayer* cp_player, MMEvent *& pr_event) = 0;

protected:
    virtual ~MMPlayerListener(){}

private:

};

#endif  
