

// Copyright (c) 20-Sep-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ZCONFIG_H
#define ZCONFIG_H

#ifndef __cplusplus
#error "This is a C++ header file;it requires C++ to compile."
#endif

#include <qmap.h>
#include <qstringlist.h>

class ZConfigData;
typedef QMap< QString, QString > ZConfigGroup;

class ZConfig
{
  public:

    ZConfig( const QString& fileName, bool needFlush = false );

    virtual ~ZConfig();

    bool writeEntry( const QString& gname, const QString& key,  char* value );

    bool writeEntry( const QString& gname, const QString& key,  const QString& value );

    bool writeEntry( const QString& gname, const QString& key, int value);

    bool writeEntry( const QString& gname, const QString& key, unsigned int value );

    bool writeEntry( const QString& gname, const QString& key, double value );

    bool writeEntry( const QString& gname, const QString& key, bool value );

    bool writeEntry( const QString& gname, const QString& key, const QStringList& list, const QChar& sep );

    QString readEntry( const QString& gname, const QString& key, const QString& deflt = QString::null );

    int readNumEntry( const QString& gname, const QString& key, int deflt = -1 );

    unsigned int readUIntEntry( const QString& gname, const QString& key, unsigned int deflt = 0 );

    bool readBoolEntry( const QString& gname, const QString& key, bool deflt = false );

    QStringList readListEntry( const QString& gname, const QString& key, const QChar& sep );

    virtual bool removeEntry( const QString& gname, const QString& key );

    bool groupExists( const QString& gname );

    virtual bool clearGroup( const QString& gname);

    virtual bool flush();

    QMap<QString, ZConfigGroup >::Iterator getGroupEntriesKeyList( const QString& gname );

    void getGroupsKeyList( QStringList& groupNames );

    static QString getSettingDirectory();

    static QString initSettingDirectory();

    bool changed() const;

  private:

    void read();
    bool write( const QString& fn = QString::null );
    bool parseLine( const QString& line );
    void setGroup( const QString& gname );
    QString readEntryDirect( const QString& gname, const QString& key, const QString& deflt = QString::null );

    ZConfigData* d;
};

#endif

