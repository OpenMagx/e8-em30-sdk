
/*
 * Copyright (C) 2007 Motorola Inc.
 *
 * Date         Author         Comment
 * 09/25/07     Motorola       Motorola customization.
*/

/****************************************************************************
** $Id: qt/src/kernel/qgfx_qws.h   2.3.8   edited 2004-08-05 $
**
** Definition of QGfx (graphics context) class
**
** Created : 940721
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of the kernel module of the Qt GUI Toolkit.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** Licensees holding valid Qt Enterprise Edition or Qt Professional Edition
** licenses for Qt/Embedded may use this file in accordance with the
** Qt Embedded Commercial License Agreement provided with the Software.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.trolltech.com/pricing.html or email sales@trolltech.com for
**   information about Qt Commercial License Agreements.
** See http://www.trolltech.com/gpl/ for GPL licensing information.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

#ifndef QGFX_H2
#define QGFX_H2

#ifndef QT_H
#include "qwidget.h"
#include "qnamespace.h"
#include "qimage.h"
#include "qfontmanager_qws.h"
#endif // QT_H

class QSharePixmap;
#include <stdio.h>
#if !defined( QT_NO_IMAGE_16_BIT ) || !defined( QT_NO_QWS_DEPTH_16 )
# ifndef QT_QWS_DEPTH16_RGB
#  define QT_QWS_DEPTH16_RGB 565
# endif
static const int qt_rbits = (QT_QWS_DEPTH16_RGB/100);
static const int qt_gbits = (QT_QWS_DEPTH16_RGB/10%10);
static const int qt_bbits = (QT_QWS_DEPTH16_RGB%10);
static const int qt_red_shift = qt_bbits+qt_gbits-(8-qt_rbits);
static const int qt_green_shift = qt_bbits-(8-qt_gbits);
static const int qt_neg_blue_shift = 8-qt_bbits;
static const int qt_blue_mask = (1<<qt_bbits)-1;
static const int qt_green_mask = (1<<(qt_gbits+qt_bbits))-((1<<qt_bbits)-1);
static const int qt_red_mask = (1<<(qt_rbits+qt_gbits+qt_bbits))-(1<<(qt_gbits+qt_bbits));

inline ushort qt_convRgbTo16( const int r, const int g, const int b )
{
    const int tr = r << qt_red_shift;
    const int tg = g << qt_green_shift;
    const int tb = b >> qt_neg_blue_shift;

    return (tb & qt_blue_mask) | (tg & qt_green_mask) | (tr & qt_red_mask);
}

inline ushort qt_convRgbTo16( QRgb c )
{
    const int tr = qRed(c) << qt_red_shift;
    const int tg = qGreen(c) << qt_green_shift;
    const int tb = qBlue(c) >> qt_neg_blue_shift;

    return (tb & qt_blue_mask) | (tg & qt_green_mask) | (tr & qt_red_mask);
}

inline QRgb qt_conv16ToRgb( ushort c )
{
    const int r=(c & qt_red_mask);
    const int g=(c & qt_green_mask);
    const int b=(c & qt_blue_mask);
    const int tr = r >> qt_red_shift;
    const int tg = g >> qt_green_shift;
    const int tb = b << qt_neg_blue_shift;

    return qRgb(tr,tg,tb);
}

inline void qt_conv16ToRgb( ushort c, int& r, int& g, int& b )
{
    const int tr=(c & qt_red_mask);
    const int tg=(c & qt_green_mask);
    const int tb=(c & qt_blue_mask);
    r = tr >> qt_red_shift;
    g = tg >> qt_green_shift;
    b = tb << qt_neg_blue_shift;
}
#endif

#ifdef QT_NO_QWS_DEPTH_18
#define QT_NO_IMAGE_18_BIT
#endif

#ifndef QT_NO_QWS_DEPTH_18
#define DEPTH_18BPP 18
#define BYTES_PER_PIXEL_18BPP 3
static const int qt_rbits_18bpp = 6;
static const int qt_gbits_18bpp = 6;
static const int qt_bbits_18bpp = 6;
static const int qt_red_shift_18bpp = qt_bbits_18bpp+qt_gbits_18bpp-(8-qt_rbits_18bpp);
static const int qt_green_shift_18bpp = qt_bbits_18bpp-(8-qt_gbits_18bpp);
static const int qt_neg_blue_shift_18bpp = 8-qt_bbits_18bpp;
static const int qt_blue_mask_18bpp = (1<<qt_bbits_18bpp)-1;
static const int qt_green_mask_18bpp = (1<<(qt_gbits_18bpp+qt_bbits_18bpp))-((1<<qt_bbits_18bpp)-1);
static const int qt_red_mask_18bpp = (1<<(qt_rbits_18bpp+qt_gbits_18bpp+qt_bbits_18bpp))-(1<<(qt_gbits_18bpp+qt_bbits_18bpp));

inline unsigned int qt_convRgbTo18( const int r, const int g, const int b )
{
    const int tr = r << qt_red_shift_18bpp;
    const int tg = g << qt_green_shift_18bpp;
    const int tb = b >> qt_neg_blue_shift_18bpp;

    return (tb & qt_blue_mask_18bpp) | (tg & qt_green_mask_18bpp) | (tr & qt_red_mask_18bpp);
}

inline unsigned int qt_convRgbTo18( QRgb c )
{
    const int tr = qRed(c) << qt_red_shift_18bpp;
    const int tg = qGreen(c) << qt_green_shift_18bpp;
    const int tb = qBlue(c) >> qt_neg_blue_shift_18bpp;

    return (tb & qt_blue_mask_18bpp) | (tg & qt_green_mask_18bpp) | (tr & qt_red_mask_18bpp);
}

inline QRgb qt_conv18ToRgb( unsigned int c )
{
    const int r=(c & qt_red_mask_18bpp);
    const int g=(c & qt_green_mask_18bpp);
    const int b=(c & qt_blue_mask_18bpp);
    const int tr = r >> qt_red_shift_18bpp;
    const int tg = g >> qt_green_shift_18bpp;
    const int tb = b << qt_neg_blue_shift_18bpp;

    return qRgb(tr,tg,tb);
}

inline void qt_conv18ToRgb( unsigned int c, unsigned int &r, \
		unsigned int &g, unsigned int &b )
{
    const int tr=(c & qt_red_mask_18bpp);
    const int tg=(c & qt_green_mask_18bpp);
    const int tb=(c & qt_blue_mask_18bpp);
    r = tr >> qt_red_shift_18bpp;
    g = tg >> qt_green_shift_18bpp;
    b = tb << qt_neg_blue_shift_18bpp;
}

//to suppor lcd overlay
//type = 0 : copy(default).
//type = 1 : set T = 1;
inline void gfxSet18bpp( unsigned char *d, unsigned int n, unsigned int t)
{
    /*if(t == 0)
    {
        *(d) = n & 0xff;
        *(d+1) = (n>>8) & 0xff;
        *(d+2) = (*(d+2) & 0xfc ) | ( (n >> 16) & 0x3 );
    }*/
    if( t == 1 )
    {
        *(d) = n & 0xff;
        *(d+1) = (n >> 8) & 0xff;
        *(d+2) = ( (n >> 16) & 0x3 ) | 0x4;
    }
    else
{
    memcpy(d, &n, BYTES_PER_PIXEL_18BPP);
    }
    
