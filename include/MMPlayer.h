

// Copyright (c) 12-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMPLAYER_H 
#define MMPLAYER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMString.h"
#include "MMInterface.h"
#include "MMControllable.h"
#include "MMManager.h"

class MMPlayerListener;
class MMInputStream;

#define MMPLAYER_TIME_UNKNOWN  (-1) 

#define MM_MAX_LISTENERS           5

enum PlayerState
{
    MMPLAYER_STATE_UNREALIZED = 0,  

    MMPLAYER_STATE_REALIZED,

    MMPLAYER_STATE_PREFETCHED,

    MMPLAYER_STATE_STARTED,

    MMPLAYER_STATE_CLOSED,

    MMNUM_OF_PLAYERSTATES	
};

typedef int MMPlayerState;

class MMPlayer : public MMControllable
{
    friend class MMManager;

public:
    virtual MMResult addPlayerListener(MMPlayerListener* p_playerListener) = 0; 

    virtual MMResult removePlayerListener(MMPlayerListener* p_playerListener) = 0;

    virtual MMResult realize() = 0;

    virtual MMResult prefetch() = 0;

    virtual MMResult start() = 0;

    virtual MMResult stop() = 0;

    virtual MMResult deallocate() = 0;

    virtual MMResult close() = 0;

    virtual MMResult open(const MMString& cr_locator) = 0;

    virtual MMResult getContentType(MMString& r_contentType) = 0;

    virtual MMResult getDuration(MMTime& r_duration) = 0;    

    virtual MMResult getMediaTime(MMTime& r_mediaTime) = 0;

    virtual MMResult setMediaTime(MMTime mediaTime) = 0;

    virtual MMResult getState(MMPlayerState& r_state) = 0;

protected:
    virtual ~MMPlayer(){}

private:
    virtual MMResult initialize(const MMString& cr_locator, int featureHandle) = 0;

    virtual MMResult initialize(MMInputStream * p_source, int featureHandle) = 0;

    virtual MMResult uninitialize() = 0;

};

#endif  
