

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZLISTBOX_H
#define PUBLIC_API_WIDGET_ZLISTBOX_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "qpixmap.h"
#include "qtimer.h"

#include "ZSkinService.h"
#include "ZScrollPanel.h"
#include "ZListItem.h"
#include "ZListBoxItem.h"
#include "ZSettingItem.h"

//#define EM30

class ZListBoxPrivate;

class Q_EXPORT ZListBox : public ZScrollPanel
{
       friend class ZListItem;
       friend class ZListBoxItem;
       friend class ZSettingItem;
       friend class ZListBoxPrivate;

       Q_OBJECT

public:
      ZListBox( QWidget* parent = 0, WFlags f = 0,
                  ZSkinService::WidgetClsID clsId = ZSkinService::clsZListBox1 );

      ZListBox( QString type, QWidget* parent=0, WFlags f = 0,
                  ZSkinService::WidgetClsID clsId = ZSkinService::clsZListBox1);

      virtual ~ZListBox();

      void setListItemType(ZListItem::ListItemType type);

      uint count() const;

      void insertItem( const ZListItem * item, int index=-1, bool autoHighlighted = TRUE );

      void insertItem( const ZListItem * item, const ZListItem *after, bool autoHighlighted = TRUE);

      void clear();

      void changeItem( const ZListItem * item, int index );

      void takeItem( const ZListItem * item);

      void removeItem( int index );

      int currentItem() const;

      virtual void setCurrentItem( int index );

      virtual void setCurrentItem( ZListItem * item);

      int topItem() const;

      virtual void setTopItem( int index );

      virtual void setBottomItem( int index );

      //ZListItem *item( int index ) const;
      ZSettingItem *item( int index ) const;

      int index( const ZListItem * item) const;

      bool itemVisible( int index );

      bool itemVisible( const ZListItem * item);

      QRect itemRect( ZListItem *item ) const;

      ZListItem *firstItem() const;

      ZListItem *lastItem() const;

      void setSelected( int index, bool select);

      virtual void setSelected( ZListItem * item, bool select);

      bool isSelected( int index) const;

      bool isSelected( const ZListItem * item) const;

      void sort( bool ascending = TRUE );

      QSize sizeHint() const;

      QSize maxmumSizeHint() const;

      QSize minimumSizeHint() const;

      void triggerUpdate( bool doLayout );

      int itemHeight( int index = 0 ) const;

      virtual void  resetFocusItem(bool);

      virtual QRect getCurrentFocusRect(int) const;

      virtual bool  hasNextPrevFocusItem(bool)const;

      int getListBoxSpace(ZListItem*) const;

	QString getItemType();

	void setItemType( QString type );

	void checkItem( int index, bool select);

	bool itemChecked(int index);

	void checkItem( ZListItem* item, bool select );

	bool itemChecked( ZListItem* item );

        QList<ZListItem>* itemsChecked();

        int radioItemChecked();

        void moveItem(int from, int to);

      void updateSkin(bool redraw);

      void setZBorder( WIDGET_BORDER_INFO_T borderItems[StateCount]);

      void enableEllpsis(bool enable);

      bool isEnableEllpsis();

       void setCurrentItem(int index, bool next);

        typedef void (*DeleteItemCallBack)(ZListItem*);

        void setDeleteItemCallBackFunction(DeleteItemCallBack func);

        DeleteItemCallBack getDeleteItemCallBackFunction() const ;

       void setDefaultItemHeight(int height);

       int defaultItemHeight() const;

       ZSkinBase* getItemSkin(ZSkinService::WidgetClsID style, SelectionState state) const ;

public:

        enum ITEMALIGN{ALIGN_MARK, ALIGN_IMAGE, ALIGN_REGION_A, ALIGN_REGION_B, ALIGN_REGION_C, ALIGN_ROWTYPETHREE};

        void setAlign(ITEMALIGN element, int align);

        int align(ITEMALIGN element) const;

      enum ListItemRegion 
         {LISTITEM_REGION_A,
          LISTITEM_REGION_B, 
          LISTITEM_REGION_C};

      void setEllpsis(QString ellpsis, ListItemRegion region = LISTITEM_REGION_C);

      QString getEllpsis(ListItemRegion region = LISTITEM_REGION_C);

      void setZItemStyle(ZSkinService::WidgetClsID style);

