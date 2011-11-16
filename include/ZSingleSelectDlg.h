

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef _ZSINGLESELECTDLG_H_
#define _ZSINGLESELECTDLG_H_

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZPopup.h"

#include "ZListBox.h"
#include "ZListItem.h"

#include "qstring.h"
#include "qobjectdefs.h"
#include "qwidget.h"
#include "qnamespace.h"
#include "qobject.h"
#include "qevent.h"

class QStringList;

struct ZSingleSelectDlgPrivate;

class ZSingleSelectDlg : public ZPopup
{
    Q_OBJECT

public:

    ZSingleSelectDlg(QWidget* parent = NULL,
                     const char* name = 0,
                     bool modal = TRUE,
                     WFlags f = 0);

    ZSingleSelectDlg(const QString& strDlgTitle,
                     const QString& strInstructText,
                     QWidget* parent = NULL,
                     const char* name = 0,
                     bool modal = TRUE,
                     WFlags f = 0,
                     int auto_dismiss_time = 0);

    virtual ~ZSingleSelectDlg();

    ZListBox* getListBox();

    ZListItem* getCheckedItem();

    int getCheckedItemIndex();

    void addItemsList(QStringList&);

signals:

    void signalCenterSelKeyPressed();

protected:

    virtual bool eventFilter( QObject* o, QEvent* e);
    virtual void showEvent(QShowEvent*);

protected slots:

    virtual void slotLSKClicked();

    virtual void slotResizeAllChild(int);

private:

    void initialize();

    void checkCurHighlightItem();

private:

    ZSingleSelectDlgPrivate* mpData;

};

#endif	

