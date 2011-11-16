
/****************************************************************************
** $Id: qt/src/widgets/ZBaseButtonGroup.h   2.3.6   edited 2001-01-26 $
**
** Definition of ZBaseButtonGroup class
**
** Created : 950130
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
** Motorola changes the file for Linux Java
**
**********************************************************************/

#ifndef ZBASEBUTTONGROUP_H
#define ZBASEBUTTONGROUP_H

#ifndef QT_H
#include "qgroupbox.h"
#endif // QT_H

#ifndef QT_NO_BUTTONGROUP


class ZBaseButton;
class ZBaseButtonList;


class Q_EXPORT ZBaseButtonGroup : public QGroupBox
{
    Q_OBJECT
    Q_PROPERTY( bool exclusive READ isExclusive WRITE setExclusive )
    Q_PROPERTY( bool radioButtonExclusive READ isRadioButtonExclusive WRITE setRadioButtonExclusive )
	
public:
    ZBaseButtonGroup( QWidget *parent=0, const char *name=0 );
    ZBaseButtonGroup( const QString &title,
		  QWidget *parent=0, const char* name=0 );
    ZBaseButtonGroup( int columns, Orientation o,
		  QWidget *parent=0, const char *name=0 );
    ZBaseButtonGroup( int columns, Orientation o, const QString &title,
		  QWidget *parent=0, const char* name=0 );
   ~ZBaseButtonGroup();

    bool	isExclusive() const;
    bool	isRadioButtonExclusive() const { return radio_excl; }
    virtual void setExclusive( bool );
    virtual void setRadioButtonExclusive( bool );

public:
    int		insert( ZBaseButton *, int id=-1 );
    void	remove( ZBaseButton * );
    ZBaseButton    *find( int id ) const;
    int		id( ZBaseButton * ) const;
    int		count() const;

    virtual void setButton( int id );

    virtual void moveFocus( int );

    ZBaseButton    *selected();

signals:
    void	pressed( int id );
    void	released( int id );
    void	clicked( int id );

protected slots:
    void	buttonPressed();
    void	buttonReleased();
    void	buttonClicked();
    void	buttonToggled( bool on );

private:
    void	init();
    bool	excl_grp;
    bool	radio_excl;
    ZBaseButtonList *buttons;

private:	// Disabled copy constructor and operator=
#if defined(Q_DISABLE_COPY)
    ZBaseButtonGroup( const ZBaseButtonGroup & );
    ZBaseButtonGroup &operator=( const ZBaseButtonGroup & );
#endif
};


#endif // QT_NO_BUTTONGROUP

#endif // ZBASEBUTTONGROUP_H
