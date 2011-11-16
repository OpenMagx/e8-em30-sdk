//Fix for compobility by Ant-ON, 15-06-2010


// Copyright (c) 07-Dec-2004 - 2008 Motorola, Inc. All rights reserved.

#ifndef Z_MULTILINE_H
#define Z_MULTILINE_H

#ifndef __cplusplus
#error "This is a C++ header file;it requires C++ to compile."
#endif

//--------------------------------------------------------------------------------------------------
//                                       INCLUDE FILES
//--------------------------------------------------------------------------------------------------
#ifndef QT_H
#include "qtableview.h"
#include "qstring.h"
#include "qlist.h"
#include "qregexp.h"
#endif // QT_H
#include "ZTableView.h"
#ifndef QT_NO_WTLE
#include "tslayout.h"

#define isOdd(x) (x % 2)
#define isEven(x) (!(x % 2))
#endif

#define InsertionMethodType InsertionMethod

//--------------------------------------------------------------------------------------------------
//                                    FORWARD DECLARATIONS
//--------------------------------------------------------------------------------------------------
struct ZMultiLineData;
class ZMultiLineEditCommand;
class QValidator;
struct  ZKbInputField;
class ZSkinBase;

#define FEAT_UISTYLE_CHAMELEON
            
//--------------------------------------------------------------------------------------------------
//                                   CLASS DEFINITIONS
//--------------------------------------------------------------------------------------------------
class Q_EXPORT ZMultiLineEdit : public ZTableView
{
    Q_OBJECT

public:
//--------------------------------------------------------------------------------------------------
//                                         ENUMS
//--------------------------------------------------------------------------------------------------
#ifndef QT_NO_MOT_CURSOR_FLAG

   enum CursorFlagExist 
   {
	CF_NONE,
	CF_YES
    };

    enum CursorFlagDirection 
    {
	CF_RTL,
	CF_LTR
    };

    enum InputContext 
    {
        IC_NONE,
        IC_SCROLLING,
        IC_TEXT_INPUT
    };

    enum InitAutoAlign
    {
	AlignmentLeft,   //initial alignment left 
	AlignmentRight   //initial alignment right
    };
    
#endif

    enum EchoMode 
    { 
       Normal, 
       NoEcho, 
       Password 
    };

     enum InsertionMethodType
     {
        INSERTION_METHOD_BEGIN,     ///< Begin,     indicates that text should begin at the first position
        INSERTION_METHOD_END,       ///< End,       indicates that text should begin at the current last position 
        INSERTION_METHOD_SELECTION,  ///< Selection, indicates that text should overwrite contents.  
        atPosNoSelected //Added by Ant-ON
     };

    enum WordWrap 
    {
        NoWrap,   
        WidgetWidth,
        FixedPixelWidth,
        FixedColumnWidth
    };
    
    enum WrapPolicy 
    {
        AtWhiteSpace,   
        Anywhere  
    };

    enum TitlePosition 
    { 
    	Unknown = 0, 
    	TitleTop, 
    	TitleLeft 
    };

