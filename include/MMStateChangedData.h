

// Copyright (c) 20-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMSTATECHANGEDDATA_H 
#define MMSTATECHANGEDDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMEventData.h"
#include "MMPlayer.h"

enum MMStateTransitCauses
{
    MMTRANSIT_CAUSE_UNDEFINED = -1,
    MMTRANSIT_CAUSE_USERACTION = 0,
    MMTRANSIT_CAUSE_DEVICEUNAVAILABLE,
    MMTRANSIT_CAUSE_ENDOFMEDIA,
    MMTRANSIT_CAUSE_STOPPEDATTIME,
    MMTRANSIT_CAUSE_ERROR
};

typedef int MMStateTransitCauseType;

class MMStateChangedData: public MMEventData
{

public:
    MMStateChangedData(MMPlayerState curState, MMPlayerState preState, MMStateTransitCauseType cause);

    ~MMStateChangedData();

    virtual MMEventData * clone();

    MMPlayerState getCurrentState() const;

    MMPlayerState getPreviousState() const;

    MMStateTransitCauseType getTransitCause() const;

protected:

private:
    MMPlayerState a_currentState;
    MMPlayerState a_previousState;
    MMStateTransitCauseType a_transitCause;
};

#endif  

