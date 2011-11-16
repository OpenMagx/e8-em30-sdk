

// Copyright (c) 15-Jun-04 - 2008 Motorola, Inc. All rights reserved.



#ifndef QT_NO_QWS_MMI_TEST
#ifndef QGFXPTF_QWS_H
#define QGFXPTF_QWS_H

#include "qobject.h"
#include "qpointarray.h"
#include <qsocketnotifier.h>
#include <qlock_qws.h>
#include "qsharedmemory.h"

#define PTF_PERF_MAX_NUM_RECORDS    125
#define PTF_PERF_RESP_HEADER_SIZE   12
#define PTF_PERF_RECORD_SIZE        16

#define PTF_PERF_FLAG_IDX           0

#define PTF_PERF_DATA_TYPE_IDX      10

#define PTF_PERF_CLIP_X_IDX         2
#define PTF_PERF_CLIP_Y_IDX         4
#define PTF_PERF_CLIP_WIDTH_IDX     6
#define PTF_PERF_CLIP_HEIGHT_IDX    8

#define PTF_PERF_RECORD_SIZE_IDX    (PTF_PERF_DATA_TYPE_IDX + 2)      

#define PTF_PERF_NUM_RECT_IDX       (PTF_PERF_RECORD_SIZE_IDX + 2)    

#define PTF_PERF_START_TIME_IDX     (PTF_PERF_NUM_RECT_IDX + 4)       

#define PTF_PERF_1ST_RECT_IDX       (PTF_PERF_START_TIME_IDX + 4)     

#define PTF_SIZE_SHM_PERF           PTF_PERF_1ST_RECT_IDX + \
                                    PTF_PERF_RECORD_SIZE * \
                                    PTF_PERF_MAX_NUM_RECORDS

static const int mouseBufSize = 128;

class QPtfLock
{
public:
    static bool _initLock( const QString &filename, bool create = FALSE );
    static bool _grabbed() { return _lock->locked(); }
    static void _grab() { if(_lock) _lock->lock( QLock::Read ); }
    static void _grab( bool write )
	{ if(_lock) _lock->lock( write ? QLock::Write : QLock::Read ); }
    static void _ungrab() { _lock->unlock(); }
    static void _deleteLock(){if(_lock) {delete _lock;_lock=0;}}

private:
    static QLock *_lock;
};

class QPTFServer : public QObject
{
    Q_OBJECT

public:

    QPTFServer();
    ~QPTFServer();
    static void startup();
    static QPTFServer * getInstance();
    int openDevice();
    int setDevice(char *devpath);
    void setupCmdMonitor();
    void removeCmdMonitor();
    void setupMouseHandler();
    void removeMouseHandler();
    void setupStrHandler();
    void removeStrHandler();
    void setupKeyHandler();
    void removeKeyHandler();
    void closeDevice();
    void sendEnd();
    void sendData();
    void sendPerformanceData();
    void sendImage();
    void sendData(QRect r, char t, UINT32 len,uchar * data,uint fgcolor, uint bgcolor, UINT32 len_resid, uchar * resid);

private slots:
    void processCmds();
    void readMouseData();
    void readStrData();
    void readKeyData();

private:
    int commandFD;
    int devFd;
    char *devPath;
    QSocketNotifier *commandNotifier;

    int mouseFD;
    QSocketNotifier *mouseNotifier;

    int strFD;
    QSocketNotifier *strNotifier;

    int keyFD;
    QSocketNotifier *keyNotifier;
	QSharedMemory shm_second_screen;

    QPointArray samples;
    unsigned int currSample;
    unsigned int lastSample;
    unsigned int numSamples;
    int skipCount;
    int mouseIdx;
    QPoint oldmouse;
    QPoint oldTotalMousePos;
    bool waspressed;
    unsigned short mouseBuf[mouseBufSize];
};

extern uchar *shmbuffer[2];
const int ptf_entry_num=128-1; 
const int ptf_entry_length=128;
const int ptf_size_shm=(ptf_entry_num+1) * ptf_entry_length;
const int ptf_last_block=ptf_entry_num * ptf_entry_length;

#define PTF_HEAD_LENGTH 10
#define PTF_DATA_PROTO 11

enum Last_block_data
{
    NEW_LAST_USEFUL_BLOCK = 36
};

#endif 

#endif 

