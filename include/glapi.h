

// Copyright (c) 12-Sep-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef GLAPI_H 
#define GLAPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "EZX_TypeDefs.h"
typedef long long INT64;
typedef double DOUBLE;

#define GLAPI_MAX_TRANS_BUF_SIZE               1536

#define GLAPI_MAX_EXTRA_INFO_LENGTH            (GLAPI_MAX_TRANS_BUF_SIZE - sizeof(GLAPI_LOCATION_FIX_STRUCT_T))

#define GLAPI_MAX_CLIENT_NAME_LENGTH           146

#define GLAPI_MAX_EXT_ADDR_LENGTH              82

#define GLAPI_PROVIDER_NAME_MAX_LENGTH         32

#define GLAPI_MAX_CAPABILITY_COUNT             10

#define GLAPI_TRANS_TYPE_GET_LOCATION          1

#define GLAPI_TRANS_TYPE_GET_LAST_KNOWN        2

#define GLAPI_TRANS_TYPE_DISTANCE_AZIMUTH      3

#define GLAPI_TRANS_TYPE_SET_USER_SETTINGS     4

#define GLAPI_TRANS_TYPE_GET_STATUS            5

#define GLAPI_TRANS_TYPE_LOCATION_LISTENER     100

#define GLAPI_TRANS_TYPE_PROXIMITY_LISTENER    101

#define GLAPI_TRANS_TYPE_MTLR_LISTENER         102

#define GLAPI_TRANS_TYPE_STATUS_LISTENER       103

#define GLAPI_NO_PREFERRED_PROVIDER_ID         (-1)

#define GLAPI_INTEGRATED_PROVIDER_ID           0

#define GLAPI_NO_REQUIREMENT                   0

#define GLAPI_DEFAULT_CRITERIA \
{GLAPI_LOCATION_METHOD_NO_PREFERENCE_EV, 0, 1000, 0, 0, 0, GLAPI_POWER_CONSUMPTION_NO_PREFERENCE_EV, 0, 1, 0, 0}

#define GLAPI_OK                               0      
#define GLAPI_ERROR_INTERNAL                   (-1)   
#define GLAPI_ERROR_OUT_OF_MEMORY              (-2)   
#define GLAPI_ERROR_INVALID_PARAM              (-3)   
#define GLAPI_ERROR_FUNCTION_MODE              (-4)   
#define GLAPI_ERROR_INVALID_SESSION_ID         (-5)   
#define GLAPI_ERROR_INVALID_TRANSACTION_ID     (-6)   
#define GLAPI_ERROR_INVALID_TRANS_TYPE         (-7)   
#define GLAPI_ERROR_ACCESS_CONFLICT            (-8)   
#define GLAPI_ERROR_DUP_MTLR_LISTENER          (-9)   
#define GLAPI_ERROR_NO_ASYNC_EVENT             (-10)  

#define GLAPI_ERROR_TRANS_FULL                 (-100)   
#define GLAPI_ERROR_UNSUPPORTED                (-101)   
#define GLAPI_ERROR_COMMUNICATION              (-103)   
#define GLAPI_ERROR_PROVIDER_INEXISTENT        (-106)   
#define GLAPI_ERROR_METHOD_UNSUPPORTED         (-107)   
#define GLAPI_ERROR_CRITERIA_UNSUPPORTED       (-108)   
#define GLAPI_ERROR_TIME_OUT                   (-109)   

#define GLAPI_ERROR_HARDWARE                   (-200)   
#define GLAPI_ERROR_PERMISSION_DENIED          (-201)   
#define GLAPI_ERROR_WEAK_SIGNAL                (-202)   
#define GLAPI_ERROR_INACTIVE_IP_NETWORK        (-205)   
#define GLAPI_ERROR_NO_LAST_KNOWN_LOCATION     (-206)   
#define GLAPI_ERROR_USER_SETTING_OFF           (-207)   
#define GLAPI_ERROR_PROVIDER_FATAL             (-208)   

typedef enum _GLAPI_TRANSACTION_STATUS_ENUM_T
{
    GLAPI_TRANSACTION_INEXISTENT_EV   = 0,  
    GLAPI_TRANSACTION_ACTIVE_EV       = 1   
} GLAPI_TRANSACTION_STATUS_ENUM_T;

