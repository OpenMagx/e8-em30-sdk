

// Copyright (c) 09-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef HSFOCUSCONTEXT_H
#define HSFOCUSCONTEXT_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qrect.h>
#include <qlist.h>
#include <qstring.h>

#include "HSPluginInfo.h"
#include "HSCommand.h"

class HSFocusContext
{

public:

    virtual ~HSFocusContext() {};

    virtual QList<HSPluginInfo>* getFocusList() = 0;

    virtual bool insertCommandList(QList<HSCommand>& commandlist,
            HSCommand::HSSoftKeyType nType) = 0;

    virtual bool changeCommandList(QList<HSCommand>& oldList,
            QList<HSCommand>& newList, HSCommand::HSSoftKeyType nType) = 0 ;

    virtual void removeCommandList(QList<HSCommand>& commandlist,
            HSCommand::HSSoftKeyType nType) = 0;

    virtual void requestToSwitchFocus(QString destPluginName) = 0;
};

#endif  
