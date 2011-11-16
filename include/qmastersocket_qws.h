

// Copyright (c) 11-Jan-05 - 2008 Motorola, Inc. All rights reserved.



#ifndef QMASTERSOCKET_QWS_H
#define QMASTERSOCKET_QWS_H

#include "qglobal.h"

#ifdef QT_MULTILCD

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#ifndef QT_H
#include <qwssocket_qws.h>
#endif 

class QMasterServerConnection : public QWSSocket
{
public:
    QMasterServerConnection(QObject *parent)
    : QWSSocket(parent), bytesNeeded(0) {}

    Q_UINT32 bytesNeeded;
};

class QMasterServerData {
public:
    QValueList<QMasterServerConnection*> connections;
};

extern QMasterServerData *qmasterServerData;

class QMasterServer : public QWSServerSocket
{
    Q_OBJECT
public:
    QMasterServer( QObject *parent=0, const char *name=0 );
    ~QMasterServer();

    static void startup();
    static void closedown();

public slots:
    void dataReady();
    void closeHandler();

private:
    void newConnection( int socket );
};

extern QMasterServer *qmasterServer;

class QMasterClientData 
{
public:
    struct Message
    {
        QCString ch;
        QCString msg;
        QByteArray data;
    };
    QWSSocket *socket;
    Q_UINT32 bytesNeeded;
};

extern QMasterClientData *qmasterClientData;

class QMasterClient : public QObject
{
    Q_OBJECT
public:

    QMasterClient( QObject* parent=0, const char *name=0 );
    ~QMasterClient();

    static void startup();

private slots:
    void dataReady();
    void connected();    
    void closeHandler();
    void beginSession();
};

#endif 

#endif  