#if 0
    *(d) = n&0xff;
    *(d+1) = n&0xff00 >> 8;
    *(d+2) = n&0x30000 >>16;
#endif
}

inline void gfxSet18bpp( unsigned char *d, int r, int g, int b, unsigned int t)
{
    unsigned int p;
    p = qt_convRgbTo18(r,g,b);
    gfxSet18bpp(d,p, t);
}

inline QRgb gfxGet18bpp_RGB( unsigned char *d)
{
    unsigned int p;
    QRgb ret;
    p = ((((*(d+2)) & 0x3) <<16) | (*(d+1)<<8) | (*d));
    ret = qt_conv18ToRgb(p);
    return ret;
}

inline unsigned int gfxGet18bpp( unsigned char *d)
{
   unsigned int p;
   p = ((((*(d+2)) & 0x3) <<16) | (*(d+1)<<8) | (*d));
   return p;
}
#endif

//=====  BGRA
#ifdef QT_NO_QWS_DEPTH_24_ALPHA
#define QT_NO_IMAGE_24_ALPHA
#endif

#ifndef QT_NO_QWS_DEPTH_24_ALPHA
#define DEPTH_24_ALPHA 24
#define BYTES_PER_PIXEL_24_ALPHA 3 
static const int qt_abits_24alpha = 6;
static const int qt_rbits_24alpha = 6;
static const int qt_gbits_24alpha = 6;
static const int qt_bbits_24alpha = 6;
static const int qt_red_shift_24alpha = qt_bbits_24alpha+qt_gbits_24alpha-(8-qt_rbits_24alpha);
static const int qt_green_shift_24alpha = qt_bbits_24alpha-(8-qt_gbits_24alpha);
static const int qt_neg_blue_shift_24alpha = 8-qt_bbits_24alpha;
static const int qt_blue_mask_24alpha = (1<<qt_bbits_24alpha)-1;
static const int qt_green_mask_24alpha = (1<<(qt_gbits_24alpha+qt_bbits_24alpha))-((1<<qt_bbits_24alpha)-1);
static const int qt_red_mask_24alpha = (1<<(qt_rbits_24alpha+qt_gbits_24alpha+qt_bbits_24alpha))-(1<<(qt_gbits_24alpha+qt_bbits_24alpha));

