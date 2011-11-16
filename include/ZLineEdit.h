//Fix for E8/EM30 by Ant-ON, 25-10-2010

// Copyright (c) 07-Dec-2007 - 2008 Motorola, Inc. All rights reserved.

#ifndef __ZLINEEDIT_H__
#define __ZLINEEDIT_H__

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

///  \file    ZLineEdit.h
///  \brief   Defined the ZLineEdit class, which corresponds to Field and Password Field widget
///          in chameleon widget set.
///  
///   Created : 950126
///
///   Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
///
///   This file is part of the tools module of the Qt GUI Toolkit.
///
///   This file may be distributed under the terms of the Q Public License
///   as defined by Trolltech AS of Norway and appearing in the file
///   LICENSE.QPL included in the packaging of this file.
///
///   This file may be distributed and/or modified under the terms of the
///   GNU General Public License version 2 as published by the Free Software
///   Foundation and appearing in the file LICENSE.GPL included in the
///   packaging of this file.
///
///   Licensees holding valid Qt Enterprise Edition or Qt Professional Edition
///   licenses may use this file in accordance with the Qt Commercial License
///   Agreement provided with the Software.
///
///   This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
///   WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
///
///   See http://www.trolltech.com/pricing.html or email sales@trolltech.com for
///   information about Qt Commercial License Agreements.
///   See http://www.trolltech.com/qpl/ for QPL licensing information.
///   See http://www.trolltech.com/gpl/ for GPL licensing information.
///
///   Contact info@trolltech.com if any conditions of this licensing are
///   not clear to you.
///
//--------------------------------------------------------------------------------------------------
//                                       INCLUDE FILES
//--------------------------------------------------------------------------------------------------
#include "ZFormItem.h"
#include "qstring.h"
#include "ZSkinService.h"
#ifndef QT_NO_PUBLIC_INTERFACE
#include "ZKbInputField.h"
#endif // QT_NO_PUBLIC_INTERFACE

#ifndef QT_NO_WTLE
#include "tslayout.h"

#define LTR_MARK 0x200E;
#define RTL_MARK 0x200F;
#define isOdd(x) (x % 2)
#define isEven(x) (!(x % 2))
#endif

//--------------------------------------------------------------------------------------------------
//                                    FORWARD DECLARATIONS
//--------------------------------------------------------------------------------------------------
class ZLineEditPrivate;
class QValidator;
class ZScrollPanel; // Add by Ant-ON
//--------------------------------------------------------------------------------------------------
//                                   CLASS DEFINITIONS
//--------------------------------------------------------------------------------------------------

///  The class implements the field and password field.

///   The ZLineEdit widget is a one-line text editor.
///   A line edit allows the user to enter and edit a single line of
///   plain text, with a useful collection of editing functions, including
///   undo & redo, cut & paste, and drag & drop.
///   By changing the echoMode of a line edit it can also be used
///   as a "write-only" field, for inputs such as passwords.
///   The length of the field can be constrained to a maxLength(),
///   or the value can be arbitrarily constrained by setting a validator().
///   A closely related class is QMultiLineEdit which allows multi-line
///   editing.
///  
///   The default ZLineEdit object has its own frame as specified by the
///   Windows/Motif style guides, you can turn off the frame by calling
///   setFrame( FALSE ).
///  
///   The default key bindings are described in keyPressEvent().
///   A right-mouse-button menu presents a number of the editing commands
///   to the user.
///   If the user want to insert text from begin,selection or end,the relative
///   function is setInsertionMethod(int nSelection);
///  
///   Use setEchoModeWhenNofocus(EchoMode mode) and setEchoModeWhenHasFocus(EchoMode mode) to 
///   set the echo mode when the edit has focus or no focus.When call the function of
///   setEchoMode(EchoMode mode),the mode of has focus and no focus will be set.
///  
///   Use echoModeNoFocus() and echoModeHasFocus() to get the state when has focus and 
///   no focus.
///  
///   Use echoMode() to get the current mode.

class ZLineEdit : public ZFormItem
{
    Q_OBJECT
	
public:
//--------------------------------------------------------------------------------------------------
//                                    ENUMS
//--------------------------------------------------------------------------------------------------
   ///
   ///  \brief The enum type defines the relative position of title
   ///
   enum    TitlePosition
   {
       TitleTop,  ///< TitleTop The title is at the top-left corner of content area;
       TitleLeft  ///< TitleLeft The title is at the left-center of content area;
   };

   ///
   ///  \brief This enum type describes how ZLineEdit displays its
   ///        contents.  
   ///
   enum  EchoMode 
   {
        Normal,  ///<  Normal - display characters as they are entered.  This is the default
        NoEcho,  ///<  NoEcho - do not display anything. This may be appropriate
                 ///<           for passwords where even the length of the password should
                 ///<           be kept secret.
        Password ///<   Password - display asterisks instead of the characters
                 ///<              actually entered.
   };

   ///
   ///  \brief set the representing value when text entry should start within a field
   ///         The value may be:Begin,End and Selection.
   ///
   ///  \note  The default value is End.
   ///
   enum InsertionMethod
   {
        Begin,     ///< Selection, indicates that text should overwrite contents.
        End,       ///< Begin,     indicates that text should begin at the first position
        Selection  ///< End,       indicates that text should begin at the current last position
   };

#ifndef QT_NO_MOT_CURSOR_FLAG
   ///
   ///  \brief the direction of cursor flag.
   ///
   ///  \note  The default value is CF_RTL
   ///
   enum CursorFlagDirection 
   {
	CF_RTL,  ///< CF_RTL, when the layout mode is from right to left, the direction of cursor flag.
	CF_LTR   ///< CF_LTR, when the layout mode is from left to right, the direction of cursor flag.
   };

