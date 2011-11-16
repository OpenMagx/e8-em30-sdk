//Fix for E8/EM30 by Ant-ON, 25-10-2010

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.



#ifndef ZHEADERDATAMODEL_H
#define ZHEADERDATAMODEL_H
	
#define ZHeaderDataModel QObject
	
/*	
	
#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <ZWidget.h>
#include <qstring.h>
#include <qrect.h>
#include "ZHeader.h"
class ZHeaderDataModelPrivate;

class ZHeaderDataModel : public QObject
{
    Q_OBJECT
public:
    static ZHeaderDataModel *instance();

    static void destruction();

    ~ZHeaderDataModel();

    bool isServerInitialized();

    int getAreaNum(ZHeader::HEADER_TYPE t);

    int getStatusVal(ZHeader::HEADER_STATUS staIdx);

    QString getStatusIconName(
        ZHeader::HEADER_STATUS staIdx, ZHeader::HEADER_TYPE t) const;

    bool setStatusVal(ZHeader::HEADER_STATUS staIdx, int value);

    int getAreaCurrentStatus(ZHeader::HEADER_TYPE t, int areaIdx);

    QString getAreaIconName(ZHeader::HEADER_TYPE t, int areaIdx) const;

    QSize getAreaSize(ZHeader::HEADER_TYPE t, int areaIdx);

signals:
    void serverInitialized();

    void areaChanged(ZHeader::HEADER_TYPE t, int areaIdx);

    void statusChanged(int staIdx, int value);
protected slots:
    void slotStatusChanged(const QCString &, const QByteArray &);
private:
    ZHeaderDataModel();
private:
    static ZHeaderDataModel *m_pInstance;
    ZHeaderDataModelPrivate *d;
};
*/
#endif

