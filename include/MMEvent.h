

// Copyright (c) 12-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMEVENT_H 
#define MMEVENT_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMResult.h"
#include "MMGeneral.h"

class MMEventData;

enum 
{

    MMEVENT_PLAYER_LISTENER_GROUP_START = 0x00001000, 

    MMEVENT_BUFFERING_STARTED = MMEVENT_PLAYER_LISTENER_GROUP_START,

    MMEVENT_BUFFERING_STOPPED, 

    MMEVENT_DURATION_UPDATED, 

    MMEVENT_END_OF_MEDIA, 

    MMEVENT_DEVICE_UNAVAILABLE, 

    MMEVENT_DEVICE_AVAILABLE, 

    MMEVENT_ERROR, 

    MMEVENT_RECORDED_TOTAL_LENGTH,

    MMEVENT_RECORD_SAVE_COMPLETED,

    MMEVENT_RECORD_STARTED,

    MMEVENT_RECORD_STOPPED,

    MMEVENT_REC_VIDEO_PREVIEW_READY,

    MMEVENT_SNAPSHOT_PREVIEW_READY,

    MMEVENT_SNAPSHOT_WAIT_UNFREEZE,

    MMEVENT_SNAPSHOT_SHOOT_STOPPED,

    MMEVENT_CAPTURE_LIMIT_REACHED,

    MMEVENT_CAPTURE_ERROR,

    MMEVENT_VIEWFINDER_FRAME_READY,

    MMEVENT_FOCUS_STATUS,

    MMEVENT_ZOOM_CHANGED,

    MMEVENT_VIDEO_SIZE_CHANGED, 

    MMEVENT_STATE_CHANGED, 

    MMEVENT_STOPPED_AT_TIME,

    MMEVENT_VOLUME_CHANGED, 

    MMEVENT_LINK_ATTEMPTING,

    MMEVENT_LINK_ESTABLISHED,

    MMEVENT_CONTACTING, 

    MMEVENT_CONTACTED, 

    MMEVENT_BUFFERING, 

    MMEVENT_DOWNLOAD_COMPLETED, 

    MMEVENT_DOWNLOAD_PROGRESS, 

    MMEVENT_POSITION_CHANGED, 

    MMEVENT_SDP_TRACK_SELECTED,

    MMEVENT_SDP_TRACK_STARTED,

    MMEVENT_SDP_TRACK_STOPPED,

    MMEVENT_SDP_TRACK_REMOVED,

    MMEVENT_SEEKING_DONE,

    MMEVENT_MEDIA_PROCESSOR_LISTENER_GROUP_START = 0x00002000,

    MMEVENT_PROCESSOR_PROCESSING_ABORTED = MMEVENT_MEDIA_PROCESSOR_LISTENER_GROUP_START, 

    MMEVENT_PROCESSOR_PROCESSING_COMPLETED, 

    MMEVENT_PROCESSOR_PROCESSING_ERROR, 

    MMEVENT_PROCESSOR_PROCESSING_STARTED, 

    MMEVENT_PROCESSOR_PROCESSING_STOPPED, 

    MMEVENT_PROCESSOR_PROCESSOR_REALIZED, 

    MMEVENT_UNKNOWN

};

typedef int MMEventType;

class MMEvent
{
public:
    MMEvent(){}

    virtual ~MMEvent(){}

    virtual MMEvent & operator=(const MMEvent & other) = 0;

    virtual MMEvent* clone() = 0;

    virtual MMResult getEventData(MMEventData*& pr_eventData) = 0;

    virtual MMResult getEventType(MMEventType& r_eventType) = 0;

protected:

private:

};

#endif  