typedef enum _GLAPI_LOCATION_METHOD_ENUM_T
{
    GLAPI_LOCATION_METHOD_UNKNOWN_EV           = 0,   
    GLAPI_LOCATION_METHOD_NO_PREFERENCE_EV     = 1,   
    GLAPI_LOCATION_METHOD_MS_BASED_AGPS_EV     = 2,   
    GLAPI_LOCATION_METHOD_MS_ASSISTED_AGPS_EV  = 3,   
    GLAPI_LOCATION_METHOD_INTERNAL_GPS_EV      = 4,   
    GLAPI_LOCATION_METHOD_EXTERNAL_GPS_EV      = 5,   
    GLAPI_LOCATION_METHOD_CELL_ID_EV           = 6,   
    GLAPI_LOCATION_METHOD_ANGLEOFARRIVAL_EV    = 7,   
    GLAPI_LOCATION_METHOD_TIMEDIFFERENCE_EV    = 8,   
    GLAPI_LOCATION_METHOD_TIMEOFARRIVAL_EV     = 9,   
    GLAPI_LOCATION_METHOD_SHORTRANGE_EV        = 10,  
} GLAPI_LOCATION_METHOD_ENUM_T;

typedef enum _GLAPI_PROVIDER_STATUS_ENUM_T
{
    GLAPI_LOCATION_PROVIDER_STATUS_UNKNOWN_EV   = 0,  
    GLAPI_LOCATION_PROVIDER_STATUS_INACTIVE_EV  = 1,  
    GLAPI_LOCATION_PROVIDER_STATUS_ACTIVE_EV    = 2,  
} GLAPI_PROVIDER_STATUS_ENUM_T;

typedef enum _GLAPI_POWER_CONSUMPTION_ENUM_T
{
    GLAPI_POWER_CONSUMPTION_INVALID_EV        = 0,  
    GLAPI_POWER_CONSUMPTION_NO_PREFERENCE_EV  = 1,  
    GLAPI_POWER_CONSUMPTION_NONE_EV           = 2,  
    GLAPI_POWER_CONSUMPTION_LOW_EV            = 3,  
    GLAPI_POWER_CONSUMPTION_MEDIUM_EV         = 4,  
    GLAPI_POWER_CONSUMPTION_HIGH_EV           = 5,  
} GLAPI_POWER_CONSUMPTION_ENUM_T;

typedef enum _GLAPI_ASYNC_MODE_ENUM_T
{
    GLAPI_ASYNC_MODE_NONE_EV      = 0,  
    GLAPI_ASYNC_MODE_FD_EV        = 1,  
    GLAPI_ASYNC_MODE_CALLBACK_EV  = 2,  
    GLAPI_ASYNC_MODE_NMEA_EV      = 3,  
} GLAPI_ASYNC_MODE_ENUM_T;

typedef enum _GLAPI_FIX_STATUS_ENUM_T
{
    GLAPI_FIX_STATUS_NULL_EV    = 0,  
    GLAPI_FIX_STATUS_IDLE_EV    = 1,  
    GLAPI_FIX_STATUS_ACTIVE_EV  = 2,  
} GLAPI_FIX_STATUS_ENUM_T;

typedef enum _GLAPI_HARDWARE_STATUS_ENUM_T
{
    GLAPI_HARDWARE_STATUS_NULL_EV   = 0,  
    GLAPI_HARDWARE_STATUS_A_OFF_EV  = 1,  
    GLAPI_HARDWARE_STATUS_A_ON_EV   = 2,  
} GLAPI_HARDWARE_STATUS_ENUM_T;

typedef enum _GLAPI_EMERGENCY_STATUS_ENUM_T
{
    GLAPI_EMERGENCY_STATUS_NULL_EV  = 0,  
    GLAPI_EMERGENCY_STATUS_ON_EV    = 1,  
    GLAPI_EMERGENCY_STATUS_OFF_EV   = 2,  
} GLAPI_EMERGENCY_STATUS_ENUM_T;

