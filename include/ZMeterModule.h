
// Copyright (c)  - 2008 Motorola, Inc. All rights reserved.


#ifndef ZMETERMODULE_H
#define ZMETERMODULE_H

#include "ZWidget.h"
#include "ZMeter.h"
#include "ZSkinService.h"

struct ZMeterModuleData;


class ZMeterModule:public ZWidget
{
Q_OBJECT

public:

   enum Alignment{
    NULL_LABEL,
    LEFT,
    TOP,
    RIGHT,
    BOTTOM
   };

    ZMeterModule( int nTotalCounts, int nMaxSize, QWidget *parent = 0,const char *name =0,WFlags f=0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZMeterModule,
            const ZSkinService::WidgetClsID clsIdMeter = ZSkinService::clsZMeter_Indicator2);

    ZMeterModule(QString strFileName="",
            QWidget *parent=NULL,const char *name=0,WFlags f=0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZMeterModule,
            const ZSkinService::WidgetClsID clsIdMeter = ZSkinService::clsZMeter_Indicator3);

    ZMeterModule(int nTotalCounts,QWidget *parent=NULL, const char *name=0, WFlags f=0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZMeterModule,
            const ZSkinService::WidgetClsID clsIdMeter = ZSkinService::clsZMeter_Indicator1);

    virtual ~ZMeterModule();

    ZMeter *getMeter() const;

    void setAlignment(Alignment alignment);

    Alignment alignment() const;

    void setOrientation(Orientation orientation);

    Orientation orientation() const;

    void setLabelText(QString strText);

    QSize sizeHint() const;

    void updateSkin(bool redraw);

    virtual void setPalette(const QPalette &palette);

public:
    QSize minimumSizeHint() const;
    void setMaxSize(int nMaxSize);
    bool autoResize () const;
    void setAutoResize ( bool enable );
    void setSpacingV1(short nSpacing);

public slots:
    void sizeChanged();

protected:
    virtual void resizeEvent(QResizeEvent * e);

    void paintEvent(QPaintEvent * e);

    void resizeAll();

private:
    void arrangeWidgets();
    void init();
    void setSpacingH1(short nSpacing);
    short getSpacingH1() const;
    short getSpacingV1() const;

private:
    ZMeterModuleData *d;
};

#endif 
