

// Copyright (c) 20-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMFORMATCONTROL_H 
#define MMFORMATCONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"
#include "MMResult.h"
#include "MMString.h"
#include "MMStringList.h"

enum MMFormatMetadataModes
{
	 MMFORMAT_METADATA_NOT_SUPPORTED = 0,

	 MMFORMAT_METADATA_SUPPORTED_FIXED_KEYS = 1,

	 MMFORMAT_METADATA_SUPPORTED_FREE_KEYS = 2,

         MMNUM_OF_METADATA_MODE
 };
typedef int MMFormatMetadataModeType;

enum MMFormatBitrates
{
	MMFORMAT_BITRATE_TYPE_CONSTANT,

	MMFORMAT_BITRATE_TYPE_VARIABLE,

        MMNUM_OF_BITRATE_TYPE
};
typedef int MMFormatBitrateType;

enum MMFormatQualitys
{
	MMFORMAT_QUALITY_TYPE_GOOD,

	MMFORMAT_QUALITY_TYPE_BETTER,

	MMFORMAT_QUALITY_TYPE_BEST,

        MMNUM_OF_QUALITY_TYPE
};
typedef int MMFormatQualityType;

enum MMFormatParams
{
	MMFORMAT_PARAM_BITRATE, 

	MMFORMAT_PARAM_BITRATE_TYPE, 

	MMFORMAT_PARAM_FRAMERATE,

	MMFORMAT_PARAM_SAMPLERATE,

	MMFORMAT_PARAM_QUALITY, 

	MMFORMAT_PARAM_VERSION_TYPE,

        MMNUM_OF_FORMAT_PARAM_TYPE
};
typedef int MMFormatParamType;

class MMFormatControl
{
public:
    virtual MMResult  getEstimatedBitRate(int& r_bitRate) = 0;

    virtual MMResult getFormat(MMString& r_format) = 0;

    virtual MMResult getIntParameterValue(const MMFormatParamType c_parameter, 
                                       int& r_value
                                      ) = 0;

    virtual MMResult getMetadataOverride(bool& r_override) = 0;

    virtual MMResult getMetadataSupportMode(MMFormatMetadataModeType& r_mode) = 0;

    virtual MMResult getStrParameterValue(const MMFormatParamType c_parameter, 
                                       MMString& r_value
                                      ) = 0;

    virtual MMResult getSupportedFormats(MMStringList& r_formatList) = 0;

    virtual MMResult getSupportedIntParameterRange(const MMFormatParamType c_parameter, 
                                                int& r_minValue, 
                                                int& r_maxValue
                                               ) = 0;

    virtual MMResult getSupportedIntParameters(MMFormatParamType *& pr_intparaList, 
                                            int& r_numOfPara
                                           ) = 0;

    virtual MMResult getSupportedMetadataKeys(MMStringList& r_keyList) = 0;

    virtual MMResult getSupportedStrParameters(MMFormatParamType *& pr_strparaList, 
                                            int& r_numOfList
                                           ) = 0;

    virtual MMResult getSupportedStrParameterValues(const MMFormatParamType c_parameter, 
                                                 MMStringList& r_paramList) = 0;

    virtual MMResult setFormat(const MMString & cr_format) = 0;

    virtual MMResult setMetadata(const MMString & cr_key,  
                                  const MMString & cr_value
                             ) = 0; 

    virtual MMResult setMetadataOverride(const bool c_override) = 0;

    virtual MMResult setIntParameter(const MMFormatParamType c_parameter, 
                                      const int c_value
                                 ) = 0;

    virtual MMResult setStrParameter(const MMFormatParamType c_parameter, 
                                     const MMString & cr_value
                                 ) = 0;

protected:
    virtual ~MMFormatControl(){}

};

#endif  
