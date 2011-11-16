

// Copyright (c) 09-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef HSSYNCSTATEAPI_H
#define HSSYNCSTATEAPI_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qcopchannel_qws.h>
#define HSFWSYNC_CHANNEL "HSFRAMEWORK/SYNCING"

#define HS_BEGIN_SYNCING    "beginSyncing()"

#define HS_END_SYNCING       "endSyncing()"

class HSSyncStateAPI
{
public:
	static void HS_beginsync()
	{
		if( QCopChannel::isRegistered(HSFWSYNC_CHANNEL) )
        {
           QCopChannel::send(HSFWSYNC_CHANNEL, HS_BEGIN_SYNCING);
        }
	}

	static void HS_endsync()
	{
        if ( QCopChannel::isRegistered(HSFWSYNC_CHANNEL) )
        {
                QCopChannel::send(HSFWSYNC_CHANNEL, HS_END_SYNCING);
        }
    }

};
#endif  
