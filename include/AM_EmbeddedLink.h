

// Copyright (c) 24-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef AM_EMBEDDEDLINK_H
#define AM_EMBEDDEDLINK_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "AM_AppObject.h"

class AM_AppRegistryImpl;

class AM_EmbeddedLink : public AM_AppObject
{
protected:
    AM_EmbeddedLink();

    virtual ~AM_EmbeddedLink();

private:
    AM_EmbeddedLink(const AM_EmbeddedLink & rhs);
    AM_EmbeddedLink & operator=(const AM_EmbeddedLink & rhs);

public:

    QString getUrl() const; 

protected:
    virtual AM_RESULT_CODE_T initObject(const QString & uid, const AppRecord &record );

    void setUrl( const QString &newUrl);

    virtual QString getDefaultName() const;

private:
    QString mUrl;

friend class AM_AppRegistryImpl;

};

#endif
