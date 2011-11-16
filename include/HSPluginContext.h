

// Copyright (c) 09-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef HSPLUGINCONTEXT_H
#define HSPLUGINCONTEXT_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>
#include <qwidget.h>
#include <qlist.h>
#include <qpoint.h>
#include <qrect.h>
#include <qstringlist.h>

#include "HSFrameworkType.h"
#include "HSCommand.h"

class HSPluginContext {

public:
    virtual bool insertHSCommandList(QList<HSCommand>& commands,
        HSCommand::HSSoftKeyType nType = HSCommand::HS_SOFTKEY_LEFT) = 0;

    virtual bool changeHSCommandList(QList<HSCommand>& oldCmds,
        QList<HSCommand>& newCmds,
        HSCommand::HSSoftKeyType nType = HSCommand::HS_SOFTKEY_LEFT) = 0;

    virtual void removeHSCommandList(QList<HSCommand>& commands,
        HSCommand::HSSoftKeyType nType = HSCommand::HS_SOFTKEY_LEFT) = 0 ;

    virtual bool changeHSSoftKey(QList<HSCommand>& commands,
        HSCommand::HSSoftKeyType nType) = 0;

    virtual void restoreHSDefaultSoftkey() = 0;

    virtual bool setPluginGeometry(const QRect& rect) = 0;

    virtual void notifyPluginHidden() = 0;

    virtual bool notifyPluginShow() = 0;

    virtual QWidget* getPluginContainer() = 0;

    virtual void notifyPluginfocusOut(QPoint& pos, 
            const QString& destPluginName = QString::null) = 0;

    virtual HSCommand* createCommand(const QString& name = 0,
                                  bool isEnabled = true,
                                  int Uid = 0,
                                  const QString&  icon = 0,
                                  HSCommand* parent = 0) = 0;

    virtual void registerKeyEvent(int key) = 0;

    virtual void unRegisterKeyEvent(int key) = 0;

    virtual void removeAllKeyEvents() = 0;

     virtual void getActivePluginsNameList(QStringList& list) = 0;

    virtual QString getCurFocusMgrName() = 0;

    virtual void transferState(
         HSFrameworkType::HSPluginTransState state,
         const QString& destPlugin) = 0;

};

#endif 
