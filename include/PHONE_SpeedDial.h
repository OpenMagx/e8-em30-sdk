

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PHONE_SPEED_DIAL_H
#define PHONE_SPEED_DIAL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstringlist.h> 

enum
{
    PHONE_SET_SPEED_DIAL_FULL=-1,
    PHONE_SET_SPEED_DIAL_ERROR=-2,
};
class PHONE_SpeedDial
{
public:
    PHONE_SpeedDial();

    ~PHONE_SpeedDial();

    QString getTurboDialing(int index, bool withUid = false);

    bool setTurboDialing(int index,const QString & number);

    void getTurboDialingList(QStringList & numberList, bool withUid = false);

    bool setTurboDialing(const QStringList & numberList);

    int getFirstAvailableTurboDialingIndex();

};

extern "C" int SPEEDDIAL_GetFirstIndex();

extern "C" bool SPEEDDIAL_SetTurboDialing(int index,const QString &number);
typedef int (*SPEEDDIAL_GetFirstIndex_T)();

typedef bool (*SPEEDDIAL_SetTurboDialing_T)(int,const QString);

#endif 