typedef enum _GLAPI_FIX_RESULT_STATUS_ENUM_T
{
    GLAPI_FIX_RESULT_STATUS_NULL_EV  = 0,  
    GLAPI_FIX_RESULT_STATUS_FAIL_EV  = 1,  
    GLAPI_FIX_RESULT_STATUS_OK_EV    = 2,  
} GLAPI_FIX_RESULT_STATUS_ENUM_T;

typedef enum _GLAPI_SIGNAL_STATUS_ENUM_T
{
    GLAPI_LOCATION_SIGNAL_STATUS_NULL_EV  = 0,  
    GLAPI_LOCATION_SIGNAL_STATUS_BAD_EV   = 1,  
    GLAPI_LOCATION_SIGNAL_STATUS_OK_EV    = 2,  
} GLAPI_SIGNAL_STATUS_ENUM_T;

typedef enum _GLAPI_USER_STATUS_ENUM_T
{
    GLAPI_USER_STATUS_NULL_EV     = 0,  
    GLAPI_USER_STATUS_OFF_EV      = 1,  
    GLAPI_USER_STATUS_ON_EV       = 2,  
    GLAPI_USER_STATUS_WARM_UP_EV  = 3,  
} GLAPI_USER_STATUS_ENUM_T;

typedef enum _GLAPI_MTLR_NOTIFICATION_ENUM_T
{
    GLAPI_MTLR_NOTIFY_INVALID_EV                                         = 0,  
    GLAPI_MTLR_NOTIFY_LOCATION_ALLOWED_EV                                = 1,  
    GLAPI_MTLR_NOTIFY_AND_VERIFY_LOCATION_ALLOWED_IF_NO_RESPONSE_EV      = 2,  
    GLAPI_MTLR_NOTIFY_AND_VERIFY_LOCATION_NOT_ALLOWED_IF_NO_RESPONSE_EV  = 3,  
} GLAPI_MTLR_NOTIFICATION_ENUM_T;

typedef enum _GLAPI_MTLR_LOCATION_ESTIMATE_ENUM_T
{
    GLAPI_MTLR_LOCATION_ESTIMATE_TYPE_INVALID_EV  = 0,  
    GLAPI_MTLR_CURRENT_LOCATION_EV                = 1,  
    GLAPI_MTLR_CURRENT_OR_LAST_KNOWN_LOCATION_EV  = 2,  
    GLAPI_MTLR_INITIAL_LOCATION_EV                = 3,  
} GLAPI_MTLR_LOCATION_ESTIMATE_ENUM_T;

typedef enum _GLAPI_ENCODING_MODE_ENUM_T
{
    GLAPI_CODING_UNKNOWN_EV  = 0,  
    GLAPI_CODING_ASCII_EV    = 1,  
    GLAPI_CODING_UCS2_EV     = 2,  
} GLAPI_ENCODING_MODE_ENUM_T;

typedef enum _GLAPI_MTLR_EVENT_ENUM_T
{
    GLAPI_MTLR_EVENT_UNKNOWN_EV           = 0,  
    GLAPI_MTLR_EVENT_INCOMING_EV          = 1,  
    GLAPI_MTLR_EVENT_NETWORK_RELEASED_EV  = 2,  
    GLAPI_MTLR_EVENT_TIME_OUT_EV          = 3,  
}GLAPI_MTLR_EVENT_ENUM_T;

typedef enum _GLAPI_MTLR_VERIFY_ENUM_T
{
    GLAPI_MTLR_VERIFY_DENIED_EV   = 0,  
    GLAPI_MTLR_VERIFY_ALLOWED_EV  = 1,  
} GLAPI_MTLR_VERIFY_ENUM_T;

typedef enum _GLAPI_EXTRA_INFO_ENUM_T
{
    GLAPI_EXTRA_INFO_NONE_EV   = 0x00,  
    GLAPI_EXTRA_INFO_NMEA_EV   = 0x01,  
    GLAPI_EXTRA_INFO_OTHER_EV  = 0x02,  
} GLAPI_EXTRA_INFO_ENUM_T;