static const int alpha_mask = 0xfc0000;
static const int alpha_shift = 16;

/*
qt_red_shift_24alpha = 10
qt_green_shift_24alpha = 4
qt_neg_blue_shift_24alpha = 2
qt_blue_mask_24alpha = 011 1111
qt_green_mask_24alpha = 1111 1100 0001
qt_red_mask_24alpha = 11 1111 0000 0000 0000
*/

// get the first 6 bits of a, r, g, b

inline unsigned int qt_convRgbTo24alpha( const int r, const int g, const int b )
{
    const int tr = r << qt_red_shift_24alpha; 
    const int tg = g << qt_green_shift_24alpha;
    const int tb = b >> qt_neg_blue_shift_24alpha;
    
    return (tb & qt_blue_mask_24alpha) | (tg & qt_green_mask_24alpha) | (tr & qt_red_mask_24alpha) | alpha_mask;
}
inline unsigned int qt_convRgbaTo24alpha( const int a, const int r, const int g, const int b )
{
    const int ta = a << alpha_shift;
    const int tr = r << qt_red_shift_24alpha; 
    const int tg = g << qt_green_shift_24alpha;
    const int tb = b >> qt_neg_blue_shift_24alpha;

    return (tb & qt_blue_mask_24alpha) | (tg & qt_green_mask_24alpha) | (tr & qt_red_mask_24alpha) | (ta & alpha_mask);
}



inline unsigned int qt_convRgbTo24alpha( QRgb c )
{
    const int tr = qRed(c) << qt_red_shift_24alpha;
    const int tg = qGreen(c) << qt_green_shift_24alpha;
    const int tb = qBlue(c) >> qt_neg_blue_shift_24alpha;

    return (tb & qt_blue_mask_24alpha) | (tg & qt_green_mask_24alpha) | (tr & qt_red_mask_24alpha) | alpha_mask;
}
inline unsigned int qt_convRgbaTo24alpha( QRgb c )
{
    const int ta = qAlpha(c) << alpha_shift;
    const int tr = qRed(c) << qt_red_shift_24alpha;
    const int tg = qGreen(c) << qt_green_shift_24alpha;
    const int tb = qBlue(c) >> qt_neg_blue_shift_24alpha;

    return (tb & qt_blue_mask_24alpha) | (tg & qt_green_mask_24alpha) | (tr & qt_red_mask_24alpha) | (ta & alpha_mask);
}



