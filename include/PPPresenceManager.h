

// Copyright (c) 11-Jul-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PP_PRESENCE_MANAGER_H 
#define PP_PRESENCE_MANAGER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ImpsObject.h"
#include "PPTypes.h"
#include <string>

class PPPresenceInfo;

class PPPresenceManager : public ImpsObject
{
public:

    virtual PP_RETURN_STATUS_TYPE publishPresence(const PPPresenceInfo& cr_presenceInfo, 
                                                  IMPS_BRAND_ID_T       brandId,
                                                  PP_TRANS_ID_T*        p_transId_out) = 0;

    virtual PP_RETURN_STATUS_TYPE getPresence(const std::string&    cr_address,
                                              IMPS_BRAND_ID_T       brandId, 
                                              PPPresenceInfo**      p_presenceInfo_out) = 0;
};

#endif  
