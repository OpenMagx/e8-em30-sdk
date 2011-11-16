

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZSETTINGITEM_H
#define PUBLIC_API_WIDGET_ZSETTINGITEM_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>
#include <qlist.h>
#include <qfont.h>
#include <qpixmap.h>

#include "ZSkinService.h"
#include "ZWrapLine.h"
#include "ZText.h"
#include "ZListItem.h"

class ZListBox;
class ZSettingItemPrivate;

enum SettingItemRegion {SETTINGITEM_REGION_A, SETTINGITEM_REGION_B};

class SetSubItemInfo
{

public:

  SetSubItemInfo():marquee(NULL), isWrapable(false), region(SETTINGITEM_REGION_B){}

  ~SetSubItemInfo(){if(marquee) delete marquee;}

  QString  text;

  ZMarqueeText *marquee;

  bool isWrapable;

  SettingItemRegion region;
};

class SetItemInfo
{
public:

    SetItemInfo(QString t,int w,QPixmap* pixmap=NULL);

    ~SetItemInfo();

    QString type;

    short width;

    bool fixWidth;

    QPixmap* pm;

    QList<SetSubItemInfo> mtiList; 
};

class Q_EXPORT ZSettingItem : public ZListItem
{
public:        
    ZSettingItem( ZListBox* container = 0, const QString itemType = NULL);

    virtual ~ZSettingItem();

    int appendSubItem(int index, QString text, bool isWrapable = false);

    int appendSubItem(int index, QString text, bool isWrapable, SettingItemRegion region);

    int getSubItemCount(int index);

    QString getSubItemText(int index, int subIndex);

    bool deleteSubItem(int index, int subIndex);

    bool setSubItem(int index, int subIndex, QString text, bool isWrapable = false, SettingItemRegion region = SETTINGITEM_REGION_B);

    QPixmap getPixmap(int index);

    bool setPixmap(int index, const QPixmap& pixmap);

    virtual int width( const ZListBox * )  const;

    virtual int height( const ZListBox * ) const;

    bool setSortIndex(int index, int subIndex);

    int  sortIndex() const; 

    int  sortSubIndex() const;

    virtual QString getSortText() const;

  protected:

    virtual void paint( QPainter * );

 private:

    void drawTextColumn(QPainter *painter, int xp,SetItemInfo* item, int validWidth );

    int textColumnSubItemHeight(const ZListBox*, SetItemInfo* item, SetSubItemInfo* subItem, int width) const;
    int textColumnItemHeight(const ZListBox*, SetItemInfo* item, int width) const ;

    virtual void startMarquee();
    virtual void stopMarquee();
    virtual ListItemType listitemType() const;

  private:
    ZSettingItemPrivate *d;

};

#endif 

