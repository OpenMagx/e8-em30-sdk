

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#include "ZHeader.h"
#include <qstring.h>
#include <sys/types.h>

extern const char*   REG_CHANNEL_NAME;
extern const char*   BROADCAST_CHANNEL_NAME;

extern const char*   APP_STATUSCHANGE_MSG;
extern const char*   BROADCAST_STATUSCHANGE_MSG;
extern const char*   BROADCAST_SERVER_INITIALIZED_MSG;

#define SHM_READY 0x01234567
#define SHM_INITIAL 0x76543210

class RES_ICON_Reader;

class ZHeaderShareInfo {
public:
    static QPixmap getPixmap(const QString& strResID, bool returnNull = false);

    ZHeaderShareInfo(int statusSum = 0, int areaSum = 0, bool isCreated = false);
    ~ZHeaderShareInfo();
    bool attach();
    bool detach();
    bool release();
    int getShmStatus();
    int getStatusSum();
    int getStatusVal(int staIdx);
    QString getStatusIconName(int staIdx, ZHeader::HEADER_TYPE t);
    int getAreaSum();
    int getAreaNum(ZHeader::HEADER_TYPE t);
    QSize getAreaSize(ZHeader::HEADER_TYPE t, int areaIdx);
    int getAreaStatusIdx(ZHeader::HEADER_TYPE t, int areaIdx);
protected:
    friend class ZHeaderServer;
    bool setShmStatus(int f);
    bool setStatusSum(int sum);
    bool setStatusIdx(int idx, int staIdx);
    bool setStatusVal(int staIdx, int v);
    bool setStatusIconName(int staIdx, ZHeader::HEADER_TYPE t, QString& name);
    bool setAreaSum(int sum);
    bool setAreaNum(ZHeader::HEADER_TYPE t, int num);
    bool setAreaSize(ZHeader::HEADER_TYPE t, int areaIdx, const QSize& size);
    bool setAreaStatusIdx(ZHeader::HEADER_TYPE t, int areaIdx, int v);
private:
    int getOffsShmStatus();
    int getOffsStatusSum();
    int getOffsStatus(int staIdx);
    int getOffsAreaSum(int statusSum);
    int getOffsAreaNum(int statusSum, ZHeader::HEADER_TYPE t);
    int getOffsArea(int statusSum, ZHeader::HEADER_TYPE t, int areaIdx);
    int getShmSize(int statusSum, int areaSum);

    bool init(int statusSum, int areaSum, bool isCreated);
    bool getLock();
    bool lock();
    bool unlock();
private:
    key_t m_tok;
    int m_segmentID;
    void* m_pData;
    int m_fd;
    static RES_ICON_Reader *pResIconReader;
};