inline QRgb qt_conv24alphaToRgb( unsigned int c )
{
    const int r=(c & qt_red_mask_24alpha);
    const int g=(c & qt_green_mask_24alpha);
    const int b=(c & qt_blue_mask_24alpha);

    const int tr = r >> qt_red_shift_24alpha;
    const int tg = g >> qt_green_shift_24alpha;
    const int tb = b << qt_neg_blue_shift_24alpha;

    return qRgb(tr,tg,tb);  // (ta=ff tr=r00 tg=g00 tb=b00)
}
inline QRgb qt_conv24alphaToRgba( unsigned int c )
{
    const int a=(c & alpha_mask);
    const int r=(c & qt_red_mask_24alpha);
    const int g=(c & qt_green_mask_24alpha);
    const int b=(c & qt_blue_mask_24alpha);

    int ta = a >> alpha_shift;
    if (ta==0xfc) ta = 0xff;    // boundary condition, 252->255

    const int tr = r >> qt_red_shift_24alpha;
    const int tg = g >> qt_green_shift_24alpha;
    const int tb = b << qt_neg_blue_shift_24alpha;

    return qRgba(tr,tg,tb,ta);  // (ta=a00 tr=r00 tg=g00 tb=b00)
}



inline void qt_conv24alphaToRgb( unsigned int c, unsigned int &r, \
                unsigned int &g, unsigned int &b )
{
    const int tr=(c & qt_red_mask_24alpha);
    const int tg=(c & qt_green_mask_24alpha);
    const int tb=(c & qt_blue_mask_24alpha);
    r = tr >> qt_red_shift_24alpha;
    g = tg >> qt_green_shift_24alpha;
    b = tb << qt_neg_blue_shift_24alpha;
}

inline void qt_conv24alphaToRgba( unsigned int c, unsigned int &a, unsigned int &r, \
                unsigned int &g, unsigned int &b)
{
    const int ta=(c & alpha_mask);
    const int tr=(c & qt_red_mask_24alpha);
    const int tg=(c & qt_green_mask_24alpha);
    const int tb=(c & qt_blue_mask_24alpha);

    a = ta >> alpha_shift;
    if (a==0xfc) a = 0xff;    // boundary condition, 252->255

    r = tr >> qt_red_shift_24alpha;
    g = tg >> qt_green_shift_24alpha;
    b = tb << qt_neg_blue_shift_24alpha;
}



inline void gfxSet24alpha( unsigned char *d, unsigned int n, unsigned int /*t*/)
{
    *d = n & 0x0000ff;
    *(d+1) = (n & 0x00ff00 ) >> 8;
    *(d+2) = (n & 0xff0000 ) >> 16;

    //memcpy(d, &n, 3);
}
inline void gfxSet24alpha( unsigned char *d, int a, int r, int g, int b, unsigned int t)
{
    unsigned int p;
    p = qt_convRgbaTo24alpha(a,r,g,b);
    gfxSet24alpha(d,p, t);
}



inline QRgb gfxGet24alpha_RGB( unsigned char *d)
{
    unsigned int p;
    QRgb ret; 
    p = ((*(d+2)<<16) | (*(d+1)<<8) | (*d));
    ret = qt_conv24alphaToRgb(p);
    return ret;
}
inline QRgb gfxGet24alpha_RGBA( unsigned char *d)
{
    unsigned int p;
    QRgb ret;
    p = ((*(d+2)<<16) | (*(d+1)<<8) | (*d));
    ret = qt_conv24alphaToRgba(p);
    return ret;
}


inline unsigned int gfxGet24alpha( unsigned char *d)
{
   unsigned int p;
   p = ((*(d+2) <<16) | (*(d+1)<<8) | (*d));
   return p;
}

#endif //!QT_NO_QWS_DEPTH_24_ALPHA
//=====




