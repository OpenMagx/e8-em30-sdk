//Fix for E8/EM30 by Ant-ON, 25-10-2010

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef __ZWRAPLINE_H__
#define __ZWRAPLINE_H__

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "qstring.h"
#include "qlist.h"
#include "qfont.h"
#include <qnamespace.h>

#ifndef QT_NO_WTLE
#include "tslayout.h"
#endif

class Q_EXPORT ZWrapLine
{
public:
    ZWrapLine(QString &strSource);

    ~ZWrapLine();

public:

    enum WordWrap {
        NoWrap,             
        WidgetWidth,        
        FixedPixelWidth,    
        FixedColumnWidth    
    };

    enum WrapPolicy {
        AtWhiteSpace,      
        Anywhere           
    };

    void setStrSource(QString &strSource);

    bool wrapLine(const QFont & font); 

    int getNumLines();

    int getLineContent(int line,QString & string,bool & newline);

    void clear();

    void setWrapPolicy( WrapPolicy policy );

    WrapPolicy wrapPolicy() const;

    void setWordWrap( WordWrap mode );

    WordWrap wordWrap() const;

    void setWrapColumnOrWidth( int );

    int wrapColumnOrWidth() const;

    void setAlignment( Qt::AlignmentFlags flags );

    Qt::AlignmentFlags alignment() const;

    void setContentsWidth(int nWidth);

    int width() const;

    int height() const;

    void draw ( QPainter * p, int x, int y, const QRect & clipRect) const;

    int getLeftBrearing();
    
    //Add by Ant-ON
    int getRightBrearing();
	//

private:
#ifndef QT_NO_WTLE
    void autoAlignment(TsLayout *layout, TsLayoutInfo &layoutInfo);
#endif

#ifndef QT_NO_MOT_ALIGN_AUTO
    bool alignmentAuto;
#endif

    WordWrap wordwrap;
    WrapPolicy wrappolicy;
    int lr_marg;
    int marg_extra;
    int wrapcol;
    Qt::AlignmentFlags align;
    QString mvstrSource;
    int contentWidth;
    int nMaxRowWidth;

    int a_nLeftBearing; 

    short chartable[256];
    void clearChartable();

    QFont mfont;

    struct ZWrapLineEditRow {
        ZWrapLineEditRow( QString string, int width, bool nl = TRUE )
            :s(string), w(width), newline( nl )
        {
        };
        QString s;
        int w;
        bool newline;
    };
    QList<ZWrapLineEditRow> *contents;
private: 
    void calcCompWidth(TsCoord& compWidth,int width);
    void wtleWrapLine(int &w  , ZWrapLineEditRow * r , const QFont & font);

};

#endif 
