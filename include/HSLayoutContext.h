

// Copyright (c) 09-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef HSLAYOUTCONTEXT_H
#define HSLAYOUTCONTEXT_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qrect.h>
#include <qlist.h>
#include <qstring.h>

#include <HSPluginInfo.h>

class HSLayoutContext
{

public:

    virtual ~HSLayoutContext() {};

    virtual const QRect& getHSFrameworkGeometry() = 0;

    virtual HSPluginInfo* getPluginInfo(const QString& pluginName) = 0;

    virtual QList<HSPluginInfo>* getDisplayList() = 0;
};

#endif  
