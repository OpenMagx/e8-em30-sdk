// Copyright (c) 07-Dec-2004 - 2008 Motorola, Inc. All rights reserved.

#ifndef Z_MULTILINE_H
#define Z_MULTILINE_H

#ifndef __cplusplus
#error "This is a C++ header file;it requires C++ to compile."
#endif

///
/// \file ZMultiLineEdit.h
/// \brief EZX MultiLineEdit widget
///
///  Definition of ZMultiLineEdit class
///
///  Created : 950126
///
///  Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
///
///  This file is part of the tools module of the Qt GUI Toolkit.
///
///  This file may be distributed under the terms of the Q Public License
///  as defined by Trolltech AS of Norway and appearing in the file
///  LICENSE.QPL included in the packaging of this file.
///
///  This file may be distributed and/or modified under the terms of the
///  GNU General Public License version 2 as published by the Free Software
///  Foundation and appearing in the file LICENSE.GPL included in the
///  packaging of this file.
///
///  Licensees holding valid Qt Enterprise Edition or Qt Professional Edition
///  licenses may use this file in accordance with the Qt Commercial License
///  Agreement provided with the Software.
///
///  This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
///  WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
///
///  See http://www.trolltech.com/pricing.html or email sales@trolltech.com for
///    information about Qt Commercial License Agreements.
///  See http://www.trolltech.com/qpl/ for QPL licensing information.
///  See http://www.trolltech.com/gpl/ for GPL licensing information.
///
///  Contact info@trolltech.com if any conditions of this licensing are
///  not clear to you.
///
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
///
/// \class ZMultiLineEdit
///
/// \brief the ZMainWidget class implements the EZX style's MultiLineEdit,
/// for example:<pre>
/// 1. support indent 
/// 2. support resize automatically(work with ZScrollView)
/// 3. support under line
/// 4. support input text filter</pre>
///
/// the ZMultiLineEdit is based on the QMultiLineEdit, so for more functions please refer to 
/// the doc of the QMultiLineEdit, except for these:
/// setIndent(), getIndent(), getLineHeight(), setUnderline(),
/// setFilter(),getFilter(), drawLineText()
///
/// \code
/// ZScrollView/// sv = new ZScrollView( this, "sv" );
/// UTIL_MulitLineEdit *ml1, *ml2;
///
/// //add a 6 lines ZMultiLineEdit
/// ml1 = new ZMultiLineEdit(sv->viewport(),true,6);
///
/// //set filter
/// QRegExp tmp("[.*]");
/// ml1->setFilter(tmp);
/// sv->addChild(ml1,0,0);
///
/// //set indent
/// ml1->setIndent(20);
/// ml2 = new ZMultiLineEdit(sv->viewport());
/// 
/// //need to change the widget when ZScrollView's scrollbar is shown/hidden
/// sv->addChild(ml2,0,30,true);
/// \endcode
///
class Q_EXPORT ZMultiLineEdit : public ZTableView
{
    Q_OBJECT

public:
//--------------------------------------------------------------------------------------------------
//                                         ENUMS
//--------------------------------------------------------------------------------------------------
#ifndef QT_NO_MOT_CURSOR_FLAG
   ///
   ///  \brief The enum type defines the relative position of title
   ///
   enum CursorFlagExist 
   {
	CF_NONE,
	CF_YES
    };

    ///
    ///  \brief The enum type defines the relative position of title
    ///
    enum CursorFlagDirection 
    {
	CF_RTL,
	CF_LTR
    };

    ///
    ///  \brief The enum type defines the relative position of title
    ///
    enum InputContext 
    {
        IC_NONE,
        IC_SCROLLING,
        IC_TEXT_INPUT
    };

    /// 
    /// \brief the initial alignment of cursor.
    ///
    enum InitAutoAlign
    {
	AlignmentLeft,   //initial alignment left 
	AlignmentRight   //initial alignment right
    };
    
#endif
    ///
    ///  \enum  EchoMode
    ///
    ///  \brief Describes the ways in which QLineEdit can display its contents
    ///
    ///  \param Normal, Display characters as they are entered. This is the default
    ///
    ///  \param NoEcho, Do not display anything
    ///
    ///  \param Password, Display asterisks instead of the characters actually entered
    ///
    enum EchoMode 
    { 
       Normal, 
       NoEcho, 
       Password 
    };

     ///
     ///  \brief set the representing value when text entry should start within a field
     ///         The value may be:Begin,End and Selection.
     ///
     ///  \note  The default value is End.
     ///
     enum InsertionMethodType
     {
        INSERTION_METHOD_BEGIN,     ///< Begin,     indicates that text should begin at the first position
        INSERTION_METHOD_END,       ///< End,       indicates that text should begin at the current last position 
        INSERTION_METHOD_SELECTION  ///< Selection, indicates that text should overwrite contents.  
     };
        
    ///
    ///  \enum   WordWrap
    ///
    ///  \brief  The multiline edit's word wrap mode
    ///
    ///  \param  NoWrap, no word wrap at all
    ///
    ///  \param  WidgetWidth, word wrap depending on the current width of the editor widget
    ///
    ///  \param  FixedPixelWidth, wrap according to a fix amount of pixels
    ///
    ///  \param  FixedColumnWidth, wrap according to a fix character column
    ///
    enum WordWrap 
    {
        NoWrap,   
        WidgetWidth,
        FixedPixelWidth,
        FixedColumnWidth
    };
   
    ///
    /// \enum  WrapPolicy
    ///
    /// \brief Defines where the text can be wrapped in the word wrap mode
    ///
    /// \param AtWhiteSpace, break only after whitespace
    ///
    /// \param Anywhere, break anywhere 
    ///
    enum WrapPolicy 
    {
        AtWhiteSpace,   
        Anywhere  
    };
   
    ///
    /// \brief The enum type defines the relative position of title
    ///
    /// \param TitleTop The title is at the top-left corner of content area;
    ///
    /// \@param TitleLeft The title is at the left-center of content area;
    /// 
    enum TitlePosition 
    { 
    	Unknown = 0, 
    	TitleTop, 
    	TitleLeft 
    };

    ///
    /// \brief Constructor of ZMulitiLineEdit, constructs a new, null EZX-Style ZMulitiLineEdit
    ///
    /// \param parent the parent widget of the ZScrollView
    ///
    /// \param name the name of the ZScrollView
    ///
    ZMultiLineEdit( QWidget* parent=0, const char* name=0);

    ///
    /// \brief Constructor of ZMultiLineEdit
    ///
    /// \param parent the parent widget of the ZMultiLineEdit
    ///
    /// \param EZXStyle if false, the class is almost the same as QMuultiLineEdit.
    /// if true, ezx-special functions will be supported. Please refer to the class for detailed info
    ///
    /// \param lines the default lines that the ZMultiLineEdit has
    ///
    /// \param name the name of the ZMultiLineEdit
    ///
    ZMultiLineEdit( QWidget* parent,bool EZXStyle,int lines = 1,const char* name=0 );

    ///
    /// \brief Destructor of ZMultiLineEdit. 
    ///
    virtual ~ZMultiLineEdit();

    //================================================================================================
    ///
    /// \brief set the indent, the index's appearance when ZMulitLineEdit with underline has 3 lines:
    /// <pre>Name:_______________
    /// ____________________
    /// ____________________</pre>
    ///
    /// \param idt the width of pixels
    ///
    /// \note
    /// it can not work with setTitle() at the time.
    ///
    /// if only want to display text, can use setTitle(), it is much faster
    /// than setIndent()
    /// if want to add some any widget(for example, a button) at the left of the
    /// ZMultiLineEdit, please use setIndent()
    ///
    /// \see setTitle()
    ///
    //================================================================================================
    void setIndent( int idt );
    
    //================================================================================================
    ///
    /// \brief  get the indent
    ///
    /// \return the width of pixels
    ///
    //================================================================================================
    int getIndent();
  
    //================================================================================================
    ///
    /// \brief  get the each line's height
    ///
    /// \return the height with pixels
    ///
    //================================================================================================
    int getLineHeight() const;

    //================================================================================================
    ///
    /// \brief set the underline flag
    ///
    /// \param needUnderline if TRUE, the ZMultiLineEdit has underline in every line
    ///
    //================================================================================================
    void setUnderline( bool needUnderline = true );

