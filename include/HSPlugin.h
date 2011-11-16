

// Copyright (c) 09-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef HSPLUGIN_H
#define HSPLUGIN_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qwidget.h>

#include "HSFrameworkType.h"

class HSPlugin
{
public:

    virtual ~HSPlugin(){};

    virtual void initialize() = 0;

    virtual void start() = 0;

    virtual void stop() = 0;

    virtual QString getDisplayName() const = 0;

    virtual HSFrameworkType::HSEventStatus handleEvent(
         const HSFrameworkType::HSEvent& event,
         int key = -1) = 0;

    virtual QRect getPluginGeometry(const QRect& rc_availableRect) = 0 ;

    virtual void focusIn() = 0;

    virtual void focusIn(int key, QPoint& pos) = 0;

    virtual void focusOut(QPoint& pos, const QString& destPluginName) = 0;

    virtual QPoint getFocusPoint() const = 0;

    virtual void notifyPluginStateChanged(
        HSFrameworkType::HSPluginTransState state,
        const QString& srcPlugin) = 0;

    virtual void setObscured(bool mode) = 0;
};

#endif  
