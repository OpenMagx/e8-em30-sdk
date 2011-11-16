
/*
 * Copyright (C) 2007 Motorola Inc.
 *
 * Date         Author         Comment
 * 09/25/07     Motorola       Motorola customization.
*/

/****************************************************************************
** $Id: qt/src/kernel/qwsdisplay_qws.h   2.3.6   edited 2003-05-16 $
**
** QWS display
**
** Created : 20000616
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

#ifndef QWSDISPLAY_H
#define QWSDISPLAY_H

#include "qobject.h"
#include "qregion.h"
#include "qlock_qws.h"
#include "qwindowdefs.h"

#include "qlist.h"

// Class forward definitions
class QWSDisplayData;
class QWSRegionManager;
class QWSEvent;
class QWSQCopMessageEvent;
class QGfx;

class Q_EXPORT QWSWindowInfo
{

public:

    int winid;
    unsigned int clientid;
    QString name;

};

#define QT_QWS_PROPERTY_CONVERTSELECTION 999
#define QT_QWS_PROPERTY_WINDOWNAME 998
#define QT_QWS_PROPERTY_MARKEDTEXT 997

class Q_EXPORT QWSDisplay
{
public:
    QWSDisplay();
    ~QWSDisplay();

    bool eventPending() const;
    QWSEvent *getEvent();
    QGfx * screenGfx();
    QWSRegionManager *regionManager() const;

    uchar* frameBuffer() const;
    int width() const;
    int height() const;
    int depth() const;
    int pixmapDepth() const;
    bool supportsDepth(int) const;

    uchar *sharedRam() const;
    int sharedRamSize() const;

    void addProperty( int winId, int property );
    void setProperty( int winId, int property, int mode, const QByteArray &data );
    void setProperty( int winId, int property, int mode, const char * data );
    void removeProperty( int winId, int property );
    bool getProperty( int winId, int property, char *&data, int &len );

    QList<QWSWindowInfo> * windowList();

    void setIdentity(const QString &appName);
    void nameRegion( int winId, const QString& n, const QString &c );
    void setRegionPriority( int winId, int p);
    void resetRegionFocusPriority( int winId);
    void requestRegion( int winId, QRegion );
    void moveRegion( int winId, int dx, int dy );
    void destroyRegion( int winId );
    void requestFocus(int winId, bool get);
    void setAltitude( int winId, int altitude, bool fixed = FALSE );
    //Added to provide atomic operation for these two request, resolve the asynchornization problem
    //order: 1 setAltitude first, 2 request Focus first
    void setAltitudeAndRequestFocus( int winId, bool fget, int altitude, bool fixed = FALSE, int order = 1);
    int takeId();
    void setSelectionOwner( int winId, const QTime &time );
    void convertSelection( int winId, int selectionProperty, const QString &mimeTypes );
    void defineCursor(int id, const QBitmap &curs, const QBitmap &mask,
			int hotX, int hotY);
    void selectCursor( QWidget *w, unsigned int id );
    void grabMouse( QWidget *w, bool grab );
    void grabKeyboard( QWidget *w, bool grab );
    void simulateMouseEvent( int x, int y, int state );
    void playSoundFile( const QString& );
    void registerChannel( const QCString& channel );
    void sendMessage(const QCString &channel, const QCString &msg,
                       const QByteArray &data );
    void stopOmgRateMode(int step); 
    // Morphing Feature
    void setMorphMode( const int morphMode, const int winId ); // send command to Qt server to change morph mode of device

#ifndef QT_NO_QWS_IM
    void setIMInfo( int winId, int x, int y, const QRect &, bool = FALSE );
    void resetIM();
    void setInputFont( int winId, const QFont & );
    void sendIMMouseEvent( int index, bool isPress );
#endif

#ifndef QT_NO_QWS_FADEBACKGROUND
    void setFadeBackground(int winId, Qt::FadeoverMode fade);
    void setSkipFadeBackground( int winId, bool sk);
#endif

    QWSQCopMessageEvent* waitForQCopResponse();

    void setCaption( QWidget *w, const QString & );

    // Lock display for access only by this process
    static bool initLock( const QString &filename, bool create = FALSE );
    static bool grabbed() { return lock->locked(); }
    static void grab() { lock->lock( QLock::Read ); }
    static void grab( bool write )
	{ lock->lock( write ? QLock::Write : QLock::Read ); }
    static void ungrab() { lock->unlock(); }

    static void setTransformation( int t );

// ADDED - BEGIN
// Just for HandWriting.
// Should be a pair: set and reset.
    void limitMouseEventCompression( bool doLimit );
// ADDED - END

private:
    friend class QApplication;
    friend class QCopChannel;
    QWSDisplayData *d;

    int getPropertyLen;
    char *getPropertyData;
    static QLock *lock;
};

extern Q_EXPORT QWSDisplay *qt_fbdpy;

#endif // QWSDISPLAY_H

