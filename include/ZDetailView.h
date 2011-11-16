//Fix for E8/EM30 by Ant-ON, 25-10-2010

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZDETAILVIEW_H
#define PUBLIC_API_WIDGET_ZDETAILVIEW_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZScrollPanel.h"
#include "ZDetailItem.h"
#include "ZSeparator.h"
#include "ZWrapLine.h"
#include "ZStructureDataParser.h"

class ZDetailViewPrivate;

class Q_EXPORT ZDetailView : public ZScrollPanel
{
       Q_OBJECT

public:
      ZDetailView( QWidget* parent = 0, WFlags f = 0,
                  ZSkinService::WidgetClsID clsId = ZSkinService::clsZDetailView1 );

      virtual ~ZDetailView();

      void addItem(ZDetailItem* item);

      void removeItem(ZDetailItem* item);

      void insertIntem(ZDetailItem* item, ZDetailItem* after);

      void triggerUpdate( bool doLayout );

      QRect itemRect( ZDetailItem *item ) const;

      QSize maxmumSizeHint() const;

      void setStructureDataParser(ZStructureDataParser* parser);

      ZStructureDataParser* getStructureDataParser() const;

      void setWrapPolicy(ZWrapLine::WrapPolicy);

      ZDetailItem* current() const;

      int currentSDIndex() const;

      uint getStructureDataCount() const;

      bool getStructureData(int id, QString& origin, QString& replaced, QString& type);

      void setFont(ZDetailItem::FontType type, QFont& font);

      QFont& font(ZDetailItem::FontType) const;

      //void enableItemHighlight(bool enable);

public:

      virtual uint getStepInScrollPanel(bool) const;

      virtual void  resetFocusItem(bool);

      virtual QRect getCurrentFocusRect(int) const;

      virtual bool  hasNextPrevFocusItem(bool)const;

      virtual bool noFocusMode() const;

public:
    void updateSkin(bool redraw);

#ifndef QT_NO_PALETTE
    void setPalette( const QPalette & );
#endif

signals:

    void returnPressed(const ZDetailItem* item, const QString & origin, const QString & replaced, const QString & type);

    void highlighted(const ZDetailItem* item, const QString & origin, const QString & replaced, const QString & type);

protected:

    void viewportPaintEvent( QPaintEvent * event);

    void keyPressEvent( QKeyEvent *e );

    void resizeEvent( QResizeEvent * );

    void focusInEvent( QFocusEvent *e );

    void focusOutEvent( QFocusEvent *e );

    void showEvent (QShowEvent*);

    void updateItem( ZDetailItem * );


private slots:
    void refreshSlot();
    void slotWaitWrapFinished();

private:
    void doLayout() const;
    int getMaxItemWidth() const;
    int wrapSpace() const;
    QColor color(ZDetailItem::ColorType) const;
    ZWrapLine::WrapPolicy wrapPolicy() const;
    void ensureCurrentVisible();
    QFont& getSeparatorFont() const;
    QPixmap& getSeparatorImage(int index) const;
    ZSkinBase* getSeparatorSkin() const;
    ZSkinBase* getItemSkin() const;    
    void setFontData(QFont& font, int size, int style) const;

    uint getSDCount() const;
    QRect getSDRect(int index) const;
    void setCurrentSD(int index, bool scroll = TRUE);

    bool isOutlined() const;
    int outlinedSize() const;
    int outlinedColor() const;

    ZDetailViewPrivate * d;

    friend class ZDetailItem;
    friend class ZDetailItemPrivate;

    void setViewTop();
    void setViewBottom();
    bool isViewTop();
    bool isViewBottom();
    bool scrollN(int n);
    bool scrollInScrollPanel(int n);
    void omgPageUp(QKeyEvent *e);

    void omgPageDown(QKeyEvent *e);

    void omgScroll(QKeyEvent *e);
};

#endif

