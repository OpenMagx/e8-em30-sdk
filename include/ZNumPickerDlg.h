

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef _ZNUMPICKERDLG_H_
#define _ZNUMPICKERDLG_H_

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZPopup.h"

#include "ZSkinService.h"
#include "ZNumModule.h"

#include "qstring.h"
#include "qobjectdefs.h"
#include "qwidget.h"
#include "qnamespace.h"
#include "qevent.h"

struct ZNumPickerDlgPrivate;

class ZNumPickerDlg : public ZPopup
{
    Q_OBJECT

public:

    ZNumPickerDlg(int nMaxLen,
                  QWidget* parent = 0, const char* name = 0, WFlags f = 0);

    virtual ~ZNumPickerDlg();

    ZNumModule* getNumModule();

    int getNumValue();

signals:

    void signalCenterSelKeyPressed();

protected slots:

    virtual void slotResizeAllChild(int);

protected:

    virtual void keyPressEvent( QKeyEvent * );

private slots:

    void slotCenterSelKeyPressed();

private:

    void initialize( int nMaxlen );

private:

    ZNumPickerDlgPrivate* mpData;
};

#endif	
