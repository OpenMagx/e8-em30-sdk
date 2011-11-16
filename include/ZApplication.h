//Fix for E8/EM30 by Ant-ON, 25-10-2010

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef Z_APPLICATION_H
#define Z_APPLICATION_H

#ifndef __cplusplus
#error "This is a C++ header file;it requires C++ to compile."
#endif

#include <qapplication.h>
#include <qwindowsystem_qws.h>
#include <qcopchannel_qws.h>
#include <qwsevent_qws.h>
#include <qvaluelist.h>
#include "ZMorphingModeDef.h"
#include "ZIMethod.h"
#include "ZKeyDef.h"

class ZApplicationData;
class QUuid;
struct ZWidgetSkinProps;

struct ZKbInputField;
class KbTouchInputEngine;

#include <ZWidget.h>
class ZSkinService;

class ES_Event;

class ZApplication : public QApplication
{
    Q_OBJECT

public:

    ZApplication( int& argc, char **argv, Type = GuiClient );

    virtual ~ZApplication();

    ZWidgetSkinProps * getSkinnableProperties();

    void showMainWidget( QWidget* mainWidget );

    int exec();

    void setAutoInvokeKb( bool invoke = true );

    bool getAutoInvokeKb();

    void setAutoInvokeKb( QWidget* editableWidget, bool invoke = true );

    void setAutoHideKb( bool hide = false );

    bool getAutoHideKb();

    void setDefaultKbMethod( const QUuid& method );

    QUuid getDefaultKbMethod( bool readConfig = false );

    void registerEditableWidget(const char* className);

    void setInputMethods( QWidget* widget, const QUuid& defaultIM,
                          const QValueList<QUuid> & favourIMList,
                          int fieldType = ZKbInputField::FIELD_TYPE_REGULAR,
                          QString fieldName = QString() );

    void setInputMethod( QWidget* widget, const QUuid& defaultIM,
                         int fieldType = ZKbInputField::FIELD_TYPE_REGULAR,
                         QString fieldName = QString() );

    void removeEditableWidget(const char* className);

    ZKbInputField * getKbInputField(QWidget * edit);

    bool getKBState();

    QIMMap getIMList();

    void updateIMNameList();

    enum
    {
        LEFT_ONLY = 0, 
        PRESS_HOLD     
    };

    static void setMouseMode( QWidget* widget, int mode );

    static int getMouseMode( QWidget* widget );

    void startShowWaitCursor( int startTime = 0,const QString& resId = QString::null );

    void stopShowWaitCursor();

    void loadString( const QString& strFileName );

    const QString& getAppName();

    const char*  getAppChannelName();

    void enableTouchSound( bool enable = true );

    void raiseAppWindows();

    void flushMsgs();

    bool notify(QObject *, QEvent *);

    void setAppFSBA(const QPixmap& pmapFSBA, int opacity = 100, int stretchPolicy = 0);
    QPixmap* getFSBAImage(int fsbaID);
    QPixmap* getFSBA(const ZWidget* pWidget);
    int getAppSysFSBAID();

    ZSkinService& getSkinService(const ZWidget* pWidget = NULL) const;
    void setAppLayoutDirection(ZWidget::LayoutDirection l);
    ZWidget::LayoutDirection getAppLayoutDirection() const;

    QValueList<int> queryMorphCapability(void);     

signals:

    void appMessage( const QCString &msg, const QByteArray &data );

    void shutdown();

    void quickQuit();

    void usbStorageInOut(bool storageIn );

    void signalRaise();
    void signalRaiseWithPolicy( int policy ); 

    void clickAppIcon();

    void signalLanguageChange();

    void signalAppThemeChange();
    void signalThemeChange();

    void signalAppLaunched( const QUuid appID );

    void signalAppKilled( const QUuid appID );

    void signalOpenDoc( const QString &doc );

    void signalCmdLine( const QString &cmdLine );

    void signalBridgeMessage( const QByteArray &data );