typedef struct _GLAPI_PROVIDER_CAPABILITY_STRUCT_T
{
    GLAPI_LOCATION_METHOD_ENUM_T    location_method;            
    UINT32                          horizontal_accuracy;        
    UINT32                          vertical_accuracy;          
    UINT32                          ttnf;                       
    GLAPI_POWER_CONSUMPTION_ENUM_T  power_consumption;          
    UINT8                           cost_needed: 1;             
    UINT8                           lat_lon_supported: 1;       
    UINT8                           altitude_supported: 1;      
    UINT8                           speed_course_supported: 1;  
    UINT32                          extra_info_supported;       
} GLAPI_PROVIDER_CAPABILITY_STRUCT_T;

typedef struct _GLAPI_LOCATION_PROVIDER_STRUCT_T
{
    INT32                              location_provider_id;      
    UINT32                             version;                   
    UINT8 location_provider_name[GLAPI_PROVIDER_NAME_MAX_LENGTH];  
    GLAPI_PROVIDER_STATUS_ENUM_T       status;                    
    UINT8                              mtlr_supported: 1;         
    UINT8                              status_supported: 1;       
    UINT8                              settings_supported: 1;     
    UINT8                              location_single_supported: 1;    
    UINT8                              location_periodic_supported: 1;  
    UINT8                              proximity_supported: 1;    
    UINT8                              distance_supported: 1;     
    UINT8                              azimuth_supported: 1;      
    UINT32                             capabilityCount;           
    GLAPI_PROVIDER_CAPABILITY_STRUCT_T capabilities[GLAPI_MAX_CAPABILITY_COUNT];  
} GLAPI_LOCATION_PROVIDER_STRUCT_T;

typedef struct _GLAPI_EVENT_HEADER_STRUCT_T
{
    INT32  transaction_type;   
    INT32  transaction_id;     
    GLAPI_TRANSACTION_STATUS_ENUM_T transaction_status;  
    INT32  result;             
} GLAPI_EVENT_HEADER_STRUCT_T;

typedef UINT8 GLAPI_EVENT_CONTENT_STRUCT_T[GLAPI_MAX_TRANS_BUF_SIZE];

typedef GLAPI_EVENT_CONTENT_STRUCT_T GLAPI_TRANSACTION_PARAM_STRUCT_T;

typedef struct _GLAPI_CRITERIA_STRUCT_T
{
    GLAPI_LOCATION_METHOD_ENUM_T    location_method;             
    UINT32                          response_time;               
    UINT32                          interval;                    
    UINT32                          max_age_allowed;             
    UINT32                          horizontal_accuracy;         
    UINT32                          vertical_accuracy;           
    GLAPI_POWER_CONSUMPTION_ENUM_T  preferred_power_consumption; 
    UINT8                           cost_allowed: 1;               
    UINT8                           lat_lon_required: 1;         
    UINT8                           altitude_required: 1;        
    UINT8                           speed_course_required: 1;    
    GLAPI_EXTRA_INFO_ENUM_T         extra_info_type;              
} GLAPI_CRITERIA_STRUCT_T;

typedef struct _GLAPI_COORDINATES_STRUCT_T
{
    DOUBLE  latitude;   
    DOUBLE  longitude;  
    DOUBLE  altitude;   
} GLAPI_COORDINATES_STRUCT_T;

typedef struct _GLAPI_CALC_DISTANCE_AZIMUTH_PARAM_STRUCT_T
{
    GLAPI_COORDINATES_STRUCT_T  from;                
    GLAPI_COORDINATES_STRUCT_T  to;                  
    UINT8                       distance_needed: 1;  
    UINT8                       azimuth_needed: 1;   
} GLAPI_CALC_DISTANCE_AZIMUTH_PARAM_STRUCT_T;

typedef struct _GLAPI_USER_SETTINGS_STRUCT_T
{
    GLAPI_USER_STATUS_ENUM_T  user_status;  
} GLAPI_USER_SETTINGS_STRUCT_T;

typedef struct _GLAPI_PROXIMITY_PARAM_STRUCT_T
{
    GLAPI_COORDINATES_STRUCT_T  center; 
    DOUBLE                      radius; 
} GLAPI_PROXIMITY_PARAM_STRUCT_T;

