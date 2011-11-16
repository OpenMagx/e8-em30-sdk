

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZSKINBASE_H
#define PUBLIC_API_WIDGET_ZSKINBASE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>
#include <qpixmap.h>
#include <qfont.h>
#include <qpainter.h>
#include <qwidget.h>
#include <ZSkinService.h>
#include "ZSkinTool.h"
#include <qbitmap.h>

class QBitArray;
class ZWidget;

class ZSkinBase
{
  public:

    struct BorderPixmaps
    {
        QString id;
        QPixmap left; 
        QPixmap right;
        QPixmap top;
        QPixmap bottom;
        QPixmap topLeft;
        QPixmap topRight;
        QPixmap bottomLeft;
        QPixmap bottomRight;
    };

    enum BorderType 
    {
       Empty_Border = 0, 
       Color_Border, 
       Pixmap_Border
    };

    enum BackgroundType 
    {
       Empty_Background = 0, 
       Color_Background, 
       Pixmap_Background
    };

    enum SelectionState
    {
        StStandard = 0,
        StHighlighted,
        StSelected,
        StHighlightSelected,
        StateCount = StHighlightSelected + 1
    };

    enum BorderSide
    {
       BorderLeft = 0,
       BorderTop,
       BorderRight,
       BorderBottom
    };

  public:

    ZSkinBase(ZWidget& w, const ZSkinService::WidgetClsID clsId = ZSkinService::clsTotal, 
               bool isWidget = TRUE);

    virtual ~ZSkinBase();
    void updateSkin();   
    const WIDGET_PADDING_INFO_T padding() const;
    void setPadding( const WIDGET_PADDING_INFO_T & padding );
    const SelectionState selectionState() const;
    void setSelectionState( const SelectionState state );
    uint getBackgroundBlendingPercent();
    uint getBorderBlendingPercent();
    void setZBorder( WIDGET_BORDER_INFO_T borderItems[StateCount]);
    void setZBorder( BorderPixmaps& pixmaps);
    int getBorderWidth(BorderSide side = BorderLeft) const; 
    void setZBackground(WIDGET_BACKGROUND_INFO_T bckgroundItems[StateCount]);
    void setZBackground(QPixmap& image);
    void unsetZBackground();
    void drawWithoutBackground(bool bDrawWithoutBg);
    bool isWithoutBackground();
    void drawBorder(QPainter& painter, ZWidget& widget, const QRect* rect = NULL, bool realWidget = TRUE);
    void drawBackground(QPainter& painter, ZWidget& widget, const QRect* rect = NULL, bool border = TRUE, bool realWidget = TRUE);
    void drawBackgroundAndBorder(QPainter& painter, ZWidget& widget, const QRect* rect = NULL, bool realWidget = TRUE);
    void drawBackgroundAndBorder(QPainter& painter,QRect rect,QPixmap *backimg,int bgx,int bgy,bool realWidget = FALSE);
    void drawBgAndBorderWithRotate(QPainter& painter, ZWidget& zwidget, bool realWidget = TRUE, int rotAngle = 90);
    void* getProps() const;
    void setBlendingTranslate(int x, int y) {dx = x; dy = y;}
    void setPixmapID(QString background, QString border);
    static void setPixmapPrefix(QString& prefix );
    void setWidgetPixmapPrefix(QString& prefix );
    BackgroundType getBackgroundType() const;
    BorderType getBorderType() const;
    void enableCache(bool enable);
    BorderPixmaps getBorderPixmaps();
    void drawBackground(QPainter& painter, QRect& rect, QPixmap* bgPixmap, int xBg, int yBg, int blendPercent);

  protected:
    void stretchPixmap(QPixmap& pm, int width, int height, PIXMAP_STRETCH_POLICY_E type, bool must = false);
    void setZBackground(WIDGET_BACKGROUND_INFO_T bckgroundItems[StateCount], int alpha);

  private:
    QPixmap* getParentBackImage(ZWidget& widget, int x, int y, int& xBg, int& yBg, bool& freeImage);
    void drawBorder(QPainter& painter, QRect& rect, QPixmap* bgPixmap, int xBg, int yBg, int blendPercent);
    void initBorder();
    void initBorder(int width, const QColor & color);
    void initBorder(const QString & pixmapId);
    void initBackground();
    void initBackground(const QColor& color);
    void initBackground(const QString& pmID);

  public:
     const ZSkinService::WidgetClsID skinClsID() const;

  private:
     QString getPixmapNameByState() const;

  private:
     void fillRect(QPainter& painter, QRect rect, QColor& color);
     void* getPixmapIDs(int&backgroundPixmapID, int&borderPixmapID);
     void loadBorderPixmaps(BorderPixmaps& border) const;
     void stretchAndDrawPixmap(QPainter& painter, QRect& rect, QPixmap& pixmap, PIXMAP_STRETCH_POLICY_E policy,
                          QPixmap* bgPixmap, int xBg, int yBg, int blendPercent);
     void drawPixmap(QPainter& painter, int x, int y, int w, int h, QPixmap& pixmap,
                     QPixmap* bgPixmap, int xBg, int yBg, int blendPercent);
     void drawPixmap(QPainter& painter, QRect& rect, QPixmap& pixmap,
                     QPixmap* bgPixmap, int xBg, int yBg, int blendPercent);
     void fillRect(QPainter& painter, int x, int y, int w, int h, QColor& color,
                     QPixmap* bgPixmap, int xBg, int yBg, int blendPercent);
     void fillRect(QPainter& painter, QRect& rect, QColor& color,
                     QPixmap* bgPixmap, int xBg, int yBg, int blendPercent);
     bool hasAlphaValue(QPixmap& pixmap);
     bool borderHasAlphaValue();
     bool bgHasAlphaValue();

  public:

    struct Padding
    {
        int all;
        int left;
        int right;
        int top;
        int bottom;
    };
    enum RelativeAlignment
    {
       ImageLeft,
       ImageRight
    };

     ZSkinBase(QWidget& w, const ZSkinService::WidgetClsID clsId = ZSkinService::clsTotal,
               bool isWidget = TRUE);

     void setSkinWidget(QWidget& w) {widget = &w;}
     QWidget* getSkinWidget() const {return widget;}
     void drawBorder(QPainter& painter, const QRect* rect = NULL);
     void drawBackground(QPainter& painter, const QRect* rect = NULL, bool border = TRUE);

      void setBlendingPercent(uint percent);

      uint getBlendingPercent();

  private:
     void drawPixmap(QPainter& painter, QRect rect, QPixmap& pixmap);
     void drawPixmap(QPainter& painter, int x, int y, QPixmap& pixmap);
     QPixmap* getWallPaper(QPainter& painter) const;

  protected:
    uint    own_padding : 1;
    uint    own_background : 1;
    uint    own_private_bg : 1;
    uint    own_border : 1;
    uint    own_private_border : 1;
    uint    own_percent : 1;

    uint    mIsWidget : 1;
    uint    mCachePixmap :1;

    ZSkinService::WidgetClsID mClsID;

    short mBgPercent;
    short mSelectionState;

    static QString mPrefix;
    QString mWidgetPrefix;

    QString backgroundPixmapID;
    QString borderPixmapID;

    WIDGET_BACKGROUND_INFO_T * ownBackgroundItems;
    WIDGET_BORDER_INFO_T * ownBorderItems;

    QPixmap* mBgPixmap;
    BorderPixmaps* mBorderPixmaps;

    WIDGET_PADDING_INFO_T* mPadding;

    short dx;
    short dy;
    bool mIsWithoutBackground;
    QWidget* widget;
};

#endif
