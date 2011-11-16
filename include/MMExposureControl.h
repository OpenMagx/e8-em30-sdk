

// Copyright (c) 20-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMEXPOSURECONTROL_H 
#define MMEXPOSURECONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMResult.h"

enum MMExposureLightMeterings
{
	MMEXPOSURE_CENTER_METRIX = 0,

	MMEXPOSURE_CENTER_WEIGHTED,

	MMEXPOSURE_CENTER_SPOT,

        MMNUM_OF_LIGHT_METERINGS
};
typedef int MMExposureLightMeteringType;

enum MMWhiteBalances
{
    MMWHITE_BALANCE_AUTO = 0,

	MMWHITE_BALANCE_SUNNY,

	MMWHITE_BALANCE_CLOUDY,

	MMWHITE_BALANCE_TUNGSTEN,

	MMWHITE_BALANCE_FLUORESCENT,

	MMWHITE_BALANCE_OFFICE,

	MMWHITE_BALANCE_HOME,

	MMWHITE_BALANCE_INCANDESCENT,

        MMNUM_OF_WHITE_BALANCE
};
typedef int MMWhiteBalanceType;

enum MMSourceLightFrequencys
{
	MM_SOURCE_LIGHT_FREQUENCY_AUTO = 0,

	MM_SOURCE_LIGHT_FREQUENCY_50HZ = 1,

	MM_SOURCE_LIGHT_FREQUENCY_60HZ = 2,

        MMNUM_OF_LIGHT_FREQUENCY
};
typedef int MMSourceLightFrequencyType;

class MMExposureControl
{
public:
    virtual MMResult getExposureCompensation(int& r_compensation) = 0;

    virtual MMResult getExposureTime(MMTime& r_time) = 0;

    virtual MMResult getExposureValue(int& r_value) = 0;

    virtual MMResult getFStop(int& r_aperture) = 0;

    virtual MMResult getISO(int& r_sensitivity) = 0;

    virtual MMResult getLightMetering(MMExposureLightMeteringType& r_mode) = 0;

    virtual MMResult getWhiteBalance(MMWhiteBalanceType& r_mode) = 0;

    virtual MMResult getMaxExposureTime(MMTime& r_time) = 0;

    virtual MMResult getMinExposureTime(MMTime& r_time) = 0;

    virtual MMResult getSupportedExposureComps(int *& pr_list,
                                               int& r_sizeOfList) = 0;

    virtual MMResult getSupportedFStops(int *& pr_value, 
                                     int& r_numOfValues
                                    ) = 0;

    virtual MMResult getSupportedISOs(int *& pr_isoList, 
                                     int& r_numOfIso
                                  ) = 0;

    virtual MMResult getSupportedLightMeterings(MMExposureLightMeteringType *& pr_meteringList, 
                                             int& r_numOfMeterings
                                            ) = 0;

    virtual MMResult getSupportedWhiteBalances(MMWhiteBalanceType *& pr_whiteBalanceList, 
                                             int& r_numOfWhiteBalance) = 0;

    virtual MMResult setExposureCompensation(const int c_ec) = 0;

    virtual MMResult setExposureTime(const MMTime c_time) = 0;

    virtual MMResult setFStop(const int c_aperture) = 0;

    virtual MMResult setISO(const int c_iso) = 0;

    virtual MMResult setLightMetering(const MMExposureLightMeteringType c_metering) = 0;

    virtual MMResult setWhiteBalance(const MMWhiteBalanceType c_wb) = 0;

    virtual MMResult setSourceLightFrequency(const MMSourceLightFrequencyType c_frequencyType) = 0;

    virtual MMResult getSourceLightFrequency(MMSourceLightFrequencyType& r_frequencyType) = 0;

protected:
    virtual ~MMExposureControl(){}
};

#endif  