   ///
   ///  \brief the direction of cursor flag.
   ///
   ///  \note  The default value is CF_NONE.
   ///
   enum CursorFlagExist
   {
	CF_NONE,  ///<  CF_NONE no cursor flag. 
	CF_YES    ///<  CF_YES  has cursor flag.
    };

   ///
   ///  \brief 
   ///
   ///  \note  The default value is IC_NONE.
   ///
   enum InputContext
   {
        IC_NONE,      ///< IC_NONE
        IC_SCROLLING, ///< IC_SCROLLING
        IC_TEXT_INPUT ///< IC_TEXT_INPU
   };

   ///
   ///  \brief the initial alignment of cursor.
   ///
   ///  \note  The default value is CF_NONE.
   ///
   enum InitAutoAlign
   {
        AlignmentLeft,   ///< initial alignment left 
        AlignmentRight   ///< initial alignment right
   };
#endif
  
    ///
    /// \brief Constructs a line edit with no text.
    /// 
    /// The default maximum text length is set to 32767 characters.
    /// The parent and  name arguments are sent to the QWidget constructor.
    /// 
    /// \see The relative functions are:setText(), setMaxLength()
    ///
    ZLineEdit( QWidget *parent, const char *name=0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZLineEdit);
 
    ///
    /// \brief Constructs a line edit containing the text contents.
    ///
    /// The cursor position is set to the end of the line and the maximum text
    /// length to 32767 characters.
    /// The parent and  name arguments are sent to the QWidget constructor.
    /// 
    /// \see The relative function is text(), setMaxLength()
    ///

// use in ZPopup
// 	enableAia(true);
//	ZLineEdit *line = new ZLineEdit("lineEdit 1", this, 0,( ZSkinService::WidgetClsID)39);
//	insertChild(line);
//	line = new ZLineEdit("lineEdit 2", this, 0,( ZSkinService::WidgetClsID)39);
//	insertChild(line);

    ZLineEdit( const QString &, QWidget *parent, const char *name=0,
               const ZSkinService::WidgetClsID clsId = ZSkinService::clsZLineEdit);
 
    ///
    /// \brief Destructs the line edit.
    ///
    ~ZLineEdit();
   
    //================================================================================================
    ///
    /// \brief  get the content of the line without predicted text
    ///
    /// \return QString:: the text in the line.
    /// 
    /// \see The relative function is: setText()
    ///
    //================================================================================================
    QString text() const;

    //================================================================================================
    ///
    /// \brief  get the content of the line as is (including predicted text)
    ///
    /// \return QString:: the text in the line.
    /// 
    /// \see The relative function is: setText()
    ///
    //================================================================================================
    QString textWithPredict() const;

    //================================================================================================
    ///
    /// \brief  get the text that is displayed.
    /// This is normally the same as text(), 
    /// but can be e.g. "*********" if EchoMode is Password or
    /// "" if it is NoEcho.
    ///
    /// \return the text that is displayed. 
    /// 
    /// \see The relative function:setEchoMode() text() EchoMode
    ///
    //================================================================================================
    QString displayText() const;

    //================================================================================================
    ///
    /// \brief  convert the phone number text to the normal text
    ///
    /// \return the number text that is already filtered out pyphen
    ///
    /// \see ZLineEdit::text()
    ///
    //================================================================================================
    QString phonenoText() const;

    //================================================================================================
    ///
    /// \brief  get the value of the max length.
    ///
    /// \return the maximum permitted length of the text in the editor.
    /// 
    /// \see    The relative function:setMaxLength()
    ///
    //================================================================================================
    int  maxLength()	const;

    //================================================================================================
    ///
    /// \brief Set the maximum length of the text in the editor.  
    /// If the text is too long, it is chopped off at the limit. 
    /// Any marked text will be unmarked. 
    /// If the length of text is larger than the max length, the 
    /// cursor position is set to the position of the max length.
    /// 
    /// \see The relative function:maxLength().
    ///
    //================================================================================================
    virtual void setMaxLength( int );

    //================================================================================================
    ///
    /// \brief Set the displaying percentage of the font in the editor. 
    /// If the text is too long, it will truncate automaticly.
    /// 
    /// \see The relative function:setFont().
    ///
    /// \warning you must put the ZLineEdit::setFontPercent() after the methods as follow:
    /// ZLineEdit::setTitle(), ZLineEdit::setPalette(), Otherwise, it does not work.
    ///
    //================================================================================================
    virtual void setFontPercent(float rate);

    //================================================================================================
    ///
    /// \brief It is implmented for the searchbox widget. It shows a special background,
    ///           when the searched result is false. 
    ///
    /// \param   bool isNoMatchSearched, the searched result is False, it shows that it can not search the 
    ///                               related contents.
    ///
    //================================================================================================
    //void showBgForNoMatchSearchResult(bool isNoMatchSearched);

    //================================================================================================
    ///
    /// \brief set frame to the line editor.
    /// if enable is TRUE, Sets the line edit to draw itself inside a frame. 
    /// if enable is FALSE, draw itself without any frame. 
    /// The default is TRUE.
    /// The relative funtion: frame()
    ///
    /// \param enable The flag if that the line edit draw itself inside a frame
    ///
    //================================================================================================
    virtual void setFrame( bool enable );

    //================================================================================================
    ///
    /// \brief  get the state of frame
    /// \return TRUE if the line edit draws itself inside a frame,
    /// FALSE if it draws itself without any frame.
    /// The default is to use a frame.
    /// 
    /// \see The relative funtion:setFrame()
    ///
    //================================================================================================
    bool frame() const;
   
