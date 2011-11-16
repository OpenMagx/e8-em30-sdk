
/*
 * unoffical E8 EZX SDK 
 * Author : tulanix@yahoo.com.cn
 * 
*/

#ifndef ZCanvas_H
#define ZCanvas_H

#include <qbitmap.h>
#include <qwidget.h>
#include <qscrollview.h>
#include <qlist.h>
#include <qptrdict.h>

class ZCanvasSprite;
class ZCanvasPolygonalItem;
class ZCanvasRectangle;
class ZCanvasPolygon;
class ZCanvasEllipse;
class ZCanvasText;
class ZCanvasLine;
class ZCanvasChunk;
class ZCanvas;
class ZCanvasData;
class ZCanvasItem;
class ZCanvasView;
class ZCanvasPixmap;


#if defined(Q_TEMPLATEDLL)
// MOC_SKIP_BEGIN
template class Q_EXPORT QList< ZCanvasItem >;
template class Q_EXPORT QList< ZCanvasView >;
template class Q_EXPORT QValueList< ZCanvasItem* >;
// MOC_SKIP_END
#endif


class ZCanvasItemList : public QValueList<ZCanvasItem*> {
public:
    void sort();
    void drawUnique( QPainter& painter );
};


class ZCanvasItemExtra;

class Q_EXPORT ZCanvasItem : public Qt
{
public:
    ZCanvasItem(ZCanvas* canvas);
    virtual ~ZCanvasItem();

    double x() const
	{ return myx; }
    double y() const
	{ return myy; }
    double z() const
	{ return myz; } // (depth)

    virtual void moveBy(double dx, double dy);
    void move(double x, double y);
    void setX(double a) { move(a,y()); }
    void setY(double a) { move(x(),a); }
    void setZ(double a) { myz=a; changeChunks(); }

    bool animated() const;
    virtual void setAnimated(bool y);
    virtual void setVelocity( double vx, double vy);
    void setXVelocity( double vx ) { setVelocity(vx,yVelocity()); }
    void setYVelocity( double vy ) { setVelocity(xVelocity(),vy); }
    double xVelocity() const;
    double yVelocity() const;
    virtual void advance(int stage);

    virtual bool collidesWith( const ZCanvasItem* ) const=0;

    ZCanvasItemList collisions(bool exact /* NO DEFAULT */ ) const;

    virtual void setCanvas(ZCanvas*);

    virtual void draw(QPainter&)=0;

    void show();
    void hide();

    virtual void setVisible(bool yes);
    bool visible() const
	{ return (bool)vis; }
    virtual void setSelected(bool yes);
    bool selected() const
	{ return (bool)sel; }
    virtual void setEnabled(bool yes);
    bool enabled() const
	{ return (bool)ena; }
    virtual void setActive(bool yes);
    bool active() const
	{ return (bool)act; }

    virtual int rtti() const;

    virtual QRect boundingRect() const=0;
    virtual QRect boundingRectAdvanced() const;

    ZCanvas* canvas() const
	{ return cnv; }

private:
    // For friendly sublasses...

    friend class ZCanvasPolygonalItem;
    friend class ZCanvasSprite;
    friend class ZCanvasRectangle;
    friend class ZCanvasPolygon;
    friend class ZCanvasEllipse;
    friend class ZCanvasText;
    friend class ZCanvasLine;

    virtual QPointArray chunks() const;
    virtual void addToChunks();
    virtual void removeFromChunks();
    virtual void changeChunks();
    virtual bool collidesWith(   const ZCanvasSprite*,
				 const ZCanvasPolygonalItem*,
				 const ZCanvasRectangle*,
				 const ZCanvasEllipse*,
				 const ZCanvasText* ) const=0;
    // End of friend stuff

    ZCanvas* cnv;//R1->0x04
    static ZCanvas* current_canvas;
    double myx,myy,myz;//0x08,0x10,0x18
    ZCanvasItemExtra *ext;//0x20
    ZCanvasItemExtra& extra();
    uint ani:1;//0x24
    uint vis:1;
    uint sel:1;
    uint ena:1;
    uint act:1;
};


class Q_EXPORT ZCanvas : public QObject
{
    Q_OBJECT
public:
    ZCanvas( QObject* parent = 0, const char* name = 0 );
    ZCanvas(int w, int h);
    ZCanvas( QPixmap p, int h, int v, int tilewidth, int tileheight );

    virtual ~ZCanvas();

    virtual void setTiles( QPixmap tiles, int h, int v,
			   int tilewidth, int tileheight );
    virtual void setBackgroundPixmap( const QPixmap& p );
    QPixmap backgroundPixmap() const;

