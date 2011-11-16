

// Copyright (c) 09-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef HSFOCUSMGR_H
#define HSFOCUSMGR_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>
#include <qpoint.h>

class HSFocusMgr
{

public:

    virtual ~HSFocusMgr() {};

    virtual QString queryPrimaryFocusPlugIn(
        const QString& lastPluginName = QString::null) = 0;

    virtual QString queryNextFocusPlugIn(
        const QString& curPluginName,
        int key,
        QPoint& pos,
        const QString& destPluginName) = 0;

    virtual QString queryNextFocusPlugIn(
        const QString& curPluginName,
        int key) = 0;

    virtual QString getName() const = 0;

    virtual void notifyFocusListChanged() = 0;

};

#endif  