    //================================================================================================
    ///
    /// \brief Sets the echo mode of the line edit widget.
    /// The echo modes available are:
    /// Normal - display characters as they are entered.  This is
    ///	       the default.
    /// NoEcho - do not display anything. This may be appropriate
    ///          for passwords where even the length of the password should
    ///          be kept secret. 
    /// Password - display asterisks instead of the characters
    ///           actually entered.
    /// The widget's display, and the ability to copy or drag the
    /// text is affected by this setting.
    /// 
    /// \param mode The value of echo mode.
    ///
    /// \see The relative funtion: echoMode() EchoMode displayText()
    ///
    //================================================================================================
    virtual void setEchoMode( EchoMode mode);

    //================================================================================================
    ///
    /// \brief  get the echo mode of the line editor.
    ///
    /// \return the current echo mode of the line edit.
    /// 
    /// \see    The relative funtion: setEchoMode() EchoMode
    ///
    //================================================================================================
    ZLineEdit::EchoMode echoMode() const;

    //================================================================================================
    ///
    /// \brief  get the position of title
    ///
    /// \return current title position
    /// 
    /// \see    ZLineEdit::setTitlePosition
    /// 
    /// \note   refer to enum TitlePosition {TitleTop, TitleLeft};   
    ///
    //================================================================================================
    TitlePosition titlePosition() const {return mTitlePos;}

    //================================================================================================
    ///
    /// \brief  Set title position
    ///
    /// \param  titlePos
    ///         please refer to refer to enum TitlePosition {TitleTop, TitleLeft};
    /// 
    /// \see     ZLineEdit::titlePosition()
    ///
    //================================================================================================
    void setTitlePosition(TitlePosition titlePos);

    //================================================================================================
    ///
    /// \brief  get the text of title.
    ///
    /// \return current title, if no title, return QString::null
    ///
    /// \see    ZLineEdit::setTitle() 
    ///
    //================================================================================================
    QString title() const {return mTitle;}

    //================================================================================================
    ///
    /// \brief Set ZLineEdit title. 
    /// if string.isEmpty() is true, the ZLineEdit has no title,
    /// ZLineEdit is normal style, or ZLineEdit displays in the form item style.
    ///
    /// \param  titleStr, the text of the title.
    ///
    //================================================================================================
    void setTitle(const QString & titleStr);
    
#if QT_VERSION >= 300
#error "Make setReadOnly virtual"
#endif

    //================================================================================================
    ///
    /// \brief Enables or disables read-only mode.
    /// where the user can cut-and-paste
    /// or drag-and-drop the text, but cannot edit it.
    /// They never see a cursor in this case.
    ///
    /// \param enable The flag if the line edit is readonly.
    ///
    /// \see The relative funtion:setEnabled(), isReadOnly()
    ///
    //================================================================================================
    void setReadOnly( bool enable);
   
    //================================================================================================
    ///
    /// \brief judge the property of read only in the line editor  
    ///
    /// \return whether the line-edit is read-only.
    /// 
    /// \see The relative funtion: setReadOnly()
    ///
    //================================================================================================
    bool isReadOnly() const;

    //================================================================================================
    ///
    /// \brief Sets this line edit to accept input only as accepted.
    /// Sets this line edit to accept input only as accepted by v,
    /// allowing arbitrary constraints on the text which the user can edit.
    /// If  v == 0, remove the current input validator.  The default
    /// is no input validator (ie. any input is accepted up to maxLength()).
    ///
    /// \param v The pointer of the validator.
    ///
    /// \see  The relative funtion: validator() QValidator
    ///
    //================================================================================================
    virtual void setValidator( const QValidator *v );

    //================================================================================================
    ///
    /// \brief  get the validator which has set to the line editor.
    ///
    /// \return a pointer to the current input validator, or 0 if no
    /// validator has been set.
    /// 
    /// \see The relative funtion:setValidator()
    ///
    //================================================================================================
    const QValidator* validator() const;

    //================================================================================================
    ///
    /// \brief  get a recommended size of the widget      
    ///
    /// \return  a recommended size for the widget.
    /// The width returned is enough for a few characters, typically 15 to 20.
    ///
    /// \note    Reimplemented from QWidget.
    ///
    /// \see     ZLineEdit::minimumSizeHint(), ZLineEdit::sizePolicy()
    ///
    //================================================================================================
    QSize	sizeHint() const;

    //================================================================================================
    ///
    /// \brief  get a minimum size of the widget      
    ///
    /// \return a minimum size for the line edit.
    /// The width returned is enough for at least one character.
    ///
    /// \note    Reimplemented from QWidget.
    ///
    /// \see     ZLineEdit::sizeHint(), ZLineEdit::sizePolicy()
    ///
    //================================================================================================
    QSize	minimumSizeHint() const;
 
    //================================================================================================
    ///
    /// \brief  get the policy of resize the widget's size.      
    ///
    /// \return the policy of resize the widget's size.
    /// 
    /// \note    Reimplemented from QWidget.
    ///
    /// \see     ZLineEdit::sizeHint(), ZLineEdit::minumumSizeHint()
    ///
    //================================================================================================
    QSizePolicy sizePolicy() const;

    //================================================================================================
    ///
    /// \brief set the font of the text in the line editor.
    /// 
    /// \note Reimplemented from QWidget.
    ///
    /// \see ZLineEdit::setFontPercent()
    ///
    //================================================================================================
    virtual void setFont( const QFont & );

    //================================================================================================
    ///
    /// \brief Sets the marked area of this line edit to start at start and
    /// be length characters long. 
    ///
    /// \param start The start position
    ///
    /// \param length The length characters long
    ///
    /// \see  ZLineEdit::getSelection 
    ///
    //================================================================================================
    virtual void setSelection( int start, int length);
    
#ifndef QT_NO_MOT_CURSOR_FLAG
    //================================================================================================
    ///
    /// \brief Sets the direction of the cursor flag for this line edit and
    ///        repaints accordingly.  
    ///
    ///
    /// \note   enum CursorFlagDirection 
    ///          {
    ///	               CF_NONE,
    ///	               CF_RTL,
    ///                CF_LTR
    ///         };
    ///
    /// \see The relative funtion: ZLineEdit::cursorPosition()
    ///
    //================================================================================================
    void setCursorFlagDirection(CursorFlagDirection d);
   
