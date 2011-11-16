

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZLISTITEM_H
#define PUBLIC_API_WIDGET_ZLISTITEM_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qlist.h>
#include <qfont.h>
#include <qpixmap.h>

#include "ZSkinService.h"
#include "ZWrapLine.h"
#include "ZText.h"
#include "ZSkinBase.h"

class ZListBox;
class ZListBoxClipper;

class Q_EXPORT ZListItem
{
public:        
    ZListItem( ZListBox* listbox, const QString itemType = NULL);

    virtual ~ZListItem();

    enum ListItemType {LISTBOXITEM, SETTINGITEM};

    QString getItemType() const;

    ZListBox* listBox() const;

    void setActive();

    void check(bool b);

    bool isChecked() const;

    QString getMarkColumnType() const;

    void setReservedData(unsigned int rsvData);

    unsigned int getReservedData();

    void setEnabled(bool enabled);

    bool enabled() const;

    bool selected() const;

    bool current() const;

    void setSelectable( bool b = FALSE );

    bool isSelectable() const;

    ZListItem *next() const;

    ZListItem *prev() const;

    void setWrapPolicy(ZWrapLine::WrapPolicy policy);

    ZWrapLine::WrapPolicy getWrapPolicy();

     void setZStyle(ZSkinService::WidgetClsID style);

     ZSkinService::WidgetClsID getZStyle() const;

     void setSeparator(const QString text, const QPixmap* icon = NULL);

     bool isSeparatorItem() const;

     virtual QString getSortText() const;

    virtual int width( const ZListBox * ) const;

    virtual int height( const ZListBox * ) const;

    void setPartialChecked(bool partial);

    bool partialChecked() const;

    void enableHighlight(bool hightlight);

    bool getEnableHighlight() const;

 protected:

    virtual void paint( QPainter * );

    int separatorHeight(const ZListBox* listbox) const;

    void drawSeparator(QPainter *painter, int x, int y, int width, int height);

 private:

    virtual void startMarquee();
    virtual void stopMarquee();

    virtual ListItemType listitemType() const;

 protected:

    void update(bool all);

    void drawImage(QPainter* painter, int x, int y, int width, int height, const QPixmap& pm, int flag);

    QString truncate(QString& str, int len, uint width, QFont& font, QString ellpsis = NULL);

    ZSkinBase::SelectionState getSelectionState();

 protected:

    ZListBox* lb;

    QString itemType;

    ZListItem * p, * n;

    enum ToggleState { OFF, NOCHANGE, ON};

    short stat;

    QPixmap* mSepIcon;

    QString* mSepText;

    ZMarqueeText* mSepMarqueeText;                                                                      

    unsigned int reserved;

    ZWrapLine::WrapPolicy wrapPolicy;

    ZSkinService::WidgetClsID itemClsId;

    uint down:1;

    uint isEnabled:1;

    uint isEnableHighlight:1;

    uint isSeparator:1;

    uint selectable:1;

    uint dirty:1;

    uint own_style:1;

    uint mPartialChecked : 1;

    friend class ZListBox;
    friend class ZListBoxClipper;
};

#endif 

