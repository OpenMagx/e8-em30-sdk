

// Copyright (c)  - 2008 Motorola, Inc. All rights reserved.

#ifndef ZTABLEVIEW_H
#define ZTABLEVIEW_H

#ifndef QT_H
#include "qtableview.h"
#endif // QT_H

#ifndef QT_NO_TABLEVIEW
#include "ZWidget.h"

class EZXStyle;
class QScrollBar;
class QCornerSquare;


class Q_EXPORT ZTableView : public ZWidget
{
    Q_OBJECT
public:
    virtual void setBackgroundColor( const QColor & );
    virtual void setPalette( const QPalette & );
    void	show();

    void	repaint( bool erase=TRUE );
    void	repaint( int x, int y, int w, int h, bool erase=TRUE );
    void	repaint( const QRect &, bool erase=TRUE );

protected:
    ZTableView( QWidget *parent=0, const char *name=0, WFlags f=0, ZSkinService::WidgetClsID clsId = ZSkinService::clsTotal);
   ~ZTableView();

    int		numRows()	const;
    virtual void setNumRows( int rows, bool updateScrBars = TRUE);
    int		numCols()	const;
    virtual void setNumCols( int );

    int		topCell()	const;
    virtual void setTopCell( int row );
    int		leftCell()	const;
    virtual void setLeftCell( int col );
    virtual void setTopLeftCell( int row, int col );

    int		xOffset()	const;
    virtual void setXOffset( int );
    int		yOffset()	const;
    virtual void setYOffset( int );
    virtual void setOffset( int x, int y, bool updateScrBars = TRUE );

    virtual int cellWidth( int col );
    virtual int cellHeight( int row );
    int		cellWidth()	const;
    int		cellHeight()	const;
    virtual void setCellWidth( int );
    virtual void setCellHeight( int );

    virtual int totalWidth();
    virtual int totalHeight();

    uint	tableFlags()	const;
    bool	testTableFlags( uint f ) const;
    virtual void setTableFlags( uint f );
    void	clearTableFlags( uint f = ~0 );

    bool	autoUpdate()	 const;
    virtual void setAutoUpdate( bool );

    void	updateCell( int row, int column, bool erase=TRUE );

    QRect	cellUpdateRect() const;
    QRect	viewRect()	 const;

    int		lastRowVisible() const;
    int		lastColVisible() const;

    bool	rowIsVisible( int row ) const;
    bool	colIsVisible( int col ) const;

    QScrollBar *verticalScrollBar() const;
    QScrollBar *horizontalScrollBar() const;

private slots:
    void	horSbValue( int );
    void	horSbSliding( int );
    void	horSbSlidingDone();
    void	verSbValue( int );
    void	verSbSliding( int );
    void	verSbSlidingDone();

protected:

    ///
    /// The standard Qt paintCell(...) implementation doesn't pass the x and
    /// y coordinates of the cell to paintCell.  For blending with the background
    /// wallpaper, we need those coordinates to be able to calculate the
    /// wallpaper coordinates.  So we added this method.
    ///
    /// The default implementation calls the original Qt paintCell without
    /// xPos and yPos
    ///
   
    void setClipRect(QPainter * p, int x, int y, int w, int h);
    void setClipRect (QPainter * p, QRect & r );
    void setClipRegion ( QPainter * p, QRegion & rgn ); 
    virtual void paintCell( QPainter *, int row, int col, int xPos, int yPos );

    /// 
    /// The default Qt paintCell(...) below has been changed to be not-abstract
    /// because we want old derived-classes to still compile, and new derived
    /// classes to not be required to implement it.
    ///
    
    virtual void paintCell( QPainter *, int row, int col );

    virtual void setupPainter( QPainter * );

    void	paintEvent( QPaintEvent * );

    void   paintEventEx(QPaintEvent *, int, int);

    void	resizeEvent( QResizeEvent * );

    int		findRow( int yPos ) const;
    int		findCol( int xPos ) const;

    bool	rowYPos( int row, int *yPos ) const;
    bool	colXPos( int col, int *xPos ) const;

    int		maxXOffset();
    int		maxYOffset();
    int		maxColOffset();
    int		maxRowOffset();

    int		minViewX()	const;
    int		minViewY()	const;
    int		maxViewX()	const;
    int		maxViewY()	const;
    ///add the view properties 
    void	setViewMargins(int left, int top, int right, int bottom);
    ///add the view properties

    virtual void drawTableFrame(QPainter * p, QRect & updateR);
    