    //================================================================================================
    ///
    /// \brief Sets the initial alignment.
    ///
    //================================================================================================ 
    void setInitAutoAlign(InitAutoAlign align);

    //================================================================================================
    ///
    /// \brief Sets the status of cursor flag.
    ///
    //================================================================================================
    void setCursorFlagExist(CursorFlagExist d); 

    //================================================================================================
    ///
    /// \brief the input method gets the bottom of all view rect.
    ///
    //================================================================================================
    int  heightViewed() const;    
private:
    void scrollN(QKeyEvent* e);

    InitAutoAlign initAlign;
    CursorFlagExist cursFlag;
    CursorFlagDirection cursFlagDirection;
    InputContext inputContext;

public:
#endif

    //================================================================================================
    ///
    /// \brief Sets the cursor position for this line edit to newPos and
    ///        repaints accordingly. 
    ///
    /// \param newPos The cursor position of the line edit
    /// 
    /// \see  The relative funtion: cursorPosition()
    ///
    //================================================================================================
    virtual void setCursorPosition( int newPos );

    //================================================================================================
    ///
    /// \brief get the current logic cursor position of this line edit.
    ///
    /// \return the current cursor position for this line edit.  
    ///
    /// \see setCursorPosition() 
    ///
    //================================================================================================
    int cursorPosition() const;

    //================================================================================================
    ///
    /// \brief Validates and perhaps sets this line edit to contain newText
    ///        with the cursor at position newPos, with marked text from
    ///        newMarkAnchor to newMarkDrag.
    /// Linebreaks in  newText are converted to spaces, and it is
    /// truncated to maxLength() before testing its validity.
    /// Repaints and emits textChanged() if appropriate.
    ///
    /// \param newText The new text that that set the line edit.
    ///
    /// \param newPos The new postion of the cursor
    ///
    /// \param newMarkAnchor The new mark anchor
    ///
    /// \param newMarkDrag The new mark drag
    ///
    /// \return TRUE if it changes the line edit and FALSE if it doesn't.
    ///
    //================================================================================================
    bool validateAndSet( const QString &newText, int newPos, int newMarkAnchor, int newMarkDrag);

#ifndef QT_NO_CLIPBOARD
    //================================================================================================
    ///
    /// \brief Copies the marked text to the clipboard and deletes it,
    /// if there is any.
    /// If the current validator disallows deleting the marked text, cut()
    /// will copy it but not delete it.
    /// 
    /// \see The relative funtion: copy() paste()
    ///
    //================================================================================================
    void cut();
   
    //================================================================================================
    ///
    /// \brief Copies the marked text to the clipboard, 
    /// if there is any and if echoMode() is Normal.
    ///
    /// \see   The relative funtion:cut() paste()
    ///
    //================================================================================================
    void copy() const;

    //================================================================================================
    ///
    /// \brief Inserts the clipboard's text at the cursor position, deleting any
    ///        previous marked text.
    /// If the end result is not acceptable for the current validator,
    /// nothing happens.
    /// 
    /// \see  The relative funtion: copy() cut()
    ///
    //================================================================================================
    void paste();
#endif
     
    //================================================================================================  
    ///
    /// \brief Sets the alignment of the line edit. 
    /// Possible Values are Qt::AlignLeft,
    /// Qt::AlignRight and Qt::Align(H)Center - see Qt::AlignmentFlags.
    ///
    /// \param flag The value of alignment.
    /// 
    /// \see  The relative funtion: alignment()
    ///
    //================================================================================================
    void setAlignment( int flag );

    //================================================================================================
    ///
    /// \brief  get the alignment of the line edit.
    /// Possible Values are:
    /// Qt::AlignLeft, Qt::AlignRight and Qt::Align(H)Center.
    ///  
    /// \return the alignment of the line edit. 
    ///       
    /// \see    The relative funtion: setAlignment(), Qt::AlignmentFlags
    ///
    //================================================================================================
    int alignment() const;

#ifndef QT_NO_WTLE
    //================================================================================================
    ///
    /// \brief Moves the cursor leftwards one or more characters.
    ///
    /// \param mark The flag if the text will be marked.
    /// 
    /// \see   The relative funtion:cursorRight()
    ///
    //================================================================================================
    void cursorLeft( bool mark);
    
    //================================================================================================
    ///
    /// \brief Moves the cursor rightwards one or more characters.
    ///
    /// \param mark The flag if the text will be marked.
    /// 
    /// \see   The relative funtion:cursorLeft()
    ///
    //================================================================================================
    void cursorRight( bool mark);
#else
    //================================================================================================
    ///
    /// \brief Moves the cursor leftwards one or more characters.
    ///
    /// \param mark The flag if the text will be marked.
    ///
    /// \param steps The step of the text will be marked.
    /// 
    /// \see   The relative funtion:cursorRight()
    ///
    //================================================================================================
    void cursorLeft( bool mark, int steps = 1 );
    
    //================================================================================================
    ///
    /// \brief Moves the cursor rightwards one or more characters.
    ///
    /// \param mark The flag if the text will be marked.
    ///
    /// \param steps The step of the text will be marked.
    /// 
    /// \see   The relative funtion:cursorLeft()
    ///
    //================================================================================================
    void cursorRight( bool mark, int steps = 1 );
#endif

    //================================================================================================
    ///
    /// \brief delete character in Arabic .
    ///
    //================================================================================================
    void        backspaceNew();
 
    //================================================================================================ 
    ///
    /// \brief Moves the cursor rightwards one or more characters.
    ///
    /// \param mark  the flag if the text will be marked.
    ///
    /// \param cp    the new logic cursor position.
    ///
    /// \see The relative funtion:cursorLeft(), cursorRight().
    ///
    //================================================================================================
    void cursorRightFinish( bool mark, int cp );

