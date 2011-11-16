//Fix for E8/EM30 by Ant-ON, 25-10-2010

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZOPTIONSMENU_H
#define PUBLIC_API_WIDGET_ZOPTIONSMENU_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qfont.h>
#include <qframe.h>
#include <qlist.h>
#include <qmap.h>
#include "ZWidget.h"
#include "ZSkinService.h"

#include "ZOptMenuParser.h"  

class QSignal;
class ZOptionsMenu;
struct ZOptionsMenuItemPrivate;


class Q_EXPORT ZOptionsMenuItem
{
public:

    virtual ~ZOptionsMenuItem();

    QString text() const;

    void setText( const QString & text );

    ZOptionsMenu* subMenu() const;

protected:
    ZOptionsMenuItem( ZOptionsMenu * menu );

    virtual void paint( QPainter * painter, int x1, int y1, int x2, int y2 );

    void drawHighlight(QPainter& painter,const QRect* r, bool border);

private:
    virtual void calcHeight();

private:
    ZOptionsMenuItemPrivate * dd;
    friend class ZOptionsMenu;
};

typedef QList<ZOptionsMenuItem> ZOptionsMenuItemList;

typedef QListIterator<ZOptionsMenuItem> ZOptionsMenuItemListIt;

typedef QList<ZOptionsMenu> ZSubMenuIList;

class ZOptionsMenuPrivate;

class Q_EXPORT ZOptionsMenu : public ZWidget
{

    Q_OBJECT

public:

    enum CornerE
    {
        TopLeft,
        TopRight,
        BottomLeft,
        BottomRight
    };

    enum EffectsE
    {
        NoEffect,
        Scroll,
        Fade
    };

    ZOptionsMenu( QRect & limitRect, QWidget * parent = 0, const char * name = 0,
                             WFlags f = 0, const ZSkinService::WidgetClsID clsId = ZSkinService::clsZOptionsMenu
                              
                             );

    ZOptionsMenu( QRect & limitRect, QWidget * parent, const char * name,
                             WFlags f, const ZSkinService::WidgetClsID clsId,
                             ZOptMenuParser * parserClass, QString menuName
                             
                             );

     ZOptionsMenu( QRect & limitRect, QWidget * parent, const char * name,
                              WFlags f, const ZSkinService::WidgetClsID clsId,
                              QString fileName, QString menuName
                              
                              );

    virtual ~ZOptionsMenu();

	// Add by Ant-ON
	void allow_uncheck_items();
	void forbid_uncheck_items();
	void emitSignalMenuToShow();
	void moveItem(int i, int to);
	
	virtual QSize sizeHint();
	
	//

    void setMenu( ZOptMenuParser * parserClass, QString menuName);

    void setMenu( QString fileName, QString menuName);

    virtual void setActiveItem( int index );

    int getActiveItemId();

    int getCurrentSelectedItemId();

    bool isItemChecked( int id ) const;

    void setItemChecked( int id, bool check );

    void setItemCheckable( int id, bool checkable );

    void changeItem( int id, const QString &text, const QPixmap * pixmap = NULL );

    void clear();

    bool connectItem( int id, const QObject * receiver, const char * memberFunc );

    bool disconnectItem( int id, const QObject * receiver, const char * memberFunc );

    uint count();

    QString disabledReason( int id ) const;

    int getIdFromIndex( int index );

    int getIndexFromId( int id );

    ZOptionsMenuItem * findItem( int id, ZOptionsMenu ** parent = 0 ) const;

    void setDisabledReason( int id, const QString & reason );

    void setDisabledReasonDlgTitle( int id, const QString & title );

    bool isItemEnabled( int id ) const;

    void setItemEnabled( int id, bool enable );

    void setSpacing( const int V1 );

    void setItemSpacing( const int H1 );

    void setItemPadding( const WIDGET_PADDING_INFO_T & pad );

