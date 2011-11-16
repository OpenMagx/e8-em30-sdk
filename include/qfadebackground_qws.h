

// Copyright (c) 26-Jun-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef QFADEBACKGROUND_H
#define QFADEBACKGROUND_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qwindowsystem_qws.h>
#include <qlist.h>

#ifndef QT_NO_QWS_FADEBACKGROUND

class QFadeBackground : public QObject 
{
    Q_OBJECT

    friend class QWSServer; 
private:    

    QFadeBackground();  

public:

    ~QFadeBackground();

protected:

    void triggerFade(int id);  

    void startFade(int id); 

    void stopFade(int id); 

    void enableFade(bool yes, int id); 

protected slots:

    void slotWindowEvent(QWSWindow *w, QWSServer::WindowEvent e);  

protected:

    void timerEvent(QTimerEvent *te);

    void fadeScreen(int id);
private:
    QColor fadeColor; 
    int timerId;      
    int refCount;     
    QList<QWSWindow> wList; 
    QArray<bool> oneLevelFading;
};

#endif 

#endif 