    //================================================================================================
    ///
    /// \brief Moves the cursor one word to the right.  
    /// If  mark is TRUE, the text is marked.
    ///
    /// \param mark The flag if the text will be marked.
    ///
    /// \see   The relative funtion:cursorWordBackward()
    ///
    //================================================================================================
    void  cursorWordForward( bool mark );
  
    //================================================================================================
    ///
    /// \brief Moves the cursor one word to the left.  
    /// If  mark is TRUE, the text is marked.
    ///
    /// \param mark The flag if the text will be marked.
    ///
    /// \see   The relative funtion:cursorWordForward()
    ///
    //================================================================================================
    void  cursorWordBackward( bool mark );

    //================================================================================================
    ///
    /// \brief Deletes the character to the left of the text cursor and moves the
    ///        cursor one position to the left.
    /// If a text has been marked by the user (e.g. by clicking and dragging) 
    /// the cursor will be put at the beginning of the marked text 
    /// and the marked text will be removed.  
    /// 
    /// \see The relative funtion: del()
    ///
    //================================================================================================
    void  backspace();

    //================================================================================================
    ///
    /// \brief Deletes the character on the right side of the text cursor. 
    /// If a text has been marked by the user (e.g. by clicking and dragging)
    /// the cursor will be put at the beginning of the marked text and
    /// the marked text will be removed. 
    /// 
    /// \see  The relative funtion: backspace()
    ///
    //================================================================================================
    void  del();

    //================================================================================================
    ///
    /// \brief Moves the text cursor to the left end of the line. 
    /// If mark is TRUE text will be marked towards the first position, 
    /// if not any marked text will be unmarked if the cursor is moved.
    ///
    /// \param mark The flag if the text will be marked towards the first position.
    /// 
    /// \see   The relative funtion:end()
    ///
    //================================================================================================
    void home( bool mark );

    //================================================================================================
    ///
    /// \brief Moves the text cursor to the right end of the line. 
    /// If mark is TRUE text will be marked towards the last position, 
    /// if not any marked text will be unmarked if the cursor is moved.
    ///
    /// \param mark The flag if the text will be marked towards the last position.
    /// 
    /// \see The relative funtion: home()
    ///
    //================================================================================================
    void  end( bool mark );

    //================================================================================================
    ///
    /// \brief Sets the edited flag of this line edit to  on.  
    /// The edited flag
    /// is never read by ZLineEdit, and is changed to TRUE whenever the user
    /// changes its contents.
    /// This is useful e.g. for things that need to provide a default value,
    /// but cannot find the default at once.  Just open the line edit without
    /// the best default and when the default is known, check the edited()
    /// return value and set the line edit's contents if the user has not
    /// started editing the line edit.
    ///
    /// \param on The flag of the field if it is editted.  
    ///
    /// \see The relative funtion: edited()
    ///
    //================================================================================================
    void  setEdited( bool on);

    //================================================================================================
    ///
    /// \brief  get the edited flag of the line edit.
    /// If this returns FALSE, the line edit's contents have not been
    /// changed since the construction of the ZLineEdit 
    /// (or the last call to either setText() or setEdited( FALSE ),
    /// if any).  If it returns true, the contents have been edited, or
    /// setEdited( TRUE ) has been called.
    /// 
    /// \return the edited flag of the line edit.  
    /// 
    /// \see    The relative funtion: setEdited()
    ///
    //================================================================================================
    bool  edited() const;

    //================================================================================================
    ///
    /// \brief  judge whether part of the text has been marked by the user
    ///
    /// \return TRUE if part of the text has been marked by the user (e.g. by
    /// clicking and dragging).
    /// 
    /// \see    The relative function:markedText()
    ///
    //================================================================================================
    bool  hasMarkedText() const;

    //================================================================================================
    ///
    /// \brief  get the text marked by the user
    /// 
    /// \return the text marked by the user (e.g. by clicking and
    /// dragging), or a QString::operator!() null string
    /// if no text is marked.
    /// 
    /// \see The relative function:hasMarkedText()
    ///
    //================================================================================================
    QString  markedText() const;

#if defined(Q_INCOMPATIBLE_3_0_ADDONS)
    //================================================================================================
    ///
    /// \brief get the marked area of this line edit to start at start and
    /// be length characters long. 
    ///
    /// \param start The start position
    ///
    /// \param length The length characters long
    ///
    /// \see  ZLineEdit::setSelection 
    ///
    //================================================================================================
    bool 	getSelection( int *start, int *end );
    
    //================================================================================================
    ///
    /// \brief set the disaplayed char which represents the password char.
    ///  
    /// \param QChar c, the displayed char of the password char.
    ///
    /// \see  ZLineEdit::passwordChar 
    ///
    //================================================================================================
    void 	setPasswordChar( QChar c );
    
    //================================================================================================
    ///
    /// \brief get the disaplayed char which represents the password char.
    /// 
    /// \see  ZLineEdit::setPasswordChar
    ///
    //================================================================================================
    QChar 	passwordChar() const;
#endif
      
    //================================================================================================
    ///
    /// \brief set the offset of the cursor.
    ///
    /// \note reimplement from qt.
    ///     
    //================================================================================================
    void setOffsetCursor(bool on);

      
#ifndef QT_NO_PUBLIC_INTERFACE
    //================================================================================================
    ///
    /// \brief get a pointer of ZKbInputField.
    ///
    //================================================================================================
    ZKbInputField  *getInputField();
     
    //================================================================================================
    ///
    /// \brief emit a textchange() signal.
    ///
    /// \see siganl:textChanged()
    /// 
    //================================================================================================
    void  emitTextChanged();
 

 
    //================================================================================================
    ///
    /// \brief calculate the logic position of cursor.
    ///
    /// \see ZLineEdit::cursorPoint()
    /// 
    //================================================================================================
    int  calCursorPos( int col , int len );
 