    //================================================================================================
    ///
    /// \brief  get the underline flag
    ///
    /// \return if true, the ZMultiLineEdit will have underline; if false, it won't have underline
    ///
    //================================================================================================
    bool getUnderline();

    //================================================================================================
    ///
    /// \brief set the filter for the text input
    ///
    /// \param filter the filter 
    ///
    /// \param match if true,the text input will need to match the filter
    ///
    /// \note if the text is big, maybe the performance will be bad
    ///
    //================================================================================================
    void setFilter( const QRegExp& filter, bool match = false );

    //================================================================================================
    ///
    /// \brief  get the filter
    ///
    /// \return the filter set by setFilter(), in the default, there is no filter.
    ///
    //================================================================================================
    const QRegExp& getFilter() const;

    //================================================================================================
    ///
    /// \brief Get a line text 
    ///
    /// \param line the No of the line gets the text, it is from 0 to numLines()
    ///
    /// \return the text at the line number (possibly the empty string),
    /// or a null string if the line is invalid.
    ///
    //================================================================================================
    QString textLine( int line ) const;

    //================================================================================================
    ///
    /// Get the total lines
    ///
    /// \return the number of lines in the editor. The count includes any
    /// empty lines at top and bottom, so for an empty editor, this method will return 1.
    ///
    //================================================================================================
    int numLines() const;

    //================================================================================================
    ///
    /// Reimplemented from QWidget.
    ///
    //================================================================================================
    QSize sizeHint() const;

    //================================================================================================
    ///
    /// get the minimum sizeHint
    ///
    /// \return a sufficient size for one character and scroll bars if the editor has
    ///
    //================================================================================================
    QSize minimumSizeHint() const;
    
    //================================================================================================
    ///
    /// Reimplemented from QWidget.
    ///
    //================================================================================================
    QSizePolicy sizePolicy() const;

    //================================================================================================
    ///
    /// Reimplemented from QWidget.
    ///
    //================================================================================================
    virtual void setFont( const QFont &font );
    
    //================================================================================================
    ///
    /// \brief set the initial alignment.
    ///
    //================================================================================================ 
    void setInitAutoAlign(InitAutoAlign align);
   
    //================================================================================================
    ///
    /// \breif set the status of cursor flag.
    ///
    //================================================================================================
    void setCursorFlagExist(CursorFlagExist d);

    //================================================================================================
    ///
    /// Inserts txt at a line number line. If the line number is less than zero,
    /// or larger than the number of rows, the new text is put at the end.
    /// If the param s contains newline characters, several lines will be inserted.
    /// The cursor position is adjusted.
    ///"Cur Fixed lines is 
    ///
    /// \param s the txt to be inserted
    ///
    /// \param line the line where the txt to be inserted
    ///
    //================================================================================================
    virtual void insertLine( const QString &s, int line = -1 );
    
    //================================================================================================
    ///
    /// Inserts txt at a line number line, after the character number col in the line.
    /// If the param s contains newline characters, new lines will be inserted.
    /// The cursor position is adjusted. If "Cur Fixed lines is the inserted position is equal to
    /// the cursor position, the cursor will be placed after the end of the new text.
    ///
    /// \param s the txt to be inserted
    ///
    /// \param line the line where the txt is to be inserted
    ///
    /// \param col the character number where the txt is to be inserted
    ///
    /// \param mark if TRUE the txt will be marked
    ///
    //================================================================================================
    virtual void insertAt( const QString &s, int line, int col, bool mark = FALSE );

    //================================================================================================
    ///
    /// Deletes the line at the line number line. If the number is less than zero, or larger
    /// than the number of lines, no line will be deleted.
    ///
    /// \param line the number of the line which will be removed
    ///
    //================================================================================================
    virtual void removeLine( int line );

#ifndef QT_NO_MOT_CURSOR_FLAG
    //================================================================================================
    ///
    /// \brief set the direction of cursor flag. 
    ///
    /// \param  d, the direction of cursor flag.
    ///        enum CursorFlagdirection contains:
    ///             CF_NONE  shows no cursor flag.
    ///             CF_RTL   shows the right cursor flag. 
    ///             CF_LTR   shows the left cursor flag.
    //================================================================================================
    void setCursorFlagDirection(CursorFlagDirection d);
#endif
    //================================================================================================
    ///
    /// Get the cursor's position
    ///
    /// \param line [out] the line number where the cursor is
    ///
    /// \param col [out] the col number where the cursor is
    ///
    //================================================================================================
    void cursorPosition( int* line, int* col ) const;
    
    //================================================================================================
    ///
    /// Set the cursor's position
    ///
    /// \param line the line number where the cursor is
    ///
    /// \param col the col number where the cursor is
    ///
    /// \param mark if FALSE, the selection will be clear. otherwise it will be extended
    ///
    //================================================================================================
    virtual void setCursorPosition( int line, int col, bool mark = FALSE );

    //================================================================================================
    ///
    /// Get the cursor's position
    ///
    /// \param line [out] the line number where the cursor is
    ///
    /// \param col [out] the col number where the cursor is
    ///
    //================================================================================================
    void getCursorPosition( int* line, int* col ) const;

    //================================================================================================
    ///
    /// Judge whether the cursor is at the beginning of the text
    ///
    /// \return TRUE if the cursor is placed at the beginning of the text.
    ///
    //================================================================================================
    bool atBeginning() const;

    //================================================================================================
    ///
    /// Judge whether the cursor is at the end of the text
    ///
    /// \return TRUE if the cursor is placed at the end of the text.
    ///
    //================================================================================================
    bool atEnd() const;

    //================================================================================================
    ///
    /// Sets the fixed height of the ZMultiLineEdit so that ln text lines are visible.
    ///
    /// \param ln the number of the fixed visible lines
    ///
    //================================================================================================
    virtual void setFixedVisibleLines( int ln );

    //================================================================================================
    ///
    /// Get the width in pixels of the longest text line in this editor. 
    /// 
    /// \return the width
    ///
    //================================================================================================
    int maxLineWidth() const;
   
    //================================================================================================
    ///
    /// Sets the alignment.
    ///
    /// \param flags Possible values are AlignLeft, Align(H)Center and AlignRight.
    ///
    /// \see alignment() and Qt::AlignmentFlags
    ///
    //================================================================================================
    void setAlignment( int flags );

    //================================================================================================
    ///
    /// Get the alignment type
    ///
    /// \return the alignment
    ///
    /// \see setAlignment() and Qt::AlignmentFlags
    ///
    //================================================================================================
    int alignment() const;

    //================================================================================================
    ///
    /// \brief Set the validator
    ///
    /// \see setFilter()
    ///
    /// \note
    /// Not supported at this time
    ///
    //================================================================================================
    virtual void setValidator( const QValidator * );

    //================================================================================================
    ///
    /// Get the validator
    ///
    /// \return the validator
    ///
    /// \see setFilter()
    ///
    /// \note
    /// Not supported at this time
    ///
    //================================================================================================
    const QValidator* validator() const;

    //================================================================================================
    ///
    /// \brief Set ZMulitLineEdit is edited
    ///
    ///  edited if TRUE, ZMulitLineEdit will be edited
    ///
    //================================================================================================
    void setEdited( bool );

    //================================================================================================
    ///
    /// Get whether ZMulitLineEdit is edited
    ///
    /// \retval TRUE the text is edited
    ///
    //================================================================================================
    bool edited() const;

    //================================================================================================
    ///
    /// Moves the cursor one word to the right.
    ///
    /// \param mark if TRUE, the text will be marked.
    ///
    //================================================================================================
    void cursorWordForward( bool mark );

    //================================================================================================
    ///
    /// Moves the cursor one word to the left.
    ///
    /// \param mark if TRUE, the text will be marked.
    ///
    //================================================================================================
    void cursorWordBackward( bool mark );

     //================================================================================================
     ///
     /// \brief set the representing value when text entry should start within a field.
     /// The value may be:Begin,End and Selection.
     /// Selection indicates that text should overwrite contents.
     /// Begin     indicates that text should begin at the first position
     /// End       indicates that text should begin at the current last position 
     ///
     /// \param nSelection The method when user insert some text.
     ///
     /// \note  The default value is End.
     ///
     //================================================================================================
     virtual void setInsertionMethod( InsertionMethodType nSelection );

