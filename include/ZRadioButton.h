

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZRADIOBUTTON_H
#define PUBLIC_API_WIDGET_ZRADIOBUTTON_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZBaseButton.h"
#include "ZSkinService.h"

class ZRadioButtonPrivate;

class Q_EXPORT ZRadioButton : public ZBaseButton
{
    Q_OBJECT
    Q_PROPERTY( bool checked READ isChecked WRITE setChecked )

public:
    ZRadioButton(
        QWidget * parent,
        const char * name = 0,
        const ZSkinService::WidgetClsID clsId = ZSkinService::clsZRadioButton );

    ZRadioButton(
        const QString& text,
        QWidget * parent,
        const char * name = 0,
        const ZSkinService::WidgetClsID clsId = ZSkinService::clsZRadioButton );

    ~ZRadioButton();

    virtual void setChecked( bool check );

    bool isZEnabled() const;

    bool isZDisabled() const;

    bool isChecked() const;

    QSize sizeHint() const;

    QSizePolicy sizePolicy() const;

    virtual void setPixmap( const QPixmap & pixmap );

    const QPixmap * pixmap() const;

    const RelativeAlignment relativeAlignment() const;

    void setRelativeAlignment( const RelativeAlignment align );

    void setSpacing( const int H1, const int H2 );

    const AlignmentFlags groupAlignment() const;

    void setGroupAlignment( const AlignmentFlags align );

    int heightForWidth ( int w ) const;

signals:

    void checked( ZRadioButton * pRadio );

public slots:

    virtual void setEnabled( bool enable );

protected:
    virtual void keyPressEvent( QKeyEvent * e );

    virtual void keyReleaseEvent( QKeyEvent * e );


    virtual void setPalette( const QPalette & pal );

    bool hitButton( const QPoint & ) const;

    void drawButton( QPainter * );

    void resizeEvent( QResizeEvent * );

    void focusInEvent( QFocusEvent * );

    void updateMask();

    virtual void focusOutEvent( QFocusEvent * e );

    void updateSkin(bool redraw);

    void setSkinFocusEffect(QFocusEvent * e);

private:

    void init( const ZSkinService::WidgetClsID clsId );

    void wrapLine();
    void wrapLine(int nWidth) const;
    QSize sizeForWidth(int nWidth) const;
    int getTextHeight() const; 

private slots:

    void slotStateChanged( int );

private:

    ZRadioButtonPrivate * d;

#if defined(Q_DISABLE_COPY)
    ZRadioButton( const ZRadioButton & );
    ZRadioButton &operator=( const ZRadioButton & );
#endif
};

#endif  
