

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZBUTTON_H
#define PUBLIC_API_WIDGET_ZBUTTON_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZBaseButton.h"
#include "qapplication.h"
#include "ZSkinBase.h"
#include "ZText.h"

#define CUSTOMEVENT_TYPE   QEvent::User + 435

class ZButton : public ZBaseButton
{
    Q_OBJECT
    Q_ENUMS(TitlePosition)
    Q_PROPERTY( TitlePosition titlePosition READ titlePosition WRITE setTitlePosition )

public:
    enum TitlePosition
    {
        TitleTop,                
        TitleLeft                 
    };

    enum MarqueeDirect
    {
            LeftM,              
	    RightM,            
	    TopM,              
	    BottomM          
    };

public:
     ZButton(QWidget * parent =0, const char * name =0 , WFlags f = 0,ZSkinService::WidgetClsID clsId = ZSkinService::clsZFormItem);

     ZButton(const QString & title,ZButton::TitlePosition titlePos = TitleTop, QWidget * parent = 0 ,
                   const char * name = 0, WFlags f = 0 ,ZSkinService::WidgetClsID clsId = ZSkinService::clsZFormItem);

     virtual ~ZButton();

public:
     virtual QString text() const;

     virtual void setText(const QString & text);

     virtual void setNum(const int nNum);

     virtual const QPixmap * pixmap() const;

     virtual void setPixmap(const QPixmap & pixmap);

     ZButton::TitlePosition titlePosition() const;

     void setTitlePosition(ZButton::TitlePosition titlePos);

         QString title()const;

     void setTitle(const QString & title) ;

    virtual QSize sizeHint() const;

    ZSkinBase::RelativeAlignment relativeAlignment() const;

    void setRelativeAlignment(ZSkinBase::RelativeAlignment relativeAlign);

    void setEnabled(bool enable);

    bool isZEnabled();

    bool isZDisabled();

    void setFont(const QFont & font);

    void enableTruncation(bool isEnable);

    bool isEnableTruncation();

    void enableMarquee(bool isEnable);

    bool isEnableMarquee();

    void setMarqueeDirect(MarqueeDirect md);

    MarqueeDirect getMarqueeDirect();

    void setAvailableWidth(int nLen);

protected:
    enum ItemType
    {
        FormItem,         
        Label,               
        Widget              
    };

    enum StateChangeReason
    {
        RFocusIn,        
        RFocusOut,      
        RKeyPress,     
        RKeyRelease   
    };

    virtual QRect getContentRect() const = 0 ;

    virtual void getBtnFrameWidth(int & nleftw, int & nrightw, int & ntopw, int & nbottomw) const = 0;

    virtual void getLabelFrameWidth(int & nleftw, int & nrightw, int & ntopw, int & nbottomw) const = 0;

    virtual void getFrameWidth(int & nleftw, int & nrightw, int & ntopw, int & nbottomw) const = 0;

    virtual void drawBorderEx(ItemType itemType, QPainter * p, const QRect * rect = NULL) = 0;

    virtual void drawBackgroundEx(ItemType itemType, QPainter * p, const QRect * rect = NULL) = 0;

    virtual int  getBtnHSpacing() const = 0;

    virtual int  getTitleSpacing(ZButton::TitlePosition titlePos = TitleTop) const = 0;

    virtual void stateChanged(StateChangeReason stChangeReason) = 0;

    virtual void titleChanged(const QString & title) = 0;

    virtual void getCurrentFont(QFont & font, QColor & ftColor, ItemType itemType) const = 0;

    virtual void drawButton(QPainter * p);
    virtual void drawButtonLabel(QPainter * p);
    virtual void resizeEvent( QResizeEvent * e);
    virtual void keyPressEvent(QKeyEvent * e);
    virtual void keyReleaseEvent(QKeyEvent * e);
    virtual void focusInEvent(QFocusEvent * e);
    virtual void focusOutEvent(QFocusEvent * e);

protected:
    QSize getTitleSize() const;

    QSize getBtnSize() const;

    QRect getTitleRect() const;

    QRect getBtnRect() const;

    QRect getBtnContentRect() const;

    void reAdjustSize(bool bAll = false,int w=-1,int h=-1);

private:
    QString mtext;
    QPixmap * mpixmap;
    TitlePosition mTitlePos;
    QString mtitle;

    bool mIsEnabled;
    bool mIsTruncText;
    bool mIsMarqueeText;
    MarqueeDirect mMarqueeDirect;
    ZMarqueeText *mMarqueeText;
    ZSkinBase::RelativeAlignment mrelPos; 
    int mLen; 
};

#endif  