typedef struct _GLAPI_LOCATION_FIX_STRUCT_T
{
    GLAPI_LOCATION_METHOD_ENUM_T  location_method;  
    UINT8   f_sample_time: 1;         
    UINT8   f_time_stamp: 1;          
    UINT8   f_gps_utc_offset: 1;      
    UINT8   f_latitude: 1;            
    UINT8   f_longitude: 1;           
    UINT8   f_horizontal_accuracy: 1; 
    UINT8   f_vertical_accuracy: 1;   
    UINT8   f_altitude: 1;            
    UINT8   f_course: 1;              
    UINT8   f_speed: 1;               
    UINT8   f_probability: 1;         

    INT64   sample_time;              
    INT64   time_stamp;               
    INT32   gps_utc_offset;           
    DOUBLE  latitude;                 
    DOUBLE  longitude;                
    DOUBLE  horizontal_accuracy;      
    DOUBLE  vertical_accuracy;        
    DOUBLE  altitude;                 
    DOUBLE  course;                   
    DOUBLE  speed;                    
    UINT8   probability;              
    GLAPI_EXTRA_INFO_ENUM_T       extra_info_type;   
    UINT16  extra_info_length;        
    UINT8   extra_info[0];            
} GLAPI_LOCATION_FIX_STRUCT_T;

typedef struct _GLAPI_STATUS_STRUCT_T
{
    UINT8  f_user_status: 1;        
    UINT8  f_hardware_status: 1;    
    UINT8  f_fix_status: 1;         
    UINT8  f_emergency_status: 1;   
    UINT8  f_fix_result_status: 1;  
    UINT8  f_signal_status: 1;      
    GLAPI_USER_STATUS_ENUM_T        user_status;        
    GLAPI_HARDWARE_STATUS_ENUM_T    hardware_status;    
    GLAPI_FIX_STATUS_ENUM_T         fix_status;         
    GLAPI_EMERGENCY_STATUS_ENUM_T    emergency_status;   
    GLAPI_FIX_RESULT_STATUS_ENUM_T  fix_result_status;  
    GLAPI_SIGNAL_STATUS_ENUM_T      signal_status;      
} GLAPI_STATUS_STRUCT_T;

typedef struct _GLAPI_DISTANCE_AZIMUTH_STRUCT_T
{
    UINT8   f_distance: 1;  
    UINT8   f_azimuth: 1;   
    DOUBLE  distance;       
    DOUBLE  azimuth;        
} GLAPI_DISTANCE_AZIMUTH_STRUCT_T;

typedef struct _GLAPI_MTLR_NOTIFY_INFO_STRUCT_T
{
    GLAPI_MTLR_NOTIFICATION_ENUM_T       notification_type;      
    GLAPI_MTLR_LOCATION_ESTIMATE_ENUM_T  location_type;          
    GLAPI_ENCODING_MODE_ENUM_T           name_coding_schema;     
    UINT8                                name_length;            
    UINT8  client_name[GLAPI_MAX_CLIENT_NAME_LENGTH];           
    GLAPI_ENCODING_MODE_ENUM_T           address_coding_schema;  
    UINT8                                address_length;         
    UINT8  client_address[GLAPI_MAX_EXT_ADDR_LENGTH];        
} GLAPI_MTLR_NOTIFY_INFO_STRUCT_T;

typedef struct _GLAPI_MTLR_EVENT_CONTENT_STRUCT_T
{
    GLAPI_MTLR_EVENT_ENUM_T          event_type;  
    UINT32                           mtlr_id;     
    GLAPI_MTLR_NOTIFY_INFO_STRUCT_T  info;        
} GLAPI_MTLR_EVENT_CONTENT_STRUCT_T;

typedef struct _GLAPI_MTLR_CONFIRMATION_STRUCT_T
{
    UINT32                    mtlr_id;  
    GLAPI_MTLR_VERIFY_ENUM_T  verify;   
} GLAPI_MTLR_CONFIRMATION_STRUCT_T;

typedef INT32 (*GLAPI_EVENT_CALLBACK_FUNC_T)(const INT32                         c_sessionId,
                                             const GLAPI_EVENT_HEADER_STRUCT_T*  cp_header,
                                             const GLAPI_EVENT_CONTENT_STRUCT_T* cp_content);

