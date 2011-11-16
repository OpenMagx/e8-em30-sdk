//Fix for E8/EM30 by Ant-ON, 25-10-2010

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef Z_KBMAINWIDGET_H
#define Z_KBMAINWIDGET_H

#ifndef __cplusplus
#error "This is a C++ header file;it requires C++ to compile."
#endif

#include "ZMainWidget.h"
#include "ZHeader.h"

class ZSoftKey;
class ZCLISoftKey;
class ZAppInfoArea;
class ZKbMainWidgetData;


class ZKbMainWidget : public ZMainWidget
{
	Q_OBJECT
public:
	ZKbMainWidget( QWidget *parent = 0, const char *name = 0, WFlags f = 0 );

	ZKbMainWidget( const QString &mwTitle, QWidget *parent = 0, const char *name = 0, WFlags f = 0 );

	ZKbMainWidget( ZHeader::HEADER_TYPE headerType, QWidget *parent = 0, const char *name = 0, WFlags f = 0 );

	virtual ~ZKbMainWidget();

	//Add by Ant-ON
	enum ENUM_CHILD{};
	QRect getChildR(ENUM_CHILD);
	QRect getChildR_Header();
	QRect getChildR_AIA();
	QRect getChildR_Content();
	QRect getChildR_Cst();

	ZHeader* getHeader();

	void setChildWidgetLayout();
	//

	void setHeaderType(ZHeader::HEADER_TYPE headerType);

	static bool setAppTitle( const QString &appTitle );

	static QString getAppTitle();

	QPixmap getTitlePixmap(int nIdx);

	bool setMainWidgetTitle( const QString &mwTitle );

	QString getMainWidgetTitle();

	bool setMainWidgetTitleIcon(const QPixmap& pmp);

	QPixmap getMainWidgetTitleIcon();

	bool setAppInfoArea( ZAppInfoArea *aia );

	ZAppInfoArea* getAppInfoArea();

	bool setSoftKey( ZSoftKey *cstWidget );

	ZSoftKey* getSoftKey( bool createZSoftKey = TRUE );

	//bool setCLISoftKey(ZCLISoftKey* cliSoftKey);

	//ZCLISoftKey* getCLISoftKey(bool createZCLISoftKey = TRUE);

	virtual bool eventFilter(QObject*, QEvent*);

	void setTitleTruncEnable(bool bTrunc);

	bool isTitleTruncEnable();

	void updateHeader();

	QSize headerSize();

	void setWidgetPixmapPrefix(QString& prefix );
	void setHeaderPixmapPrefix(QString& prefix);
	void hideHeader() ;

	void showHeader() ;
	virtual QWidget* getContentWidget(bool createZScrollView = TRUE);

	virtual bool setContentWidget(QWidget* w = NULL);
	virtual QWidget* getCSTWidget( bool create = TRUE );
	virtual bool setCSTWidget( QWidget* w = NULL );
	virtual bool setTitleBarWidget( QWidget* w = NULL );
	virtual QWidget* getTitleBarWidget();	
	virtual void setFullScreenMode(bool fullScreen, bool reserved = FALSE);

	virtual bool getFullScreenMode();

	QSize getContentSize();

	virtual bool getEditMode();

signals:

	void clearKeyClicked( );

	void serverInitialized();

	void TitlePixmapChanged(int nIdx);
	protected slots:
	virtual void slotKbWidgetSizeChanged(const QRect & resizeR,
						 int topLevelWinId,
						 bool show,
						 bool changed);
protected:

	virtual bool event( QEvent *e );

	int getLRSBaseIndex();

	virtual void keyPressEvent( QKeyEvent * e);

	virtual void resizeEvent( QResizeEvent * e);

private slots:  
	void slotAppMessage(const QCString &msg, const QByteArray &);
	void childDestroyed();

private:
	void init(ZHeader::HEADER_TYPE headerType);
	void initMainWidget();

private:
	ZKbMainWidgetData *data;
};

#endif

