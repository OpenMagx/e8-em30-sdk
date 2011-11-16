

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZNAVTABWIDGET_H
#define PUBLIC_API_WIDGET_ZNAVTABWIDGET_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZWidget.h"
#include "qiconset.h"
#include "ZSkinBase.h"
#include "ZSkinService.h"
class ZNavTabBar;
class ZNavTabWidgetData;
class ZNavTab;
class ZNavWidgetStack;

class ZNavTabWidget : public ZWidget
{
    Q_OBJECT
    Q_PROPERTY( TabPosition tabPosition READ tabPosition WRITE setTabPosition )
    Q_PROPERTY( int margin READ margin WRITE setMargin )
    Q_PROPERTY( int currentPage READ currentPageIndex WRITE setCurrentPage )

public:
    enum TabPosition { TOP, BOTTOM };
    enum ButtonPos{NEIGHBOR,SEPARATE};

    ZNavTabWidget( QWidget *parent = 0, const char *name = 0,
        const ZSkinService::WidgetClsID clsId = ZSkinService::clsZNavTabWidget);

    ZNavTabWidget(int nButtonPos,bool bHeaderVisible = false,bool bCountVisible = false,
       QWidget *parent=0, const char *name=0,
       const ZSkinService::WidgetClsID clsId = ZSkinService::clsZNavTabWidget);

    void stopNextWhenKeyRepeat(bool bStop = FALSE);

    void setLabelCountVisible(bool bLabelCountVisible);

    void setSubHeaderVisible( bool bHeaderVisible);

    ~ZNavTabWidget();

    void addTab( QWidget *child, const QString &label);

    void addTab( QWidget *child, const QIconSet& iconset, const QString &label);

    void addTab( QWidget *child, ZNavTab *tab );

    void insertTab( QWidget *child, const QString &label, int index = -1);

    void insertTab( QWidget *child, const QIconSet& iconset, const QString &label, int index = -1);

    void insertTab( QWidget *child, ZNavTab *tab, int index = -1 );

    void changeTab( QWidget *w, const QString &label);

    void changeTab( QWidget *child, const QIconSet& iconset, const QString &label);

    bool isTabEnabled(  QWidget *w ) const;

    void setTabEnabled( QWidget *w, bool enable);

    void showPage( QWidget *w );

    void removePage( QWidget *w );

    QString tabLabel( QWidget *w ); 

    QWidget * currentPage() const;

    int currentPageIndex() const;

    void setCurrentPage( int id);

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    TabPosition tabPosition() const;

    void setTabPosition( TabPosition pos);

    int margin() const;
    void setMargin( int w);

    QSizePolicy sizePolicy() const;

    void setSpacingH1(short nSpacing);

    short getSpacingH1()const;

    void  setEnabled(bool enable);

    bool  isZEnabled();
    bool  isZDisabled();
protected:
    void showEvent( QShowEvent * );
    void resizeEvent( QResizeEvent * );
    void setTabBar( ZNavTabBar* );

    ZNavTabBar* tabBar() const;
    void styleChange( QStyle& );
    void updateMask();
    bool eventFilter( QObject *, QEvent * );
    void paintEvent(QPaintEvent *);
    void updateSkin(bool redraw);
    virtual void setPalette(const QPalette &palette);

signals:
    void currentChanged( QWidget * );
    void selected( const QString& ); 

private slots:
    void showTab( int i );

    void scrollTabs();

private:
    ZNavTabWidgetData *d;
    void setUpStack(bool = FALSE);
    void setUpBar(bool = FALSE);
    void setUpLayout(bool = FALSE);
    void init( int nButtonPos);

private:        
#if defined(Q_DISABLE_COPY)
	ZNavTabWidget( const ZNavTabWidget & );
    ZNavTabWidget& operator=( const ZNavTabWidget & );
#endif
};
#endif 
