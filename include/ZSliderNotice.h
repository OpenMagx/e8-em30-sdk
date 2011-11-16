

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ZSLIDERNOTICE_H
#define ZSLIDERNOTICE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZPopup.h"
#include "ZSliderModule.h"

struct ZSliderNoticePrivate;

class ZSliderNotice : public ZPopup
{

Q_OBJECT

public:
    ZSliderNotice(const QString &instr, QWidget *parent = 0,
		  int minV = 0,int maxV = 10, int step = 1, int value = 0,
		  const char *name = 0, WFlags f = 0);

    ~ZSliderNotice();

    ZSliderModule *getSliderModule( ) const;

    bool eventFilter(QObject *, QEvent *);
    void setOmgPage(int steps);

    int omgPage(void);

    virtual void setOmegaInput(bool flag);

protected slots:

    void onValueChanged(int);
protected:
    void showEvent(QShowEvent *);
    void hideEvent(QHideEvent *);
    void timerEvent(QTimerEvent *);

private:
    void restartTimer();

    ZSliderNoticePrivate* mpData;
};

#endif  
