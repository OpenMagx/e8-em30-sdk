

// Copyright (c)  - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZSKIN_TOOL_H 
#define PUBLIC_API_WIDGET_ZSKIN_TOOL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qpixmap.h>

#ifdef FEAT_UISTYLE_CHAMELEON
#include <ZWidgetSkinProps.h>
#endif

class ZSkinTool
{
public:



#ifdef FEAT_UISTYLE_CHAMELEON
    QPixmap process(QPixmap &pm, int width, int height, PIXMAP_STRETCH_POLICY_E type);
#endif
    QPixmap stretchV(QPixmap &, int height);
    QPixmap stretchH(QPixmap &, int width);
private:
};
#endif 
