
/*
 * Copyright (C) 2007 Motorola Inc.
 *
 * Date         Author         Comment
 * 09/25/07     Motorola       Motorola customization.
*/

/****************************************************************************
** $Id: qt/src/kernel/qpixmap.h   2.3.8   edited 2004-08-05 $
**
** Definition of QPixmap class
**
** Created : 940501
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of the kernel module of the Qt GUI Toolkit.
**
** This file may be distributed under the terms of the Q Public License
** as defined by Trolltech AS of Norway and appearing in the file
** LICENSE.QPL included in the packaging of this file.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** Licensees holding valid Qt Enterprise Edition or Qt Professional Edition
** licenses may use this file in accordance with the Qt Commercial License
** Agreement provided with the Software.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.trolltech.com/pricing.html or email sales@trolltech.com for
**   information about Qt Commercial License Agreements.
** See http://www.trolltech.com/qpl/ for QPL licensing information.
** See http://www.trolltech.com/gpl/ for GPL licensing information.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

#ifndef QPIXMAP_H
#define QPIXMAP_H

#ifndef QT_H
#include "qpaintdevice.h"
#include "qcolor.h"
#include "qstring.h"
#include "qnamespace.h"
#endif // QT_H

class QGfx;

#if defined(_WS_WIN_)
// Internal pixmap memory optimization class for Windows 9x
class QMultiCellPixmap;
#endif


class Q_EXPORT QPixmap : public QPaintDevice, public Qt
{
public:
    enum ColorMode { Auto, Color, Mono };
    enum Optimization { DefaultOptim, NoOptim, MemoryOptim=NoOptim,
			NormalOptim, BestOptim };

    QPixmap();
    QPixmap( int w, int h,  int depth = -1, Optimization = DefaultOptim );
    QPixmap( const QSize &, int depth = -1, Optimization = DefaultOptim );
    QPixmap( const QString& fileName, const char *format=0,
	     ColorMode mode=Auto );
    QPixmap( const QString& fileName, const char *format,
	     int conversion_flags );
    QPixmap( const char *xpm[] );
    QPixmap( const QByteArray &data );
    QPixmap( const QPixmap & );

#if defined(_WS_QWS_)

    //
    // MOT
    //
    // -- Added to support setting pixmaps from resource file data
    //

    QPixmap( unsigned char* data,
             int width, int height, int depth, int linestep,
             bool alloc = false, int hasAlpha = -1);
#endif

   ~QPixmap();

    QPixmap    &operator=( const QPixmap & );
    QPixmap    &operator=( const QImage	 & );

    bool	isNull()	const;

    int		width()		const { return data->w; }
    int		height()	const { return data->h; }
    QSize	size()		const { return QSize(data->w,data->h); }
    QRect	rect()		const { return QRect(0,0,data->w,data->h); }
    int		depth()		const { return data->d; }
    static int	defaultDepth();

    void	fill( const QColor &fillColor = Qt::white );
    void	fill( const QWidget *, int xofs, int yofs );
    void	fill( const QWidget *, const QPoint &ofs );
    void	resize( int width, int height );
    void	resize( const QSize & );

    const QBitmap *mask() const;
    void	setMask( const QBitmap & );
    bool	selfMask() const;
    QBitmap	createHeuristicMask( bool clipTight = TRUE ) const;

    static  QPixmap grabWindow( WId, int x=0, int y=0, int w=-1, int h=-1 );
    static  QPixmap grabWidget( QWidget * widget,
				int x=0, int y=0, int w=-1, int h=-1 );

#ifndef QT_NO_PIXMAP_TRANSFORMATION
    QPixmap	    xForm( const QWMatrix & ) const;
#endif
#ifndef QT_NO_WMATRIX
    static QWMatrix trueMatrix( const QWMatrix &, int w, int h );
#endif

    QImage	convertToImage() const;
    bool	convertFromImage( const QImage &, ColorMode mode=Auto );
    bool	convertFromImage( const QImage &, int conversion_flags );

    static const char* imageFormat( const QString &fileName );
    bool	load( const QString& fileName, const char *format=0,
		      ColorMode mode=Auto );
    bool	load( const QString& fileName, const char *format,
		      int conversion_flags );
    bool	loadFromData( const uchar *buf, uint len,
			      const char* format=0,
			      ColorMode mode=Auto );
    bool	loadFromData( const uchar *buf, uint len,
			      const char* format,
			      int conversion_flags );
    bool	loadFromData( const QByteArray &data,
			      const char* format=0,
			      int conversion_flags=0 );
    bool	save( const QString& fileName, const char* format ) const; // ### remove 3.0
    bool	save( const QString& fileName, const char* format,
		      int quality ) const; // ### change to quality=-1 in 3.0

#if defined(_WS_WIN_)
    HBITMAP	hbm()		const;
#endif

    int		serialNumber()	const;

    Optimization	optimization() const;
    void		setOptimization( Optimization );
    static Optimization defaultOptimization();
    static void		setDefaultOptimization( Optimization );

    virtual void detach();

    bool	isQBitmap() const;

#if defined(_WS_WIN_)
    // These functions are internal and used by Windows 9x only
    bool	isMultiCellPixmap() const;
    HDC		multiCellHandle() const;
    HBITMAP	multiCellBitmap() const;
    int		multiCellOffset() const;
    int		allocCell();
    void	freeCell( bool = FALSE );
#endif

#if defined(_WS_QWS_)

    //
    // MOT -- added by Motorola to support pixmaps shared between processes.
    //        This is used for wallpaper.
    //
  
    // 
    // setRawData -- sets this pixmap to use data allocated elsewhere in 
    // memory.  Destroying this QPixmap will NOT free memory pointed to 
    // by data
    //

    void setRawData(unsigned char* data, 
                    int width, int height, int depth, int linestep,
                    bool alloc = false, int hasAlpha = -1);

#ifndef QT_NO_QWS_DEPTH_24_ALPHA
    // by default, all the alpha values in QPixmap will not change
    void setAlpha(int alpha = -1);  
#endif

    //
    // MOT -- end of mot changes
    //
    
    virtual QGfx * graphicsContext(bool clip_children=TRUE) const;
    virtual unsigned char * scanLine(int) const;
    virtual int bytesPerLine() const;
    QRgb * clut() const;
    int numCols() const;
    bool hasAlpha() const { return data->hasAlpha || data->mask; }
#else
    bool hasAlpha() const { return data->mask; }
#endif

#if defined(Q_FULL_TEMPLATE_INSTANTIATION)
    bool operator==( const QPixmap& ) const { return FALSE; }
#endif

protected:
    QPixmap( int w, int h, const uchar *data, bool isXbitmap );
    int metric( int ) const;

#if defined(_WS_WIN_)
    struct QMCPI {				// mem optim for win9x
	QMultiCellPixmap *mcp;
	int	offset;
    };
#endif

    struct QPixmapData : public QShared {	// internal pixmap data
	QCOORD	w, h;
	short	d;
	uint	uninit	 : 1;
	uint	bitmap	 : 1;
	uint	selfmask : 1;
#if defined(_WS_WIN_)
	uint	mcp	 : 1;
#endif
	int	ser_no;
	QBitmap *mask;
#if defined(_WS_WIN_)
	void   *bits;
	QPixmap *maskpm;
	union {
	    HBITMAP hbm;    // if mcp == FALSE
	    QMCPI  *mcpi;   // if mcp == TRUE
	} hbm_or_mcpi;
#elif defined(_WS_X11_)
	void   *ximage;
	void   *maskgc;
#elif defined(_WS_QWS_)
	int id; // ### should use QPaintDevice::hd, since it is there
	QRgb * clut;
	int numcols;
	int rw;
	int rh;
	bool hasAlpha;
        void copyData(int id, int width, int depth) const;
#endif
	Optimization optim;
    } *data;

private:
    QPixmap( int w, int h, int depth, bool, Optimization );
    void	init( int, int, int, bool, Optimization );
    void	deref();
    QPixmap	copy( bool ignoreMask = FALSE ) const;
    static Optimization defOptim;
    friend Q_EXPORT void bitBlt( QPaintDevice *, int, int,
				 const QPaintDevice *,
				 int, int, int, int, RasterOp, bool );
    friend Q_EXPORT void bitBlt( QPaintDevice *, int, int,
				 const QImage* src,
				 int, int, int, int, int conversion_flags );
    //added for webKit
    friend Q_EXPORT void copyBlt( QPixmap *dst, int dx, int dy,
                                  const QPixmap *src, int sx, int sy,
                                  int sw, int sh );
    //added for webKit
    friend class QBitmap;
    friend class QPaintDevice;
    friend class QPainter;
    friend class QSharedMemoryManager;

#ifndef QT_NO_QWS_MMI_TEST
public:
    QString file_Name_;
#endif
};


inline bool QPixmap::isNull() const
{
    return data->w == 0;
}

inline void QPixmap::fill( const QWidget *w, const QPoint &ofs )
{
    fill( w, ofs.x(), ofs.y() );
}

inline void QPixmap::resize( const QSize &s )
{
    resize( s.width(), s.height() );
}

inline const QBitmap *QPixmap::mask() const
{
    return data->mask;
}

inline bool QPixmap::selfMask() const
{
    return data->selfmask;
}

#if defined(_WS_WIN_)
inline HBITMAP QPixmap::hbm() const
{
    return data->mcp ? 0 : data->hbm_or_mcpi.hbm;
}
#endif

inline int QPixmap::serialNumber() const
{
    return data->ser_no;
}

inline QPixmap::Optimization QPixmap::optimization() const
{
    return data->optim;
}

inline bool QPixmap::isQBitmap() const
{
    return data->bitmap;
}

#if defined(_WS_WIN_)
inline bool QPixmap::isMultiCellPixmap() const
{
    return data->mcp;
}
#endif


/*****************************************************************************
  QPixmap stream functions
 *****************************************************************************/

#ifndef QT_NO_DATASTREAM
Q_EXPORT QDataStream &operator<<( QDataStream &, const QPixmap & );
Q_EXPORT QDataStream &operator>>( QDataStream &, QPixmap & );
#endif

//Added for webKit
// QPixmap helper function (qt3 backport)

Q_EXPORT void copyBlt( QPixmap *dst, int dx, int dy,
                       const QPixmap *src, int sx = 0, int sy = 0,
                       int sw = -1, int sh = -1 );
//Added for webKit


#endif // QPIXMAP_H