    ZMultiLineEdit( QWidget* parent=0, const char* name=0);
    ZMultiLineEdit( QWidget* parent,bool EZXStyle,int lines = 1,const char* name=0 );
    virtual ~ZMultiLineEdit();
    void setIndent( int idt );
    int getIndent();
    int getLineHeight() const;
    void setUnderline( bool needUnderline = true );
    bool getUnderline();
    void setFilter( const QRegExp& filter, bool match = false );
    const QRegExp& getFilter() const;
    QString textLine( int line ) const;
    int numLines() const;
    QSize sizeHint() const;
    QSize minimumSizeHint() const;
    QSizePolicy sizePolicy() const;
    virtual void setFont( const QFont &font );
    void setInitAutoAlign(InitAutoAlign align);
    void setCursorFlagExist(CursorFlagExist d);
    virtual void insertLine( const QString &s, int line = -1 );
    virtual void insertAt( const QString &s, int line, int col, bool mark = FALSE );
    virtual void removeLine( int line );

#ifndef QT_NO_MOT_CURSOR_FLAG
    void setCursorFlagDirection(CursorFlagDirection d);
#endif
    void cursorPosition( int* line, int* col ) const;
    virtual void setCursorPosition( int line, int col, bool mark = FALSE );
    void getCursorPosition( int* line, int* col ) const;
    bool atBeginning() const;
    bool atEnd() const;
    virtual void setFixedVisibleLines( int ln );
    int maxLineWidth() const;
    void setAlignment( int flags );
    int alignment() const;
    virtual void setValidator( const QValidator * );
    const QValidator* validator() const;
    void setEdited( bool );
    bool edited() const;
    void cursorWordForward( bool mark );
    void cursorWordBackward( bool mark );
    virtual void setInsertionMethod( InsertionMethod nSelection );
    virtual void setEchoMode( EchoMode );
    EchoMode echoMode() const;
    void setMaxLength( int m );
    virtual void setFontPercent(float rate);
    int maxLength() const;
    virtual void setMaxLineLength( int m );
    int maxLineLength() const;
    virtual void setMaxLines( int m );
    int maxLines() const;
    virtual void setHMargin( int m );
    int hMargin() const;
    virtual void setSelection( int row_from, int col_from, int row_to, int col_to );
    void setWordWrap( WordWrap mode );
    WordWrap wordWrap() const;
    void setWrapColumnOrWidth( int value );
    int wrapColumnOrWidth() const;
    void setWrapPolicy( WrapPolicy policy );
    WrapPolicy wrapPolicy() const;
    bool autoUpdate()   const;
    virtual void setAutoUpdate( bool enable );
    void setUndoEnabled( bool enable );
    bool isUndoEnabled() const;
    void setUndoDepth( int depth );
    int undoDepth() const;
    bool isReadOnly() const;
    bool isOverwriteMode() const;
    QString text() const;
    QString textWithPredict() const;
    QString phonenoText() const;
    int length() const;
    static void setDefaultTabStop( int ex );
    static int defaultTabStop();
    virtual void show();
    void setTitlePosition(TitlePosition titlePos);
    QString title() const; 
    void setTitle(const QString & titleStr);
    void setTruncateInfo(int nStyle = 0, const QString & strReplace = QString::null);
    void setAutoFixedHeight(bool enable);
    virtual void  resetFocusItem(bool);
    virtual QRect getCurrentFocusRect();
    virtual bool  hasNextPrevFocusItem(bool);
    void setNestScrollPanelMode(bool nest);
    bool nestScrollPanelMode() const;
    void setMoveFocusOutRange(bool b);
    bool focusOutRange() const;
    void setAutoExpandInNestMode(bool expand);
    bool autoExpandInNestMode() const;


#ifndef QT_NO_WORDCOMPLETE
    void cursorPosBeforeInsert(int currentX,int currentY,int insertLength,int* previousX,int* previousY);
    void setWordComplete(bool wc);
#endif

#ifndef QT_NO_GET_CONTEXT
    QString getRowString(int i);
#endif

#if defined(QT_NO_PUBLIC_INTERFACE) && defined(QT_NO_WORDCOMPLETE)
#else
    void emitTextChanged();
#endif

#ifndef QT_NO_PUBLIC_INTERFACE
    QPoint calCursorPos( QPoint startPos , int len );
    int getLineCount();
    QString getLineContent( int line );
    ZKbInputField*  getInputField();
    void insertString_if( QPoint pos, QString text ); 
#endif
    int  heightViewed() const;
    bool isValidChar( const QChar& ch );
    
#ifndef QT_NO_WTLE
    void specialInputModeCursorModel(bool);
#endif //end QT_NO_WTLE
    void setInputModeCursorModel(int);
    int getInputModeCursorModel(void);
    void updateCursorModel(void);
    void backspaceNew(void);
    void insertAtNew( const QString &, int, int, bool);
    bool  isLTRBidiClass(TsBidiCharClass);
    bool  isRTLBidiClass(TsBidiCharClass);
    bool isNumericBidiClass(TsBidiCharClass);
    bool  isNeutralBidiClass(TsBidiCharClass); 

public slots:
    virtual void changeContentSize( int lines,QPoint cursorPos );
    virtual void setText( const QString &s );
    virtual void setReadOnly( bool on );
    virtual void setZEnabled(bool enable);
    bool isZEnabled();
    bool isZDisabled();
    virtual void setOverwriteMode( bool on );
    void      clear();
    void append( const QString &s );
    void       deselect();
    void       selectAll();
    void  smartPunctuation(); 
    
#ifndef QT_NO_CLIPBOARD
    void       paste();
    void       pasteSubType(const QCString& subtype);
    void       copyText() const;
    void       copy() const;
    void       cut();
    void       deleteText();
#endif
    void insert( const QString& s );
    void       undo();
    void       redo();

signals:
    void    clicked();
    void    textTrancated();
    void    textChanged();
    void    returnPressed();
    void undoAvailable( bool yes );
    void redoAvailable( bool yes );
    void    copyAvailable( bool );
    void  cursorChanged(int cursorX, int cursorY);

#ifndef QT_NO_GET_CONTEXT 
    void  bufferUpdate(int cursorX, int cursorY); 
    void  contentChanged();
#endif
    void    changeSizeHint( QWidget* widget,QSize size,QPoint cusrorPos,int larger );
    void    linesChanged( int lines,QPoint cursorPos );
    void    rightSmartPuncOccurred(void);
    void sigCursorUpDown(bool down);

#ifdef FEAT_UISTYLE_CHAMELEON
    void contentsResizing(ZMultiLineEdit* , int width, int height);
#endif
    
protected:
    void    updateMask();
#ifndef QT_NO_WTLE
    void    pixelPosToCursorPos(QPoint p, int* x, int* y);
#else
    void    pixelPosToCursorPos(QPoint p, int* x, int* y) const;
#endif
    void    setCursorPixelPosition(QPoint p, bool clear_mark = true);

public: // Added 15-06-2010
    void    paintEvent(QPaintEvent* );
    
protected:

#ifndef QT_NO_PUBLIC_INTERFACE
	int paintCell_if( QPainter* p , int row , int underlineI , bool underlineHit , int reverseI ,\
                      bool reverseHit , int yPos , int x , QString s , QFontMetrics fm , QRect updateR , QColorGroup g );
#endif
    void    paintCell( QPainter *, int row, int col, int xPos, int yPos );
    virtual void drawLineText( QPainter* painter, int x, int y, int width,
                               int height, int flags, const QString& lineStr, int row = 0 , int col = 0);
    virtual void drawTableFrame(QPainter*  p, QRect & updateR);
    bool event( QEvent * );
    void    mousePressEvent( QMouseEvent * );
    void    mouseMoveEvent( QMouseEvent * );
    void    mouseReleaseEvent( QMouseEvent * );
    void    mouseDoubleClickEvent( QMouseEvent * );
    void    wheelEvent( QWheelEvent * );

public: //Added 15-06-2010
    void    keyPressEvent( QKeyEvent * );

protected:
    void keyReleaseEvent(QKeyEvent * );
    void    focusInEvent( QFocusEvent * );
    void    focusOutEvent( QFocusEvent * );
    void    timerEvent( QTimerEvent * );
    void    leaveEvent( QEvent * );
    void    resizeEvent( QResizeEvent * );
    bool    focusNextPrevChild( bool );
    bool    hasMarkedText() const;
    QString markedText() const;
    
#ifndef QT_NO_WTLE
    int	    textWidthWithTabs( int lineNo );
    int	    textWidth( int lineNo = -1 );
#else
    int     textWidth( int );
    int textWidth( const QString &s);
#endif

public: //Added 15-06-2010
#ifndef QT_NO_WTLE
    QPoint  cursorPoint();
#else
    QPoint  cursorPoint() const;
#endif

protected:
#ifndef QT_NO_WTLE
    QPoint  cursorPointViewed();
#else
    QPoint  cursorPointViewed() const;
#endif
    virtual void insert( const QString& c, bool mark );
    virtual void newLine();
    virtual void killLine();

public: //Added 15-06-2010
    virtual void pageUp( bool mark=FALSE );
    virtual void pageDown( bool mark=FALSE );
    virtual void cursorLeft( bool mark=FALSE, bool wrap = TRUE );
    virtual void cursorRight( bool mark=FALSE, bool wrap = TRUE );
    virtual void cursorUp( bool mark=FALSE );
    virtual void cursorDown( bool mark=FALSE );

protected:

#ifdef FEAT_UISTYLE_CHAMELEON
    virtual void cursorMove(bool down);
    void linesChangedNoExp(int lines);
    int firstNoVisibleLines(int curLines, const QRect & rt, bool down);
#endif
    virtual void backspace();
    virtual void del();
    virtual void home( bool mark=FALSE );
    virtual void end( bool mark=FALSE );
    bool getMarkedRegion( int* line1, int* col1,
                          int* line2, int* col2 ) const;
    int lineLength( int row ) const;
    QString* getString( int row ) const;
    bool isEndOfParagraph( int row ) const;
    QString stringShown( int row ) const;
    virtual void setPalette(const QPalette &);
    void insertChar( QChar c );
    int  positionToOffsetInternal( int row, int col ) const;
    void  offsetToPositionInternal( int position, int* row, int* col ) const;
    void  clearUndoList();
    bool  partiallyInvisible( int row );
    int   getTruncateCount();   
    bool  cursorOn;

private slots:
    void    clipboardChanged();
    void    blinkTimerTimeout(); 
    void    scrollTimerTimeout();
    void    dndTimeout();
    void    fastDelTimerTimeout();

#ifndef QT_NO_GET_CONTEXT
    void    bufferUpdate(); 
#endif

private:
    enum LineType
    {
        Empty_Line = 0,
        Color_Line,
        Pixmap_Line
    };

