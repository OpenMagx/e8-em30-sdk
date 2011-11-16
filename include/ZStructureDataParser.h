

// Copyright (c)  - 2008 Motorola, Inc. All rights reserved.


#ifndef __ZSTRUCTUREDATAPARSER_H__
#define __ZSTRUCTUREDATAPARSER_H__

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "qlist.h"
#include "qstring.h"
#include "qstringlist.h"

class   ZStruDataParserPrivate;

#define STRUCTUREDATATYPE_PHONENUMBER  "text/x-phoneNumber"   
#define STRUCTUREDATATYPE_EMAIL        "text/x-email"         
#define STRUCTUREDATATYPE_URL          "text/x-url"           
#define STRUCTUREDATATYPE_IM           "text/x-wv"            
#define STRUCTUREDATATYPE_DATE_1       "text/x-date1"         
#define STRUCTUREDATATYPE_DATE_2       "text/x-date2"         
#define STRUCTUREDATATYPE_TIME         "text/x-time"          

typedef int (*PPARSERCALLBACK)(
                const QString&  origStr,
                QString&        desStr );

class Q_EXPORT  ZStructureDataParser
{
public:

    typedef struct
    {
        QString strOrig;                
        int     origBeginPos;           
        int     origEndPos;             
        QString strDisplay;             
        int     disBeginPos;            
        int     disEndPos;              
        int     replacedFlag;           
        QString type;                   
    }
    STRUCTUREDATA, *LPSTRUCTUREDATA;

    ZStructureDataParser( void );

    ZStructureDataParser(
        const QString&  strText,
        const QString&  type = "text/x-phoneNumber",
        PPARSERCALLBACK pParserCallback = 0 );

    ~ZStructureDataParser( void );

    void                    setTypeInfo(
                                const QString&  type,
                                const QString&  strTypeRule = QString::null,
                                PPARSERCALLBACK pParserCallback = 0 );

    void                    setType(
                                const QString&  type,
                                bool            append = false );

    QString                 getType( void );

    void                    setFilterType( const QString& type );

    void                    setText(
                                const QString&  strText,
                                int             nPos = 0,
                                bool            isAdd = false );

    bool                    parse( void );

    bool                    parse(
                                const QString&  strText,
                                int             nPos,
                                const QString&  type,
                                bool            isAdd = false );

    QList<STRUCTUREDATA>    getStructureData( const QString& type = QString::null );

    int                     getStructureDataCount( const QString& type = QString::null );

    const LPSTRUCTUREDATA   getStructureData(
                                int             nIndex,
                                const QString&  type = QString::null );

    QString                 getDisplayText( void );

    void                    deleteStructureData(
                                int             nIndex,
                                const QString&  type = QString::null );
private:

    void        inital( void );

    QString     getCurrentRule( QStringList typeList );

    void        setCallBack(
                    const QString&  type,
                    PPARSERCALLBACK pParserCallback );

    QStringList getCurrentTypeList( const QString& type );

    int         getCapturedParaNumber( const QString& strTypeRule );

    bool        realParse( void );

    int         getStruDataTypeInfo( QString& strMatch );

    int         addNewStruDataTypeInfo(
                    const QString&  strMatch,
                    const QString&  strTypeName,
                    PPARSERCALLBACK pParserCallback,
                    int             nPos,
                    int             nIndex );

    int         findStructureDataByPos( int nPos );

    int         getDisplayTextPos(
                    int norigPos,
                    int nIndex );

    int         getEmailHeader(
                    const QString&  strSour,
                    QString&        strHead,
                    int             curPos );

    int         getContainedSD(
                    int nPos,
                    int nFirstIndex,
                    int nLastIndex );

    bool        isFilterData( const QString& strType );

    typedef struct
    {
        QString         strTypeName;    
        QString         strTypeRule;    
        int             nCapNumber;     
        PPARSERCALLBACK pParserCallback;    
    }
    TYPEINFO, *LPTYPEINFO;

    QList<TYPEINFO> mlistTypeInfo;

    QList<STRUCTUREDATA> mlistStruData;

    ZStruDataParserPrivate* d;
};
#endif  