const int SourceSolid=0;
const int SourcePixmap=1;

#ifndef QT_NO_QWS_CURSOR

extern bool qt_sw_cursor;

class QGfxRasterBase;

#define SW_CURSOR_DATA_SIZE	4096  // 64x64 8-bit cursor

class SWCursorData;

class QScreenCursor
{
public:
    QScreenCursor( );
    virtual ~QScreenCursor();

    virtual void init(SWCursorData *da, bool init = FALSE);

    virtual void set( const QImage &image, int hotx, int hoty );
    virtual void move( int x, int y );
    virtual void show();
    virtual void hide();

    virtual bool restoreUnder( const QRect &r, QGfxRasterBase *g = 0 );
    virtual void saveUnder();
    virtual void drawCursor();
    void draw();
    virtual bool supportsAlphaCursor();

    static bool enabled() { return qt_sw_cursor; }

protected:
    QGfxRasterBase *gfx;
    QGfxRasterBase *gfxunder;

    QImage *imgunder;
    const QImage *cursor;

    uchar *fb_start;
    uchar *fb_end;
    bool save_under;
    SWCursorData *data;

    int clipWidth;
    int clipHeight;
    int myoffset;

};

extern QScreenCursor * qt_screencursor;

#endif // QT_NO_QWS_CURSOR

struct fb_cmap;

// A (used) chunk of offscreen memory

class QPoolEntry
{
public:
    unsigned int start;
    unsigned int end;
    int clientId;
};

// To support LCD overlay
class QLCDLayer {

    enum LayerIndex
    {
        LAYER1 = 0,
        LAYER2 = 1
    };
    
public:
    QLCDLayer(LayerIndex index = LAYER2);
    ~QLCDLayer();

    LayerIndex index(){ return layerIndex; }
    
    bool isHardwareSupport(){ return hardwareSupported; }
    void setHardwareSupport(bool isHardwareSupported)
        { hardwareSupported = isHardwareSupported; }
    
    void open();
    void close();

    // tranparentLevel valid values:
    // 0: k1=k2=k3 = 1/8
    // 1: k1=k2=k3 = 2/8
    // 2: k1=k2=k3 = 3/8
    // 3: k1=k2=k3 = 4/8
    // 4: k1=k2=k3 = 5/8
    // 5: k1=k2=k3 = 6/8
    // 6: k1=k2=k3 = 7/8
    // 7: k1=k2=k3 = 1
    // default k1=k2=k3= 4/8
    //
    // The trasparency algorithm is
    // R = BaseR * k1 + OverlayR * (1 - K1)
    // G = BaseG * k2 + OverlayG * (1 - K2)
    // B = BaseB * k3 + OverlayB * (1 - K3)

    int transparentLevel(){ return transLevel; }
    void setTransparentLevel(int level){ transLevel = level; }
    
    bool isEnabled(){ return enabled; }
    void enable();
    void disable();

    unsigned char * base();
    unsigned char * back();
    int cbOffset(){ return cboff; }
    int crOffset(){ return croff; }

    bool isDoubleBufferEnabled(){ return doubleBufferEnabled; }
    void enableDoubleBuffer();
    void disableDoubleBuffer();

    void flip();

    void resetRegion(int x, int y, int w, int h); 
    int OverlayDepth() { return depth; }
    int OverlayPixelType() { return pixeltype; }

#ifndef QT_NO_QWS_DEPTH_18
    void setTBitOfBase(int x, int y, int w, int h);
    void clearTBitOfBase(int x, int y, int w, int h);
#endif
    
private:
    int fd;
    LayerIndex layerIndex;
    bool hardwareSupported;
    bool enabled;
    bool doubleBufferEnabled;

    unsigned char * frame[2];
    int currentFrameIndex;

    int cboff;
    int croff;

    int transLevel;

    int depth;

    // 0:BGR888  1:BGRA6666  2:RGB888 
    int pixeltype; 
};

class QScreen;
typedef void(*ClearCacheFunc)(QScreen *obj, int);