    //================================================================================================
    ///
    /// \brief Sets the echo mode. The default is Normal.
    ///
    ///  the echo mode to set
    ///
    //================================================================================================
    virtual void setEchoMode( EchoMode );

    //================================================================================================
    ///
    /// Get the echo mode. The default is Normal.
    ///
    /// \return the echo mode set
    ///
    //================================================================================================
    EchoMode echoMode() const;

    //================================================================================================
    ///
    /// Sets the maximum number of lines to m. Use -1 for unlimited characters(the default). 
    /// The existing excess lines will be deleted.
    ///
    /// \param m the maximum number of lines to set
    /// 
    /// \note
    /// If the number of lines exceed the maximum number, 
    /// the excess lines will be deleted from the bottom of the text 
    ///
    /// \see maxLines() and numLines().
    ///
    //================================================================================================
    void setMaxLength( int m );
    
    //================================================================================================
    ///
    /// \brief Set the displaying percentage of the font in the editor.  If the text is
    /// too long, it will truncate automaticly.
    /// The relative function:setFont().
    ///
    //================================================================================================
    virtual void setFontPercent(float rate);

    //================================================================================================
    ///
    /// Returns the current set line limit
    ///
    /// \return the currently set line limit, or -1 if there is no limit (the default).
    ///
    /// \see maxLines() and numLines().
    ///
    //================================================================================================
    int maxLength() const;

    //================================================================================================
    ///
    /// Sets the maximum length of lines. Use -1 for unlimited characters (the default). 
    /// The existing long lines will be truncated.
    ///
    /// \param m the maximum length of lines to set
    ///
    /// \see maxLineLength()
    ///
    //================================================================================================
    virtual void setMaxLineLength( int m );
    
    //================================================================================================
    ///
    /// Get the current set line length limit
    ///
    /// \return the currently set line length limit,
    /// or -1 if there is no limit (this is the default).
    ///
    //================================================================================================
    int maxLineLength() const;
    
    //================================================================================================
    ///
    /// Sets the maximum number of lines, Use -1 for unlimited characters (the default). 
    /// The existing excess lines will be deleted. 
    ///
    /// \param m the maximum number of lines to set
    ///
    /// \note
    /// The excess lines are deleted from the bottom of the lines.  
    ///
    /// \see maxLines() and numLines()
    ///
    //================================================================================================
    virtual void setMaxLines( int m );
    
    //================================================================================================
    ///
    /// Get the current set line limit
    ///
    /// \return the current set line limit, or -1 if there is no limit (the default). 
    ///
    /// \see setMaxLines()
    ///
    //================================================================================================
    int maxLines() const;
    
    //================================================================================================
    ///
    /// Sets the horizontal margin
    ///
    /// \param m the horizontal margin to set
    ///
    /// \see hMargin()
    ///
    //================================================================================================
    virtual void setHMargin( int m );
    
    //================================================================================================
    ///
    /// Get the current horizontal margin set
    ///
    /// \return the horizontal margin current set. The default is 3. 
    ///
    /// \see setHMargin()
    ///
    //================================================================================================
    int hMargin() const;

    //================================================================================================
    ///
    /// Marks the text 
    ///
    /// \param row_from The row marks the text start
    ///
    /// \param col_from The col marks the text start
    ///
    /// \param row_to The row marks the text end
    ///
    /// \param col_to The col marks the text end
    ///
    //================================================================================================
    virtual void setSelection( int row_from, int col_from, int row_to, int col_to );
     
    //================================================================================================
    ///
    /// Sets the word wrap mode, Per default, wrapping keeps words integrated. 
    /// To allow breaking within words, set the wrap policy to Anywhere, 
    /// The default wrap mode is NoWrap.  
    ///
    /// \param mode the word wrap mode to set
    ///
    /// \see wordWrap(), setWrapColumnOrWidth() and setWrapPolicy(). 
    ///
    //================================================================================================
    void setWordWrap( WordWrap mode );

    //================================================================================================
    ///
    /// Get the current word wrap mode
    ///
    /// \return the current word wrap mode
    ///
    /// \see setWordWrap()
    ///
    //================================================================================================
    WordWrap wordWrap() const;

    //================================================================================================
    ///
    /// Sets the wrap column or wrap width, depending on the word wrap mode
    ///
    /// \param value the wrap column or wrap width to set
    ///
    /// \see setWordWrap(), wrapColumnOrWidth()
    ///
    //================================================================================================
    void setWrapColumnOrWidth( int value );

    //================================================================================================
    ///
    /// Get the wrap column or wrap width, depending on the word wrap mode.
    ///
    /// \return the wrap column or wrap width
    ///
    /// \see setWordWrap(), wrapColumnOrWidth()
    ///
    //================================================================================================
    int wrapColumnOrWidth() const;

    //================================================================================================
    ///
    /// Defines where the text can be wrapped in the word wrap mode, 
    /// The default is AtWhiteSpace. 
    ///
    /// \param policy the word wrap mode to set
    ///
    //================================================================================================
    void setWrapPolicy( WrapPolicy policy );
 
    //================================================================================================
    ///
    /// Get the current word wrap policy
    ///
    /// \return the current word wrap policy
    ///
    /// \see setWrapPolicy()
    ///
    //================================================================================================
    WrapPolicy wrapPolicy() const;

    //================================================================================================
    ///
    /// Get whether the view can update itself automatically 
    /// whenever it is changed in some way
    ///
    /// \retval TRUE if the view updates itself automatically 
    /// whenever it is changed in some way
    ///
    /// \see setAutoUpdate()
    ///
    //================================================================================================
    bool autoUpdate()   const;

    //================================================================================================
    ///
    /// Sets the auto-update option for multi-line editor
    ///
    /// \param enable if TRUE (this is the default),the editor will update itself 
    /// automatically whenever it has changed in some way (generally, when the text 
    /// has been inserted or deleted);
    /// If FALSE, the view will NOT repaint itself, or update its internal state 
    /// variables itself when it is changed. This can be useful to avoid flicker 
    /// during large changes, and is singularly useless otherwise: Disable auto-update, 
    /// do the changes, re-enable auto-update, and call repaint().
    ///
    /// \note
    /// Do not leave the view in this state for a long time (i.e. between events ). 
    /// If, for example, the user interacts with the view when auto-update is off, 
    /// strange things can happen
    /// 
    /// Setting auto-update to be TRUE will not repaint the view. You must call repaint() 
    /// to do this (preferable repaint(FALSE) to avoid flicker).
    /// 
    /// \see autoUpdate() and repaint()
    ///
    //================================================================================================
    virtual void setAutoUpdate( bool enable );

    //================================================================================================
    ///
    /// Sets undo enabled
    ///
    /// \param enable set undo enabled to enable
    /// 
    /// \see isUndoEnabled()
    ///
    //================================================================================================
    void setUndoEnabled( bool enable );

    //================================================================================================
    ///
    /// Get whether undo is enabled
    ///
    /// \return whether or not the multilineedit is currently undo enabled 
    /// 
    /// \see setUndoEnabled()
    ///
    //================================================================================================
    bool isUndoEnabled() const;

    //================================================================================================
    ///
    /// Sets the maximum number of operations that can be stored on the undo stack
    ///
    /// \param depth the depth of the undo stack
    /// 
    /// \see undoDepth()
    ///
    //================================================================================================
    void setUndoDepth( int depth );

    //================================================================================================
    ///
    /// Get the maximum number of operations that can be stored on the undo stack
    ///
    /// \return the maximum number of operations
    /// 
    /// \see setUndoDepth()
    ///
    //================================================================================================
    int undoDepth() const;

    //================================================================================================
    ///
    /// Get whether this editor can accept the text input. 
    /// Scrolling and cursor movements are accepted in any case
    ///
    /// \return FALSE if this editor can not accept any text input
    /// 
    /// \see setReadOnly() and QWidget::isEnabled()
    ///
    //================================================================================================
    bool isReadOnly() const;

    //================================================================================================
    ///
    /// Get whether the editor is in overwrite mode, 
    /// i.e. if characters typed replace characters in the editor
    ///
    /// \retval TRUE if this editor is in overwrite mode
    /// 
    /// \see setOverwriteMode()
    ///
    //================================================================================================
    bool isOverwriteMode() const;