    enum TextType
    {
        Title = 0,
        Field
    };
 
#ifndef QT_NO_WTLE
    enum eParaAlignment
    {
    	DIR_UNKNOWN,
    	LTR,
    	RTL
    };
#endif
    struct ZMultiLineEditRow 
    {
        ZMultiLineEditRow( QString string, int width, bool nl = TRUE, bool old = FALSE, eParaAlignment dir = DIR_UNKNOWN )
            :s(string), w(width), newline( nl ), overrideLineDirection( old ), direction( dir ) 
            {
            };
        QString s;
        int w;
        bool newline;
        bool overrideLineDirection;
        eParaAlignment direction;
    };

    void init( QWidget* parent,bool style,int lines,const char* name );
    void filterString( QString& filtered,const QString& s );
    void autoSendScrollRequest( int lines,const QPoint& curPos );
    void setTitlePositionAux(const QString& /*oldTitle*/, int from);
    QString addReplacedStr(const QString & strSource, int row);
    QRect getFormItemTopArea();
    QRect getFormItemLeftArea();
    QRect getFormItemRightArea();
    QRect getFormItemBottomArea();
    QRect getMDTopArea();
    QRect getMDBottomArea();
    QRect getMDLeftArea();
    QRect getMDRightArea();
    QRect getEditArea();
    QRect  getFieldRect();
    void drawOtherArea(QPainter* p, const QRect & validrc, const QRect & paintArea, ZSkinBase* pSkinBase);
    void drawMultiArea(QPainter* p, const QRect & validrc, const QRect & paintArea, ZSkinBase* pSkinBase);
    QSize updateTextLayout();
    int getContentsWidth();
    void   pasteSpecial(const QPoint&);
    int     mapFromView( int xPos, int row );
    int     mapToView( int xIndex, int row );
    void    setWidth( int );
    void    updateCellWidth();
    void    makeVisible(bool isDown);
    void    setBottomCell( int row );
    void    newMark( int posx, int posy, bool copy=TRUE );
    void    markWord( int posx, int posy );
    void    extendSelectionWord( int &newX, int&newY);
    int     charClass( QChar );
    void    turnMark( bool on );
    bool    inMark( int posx, int posy ) const;
    bool    beforeMark( int posx, int posy ) const;
    bool    afterMark( int posx, int posy ) const;
    int     setNumRowsAndTruncate();
    int     getOffset(int row);
    void    startAutoScroll();
    void    stopAutoScroll();

public: //Added 15-06-2010
    void    cursorLeft( bool mark, bool clear_mark, bool wrap );
    void    cursorRight( bool mark, bool clear_mark, bool wrap );
    void    cursorUp( bool mark, bool clear_mark );
    void    cursorDown( bool mark, bool clear_mark );

private:
    void    wrapLine( int line, int removed = 0);
    void    wtleWrapLine( int line, int& w, int& nlines);
    void    qtWrapLine( int line, int&w, int& nlines );
    void    rebreakParagraph( int line, int removed = 0 );
    void    rebreakAll();
    void    insertAtAux( const QString &s, int line, int col, bool mark = FALSE );
    void    killLineAux();
    void    delAux();
    void    deleteNextChar( int offset, int row, int col );
    void    deleteWord();
    void    addUndoCmd( ZMultiLineEditCommand* );
    void    addRedoCmd( ZMultiLineEditCommand* );
    void    processCmd( ZMultiLineEditCommand*, bool );
    int getHeight() const;
    int getWidth() const;
    QSize getTitleSize() const;
    void getFrameWidth(int & nleft, int & nright, int & ntop, int & nbottom);
    void getMDFrameWidth(int & nleft, int & nright, int & ntop, int & nbottom);
    void getSkinFont(QFont & font, QColor & color, TextType type) const;
    void updateSkin(bool redraw);
    LineType  lineType(const SelectionState state);
    void lineColor(const SelectionState state, QColor & color);
    QPixmap* getPixmap(const SelectionState state);
    int lineHeight();
    QPixmap loadLinePixmap(const SelectionState state);
    void getLinePixSuffixName(const SelectionState state, QString & suffix);
    LineType changeToLineType(int lineTpye);
    void setViewMarginsEx();
    void drawUnderLine(QPainter* p, int xBase, int yBase, int wDelta);
    void stretchPixmap( QPixmap& pm, int width, int height, PIXMAP_STRETCH_POLICY_E type);
    void setStateFont(bool bChangeState = TRUE);
    int getCursorOffset(int cursorRow, int cursorCol);

public: //Added 15-06-2010    
    void getCorsorPosition(int & cursorRow, int & cursorCol, int cursorOffset);

private:
    int getCursorState();
    bool isTextEmpty() const;

#ifndef QT_NO_MIME
    QCString pickSpecial( QMimeSource* ms, bool always_ask, const QPoint& );
#endif
    
#ifndef QT_NO_WTLE