class QScreen {
public:
    enum
    {
        DEFAULT_SCREEN = 0,    // not definitely ensure to get on or off screen, must refer calling code context
        ON_SCREEN = 1,         // ensure to get front or on screen gfx
        OFF_SCREEN = 2,        // ensure to get back or off screen gfx
    };
                                     
    
    QScreen( int display_id );
    virtual ~QScreen();
    virtual bool initDevice() = 0;
    virtual bool connect( const QString &displaySpec ) = 0;
    virtual void disconnect() = 0;
    virtual int initCursor(void *, bool=FALSE);
    virtual void shutdownDevice();
    virtual void setMode(int,int,int) = 0;
    virtual bool supportsDepth(int) const;
    virtual QGfx * createGfx(unsigned char *,int,int,int,int);

    // add flag for get front/back (on/offScreen) Gfx
    // Do not use other flag parameter than DEFAULT_SCREEN, unless you know what you are doing!
    // Just call this function as before by "screenGfx()"
    virtual QGfx * screenGfx(int flag = DEFAULT_SCREEN);
#ifndef QT_NO_QWS_FADEBACKGROUND
    virtual QGfx * offScreenGfx();  // special function used for off screen gfx, used by fade background
    // This function is used by QFadeBackground double buffering scheme
    // unless you know what you are doing DO NOT call this function!
    QPixmap * offScreenPixmap();   
#endif

    virtual void save();
    virtual void restore();
    virtual void blank(bool on);

    virtual int pixmapOffsetAlignment() { return 64; }
    virtual int pixmapLinestepAlignment() { return 64; }

    virtual bool onCard(unsigned char *) const;
    virtual bool onCard(unsigned char *, ulong& out_offset) const;

    // sets a single color in the colormap
    virtual void set(unsigned int,unsigned int,unsigned int,unsigned int);
    // allocates a color
    virtual int alloc(unsigned int,unsigned int,unsigned int);

    int width() const { return w; }
    int height() const { return h; }
    int depth() const { return d; }
    virtual int pixmapDepth() const;
    int pixelType() const { return pixeltype; }
    int linestep() const { return lstep; }
    int deviceWidth() const { return dw; }
    int deviceHeight() const { return dh; }
    uchar * base() const { return data; }
    // Ask for memory from card cache with alignment
    virtual uchar * cache(int,int) { return 0; }
    virtual void uncache(uchar *) {}

    int screenSize() const { return size; }
    int totalSize() const { return mapsize; }

    QRgb * clut() { return screenclut; }
    int numCols() { return screencols; }

    virtual QSize mapToDevice( const QSize & ) const;
    virtual QSize mapFromDevice( const QSize & ) const;
    virtual QPoint mapToDevice( const QPoint &, const QSize & ) const;
    virtual QPoint mapFromDevice( const QPoint &, const QSize & ) const;
    virtual QRect mapToDevice( const QRect &, const QSize & ) const;
    virtual QRect mapFromDevice( const QRect &, const QSize & ) const;
    virtual QImage mapToDevice( const QImage & ) const;
    virtual QImage mapFromDevice( const QImage & ) const;
    virtual QRegion mapToDevice( const QRegion &, const QSize & ) const;
    virtual QRegion mapFromDevice( const QRegion &, const QSize & ) const;
    virtual int transformOrientation() const;
    virtual bool isTransformed() const;

    virtual bool isInterlaced() const;

    //
    // MOTOROLA -- Double buffering changes
    //

    // 
    // canFlip - returns true if this device supports double-buffering
    //
    
    virtual bool canFlip() const { return false; }

    //
    // enableFlipping
    //
    // makes Qt start drawing to the back buffer
    //
    
    virtual bool enableFlipping(QWidget *) { return false; }

    //
    // flippingEnabled
    //
    // returns true if flipping is enabled
    //

    virtual bool flippingEnabled() const { return false; }
    
    //
    // disableFlipping
    //
    // has Qt start drawing to the front buffer
    //
    
