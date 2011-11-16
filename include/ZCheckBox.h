

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZCHECKBOX_H
#define PUBLIC_API_WIDGET_ZCHECKBOX_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZBaseButton.h"

class ZCheckBoxPrivate;

class Q_EXPORT ZCheckBox : public ZBaseButton
{
    Q_OBJECT
    Q_ENUMS(TitlePosition)
    Q_PROPERTY( bool checked READ isChecked WRITE setChecked )
    Q_PROPERTY( bool tristate READ isTristate WRITE setTristate )
    Q_PROPERTY( TitlePosition titlePosition READ titlePosition WRITE setTitlePosition )
public:
    enum TitlePosition
    {
        TitleTop = 0,      
        TitleLeft		 
    };

public:
    ZCheckBox( QWidget * parent, const char *name = 0 );

    ZCheckBox( const QString & text, QWidget * parent, const char* name = 0 );

    ~ZCheckBox();

    bool isZEnabled() const;

    bool isZDisabled() const;

    void setNoChange();

    void setTristate( bool y = TRUE );

    void setSpacing( const int H1, const int H2 );

    void setFormItemSpacing( const int S1 );

    bool isTristate() const;

    QSize sizeHint() const;

    virtual void setPixmap( const QPixmap & icon );

    const QPixmap * pixmap() const;

    const RelativeAlignment relativeAlignment() const;

    void setRelativeAlignment( const RelativeAlignment align );

    const AlignmentFlags groupAlignment() const;

    void setGroupAlignment( const AlignmentFlags align );

    void setTitle(const QString & string);

    QString title() const;

    TitlePosition titlePosition() const;

    void setTitlePosition(TitlePosition titlePos);

    void getFrameWidth(int & nleftf, int & nrightf, int & ntopf, int & nbottomf) const;

    int heightForWidth ( int w ) const;

    virtual void resize(int w, int h);

    virtual void setGeometry(int x,int y, int w, int h);

    virtual void setGeometry(const QRect & r);

    bool isChecked() const;

    void setChecked( bool check );

public slots:

    virtual void setEnabled( bool enable );

protected:
    virtual void keyPressEvent( QKeyEvent * e );

    virtual void keyReleaseEvent( QKeyEvent * e );


    virtual void setPalette( const QPalette & pal );

    void resizeEvent( QResizeEvent * );

    void drawButton( QPainter * );

    virtual void focusInEvent( QFocusEvent * e );

    virtual void focusOutEvent( QFocusEvent * e );

    void setSkinFocusEffect(QFocusEvent * e);

    QRect getCheckBtnRect() const;

    QSize getTitleSize() const;

    QRect getTitleRect() const;

    QRect getContentRect() const;

    void updateSkin(bool redraw);

private slots:

    void slotStateChanged( int );

private:
    ZCheckBoxPrivate * d;
    void init();
    void wrapLine();
    void wrapLine(int nTextWidth) const;
    int getTextHeight() const;
    QSize sizeForWidth(int w) const;

#if defined(Q_DISABLE_COPY)
    ZCheckBox( const ZCheckBox & );
    ZCheckBox &operator=( const ZCheckBox & );
#endif
};

#endif  
