#ifndef ZKB_INPUTFIELD_H
#define ZKB_INPUTFIELD_H

#include <qvaluelist.h>

class QUuid;

struct ZKbInputField
{
    virtual void setFieldName(const char* fieldName) = 0;
    virtual const char* getFieldName() = 0;
    virtual int getType() const = 0;
    virtual void setType(int fieldType) = 0;
    virtual int editType() const = 0;  
    virtual void setPreferredInputModes(const QValueList<QUuid> & preferredKbList, const QUuid & defaultKb) = 0; 
    virtual bool getPreferredInputModes( QValueList<QUuid> & preferredKbList, QUuid & defaultKb) const = 0;
    virtual QUuid getTextEntryMode()=0; 
    virtual void setOptions(int fieldOptions, long optionData = 0) = 0;
    virtual long getOptions(int optionType) const = 0;
}; 


#endif