    //================================================================================================
    ///
    /// \brief calculate the relative position of cursor.
    ///
    /// \see ZLineEdit::calCursorPos()
    ///
    //================================================================================================  
    QPoint  cursorPoint();
     
#endif // QT_NO_PUBLIC_INTERFACE

    //================================================================================================
    ///
    /// \brief Set the pixel width of the field.
    ///
    /// \param nWidth The value of the pixel width
    ///
    /// \see   the relatived function:getPreferredWidth() 
    ///
    //================================================================================================
    void setPreferredWidth(int nWidth);
   
    //================================================================================================
    ///
    /// \brief get the pixel width of the field.
    ///
    /// \see   the relatived function:setPreferredWidth() 
    ///
    //================================================================================================
    int  getPreferredWidth() const;

    //================================================================================================
    ///
    /// \brief When the mode of the field is Password,it should represent 
    ///        a predefined number of /// mask characters.
    /// Example:if the password value is 5 characters and the presentmask
    /// is 8,then 8 characters mask characters
    /// will be displayed to the user,even though the actual password is only 5 characters.
    ///
    /// \see the relatived function: getPredefinedNumbers()
    ///
    //================================================================================================
    void setPredefinedNumbers(int nCount);
 
    //================================================================================================
    ///
    /// \brief get the predefined number of /// mask characters.
    ///
    /// \see   the relatived function: setPredefinedNumbers()
    ///
    int  getPredefinedNumbers( ) const;

    //================================================================================================
    ///
    /// \brief get the flag of auto resize properties.
    ///
    /// \see   the relatived function: setAutoResize()
    ///
    //================================================================================================
    bool autoResize () const;
 
    //================================================================================================
    ///
    /// \brief set the flag of auto resize properties.
    ///
    /// \see   the relatived function: autoResize()
    ///
    //================================================================================================
    void setAutoResize ( bool enable );

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
    void setInsertionMethod( enum InsertionMethod nSelection );

    //================================================================================================
    ///
    /// \brief set the echo mode when the edit no focus,it is only for VODAFONE
    /// The echo modes available are:
    /// Normal - display characters as they are entered.  This is
    ///	       the default.
    /// NoEcho - do not display anything. This may be appropriate
    ///          for passwords where even the length of the password should
    ///          be kept secret. 
    /// Password - display asterisks instead of the characters
    ///           actually entered.
    ///
    /// \param mode The echo mode value
    ///
    ///  \see the relatived function: echoModeNoFocus()
    ///
    //================================================================================================
    void setEchoModeWhenNoFocus( EchoMode  mode );

    //================================================================================================
    ///
    /// \brief set the echo mode when the edit has focus,it is only for VODAFONE
    /// The echo modes available are:
    /// Normal - display characters as they are entered.  This is
    ///	       the default.
    /// NoEcho - do not display anything. This may be appropriate
    ///          for passwords where even the length of the password should
    ///          be kept secret. 
    /// Password - display asterisks instead of the characters
    ///           actually entered.
    ///
    /// \param mode The echo mode value
    ///
    //================================================================================================
    void setEchoModeWhenHasFocus( EchoMode  mode );

    //================================================================================================
    ///
    /// \brief  get the echo mode of the line edit when no focus.
    ///
    /// \return the echo mode of the line edit when no focus.It is only for VODAFONE
    ///
    /// \see the relatived function: setEchoModeWhenNoFocus()
    ///
    //================================================================================================
    ZLineEdit::EchoMode echoModeNoFocus() const;

    //================================================================================================
    ///
    /// \brief  get the echo mode of the line edit when focus.
    ///
    /// \return the echo mode of the line edit when focus.It is only for VODAFONE
    ///
    /// \see the relatived function: setEchoModeWhenHasFocus()
    ///
    //================================================================================================
    ZLineEdit::EchoMode echoModeHasFocus() const;

    //================================================================================================
    ///
    /// \brief set the Enable and disable status to the line editor.
    ///
    /// \see the relatived fuction: isZEnabled(), isZDisabled().
    ///
    //================================================================================================
    virtual void setEnabled(bool enable);
  
    //================================================================================================
    ///
    /// \brief judge whether the Enable status in the line editor.
    ///
    /// \see the relatived fuction: setEnabled(), isZDisabled().
    ///
    //================================================================================================
    bool isZEnabled();
  
    //================================================================================================
    ///
    /// \brief judge whether the disable status in the line editor.
    ///
    /// \see the relatived fuction: isZEnabled(), setEnabled().
    ///
    //================================================================================================
    bool isZDisabled();
  
    //================================================================================================
    ///
    /// \brief wrap the text.
    /// 
    //================================================================================================
    QStringList wrapText(QString,int);

#ifndef QT_NO_WTLE
    //================================================================================================
    ///
    /// \brief special cursor mode.
    /// 
    //================================================================================================
    void specialInputModeCursorModel(bool);

    //================================================================================================
    ///
    /// \brief set the cursor mode of input mode
    /// 
    //================================================================================================
    void setInputModeCursorModel(int);

    //================================================================================================
    ///
    /// \brief get the cursor mode of input mode
    /// 
    //================================================================================================
    int  getInputModeCursorModel(void);

#endif //end QT_NO_WTLE

public slots:
    //================================================================================================
    ///
    /// \brief Sets the line edit text to  text, 
    ///        clears the selection and moves
    /// the cursor to the end of the line.
    /// If necessary the text is truncated to maxLength().
    ///
    /// \param text The text that will be set.
    ///
    /// \see The relatived function is text()
    ///
    //================================================================================================
    virtual void setText( const QString &text);

