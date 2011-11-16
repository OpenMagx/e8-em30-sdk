//Fix for E8/EM30 by Ant-ON, 25-10-2010

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZWIDGET_H
#define PUBLIC_API_WIDGET_ZWIDGET_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qwidget.h>
#include <ZMorphingModeDef.h>
#include <qpaintermoto.h>

#include "ZSkinBase.h"
#include "ZSkinTool.h"
#include <qgfx_qws.h>
#define FEAT_OMEGA_WRAP_PAUSE_TIME 500

class ZWidgetPrivate;

class Q_EXPORT ZWidget : public QWidget, public ZSkinBase
{
   Q_OBJECT
	uint fix[5];	
	
  public:
     ZWidget(QWidget * parent = 0, const char * name = 0, WFlags f = 0, ZSkinService::WidgetClsID = ZSkinService::clsTotal);
     ~ZWidget();

  public:
     virtual void updateSkin(bool redraw);
     void setScreenFSBA(QPixmap& pixmap, int opacity = 100, PIXMAP_STRETCH_POLICY_E type = spScale);
     QPixmap* getScreenFSBA();
     void setScreenSkinFile(QString iniFile);
     ZSkinService* getScreenSkinService();
     virtual void setFrameBufferAlphaValue(int alpha );
     int getFrameBufferAlphaValue();
     //bool isHandleSideUpDown();
     //void enableHandleSideUpDown(bool bEnable);
     //bool isHandleSideSelect();
     //void enableHandleSideSelect(bool bEnable);

  public:
     bool transparentBgImageCached() const;
     void cacheTransparentBgImage(bool cache);
     virtual QPixmap* getBgImageForTransparent(bool& freeImage);
     QPixmap& getCachedBgPixmap() const;
     bool scrolledInPanel() const;
     void setScrolledInPanel(bool scrolled);
     void setAutoAdjustWidthInPanel(bool adjustWidth);
     bool autoAdjustWidthInPanel() const;
     virtual QSize maxmumSizeHint() const {return QSize(width(), height());}
     virtual bool isScrollPanelTypeWidget() const {return FALSE;}
     virtual bool isSeparatorTypeWidget() const {return FALSE;}
     virtual uint getStepInScrollPanel(bool) const {return 20;}
     bool isInternalWidget() const;
     void setInternalWidget(bool internal);
     enum LayoutDirection{DefaultLayout, LeftToRight, RightToLeft, CachedLtoR, CachedRtoL};
     void setScreenLayoutDirection(LayoutDirection);
     LayoutDirection getScreenLayoutDirection() const;
     bool isLeftToRightLanguage() const; 
     enum ResizeMethod{ResizeByDefault,ResizeByParent,ResizeByContent,FixedSize};
     void setResizeMethod(ResizeMethod method);
     ResizeMethod resizeMethod() const;
     virtual void setLandScapeFlag(bool  bLandScape) ;
     virtual bool getLandScapeFlag() const;
	 virtual void setOmegaInput(bool);
     void setPalette( const QPalette & ){updateSkin(TRUE);}
     bool filterOmega(QObject *, QEvent *);
     bool omegaInput();

signals:
     void needResize();

protected:
     virtual void drawBackgroundAndBorder(QPainter& painter, const QRect* rect = NULL);
     virtual void drawBorder(QPainter& painter, const QRect* rect = NULL);
     virtual void drawBackground(QPainter& painter, const QRect* rect = NULL, bool border = TRUE);
     virtual bool eventFilter(QObject *, QEvent *);
     void setPixmapAlpha(QPixmap& pmap);
     void setPixmapAlpha(QPixmap& dst, const QPixmap& src, int dstStartX, int dstStartY, int srcW, int srcH);
     void setPixmapAlphaWithBorder(QPixmap& pmap);     

protected slots:
     virtual void slotResizeChild();

private:
     ZWidgetPrivate* d;
};

#endif