    //================================================================================================
    ///
    /// Get the text of the edit withour predicted part of text
    ///
    /// \return a copy of the whole text, 
    /// if the edit contains no text, a null string is returned
    ///
    //================================================================================================
    QString text() const;
    
    //================================================================================================
    ///
    /// Get the text of the edit as is
    ///
    /// \return a copy of the whole text, 
    /// if the edit contains no text, a null string is returned
    ///
    //================================================================================================
    QString textWithPredict() const;

    //================================================================================================
    ///
    /// Get the text of the phone no edit without pyphen
    ///
    /// \return a copy of the whole text, 
    /// if the edit contains no text, a null string is returned
    ///
    //================================================================================================
    QString phonenoText() const;

    //================================================================================================
    ///
    /// Get the length of the edit's text length
    ///
    /// \return the length of the current text
    ///
    /// \see setMaxLength()
    ///
    //================================================================================================
    int length() const;

    //================================================================================================
    ///
    /// Sets the distance between tab stops, the distance is measured in multiples 
    /// of the width of a lower case 'x' in the widget's font
    ///
    /// \param ex the distance to set, the default is 8
    ///
    /// \see defaultTabStop()
    ///
    //================================================================================================
    static void setDefaultTabStop( int ex );

    
    //================================================================================================
    ///
    /// Get the distance between tab stops
    ///
    /// \return the distance
    ///
    /// \see setDefaultTabStop()
    ///
    //================================================================================================
    static int defaultTabStop();

    //================================================================================================
    ///
    /// Reimplemented from ZTableView
    ///
    //================================================================================================
    virtual void show();
   
    //================================================================================================
    ///
    /// return current title position
    ///
    //TitlePosition titlePosition() const;

    //================================================================================================
    ///
    /// Set title position
    ///
    /// \note
    /// if its style is not ezx_style(the ZMultiLineEdit will appear a scrollbar
    /// can resize dynamically), can only set position TitleTop
    ///
    /// \see constructor
    ///
    /// \see setTitle()
    ///
    //================================================================================================
    void setTitlePosition(TitlePosition titlePos);

    //================================================================================================
    ///
    /// return current title, if no title, return QString::null
    ///
    //================================================================================================
    QString title() const; 

    //================================================================================================
    ///
    /// Set ZMultiLineEdit title
    ///
    /// \note
    /// it can not work with setIndent() at the time.
    ///
    /// if only want to display text, can use the function, it is much faster
    /// than setIndent()
    /// if want to add some any widget(for example, a button) at the left of the
    /// ZMultiLineEdit, please use setIndent()
    ///
    /// \see setIndent()
    ///
    //================================================================================================
    void setTitle(const QString & titleStr);

    //================================================================================================
    ///
    /// \brief Set truncating info. When the length of text exceeds the max length of multiline edit,
    ///        multiline edit will truncate it. The style of truncating has two kinds, the fist one 
    ///        directly truncate the text at the max length, the second one replaces the last several
    ///        char after truncating with replacing string.
    /// 
    /// \param nStyle, The truncating style, 0, truncating direct, 1, replacing the last several
    /// chars with strReplace. The default vale is 0.
    /// 
    /// \param strReplace, replacing string.  
    /// 
    ///
    //================================================================================================
    void setTruncateInfo(int nStyle = 0, const QString & strReplace = QString::null);

    //================================================================================================
    ///
    /// if enable = true, ZMultiLineEdit will automatic calculate the height based on the lines of text, or
    /// not.
    /// Note: it only is effective when ZMultiLineEdit is no ezx style, at the same time, it doesn't update
    /// the ZMultiLineEdit status when changing the enable value, so you must reset the ZMultiLineEdit geometry
    /// by yourself or by Layout manager.
    /// it only applies when ZMultiLineEdit set readOnly = true. 
    ///
    ///
    //================================================================================================
    void setAutoFixedHeight(bool enable);

#ifdef FEAT_UISTYLE_CHAMELEON
    //================================================================================================
    ///
    /// \brief For navigate mode, to reset the foucus item.
    ///        
    /// \param  bool next, If the multiline editor has the next page, 
    ///         next will be TRUE. Then the focus will be set to the first item of next page.
    ///         Otherwise, it should be FALSE. And the focus will be set to last item of this page.
    ///
    //================================================================================================
    virtual void  resetFocusItem(bool);
    
    //================================================================================================
    ///
    /// \brief get the rect of current foucs item.
    /// 
    /// \return the rect of current focus item.
    ///
    //================================================================================================
    virtual QRect getCurrentFocusRect();
    
    //================================================================================================
    ///
    /// \brief justify whether the editor has next focus item.
    ///
    //================================================================================================
    virtual bool  hasNextPrevFocusItem(bool);
    
    //================================================================================================
    ///
    /// \brief set the scroll panel mode of  multiLine editor.
    /// 
    /// \param bool nest, if nest is TRUE, it should have a nested scroll panel.
    ///                   Otherwise, it should auto-expand.
    ///
    //================================================================================================
    void setNestScrollPanelMode(bool nest);
   
    //================================================================================================
    ///
    /// \brief get the scroll panel mode 0f multiLine editor.
    /// 
    /// \return bool, whether the mode is nested.
    ///
    //================================================================================================
    bool nestScrollPanelMode() const;
    
    //================================================================================================
    ///
    /// \brief set the foucs status.
    /// 
    /// \param bool b, If b is TRUE, focus is out. Otherwise, focus is in.
    ///
    //================================================================================================
    void setMoveFocusOutRange(bool b);
    
    //================================================================================================
    ///
    /// \brief get the foucs status.
    /// 
    ///
    //================================================================================================
    bool focusOutRange() const;

    //================================================================================================
    ///
    /// \brief Expand mode coincides with ezx_style, 
    ///  if ezx_style is true, expand mode,
    ///  or, no expand mode, don't support switching between two mode, so, using
    ///  constructor to decide which mode is used;
    ///
    //================================================================================================
    void setAutoExpandInNestMode(bool expand);
    
    //================================================================================================
    ///
    ///  \brief EZX_STYLE is decided by the constructor
    ///
    ///  return ezx_style 
    ///
    //================================================================================================
    bool autoExpandInNestMode() const;
#endif

#ifndef QT_NO_WORDCOMPLETE
    //================================================================================================
    ///
    ///  \brief it is used by input method. To get the previous position of cursor.
    ///
    ///  \param currentX, the X position, after inserting string.
    ///
    ///  \param currentY, the Y position, after inserting string.
    ///
    ///  \param insertLength, the length of inserted string.
    ///
    ///  \param  previousX,  the previous X position, before inserting string
    ///
    ///  \param  previousY,  the previous Y position, before inserting string
    ///
    //================================================================================================
    void cursorPosBeforeInsert(int currentX,int currentY,int insertLength,int* previousX,int* previousY); //for input method
    
    //================================================================================================
    ///
    ///  \brief it is used by input method. just inform the editor, 
    ///         whether the inserted string has word completion. 
    ///
    ///  \param  wc, if wc is TRUE, the inserted string has word completion, Or it has no word completion.
    ///
    //================================================================================================
    void setWordComplete(bool wc);
#endif

#ifndef QT_NO_GET_CONTEXT
    //================================================================================================
    ///
    ///  \brief  get the string of a line.
    ///
    ///  \param i, the number of line.
    ///
    //================================================================================================
    QString getRowString(int i);
#endif

#if defined(QT_NO_PUBLIC_INTERFACE) && defined(QT_NO_WORDCOMPLETE)
#else
    //================================================================================================
    ///
    ///  \brief emit a textchange signal.
    ///
    //================================================================================================
    void emitTextChanged();
#endif

#ifndef QT_NO_PUBLIC_INTERFACE
    //================================================================================================
    ///
    ///  \brief calculate the pos 'len' steps from the given position 'startPos'
    ///
    ///  \param startPos, started position of cursor. 
    ///
    ///  \param len, the length of string.
    ///
    //================================================================================================	
    QPoint calCursorPos( QPoint startPos , int len );
    
    //================================================================================================
    ///
    ///  \brief get the line number of current content.
    ///
    ///  \return the number of line.
    ///
    //================================================================================================
    int getLineCount();
    
    //================================================================================================
    ///
    ///  \brief get the content of a line
    ///
    ///  \param line, the number of the line.
    ///
    ///  \return the content of current line.
    ///
    //================================================================================================
    QString getLineContent( int line );
    
