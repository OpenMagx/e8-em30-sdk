
/*
 * Copyright (C) 2007 Motorola Inc.
 *
 * Date         Author         Comment
 * 09/25/07     Motorola       Motorola customization.
*/

/****************************************************************************
** $Id: qt/src/kernel/qsoundqss_qws.h   2.3.8   edited 2004-08-05 $
**
** Definition of Qt Sound System
**
** Created : 001017
**
** Copyright (C) 2000 Trolltech AS.  All rights reserved.
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

#ifndef QSOUNDQSS_H
#define QSOUNDQSS_H

#ifndef QT_H
#include <qserversocket.h>
#endif // QT_H

#if defined(QT_NO_NETWORK) || defined(QT_NO_DNS)
#define QT_NO_SOUNDSERVER
#endif

#ifndef QT_NO_SOUND

class QWSSoundServerData;

class QWSSoundServer : public QObject {
    Q_OBJECT
public:
    QWSSoundServer(QObject* parent=0);
    ~QWSSoundServer();
    void playFile( const QString& filename , int );
    void stopFile( int );
    void pauseFile( int );
    void resumeFile( int );

private:
    QWSSoundServerData* d;
};

#ifndef QT_NO_SOUNDSERVER
class QWSSoundClient : public QSocket {
    Q_OBJECT
public:

    enum SoundFlags {
	Priority = 0x01,
	Streaming = 0x02  // currently ignored, but but could set up so both Raw and non raw can be done streaming or not.
    };
    QWSSoundClient( QObject* parent=0 );
    ~QWSSoundClient( );
    void ping();
    void play( int id, const QString& filename );
    void play( int id, const QString& filename, int volume, int flags = 0 );
    void playRaw( int id, const QString&, int, int, int, int flags = 0 );

    void pause( int id );
    void stop( int id );
    void resume( int id );
    void setVolume( int id, int left, int right );
    void setMute( int id, bool m );

    // to be used by server only, to protect phone conversation/rings.
    void playPriorityOnly(bool);

signals:
    void soundCompleted(int);
    void rawFileOpen(int);
    void pong();

private slots:
    void tryReadCommand();
};

class QWSSoundServerClient : public QSocket {
    Q_OBJECT

public:
    QWSSoundServerClient(int s, QObject* parent);
    ~QWSSoundServerClient();

public slots:
    void sendSoundCompleted(int, int);
    void sendRawFileOpen(int, int);

signals:
    void play(int, int, const QString&);
    void play(int, int, const QString&, int, int);
    void playRaw(int, int, const QString&, int, int, int, int);

    void pause(int, int);
    void stop(int, int);
    void resume(int, int);
    void setVolume(int, int, int, int);
    void setMute(int, int, bool);

    void stopAll(int);

    void playPriorityOnly(bool);

private slots:
    void destruct();
    void tryReadCommand();

private:
    void sendPong();
    int mCurrentID;
    int left, right;
    bool priExist;
    static int lastId;
    static int nextId() { return ++lastId; }
};

class QWSSoundServerSocket : public QServerSocket {
    Q_OBJECT

public:
    QWSSoundServerSocket(QObject* parent=0, const char* name=0);
    void newConnection(int s);

signals:
    void playFile(int, int, const QString&);
    void playFile(int, int, const QString&, int, int);
    void playRawFile(int, int, const QString&, int, int, int, int);
    void pauseFile(int, int);
    void stopFile(int, int);
    void resumeFile(int, int);
    void setVolume(int, int, int, int);
    void setMute(int, int, bool);

    void stopAll(int);

    void playPriorityOnly(bool);

    void soundFileCompleted(int, int);
    void rawFileOpen(int, int);
};
#endif

#endif // QT_NO_SOUND

#endif
