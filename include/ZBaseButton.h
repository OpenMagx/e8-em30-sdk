// Copyright (c) 27-Oct-2005 - 2008 Motorola, Inc. All rights reserved.

/////////////////////////////////////////////////////////////////////
/// $Id: qt/include/qbutton.h   2.3.6   edited 2001-01-26 $
///
/// Definition of QButton class
///
/// Created : 941115
///
/// Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
///
/// This file is part of the widgets module of the Qt GUI Toolkit.
///
/// This file may be distributed under the terms of the Q Public License
/// as defined by Trolltech AS of Norway and appearing in the file
/// LICENSE.QPL included in the packaging of this file.
///
/// This file may be distributed and/or modified under the terms of the
/// GNU General Public License version 2 as published by the Free Software
/// Foundation and appearing in the file LICENSE.GPL included in the
/// packaging of this file.
///
/// Licensees holding valid Qt Enterprise Edition or Qt Professional Edition
/// licenses may use this file in accordance with the Qt Commercial License
/// Agreement provided with the Software.
///
/// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
/// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
///
/// See http://www.trolltech.com/pricing.html or email sales@trolltech.com for
///   information about Qt Commercial License Agreements.
/// See http://www.trolltech.com/qpl/ for QPL licensing information.
/// See http://www.trolltech.com/gpl/ for GPL licensing information.
///
/// Contact info@trolltech.com if any conditions of this licensing are
/// not clear to you.
///
/// Motorola changes the file for Linux Java
///
///Drafted Header Files, will be revised in LJ6.3. They can be private or renamed
///////////////////////////////////////////////////////////////////////////

#ifndef PUBLIC_API_WIDGET_ZBASEBUTTON_H
#define PUBLIC_API_WIDGET_ZBASEBUTTON_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

//--------------------------------------------------------------------------------------------------
//                                    INCLUDE FILES
//--------------------------------------------------------------------------------------------------

#include "ZFormItem.h"

#ifndef QT_NO_BUTTON

//-----------------------------------------------------------------------------
//                            FORWARD CLASS DECLARATIONS
//-----------------------------------------------------------------------------
class ZBaseButtonGroup;
struct ZBaseButtonData;
class QToolBar;


///----------------------------------------------------------------------------
//                               CLASS DEFINITION
//-----------------------------------------------------------------------------

/// It is a base class of button widget,inherit by ZCheckBox,ZRadioButton,etc.

/// Category:    General
/// Persistence: Transient
/// Cardinality/Multiplicity:  None
/// API Migration State: DRAFT
class Q_EXPORT ZBaseButton : public ZFormItem
{
    Q_OBJECT
    Q_ENUMS( ToggleType ToggleState )
    Q_PROPERTY( QString text READ text WRITE setText )
    Q_PROPERTY( QPixmap pixmap READ pixmap WRITE setPixmap )
    Q_PROPERTY( int accel READ accel WRITE setAccel )
    Q_PROPERTY( bool toggleButton READ isToggleButton )
    Q_PROPERTY( ToggleType toggleType READ toggleType )
    Q_PROPERTY( bool down READ isDown WRITE setDown DESIGNABLE false  )
    Q_PROPERTY( bool on READ isOn )
    Q_PROPERTY( ToggleState toggleState READ state )
    Q_PROPERTY( bool autoResize READ autoResize WRITE setAutoResize )
    Q_PROPERTY( bool autoRepeat READ autoRepeat WRITE setAutoRepeat )
    Q_PROPERTY( bool exclusiveToggle READ isExclusiveToggle )

public:
    ///
    /// Constructor of ZBaseButton.
    /// \param parent The parent of the ZBaseButton
    /// \param name Class name string.
    /// \param f The flag of the ZBaseButton
    /// \param clsId The skin style ID of the ZBaseButton
    ///
    ZBaseButton( QWidget *parent, const char *name, WFlags f,ZSkinService::WidgetClsID clsId );

    ///
    /// Destructor of ZBaseButton
    ///
   ~ZBaseButton();

    ///
    ///Returns the button text, or null string if the button has no text.
    ///
    QString text() const;

    ///
    ///Sets the button to display text.
    ///
    virtual void setText( const QString &);

    ///
    ///Returns the button pixmap, or 0 if the button has no pixmap.
    ///
    const QPixmap *pixmap() const;

    ///
    ///Sets the button to display pixmap
    ///
    virtual void setPixmap( const QPixmap & );

    ///
    ///Returns the accelerator key currently set for the button, or 0 if no accelerator key has 
    ///been set.
    ///
    int		accel()	const;

    ///
    ///Specifies an accelerator key for the button, or removes the accelerator if key is 0.
    ///
    virtual void	setAccel( int );

    ///
    ///Returns TRUE if the button is a toggle button.
    ///
    bool	isToggleButton() const;

    //-----------------------------------------------------------------------------
    //                                  ENUMS
    //-----------------------------------------------------------------------------
    ///
    /// enum type ToggleType,This enum type defines what a button can do in response to a 
    /// mouse/keyboard press
    ///
    enum ToggleType { SingleShot, Toggle, Tristate };

    ///
    ///Returns the current toggle type.
    ///
    ToggleType	toggleType() const;

    ///
    ///Sets the state of the button to pressed down if enable is TRUE or to standing up if 
    ///enable is FALSE.
    ///
    virtual void setDown( bool );

