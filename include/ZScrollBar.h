/////////////////////////////////////////////////////////////////////
/// $Id: qt/src/widgets/qscrollbar.h   2.3.6   edited 2001-01-26 $
///
/// Definition of QScrollBar class
///
/// Created : 941115
///
/// Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
///
/// This file is part of the widgets module of the Qt GUI Toolkit.
///
/// This file may be distributed under the terms of the Q Public License
/// as defined by Trolltech AS of Norway and appearing in the file
/// LICENSE.QPL included in the packaging of this file.
///
/// This file may be distributed and/or modified under the terms of the
/// GNU General Public License version 2 as published by the Free Software
/// Foundation and appearing in the file LICENSE.GPL included in the
/// packaging of this file.
///
/// Licensees holding valid Qt Enterprise Edition or Qt Professional Edition
/// licenses may use this file in accordance with the Qt Commercial License
/// Agreement provided with the Software.
///
/// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
/// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
///
/// See http://www.trolltech.com/pricing.html or email sales@trolltech.com for
///   information about Qt Commercial License Agreements.
/// See http://www.trolltech.com/qpl/ for QPL licensing information.
/// See http://www.trolltech.com/gpl/ for GPL licensing information.
///
/// Contact info@trolltech.com if any conditions of this licensing are
/// not clear to you.
///
/// Motorola changes the file for Linux Java
///
///Drafted Header Files, will be revised in LJ6.3. They can be private or renamed
///
///////////////////////////////////////////////////////////////////////////
#ifndef PUBLIC_API_WIDGET_ZSCROLLBAR_H
#define PUBLIC_API_WIDGET_ZSCROLLBAR_H

class QTimer;

#ifndef QT_H
#include "qwidget.h"
#include "qrangecontrol.h"
#include "qdrawutil.h" // REMOVE THIS IN 3.0
#endif // QT_H

#include "ZWidget.h"

#ifndef QT_NO_SCROLLBAR

class ZScrollBarPrivate;

/// The widget provides a vertical or horizontal scroll bar.

/// For more information, please refer to /vobs/ezx_qt/code/doc/html/qscrollbar.html

class Q_EXPORT ZScrollBar : public ZWidget, public QRangeControl
{
    Q_OBJECT
public:
    enum Orientation {
        Horizontal,     ///< horizontal scrollbar
        Vertical        ///< vertical scrollbar
    };

    ///
    /// indicate if increment or decrement button is selected.
    ///
    enum INCORDEC {
        NEITHER_SELECT, ///< neither increment nor decrement
        INC_SELECT,     ///< increment
        DEC_SELECT      ///< decrement
    };

    ZScrollBar(QWidget *parent, const char *name = 0, WFlags f = 0,
        ZSkinService::WidgetClsID clsId = ZSkinService::clsZScrollbar);

    ZScrollBar(Orientation orientation,
        QWidget *parent, const char *name = 0, WFlags f = 0,
        ZSkinService::WidgetClsID clsId = ZSkinService::clsZScrollbar);

    ZScrollBar(int minValue, int maxValue,
        int LineStep, int PageStep, int value,
        Orientation orientation, QWidget *parent,
        const char *name = 0, WFlags f = 0,
        ZSkinService::WidgetClsID clsId = ZSkinService::clsZScrollbar);

    ~ZScrollBar();
    virtual void setOrientation( Orientation );
    Orientation orientation() const;
    //virtual void setTracking( bool enable );
    //bool tracking() const;
    //bool draggingSlider() const;

    virtual void setPalette( const QPalette & );
    void updateSkin(bool redraw);
    // obsolete!!!
    QSize	sizeHint() const;
    /// this function will be replaced sizeHint() function in the further
    /// version. It returns width of vertical scroll bar or height of
    /// horizontal scroll bar.
    int getExtent() const;

    //QSizePolicy sizePolicy() const;

    int	 minValue() const;
    int	 maxValue() const;
    void setMinValue( int );
    void setMaxValue( int );
    int	 lineStep() const;
    int	 pageStep() const;
    void setLineStep( int );
    void setPageStep( int );
    int  value() const;
    ///
    /// When value is changed, the increment or decrement button can show
    /// pictures in selection status as user specified
    ///
    void setValue(int v, enum INCORDEC s = NEITHER_SELECT);

    ///
signals:
    void	valueChanged( int value );
    void	sliderPressed();
    void	sliderMoved( int value );
    void	sliderReleased();
    void	nextLine();
    void	prevLine();
    void	nextPage();
    void	prevPage();
protected slots:
    ///
    /// recover increment or decrement button to standard status
    ///
    void slotRecoverStdStatus();
protected:
    //void 	wheelEvent( QWheelEvent * );
    //void keyPressEvent( QKeyEvent * );
    void	resizeEvent( QResizeEvent * );
    void	paintEvent( QPaintEvent * );

    //void	mousePressEvent( QMouseEvent * );
    //void	mouseReleaseEvent( QMouseEvent * );
    //void	mouseMoveEvent( QMouseEvent * );

    void	valueChange();
    void	stepChange();
    void	rangeChange();

    int		sliderStart() const;

    // obsolete!!!
    QRect	sliderRect() const;

    //void styleChange( QStyle& );
private:
    void init();
    //void updateSkinParam();

    void positionSliderFromValue()  const;
    int rangeValueToSliderPos( int val )  const;
    //int calculateValueFromSlider() const;

    void sliderMinMax( int &, int & )		const;
    void metrics(int &, int &, int &) const;

    QPixmap getIncPixmap() const;
    QPixmap getDecPixmap() const;
    //void startAutoRepeat();
    //void stopAutoRepeat();

    //QStyle::ScrollControl pointOver( const QPoint &p ) const;

    //int sliderPosToRangeValue( int  val ) const;

    //void action( QStyle::ScrollControl control );

    void drawControls();
    //void drawControls( uint controls, uint activeControl,
    //    QPainter *p ) const;
private:    
    ZScrollBarPrivate* d;
};

#endif // QT_NO_SCROLLBAR

#endif // QSCROLLBAR_H
