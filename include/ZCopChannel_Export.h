

// Copyright (c) 29-Apr-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef ZCopChannel_EXPORT_H
#define ZCopChannel_EXPORT_H

#include "ZCopChannel_Stream.h"
#ifdef __cplusplus
extern "C"
{
#endif

    enum {RunSockThread=1, AutoReconnect=2};

    int ZCopChannel_Init(int mode, void * notifyReconOverFn);

    int ZCopChannel_Close();

    int ZCopChannel_RegisterChannel(const char* chnName);

    int ZCopChannel_IsRegistered(const char* chnName);

    int ZCopChannel_UnregisterChannel(const char* chnName);

    typedef int (*ZCopChannel_ChnCallback)(const char *szChannel, const char* msgName,
                                           ZDataStream_Data* data, void * lpParam);

    int ZCopChannel_RegisterChnCallBack(const char* chnName, ZCopChannel_ChnCallback chnCallBack, void * lpParam);

    int ZCopChannel_UnregisterCallBack(const char* chnName, ZCopChannel_ChnCallback chnCallBack, void * lpParam);

    int ZCopChannel_SendMsg( const char* chnName, const char* msgName);

    int ZCopChannel_SendData( const char* chnName, const char* msgName, ZDataStream_Data* data);

    int ZCopChannel_Socket();

    int ZCopChannel_AsyncReceiveMsg();

    int ZCopChannel_syncReceiveMsg(const char* chnName, const char* msg, int timeout,
                                   int autoreset, ZDataStream_Data** data, int *cnt);

    void ZCopChannel_FreeSyncMsg(ZDataStream_Data* data, int cnt);

#ifdef __cplusplus
}
#endif

#endif