    //================================================================================================
    ///
    /// \brief Selects all text (i.e. marks it) and 
    ///        moves the cursor to the end. 
    /// This is useful when a default value has been inserted,
    /// since if the user types before clicking on the widget the
    /// selected text will be erased.
    ///
    /// \see the relatived function: deselect().
    ///
    //================================================================================================
    void  selectAll();

    //================================================================================================
    ///
    /// \brief Deselects all text (i.e. removes marking) and leaves the cursor at the
    ///        current position.
    ///
    /// \see   the relatived function: selectAll().
    ///
    //================================================================================================
    void  deselect();

    //================================================================================================
    /// 
    /// \brief This slot is equivalent to setValidator( 0 ). 
    ///
    /// \see the relatived function: setValidator()
    ///
    //================================================================================================
    void  clearValidator();
  
    //================================================================================================
    ///
    /// \brief insert a string into the current cursor postion.
    ///
    /// \see the relatived function: del(), backspace().
    ///
    //================================================================================================
    void insert( const QString &);

    //================================================================================================
    ///
    /// \brief insert a string, when the language is Arabic.
    ///
    //================================================================================================
    void        insertNew( const QString &);
    
    //================================================================================================
    ///
    /// \brief judge TsBidiCharClass is LTR Bidi.
    ///
    //================================================================================================
    bool     isLTRBidiClass(TsBidiCharClass);
    
    //================================================================================================
    ///
    /// \brief judge TsBidiCharClass is RTL Bidi.
    ///
    //================================================================================================
    bool     isRTLBidiClass(TsBidiCharClass);

    //================================================================================================
    ///
    /// \brief judge TsBidiCharClass is Number Bidi.
    ///
    //================================================================================================
    bool     isNumericBidiClass(TsBidiCharClass);
    
    //================================================================================================
    ///
    /// \brief judge TsBidiCharClass is Neutral Bidi.
    ///
    //================================================================================================ 
    bool     isNeutralBidiClass(TsBidiCharClass); 

    //================================================================================================
    ///
    /// \brief Syntactic sugar for setText( "" ), provided 
    ///        to match no-argument signals.
    ///
    //================================================================================================
    void  clear();

signals:
    ///
    /// \brief when the text is modified, not the state is changed,
    /// the textChanged signal will emit.
    ///
    void  textChanged( const QString &);

    ///
    /// \brief when the keyword text changes, not include the tempory text.
    /// the confirmedTextChanged signal will emit.
    ///
    void committedTextChanged( const QString &keyword);

    ///
    /// \brief the signal of return pressed.
    ///
    void  returnPressed();

#ifndef QT_NO_PUBLIC_INTERFACE
    ///
    /// \brief the signal of cursor changed.
    ///
    void cursorChanged(int cursorX, int cursorY);
#endif /* end the QT_NO_PUBLIC_INTERFACE*/ 

protected:
    ///
    /// \brief type ItemType define the different area of the widget.
    ///
    /// The button supports the two style widget: 
    ///  1: The normal widget The button has no title.
    ///  2: FormItem widget The button has a title. So the widget is composed of
    ///  three parts: FormItem, Label and Widget.
    ///      FormItem: the part includes the whole area, it ownes the skin of ForItem.
    ///      Label:    the part is title area, it displays widget title, it ownes the 
    ///                skin of Label.
    ///      Widget:   the part is the widget area, it appears like a real button, it 
    ///                ownes the skin of button.
    ///
    /// \param ForItem It indicates the button is now dealing with FormItem area.
    ///
    /// \param Label   It indicates the button is now dealing with title area.
    ///
    /// \param Widget  It indicates the button is now dealing with widget area.
    /// 
    enum ItemType
    {
       FormItem,
       Label,
       Widget
    };

    ///
    /// \brief type StateChangeReason define the reasons of state change.
    ///
    enum StateChangeReason
    {
       RFocusIn,
       RFocusOut,
       RKeyPress,
       RKeyRelease
    };
    
    ///
    ///  \brief event filter 
    ///
    bool  event( QEvent * );
    
    ///
    ///  \brief accept the mouse press event.  
    ///
    void  mousePressEvent( QMouseEvent * );
    
    ///
    ///  \brief accept the mouse move event.
    ///
    void  mouseMoveEvent( QMouseEvent * );
    
    ///
    ///  \brief accept the mouse release event.  
    ///
    void  mouseReleaseEvent( QMouseEvent * );
    
    ///
    ///  \brief accept the mouse double click event.
    ///
    void  mouseDoubleClickEvent( QMouseEvent * );
    
    ///
    ///  \brief accept the keypress event.
    ///
    void  keyPressEvent( QKeyEvent * );
    
    ///
    ///  \brief dispose the foucs in event. 
    ///
    void  focusInEvent( QFocusEvent * );
    
    ///
    ///  \brief dispose the foucs out event.
    ///
    void  focusOutEvent( QFocusEvent * );
    
    ///
    ///  \brief paint Event. Mainly paint are finished in it.
    ///
    void  paintEvent( QPaintEvent * );
    
    ///
    ///  \brief accept resize event.
    ///
    void  resizeEvent( QResizeEvent * );
       
    ///
    ///  \brief accept the leave event.
    ///
    void  leaveEvent( QEvent * );
           
    ///
    ///  \brief get the titel size.
    ///
    QSize  getTitleSize() const;
           
    ///
    ///  \brief the rect contains the title.
    ///
    QRect  getTitleRect() const;
           
    ///
    ///  \brief get the editor area, not include padding.
    ///
    QRect  getEditAreaRect() const;
           
    ///
    ///  \brief get the content area, not include padding.
    ///
    QRect  getContentRect() const;
           
    ///
    ///  \brief get the width of content area.
    ///
    int  getContentWidth() const;
           
    ///
    ///  \brief get the heigth of content area.
    ///
    int  getContentHeight() const;
           
