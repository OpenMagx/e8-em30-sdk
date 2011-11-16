

// Copyright (c) 15-Jun-04 - 2008 Motorola, Inc. All rights reserved.



#ifndef QT_NO_QWS_MMI_TEST

#ifndef QPTF_H
#define  QPTF_H

#ifndef QT_H
#include "qglobal.h"
#include "qwidget.h"
#endif 

#ifdef PTF_USE_DEBUG
#define PTF_TRACE() \
    qDebug("PTF:LOG....%s,%s,%d\n",__FILE__,__FUNCTION__,__LINE__)
#define PTF_TRACE_STR(str) \
    qDebug("PTF:LOG....%s,%s,%d,%s\n",__FILE__,__FUNCTION__,__LINE__,str)
#define PTF_TRACE_INT(str,i) \
    qDebug("PTF:LOG....%s,%s,%d,%s %d\n",__FILE__,__FUNCTION__,__LINE__,str,i)
#else
#define PTF_TRACE()
#define PTF_TRACE_STR(str) 
#define PTF_TRACE_INT(str,i)
#endif

#define PTF_CHECKPTR(ptr) if ((ptr) == NULL) \
    { \
        qDebug("PTF:LOG....NULL pointer....%s,%s,%d\n",__FILE__,__FUNCTION__,__LINE__); \
        exit(-1); \
    }
#define PTF_LOG_ERRNO(str) \
    qDebug("PTF:LOG....%s, %s, %d, %s  Error is: %s\n",__FILE__,__FUNCTION__,__LINE__,str, strerror(errno))
#define PTF_LOG_ERR(str) \
    qDebug("PTF:LOG....%s,%s,%d,%s\n",__FILE__,__FUNCTION__,__LINE__,str)

#define PTF_LOG qDebug

class Q_EXPORT QPTF
{
public:
    QPTF(QWidget* qwidget);
    virtual ~QPTF();
    static bool       isFlexBitSet();
    virtual int        getPacketId(){ return 0;};
    virtual int        ptf_getState();
    virtual QRect   globalRect();
    virtual int        sendPackage();
    virtual int        sendPackage(int childno, QRect rtmp,int type_,int state_,QString qstrtmp,QString iconName_);
    virtual int        getPackageType();
    virtual QString getPtfText();
    virtual void      setPtfText(const QString &text);
    virtual const QPixmap * getPtfPixmap();
    virtual QString getPtfIconId();
    virtual void      setPtfIconId(const QString &iconid);
    unsigned char getTotalRectangle();
    static int   getWritePipe();
    static int   createWritePipe();
    static void closeWritePipe();
    int   fillInText(uchar * buff, QString qstrtmp);
    int   fillInIcon(uchar * buff, QString iconName_);
    int   fillInPayloadSend(uchar * buff,int payload);
    void fillInHeadTime(uchar * buff,int childno);
    void fillInRect(uchar * buff,QRect rtmp);
    void fillInRect(uchar * buff,int x,int y,int x2,int y2);
    void fillInType(uchar * buff);
    void fillInType(uchar * buff, int type);
    void fillInState(uchar * buff, int state);
    void fillInState(uchar * buff);
    void setPtfOverlay(const QString &overlaystr);
    void setPtfPixmap(const QPixmap &pixmap );
    void setPtfPixmap(const QString &pixmapstr );
    void setPackageType(int ptype);

    void report();
#ifndef QT_NO_RADIOBUTTON
    int  sendPackage_RadioButton();
#endif
#ifndef QT_NO_CHECKBOX
    int  sendPackage_CheckBox();
#endif
#ifndef QT_NO_BUTTON
    int  sendPackage_Button();
#endif
#ifndef QT_NO_SLIDER
    int  sendPackage_Slider();
#endif
    int  sendPackage_Base();

    static void sendEnd();
    static void decrePackNo();
    static void setPackNo(uchar packno);
    static uchar *_shmbuff;
    static uchar *_shm_perf_buff;
    QWidget *q;

protected:
    int packtype;
    QString ptftext;
    QString ptficon;
    QPixmap *ptfpixmap;
    QPixmap *ptfOverlay;
    int ptf_packet_Id;
    int _id_set;

private:
    static int ptf_pipe;
    static int _bflex;
    static int _flex_set;
};

#ifdef _WS_QWS_
#include "qgfx_qws.h"
#define ptfBlt( x, y, w, h,dst, src) \
    if((src) && (dst)) \
    { \
        QGfx* gfxptf = (dst)->graphicsContext();\
        if(gfxptf){  \
            gfxptf->setSource(src); \
            gfxptf->virtualBlt(x,y,w,h); \
            delete gfxptf; \
        } \
        if((dst)->width()<=(src)->width()) \
            (dst)->file_Name_ = (src)->file_Name_; \
    }
#else
#define ptfBlt( x, y, w, h,dst, src) \
    if((dst)->width()<=(src)->width()) \
    { \
        (dst)->file_Name_ = (src)->file_Name_; \
    }
#endif

typedef void (*QAutoBlendSrc2Dst)( int srcx, int srcy, int destx, int desty, int width, int height, unsigned char * src_buffer, unsigned char * dst_buffer, int highlight);
typedef void (*QAutoFreeObject)(unsigned char * address);
typedef void (*QAutoBlendToScreen)( int dx1, int dy1, int dx2, int dy2, char type_, unsigned short* wTextname, const char* strIconname, unsigned char * src_buffer, unsigned int highlight, int srcx, int srcy);
typedef void (*QAutoSetHighlight)(int state);

typedef struct
{
    QAutoFreeObject pfnFreeObject;		
    QAutoBlendSrc2Dst pfnBlendSrc2Dst;       
    QAutoBlendToScreen pfnBlendToScreen;	
    QAutoSetHighlight pfnSetHighlight;           
} QAutoCallbacks;

extern QAutoCallbacks *autocallback;

#endif  
#endif 

