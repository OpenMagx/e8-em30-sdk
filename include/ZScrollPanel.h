

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZSCROLLPANEL_H
#define PUBLIC_API_WIDGET_ZSCROLLPANEL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZWidget.h"
#include "ZScrollBar.h"
#include "ZGroupBox.h"

struct ZScrollPanelData;
class  ZMultiLineEdit;

class Q_EXPORT ZScrollPanel : public ZWidget
{

    Q_OBJECT

public:
    ZScrollPanel(QWidget *parent=0, const char *name=0, WFlags f=0,
                 ZSkinService::WidgetClsID = ZSkinService::clsZScrollPanel);

    ~ZScrollPanel();

    virtual void updateSkin(bool redraw);

    virtual void removeChild(ZWidget* child);

    virtual void addChild( ZWidget* child, int x, int y );

    virtual void moveChild( ZWidget* child, int x, int y );

    int childX(ZWidget* child);

    int childY(ZWidget* child);

    enum ScrollBarMode { Auto, AlwaysOff, AlwaysOn };

    ScrollBarMode vScrollBarMode() const;

    virtual void  setVScrollBarMode( ScrollBarMode );

    ScrollBarMode hScrollBarMode() const;

    virtual void  setHScrollBarMode( ScrollBarMode );

    ZScrollBar*  horizontalScrollBar() const;

    ZScrollBar*  verticalScrollBar() const;

    ZWidget*	 viewport() const;

    ZWidget*	 clipper() const;

    int		contentsWidth() const;

    int		contentsHeight() const;

    int		contentsX() const;

    int		contentsY() const;

    int		visibleWidth() const;

    int		visibleHeight() const;

    void	resize( int w, int h );

    void	resize( const QSize& );

    void	show();

    void	updateContents( int x, int y, int w, int h );

    void	updateContents( const QRect& r );

    void	repaintContents( int x, int y, int w, int h, bool erase=TRUE );

    void	repaintContents( const QRect& r, bool erase=TRUE );

    void	contentsToViewport(int x, int y, int& vx, int& vy);

    void	viewportToContents(int vx, int vy, int& x, int& y);

    QPoint	contentsToViewport(const QPoint&);

    QPoint	viewportToContents(const QPoint&);

    void	enableClipper(bool y);

    QSize	viewportSize( int, int ) const;

    QSizePolicy sizePolicy() const;

    QSize	sizeHint() const;

    QSize	minimumSizeHint() const;

    void  setFocusArea(int left, int top, int right, int bottom);

    int focusAreaLeft() const;

    int focusAreaRight() const;

    int focusAreaTop() const;

    int focusAreaBottom() const;

    void setKeyScrollWrap(bool wrap);

    bool keyScrollWrap() const;

    void setFramesWidth(int left, int top, int right, int bottom);

    ZWidget* firstChild() const;

    ZWidget* lastChild() const;

    ZWidget* nextChild(ZWidget* child) const;

    ZWidget* prevChild(ZWidget* child) const;

     void setZBorder( WIDGET_BORDER_INFO_T borderItems[StateCount]);

     void setZBorder( BorderPixmaps& pixmaps);

#ifndef QT_NO_PALETTE
     void setPalette( const QPalette & );
#endif

public:
    void omitOmega(bool bOmit);

    virtual bool  isScrollPanelTypeWidget() const;

    virtual void  resetFocusItem(bool);

    virtual QRect getCurrentFocusRect(int) const;

    virtual bool  hasNextPrevFocusItem(bool) const;

    void setNestScrollPanelMode(bool nest);

    bool nestScrollPanelMode() const;

    void setMoveFocusOutRange(bool b);

    bool focusOutRange() const;

    virtual bool noFocusMode() const;

    void setAutoExpandInNestMode(bool expand);

    bool autoExpandInNestMode() const;

    virtual QPixmap* getBgImageForTransparent(bool& freeImage);

public:
    virtual void setMargins(int left, int top, int right, int bottom);

    int leftMargin() const;

    int topMargin() const;

    int rightMargin() const;

    int bottomMargin() const;

signals:

    void	contentsMoving(int x, int y);

    void	contentsResizing(ZScrollPanel*, int w, int h);

public slots:
    virtual void resizeContents( int w, int h );

    void	scrollBy( int dx, int dy );

    virtual void        setContentsPos( int x, int y );

    void	ensureVisible(int x, int y);

    void	ensureVisible(int x, int y, int xmargin, int ymargin);

    void	center(int x, int y);

    void	center(int x, int y, float xmargin, float ymargin);

    void	updateScrollBars();

    void	setEnabled( bool enable );

    void        editCursorMove(bool down);

protected:

    void	resizeEvent(QResizeEvent*);

    void        keyPressEvent( QKeyEvent *e );

    void        keyReleaseEvent( QKeyEvent *e );

    bool	eventFilter( QObject *, QEvent *e );

    virtual void contentsMousePressEvent( QMouseEvent* );

    virtual void contentsMouseReleaseEvent( QMouseEvent* );

    virtual void contentsMouseDoubleClickEvent( QMouseEvent* );

    virtual void contentsMouseMoveEvent( QMouseEvent* );

    virtual void viewportPaintEvent( QPaintEvent* );

    virtual void viewportResizeEvent( QResizeEvent* );

    virtual void viewportMousePressEvent( QMouseEvent* );

    virtual void viewportMouseReleaseEvent( QMouseEvent* );

    virtual void viewportMouseDoubleClickEvent( QMouseEvent* );

    virtual void viewportMouseMoveEvent( QMouseEvent* );

    virtual void drawContentsOffset(QPainter*, int ox, int oy,
		    int cx, int cy, int cw, int ch);

    virtual void drawContents(QPainter*, int cx, int cy, int cw, int ch);

    bool focusNextPrevChild( bool next );

    enum ResizePolicy { Default, Manual, AutoOne, AutoOneFit  };

    virtual void setResizePolicy( ResizePolicy );

    ResizePolicy resizePolicy() const;

    virtual void setHBarGeometry(ZScrollBar& hbar, int x, int y, int w, int h);

    virtual void setVBarGeometry(ZScrollBar& vbar, int x, int y, int w, int h);
    QObjectList * queryChildrenList();
    virtual void insertFormItemChild(ZWidget *child,int x,int y,ZWidget *after = NULL);
    void adjustContents(ZWidget *child,int h);

private:

    void     setStaticBackground(bool y);
    bool     hasStaticBackground() const;

    void styleChange(QStyle&);

    int adjustPosInRange(int curTop, int curBottom, QRect& rect, bool next);

    void handleOmgEvent(QKeyEvent* e);

    ZWidget* prevNextOmgWidget(ZWidget*widget, bool next, bool& bWraped);
private:
    virtual void drawContents( QPainter* );
    void moveContents(int x, int y);

    ZWidget* prevNextWidget(ZWidget*widget, bool next, bool& wraped);

    ZScrollPanelData* d;

private slots:
    void hslide(int);
    void vslide(int);
    void slotContentsResizing(ZScrollPanel*, int, int);
    void slotContentsResizing(ZGroupBox*, int, int);
    void slotContentsResizeTimer();

    void slotContentsResizing(ZMultiLineEdit *, int, int);

    void slotWaitWrapFinished();

    friend class ZScrollPanelData;
};

#endif 
