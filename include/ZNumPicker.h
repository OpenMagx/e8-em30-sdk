

// Copyright (c)  - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZNUMPICKER_H
#define PUBLIC_API_WIDGET_ZNUMPICKER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZWidget.h"
#include <qpixmap.h>

struct ZNumPickerData;

class ZNumPicker : public ZWidget
{
    Q_OBJECT

public:
    ZNumPicker( int nMaxLen,QWidget *parent = 0, const char *name = 0,  WFlags f = 0 ,const ZSkinService::WidgetClsID clsId = ZSkinService::clsZNumPicker);

    ~ZNumPicker();

    int getValue();

    void setMaxValue( int nValue );

    void setMinValue( int nValue );

    void setValue( int nValue );

    void setLineStep( int nStep);
    void setPageStep( int nStep);

    int lineStep();
    int pageStep();

        void setWrapping(bool bOn);

        bool wrapping();

	int maxValue();

	int minValue();

         void setSelectionState( const SelectionState state );

	QSize sizeHint() const;

        bool hasFocus() const;

	void updateSkin(bool redraw);

        virtual void setPalette(const QPalette &palette);

public:
	QSize minimumSizeHint() const;
	void setEnabled(bool enable);
        bool isZEnabled();
        bool isZDisabled();
        bool autoResize() const;
        void setAutoResize( bool enable );

public slots:
       void keyEventProcess(QEvent *ev, int nTabIndex = 0);

       void valueChange(int value );

signals:
      void valueChanged( int value );

      void numPickerSizeChange();

      void signalSelect();

protected:
       void resizeEvent(QResizeEvent * e);

       void paintEvent(QPaintEvent * e);

       void keyPressEvent(QKeyEvent * e);

       void focusInEvent( QFocusEvent * e);

       void focusOutEvent( QFocusEvent * e);

private:
        void initValue(int nMaxLen);
       	void init(int nMaxLen);
        void initLRS();
        void  setSpacingV1(short nSpacing);
        short getSpacingV1()const;
        void getStandardPixmap();
        void getHighSelectedPixmap();
        void getSelectedPixmap();
        void getUpHighSelectedPixmap();
        void getDownHighSelectedPixmap();

private:
        ZNumPickerData * d;
};

#endif  
