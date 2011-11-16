
/*
 * Copyright (C) 2007 Motorola Inc.
 *
 * Date         Author         Comment
 * 09/25/07     Motorola       Motorola customization.
*/

/**********************************************************************
** $Id: qt/src/widgets/qlineedit.h   2.3.8   edited 2004-08-05 $
**
** Definition of QLineEdit widget class
**
** Created : 941011
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of the widgets module of the Qt GUI Toolkit.
**
** This file may be distributed under the terms of the Q Public License
** as defined by Trolltech AS of Norway and appearing in the file
** LICENSE.QPL included in the packaging of this file.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** Licensees holding valid Qt Enterprise Edition or Qt Professional Edition
** licenses may use this file in accordance with the Qt Commercial License
** Agreement provided with the Software.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.trolltech.com/pricing.html or email sales@trolltech.com for
**   information about Qt Commercial License Agreements.
** See http://www.trolltech.com/qpl/ for QPL licensing information.
** See http://www.trolltech.com/gpl/ for GPL licensing information.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

#ifndef QLINEEDIT_H
#define QLINEEDIT_H

struct QLineEditPrivate;

class QComboBox;
class QValidator;


#ifndef QT_H
#include "qwidget.h"
#include "qstring.h"
#endif // QT_H

#ifndef QT_NO_LINEEDIT

class QLineEditMoto;
class Q_EXPORT QLineEdit : public QWidget
{
    Q_OBJECT
    Q_ENUMS( EchoMode )
    Q_PROPERTY( QString text READ text WRITE setText )
    Q_PROPERTY( int maxLength READ maxLength WRITE setMaxLength )
    Q_PROPERTY( bool frame READ frame WRITE setFrame )
    Q_PROPERTY( EchoMode echoMode READ echoMode WRITE setEchoMode )
    Q_PROPERTY( QString displayText READ displayText )
    Q_PROPERTY( int cursorPosition READ cursorPosition WRITE setCursorPosition )
    Q_PROPERTY( Alignment alignment READ alignment WRITE setAlignment )
    Q_PROPERTY( bool edited READ edited WRITE setEdited )
    Q_PROPERTY( bool hasMarkedText READ hasMarkedText )
    Q_PROPERTY( QString markedText READ markedText )

public:
    QLineEdit( QWidget *parent, const char *name=0 );
    QLineEdit( const QString &, QWidget *parent, const char *name=0 );
   ~QLineEdit();

    QString text() const;

    QString displayText() const;

    int		maxLength()	const;
    virtual void setMaxLength( int );

    virtual void setFrame( bool );
    bool	frame() const;

    enum	EchoMode { Normal, NoEcho, Password };
    virtual void setEchoMode( EchoMode );
    EchoMode 	echoMode() const;
#if QT_VERSION >= 300
#error "Make setReadOnly virtual"
#endif
    void setReadOnly( bool );
    bool isReadOnly() const;

    virtual void setValidator( const QValidator * );
    const QValidator * validator() const;

    QSize	sizeHint() const;
    QSize	minimumSizeHint() const;
    QSizePolicy sizePolicy() const;

    virtual void setEnabled( bool );
    virtual void setFont( const QFont & );
    virtual void setPalette( const QPalette & );
    virtual void setSelection( int, int );

#ifndef QT_NO_MOT_CURSOR_FLAG
    enum CursorFlagDirection {
	CF_NONE,
	CF_RTL,
	CF_LTR
    };

    void setCursorFlagDirection(CursorFlagDirection d);
  private:
    CursorFlagDirection cursFlag;
  public:
#endif
//#ifndef QT_NO_MOT_CURS_DISP_POS
//    enum CursorDisplayPosition {
//	CDP_RTL,
//	CDP_LTR
//    };
//    void setCursorDisplayPosition(CursorDisplayPosition d);
//  private:
//    CursorDisplayPosition cursDispPos;
//  public:
//#endif
    virtual void setCursorPosition( int );
    int		cursorPosition() const;

    bool	validateAndSet( const QString &, int, int, int );

#ifndef QT_NO_CLIPBOARD
    void	cut();
    void	copy() const;
    void	paste();
#endif

    void setAlignment( int flag );
    int alignment() const;

#ifndef QT_NO_RTL
    void        backspaceNew();
#endif
    void	cursorLeft( bool mark, int steps = 1 );
    void	cursorRight( bool mark, int steps = 1 );
    void	cursorRightFinish( bool mark, int cp );
    void	cursorWordForward( bool mark );
    void	cursorWordBackward( bool mark );
    void	backspace();
    void	del();
    void	home( bool mark );
    void	end( bool mark );

    void	setEdited( bool );
    bool	edited() const;

    bool	hasMarkedText() const;
    QString	markedText() const;
#if defined(Q_INCOMPATIBLE_3_0_ADDONS)
    bool 	getSelection( int *start, int *end );
    void 	setPasswordChar( QChar c );
    QChar 	passwordChar() const;
#endif    
    void        setOffsetCursor(bool on);
public slots:
    virtual void setText( const QString &);

    void	selectAll();
    void	deselect();

    void	clearValidator();

    void	insert( const QString &);
#ifndef QT_NO_RTL
    void        insertNew( const QString &);
#endif

    void	clear();

signals:
    void	textChanged( const QString &);
    void	returnPressed();

protected:
    bool	event( QEvent * );
    void	mousePressEvent( QMouseEvent * );
    void	mouseMoveEvent( QMouseEvent * );
    void	mouseReleaseEvent( QMouseEvent * );
    void	mouseDoubleClickEvent( QMouseEvent * );
    void	keyPressEvent( QKeyEvent * );
    void	focusInEvent( QFocusEvent * );
    void	focusOutEvent( QFocusEvent * );
    void	paintEvent( QPaintEvent * );
    void	resizeEvent( QResizeEvent * );
    void	leaveEvent( QEvent * );
#ifndef QT_NO_DRAGANDDROP
    void	dragEnterEvent( QDragEnterEvent * );
    void	dropEvent( QDropEvent * );
#endif

    void	repaintArea( int, int );

    int         xPosToCursorPos( int ) const;
    int		offset;

private slots:
    void	clipboardChanged();
    void	blinkSlot();
    void	dragScrollSlot();
#ifndef QT_NO_DRAGANDDROP
    void 	doDrag();
#endif

//For QLineEditMoto
protected:
    int tbufLength() { return tbuf.length(); }
    int	getAlignmentFlag() { return alignmentFlag; }
    void setAlignmentFlag(int f) { alignmentFlag = f; }
#ifndef QT_NO_MOT_ALIGN_AUTO
    bool getAlignmentAuto() { return alignmentAuto; }
#endif

private:
    // kept
    void	newMark( int pos, bool copy=TRUE );
    void	markWord( int pos );
    int		lastCharVisible() const;
    int		minMark() const;
    int		maxMark() const;
    int		frameW() const;
#ifndef QT_NO_QWS_IM
    void imStartEvent( QIMEvent * );
    void imComposeEvent( QIMEvent * );
    void imEndEvent( QIMEvent * );

    bool composeMode() const;
#endif    

    void	init();

public:
    void specialInputModeCursorModel(bool);
    void setInputModeCursorModel(int);
    int  getInputModeCursorModel(void);
private:
    QString	tbuf;
    QLineEditPrivate * d;
    int		cursorPos;
//    int		offset;
    int		maxLen;
    int		markAnchor;
    int		markDrag;
    bool	cursorOn;
    bool	dragScrolling;
    bool	scrollingLeft;
#ifndef QT_NO_MOT_ALIGN_AUTO
    bool	alignmentAuto;
#endif
    int		alignmentFlag;
    bool	ed;
    bool	offsetCursor; 
    
    void updateOffset();
//    int xPosToCursorPos( int ) const;
    void blinkOn();
    void makePixmap() const;
    void undoInternal();
    void redoInternal();

private:	// Disabled copy constructor and operator=
#if defined(Q_DISABLE_COPY)
    QLineEdit( const QLineEdit & );
    QLineEdit &operator=( const QLineEdit & );
#endif

    friend class QLineEditMoto;
    QLineEditMoto *m;

public:
    QLineEditMoto *moto() const { return m; }	
};

#endif // QT_NO_LINEEDIT

#endif // QLINEEDIT_H