      ZSkinService::WidgetClsID getZItemStyle(bool isSeparator = FALSE) const;

       void setItemFont(ListItemRegion region, SelectionState state, QFont& font);

       QFont& itemFont(ListItemRegion region, SelectionState state) const;

       void enableMarquee(ListItemRegion region, bool enable);

       bool marqueeEnabled(ListItemRegion region) const;

  public:
        void setShowSubItemIcon(bool show);

        bool isShowSubItemIcon() const;

        void showAllSubItem(bool bShow = true);

        bool isShowAllSubItem() const;

        ZListItem * itemAt( QPoint pt) const;

	void setPartialColor(QColor &c,SelectionState state);

	QColor getPartialColor(SelectionState state);
    QColor getPartialColor(SelectionState state, ListItemRegion region);

#ifndef QT_NO_PALETTE
     void setPalette( const QPalette & );
#endif


public:
       void setItemFont(ListItemRegion region, QFont& font, bool highlighted = FALSE);

       QFont& getItemFont(ListItemRegion region, bool highlighted = FALSE) const;

public slots:
    virtual void ensureCurrentVisible();

signals:

    void highlighted( int index );

    void highlighted( ZListItem * );

    void highlighted( ZListBoxItem * );

    void highlighted( ZSettingItem * );

    void selected( int index );

    void selected( ZListItem * );

    void selected( ZListBoxItem * );

    void selected( ZSettingItem * );

    void selectionChanged( ZListItem * );

    void selectionChanged( ZListBoxItem * );

    void selectionChanged( ZSettingItem * );

    void currentChanged( ZListItem * );

    void currentChanged( ZListBoxItem * );

    void currentChanged( ZSettingItem * );

    void returnPressed( int );

    void returnPressed( ZListItem * );

    void returnPressed( ZListBoxItem * );

    void returnPressed( ZSettingItem * );

    void clicked( ZListItem * );

    void clicked( ZListItem *, const QPoint & );

    void doubleClicked( ZListItem * );

    void showedSubItemChanged(int index, int subIndex);

protected:


    void viewportResizeEvent( QResizeEvent* );
    void hideEvent ( QHideEvent * );
   void viewportPaintEvent( QPaintEvent * event);

    void viewportMousePressEvent( QMouseEvent * );

    void mousePressEvent ( QMouseEvent * );

    void viewportMouseDoubleClickEvent( QMouseEvent * );

    void mouseDoubleClickEvent( QMouseEvent * );

    void keyPressEvent( QKeyEvent *e );

    void focusInEvent( QFocusEvent *e );

    void focusOutEvent( QFocusEvent *e );

    void resizeEvent( QResizeEvent * );

    void showEvent( QShowEvent * );

    void updateItem( int index );

    void updateItem( ZListItem * );

    void toggleCurrentItem();

    void doLayout() const;

private slots:
    void refreshSlot();
    void adjustItems();
    void slotWaitWrapFinished();

private:
	//fix em30
	#ifdef EM30
	char tmp[128];
	#endif
	
    void init(QString type,QWidget * parent,WFlags f, const ZSkinService::WidgetClsID clsId );
    void selectBtns(ZListItem* it);

    void tryGeometry( int, int ) const;

    int numRows() const; 
    int currentRow() const;
    int rowAt( int ) const;

    void setFontData(QFont& font, int size, int style) const;

    int getMaxItemWidth() const;

    QPixmap& indImage(SelectionState state)const;
    QPixmap& markImage(SelectionState state, bool single, bool partial) const;

    void setSeparatorFont(QFont& font);
    QFont& getSeparatorFont() const;

    QPixmap& getSeparatorImage(int index) const;
    ZSkinBase* getSeparatorSkin(ZSkinService::WidgetClsID) const;

    ZSkinBase* getImageContainerSkin(SelectionState state);

    int textAlign(ListItemRegion region, SelectionState state);
    QColor textColor(ListItemRegion region, SelectionState state);

    ZListBoxPrivate * d;

    int scrollingInPage(int n);

    int scrollingInNextPage(int n, bool keepLast);

    bool isHighlightTop();

    bool isHighlightBottom();

    void setHighlightTop();

    void setHighlightBottom();

    ZListItem *findEdge(bool isBottom);

    void omgPageUp(QKeyEvent *e);

    void omgPageDown(QKeyEvent *e);

    void omgScroll(QKeyEvent *e);
};

#endif  

