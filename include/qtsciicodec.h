

// Copyright (c) 20-Jun-03 - 2008 Motorola, Inc. All rights reserved.



#ifndef QTSCIICODEC_H
#define QTSCIICODEC_H

#ifndef QT_H
#include "qtextcodec.h"
#endif 

#ifndef QT_NO_TSCIICODEC

class Q_EXPORT QTsciiCodec : public QTextCodec {
public:
    virtual int mibEnum() const;
    const char* name() const;

    QCString fromUnicode(const QString& uc, int& len_in_out) const;
    QString toUnicode(const char* chars, int len) const;

    int heuristicContentMatch(const char* chars, int len) const;
    int heuristicNameMatch(const char* hint) const;
};

#endif

#endif
