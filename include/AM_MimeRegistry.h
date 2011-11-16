

// Copyright (c) 25-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef  AM_MimeRegistry_h
#define  AM_MimeRegistry_h

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qobject.h>
#include <quuid.h>
#include <qvaluelist.h>
#include "AM_Defs.h"

class AM_MimeRegistryImpl;

enum MIME_FILE_T
{
        ALL = 0,
        MIME_TYPES = 1,
        USER_MIME = 2
};

class AM_MimeRegistry : public QObject
{
  Q_OBJECT
 public:

  enum MIME_LOOKUP_CRITERIA
    {
      BY_EXTENSION,
      BY_MIME_TYPE,
      NONE
    };

    AM_MimeRegistry();

    ~AM_MimeRegistry();

    AM_RESULT_CODE_T init(MIME_FILE_T fileType = ALL);

    QString getDefaultHandlerId(MIME_LOOKUP_CRITERIA criteria,
            const QString &criteriaValue,
            const QString &action = QString::null) const;

    void getHandlerIds(MIME_LOOKUP_CRITERIA criteria,
                       const QString &criteriaValue,
                       QStringList &handlerList,
                       const QString &action = QString::null) const;

    void getHandlerInfo(const QString &appId,
                        QStringList &mimeTypes,
                        QStringList &actions) const;

    QString getAssociatedMimeType(const QString &extension) const;

    bool getAssociatedMimeTypes(const QString &extension, QStringList &types) const;

    void getAssociatedExtensions(const QString &mimeType,
            QStringList &extensionList);

    void getSupportedMimeTypes(QStringList& mimeTypeList) const;

    void getSupportedMimeTypes(const QUuid &appId, QStringList &mimeTypeList) const;

    AM_RESULT_CODE_T registerMimeHandler(const QString &mimeType,
                                         const QString &appId,
                                         const QStringList &actionList,
                                         bool setDefault = false);

    AM_RESULT_CODE_T unregisterMimeFromHandler(const QString &appId,
                                               const QString &mimeType,
                                               const QStringList &actionList);

    AM_RESULT_CODE_T unregisterMimeHandler(const QString &appId);

    bool isRegisteredMimeType(const QString &mimeType) const;

    AM_RESULT_CODE_T registerMimeType(const QString &mimeType,
                                      const QStringList &extensionList);

    void getAllHandlerIds(QStringList &handlerList) const;

 signals:

    void signalRegistryUpdated();

 private slots:
    void slotRegistryUpdated();

 private:
    AM_MimeRegistryImpl* impl;
    AM_MimeRegistry( const AM_MimeRegistry & ref);
    AM_MimeRegistry& operator = ( const AM_MimeRegistry & );
    bool isSystemApp (const QString & appId) const;
};

#endif
