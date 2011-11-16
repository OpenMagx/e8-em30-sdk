

// Copyright (c)  - 2008 Motorola, Inc. All rights reserved.



#ifndef _NETMUX_LDPROTOCOL_H_
#define _NETMUX_LDPROTOCOL_H_

#define LDP_ERROR_NONE        0x00000000
#define LDP_ERROR_FATAL       0x00000001
#define LDP_ERROR_RECOVERABLE 0x00000002

#define LDP_INFORM_SHUTDOWN  0x00000001
#define LDP_INFORM_RECOVERED 0x00000002

typedef struct INTERFACELINK
{
    unsigned long (*LinkSend)   (void**, void*);
    unsigned long (*LinkInform) (void*, void*);

    unsigned long localMaxRcvSize;
    unsigned long remoteMaxRcvSize;
}INTERFACELINK;

typedef struct INTERFACEMUX
{
    unsigned long (*MUXReceive) (void*, void*);
    unsigned long (*MUXInform)  (void*, void*);

    void* id;
}INTERFACEMUX;

extern unsigned long RegisterMUXLink   (INTERFACELINK*, INTERFACEMUX*);
extern unsigned long UnregisterMUXLink (void*);

#endif