typedef struct _GLAPI_EVENT_HANDLER_STRUCT_T
{
    GLAPI_EVENT_CALLBACK_FUNC_T   callback;  
    GLAPI_EVENT_HEADER_STRUCT_T   header;    
    GLAPI_EVENT_CONTENT_STRUCT_T  content;   
} GLAPI_EVENT_HANDLER_STRUCT_T;

extern INT64 GLAPI_GetCurrentTicks();

extern INT32 GLAPI_GetProviderCount();

extern INT32 GLAPI_GetAllProviders(GLAPI_LOCATION_PROVIDER_STRUCT_T* p_providerArray,
                                   const UINT32                      c_count);

extern INT32 GLAPI_GetProvider(const UINT32                      c_providerId,
                               GLAPI_LOCATION_PROVIDER_STRUCT_T* p_provider);

extern INT32 GLAPI_OpenSession(const INT32                         c_providerId,
                               const GLAPI_ASYNC_MODE_ENUM_T       c_mode,
                               const GLAPI_EVENT_HANDLER_STRUCT_T* cp_handler);

extern INT32 GLAPI_CloseSession(const INT32 c_sessionId);

extern INT32 GLAPI_GetAsyncFd(const INT32 c_sessionId);

extern INT32 GLAPI_GetAsyncEvent(const INT32                   c_sessionId,
                                 GLAPI_EVENT_HEADER_STRUCT_T*  p_header,
                                 GLAPI_EVENT_CONTENT_STRUCT_T* p_content);

extern INT32 GLAPI_GetLocation(const INT32                    c_sessionId,
                               const GLAPI_CRITERIA_STRUCT_T* cp_criteria,
                               GLAPI_LOCATION_FIX_STRUCT_T*   p_fix);

extern INT32 GLAPI_GetLastKnownLocation(const INT32                  c_sessionId,
                                        GLAPI_LOCATION_FIX_STRUCT_T* p_fix);

extern INT32 GLAPI_SetUserSettings(const INT32                         c_sessionId,
                                   const GLAPI_USER_SETTINGS_STRUCT_T* cp_userSettings);

extern INT32 GLAPI_GetStatus(const INT32            c_sessionId,
                             GLAPI_STATUS_STRUCT_T* p_status);

extern INT32 GLAPI_CalcDistanceAzimuth(const INT32                            c_sessionId,
                                       const GLAPI_CALC_DISTANCE_AZIMUTH_PARAM_STRUCT_T* cp_param,
                                       GLAPI_DISTANCE_AZIMUTH_STRUCT_T*       p_distanceAzimuth);

extern INT32 GLAPI_AddLocationListener(const INT32                    c_sessionId,
                                       const GLAPI_CRITERIA_STRUCT_T* cp_criteria);

extern INT32 GLAPI_RemoveLocationListener(const INT32 c_sessionId,
                                          const INT32 c_transactionId);

extern INT32 GLAPI_AddProximityListener(const INT32                           c_sessionId,
                                        const GLAPI_PROXIMITY_PARAM_STRUCT_T* cp_param);

extern INT32 GLAPI_RemoveProximityListener(const INT32 c_sessionId,
                                           const INT32 c_transactionId);

extern INT32 GLAPI_AddMtlrListener(const INT32 c_sessionId);

extern INT32 GLAPI_RemoveMtlrListener(const INT32 c_sessionId,
                                      const INT32 c_transactionId);

extern INT32 GLAPI_AddStatusListener(const INT32 c_sessionId);

extern INT32 GLAPI_RemoveStatusListener(const INT32 c_sessionId,
                                        const INT32 c_transactionId);

extern INT32 GLAPI_ConfirmMtlr(const INT32                             c_sessionId,
                               const INT32                             c_transactionId,
                               const GLAPI_MTLR_CONFIRMATION_STRUCT_T* cp_confirmation);

extern INT32 GLAPI_StartTransaction(const INT32                             c_sessionId,
                                    const INT32                             c_transactionType,
                                    const GLAPI_TRANSACTION_PARAM_STRUCT_T* cp_param);

extern INT32 GLAPI_CancelTransaction(const INT32 c_sessionId,
                                     const INT32 c_transactionType,
                                     const INT32 c_transactionId);

extern INT32 GLAPI_Reset(const INT32 c_sessionId);

#ifdef __cplusplus
}
#endif 

#endif  

