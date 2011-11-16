//Fix for E8/EM30 by Ant-ON, 25-10-2010

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZDETAILITEM_H
#define PUBLIC_API_WIDGET_ZDETAILITEM_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZWidget.h"
#include "ZSkinService.h"

class ZDetailView;
class ZDetailItemPrivate;

class ZDetailItem
{
public:

      enum ItemType
      {
          ItemTypeSeparator, 

	  ItemTypeA, 
	  ItemTypeB, 
          ItemTypeC, 
          ItemTypeD, 
          ItemTypeE, 
          ItemTypeF, 
          ItemTypeG, 
          ItemTypeH, 
          ItemTypeI, 
          ItemTypeJ  
      };

      enum FontType{FontTitle, FontContent, FontSDHighlighted, FontSDStandard};

      enum ColorType{ColorTitle, ColorContent, ColorSDHighlighted, ColorSDStandard};

      ZDetailItem(ItemType type, QString title = QString(""), QChar titleColon = QChar(), ZDetailView* parent = NULL);

      ZDetailItem(QString text = QString(""), QPixmap* icon = NULL, ZDetailView* parent = NULL);

      virtual ~ZDetailItem();

      void setReservedData(unsigned int rsvData);

      unsigned int getReservedData();

      void appendTextIconRow(QString text);

      void appendTextIconRow(QPixmap& icon);

      void appendTextIconRow(QString text, QPixmap& icon, bool IconLeftOrLabelBottom=TRUE);
      
	  void appendTextIconRow(QString text, QPixmap& icon1, QPixmap& icon2,
	  			bool IconLeftOrLabelBottom1=TRUE, bool IconLeftOrLabelBottom2=TRUE);//Add by Ant-ON

      void clearAllRow();

      void removeRow(uint index);

      ItemType itemType() const;

      void enableStructureDataParse(bool enable);

      void setParseType(QString type);

      void enableTitleParse(bool enable);

public:
      virtual void paint(QPainter& painter);

protected:

      void setParent(ZDetailView * parent);

      virtual int height(const ZDetailView *);

      void setRect(int x, int y, int w, int h);

      QRect rect() const;

      void setDirty(bool dirty);

      bool dirty() const;

      void doParse();
private:

     int separatorHeight(const ZDetailView * view);

      uint getSDCount() const;
      void getSDData(int index, QString& origin, QString& replaced, QString& type) const; 
      int currentSDIndex() const;
      QRect getSDRect(int index) const;
      void setCurrentSD(int index);

      ZDetailItemPrivate* d;

      friend class ZDetailView;
      friend class ZDetailItemPrivate;
};

#endif

