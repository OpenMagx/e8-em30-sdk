

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZCOMBOBOX_H
#define PUBLIC_API_WIDGET_ZCOMBOBOX_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZButton.h"

#ifndef EZX_NO_COMBOBOX

struct ZComboData;
class QStrList;
class QStringList;
class ZLineEdit;
class QValidator;
class ZListBox;
class ZListBoxItem;

class Q_EXPORT ZComboBox : public ZButton
{
    Q_OBJECT

public:
    enum Policy
    {
          NoInsertion,            
	  AtTop,			
	  AtCurrent,		
	  AtBottom,		
          AfterCurrent,		
	  BeforeCurrent
    };

    enum DlgType
    {
        SingleSelectDlg,          
        SingleCaptureDlg        
    };

public:
    ZComboBox( QWidget *parent=0, const char *name=0, bool isInitListBox = true );

    ZComboBox( bool rw, QWidget *parent=0, const char *name=0, bool isInitListBox = true );

   ~ZComboBox();

    int count() const;

    void insertStringList( const QStringList &, int index=-1 );

    void insertStrList( const QStrList &, int index=-1 );

    void insertStrList( const QStrList *, int index=-1 );

    void insertStrList( const char **, int numStrings=-1, int index=-1);

    void insertItem( const QString &text, int index=-1 );

    void insertItem( const QPixmap &pixmap, int index=-1 );

    void insertItem( const QPixmap &pixmap, const QString &text, int index=-1 );

    void removeItem( int index );

    void clear();

    QString currentText() const;

    QString text( int index ) const;

    const QPixmap pixmap( int index ) const;

    void changeItem( const QString &text, int index );

    void changeItem( const QPixmap &pixmap, int index );

    void changeItem( const QPixmap &pixmap, const QString &text, int index );

    int currentItem() const;

    virtual void setCurrentItem( int index );

    virtual void setSizeLimit( int );

    int sizeLimit() const;

    virtual void setMaxCount( int );

    int maxCount() const;

    virtual void setInsertionPolicy( Policy policy );

    Policy insertionPolicy() const;

    virtual void setValidator( const QValidator * v);

    const QValidator * validator() const;

    ZListBox * listBox() const;

    ZLineEdit * lineEdit() const;

    bool eventFilter( QObject *object, QEvent *event );

    virtual void setAutoCompletion( bool );

    bool autoCompletion() const;

    void setDuplicatesEnabled( bool enable );

    bool duplicatesEnabled() const;

    bool editable() const;

    void setEditable( bool y);

    void setDlgTitle(const QString & title, DlgType dlgType = SingleSelectDlg);

    void setDlgInstructText(const QString & instructText, DlgType dlgType = SingleSelectDlg);

    void setSoftkeyTextLeft(const QString& strText, DlgType dlgType = SingleSelectDlg);

    void setSoftkeyTextRight(const QString& strText, DlgType dlgType = SingleSelectDlg);

    void setSoftkeyText(const QString& strLeft, const QString& strRight, DlgType dlgType = SingleSelectDlg);

    void getFrameWidth(int & nleftw, int & nrightw, int & ntopw, int & nbottomw) const;

public slots:

    void clearValidator();

signals:

    void activated( int index );

    void highlighted( int index );

    void activated( const QString &);

    void highlighted( const QString &);

    void textChanged( const QString &);

    void sigInsertData(QWidget * pWidget, bool isFirst);

private slots:
    void internalActivate( int );
    void internalHighlight( int );
    void returnPressed();
    void pressPopupButton();
    void slotClearKeyClick();

protected slots:
    virtual void slotLeftSoftkeyClick();
    virtual void slotRightSoftkeyClick();

protected:
    int getItemType(ZListBoxItem * item) const;
    void resizeEvent( QResizeEvent * );
    void keyPressEvent( QKeyEvent *e );
    void styleChange( QStyle& );
    void showEvent(QShowEvent * );
    void customEvent(QCustomEvent * );

    void updateSkin(bool redraw);

    virtual void setPalette(const QPalette &);

    void popup(bool editable);

    virtual QRect getContentRect() const;
    virtual void getBtnFrameWidth(int & nleftw, int & nrightw, int & ntopw, int & nbottomw) const;
    virtual void getLabelFrameWidth(int & nleftw, int & nrightw, int & ntopw, int & nbottomw) const; 
    virtual void drawBorderEx(ItemType itemType, QPainter * p, const QRect * rect = NULL);
    virtual void drawBackgroundEx(ItemType itemType, QPainter * p, const QRect * rect = NULL);
    virtual int  getBtnHSpacing() const;
    virtual int  getTitleSpacing(TitlePosition titlePos = TitleTop) const;
    virtual void stateChanged(StateChangeReason stChangeReason);
    virtual void titleChanged(const QString & title);
    virtual void getCurrentFont(QFont & font, QColor & ftColor, ItemType itemType) const;

private:
    void returnPressed(bool isPopupDown);
    void internalActivate(int nIndex, bool isPopupDown);
    void updateBtn(int nIndex);
    void postCustomEvent();
    bool isSpecialData(int nIndex,int nFlag);
    void changeZItem(const QString & t,int index);
    void changeZItem(const QPixmap & pixmap,int index);
    void changeZItem(const QPixmap & pixmap,const QString & t,int index); 
    void insertZItem(const QString & t, int index,int rsvData);
    void insertZItem(const QPixmap & pixmap,int index,int rsvData);
    void insertZItem(const QPixmap & pixmap,const QString & t, int index,int rsvData);
    void setDialog();
    void setPressBtn();
    void setUpListBox();
    void setUpLineEdit();
    void setCaptureDlg();
    void cancelCaptureDlg();
    void popDownListBox();
    void reIndex();
    void currentChanged();
    int adjustIndex(int nIndex) const;
    int realCount() const;
    void inital();

    int mEventData;   

    ZComboData     *d;

private:     
#if defined(Q_DISABLE_COPY)
    ZComboBox( const ZComboBox & );
    ZComboBox &operator=( const ZComboBox & );
#endif
};

#endif 

#endif  