    virtual void setBackgroundColor( const QColor& c );
    QColor backgroundColor() const;

    virtual void setTile( int x, int y, int tilenum );
    int tile( int x, int y ) const
	{ return grid[x+y*htiles]; }

    int tilesHorizontally() const
	{ return htiles; }
    int tilesVertically() const
	{ return vtiles; }

    int tileWidth() const
	{ return tilew; }
    int tileHeight() const
	{ return tileh; }

    virtual void resize(int width, int height);
    int width() const
	{ return awidth; }
    int height() const
	{ return aheight; }
    QSize size() const
	{ return QSize(awidth,aheight); }
    bool onCanvas( int x, int y ) const
	{ return x>=0 && y>=0 && x<awidth && y<aheight; }
    bool onCanvas( const QPoint& p ) const
	{ return onCanvas(p.x(),p.y()); }
    bool validChunk( int x, int y ) const
	{ return x>=0 && y>=0 && x<chwidth && y<chheight; }
    bool validChunk( const QPoint& p ) const
	{ return validChunk(p.x(),p.y()); }

    int chunkSize() const
	{ return chunksize; }
    virtual void retune(int chunksize, int maxclusters=100);

    bool sameChunk(int x1, int y1, int x2, int y2) const
	{ return x1/chunksize==x2/chunksize && y1/chunksize==y2/chunksize; }
    virtual void setChangedChunk(int i, int j);
    virtual void setChangedChunkContaining(int x, int y);
    virtual void setAllChanged();
    virtual void setChanged(const QRect& inarea);

    // These call setChangedChunk.
    void addItemToChunk(ZCanvasItem*, int i, int j);
    void removeItemFromChunk(ZCanvasItem*, int i, int j);
    void addItemToChunkContaining(ZCanvasItem*, int x, int y);
    void removeItemFromChunkContaining(ZCanvasItem*, int x, int y);

    ZCanvasItemList allItems();
    ZCanvasItemList collisions( const QPoint&) const;
    ZCanvasItemList collisions( const QRect&) const;
    ZCanvasItemList collisions( const QPointArray& pa, const ZCanvasItem* item,
				bool exact) const;

    // These are for ZCanvasView to call
    virtual void addView(ZCanvasView*);
    virtual void removeView(ZCanvasView*);
    void drawArea(const QRect&, QPainter* p=0, bool double_buffer=TRUE);

    // These are for ZCanvasItem to call
    virtual void addItem(ZCanvasItem*);
    virtual void addAnimation(ZCanvasItem*);
    virtual void removeItem(ZCanvasItem*);
    virtual void removeAnimation(ZCanvasItem*);

    virtual void setAdvancePeriod(int ms);
    virtual void setUpdatePeriod(int ms);

    virtual void setDoubleBuffering(bool y);

signals:
    void resized();

public slots:
    virtual void advance();
    virtual void update();

protected:
    virtual void drawBackground(QPainter&, const QRect& area);
    virtual void drawForeground(QPainter&, const QRect& area);

private:
    void init(int w, int h, int chunksze=16, int maxclust=100);

    ZCanvasChunk& chunk(int i, int j) const;
    ZCanvasChunk& chunkContaining(int x, int y) const;

    void drawChanges(const QRect& inarea);

    QPixmap offscr;//0x24 **
    int tmp0;//0x28
    int awidth,aheight;//0x3C,0x40 **
    int chunksize;//0x44  **
    int maxclusters;//0x48 **
    int chwidth,chheight;//0x4C,0x50 **
    ZCanvasChunk* chunks;//0x54 **
    ZCanvasData* d;//0x58  **
    ushort *grid;//0x5C **
    ushort htiles;//0x60  **
    ushort vtiles;//0x62  **
    ushort tilew;//0x64 **
    ushort tileh;//0x66 **
    int tmp1;
    QPixmap pm;//0x6C **
    int tmp2[3];//0x70,0x74,0x78 ???
    QPixmap pm2;//0x7C **
    int tmp3;//0x80
    QTimer* update_timer;//0x84 **
    QColor bgcolor;//0x88 **
    int tmp4[2];
    //void initTiles(QPixmap p, int h, int v, int tilewidth, int tileheight);
    //bool oneone;
    bool debug_redraw_areas;//0x94 **
    bool dblbuf;//0x95 **
    friend void qt_unview(ZCanvas* c);
};

class Q_EXPORT ZCanvasView : public QScrollView
{
    Q_OBJECT
public:
    ZCanvasView(ZCanvas* viewing=0, QWidget* parent=0, const char* name=0, WFlags f=0);
    ~ZCanvasView();

