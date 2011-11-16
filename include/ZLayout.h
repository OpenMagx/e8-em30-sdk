

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef Z_LAYOUT_H
#define Z_LAYOUT_H

#ifndef __cplusplus
#error "This is a C++ header file;it requires C++ to compile."
#endif

#define EZX_DLG_WIDTH 224

#define EZX_DLGTITLE_LEFT_SPACING 5

#define EZX_CHECK_BOXSIZE 20

#define DEFAULT_FONT_SIZE_SMALL 15
#define DEFAULT_FONT_SIZE_MEDIUM 18
#define DEFAULT_FONT_SIZE_LARGE 21

typedef enum
{
    EZX_FONT_SIZE_SMALL=0,
    EZX_FONT_SIZE_MEDIUM,
    EZX_FONT_SIZE_LARGE
} EZX_FONT_SIZE_T;

#define EZX_SCROLLBAR_EXTENSION 19

#include "ZWidgetSkinProps.h"

#include <qrect.h>
#define ZSetLayout(widgetPtr, globalR) widgetPtr->setGeometry(ZGlobal::mapFromGlobalR(widgetPtr, globalR))
#define ZDiffR(parent, child) ZGlobal::diffRect(ZGlobal::get##parent(), ZGlobal::get##child())

class QWidget;

namespace ZGlobal
{

    QRect mapFromGlobalR(QWidget* self, QRect gRect);

    QRect diffRect(QRect parent, QRect child);

    QRect getScreenR();

    QRect getDesktopRect();

    QRect getHeaderR( bool hasSecondTitle = FALSE );

    QRect getCstR();

    QRect getContentR( bool hasSecondTitle = FALSE );

    QRect getAIAR();

    QRect getHomeR( bool hasSecondTitle = FALSE );

    QRect getSubContentR();

    int getLineHeight();

    int getLineSpace();

    enum VSpacingType 
    {
        FormContainer_V1 = 0,
        FormContainer_V2,
        FormContainer_V3,

        FormItem_V1,

        DetailView_V1,
        DetailView_V2,
        DetailView_V3
    };

     int getVSpacing( VSpacingType vst );

    enum PaddingType 
    {
        DetailView = 0
    };

    WIDGET_PADDING_INFO_T getPadding( PaddingType pt );

    QRect getGNBRect();

    QRect getMainWidgetRect();

    QRect getStatusBarR();

    int getFontSize(EZX_FONT_SIZE_T fontSizeType);
};

#endif 