    virtual void disableFlipping() { }

    //
    // back - returns a pointer to the current back buffer
    //
    // If flipping is disabled or not available, this returns the base()
    //
    
    virtual uchar* back() { return base(); }

    //
    // flip
    //
    // displays the back buffer on the screen.
    //
    // If there are any widgets on top of widget passed into enableFlipping(),
    // flip() will use Qt's region manager to clip the output.
    //
    
    virtual bool flip() { return false; }

    //
    // sets render destination
    //

    virtual bool redirectQtToBack(bool) { return false; };
    
    //
    // MOTOROLA -- End double buffering changes
    //
    
    // MOTORLA -- LCD Overlay support
    
    QLCDLayer* layer2(){ return &lcdLayer2; }

    // MOTOROLA -- FOR MEDL SUPPORT
    
    virtual bool refresh(int,int,int,int) { return true; };

protected:
    QLCDLayer lcdLayer2;

    QRgb screenclut[256];
    int screencols;

    bool initted;

    uchar * data;

    // Table of allocated lumps, kept in sorted highest-to-lowest order
    // The table itself is allocated at the bottom of offscreen memory
    // i.e. it's similar to having a stack (the table) and a heap
    // (the allocated blocks). Freed space is implicitly described
    // by the gaps between the allocated lumps (this saves entries and
    // means we don't need to worry about coalescing freed lumps)

    QPoolEntry * entries;
    int * entryp;
    unsigned int * lowest;

    int w;
    int lstep;
    int h;
    int d;

    // 0:BGR888  1:BGRA6666  2:RGB888 
    int pixeltype;  
    
    int dw;
    int dh;

    int hotx;
    int hoty;
    QImage cursor;

    int size;	       // Screen size
    int mapsize;       // Total mapped memory


    friend class QWSServer;
    static ClearCacheFunc clearCacheFunc;

    // to realize the fade window background, create a offScreenPixmap to simulate the on screen framebuffer
#ifndef QT_NO_QWS_FADEBACKGROUND
    QSharePixmap* pSharePixmap;   // QSharePixmap, a share memory pixmap manager, for offscreen pixmap
    QPixmap *offScreenPM;       // The pointer of shared offscreen pixmap
#endif
    
};

extern QScreen * qt_screen;

class Q_EXPORT QGfx : public Qt 
{
   friend class QScreen; 
public:
    // With loadable drivers, do probe here
    static QGfx *createGfx( int depth, unsigned char *buffer,
			    int w, int h, int linestep );

    virtual ~QGfx(); 

    virtual void setPen( const QPen & )=0;
    virtual void setFont( const QFont & )=0;
    virtual void setBrush( const QBrush & )=0;
    virtual void setBrushPixmap( const QPixmap * )=0;
    virtual void setBrushOffset( int, int ) = 0;
    virtual void setClipRect( int,int,int,int )=0;
    virtual void setClipRegion( const QRegion & )=0;
    virtual void setClipDeviceRegion( const QRegion & )=0;
    virtual void setClipping (bool)=0;
    // These will be called from qwidget_qws or qwidget_mac
    // to update the drawing area when a widget is moved
    virtual void setOffset( int,int )=0;
    virtual void setWidgetRect( int,int,int,int )=0;
    virtual void setWidgetRegion( const QRegion & )=0;
    virtual void setWidgetDeviceRegion( const QRegion & )=0;
    virtual void setSourceWidgetOffset(int x, int y) = 0;
    virtual void setGlobalRegionIndex( int idx ) = 0;

    virtual void setDashedLines(bool d) = 0;
    virtual void setDashes(char *, int) = 0;

    virtual void setOpaqueBackground(bool b)=0;
    virtual void setBackgroundColor(QColor c)=0;

    // Drawing operations
    virtual void drawPoint( int,int )=0;
    virtual void drawPoints( const QPointArray &,int,int )=0;
    virtual void moveTo( int,int )=0;
    virtual void lineTo( int,int )=0;
    virtual void drawLine( int,int,int,int )=0;
    virtual void drawPolyline( const QPointArray &,int,int )=0;