    int		viewWidth()	const;
    int		viewHeight()	const;

    void	scroll( int xPixels, int yPixels );
    void	updateScrollBars();
    void	updateTableSize();

private:
    void	coverCornerSquare( bool );
    void	snapToGrid( bool horizontal, bool vertical );
    virtual void	setHorScrollBar( bool on, bool update = TRUE );
public:
    virtual void	setVerScrollBar( bool on, bool update = TRUE );
private:    
    void	updateView();
    int		findRawRow( int yPos, int *cellMaxY, int *cellMinY = 0,
			    bool goOutsideView = FALSE ) const;
    int		findRawCol( int xPos, int *cellMaxX, int *cellMinX = 0,
			    bool goOutsideView = FALSE ) const;
    int		maxColsVisible() const;

    void	updateScrollBars( uint );
    void	updateFrameSize();

    void	doAutoScrollBars();
    void	showOrHideScrollBars();

    int		nRows;
    int		nCols;
    int		xOffs, yOffs;
    int		xCellOffs, yCellOffs;
    short	xCellDelta, yCellDelta;
    short	cellH, cellW;

    uint	eraseInPaint		: 1;
    uint	verSliding		: 1;
    uint	verSnappingOff		: 1;
    uint	horSliding		: 1;
    uint	horSnappingOff		: 1;
    uint	coveringCornerSquare	: 1;
    uint	sbDirty			: 8;
    uint	inSbUpdate		: 1;

    uint	tFlags;
    QRect	cellUpdateR;

    QScrollBar *vScrollBar;
    QScrollBar *hScrollBar;
    QCornerSquare *cornerSquare;

    ///add the view properties
    int viewLeft;
    int viewTop;
    int viewRight;
    int viewBottom;
    ///add the view properties

   EZXStyle * st; 

private:	/// Disabled copy constructor and operator=
#if defined(Q_DISABLE_COPY)
    ZTableView( const ZTableView & );
    ZTableView &operator=( const ZTableView & );
#endif
};

///
///const uint Tbl_vScrollBar	= 0x00000001;
///const uint Tbl_hScrollBar	= 0x00000002;
///const uint Tbl_autoVScrollBar	= 0x00000004;
///const uint Tbl_autoHScrollBar	= 0x00000008;
///const uint Tbl_autoScrollBars	= 0x0000000C;

///const uint Tbl_clipCellPainting = 0x00000100;
///const uint Tbl_cutCellsV	= 0x00000200;
///const uint Tbl_cutCellsH	= 0x00000400;
///const uint Tbl_cutCells		= 0x00000600;

///const uint Tbl_scrollLastHCell	= 0x00000800;
///const uint Tbl_scrollLastVCell	= 0x00001000;
///const uint Tbl_scrollLastCell	= 0x00001800;

///const uint Tbl_smoothHScrolling = 0x00002000;
///const uint Tbl_smoothVScrolling = 0x00004000;
///const uint Tbl_smoothScrolling	= 0x00006000;

///const uint Tbl_snapToHGrid	= 0x00008000;
///const uint Tbl_snapToVGrid	= 0x00010000;
///const uint Tbl_snapToGrid	= 0x00018000;

///
inline int ZTableView::numRows() const
{ return nRows; }

inline int ZTableView::numCols() const
{ return nCols; }

inline int ZTableView::topCell() const
{ return yCellOffs; }

inline int ZTableView::leftCell() const
{ return xCellOffs; }

inline int ZTableView::xOffset() const
{ return xOffs; }

inline int ZTableView::yOffset() const
{ return yOffs; }

inline int ZTableView::cellHeight() const
{ return cellH; }

inline int ZTableView::cellWidth() const
{ return cellW; }

inline uint ZTableView::tableFlags() const
{ return tFlags; }

inline bool ZTableView::testTableFlags( uint f ) const
{ return (tFlags & f) != 0; }

inline QRect ZTableView::cellUpdateRect() const
{ return cellUpdateR; }

inline bool ZTableView::autoUpdate() const
{ return isUpdatesEnabled(); }

inline void ZTableView::repaint( bool erase )
{ repaint( 0, 0, width(), height(), erase ); }

inline void ZTableView::repaint( const QRect &r, bool erase )
{ repaint( r.x(), r.y(), r.width(), r.height(), erase ); }

inline void ZTableView::updateScrollBars()
{ updateScrollBars( 0 ); }


#endif // QT_NO_TABLEVIEW

#endif // QTABLEVIEW_H
