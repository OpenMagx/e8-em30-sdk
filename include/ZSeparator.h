

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZSEPARATOR_H
#define PUBLIC_API_WIDGET_ZSEPARATOR_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qrect.h>
#include <qpixmap.h>
#include "ZSkinTool.h"
#include "ZSkinBase.h"
#include "ZSkinService.h"
#include "ZWidget.h"

struct ZSeparatorData;
class ZLabel;

class ZSeparator:public ZWidget
{

public:
        enum RelativeAlignment
	{
            LEFT,
            RIGHT
        };

        ZSeparator(QWidget *parent = 0,const char *name = 0 , WFlags f = 0,
              const ZSkinService::WidgetClsID clsId = ZSkinService::clsZSeparator1);

        virtual ~ZSeparator();

	virtual bool isSeparatorTypeWidget() const {return TRUE;}

        void setRelativeAlignment(RelativeAlignment alignment);

        void setOrientation(Orientation orientation);

        void setIconPixmap(const QPixmap &pixmap);

        void setIconPixmap(const QPixmap &pixmap,QRect rect,bool bHeightWidth = true,bool bXY = false);

        void setLabel(ZLabel *label);

        void setLabel(ZLabel *label,QRect rect,bool bHeightWidth = true,bool bXY = false);

        RelativeAlignment relativeAlignment() const;

        void setLength(int nLen);

        QSize sizeHint() const;

        void updateSkin(bool redraw);

        virtual void setPalette(const QPalette &palette);

public:
	ZSeparator(const QPixmap &leftPixmap,const QPixmap &rightPixmap,
              bool bLeftStretch = false,bool bRightStretch = true,
              QWidget *parent = 0,const char *name = 0 , WFlags f = 0,
              const ZSkinService::WidgetClsID clsId = ZSkinService::clsZSeparator1);
	void setChildPosition( int nChildX, int nChildY );
        void setLeftPixmap(const QPixmap &pixmap,bool bStretch = false);
        void setRightPixmap(const QPixmap &pixmap,bool bStretch = true);
        void setLeftStretch(bool bStretch);
        void setRightStretch(bool bStretch);
	Orientation orientation() const;
	ZLabel *getLabel();
        QSize minimumSizeHint() const;
        bool autoResize() const;
        void setAutoResize( bool enable );

protected:
         virtual void paintEvent(QPaintEvent * e);

         virtual void resizeEvent(QResizeEvent * e);

private:
        void init(const QPixmap &leftPixmap,const QPixmap &rightPixmap,
        bool bLeftStretch,bool bRightStretch);
        void resizeHorz();
        void resizeVert();
        void getCurrentFont(QFont & font, QColor & ftColor);
        void setSpacingH2(int nSpacing);
        short getSpacingH2()const;
        void setSpacingH1(int nSpacing);
        short getSpacingH1()const;
	void drawHorz();
        void drawVert();

private:
        struct ZSeparatorData *d;
};
#endif  
