

// Copyright (c) 20-Jun-03 - 2008 Motorola, Inc. All rights reserved.



#ifndef QRTLCODEC_H
#define QRTLCODEC_H

#ifndef QT_H
#include "qtextcodec.h"
#endif 

#ifndef QT_NO_RTLCODEC

class Q_EXPORT QHebrewCodec : public QTextCodec {
public:
    virtual int mibEnum() const;
    const char* name() const;

    QCString fromUnicode(const QString& uc, int& len_in_out) const;
    QString toUnicode(const char* chars, int len) const;

    int heuristicContentMatch(const char* chars, int len) const;

protected:
    virtual bool to8bit(const QChar ch, QCString *str) const; 
    QString toUnicode(const char* chars, int len, const ushort *table) const;

};

class Q_EXPORT QArabicCodec : public QHebrewCodec {
public:
    virtual int mibEnum() const;
    const char* name() const;

    QString toUnicode(const char* chars, int len) const;

    int heuristicContentMatch(const char* chars, int len) const;

protected:
    virtual bool to8bit(const QChar ch, QCString *str) const; 
};

#endif

#endif