    int insertItem(
        const QString & text,
        const QPixmap * pixmap = NULL,
        const QObject * receiver = NULL,
        const char * memberFunc = NULL,
        bool enable = true,
        bool checkable = false,
        bool checked = false,
        int id = -1,
        int index = -1,
	bool hide = false );

    int insertItem(
        const QString & text,
        ZOptionsMenu * sub,
        const QPixmap * pixmap = NULL,
        bool enable = true,
        int id = -1,
        int index = -1,
	bool hide = false,
        bool checkable = false,
        bool checked = false );

    //int insertItem( ZOptionsMenuItem * item, int id = -1, int index = -1 );

    int insertSeparator( int id = -1, int index = -1 );

    void setFixedWidth( int width );

    void unsetFixedWidth();

    void removeItem( int id, bool needUpdate = TRUE );

    QRect limitRect() const;

    void setLimitRect( const QRect & rect );

    void setLimitRect( int maxLineNum = 5 );

    void setPosition( CornerE corner, QPoint & point );

    AlignmentFlags textAlignment() const;

    void setTextAlignment( AlignmentFlags align );

    bool wrap() const;

    void setWrap( bool wrap );

    bool isItemHided( int id ) const;

    void setItemHide(int id, bool hided);

     void setItemSubMenu(int id, ZOptionsMenu * sub);

     ZOptionsMenu* getItemSubMenu(int id);

    itemList getAllItemIds();

    int getItemParentId( int id );

    int getItemSubMenuNum( int id );

    virtual void setPalette( const QPalette & );
    
    //void setAutoAddCloseItem(bool bAutoAddCloseItem);
    
    //bool isAutoAddCloseItem();
    
signals:

    void aboutToHide();

    void aboutToShow();

    void activated( int itemId );

    void canceled();

    void highlighted( int itemId );

    void lSoftkeyDown();

    void lSoftkeyUp();

    void rSoftkeyDown();

    void rSoftkeyUp();
    
    //Add by Ant-ON
    void optionMenuToShow(); //???
    //

public slots:
    virtual void hide();

    void popup();

    virtual void show();

protected:


    void hideEvent( QHideEvent * );

    virtual void closeEvent( QCloseEvent * e );

    virtual void focusInEvent( QFocusEvent * e );

    virtual void focusOutEvent( QFocusEvent * e );

    virtual void paintEvent( QPaintEvent * e );

    virtual void drawScrollIndicator( QPainter * painter );

    virtual void fontChange( const QFont & oldFont );

    virtual void keyReleaseEvent( QKeyEvent * e);

    virtual void keyPressEvent( QKeyEvent * e );
    
    //Add by Ant-ON
    virtual void timerEvent( QTimerEvent * );
    //

private slots:
    void slotWaitWrapFinished();

    void objectDestroyed();
    
    //void clickCloseItem();
    
private:
    void startMarquee();
    int insertItemToMenu(ZOptionsMenuItem *item, int id, int index);

    void init( QRect & limitRect );

    void ItemState( ZOptionsMenu * menu, ZOptionsMenu * subMenu, menuItem * item );
    void getListFromConfig( itemList & iList, QString fileName, QString screenName );
    void genMenu( QRect & limitRect, itemList myList );
    void removeItemFromVisibleList( ZOptionsMenu* pMenu, ZOptionsMenuItem* pItem );
    void resetHS( ZOptionsMenu* pMenu );
    bool getMenuDisplayState( ZOptionsMenu * menu );

    void initShow();
    void onShortcut( QKeyEvent * e );

    void updateSize();

    void updateVisibleItems( int index, bool atBottom );

private:
    ZOptionsMenuPrivate * d;

    friend class ZOptionsMenuItem;

    int scrollingInPage(int n);

    int scrollingInNextPage(int n, bool keepLast);

    bool isHighlightTop();

    bool isHighlightBottom();

    void setHighlightTop();

    void setHighlightBottom();

    int findEdge(bool isBottom);

    void omgScroll(QKeyEvent *e);
};

#endif 

