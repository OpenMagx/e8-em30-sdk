

// Copyright (c) 24-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef AM_FOLDER_H
#define AM_FOLDER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qvaluelist.h>

#include "AM_RegistryObject.h"

class AM_AppRegistryImpl;

class AM_Folder : public AM_RegistryObject
{
protected:
    AM_Folder();
    virtual ~AM_Folder();

private:
    AM_Folder(const AM_Folder & rhs);
    AM_Folder & operator=(const AM_Folder & rhs);

public:
    virtual void getContent(QValueList <const AM_RegistryObject *> &contentList) const;

    virtual bool isEmpty() const;

    virtual int getPosition( const AM_RegistryObject *obj ) const;

    virtual bool isJavaEnabled() const {return mIsJavaEnabledFolder;}

protected:    
    virtual AM_RESULT_CODE_T initObject(const QString & uid, const AppRecord &record );

    virtual void add(AM_RegistryObject *obj, int index = -1);

    virtual void remove(AM_RegistryObject *obj);

    virtual void clear();

    virtual QString getDefaultName() const;

private:

   QValueList<AM_RegistryObject *> contentList;    
   bool mIsJavaEnabledFolder;

friend class AM_AppRegistryImpl;

};

#endif
