

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZLISTBOXITEM_H
#define PUBLIC_API_WIDGET_ZLISTBOXITEM_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>
#include <qstringlist.h>
#include <qmap.h>
#include <qlist.h>
#include <qfont.h>
#include <qpixmap.h>
#include <qevent.h>

#include "ZSkinService.h"
#include "ZWrapLine.h"
#include "ZText.h"
#include "ZListItem.h"

class ZListBox;
class ZListBoxClipper;
class ZListBoxItemPrivate;

class LBSubItemInfo
{
public:

  enum TEXTROWTYPE {ROWTYPE_ONE, ROWTYPE_TWO, ROWTYPE_THREE};

  LBSubItemInfo():type(ROWTYPE_TWO), marquee1(NULL), marquee2(NULL), isWrapable(false), showed(FALSE),icon(NULL), iconList(NULL), iconCount(0),region(0),pos(0),length(0){}

  ~LBSubItemInfo(){if(iconList) delete[] iconList; if(icon) delete icon; if(marquee1)delete marquee1;if(marquee2)delete marquee2;}

  TEXTROWTYPE type;

  QString  text;

  QString text2;

  ZMarqueeText* marquee1;

  ZMarqueeText* marquee2;

  ushort priority;

  ushort percent;

  bool isWrapable;

  bool showed;

  QPixmap* icon;

  QPixmap* iconList;

  short iconCount;

  uint region:1;
  int pos;
  int length;
};

class LBItemInfo
{
public:

    LBItemInfo(char t, int w, QPixmap* pixmap=NULL);

    ~LBItemInfo();

    char type;

    short width;

    short showedSubItem;

    uint fixWidth : 1;

    uint show : 1;

    uint imageContainer : 1;

    QPixmap* pm;

    QList<LBSubItemInfo> mtiList; 
};

class Q_EXPORT ZListBoxItem : public ZListItem
{
public:        
    ZListBoxItem( ZListBox* listbox, const QString itemType = NULL);

    virtual ~ZListBoxItem();

    enum ShowPriority
    {
       FirstPriority , 
       SecondPriority, 
       EquityPriority 
    };

    int appendSubItem(int index, const QString text, const QString text2, const QPixmap* icon = NULL, 
                      uint percent = 50, ShowPriority priority = EquityPriority);

    int appendSubItem(int index, const QString text, bool isWrapable = false, const QPixmap* icon = NULL);

    int appendSubItem(int index, QPixmap* iconList, uint count);

    QString getSubItemText(int index, int subIndex, bool text2 = false);

    QList<QPixmap> getSubItemIcon(int index, int subIndex);

    bool deleteSubItem(int index, int subIndex);

    bool setSubItem(int index, int subIndex, QString text, QString text2, const QPixmap* icon = NULL, uint percent = 50);

    bool setSubItem(int index, int subIndex, QString text, bool isWrapable = false, const QPixmap* icon = NULL);

    bool setSubItem(int index, int subIndex, QPixmap* iconList, uint count);

    int getCurrentSubItem(int index);

    void setCurrentSubItem(int index, int subIndex, bool doUpdate = true);

    void setSubItemShowed(int index, int subIndex, bool showed, bool doUpdate = true);

    QPixmap getPixmap(int index);

    bool setPixmap(int index, const QPixmap& pixmap, bool doUpdate = true, bool imageContainer = false);

    void setShowIndicator(bool isShow);

    void keyPressEvent( QKeyEvent *e );

     void showColumn(int index, bool show);

    bool setSortIndex(int index, int subIndex);

    int  sortIndex() const; 

    int  sortSubIndex() const;

    virtual QString getSortText() const;

    virtual int width( const ZListBox * )  const;

    virtual int height( const ZListBox * ) const;

    void setPartialStrInfo(int index,int subindex,int region,int pos,int length);

protected:
    virtual void paint( QPainter * );

    void drawColumnBImage(QPainter* painter,int x, int y, int width, int height, QPixmap* pm);

private:
    virtual void startMarquee();
    virtual void stopMarquee();
    virtual ListItemType listitemType() const {return LISTBOXITEM;}

    void drawTextColumn(QPainter *painter, int xp,LBItemInfo* item, int validWidth );

    int textColumnSubItemHeight(const ZListBox* listbox, LBItemInfo* item, LBSubItemInfo* subItem, int width) const;
    int textColumnItemHeight(const ZListBox* listbox, LBItemInfo* item, int width) const ;

    int prevShowedSubItem(LBItemInfo* item);
    int nextShowedSubItem(LBItemInfo* item);

    bool isIndicatorShowed(LBItemInfo* item) const;
    bool isShowSubItemIcon() const;

    void setCacheEnable(bool isEnable);
    friend void enalbeAllItemsCache(QList<ZListBoxItem>& list);

private:
    ZListBoxItemPrivate *d;
};

#endif 

