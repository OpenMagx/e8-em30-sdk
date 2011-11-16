

// Copyright (c) 24-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef AM_SHORTCUT_H
#define AM_SHORTCUT_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "AM_AppObject.h"
class AM_AppRegistryImpl;

class AM_Shortcut : public AM_AppObject
{
protected:
    AM_Shortcut();

    virtual ~AM_Shortcut();

private:
    AM_Shortcut(const AM_Shortcut & rhs);
    AM_Shortcut & operator=(const AM_Shortcut & rhs);

public:
    virtual QString getAction() const;

protected:
    virtual AM_RESULT_CODE_T initObject(const QString & uid, const AppRecord &record );
    virtual QString getDefaultName() const;

    QString mAction;

friend class AM_AppRegistryImpl;

};

#endif