    void autoAlignment(TsLayout* layout, TsLayoutInfo &layoutInfo);
    int getParaAlignment(void);
    void invalidateTsLayout(int lineNo, bool andFollowing = FALSE);
    int prepareTsLayout(int lineNo);
    int cursorToLayoutIndex(int relLine);
    void layoutIndexToCursor(int index);
    QRegion prepareTsMarkRegion(int markLow, int markHigh, int offset, int row, int x, int y, int txtH, const QString & s);
    QRegion glyphRegion(const TsGlyphInfo & glinfo, int offset, int x, int y, int charBearing);
    int	    xPosToCursorPos( int lineNo, int xPos );
    bool  isLTRM(TsBidiCharClass);
    bool  isSpaceNeutral(TsBidiCharClass);
    void updateCursorFlagAfterBackspace(void);
    void RTLWorkAround(int removed);
    void stripMarks(int line);
    void overrideLineDirection(int line, eParaAlignment dir, int removed);
#endif

    void handleOmgEvent(int key, int step);


#if defined(Q_DISABLE_COPY)
    ZMultiLineEdit( const ZMultiLineEdit & );
    ZMultiLineEdit &operator=( const ZMultiLineEdit & );
#endif

    void scrollN(QKeyEvent* e);

    QList<ZMultiLineEditRow>*  contents;
    ZMultiLineData*   d;

    int     indent;
    QSize   hint;
    bool    ezx_style;
    int     lines;
    int     minLines;
    bool    underline;
    
    bool    readOnly;
    bool    dummy;
    bool    markIsOn;
    bool    dragScrolling ;
    bool    dragMarking;
    bool    textDirty;
    bool    wordMark;
    bool    overWrite;
    bool    isCursorOn;
       
    int     cursorX;
    int     cursorY;
    int     markAnchorX;
    int     markAnchorY;
    int     markDragX;
    int     markDragY;
    int     curXPos;    
    int     blinkTimer; 
    int     scrollTimer;

#ifndef QT_NO_MOT_CURSOR_FLA    
    InitAutoAlign initAlign;
    CursorFlagExist cursFlag;
    CursorFlagDirection cursFlagDirection;
    InputContext inputContext;
#endif    

};
#endif







