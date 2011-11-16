

// Copyright (c) 26-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ZKB_INPUTFIELD_H
#define ZKB_INPUTFIELD_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qvaluelist.h>

class QUuid;

#define FIELD_REGULAR_STR          "FIELD_TYPE_REGULAR"           
#define FIELD_NAME_STR             "FIELD_TYPE_NAME"              
#define FIELD_EMAILADDR_STR        "FIELD_TYPE_EMAILADDR"         
#define FIELD_URL_STR              "FIELD_TYPE_URL"               
#define FIELD_PHONENUMBER_STR      "FIELD_TYPE_PHONENUMBER"       
#define FIELD_FDN_STR              "FIELD_TYPE_FDN"               
#define FIELD_NUMERIC_STR          "FIELD_TYPE_NUMERIC"           
#define FIELD_ZIP_STR              "FIELD_TYPE_ZIP"               
#define FIELD_PASSWORD_STR         "FIELD_TYPE_PASSWORD"          
#define FIELD_SEARCHFIELD_STR         "FIELD_TYPE_SEARCHFIELD"    
#define FIELD_CURRENCY_STR         "FIELD_TYPE_CURRENCY"          
#define FIELD_NUMPLUS_STR          "FIELD_TYPE_NUMPLUS"           
#define FIELD_MULTIPHONENUMBER_STR "FIELD_TYPE_MULTIPHONENUMBER"  
#define FIELD_NUMPASSWORD_STR	   "FIELD_TYPE_NUMPASSWORD"       
#define FIELD_USERID_STR	   "FIELD_TYPE_USERID"            
#define FIELD_KEYWORD_STR          "FIELD_TYPE_KEYWORD"           

struct ZKbInputField
{
    enum
    {
        ZKB_GENERAL_EDIT,         
        ZKB_SUPPORTED_EDIT,       
    };

    enum 
    {
        FIELD_TYPE_REGULAR=0,       
        FIELD_TYPE_NAME,            
        FIELD_TYPE_EMAILADDR,       
        FIELD_TYPE_URL,             
        FIELD_TYPE_PHONENUMBER,     
        FIELD_TYPE_FDN,             
        FIELD_TYPE_NUMERIC,         
        FIELD_TYPE_ZIP,             
        FIELD_TYPE_PASSWORD,        
        FIELD_TYPE_SEARCHFIELD,     
        FIELD_TYPE_CURRENCY,        
        FIELD_TYPE_NUMPLUS,         
        FIELD_TYPE_MULTIPHONENUMBER,
	FIELD_TYPE_NUMPASSWORD,	    
	FIELD_TYPE_USERID,	    
        FIELD_TYPE_KEYWORD,         
        FIELD_TYPE__NUM_OF_TYPES    
    }; 

    enum
    {
        FIELD_OPTION_DISABLE_COMPLETION = 0x02, 
        FIELD_OPTION_DISABLE_UAD = 0x04,        
        FIELD_OPTION_DISABLE_INSERT_MENU = 0x08, 
        FIELD_OPTION_ENABLE_INSERT_CARET = 0x10, 
        FIELD_OPTION_REVERSE_ONE = 0x20, 
        FIELD_OPTION_DISABLE_AUTOSHIFT = 0x40, 
        FIELD_OPTION_DEFAULT_LOWER_CASE = 0x40, 
        FIELD_OPTION_PASS_MODE_KEY  = 0x80, 
 	FIELD_OPTION_DEFAULT_CAPSLOCK = 0x100, 

        FIELD_OPTION_DISABLE_LANGSETTING = 0x200,
        FIELD_OPTION_DISABLE_TEXTMODE    = 0x600, 
	FIELD_OPTION_COMPOSITE_OPTIONS = 0x10000,     

        FIELD_OPTION_FAVORITE_LANGUAGES = 0x20000,
	FIELD_OPTION_EMOTICON = 0x40000, 

	FIELD_OPTION_IMSTATEOBSERVER = 0x80000,

        FIELD_OPTION_FAVORITE_WRITING_SYSTEM = 0x100000,  

        FIELD_OPTION_PRELOAD_DICTIONARY  = 0x200000

    };

    virtual void setWIUI(bool wiui)=0;

    virtual void setFieldName(const char* fieldName) = 0;

    virtual const char* getFieldName() = 0;

    virtual int getType() const = 0;

    virtual void setType(int fieldType) = 0;

    virtual int editType() const = 0;  

    virtual void setPreferredInputModes(const QValueList<QUuid> & preferredKbList, const QUuid & defaultKb) = 0; 

    virtual bool getPreferredInputModes( QValueList<QUuid> & preferredKbList, QUuid & defaultKb) const = 0;

    virtual QUuid getTextEntryMode()=0; 

    virtual void setOptions(int fieldOptions, long optionData = 0) = 0;

    virtual long getOptions(int optionType = FIELD_OPTION_COMPOSITE_OPTIONS) const = 0;
}; 

#endif