    ZCanvas* canvas() const
	{ return viewing; }
    void setCanvas(ZCanvas* v);

protected:
    void drawContents( QPainter*, int cx, int cy, int cw, int ch );
    QSize sizeHint() const;

private:
    ZCanvas* viewing;//0xD4 = 0
    friend void qt_unview(ZCanvas* c);

private slots:
    void cMoving(int,int);
    void updateContentsSize();
};


class Q_EXPORT ZCanvasPixmap : public QPixmap
{
public:
    ZCanvasPixmap(const QString& datafilename);
    ZCanvasPixmap(const QImage& image);
    ZCanvasPixmap(const QPixmap&, QPoint hotspot);
    ~ZCanvasPixmap();

    int offsetX() const
	{ return hotx; }
    int offsetY() const
	{ return hoty; }
    void setOffset(int x, int y) { hotx = x; hoty = y; }

private:
    void init(const QImage&);
    void init(const QPixmap& pixmap, int hx, int hy);

    friend class ZCanvasSprite;
    friend class ZCanvasPixmapArray;
    friend bool qt_testCollision(const ZCanvasSprite* s1, const ZCanvasSprite* s2);

    int hotx,hoty;//0x18,0x1C

    QImage* collision_mask;//0x20
};


class Q_EXPORT ZCanvasPixmapArray
{
public:
    ZCanvasPixmapArray();
    ZCanvasPixmapArray(const QString& datafilenamepattern, int framecount=0);
    ZCanvasPixmapArray(QList<QPixmap>, QList<QPoint> hotspots);
    ~ZCanvasPixmapArray();

    bool readPixmaps(const QString& datafilenamepattern, int framecount=0);
    bool readCollisionMasks(const QString& filenamepattern);

    int operator!(); // Failure check.

    ZCanvasPixmap* image(int i) const
	{ return img[i]; }
    void setImage(int i, ZCanvasPixmap* p);
    uint count() const
	{ return (uint)framecount; }

private:
    bool readPixmaps(const QString& datafilenamepattern, int framecount, bool maskonly);

    void reset();
    int framecount;
    ZCanvasPixmap** img;
};


class Q_EXPORT ZCanvasSprite : public ZCanvasItem
{
public:
    ZCanvasSprite(ZCanvasPixmapArray* array, ZCanvas* canvas);

    void setSequence(ZCanvasPixmapArray* seq);

    virtual ~ZCanvasSprite();

    void move(double x, double y);
    virtual void move(double x, double y, int frame);
    void setFrame(int);
    int frame() const
	{ return frm; }
    int frameCount() const
	{ return images->count(); }

    virtual int rtti() const;

    bool collidesWith( const ZCanvasItem* ) const;

    QRect boundingRect() const;

protected:
    void draw(QPainter& painter);

    int width() const;
    int height() const;

    int absX() const;
    int absY() const;
    int absX2() const;
    int absY2() const;

    int absX(int nx) const;
    int absY(int ny) const;
    int absX2(int nx) const;
    int absY2(int ny) const;
    ZCanvasPixmap* image() const
	{ return images->image(frm); }
    virtual ZCanvasPixmap* imageAdvanced() const;
    ZCanvasPixmap* image(int f) const
	{ return images->image(f); }

private:
    void addToChunks();
    void removeFromChunks();
    void changeChunks();

    int frm;
    bool collidesWith( const ZCanvasSprite*,
		       const ZCanvasPolygonalItem*,
		       const ZCanvasRectangle*,
		       const ZCanvasEllipse*,
		       const ZCanvasText* ) const;

    friend bool qt_testCollision( const ZCanvasSprite* s1, 
				  const ZCanvasSprite* s2 );

    ZCanvasPixmapArray* images;
};

class QPolygonalProcessor;

class Q_EXPORT ZCanvasPolygonalItem : public ZCanvasItem
{
public:
    ZCanvasPolygonalItem(ZCanvas* canvas);
    virtual ~ZCanvasPolygonalItem();

    bool collidesWith( const ZCanvasItem* ) const;

    virtual void setPen(QPen p);
    virtual void setBrush(QBrush b);

    QPen pen() const
	{ return pn; }
    QBrush brush() const
	{ return br; }

    virtual QPointArray areaPoints() const=0;
    virtual QPointArray areaPointsAdvanced() const;
    QRect boundingRect() const;

    int rtti() const;

protected:
    void draw(QPainter &);
    virtual void drawShape(QPainter &) = 0;

    bool winding() const;
    void setWinding(bool);

private:
    void scanPolygon( const QPointArray& pa, int winding,
		      QPolygonalProcessor& process ) const;
    QPointArray chunks() const;

