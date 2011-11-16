

// Copyright (c) 07-Jun-05 - 2008 Motorola, Inc. All rights reserved.


#ifndef UTIL_FONT_FACTORY_ITYPE_H
#define UTIL_FONT_FACTORY_ITYPE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#ifndef QT_H
#include <qfontmanager_qws.h>
#endif 
#include <qstringlist.h>

extern "C" {
#include <fs_port.h>     
#include <object.h>   
#include <function.h>  
#include <err.h>      
}

class UTIL_FONT_Factory_iType : public QFontFactory {

public:

    UTIL_FONT_Factory_iType();
    virtual ~UTIL_FONT_Factory_iType();

    QRenderedFont * get(const QFontDef &,QDiskFont *);
    virtual void load(QDiskFont *) const;
    virtual QString name();

    bool addFont(const char* name, const char* path, unsigned char *memptr, unsigned long index) const;

private:

    friend class QRenderedFontFS;

    FS_STATE *FS_state_ptr;

    mutable QStringList mapped;
};

#endif 
