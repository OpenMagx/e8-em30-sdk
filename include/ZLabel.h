//Fix for E8/EM30 by Ant-ON, 25-01-2010

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZLABEL_H
#define PUBLIC_API_WIDGET_ZLABEL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif
#include "qtimer.h"
#include "qrect.h"
#include "ZWidget.h"
#include "ZWrapLine.h"
#include "ZSkinService.h"

#define MARQUEE_FOREVER  -1

#define MARQUEE_NOFOREVER 0

#define TRANCATE_FROMEND -1

typedef int NumLines;

typedef int TruncateNum;

typedef unsigned char TruncateStat;

class ZLabelPrivate;

class Q_EXPORT ZLabel : public ZWidget
{
    Q_OBJECT

public:

   enum MarqueeState{
        None = 0,   
        Standard,   
        Highlighted 
    };

    enum MarqueeDirection{
        Left = 0, 
        Right,     
        Top,       
        Bottom  
    };

    enum TextDirection{
        LeftToRight = 0, 
        RightToLeft        
    };

     ZLabel( QWidget *parent, const char *name=0, WFlags f=0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsTotal );

    ZLabel( const QString &text, QWidget *parent, const char *name=0,
           WFlags f=0, const ZSkinService::WidgetClsID clsId = ZSkinService::clsTotal);

    ZLabel(const QString &text, int scrollMillisecond, QWidget* parent, const char* name=0, WFlags f=0, const ZSkinService::WidgetClsID clsId = ZSkinService::clsTotal);

    void marqueeScroll();

public:

    ~ZLabel();

    QString text() const;

    Qt::AlignmentFlags  alignment() const ;

    virtual void setAlignment( Qt::AlignmentFlags alignment );

     NumLines numLines() const ;

    void     setNumLines(NumLines numlines);

    TextDirection textDirection() const ;

    void setTextDirection(TextDirection tdirection);

    TruncateNum truncateNum() const ;
    void setTruncateNum(TruncateNum truncatenum);
    void        getFrameWidth(int & nleftf,int & nrightf, int & ntopf, int & nbottomf) const;
    void setParentBackground(bool isParentBg);
    bool isParentBackground();

    QString truncateString() const ;

    void setTruncateString(const QString & truncateStr);

    TruncateStat truncateStat() const ;

    void setTruncateStat(TruncateStat truncatestat);

    int marqueeSpeed() const;

    void setMarqueeSpeed(int marqueespeed);

    int marqueeStep() const;

    void setMarqueeStep(int marqueestep);

    MarqueeDirection marqueeDirection() const;

    void setMarqueeDirection(MarqueeDirection marqueedirection);

    int marqueeRepetition() const;

    void setMarqueeRepetition(int marqueerepetition);

    int leading() const;

    void setLeading(int leading);

   void setFontColor(const QColor & color);

    QColor fontColor() const;

     int preferredWidth() const;

    void setPreferredWidth(int preferredw);

    ZWrapLine::WrapPolicy wrapPolicy() const;

    void setWrapPolicy(ZWrapLine::WrapPolicy wrappolicy);

    bool autoResize() const;

     virtual void setAutoResize( bool enable);

    MarqueeState marqueeState() const;

    void setMarqueeState(MarqueeState marqueeStat);

    void   marqueePlay();

    void   marqueePause();

    QSize sizeHint() const;

     virtual void setGeometry(int x,int y, int w, int h);
     virtual void setGeometry(const QRect & r);
     virtual void resize(int w, int h);

    int heightForWidth ( int w ) const;

    void setPadding( const WIDGET_PADDING_INFO_T & padd );

     virtual void setEnabled(bool enable);
     bool isZEnabled();
     bool isZDisabled();

    void setOutline(bool outline,QColor outc=QColor(255,0,0),QColor innerc=QColor(0,0,0));

    //void setOutline( bool outline,short outlineSize=1 ,QColor outc=QColor(255,0,0),QColor innerc=QColor(0,0,0));
    virtual void setPalette(const QPalette &);

    void adjustHeightBySetting(int nPreferredHeight);

    int  getContentNumLines();

    void updateLabelSkin();
    
	//add by Ant-ON
	//virtual void setFont(QFont& font);
	// 
    
public slots:
    virtual void setText( const QString &);

    void clear();

protected:

    void paintEvent(QPaintEvent *);

    virtual void fontChange( const QFont & );

    virtual void showEvent ( QShowEvent * );

    QRect getContentRect(); 

private slots:
    void slotScrollTimer();
    
private:
    void init();
    void clearContents();
    void updateLabel( QSize oldSizeHint );
    QSize sizeForWidth( ) const;
    void paintHscroll(QPainter * p);
    void paintVscroll(QPainter * p);
    void paintStaticText(QPainter * p);
    int getLineH(int linenum) const;
    int getHTotalWidth();
    int getVTotalHeight();
    void getTruncStr(QString & string,char addchar,int addnums);
    void wrapLine();
    int  getSpaceWidth();
    void startScroll();
    void stopScroll(bool bRScroll = 0);
    int  getRealNums();
    bool isScroll();
    QRect getLabelRect();
    QString getTrancatestr(const QString & str);
    int getSpacing() const;

    ZLabelPrivate * d;
    void drawOutlineText(QPainter *p, QColor tc, QColor oc,int x, int y, int w, int h, int flags,
    const QString& str, int len = -1, QRect *br=0,
    char **internal=0 );
};

#endif  