    bool collidesWith( const ZCanvasSprite*,
		       const ZCanvasPolygonalItem*,
		       const ZCanvasRectangle*,
		       const ZCanvasEllipse*,
		       const ZCanvasText* ) const;

    QBrush br;
    QPen pn;
    uint wind:1;
};


class Q_EXPORT ZCanvasRectangle : public ZCanvasPolygonalItem
{
public:
    ZCanvasRectangle(ZCanvas* canvas);
    ZCanvasRectangle(const QRect&, ZCanvas* canvas);
    ZCanvasRectangle(int x, int y, int width, int height, ZCanvas* canvas);

    ~ZCanvasRectangle();

    int width() const;
    int height() const;
    void setSize(int w, int h);
    QSize size() const
	{ return QSize(w,h); }
    QPointArray areaPoints() const;
    QRect rect() const
	{ return QRect(int(x()),int(y()),w,h); }

    bool collidesWith( const ZCanvasItem* ) const;

    int rtti() const;

protected:
    void drawShape(QPainter &);
    QPointArray chunks() const;

private:
    bool collidesWith(   const ZCanvasSprite*,
			 const ZCanvasPolygonalItem*,
			 const ZCanvasRectangle*,
			 const ZCanvasEllipse*,
			 const ZCanvasText* ) const;

    int w, h;
};


class Q_EXPORT ZCanvasPolygon : public ZCanvasPolygonalItem
{
public:
    ZCanvasPolygon(ZCanvas* canvas);
    ~ZCanvasPolygon();
    void setPoints(QPointArray);
    QPointArray points() const;
    void moveBy(double dx, double dy);

    QPointArray areaPoints() const;
    int rtti() const;

protected:
    void drawShape(QPainter &);
    QPointArray poly;
};


class Q_EXPORT ZCanvasLine : public ZCanvasPolygonalItem
{
public:
    ZCanvasLine(ZCanvas* canvas);
    ~ZCanvasLine();
    void setPoints(int x1, int y1, int x2, int y2);

    QPoint startPoint() const
	{ return QPoint(x1,y1); }
    QPoint endPoint() const
	{ return QPoint(x2,y2); }

    int rtti() const;

    void setPen(QPen p);

protected:
    void drawShape(QPainter &);
    QPointArray areaPoints() const;

private:
    int x1,y1,x2,y2;
};

//functions ok
class Q_EXPORT ZCanvasEllipse : public ZCanvasPolygonalItem
{

public:
    ZCanvasEllipse( ZCanvas* canvas );
    ZCanvasEllipse( int width, int height, ZCanvas* canvas );
    ZCanvasEllipse( int width, int height, int startangle, int angle,
		    ZCanvas* canvas );

    ~ZCanvasEllipse();

    int width() const;
    int height() const;
    void setSize(int w, int h);
    void setAngles(int start, int length);
    int angleStart() const
	{ return a1; }
    int angleLength() const
	{ return a2; }
    QPointArray areaPoints() const;

    bool collidesWith( const ZCanvasItem* ) const;

    int rtti() const;

protected:
    void drawShape(QPainter &);

private:
    bool collidesWith( const ZCanvasSprite*,
		       const ZCanvasPolygonalItem*,
		       const ZCanvasRectangle*,
		       const ZCanvasEllipse*,
		       const ZCanvasText* ) const;
    int w, h;
    int a1, a2;
};


class ZCanvasTextExtra;

class Q_EXPORT ZCanvasText : public ZCanvasItem
{
public:
    ZCanvasText(ZCanvas* canvas);
    ZCanvasText(const QString&, ZCanvas* canvas);
    ZCanvasText(const QString&, QFont, ZCanvas* canvas);

    virtual ~ZCanvasText();

    void setText( const QString& );
    void setFont( const QFont& );
    void setColor( const QColor& );
    QString text() const;
    QFont font() const;
    QColor color() const;

    void moveBy(double dx, double dy);

    int textFlags() const
	{ return flags; }
    void setTextFlags(int);

    QRect boundingRect() const;

    bool collidesWith( const ZCanvasItem* ) const;

    virtual int rtti() const;

protected:
    virtual void draw(QPainter&);

private:
    void addToChunks();
    void removeFromChunks();
    void changeChunks();

    void setRect();
    QRect brect;
    QString txt;
    int flags;
    QFont fnt;
    QColor col;
    ZCanvasTextExtra* extra;

    bool collidesWith(   const ZCanvasSprite*,
			 const ZCanvasPolygonalItem*,
			 const ZCanvasRectangle*,
			 const ZCanvasEllipse*,
			 const ZCanvasText* ) const;
};


#endif // ZCanvas_H
