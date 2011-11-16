//Fix for E8/EM30 by Ant-ON, 25-10-2010

// Copyright (c) 24-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef UTIL_ACTIONRECEIVER_H
#define UTIL_ACTIONRECEIVER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qobject.h>
#include "AM_ActionGlobal.h"

class AM_ActionData;
class ES_Event;
class ESCopChannel;

class AM_ActionReceiver : public QObject
{
    Q_OBJECT
public:
    ~AM_ActionReceiver();                        
    static AM_ActionReceiver * instance();
signals:
    void receiveAction(const AM_ActionData & d);
    
private slots:
//    void pidMessage( const ES_Event& event );
    void slotProcessMessage(const QCString & action, const QByteArray & data); //Add by Ant-ON
    
private:
    AM_ActionReceiver(QObject * parent = 0, const char * name = 0);                         
    static AM_ActionReceiver * pInstance;
    ESCopChannel* pidChannel;
};

#endif  