    //================================================================================================
    ///
    ///  \brief get a handle of input field. 
    ///
    ///  \return ZKbInputField*, return the handle of input field.
    ///
    //================================================================================================
    ZKbInputField*  getInputField();

    //================================================================================================
    ///
    ///  \brief it is used by input method. insert the string into ZMultiLine editor.
    ///
    ///  \param pos, the position of insertion.
    ///
    ///  \param text  text of inserted string.
    ///  
    //================================================================================================
    void insertString_if( QPoint pos, QString text ); 
#endif

    //================================================================================================
    ///
    ///  \brief get the height of a line. 
    ///
    ///  \return the height of a line.
    ///
    //================================================================================================
    int  heightViewed() const;

    //================================================================================================
    ///
    ///  \brief judge if the char can be inserted due to filter
    ///
    ///  \param ch, the char that want to be inserted
    ///
    ///  \return true if the can can be inserted
    /// 
    //================================================================================================
    bool isValidChar( const QChar& ch );
    
#ifndef QT_NO_WTLE
    //================================================================================================
    ///
    /// \brief special cursor mode.
    /// 
    //================================================================================================
    void specialInputModeCursorModel(bool);
#endif //end QT_NO_WTLE
    //================================================================================================
    ///
    /// \brief set cursor mode of input mode.
    /// 
    //================================================================================================
    void setInputModeCursorModel(int);
    
    //================================================================================================
    ///
    /// \brief get cursor mode of input mode.
    /// 
    //================================================================================================
    int getInputModeCursorModel(void);

    //================================================================================================
    ///
    /// \brief update cursor mode.
    /// 
    //================================================================================================
    void updateCursorModel(void);

    //================================================================================================
    ///
    /// \brief delete the character, when the language is RTL.
    /// 
    //================================================================================================
    void backspaceNew(void);
    
    //================================================================================================
    ///
    /// \brief insert the string, when the language is RTL.
    /// 
    //================================================================================================
    void insertAtNew( const QString &, int, int, bool);
    
    //================================================================================================
    ///
    /// \brief judge the TsBidiCharClass is Bidi.
    /// 
    //================================================================================================
    bool  isLTRBidiClass(TsBidiCharClass);

    //================================================================================================
    ///
    /// \brief judge the TsBidiCharClass is Bidi .
    /// 
    //================================================================================================
    bool  isRTLBidiClass(TsBidiCharClass);

    //================================================================================================
    ///
    /// \brief judge the TsBidiCharClass is Number.
    /// 
    //================================================================================================
    bool isNumericBidiClass(TsBidiCharClass);
    
    //================================================================================================
    ///
    /// \brief judge the TsBidiCharClass is  Neutral Bidi .
    /// 
    //================================================================================================
    bool  isNeutralBidiClass(TsBidiCharClass); 

public slots:
    ///
    /// change the content size
    /// 
    /// \param lines how many lines have been changed
    ///
    /// \param cursorPos cursor position
    ///
    /// \note internal use
    ///
    virtual void changeContentSize( int lines,QPoint cursorPos );

    ///
    /// Sets the text, removing the old text, if any.
    ///
    /// \param s the text to set
    ///
    virtual void setText( const QString &s );
    
    ///
    /// Set whether this edit can accept the text input. 
    /// Scrolling and cursor movements are accepted in any case
    ///
    /// \param on if FALSE, this edit will accept the text input
    ///
    /// \see isReadOnly() and QWidget::setEnabled()
    ///
    virtual void setReadOnly( bool on );

    ///
    /// \brief set the enable and disbale state of multilineedit
    ///
    /// \param enable, on if FALSE, this edit will be disable state
    ///
    /// \see isZEnabled() isZDisabled and setReadOnly()
    ///
    virtual void setZEnabled(bool enable);

    ///
    /// \brief justify whether multilineedit is enable state or not.
    ///
    /// \return bool, the state of enable. 
    ///
    /// \see setZEnabled() isZDisabled and setReadOnly()
    ///
    bool isZEnabled();
    
    ///
    ///  \brief justify whether multilineedit is disbale state or not.
    ///
    /// \return bool, the state of disable.
    ///
    /// \see isZEnabled() setZEnabled() and setReadOnly()
    ///
    bool isZDisabled();

    ///
    /// Sets overwrite mode,Overwrite mode means that typed characters  
    /// replace characters in the editor
    ///
    /// \param on if TRUE, sets overwrite mode will be on, or will be off
    ///
    virtual void setOverwriteMode( bool on );

    ///
    /// Removes all texts
    ///
    void      clear();
    
    ///
    /// Appends text to the editor's text
    ///
    /// \param s the text to append
    ///
    void append( const QString &s );
    
    ///
    /// Deselects all texts (i.e. removes marking) and leaves the cursor 
    /// at the current position. 
    ///
    void       deselect();

    ///
    /// Selects all texts without moving the cursor
    ///
    void       selectAll();
    
    ///
    ///  For input methods
    ///
    ///  \internal
    ///
    void  smartPunctuation(); 
    
#ifndef QT_NO_CLIPBOARD
    ///
    /// Copies the plain text from the clipboard onto the current cursor position. 
    /// Any marked text is deleted first
    ///
    void       paste();

    ///
    /// Copies text in MIME subtype from the clipboard onto the current cursor 
    /// position. Any marked text is deleted first. 
    ///
    /// \param subtype MIME subtype in which the text is copied
    ///
    void       pasteSubType(const QCString& subtype);

    ///
    /// The function is obsolete
    ///
    void       copyText() const;

    ///
    /// Copies the marked text to the clipboard. It will only make 
    /// copies if echoMode() is Normal
    ///
    void       copy() const;

    ///
    /// Copies the selected text to the clipboard and deletes the selected text
    ///
    void       cut();

    ///
    /// Deletes the selected text
    ///
    void       deleteText();
#endif

    ///
    /// Inserts the text at the current cursor position
    ///
    /// \param s the text is to insert
    ///
    void insert( const QString& s );

    ///
    /// Undoes the last text operation
    ///
    void       undo();

    ///
    /// Redoes the last text operation
    ///
    void       redo();

signals:
    ///
    /// This signal is emitted when the editor is clicked. 
    ///
    void    clicked();

    ///
    /// This signal is emitted when the text is trancated
    ///
    /// \note
    /// The text will be trancated when the text is too big to display
    ///
    void    textTrancated();

    ///
    /// This signal is emitted when the text is changed by an event or by a slot. 
    ///
    /// \note 
    /// The signal is not emitted when you call a non-slot function such as insertLine().
    ///
    void    textChanged();

    ///
    /// This signal is emitted when the text is changed by an event or by a slot. 
    ///
    /// \note
    /// The signal is not emitted when you call a non-slot function such as insertLine(). 
    ///
    /// \see returnPressed() 
    ///
    void    returnPressed();

    ///
    /// This signal is emitted when the availability of undo changes. 
    ///
    /// \param yes if TRUE then undo() will work 
    /// until undoAvailable( FALSE ) is next emitted
    ///
    void undoAvailable( bool yes );

    ///
    /// This signal is emitted when the availability of redo changes. 
    ///
    /// \param yes If TRUE, then redo() will work 
    /// until redoAvailable( FALSE ) is next emitted.
    ///
    void redoAvailable( bool yes );

    ///
    /// \brief This signal is emitted when the availability of cut/copy changes. 
    ///
    /// \note If TRUE, then cut() and copy() will work 
    ///   until copyAvailable( FALSE ) is next emitted 
    ///
    void    copyAvailable( bool );

//#if defined(QT_NO_PUBLIC_INTERFACE) && defined(QT_NO_WORDCOMPLETE) && defined(QT_NO_GET_CONTEXT)
//#else
    ///
    /// \brief  when cursor is changed, the signal is emited.
    ///
    void  cursorChanged(int cursorX, int cursorY);
//#endif

#ifndef QT_NO_GET_CONTEXT
    ///
    /// \brief  when buffer is updated,the signal is emited.
    /// 
    void  bufferUpdate(int cursorX, int cursorY); 

    ///
    /// \brief  when content is changed, the signal is emited.
    ///
    void  contentChanged();
#endif
    
