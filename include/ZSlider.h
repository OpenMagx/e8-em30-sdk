

// Copyright (c)  - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZSLIDER_H
#define PUBLIC_API_WIDGET_ZSLIDER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZWidget.h"
#include "qrangecontrol.h"
#include "ZSkinTool.h"
#include "ZSkinService.h"
class QTimer;
struct ZSliderPrivate;

class ZSlider : public ZWidget, public QRangeControl
{
    Q_OBJECT

public:
    enum Indicator
    {
      NULL_MINMAX,
      TEXT,
      ICON      
    };

    ZSlider( QWidget *parent, const char *name=0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZSlider);

    ZSlider( Indicator indicator,Orientation orientation, QWidget *parent, const char *name=0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZSlider);

    ZSlider( int minValue, int maxValue, int pageStep, int value,
            Indicator indicator,Orientation orientation,
            QWidget *parent, const char *name=0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZSlider);

    virtual ~ZSlider();

    virtual void setOrientation( Orientation orientation);

    Orientation orientation() const;

    int minValue() const;

    int maxValue() const;

    void setMinValue( int value);

    void setMaxValue( int value);

    int lineStep() const;

    int pageStep() const;

    void setLineStep( int i );

    void setPageStep( int i);

    int  value() const;

    void setPixmap(QPixmap increment,QPixmap decrement);

    void reset();

    void showThumb( bool bShow );

    void setThickness(int nCounts);

    int thickness() const;

    void setSelectionState( const ZSkinBase::SelectionState state );

    QSize sizeHint() const;

    void updateSkin(bool redraw);

    virtual void setPalette(const QPalette &palette);

    void setOmgPage(int steps);

    int omgPage(void);

    void addOmgPage(void);

    void subtractOmgPage(void);

    void scrollOmg(int steps);
public:
    QSize minimumSizeHint() const;
    void  setEnabled(bool enable);
    bool  isZEnabled();
    bool  isZDisabled();
    bool  autoResize() const;
    void  setAutoResize( bool enable );

    void changeToVertical( bool bVertical) ;
public slots:
    virtual void setValue( int value);

    void addStep();

    void subtractStep();

    void updateState();

signals:
    void valueChanged( int value );

    void sliderSizeChange();

    void signalSelect();

protected:
    void resizeEvent( QResizeEvent * e);

    void paintEvent( QPaintEvent * e);

    void keyPressEvent( QKeyEvent * e);
    void        keyReleaseEvent( QKeyEvent *e );
    void focusInEvent( QFocusEvent * e );

    void focusOutEvent( QFocusEvent * e );

    void valueChange();

    void rangeChange();

    virtual void paintSlider( QPainter *painter, const QRect & r);

private:
    QRect sliderRect() const;
    void init();
    int positionFromValue( int ) const;
    int valueFromPosition( int ) const;
    void moveSlider( int );
    void reallyMoveSlider( int );
    int slideLength() const;
    int available() const;
    void initTicks();
    void resizeSlider();
    void setSpacingS1(int nSpacing);
    short getSpacingS1() const;
    void loadLRS( WIDGET_PADDING_INFO_T &pad,int &nSpacing) const;

private:
    ZSliderPrivate *d;
};

#endif 
