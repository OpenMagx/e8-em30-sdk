//Fix for E8/EM30 by Ant-ON, 25-10-2010

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ZPOPUP_H
#define ZPOPUP_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZSkinBase.h"
#include "ZUNS_PopupDefines.h"

#include <qdialog.h>
#include <qgfx_qws.h>

class ZAppInfoArea;
class ZSoftKey;
class ZCLISoftKey;
class ZWidget;
class ZPopupHeader;

class ZFormContainer;
class ZDetailView;
class ZIconView;
class ZListBox;
class ZScrollPanel;
class ZLabel;
//class ZPopupEventFilter;

struct ZPopupPrivate;
struct ZPopupPrivateUNS;

class ZPopup : public QDialog
{
    Q_OBJECT

public:

    enum POPUP_TYPE_E
    {
        DIALOG,    
        NOTICE     
    };

    enum PopupCode
    {
        Rejected = QDialog::Rejected,
        Accepted = QDialog::Accepted, 
        AutoDismissed = 100,     
        AnykeyPressed,            
        DismissByEndKey           
    };

    ZPopup(POPUP_TYPE_E type = DIALOG,
           QWidget *parent = 0,
           const char *name = 0,
           bool modal = true,
           int dismiss_time = 0,
           WFlags f = 0);

    virtual ~ZPopup();

    void setTitle(const QString& strTitle);

    QString getTitle();

    void setTitleIcon(const QString& strResourceID);

    void setTitleIcon(const QPixmap& icon);

    ZPopupHeader* getPopupHeader();

    void enableAia(bool enable);

    ZAppInfoArea* getAppInfoArea();

    void setInstructText(const QString& str);

    void setInsTruncPolicy(bool truncated = false);

	int getBodyAvailableWidth() const;

	int getBodyAvailableHeight();

    void insertChild(ZWidget* child, int index = -1);

    void removeChild(ZWidget* child);

    void insertChild(ZFormContainer* pFormContainer, int index = -1);

    void insertChild(ZDetailView* pDetailView,       int index = -1);

    void insertChild(ZIconView* pIconView,           int index = -1);

    void insertChild(ZListBox* pList,                int index = -1);

    void setSoftkeyTextLeft(const QString&);

    void setSoftkeyTextRight(const QString&);

    void setSoftkeyText(const QString& left, const QString& right);

    ZSoftKey *getSoftKey();

    //bool setCLISoftKey(ZCLISoftKey* cliSoftKey);
    //ZCLISoftKey* getCLISoftKey();
    //void setAlwaysActive(bool bActive);
    //bool isAlwaysActive();
    
    void setAutoDismissTime(int msec);

    void setReturnIdlePolicy(int reason, bool disableDefaultBehavior = false);

    virtual void doLayout(bool bLayoutNow = true);

    virtual void show();

    int exec();

    void setScrollable(bool bScrollable);

    bool getScrollable();

    void setBodyPadding(const WIDGET_PADDING_INFO_T& pad);

    void setBodyBorder(WIDGET_BORDER_INFO_T borderItems[ZSkinBase::StateCount]);

    void setBodyBorder(ZSkinBase::BorderPixmaps& pixmaps);

    void setBodyBackground(QPixmap& image);

    void setBodyVSpacing(int nVSpacing);

    void setInstructPadding(const WIDGET_PADDING_INFO_T& pad);

    void setInstructFont(const QFont& fnt);

    void setInstructFontColor(const QColor& clr);

    void setPalette(const QPalette&);

    ZLabel* getInstructionLabel() const;            
    Qt::AlignmentFlags getInstructAlign() const;
    void setInstructAlign(Qt::AlignmentFlags f);

    static void stretchPixmap( QPixmap& pm, int width, int height, PIXMAP_STRETCH_POLICY_E type);
    static void fillRect(QPainter& painter, QRect& rect, QColor& color, 
                QPixmap* bgPixmap, int xBg, int yBg, int blendPercent);

    int getBodyBorderWidth(ZSkinBase::BorderSide side);

    //void dismissByEndKey (bool b);

public slots:

    void done( int r );

    void accept();

    void reject();

signals:

    void leftSoftkeyClicked();

    void rightSoftkeyClicked();

    void signalClearKeyPressed();

    void askReturnToIdle(int reason);

protected slots:

    virtual void slotLSKClicked();

    virtual void slotRSKClicked(); 

    virtual void slotResizeAllChild(int);

protected:

    virtual void keyPressEvent(QKeyEvent*);

    virtual void showEvent(QShowEvent*);

    virtual void hideEvent(QHideEvent*);

    virtual void timerEvent(QTimerEvent*);

    virtual void customEvent(QCustomEvent*);

    const ZScrollPanel* getBody() const;

    QFont instructFont() const;

    QColor instructFontColor() const;


    void paintEvent(QPaintEvent*);

    void postLayoutEvent();

private slots:
    void slotSPC_resize(ZScrollPanel*, int, int);

    //void slotChildDelete();

private:
    void updateIdleScreenSign();

    void loadSkinData(bool bThemeChanged = false);
    void applySkinData();
    void releaseBodyPixmap();
    void applyBodyBk();
    void applyBodyPadding();

    void removeAndInsert();

    void layoutDialog();
    void layoutNotice();
    void layoutScrollPanel();

    void layoutOtherContainer();

    void layoutNothing();

    void layoutDialogFourAreas();
    void layoutNoticeTwoAreas();

    int  getChildrenMaxWidth();
    bool isNeedShowVScrollBar() const;

    void detect_xModal();

    int calculateDesiredContentHeight(const int nWidthMax);
    int calculateBodyAvailWidth(bool bShowScrollbar) const;

    void layout_inner(const int nTop, const int nAvailW);

    void setInsLabelProperty(bool bScrollable);

    void doShow();

    //void setBodySideKeyHandlePolicy();

    void drawSingleBodyBorder(QPainter& p, QPixmap& bg, QPixmap & border, int percent, int left, int top, int bodyY);
    void drawBodyBorder();

private:

    ZPopupPrivate* mpData;

public:

    bool setUNSFlag(UNS_PRIO_T priority);

    UNS_PRIO_T getUNSFlag();

    void showUNSDlg(bool showOnTaskState = false);

    bool setBypassSIMLock(bool bBypass);

    bool getBypassSIMLock();

signals:

    void dlgAboutToShow();

    void dlgAboutToHide(int);

private:
    void killScreenSaver();

private slots:
    void slotSocketConnected();
    void slotSocketReadyRead();
    void slotConnectionClosed();

    void slotFlipOnOff(int);

private:
    ZPopupPrivateUNS* mpDataUNS;

//private:    
//    ZPopupEventFilter *evtFilter;
};

/*
class ZPopupEventFilter : public QObject
{
    Q_OBJECT
public:
    ZPopupEventFilter( ZPopup * p ) : popup( p ) {}
    bool eventFilter(QObject* o, QEvent* e);
private:
    ZPopup *popup;
};
*/

#endif  
