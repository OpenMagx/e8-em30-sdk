//Fix for E8/EM30 by Ant-ON, 25-10-2010

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef _ZNOTICESDLG_H_
#define _ZNOTICESDLG_H_

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <ZPopup.h>

#include "qstring.h"
#include "qobjectdefs.h"
#include "qwidget.h"
#include "qnamespace.h"
#include "qglobal.h"
#include "qpixmap.h"
#include "qobject.h"
#include "qpalette.h"
#include "qevent.h"

struct ZNoticeDlgPrivate;

class ZNoticeDlg : public ZPopup
{
    Q_OBJECT

public:

    enum Type
    {
        Success,            
        Information         
    };

public:

    ZNoticeDlg(Type type,
               const QString& strInstructText = QString::null,
               const QString& strMsg = QString::null,
               QWidget* parent = 0,
               const char* name = 0,
               bool modal = true,
               WFlags f = 0,
               bool bEnableDismissTimer = true);

    ZNoticeDlg(Type type,
               uint nAutoDismissTime = 0,
               const QString& strInstructText = QString::null,
               const QString& strMsg = QString::null,
               QWidget* parent = 0,
               const char* name = 0,
               bool modal = true,
               WFlags f = 0);

    virtual ~ZNoticeDlg();

    void setAnimate(const QString& strAnimateFileID);

    void setMessageIcon(const QPixmap& icon);

    void setMessageText(const QString& str);

    void setAutoDismissTime(int ntime);

    //bool isDismissedWhenFlip();
    //void enableDismissedWhenFlip(bool bDismissed);
    
    static void information(
        const QString& strMsg,
        const QString& strInstructText = QString::null,
        const QString& strAnimateFile = QString::null,
        const QString& strIconResID = QString::null,
        const QObject* pReceiver = NULL,
        char* pszSlot = NULL);

signals:
    void    dlgDismissed();

protected slots:

    virtual void slotResizeAllChild(int);

protected:

    virtual void keyPressEvent(QKeyEvent* e);

    //virtual void keyReleaseEvent(QKeyEvent* e);

    virtual void showEvent(QShowEvent*);


private:

    void initialize(Type type);

    void startAutoDismissTimer();

    void dismissDlg( ZPopup::PopupCode code);

    uint calculateDismissTime();

private slots:

    void slotTimeout();

private:

    ZNoticeDlgPrivate* mpData;

};

#endif	
