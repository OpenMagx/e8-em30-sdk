//Fix for E8 by Ant-ON

// Copyright (c)  - 2008 Motorola, Inc. All rights reserved.


#ifndef ZMAINWIDGET_H
#define ZMAINWIDGET_H

#include <qscrollview.h>
#include <qlayout.h>
#include <qpopupmenu.h>
#include <qstringlist.h>
#include "ZWidget.h"
#include "ZGlobal.h"


class QUuid;
class ZMainWidgetPrivate;

class ZMainWidget: public ZWidget
{
    Q_OBJECT

public:

    enum
    {
        INPUTWIDGET_HIDE = 0, 
        INPUTWIDGET_SHOW,     
    };

    ZMainWidget(bool editorMode,
                QWidget* parent,
                const char* name = 0,
                WFlags f = 0 );

    ZMainWidget(bool kbMainWidget,bool editorMode,
                QWidget* parent,
                const char* name = 0,
                WFlags f = 0 );

    ZMainWidget(QWidget* parent, const char* name = 0, WFlags f = 0 );

    ZMainWidget( const QString& titleText, bool editorMode, QWidget* parent, const char* name = 0, WFlags f = 0 );

    virtual ~ZMainWidget();

public:

    virtual bool getEditMode();

    virtual QWidget* getContentWidget(bool createZScrollView = TRUE);

    virtual bool setContentWidget(QWidget* w = NULL);

    virtual QWidget* getCSTWidget( bool create = TRUE );

    virtual bool setCSTWidget( QWidget* w = NULL );

    virtual bool setTitleBarWidget( QWidget* w = NULL );

    virtual QWidget* getTitleBarWidget();

    int getKbState();

    void setInputMethod(QWidget* widget,
                        const QUuid& method = IMID_UNDEFINED,
                        int fieldType = 0,
                        QString fieldName = QString());

    void showWithInputMethod(const QUuid & method = IMID_UNDEFINED,
                             int flag = 0);

    void setFavoriteInputMethods(QWidget* widget,
                                 const QValueList<QUuid> & imList);

    void setFavoriteInputMethods(const QValueList<QUuid> & imList);

    void setInputMethods(QWidget* widget,
                         const QUuid& defaultIM,
                         const QValueList<QUuid> & favourIMList,
                         int fieldType = ZKbInputField::FIELD_TYPE_REGULAR,
                         QString fieldName = QString());

    void setInputMethods(QWidget* widget,
                         const QUuid& defaultIM,
                         int fieldType = ZKbInputField::FIELD_TYPE_REGULAR,
                         QString fieldname = QString());

    void setInputMethod(const QUuid& method = IMID_UNDEFINED,
                        int flag = 0);

    QValueList<QUuid> &  getFavoriteInputMethods() const;

    virtual void setFullScreenMode(bool fullScreen, bool reserved = FALSE);

    virtual bool getFullScreenMode();

public:

    virtual void show();

    virtual void hide();

    virtual bool eventFilter(QObject*, QEvent*);

public slots:

    virtual void hideInputWidget();

    virtual void slotPopupMenu(int id);

    virtual void invokeInputWidget();

signals:

    void kbStateChanged( bool show, const QUuid& imName, int kbh );

    void kbStateChanged(bool show);

    void fullScreenModeChanged( bool show );

    void mainWidgetSizeChanged(int mwId, const QRect & resizeR);

protected slots:

    virtual void slotKbWidgetSizeChanged(const QRect & resizeR,
                                 int topLevelWinId,
                                 bool show,
                                 bool changed);

    void slotKbStateChanged( bool show, const QUuid& imName, int kbh );

protected:

    virtual void paletteChange( const QPalette &pal);

    virtual bool showToolBar() { return FALSE; }

    virtual bool setToolBar( const QUuid& t) { return FALSE; }

    virtual bool hideToolBar() { return FALSE; }

    virtual void setupInputMethodsPopupMenu();

    virtual int getLRSBaseIndex();

    QVBoxLayout* getVBoxLayout();

private:

    void init( bool hasTitleBar = FALSE, const QString& text = QString::null );

private slots:

    void popupKBMenu();
    void objectDestroyed();


private:
    ZMainWidgetPrivate* d;
};

#endif

