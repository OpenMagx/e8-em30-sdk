

// Copyright (c) 13-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef WORLDCLOCK_SERVICE_H
#define WORLDCLOCK_SERVICE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <vector>
#include <qstringlist.h>
#include "WORLDCLOCK_TypeDefs.h"

#ifdef __cplusplus
extern "C" {
#endif

bool getNitzData(char* pUtc, int utcLen, INT32& gmt, UINT16& dstOffset, bool& isNITZ);

#ifdef __cplusplus
}
#endif

class WORLDCLOCK_ServiceImpl;

class WORLDCLOCK_Service
{
public:
    static WORLDCLOCK_Service* getInstance();

    void dispose();

    bool isCityValid(const QString& cityName);

    bool getCityInfo(const QString& cityName, CityInfo& ci);

    QStringList getAllCityNames();

    bool getCitiesByHour(const INT32 hour, std::vector<CityInfo>& cities);

    bool getCitiesByRule(const CityInfo& ciRule, std::vector<CityInfo>& cities);

    static LocationInfo getLocalLocationInfo();

    bool setLocalCity(const QString& city);

    bool isNitzAvailable();    

    bool isNitzAutoUpdateEnabled();

    bool setNitzAutoUpdateEnabled(const bool value);

    static QString translateCityName(const QString& srcName);

    static QString fromTranslateCityName(const QString& srcName);

    static QString gmtVal2Str(const GMTOffset& gmt, bool bIsComplete = false);

    static QString gmtVal2Str(const INT32 hour, const INT32 minute, const INT32 second, bool bIsComplete = false);

private:
    static WORLDCLOCK_Service* sp_instance;

    static int s_refCount;

    WORLDCLOCK_Service();

    ~WORLDCLOCK_Service();

    WORLDCLOCK_ServiceImpl* ap_impl;
};

#endif 