    ///
    /// \brief the signal is emitted when size hint is changed
    ///
    /// \note internal use
    ///
    void    changeSizeHint( QWidget* widget,QSize size,QPoint cusrorPos,int larger );

    ///
    /// \brief the signal is emitted, when lines are changed
    ///
    /// \note internal use
    ///
    void    linesChanged( int lines,QPoint cursorPos );

    ///
    /// \brief when right smart punctnate is occured, the signal is emited.
    ///
    void    rightSmartPuncOccurred(void);

    ///
    /// \brief the cursor is moved up and down, the signal is emited.
    ///
    void sigCursorUpDown(bool down);

#ifdef FEAT_UISTYLE_CHAMELEON
    ///
    /// \note internal use
    ///
    void contentsResizing(ZMultiLineEdit* , int width, int height);
#endif
    
protected:
    ///
    /// Reimplemented from QFrame.
    ///
    void    updateMask();
#ifndef QT_NO_WTLE
    ///
    /// Convert the pixel position to the cursor position
    ///
    /// \param p [in] pixel position 
    ///
    /// \param x [out] cursor x position 
    ///
    /// \param y [out] cursor y position 
    ///
    void    pixelPosToCursorPos(QPoint p, int* x, int* y);
#else
    ///
    /// Convert the pixel position to the cursor position
    ///
    /// \param p [in] pixel position 
    ///
    /// \param x [out] cursor x position 
    ///
    /// \param y [out] cursor y position 
    ///
    void    pixelPosToCursorPos(QPoint p, int* x, int* y) const;
#endif
    ///
    /// Set the cursor pixel position
    ///
    /// \param p cursor pixel position to set
    ///
    /// \param clear_mark if TRUE, the selection will be unmarked
    ///
    void    setCursorPixelPosition(QPoint p, bool clear_mark = true);

    ///
    /// Reimplemented from ZTableView
    ///
    void    paintEvent(QPaintEvent* );

#ifndef QT_NO_PUBLIC_INTERFACE
    ///
    /// \brief a part of paint action.
    ///
    /// \note internal use
    ///
	int paintCell_if( QPainter* p , int row , int underlineI , bool underlineHit , int reverseI ,\
                      bool reverseHit , int yPos , int x , QString s , QFontMetrics fm , QRect updateR , QColorGroup g );
#endif

    ///
    /// Reimplemented from ZTableView
    ///
    void    paintCell( QPainter *, int row, int col, int xPos, int yPos );
    
    ///
    /// draw the line text
    /// override the function to draw its own style's text.
    /// for example:
    /// change color of the line text
    ///
    /// \param (x,y) the base line to draw  
    ///
    /// \param width the width of the area to draw
    ///
    /// \param height the height of the area to draw
    ///
    /// \param flags alignment
    ///
    /// \param flags lineStr line text
    ///
    /// \param lineStr line text
    ///
    /// \param painter
    ///
    /// \param row
    ///
    /// \param col
    ///
    /// \note all the params above have the right initial values
    ///
    virtual void drawLineText( QPainter* painter, int x, int y, int width,
                               int height, int flags, const QString& lineStr, int row = 0 , int col = 0);

    ///
    /// \brief draw the frame of table view.
    ///
    virtual void drawTableFrame(QPainter*  p, QRect & updateR);
                                   
    ///
    /// \brief event filter.
    ///
    bool event( QEvent * );

    ///
    /// \brief accept the mouse presses event.
    ///
    void    mousePressEvent( QMouseEvent * );

    ///
    /// \brief accept mouse moves event.
    ///
    void    mouseMoveEvent( QMouseEvent * );

    ///
    /// \brief accept mouse releases event.
    ///
    void    mouseReleaseEvent( QMouseEvent * );

    ///
    /// \brief accept mouse double clicked event.
    ///
    void    mouseDoubleClickEvent( QMouseEvent * );

    ///
    /// \brief accept wheel event
    ///
    void    wheelEvent( QWheelEvent * );

    ///
    /// \brief accept key presses event
    ///
    void    keyPressEvent( QKeyEvent * );

    ///
    /// \brief accept key releases event
    ///
    void keyReleaseEvent(QKeyEvent * );
    
    ///
    /// \note
    /// Starts the cursor blinking
    ///
    void    focusInEvent( QFocusEvent * );
    
    ///
    /// \note
    /// Stop the cursor blinking
    ///
    void    focusOutEvent( QFocusEvent * );
    
    ///
    /// \brief accept the timer event.
    ///
    void    timerEvent( QTimerEvent * );

    ///
    /// \brief accept leave event
    ///
    void    leaveEvent( QEvent * );

    ///
    /// \brief accept resize event
    ///
    void    resizeEvent( QResizeEvent * );

    ///
    /// \brief set fous to the child widget.
    ///
    bool    focusNextPrevChild( bool );


    ///
    /// Judge whether there is a marked text
    ///
    /// \retval TRUE if there is a marked text
    ///
    bool    hasMarkedText() const;
    
    ///
    /// Get the marked text
    ///
    /// \return the marked text
    ///
    QString markedText() const;
    
#ifndef QT_NO_WTLE
    ///
    /// Returns the width in pixels of the text
    ///
    /// \param lineNo the number of line.
    ///
    ///
    int	    textWidthWithTabs( int lineNo );
    
    ///
    /// Returns the width in pixels of the text.
    ///
    /// \param lineNo the number of line. 
    ///
    ///
    int	    textWidth( int lineNo = -1 );
#else
    ///
    /// Returns the width in pixels of the text
    ///
    /// \param line the text at line 
    ///
    ///
    int     textWidth( int );

    ///
    /// Returns the width in pixels of the text
    ///
    /// \param s the text 
    ///
    ///
    int textWidth( const QString &s);
#endif

    ///
    /// Get the top center point where the cursor is drawn.
    ///
    /// \return the top center point 
    ///
#ifndef QT_NO_WTLE
    QPoint  cursorPoint();
#else
    QPoint  cursorPoint() const;
#endif

    ///
    /// Get the top center point where the cursor is drawn in the displayed cleartool 
    ///
    /// \return the top center point 
    ///
#ifndef QT_NO_WTLE
    QPoint  cursorPointViewed();
#else
    QPoint  cursorPointViewed() const;
#endif
    ///
    /// Inserts the text at the current cursor position
    ///
    /// \param c the text to set
    /// \param mark if TRUE, the text will be marked
    ///
    virtual void insert( const QString& c, bool mark );

    ///
    /// Makes a line break at the current cursor position
    ///
    virtual void newLine();

    ///
    /// Deletes the text from the current cursor position to the end of the line
    ///
    virtual void killLine();
    
    ///
    /// Moves the cursor one page up. 
    ///
    /// \param mark if TRUE, the text will be marked.
    ///
    virtual void pageUp( bool mark=FALSE );
    
    ///
    /// Moves the cursor one page down. 
    ///
    /// \param mark if TRUE, the text will be marked.
    ///
    virtual void pageDown( bool mark=FALSE );
    
    ///
    /// Moves the cursor one character to the left
    /// 
    /// \param mark if TRUE, the text will be marked.
    /// \param wrap If TRUE, the cursor will move to the end of the previous line 
    /// if it is placed at the beginning of the current line
    ///
    virtual void cursorLeft( bool mark=FALSE, bool wrap = TRUE );

    ///
    /// Moves the cursor one character to the right
    ///
    /// \param mark if TRUE, the text will be marked.
    /// \param wrap If TRUE, the cursor will move to the beginning of the next line 
    /// if it is placed at the end of the current line.
    ///
    virtual void cursorRight( bool mark=FALSE, bool wrap = TRUE );

    ///
    /// Moves the cursor up one line
    ///
    /// \param mark if TRUE, the text will be marked.
    ///
    virtual void cursorUp( bool mark=FALSE );

    ///
    /// Moves the cursor one line down
    ///
    /// \param mark if TRUE, the text is marked.
    ///
    virtual void cursorDown( bool mark=FALSE );
    
#ifdef FEAT_UISTYLE_CHAMELEON
    ///
    /// \brief when mutliLine is readonly, the method is used to move the cursor.
    ///
    virtual void cursorMove(bool down);
    
    ///
    /// \brief when cursor moves from one line to another one, it emits a signal to inform
    ///        the scroll panel. 
    ///
    /// \param int lines, if lines > 0, cursor will move down. 
    ///                   Otherwise, cursor will move up.
    ///
    void linesChangedNoExp(int lines);
    
