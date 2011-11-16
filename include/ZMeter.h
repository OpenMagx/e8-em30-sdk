
// Copyright (c)  - 2008 Motorola, Inc. All rights reserved.

#ifndef ZMETER_H
#define ZMETER_H

#include "ZWidget.h"
#include "ZSkinService.h"
#include "ZImage.h"

struct ZMeterData;

class ZMeter : public ZWidget
{
    Q_OBJECT

public:
    enum Information
    {
       NULL_MINMAX,
       TEXT,
       ICON
    };
    enum Alignment
    {
      TWO_BOTTOM,
      LEFT_TOP,
      RIGHT_BOTTOM
    };
    enum PixmapSetting
    {
      HORIZONTAL_PIXMAP,
      VERTICAL_PIXMAP,
      ALL_PIXMAP
    };
    enum Types
    {                   // MeterType
       STATIC,                           // tile
       DETERMINATE,               // stretch
       INDETERMINATE             // indeterminate
     };
    ZMeter(int nTotalCounts,int nMaxSize,
            QWidget *parent=0, const char *name=0, WFlags f=0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZMeter_Indicator2);
    ZMeter(QString strFileName="",QWidget *parent = 0,const char *name=0,WFlags f=0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZMeter_Indicator3);
    ZMeter( int nTotalCounts,QWidget *parent=0, const char *name=0, WFlags f=0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZMeter_Indicator1);
    virtual ~ZMeter();
    void reset();
    void pause();
    int  totalSteps() const;
    int  progress() const;
    void setMinText( QString strMinText );
    void setMaxText( QString strMaxText );
    QString minText();
    QString maxText();
    void setPixmap(QPixmap minPixmap,QPixmap maxPixmap,PixmapSetting setting);
    void setOrientation(Orientation orientation);
    Orientation orientation() const;
    void setAlignment(Alignment alignment);
    Alignment alignment() const;
     void setInformation(Information information);
     Information information() const;
     QSize sizeHint() const;
     bool  paused () const;
     bool  running () const;
     void updateSkin(bool redraw);
     virtual void setPalette(const QPalette &palette);

public:
     bool autoResize () const;
     void setAutoResize ( bool enable );
     void  setEnabled(bool enable);
     bool  isZEnabled();
     bool  isZDisabled();
     QSize minimumSizeHint() const;
     void setMaxSize( int nMaxSize);
     int  maxSize() const;
    
    ZImage * getImageWidget() const ;

    void resizeMovieLabel();

signals:
    void meterSizeChange();

public slots:
    virtual void setTotalSteps( int totalSteps );

    virtual void setProgress( int progress );

public slots:
    void sizeChanged();

protected:
    void resizeEvent(QResizeEvent * e);

    void paintEvent(QPaintEvent * e);

    void showEvent ( QShowEvent *e );

private:
     void init();
     void initButton();
     void setSpacingS2(int nSpacing);
     short getSpacingS2()const;
     void  setSpacingS1(int nSpacing);
     short getSpacingS1() const;
     void  getIndicatorLength() const;
     QSize meterATypeSizeHint() const;
     QSize meterBTypeSizeHint() const;
     QSize ZMeter::getIndicatorSize() const;
     int getIndicatorX() const;
     int getIndicatorY() const;
     void drawIndicatorContents( QPixmap& all,int xPoint,int yPoint,QSize sz );

private:
     ZMeterData *d;
};
#endif
