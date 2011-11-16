

// Copyright (c) 09-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef HSLAYOUTMGR_H
#define HSLAYOUTMGR_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qrect.h>
#include <qstring.h>

class HSLayoutMgr
{

public:

    virtual ~HSLayoutMgr() {};

    virtual void layoutAll() = 0;

    virtual bool setPluginGeometry(const QString& pluginName, 
                                   const QRect& rect) = 0;

    virtual void notifyPluginHidden(const QString& pluginName) = 0;

    virtual bool requestPluginShow(const QString& pluginName) = 0;

    virtual bool requestPluginLoad(const QString& pluginName) = 0;

    virtual void notifyPluginUnloaded(const QString& pluginName) = 0;
};

#endif  
