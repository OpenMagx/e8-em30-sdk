

// Copyright (c) 29-Apr-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef ZDATASTREAM_H
#define ZDATASTREAM_H

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct ZDataStream_Data_T
    {
        char* dataStr;
        int dataLen;
        int index;
        int byteOrder;
    }
    ZDataStream_Data;

    int ZDataStream_init(ZDataStream_Data* data, const char* dataStr, int dataLen);

    void ZDataStream_close(ZDataStream_Data* data);

    int ZDataStream_readRawBytes(ZDataStream_Data* data, char** buf, int len);

    int ZDataStream_writeRawBytes(ZDataStream_Data* data, char* pRawData, int len);

    int ZDataStream_setByteOrder(ZDataStream_Data* data, int order);

    int ZDataStream_GetChar(ZDataStream_Data* data, char* ch);

    int ZDataStream_SetChar(ZDataStream_Data* data, char ch);

    int ZDataStream_GetUChar(ZDataStream_Data* data, unsigned char* ch);

    int ZDataStream_SetUChar(ZDataStream_Data* data, unsigned char ch);

    int ZDataStream_GetShort(ZDataStream_Data* data, short* i);

    int ZDataStream_SetShort(ZDataStream_Data* data, short i);

    int ZDataStream_GetUShort(ZDataStream_Data* data, unsigned short* i);

    int ZDataStream_SetUShort(ZDataStream_Data* data, unsigned short i);

    int ZDataStream_GetInt(ZDataStream_Data* data, int* i);

    int ZDataStream_SetInt(ZDataStream_Data* data, int i);

    int ZDataStream_GetUInt(ZDataStream_Data* data, unsigned int* i);

    int ZDataStream_SetUInt(ZDataStream_Data* data, unsigned int i);

    int ZDataStream_GetLong(ZDataStream_Data* data, long* i);

    int ZDataStream_SetLong(ZDataStream_Data* data, long i);

    int ZDataStream_GetULong(ZDataStream_Data* data, unsigned long* i);

    int ZDataStream_SetULong(ZDataStream_Data* data, unsigned long i);

    int ZDataStream_GetQCString(ZDataStream_Data* data, char** str, int* len);

    int ZDataStream_SetQCString(ZDataStream_Data* data, char* str, int len);

    int ZDataStream_GetQString(ZDataStream_Data* data, unsigned short** str, int* len);

    int ZDataStream_SetQString(ZDataStream_Data* data, unsigned short* str, int len);

    void ZDataStream_FreeString(void * str);

#ifdef __cplusplus
}
#endif

#endif
