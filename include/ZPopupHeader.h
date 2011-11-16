

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ZPOPUPHEADER_H
#define ZPOPUPHEADER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZWidget.h"

class QPixmap;

class ZPopupHeaderPrivate;

class ZPopupHeader : public ZWidget
{
    Q_OBJECT

public:

    enum HEADER_TYPE_E
    {
        STANDARD,
        TWO_LINE
    };

    ZPopupHeader( HEADER_TYPE_E type = STANDARD, QWidget *parent = 0, const char *name = 0, WFlags f = 0 );

    ~ZPopupHeader( );

    void setType( HEADER_TYPE_E type );

    HEADER_TYPE_E getType( ) const;

    void setPrimaryTitle( const QString &title );

    QString getPrimaryTitle( ) const;

    void setSecondaryTitle( const QString &title );

    QString getSecondaryTitle( ) const;

    void setIcon( const QString &id, int pos = 0 );

    void setIcon( const QPixmap &icon, int pos = 0 );

    void setTitleFont(const QFont&, int pos = 0);

    void setTitleColor(const QColor&, int pos = 0);

    void setTitleOutline(bool, int pos = 0);

    void setTitleOutlineColor(const QColor&, int pos = 0);

    void setTitleAlignment(int, int pos = 0);

    void setHSpacing(int h);

    void setVSpacing(int v);

    virtual void doLayout();

    virtual void setPalette (const QPalette& p);

public slots:
    void setGeometry( int x, int y, int w, int h );

protected:

    void showEvent( QShowEvent *e );

    void paintEvent( QPaintEvent *e );

private:
    void setAniIcon(const QString& strResID);

private slots:

    void slotAnimationStatus(int);
    void slotAnimationUpdate(const QRect&);

private:

    ZPopupHeaderPrivate *mpData;
};

#endif  
