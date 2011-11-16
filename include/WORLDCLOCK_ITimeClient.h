

// Copyright (c) 13-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef WORLDCLOCK_ITIMECLIENT_H
#define WORLDCLOCK_ITIMECLIENT_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <vector>
#include <qcom.h>
#include <quuid.h>
#include <qlibrary.h>
#include <qdatetime.h>
#include <qstringlist.h>
#include "ZLog.h"
#include "WORLDCLOCK_TypeDefs.h"

#define IID_TIME_CLIENT QUuid("{789c7070-01af-4928-8614-3e79c927c701}")

class WORLDCLOCK_PluginHandler
{
public:
    WORLDCLOCK_PluginHandler() {};

    virtual ~WORLDCLOCK_PluginHandler() {};

    virtual void releaseInterface(QLibrary* p_lib, QUnknownInterface* p_ifc) = 0;
};

class ITimeClient : public QUnknownInterface
{
public:
    Q_REFCOUNT

    virtual QRESULT queryInterface(const QUuid& iid, QUnknownInterface** ppIfc)
    {
        *ppIfc = 0;
        if((iid == IID_QUnknown) || (iid == IID_TIME_CLIENT))
        {
            *ppIfc = static_cast<ITimeClient*>(this);
            (static_cast<ITimeClient*>(*ppIfc))->addRef();
            return QS_OK;
        }
        return QE_NOINTERFACE;
    }

    virtual void onUtcChanged(const QDateTime& oldTime, const QDateTime& newTime) { }

    virtual void onLocalTimeZoneChanged(const CityInfo& oldTZ, const CityInfo& newTZ) { }

    virtual void onDstStatusChanged(const bool oldDst, const bool newDst) { }

    virtual void onTimeZoneDataChanged(const std::vector<CityInfo>& cities) { }

    void releaseITimeClientPlugin()
    {
        zSDbg("Prepare for releasing the Plug-in, ap_handler is %p", ap_handler);
        if (a_bAutoUnload)
        {
            zSDbg("It should be autoUnloaded!!");
            return;
        }
        if (ap_handler)
        {
            zSDbg("Now releaseInterface!!! ap_library is %d, interface is %p", ap_library, this);
            ap_handler->releaseInterface(ap_library, this);
        }
    }

public:
    ITimeClient() : a_bAutoUnload(true) { }

protected:
    bool a_bAutoUnload;

private:
    void setHandler(WORLDCLOCK_PluginHandler* p_handler, QLibrary* p_lib)
    {
        ap_handler = p_handler;
        zSDbg("Set mpHandler to %p", ap_handler);
        ap_library = p_lib;
        zSDbg("Set mpLibrary to %p", ap_library);
    };

private:
    WORLDCLOCK_PluginHandler* ap_handler;

    QLibrary* ap_library;

    friend class WORLDCLOCK_PluginProcess;
};

#endif 