    // Fill operations - these use the current source (pixmap,
    // color, etc), and draws outline
    virtual void fillRect( int,int,int,int )=0;
#ifdef QT_BLEND_WALLPAPER
    virtual void eraseRect( int,int,int,int,int,const QPixmap* )=0; 
#endif
    virtual void drawPolygon( const QPointArray &,bool,int,int )=0;

    virtual void setLineStep(int)=0;

    // Special case of rect-with-pixmap-fill for speed/hardware acceleration
    virtual void blt( int,int,int,int,int,int )=0;
    virtual void scroll( int,int,int,int,int,int )=0;

#if !defined(QT_NO_MOVIE) || !defined(QT_NO_TRANSFORMATIONS) || !defined(QT_NO_PIXMAP_TRANSFORMATION)
    virtual void stretchBlt( int,int,int,int,int,int )=0;
#endif
    virtual void tiledBlt( int,int,int,int )=0;

#ifndef QT_NO_QWS_MMI_TEST
    virtual void virtualBlt( int,int,int,int ){};
#endif

    enum SourceType { SourcePen, SourceImage, SourceAccel };
    enum PixelType { BGRA6666Pixel, NormalPixel, BGRPixel }; 

    // Setting up source data - can be solid color or pixmap data
    virtual void setSource(const QPaintDevice *)=0;
    virtual void setSource(const QImage *)=0;
    // This one is pen
    virtual void setSourcePen()=0;

    virtual void drawAlpha(int,int,int,int,int,int,int,int) {}

    virtual void hsync(int) {}

    // These apply only to blt's. For alpha values for general
    // drawing operations we should probably have a separate QGfx
    // class. It's not a high priority though.

    // Enum values: Ignore alpha information, alpha information encoded in
    // 32-bit rgba along with colors, alpha information in 8bpp
    // format in alphabits

    enum AlphaType { IgnoreAlpha, InlineAlpha, SeparateAlpha,
                     LittleEndianMask, BigEndianMask, SolidAlpha };

    // Can be no alpha, inline (32bit data), separate (for images),
    // LittleEndianMask/BigEndianMask 1bpp masks, constant alpha
    // value
    virtual void setAlphaType(AlphaType)=0;
    // Pointer to data, linestep
    virtual void setAlphaSource(unsigned char *,int)=0;
    virtual void setAlphaSource(int,int=-1,int=-1,int=-1)=0;

    virtual void drawText( int,int,const QString & )=0;

    virtual void setClut(QRgb *,int)=0;

    // Save and restore pen and brush state - necessary when setting
    // up a bitBlt for example
    virtual void save()=0;
    virtual void restore()=0;

    virtual void setRop(RasterOp)=0;

    bool isScreenGfx() { return is_screen_gfx; } //for cursor..
    
    // to support lcd overlay
    // type == 0 original copy
    // type == 1 support transparentcy
    // default 0
    unsigned int overlayTransparentType(){ return overlayType; }
    void setOverlayTransparentType(unsigned int type)
                                { overlayType = type; }

    
    bool alphaInColor() { return alphaEnabledInColor; }
    void enableAlphaInColor(bool enable)  { alphaEnabledInColor = enable; }
    
protected:
    unsigned int overlayType;
    bool is_screen_gfx;
#ifndef QT_NO_QWS_FADEBACKGROUND
    bool is_offscreen_gfx; // flag to indicate if the gfx is created from the offScreenPixmap
#endif

    // flag to indicate whether sw alpha blending is performed on graphics (point, line, rect...)
    bool alphaEnabledInColor;
};


// This lives in loadable modules

#ifndef QT_LOADABLE_MODULES
extern "C" QScreen * qt_get_screen( int display_id, const char* spec );
#endif

// This is in main lib, loads the right module, calls qt_get_screen
// In non-loadable cases just aliases to qt_get_screen

const unsigned char * qt_probe_bus();

#endif



