

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PHONE_ASYNC_MSG_RECEIVER_H 
#define PHONE_ASYNC_MSG_RECEIVER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <TAPI_SETUP_General.h>
#include <qstring.h>
#include <qobject.h>
typedef struct 
{
    BOOLEAN     isDisplayRegisteredPlmn;
    QString     serviceName;
}PHONE_SERVICE_PROVIDER_DATA_S;

class  PHONE_MsgClient;
class PHONE_AsyncMsgReceiver : public QObject
{
    Q_OBJECT
public:
    static PHONE_AsyncMsgReceiver* instance(void);

    static void destruction();

    ~PHONE_AsyncMsgReceiver();

private:
    PHONE_AsyncMsgReceiver();

    PHONE_MsgClient *d;

protected:
  signals:

    void signalSimCardStatus(TAPI_SIM_STATUS_E status);

    void signalPinStatus(TAPI_SECURITY_PIN_STATUS_E status);

    void signalChargeStatus(TAPI_CHARGER_STATUS_E status);

    void signalBatteryStatus(TAPI_BATTERY_STATUS_E value);  

    void signalBatteryCapacity(UINT8 value);

    void signalSetRFModResult(bool code);

    void signalSignalQuality(TAPI_NETWORK_SIGNAL_E value);

    void signalServiceAvailability(TAPI_BOOL_STATUS_E value);   

    void signalRoamingState(TAPI_NETWORK_ROAM_E value);  

    void signalNetworkStatus(TAPI_NETWORK_STATUS_E status);

    void signalRegisted(QString value);                                         

    void signalServiceName(QString name);

    void signalSpnNameExtend(PHONE_SERVICE_PROVIDER_DATA_S name);  

    void signalGprsActivated(bool);    

    void signalGprsAttached(bool);

    void signalGprsService(bool);

    void signalEgprsService(bool);

    void signalEgprsTrans(bool);

    void signalOpenGprsResult(TAPI_RESULT_E ret);

    void signalCloseGprsResult(TAPI_RESULT_E ret);

    void signalHSDPAAvailbleIcon(int value);

    void signalHSDPATransferIcon(int value);

    void signalLowBattery();

    void signalOperatorLogo(bool isHide);

    void signalCSDCallStatChanged(void);

    void signalCallForwardStatChanged(void);

    void signalLineNumberStatChanged(void);

    void signalVoiceCallStatChanged(void);

    void signalChargeComleted();

    void signalLowBatteryStatusChanged();

    void signalCallbarringStatusChanged();

    void signalWifiCampStatus();

    void signalWifiSignalBar();

    void signalWifiConnectionInProgress();

    void signalWifiProfileName(QString profile);

    void signalSimCardChanged();

    void signalHomeZoneName(QString homeZoneName);

    void signalDisplayUMAIcon(UINT8 value);

    void signalMATypeChanged(void);
};

#endif

