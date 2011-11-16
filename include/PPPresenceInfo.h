

// Copyright (c) 07-Feb-08 - 2008 Motorola, Inc. All rights reserved.


#ifndef PP_PRESENCE_INFO_H 
#define PP_PRESENCE_INFO_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "PPTypes.h"
#include <string>
#include "ImpsObject.h"
#include "PPPresenceElement.h"

class PPPresenceInfo : public ImpsObject
{
public:

    static PPPresenceInfo* create();

    virtual PP_RETURN_STATUS_TYPE addElement(const PPPresenceElement& cr_presenceElement) = 0;

    virtual UINT16
    getServiceCount() const = 0;

    virtual UINT16
    getDeviceCount() const = 0;

    virtual PPPresenceElement* getPerson() const = 0;

    virtual PPPresenceElement* getService(UINT16 index) const = 0;

    virtual PPPresenceElement* getDevice(UINT16 index) const = 0;

    virtual void setNote(const std::string& cr_note) = 0;

    virtual std::string getNote() const = 0;
};

#endif  