    ///
    ///  \brief get the width of padding.
    ///
    int  getPaddingWidth() const;
           
    ///
    ///  \brief get the height of padding.
    ///
    int  getPaddingHeight() const;
           
    ///
    ///  \brief get the field Rect not include title, include padding.
    ///
    QRect  getFieldRect() const;
           
    ///
    ///  \brief when state changed, it will be invoked.
    ///
    void  stateChanged(StateChangeReason stChangeReason);
           
    ///
    ///  \brief change the title.
    ///
    void  titleChanged(const QString & title);
           
    ///
    ///  \brief get the current font.
    ///
    void  getCurrentFont(QFont & font, QColor & ftColor, ItemType itemType) const;
           
    ///
    ///  \brief get frame width.
    ///
    void  getFrameWidth(int & nleftw, int & nrightw, int & ntopw, int & nbottomw) const;
           
    ///
    ///  \brief update the properties of skin.
    ///
    void  updateSkin(bool redraw);
           
    ///
    ///  \brief  set the palette.
    ///
    virtual void setPalette(const QPalette &);

           
    ///
    ///  \brief  repaint a certain area.
    ///
    void  repaintArea( int, int );
           
    ///
    ///  \brief the offset of line.
    ///
    int  offset;		// moved here by Dong Feng

private slots:
           
    ///
    ///  \brief when clipboard is changed, it will be invoked.
    ///
    void  clipboardChanged();
           
    ///
    ///  \brief when cursor blinks, it will be invoked.
    ///
    void  blinkSlot();
           
    ///
    ///  \breif when draging the scroll bar, it will be invoked.
    ///
    void  dragScrollSlot();
           
    ///
    ///  \brief when fast delete, it must wait the timer out. 
    ///
    void  fastDelTimerTimeout();

private:
    ///
    /// \brief In search box, It can not set the suitable string, It will use
    ///        this function to draw a special background.
    ///        
    //void drawNoMatchBackgournd(QPainter& p);          
 
    ///
    ///  \brief  get the new mark position.
    ///
    void  newMark( int pos, bool copy=TRUE );
    
    ///
    ///  \brief mark a word on a certain position.
    ///
    void  markWord( int pos );
               
    ///
    ///  \brief get the index of last visible char.
    ///
    int  lastCharVisible() const;
               
    ///
    ///  \brief get the min mark.
    ///
    int  minMark() const;
               
    ///
    ///  \brief get the max mark.
    ///
    int  maxMark() const;
               
    ///
    ///  \brief get the frame width.
    ///
    int  frameW() const;
#ifndef QT_NO_QWS_IM
               
    ///
    ///  \brief accept the input method start event.
    ///
    void  imStartEvent( QIMEvent * );
               
    ///
    ///  \brief accept the input method compose event.
    ///
    void  imComposeEvent( QIMEvent * );
               
    ///
    ///  \brief accept the input method end event.
    ///
    void  imEndEvent( QIMEvent * );
               
    ///
    ///  \brief get the compose mode.
    ///
    bool composeMode() const;
#endif    
               
    ///
    ///  \brief initial the properties of line editor.
    ///
    void  init();
    
#ifndef QT_NO_WTLE
               
    ///
    ///  \brief give the line editor alignment automaticly. 
    ///
    void autoAlignment();
               
    ///
    ///  \brief when the text change, it will be invoked.
    ///
    void tbufChange();
               
    ///
    ///  \brief get the width of displayed text 
    ///
    int displayTextWidth(int partial = FALSE, int b = 0, int len = 0);
               
    ///
    ///  \brief get the region of mark region.
    ///
    QRegion prepareTsMarkRegion(int markLow, int markHigh, int offset, int hAdd, int y, const QString & s);
               
    ///
    ///  \brief get the font glyph region.
    ///
    QRegion glyphRegion(const TsGlyphInfo & glinfo, int offset, int y);
#endif
               
    ///
    ///  \brief update the offset of the first character.
    ///
    void updateOffset();
               
    ///
    ///  \brief according the logic position, get the relative position.
    ///
    int xPosToCursorPos( int ) const;
               
    ///
    ///  \brief cursor blinks on. 
    ///
    void blinkOn();
               
    ///
    ///  \brief make a pixmap.
    ///
    void makePixmap() const;
               
    ///
    ///  \brief undo event.
    ///
    void undoInternal();
               
    ///
    ///  \brief redo event.
    ///
    void redoInternal();
               
    ///
    ///  \brief set the echo mode of line editor.
    ///
    void setMode(EchoMode mode);
    
    ///	
    /// Disabled copy constructor and operator=
    ///
#if defined(Q_DISABLE_COPY)
    ZLineEdit( const ZLineEdit & );
    ZLineEdit &operator=( const ZLineEdit & );
#endif
    ///
    /// \brief this function reuturn the width of the under line 
    ///
    int getUnderlineWidth() const;

    ///
    /// \breif this function reuturn the height of the alter icon that is the height of down arrow.
    ///
    int getAlterIconHeight() const;

    QString	tbuf;
    ZLineEditPrivate* d;
    int  cursorPos;
    int  maxLen;
    int  markAnchor;
    int  markDrag;
    bool  cursorOn;
    bool  dragScrolling;
    bool  scrollingLeft;
#ifndef QT_NO_MOT_ALIGN_AUTO
    bool  alignmentAuto;
#endif
    int  alignmentFlag;
    bool  ed;
    bool  offsetCursor; //Zhou Dengxiang add
    QString mTitle;
    TitlePosition mTitlePos;
    int  m_nSelection;
    bool isPasswordSelection;
  
//Add by Ant-ON 
public:
    void ensureDisplayed();
    int  getRealMaxLen() const;
    bool isHyphenAuto() const;
    void setScrollParent(ZScrollPanel *);
//
};
#endif // __ZLINEEDIT_H__
