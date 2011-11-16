#ifndef ZREGEXP_H
#define ZREGEXP_H
#include "qstringlist.h"

class ZRegExp
{
    char tmp[8];
public:
    enum CaretMode
    {};
    ZRegExp();
    ZRegExp(const QString&,bool,bool);
    ZRegExp(const ZRegExp&);
    ~ZRegExp();
    bool isEmpty() const;
    bool isValid() const;
    QString pattern() const;
    void setPattern(const QString&);
    bool caseSensitive() const;
    void setCaseSensitive(bool);
    bool wildcard() const;
    void setWildcard(bool);
    bool minimal() const;
    void setMinimal(bool);
    bool exactMatch(const QString&) const;
    int match(const QString&,int,int*,bool) const;
    int search(const QString&,int) const;
    int search(const QString&,int,CaretMode) const;
    int searchRev(const QString&,int) const;
    int searchRev(const QString&,int,CaretMode) const;
    int matchedLength() const;
    int numCaptures() const;
    QStringList capturedTexts();
    QString cap(int);
    int pos(int);
    QString errorString();
    QString escape( const QString& );
    void prepareEngine() const;
    void prepareEngineForMatch(const QString&) const;
    void invalidateEngine();
    static int caretIndex(int,CaretMode);
};
#endif