    void signalBridgeMessage( const QCString &action, const QByteArray &data );

    void signalBridgeMessageWithoutRaise( const QCString &action, const QByteArray &data );

    void signalMasterClear();
    void signalTcmdMasterClear();

    void signalMasterReset();
    void signalTcmdMasterReset();

    void signalLaunchactionByIdlescreen(const QUuid&);
    void signalLaunchactionByMainscreen(const QUuid&);
    void signalLaunchactionByVoicecommand(const QUuid&);
    void signalLaunchactionByDedicatedkey(const QUuid&);
    void signalLaunchactionByAnotherApp(const QUuid&);
    void signalKillactionByMassstorage();

    void systemMessage( const QCString &msg, const QByteArray &data );

    void processMessage( const QCString &msg, const QByteArray &data );

    void flipStatusChanged(int state);

    void sliderStatusChanged( int status );

    void signalKbStateChanged(const QRect & resizeR, int topLevelWinId, bool show, bool changed);

    void kbStateChanged( bool show, const QUuid& imName, int kbh );

    void askReturnToIdle( int reason );

    void mainWidgetSizeChanged(int mwId, const QRect & resizeR);

protected:

    bool qwsEventFilter( QWSEvent* e );

    virtual bool eventFilter( QObject* o, QEvent* e);

    virtual void timerEvent( QTimerEvent* e);

    virtual void tryQuit();

    void setEnv( const QString& env );

    bool askDialogsDismiss( int reason );

protected slots:

    virtual void slotShutdown();

    virtual void slotQuickQuit();

    virtual void slotUsbStorageInOut(bool storagIn );

    virtual void slotClickAppIcon();

    virtual void slotRaise();

    virtual void slotLanguageChange();

    virtual void slotThemeChange();

    virtual void slotReturnToIdle( int reason );

    virtual void slotLaunchactionByIdlescreen(const QUuid&);
    virtual void slotLaunchactionByMainscreen(const QUuid&);
    virtual void slotLaunchactionByVoicecommand(const QUuid&);
    virtual void slotLaunchactionByDedicatedkey(const QUuid&);
    virtual void slotLaunchactionByAnotherApp(const QUuid&);
    virtual void slotKillactionByMassstorage();

private:

    QCopChannel*  getAppChannel();
    void soundTouchPanel( QWSEvent* e );
    void loadEZXFonts();
    bool createChannel();
    void startShowPHCursor( int startTime = 0,const QString& resId = QString::null );
    void stopShowPHCursor();
    void resetPHTimer();

    enum
    {
        WINS_LOWER = -1,
        WINS_HOLD = 0,
        WINS_SHOW,
        WINS_RAISE
    };

    void manipulateAppWindows( int show );
    void serverManipulateAppWindows( int show,const QString& clientName );
    void clientManipulateAppWindows( int show,QValueList<int>& winList );
    void setFocusToLatestWindow( int winId );

    int applyStyle();
    int initPalette();
    int applyPalette();
    int initTextSize();
    int changeTextSize();
    bool hasTimerWidgets();

private slots:

    void animationTimeOut();
    void animationStatus( int status );
    void animationUpdate( const QRect& );
    void slotCursorSelected( QWSCursor* cursor );

    void slotSysSetupMessage( const QCString &msg, const QByteArray &data );
    void slotSystemMessage( const QCString &msg, const QByteArray &data );
    void slotServerMessage( const QCString &msg, const QByteArray &data );
    void slotAppMessage( const QCString &msg, const QByteArray &data );
    //void pidMessage( const ES_Event& event );
    void pidMessage( const QCString &message, const QByteArray &data );// Fix by Ant-ON

    void resetMouseMode();
    void resetPressHoldStatus();

    void slotKbStateChanged(const QRect & resizeR, int topLevelWinId, bool show, bool changed);

    void slotHKData(const QCString&,const QByteArray&);

private:

    ZApplicationData* d;
    friend class ZMainWidget;
    friend class KbTouchInputEngine;
};

#endif 
