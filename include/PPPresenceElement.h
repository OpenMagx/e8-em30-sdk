

// Copyright (c) 07-Feb-08 - 2008 Motorola, Inc. All rights reserved.


#ifndef PP_PRESENCE_ELEMENT_H 
#define PP_PRESENCE_ELEMENT_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <string>
#include <vector>
#include "ImpsObject.h"
#include "PPTypes.h"

enum PP_PRESENCE_ELEMENT_TYPE_T
{
    PP_PRESENCE_ELEMENT_TYPE_INVALID = 0, 
    PP_PRESENCE_ELEMENT_TYPE_PERSON,      
    PP_PRESENCE_ELEMENT_TYPE_DEVICE,      
    PP_PRESENCE_ELEMENT_TYPE_SERVICE      
};

enum PP_PRESENCE_ATTRIBUTE_T
{
    PP_PRESENCE_ATTRIBUTE_INVALID                     = 0,
    PP_PRESENCE_ATTRIBUTE_GENERAL_START, 
    PP_PRESENCE_ATTRIBUTE_GENERAL_NOTE                = PP_PRESENCE_ATTRIBUTE_GENERAL_START,         
    PP_PRESENCE_ATTRIBUTE_GENERAL_ID,                     
    PP_PRESENCE_ATTRIBUTE_GENERAL_TIME_STAMP,             
    PP_PRESENCE_ATTRIBUTE_GENERAL_END                 = PP_PRESENCE_ATTRIBUTE_GENERAL_TIME_STAMP,    
    PP_PRESENCE_ATTRIBUTE_PERSON_START,                   
    PP_PRESENCE_ATTRIBUTE_PERSON_ACTIVITY             = PP_PRESENCE_ATTRIBUTE_PERSON_START,
    PP_PRESENCE_ATTRIBUTE_PERSON_MOOD_STATE,              
    PP_PRESENCE_ATTRIBUTE_PERSON_MOOD_NOTE,               
    PP_PRESENCE_ATTRIBUTE_PERSON_OVERRIDING_WILLINGNESS,  
    PP_PRESENCE_ATTRIBUTE_PERSON_AGE,                     
    PP_PRESENCE_ATTRIBUTE_PERSON_HOME_LOCATION,           
    PP_PRESENCE_ATTRIBUTE_PERSON_GENDER,                  
    PP_PRESENCE_ATTRIBUTE_PERSON_INTENTION,               
    PP_PRESENCE_ATTRIBUTE_PERSON_INTERESTS,               
    PP_PRESENCE_ATTRIBUTE_PERSON_MARITAL_STATUS,          
    PP_PRESENCE_ATTRIBUTE_PERSON_ICON,                    
    PP_PRESENCE_ATTRIBUTE_PERSON_END                  = PP_PRESENCE_ATTRIBUTE_PERSON_ICON,
    PP_PRESENCE_ATTRIBUTE_SERVICE_START,                  
    PP_PRESENCE_ATTRIBUTE_SERVICE_STATUS              = PP_PRESENCE_ATTRIBUTE_SERVICE_START,
    PP_PRESENCE_ATTRIBUTE_SERVICE_DESCRIPTION,            
    PP_PRESENCE_ATTRIBUTE_SERVICE_VERSION,                
    PP_PRESENCE_ATTRIBUTE_SERVICE_CONTACT_ADDRESS,        
    PP_PRESENCE_ATTRIBUTE_SERVICE_CONTACT_PRIORITY,       
    PP_PRESENCE_ATTRIBUTE_SERVICE_DEVICE_ID,              
    PP_PRESENCE_ATTRIBUTE_SERVICE_WILLINGNESS,            
    PP_PRESENCE_ATTRIBUTE_SERVICE_BARRING,                
    PP_PRESENCE_ATTRIBUTE_SERVICE_REGISTRATION,           
    PP_PRESENCE_ATTRIBUTE_SERVICE_SESSION_PARTICIPATION,  
    PP_PRESENCE_ATTRIBUTE_SERVICE_ICON,                   
    PP_PRESENCE_ATTRIBUTE_SERVICE_END                 =  PP_PRESENCE_ATTRIBUTE_SERVICE_ICON,
    PP_PRESENCE_ATTRIBUTE_DEVICE_START,                   
    PP_PRESENCE_ATTRIBUTE_DEVICE_NETWORK_AVAILABILITY = PP_PRESENCE_ATTRIBUTE_DEVICE_START,    
    PP_PRESENCE_ATTRIBUTE_DEVICE_END                  = PP_PRESENCE_ATTRIBUTE_DEVICE_NETWORK_AVAILABILITY
};

class PPPresenceElement : public ImpsObject
{
public:

    static PPPresenceElement* create(PP_PRESENCE_ELEMENT_TYPE_T type);

    virtual PP_RETURN_STATUS_TYPE setSpecificAttribute(PP_PRESENCE_ATTRIBUTE_T attributeId,
                                                       const std::string&      cr_attributeValue) = 0;

    virtual PP_RETURN_STATUS_TYPE setGenericAttribute(const std::string& cr_attributeName,
                                                      const std::string& cr_attributeValue) = 0;

    virtual PP_RETURN_STATUS_TYPE getSpecificAttribute(PP_PRESENCE_ATTRIBUTE_T attributeId,
                                                       std::string*            p_attributeValue_out) const = 0;

    virtual PP_RETURN_STATUS_TYPE getGenericAttribute(const std::string& cr_attributeName,
                                                      std::string*       p_attributeValue_out) const = 0;

    virtual PP_RETURN_STATUS_TYPE getGenericAttributeNameList(std::vector<std::string>*  p_attributes_out) const = 0;

    virtual PP_RETURN_STATUS_TYPE getSpecificAttributeIdList(std::vector<PP_PRESENCE_ATTRIBUTE_T>*  p_attributes_out) const = 0;

    virtual std::string getSpecificAttributeNameAsString(PP_PRESENCE_ATTRIBUTE_T attribute) const = 0;

    virtual PP_PRESENCE_ELEMENT_TYPE_T getType() const = 0;
};

#endif  