    ///
    /// \brief get the first invisible line number.
    ///
    int firstNoVisibleLines(int curLines, const QRect & rt, bool down);
#endif
    ///
    /// Deletes the character on the left side of the text cursor and moves the cursor
    /// one position to the left. If a text has been marked by the user (e.g. by clicking 
    /// and dragging) the cursor will be put at the beginning of the marked text and the marked 
    /// text will be removed
    ///
    /// \see del()
    ///
    virtual void backspace();

    ///
    /// Deletes the character on the right side of the text cursor. If a text has been marked
    /// by the user (e.g. by clicking and dragging) the cursor is put at the beginning of the
    /// marked text and the marked text is removed.
    ///
    /// \see backspace()
    ///
    virtual void del();

    ///
    /// Moves the text cursor to the left end of the line
    ///
    /// \param mark if TRUE, the text will be marked toward the first position
    ///
    /// \see end()
    ///
    virtual void home( bool mark=FALSE );

    ///
    /// Moves the text cursor to the right end of the line
    ///
    /// \param mark if TRUE, the text will be marked toward the last position
    ///
    /// \see home()
    ///
    virtual void end( bool mark=FALSE );

    ///
    /// If there is a marked text, set the marked region
    ///
    /// \param line1 the line start of the marked region 
    ///
    /// \param col1 the col start of the marked region 
    ///
    /// \param line2 the line end of the marked region 
    ///
    /// \param col2 the col emd of the marked region 
    ///
    /// \retval TRUE if there is marked text, or FALSE
    ///
    bool getMarkedRegion( int* line1, int* col1,
                          int* line2, int* col2 ) const;

    ///
    /// Get the number of characters at the line number 
    ///
    /// \param row the line number
    ///
    /// \return the length of the text at the line number
    ///
    int lineLength( int row ) const;

    ///
    /// Get a pointer to the text at the line number row
    ///
    /// \param row the line number
    ///
    /// \return the text at the line number
    ///
    QString* getString( int row ) const;

    ///
    /// Judge whether the row is the last row in a paragraph
    ///
    /// \param row the line number
    ///
    /// \retval TRUE if the row is the last row in a paragraph
    ///
    bool isEndOfParagraph( int row ) const;

    ///
    /// Get the string shown at line, including processing of the echoMode(). 
    ///
    /// \param row the line number
    ///
    /// \return the text shown at line
    ///
    QString stringShown( int row ) const;

    ///
    /// \brief set the palette.
    /// 
    virtual void setPalette(const QPalette &);

    ///
    /// Inserts a QChar at the current cursor position
    ///
    /// \param c the QChar to insert
    ///
    /// \note
    /// Please call insert
    ///
    void insertChar( QChar c );

    ///
    /// \brief get the offset 
    ///
    int  positionToOffsetInternal( int row, int col ) const;

    ///
    /// \brief set the offset.
    ///
    void  offsetToPositionInternal( int position, int* row, int* col ) const;
    
    ///
    /// \brief clear the list of undo.
    ///
    void  clearUndoList();
    
    ///
    /// \brief justify whether the line is visible partially.
    ///
    bool  partiallyInvisible( int row );

    ///
    /// \brief get the count of truncate.
    ///
    int   getTruncateCount();

    ///
    /// \brief a flag of cursor state.
    ///    
    bool  cursorOn;

private slots:
    ///
    ///  \brief when clipboard is changed, it will be invoked.
    /// 
    void    clipboardChanged();
    
    ///
    ///  \brief when the cursor blink timer is timeout, it will be invoked.
    /// 
    void    blinkTimerTimeout();
    
    ///
    ///  \brief when the scroll timer is timeout, it will be invoked.
    /// 
    void    scrollTimerTimeout();
    
    ///
    ///  \brief implementation. for drag copy.
    /// 
    void    dndTimeout();
    
    ///
    ///  \brief when delete fastly, it will be invoked.
    /// 
    void    fastDelTimerTimeout();

#ifndef QT_NO_GET_CONTEXT
    ///
    ///  \brief used by input methods. update buffer.
    ///         Mainly support for touch pad.
    ///
    void    bufferUpdate(); 
#endif

private:
    ///
    /// \brief  type of line.
    ///
    enum LineType
    {
        Empty_Line = 0,
        Color_Line,
        Pixmap_Line
    };

    ///
    /// \brief type of text  
    ///
    enum TextType
    {
        Title = 0,
        Field
    };
 
#ifndef QT_NO_WTLE
    ///
    /// \brief the alignment of paragraph.  
    ///
    enum eParaAlignment
    {
    	DIR_UNKNOWN,
    	LTR,
    	RTL
    };
#endif
    ///
    /// \struct   a row of multiline editor.
    ///
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
    
    ///
    /// \brief initial the multiline editor.
    ///
    void init( QWidget* parent,bool style,int lines,const char* name );
    
    ///
    /// \brief  validate the input string.
    ///
    void filterString( QString& filtered,const QString& s );
    
    ///
    /// \brief  auto send the request to scroll panel.
    ///
    void autoSendScrollRequest( int lines,const QPoint& curPos );
    
    ///
    /// \brief  set the title into a certain place.
    ///
    void setTitlePositionAux(const QString& /*oldTitle*/, int from);
    
    ///
    /// \brief  use the replaced string instead of some charaters.
    ///
    QString addReplacedStr(const QString & strSource, int row);
    
    ///
    /// \brief  get the top area of form item.
    ///
    QRect getFormItemTopArea();
    
    ///
    /// \brief  get the left area of form item.
    ///
    QRect getFormItemLeftArea();
    
    ///
    /// \brief  get the right area of form item.
    ///
    QRect getFormItemRightArea();
    
    ///
    /// \brief  get the bottom area of form item.
    ///
    QRect getFormItemBottomArea();
    
    ///
    /// \brief get top area of the md 
    ///
    QRect getMDTopArea();
    
    ///
    /// \brief get the bottom area of the md.
    ///
    QRect getMDBottomArea();
    
    ///
    /// \brief get the left area of the md.
    ///
    QRect getMDLeftArea();
    
    ///
    /// \brief get the right area of the md
    ///
    QRect getMDRightArea();
    
    ///
    /// \brief get the edit area.
    ///
    QRect getEditArea();
   
    ///
    ///  \brief get the field Rect not include title, include padding.
    ///
    QRect  getFieldRect();
 
    ///
    /// \brief draw the other area.
    ///
    void drawOtherArea(QPainter* p, const QRect & validrc, const QRect & paintArea, ZSkinBase* pSkinBase);
    
    ///
    /// \brirf draw mutliple area. 
    ///
    void drawMultiArea(QPainter* p, const QRect & validrc, const QRect & paintArea, ZSkinBase* pSkinBase);
    
    ///
    /// \brief update the layout of text
    ///
    QSize updateTextLayout();
    
    ///
    /// \brief get the width of the contents. 
    ///
    int getContentsWidth();
    
    ///
    /// \brief paste at the special area.  
    ///
    void   pasteSpecial(const QPoint&);
    
    ///
    /// \brief the map from view. 
    ///
    int     mapFromView( int xPos, int row );
    
    ///
    /// \brief the map  to view.
    ///
    int     mapToView( int xIndex, int row );
    
    ///
    /// \brief set the width of multiline editor.  
    ///
    void    setWidth( int );
    
    ///
    /// \brief update the width of the cell. 
    ///
    void    updateCellWidth();
    
    ///
    /// \brief make some part visible.  
    ///
    void    makeVisible(bool isDown);
    
    ///
    /// \brief set the cell of bottom.
    ///
    void    setBottomCell( int row );
    
    ///
    /// \brief get the new mark.
    ///
    void    newMark( int posx, int posy, bool copy=TRUE );
    
    ///
    /// \brief mark the word.  
    ///
    void    markWord( int posx, int posy );
    
    ///
    /// \brief extend the selected word.   
    ///
    void    extendSelectionWord( int &newX, int&newY);
    
    ///
    /// \brief  the class of char.
    ///
    int     charClass( QChar );
    
    ///
    /// \brief  turn the mark.
    ///
    void    turnMark( bool on );
    
    ///
    /// \brief  justify whether in mark.
    ///
    bool    inMark( int posx, int posy ) const;
    
