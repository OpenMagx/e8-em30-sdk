//Fix for E8/EM30 by Ant-ON, 25-10-2010

// Copyright (c) 24-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef UTIL_ACTIONDATA_H
#define UTIL_ACTIONDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>
#include <qcstring.h>
#include <qmap.h>

#include "AM_Global.h"
#include "AM_Defs.h"

class UTIL_ActionDataPrivate;
class ESCopChannel;
struct SEventLaunch;
class AM_ActionResults 
{
public:
typedef QMap<QString,QString> StrMap;
typedef QMap<QString, QByteArray> BinaryMap;
    AM_ActionResults() : m_error(0) {}
    AM_ActionResults(const AM_ActionResults& results)
    {
        *this = results;
    }
    AM_ActionResults& operator = (const AM_ActionResults& results)
    {
        m_mapStr = results.m_mapStr;
        m_mapBinary = results.m_mapBinary;
        m_error = results.m_error; 
        return *this;
    }
public:
    inline bool getValue(const QString &name, QByteArray& data) const
    {
        BinaryMap::ConstIterator it = m_mapBinary.find(name);
        if(it != m_mapBinary.end())
        {
            data = *it;
            return true;
        }
        return false;
    }
    inline void setValue(const QString &name, const QByteArray& data)
    {
        m_mapBinary[name] = data;
    }

    inline bool getValue(const QString& name, QString& v) const
    {
        StrMap::ConstIterator it = m_mapStr.find(name);
        if(it != m_mapStr.end())
        {
            v = m_mapStr[name];
            return true;
        }
        return false;
    }
    inline void setValue(const QString& name, QString& v)
    {
        m_mapStr[name] = v;
    }
    inline void clear()
    {
        m_mapBinary.clear();
        m_mapStr.clear();
        m_error = 0;
    }
public:
    inline int getError() const { return m_error;}
    inline void setError(int error) { m_error = error;}

    SEventLaunch* createEventData() const;

public:
    friend QDataStream & operator << (QDataStream & ds, const AM_ActionResults& value);
    friend QDataStream & operator >> (QDataStream & ds, AM_ActionResults& value);
protected:
    int m_error;
    StrMap m_mapStr;
    BinaryMap m_mapBinary; 
};

typedef QMap<QString,QString> AM_ActionCommandValueMap;
class AM_ActionData : public QObject
{
    Q_OBJECT
public:
    AM_ActionData();                         
    ~AM_ActionData();                        
    void init();

    QString action()const;

    QString object()const;

    QString value(const QString & name)const;

    bool getValue(const QString & name, QString & v)const;

    bool getValue(const QString & name, int & v)const;

    QCString encodedString()const;
    bool openWithDefaultApp()const;

    QUuid openApp()const;

    void setAction(const QString &v);

    void setObject(const QString &v);

    inline void setValue(const QString& name, const char* v)
    {
	setValue(name, QString(v));
    }

    void setValue(const QString &name, const QString &v);

    void setValue(const QString &name, int v);

    void setOpenWithSystemApp();

    bool getValue(const QString &name, QByteArray& data) const;

    bool setValue(const QString &name, const QByteArray& data);

    enum
    {
       ActionData_String = 0,
       ActionData_Int = 1,
       ActionData_Binary = 2,
       ActionData_Unknown = -1,
    };

//    int getValueType(const QString &name) const;

    void setOpenApp(QUuid app);

    void setAppLockCheck( const bool &lock );

    bool getAppLockCheck() const;

    void sendResults(const AM_ActionResults & results) const;

//    void sendPidResults(const QString& pid) const;

    AM_RESULT_CODE_T invoke(const bool needReturnData = false) const;

    void setEncodedString(const QCString &s);    

//    void setNonQTFlag(bool flag);

//    bool getNonQTFlag() const;

//    void getKeys(QStringList& keys) const;

    friend QDataStream & operator << (QDataStream & ds, const AM_ActionData & value);

    friend QDataStream & operator >> (QDataStream & ds, AM_ActionData & value);


signals:
    void signalResultsAvailable(const AM_ActionResults& results);

//    void signalActionAborted();

protected slots:
    void slotHandleResults(const QCString& msg, const QByteArray& data);

//    void slotHandlePidResults(const QCString& msg, const QByteArray& data);

//    void slotHandleCrashResults(const QCString& msg, const QByteArray& data);

protected:
    void parserString()const;

    void composeString()const;

    void setupReturnChannel() const;

//    void setPid(const QString& pid);

//    QString getPid() const;

private:
    mutable ESCopChannel *returnChannel;
    mutable QCopChannel *returnPidChannel;
    mutable QCopChannel *returnCrashChannel;
    mutable UTIL_ActionDataPrivate * d;
};

#endif  