    ///
    ///Returns TRUE if the button pressed down, or FALSE if it is standing up.
    ///
    bool	isDown() const;

    ///
    ///Returns TRUE if this toggle button is switched on, or FALSE if it is switched off.
    ///
    bool	isOn() const;

    //-----------------------------------------------------------------------------
    //                                  ENUMS
    //-----------------------------------------------------------------------------
    ///
    /// enum type ToggleState,This enum defines the state of a toggle button at any moment.
    ///
    enum ToggleState { Off, NoChange, On };
    ToggleState	state() const;

    ///
    ///It is a obsolete function,please don't call it.
    ///
    bool	autoResize() const;

    ///
    ///It is a obsolete function,please don't call it.
    ///
    virtual void setAutoResize( bool );

    ///
    ///Returns TRUE if the button is auto-repeating, else FALSE.
    ///
    bool	autoRepeat() const;

    ///
    ///Turns on auto-repeat for the button if enable is TRUE, or turns it off if enable is FALSE.
    ///
    virtual void setAutoRepeat( bool );

    ///
    ///Returns TRUE if this button behaves exclusively inside a ZBaseButtonGroup
    ///
    bool	isExclusiveToggle() const;
   
    ///
    ///Reimplement
    ///
    bool	focusNextPrevChild( bool next );

    ///
    ///Returns a pointer to the group of which this button is a member.
    ///
    ZBaseButtonGroup *group() const;

public slots:
    ///
    ///Performs an animated click: The button is pressed and a short while later released.
    ///
    void	animateClick();

    ///
    ///if this is a toggle button, toggles it.
    ///
    void	toggle();

signals:
    ///
    /// This signal is emitted when the button is pressed down
    ///
    void	pressed();

    ///
    /// This signal is emitted when the button is released
    ///
    void	released();

    ///
    /// This signal is emitted when the button is activated, i.e. first pressed down 
    /// and then released when the mouse cursor is inside the button, or when the accelerator 
    /// key is typed, or when animateClick() is called.
    ///
    void	clicked();

    ///
    /// This signal is emitted whenever a toggle button changes status.
    /// on is TRUE if the button is on, or FALSE if the button is off.
    ///
    void	toggled( bool );

    ///
    /// This signal is emitted whenever a toggle button changes status.
    /// state is 2 if the button is on, 1 if it is in the "no change" state or 0 if the button is off.
    ///
    void	stateChanged( int );

protected:

    ///
    ///Makes the button a toggle button if enable is TRUE, or a normal button if enable is FALSE.
    ///
    void	setToggleButton( bool );

    ///
    /// Sets the type of toggling behavior. The default is SingleShot.
    /// Subclasses use this, and present it with a more comfortable interface
    ///
    virtual void	setToggleType( ToggleType );

    ///
    /// Switches a toggle button on if enable is TRUE or off if enable is FALSE. This function should 
    /// be called only for toggle buttons.
    ///
    void	setOn( bool );

    ///
    /// This protected function sets the button state into state t but does not cause repainting.
    ///
    virtual void	setState( ToggleState );

    ///
    /// Returns TRUE if pos is inside the clickable button rectangle, or FALSE if it is outside.
    ///
    virtual bool hitButton( const QPoint &pos ) const;

    ///
    /// Draws the button. The default implementation does nothing.
    ///
    virtual void drawButton( QPainter * );

    ///
    /// Draws the button text or pixmap.
    ///
    virtual void drawButtonLabel( QPainter * );

    ///
    /// Reimplemented in ZBaseButton
    ///
    void	keyPressEvent( QKeyEvent *);

    ///
    /// Reimplemented in ZBaseButton
    ///
    void	keyReleaseEvent( QKeyEvent *);

    ///
    /// Reimplemented in ZBaseButton
    ///
    void	mousePressEvent( QMouseEvent * );

    ///
    /// Reimplemented in ZBaseButton
    ///
    void	mouseReleaseEvent( QMouseEvent * );

    ///
    /// Reimplemented in ZBaseButton
    ///
    void	mouseMoveEvent( QMouseEvent * );

    ///
    /// Reimplemented in ZBaseButton
    ///
    void	paintEvent( QPaintEvent * );

    ///
    /// Reimplemented in ZBaseButton
    ///
    void	focusInEvent( QFocusEvent * );

    ///
    /// Reimplemented in ZBaseButton
    ///
    void	focusOutEvent( QFocusEvent * );

    ///
    /// Reimplemented in ZBaseButton
    ///
    void	enabledChange( bool );

private slots:
    void	animateTimeout();
    void	autoRepeatTimeout();

private:
    QString	btext;
    QPixmap    *bpixmap;
    uint	toggleTyp	: 2;
    uint	buttonDown	: 1;
    uint	stat		: 2;
    uint	mlbDown		: 1;
    uint	autoresize	: 1;
    uint	animation	: 1;
    uint	repeat		: 1;
    ZBaseButtonData *d;

    friend class ZBaseButtonGroup;
    friend class QToolBar;
    void          ensureData();
    virtual void setGroup( ZBaseButtonGroup* );
    QTimer	 *timer();
    void	nextState();

private:	// Disabled copy constructor and operator=
#if defined(Q_DISABLE_COPY)
    ZBaseButton( const ZBaseButton & );
    ZBaseButton &operator=( const ZBaseButton & );
#endif
};


#endif // QT_NO_BUTTON

#endif //PUBLIC_API_WIDGET_ZBASEBUTTON_H
