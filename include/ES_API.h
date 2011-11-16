

// Copyright (c) 26-May-07 - 2008 Motorola, Inc. All rights reserved.



#ifndef __ES_API_H__
#define __ES_API_H__

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <map>
#include <string>
#include <vector>
using namespace std;

enum {
    ES_RESULT_SUCCESS                               = 0,

    ES_RESULT_PERMISSION_DENIED                     = 1,

    ES_RESULT_SID_NOT_FOUND                         = 2,

    ES_RESULT_SID_ALREADY_EXIST                     = 3,

    ES_RESULT_CUSTOM_FILTER_NOT_FOUND               = 4,

    ES_RESULT_FILTER_INVALID                        = 5,

    ES_RESULT_CUSTOM_FILTER_INVALID                 = 6,

    ES_RESULT_INVALID_TOPIC                         = 7,

    ES_RESULT_CONNECTION_ERROR                      = 8,

    ES_RESULT_OPERATION_TIMEOUT                     = 9,

    ES_RESULT_FAILED                                = 10,

    ES_RESULT_TOPIC_NOT_FOUND                       = 11,

    ES_RESULT_INVALID_HANDLER                       = 12,

    ES_RESULT_OTHER_MODE_INITED                     = 13,

    ES_RESULT_FAILED_TO_CALL_ADAPTER_SUBSCRIBE      = 14,

    ES_RESULT_ADAPTER_POINTER_IS_NULL               = 15,

    ES_RESULT_FAILED_LOAD_ADAPTERINFO               = 16,

    ES_RESULT_ADAPTER_PREFIX_NOT_REGISTERED         = 17,

    ES_RESULT_FAILED_INIT_ADAPTER                   = 18,

    ES_RESULT_FAILED_UNLOAD_ADAPTER                 = 19,

    ES_RESULT_CAN_NOT_GETADAPTER                    = 20,

    ES_RESULT_TRY_UNLOAD_ADAPTER_BEFORE_REF_IS_ZERO = 21,

    ES_RESULT_FAILED_OPEN_ADAPTER_OBJECT            = 22,

    ES_RESULT_FAILED_FIND_SYMBOL_IN_ADAPTER         = 23,

    ES_RESULT_TRY_TO_UNLOAD_UNUSED_ADAPTER          = 24,

    ES_RESULT_FAILED_TO_CALL_DMT_FUNCTION           = 25,

    ES_RESULT_A_PRECISION_NOT_SUPPORTED             = 26,

    ES_RESULT_A_SYNTAX_ERROR                        = 27,

    ES_RESULT_A_INVALID_INPUT                       = 28,

    ES_RESULT_A_MEMORY_ALLOCATION_FAILURE           = 29,

    ES_RESULT_A_TIME_RANGE_NOT_SUPPORTED            = 30,

    ES_RESULT_A_UNKNOWN_ERROR                       = 31,

    ES_RESULT_A_NETLINK_SOCKET_ERROR                = 32,

    ES_RESULT_TOPIC_ALREADY_SUBSCRIBED              = 33,

    ES_RESULT_INVALID_CORRELATION_ID                = 34,

    ES_RESULT_CORRELATION_ID_NOT_FOUND              = 35,

    ES_RESULT_NO_STARTUP_EVENTS                     = 36,

    ES_RESULT_FAILED_TO_CREATE_DMT_SUBSCRIPTION     = 37,

    ES_RESULT_A_TAPI_SERVER_ERROR                   = 38

};

class ES_Event
{
public:
    typedef map<string, string>  PropertiesMap;

    ES_Event();

    ES_Event(
        const char * topic,
        const void * data = 0,
        int size = 0,
        const PropertiesMap * properties = 0
    );

    ~ES_Event();

    const char * getTopic() const { return m_strTopic.c_str();}

    const PropertiesMap& getProperties() const { return m_mapProps;}

    const void * getData() const {return getSize() ? &m_aData[0] : 0;}

    int getSize() const { return m_aData.size();}

    int getSourcePID() const;

    void getSourceDomain(
        int * aDomains,
        unsigned int * nArraySize
    ) const;

    string& GetTopicStr() { return m_strTopic;}

    PropertiesMap& GetPropMap() {return m_mapProps;}

    vector<char>& GetDataArray() {return m_aData;}

private:
    string              m_strTopic;
    vector<char>        m_aData;
    PropertiesMap       m_mapProps;
};

#endif