    ///
    /// \brief justify whether before mark.  
    ///
    bool    beforeMark( int posx, int posy ) const;
    
    ///
    /// \brief justify whether after mark
    ///
    bool    afterMark( int posx, int posy ) const;
    
    ///
    /// \brief set the truncated position.
    ///
    int     setNumRowsAndTruncate();
    
    ///
    /// \brief get the offset. 
    ///
    int     getOffset(int row);
    
    ///
    /// \brief set the scroll bar start automaticly.  
    ///
    void    startAutoScroll();
    
    ///
    /// \brief stop the scroll bar start automaticly. 
    ///
    void    stopAutoScroll();
    
    ///
    /// \brief move the cursor left.  
    ///
    void    cursorLeft( bool mark, bool clear_mark, bool wrap );
    
    ///
    /// \brief move the cursor right.  
    ///
    void    cursorRight( bool mark, bool clear_mark, bool wrap );
    
    ///
    /// \brief move the cursor up
    ///
    void    cursorUp( bool mark, bool clear_mark );
    
    ///
    /// \brief move the cursor down 
    ///
    void    cursorDown( bool mark, bool clear_mark );
    
    ///
    /// \brief wrap a line.  
    ///
    void    wrapLine( int line, int removed = 0);
   
    void    wtleWrapLine( int line, int& w, int& nlines);
    void    qtWrapLine( int line, int&w, int& nlines );
 
    ///
    /// \brief break a paragraph.  
    ///
    void    rebreakParagraph( int line, int removed = 0 );
    
    ///
    /// \brief break all.  
    ///
    void    rebreakAll();
    
    ///
    /// \brief insert a string.  
    ///
    void    insertAtAux( const QString &s, int line, int col, bool mark = FALSE );
    
    ///
    /// \brief kill a line.
    ///
    void    killLineAux();
    
    ///
    /// \brief delete a charater.  
    ///
    void    delAux();
    
    ///
    /// \brief delete next charater.  
    ///
    void    deleteNextChar( int offset, int row, int col );
    
    ///
    /// \brief delete a word.  
    ///
    void    deleteWord();
    
    ///
    /// \brief add undo command.  
    ///
    void    addUndoCmd( ZMultiLineEditCommand* );
    
    ///
    /// \brief add redo command.  
    ///
    void    addRedoCmd( ZMultiLineEditCommand* );
    
    ///
    /// \brief process command.
    ///
    void    processCmd( ZMultiLineEditCommand*, bool );
    
    ///
    /// \brief  get the height of a line.  
    ///
    int getHeight() const;
    
    ///
    /// \brief get the width of a line.  
    ///
    int getWidth() const;
    
    ///
    /// \brief get the size of title.  
    ///
    QSize getTitleSize() const;
    
    ///
    /// \brief get the width of frame.  
    ///
    void getFrameWidth(int & nleft, int & nright, int & ntop, int & nbottom);
    
    ///
    /// \brief get the width of MD frame 
    ///
    void getMDFrameWidth(int & nleft, int & nright, int & ntop, int & nbottom);
    
    ///
    /// \brief get the font of skin.  
    ///
    void getSkinFont(QFont & font, QColor & color, TextType type) const;
    
    ///
    /// \brief update the skin.  
    ///
    void updateSkin(bool redraw);
    
    ///
    /// \brief get the line type.  
    ///
    LineType  lineType(const SelectionState state);
    
    ///
    /// \brief get the color of line.
    ///
    void lineColor(const SelectionState state, QColor & color);
    
    ///
    /// \brief get the pixmap.  
    ///
    QPixmap* getPixmap(const SelectionState state);
    
    ///
    /// \brief get the height of line  
    ///
    int lineHeight();
    
    ///
    /// \brief load a line pixmap. 
    ///
    QPixmap loadLinePixmap(const SelectionState state);
    
    ///
    /// \brief get the suffix name of line.  
    ///
    void getLinePixSuffixName(const SelectionState state, QString & suffix);
    
    ///
    /// \brief change the line type.  
    ///
    LineType changeToLineType(int lineTpye);
    
    ///
    /// \brief st the margin of view.  
    ///
    void setViewMarginsEx();
    
    ///
    /// \brief draw the under line.  
    ///
    void drawUnderLine(QPainter* p, int xBase, int yBase, int wDelta);
    
    ///
    /// \brief stretch the pixmap.  
    ///
    void stretchPixmap( QPixmap& pm, int width, int height, PIXMAP_STRETCH_POLICY_E type);
    
    ///
    /// \brief get font by the state.  
    ///
    void setStateFont(bool bChangeState = TRUE);
    
    ///
    /// \brief get the offset of cursor.  
    ///
    int getCursorOffset(int cursorRow, int cursorCol);
    
    ///
    /// \brief get the cursor positon.  
    ///
    void getCorsorPosition(int & cursorRow, int & cursorCol, int cursorOffset);
    
    ///
    /// \brief get the state of cursor.  
    ///
    int getCursorState();

    ///
    /// \brief judge if the text buffer is empty
    ///
    bool isTextEmpty() const;

#ifndef QT_NO_MIME
    ///
    /// \internal  
    ///
    QCString pickSpecial( QMimeSource* ms, bool always_ask, const QPoint& );
#endif
    
#ifndef QT_NO_WTLE

    ///
    /// \brief set editor to align automaticly.  
    ///
    void autoAlignment(TsLayout* layout, TsLayoutInfo &layoutInfo);
    
    ///
    /// \brief get the alignment of paragraph. 
    ///
    int getParaAlignment(void);
    
    ///
    /// \brief incalidate the text layout.  
    ///
    void invalidateTsLayout(int lineNo, bool andFollowing = FALSE);
    
    ///
    /// \brief prepare the text layout.  
    ///
    int prepareTsLayout(int lineNo); // return relative line
    
    ///
    /// \brief  get the index of cursor in the text layout.  
    ///
    int cursorToLayoutIndex(int relLine);
    
    ///
    /// \brief set the index of cursor in the text layout.  
    ///
    void layoutIndexToCursor(int index);
    
    ///
    /// \brief prepare the marked region.  
    ///
    QRegion prepareTsMarkRegion(int markLow, int markHigh, int offset, int row, int x, int y, int txtH, const QString & s);
    
    ///
    /// \brief get the font glyph region.  
    ///
    QRegion glyphRegion(const TsGlyphInfo & glinfo, int offset, int x, int y, int charBearing);

    ///
    /// \brief convert the relative position of cursor into logical position.  
    ///
    int	    xPosToCursorPos( int lineNo, int xPos );

    ///
    /// \brief judge the TsBidiCharClass is LTR mark.
    ///
    bool  isLTRM(TsBidiCharClass);

    ///
    /// \brief judge the TsBidiCharClass is Space.
    ///
    bool  isSpaceNeutral(TsBidiCharClass);

    ///
    /// \brief update cursor flag after deletion.
    ///
    void updateCursorFlagAfterBackspace(void);

    ///
    /// \brief temporary solution for multi-line wrap line issue under RTL environment
    ///
    void RTLWorkAround(int removed);

    ///
    /// \brief remove LTR or RTL mark
    ///
    void stripMarks(int line);

    ///
    /// \brief override line direction ( LTR or RTL )
    void overrideLineDirection(int line, eParaAlignment dir, int removed);
#endif

    ///
    /// scroll with omega event in non-edit state
    ///
    void handleOmgEvent(int key, int step);


#if defined(Q_DISABLE_COPY)
    ///
    /// Disabled copy constructor
    ///
    ZMultiLineEdit( const ZMultiLineEdit & );
    
    ///
    /// Disabled operator=
    ///
    ZMultiLineEdit &operator=( const ZMultiLineEdit & );
#endif

    ///
    /// Use Omega Wheel to scroll the text
    /// 
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
    int     curXPos;    // cell coord of cursor
    int     blinkTimer; // #### not used anymore - remove in 3.0
    int     scrollTimer; // #### not used anymore - remove in 3.0

#ifndef QT_NO_MOT_CURSOR_FLA    
    InitAutoAlign initAlign;
    CursorFlagExist cursFlag;
    CursorFlagDirection cursFlagDirection;
    InputContext inputContext;
#endif    

};
#endif // end Z_MULTILINE_H







