/****************************************************************************
 ** $Id:  qt/qcom.h   3.0.0   edited Sep 20 19:46 $
 **
 ** Definition of QLibrary class
 **
 ** Created : 2000-01-01
 **
 ** Copyright (C) 2000 Trolltech AS.  All rights reserved.
 **
 ** This file is a part of the kernel module of the Qt GUI Toolkit.
 **
 ** This file may be distributed under the terms of the Q Public License
 ** as defined by Trolltech AS of Norway and appears in the file
 ** LICENSE.QPL is included in the packaging of this file.
 **
 ** This file may be distributed and/or modified under the terms of the
 ** GNU General Public License version 2 as published by the Free Software
 ** Foundation and appears in the file LICENSE.GPL is included in the
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
 ** Modified by BJDC, Motorola 
 **
 **********************************************************************/
 

// Revision History:
//                             Modification     Tracking
// Author (core ID)                Date          Number     Description of Changes
// -------------------------   ------------    ----------   --------------------------------------
// Chu Yangqing/w20080         12/10/2002     LIBbbXXXXX    Ported from Qt 3.0
//


#ifndef QCOM_H
#define QCOM_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "quuid.h"

#define QRESULT     unsigned long
#define QS_OK       (QRESULT)0x00000000
#define QS_FALSE    (QRESULT)0x00000001

#define QE_NOTIMPL      (QRESULT)0x80000001
#define QE_OUTOFMEMORY  (QRESULT)0x80000002
#define QE_INVALIDARG   (QRESULT)0x80000003
#define QE_NOINTERFACE  (QRESULT)0x80000004
#define QE_NOCOMPONENT  (QRESULT)0x80000005

/**
 * The class wraps an initialized ulong
 *
 * @internal 
 */
struct QtULong
{
    QtULong() : ref( 0 ) { }
    operator unsigned long () const { return ref; }
    unsigned long& operator++() { return ++ref; }
    unsigned long operator++( int ) { return ref++; }
    unsigned long& operator--() { return --ref; }
    unsigned long operator--( int ) { return ref--; }

    unsigned long ref;
};

/**
 * The QUnknownInterface is for the class to get the pointers to other interfaces through the queryInterface method,
 * and manage the existenece of the object by addRef() and release(). The class is the base class for the other
 * interface classes
 *
 * @see QLibrary
 */
struct QUnknownInterface
{
    /**
     * Return a pointer to an interface on an object which is defined by QUuid, in the function,
     * addRef() should be called.
     *
     * @param id [in] identifier of the interface which is requested
     * @param ppObj [out] the pointer of the interfaces requested with id
     *
     * @retval return QS_OK if the interface is supported, or return QS_FALSE
     *
     * @see QUuid
     */
    virtual QRESULT queryInterface( const QUuid&, QUnknownInterface** ) = 0;
    
    /**
     * Add the reference count for the interface, the function should be called in every queryInterface
     *
     * @retval return the new reference for the interface, the reference is from 1 to n 
     *
     * @see queryInterface
     */
    virtual ulong   addRef() = 0;

    /**
     * Decrease the reference count for the interface, 
     *
     * @retval return the new reference for the interface, if the count is 0, the object should be
     * freed from memory.
     *
     * @see queryInterface
     */
    virtual ulong   release() = 0;
};

/**
 * Macro for managing the referenece of the interface which inherits from QUnknownInterface 
 * Default implementation of ref counting. A variable "ulong ref" has to be a member
 *
 * @see QUnknownInterface
 */
#define Q_REFCOUNT \
private:       \
    QtULong qtrefcount;   \
public:        \
    ulong addRef() {return qtrefcount++;} \
    ulong release() {if(!--qtrefcount){delete this;return 0;}return qtrefcount;}

#ifndef Q_EXTERN_C
#define Q_EXTERN_C  extern "C"
#endif


/**
 * {1D8518CD-E8F5-4366-99E8-879FD7E482DE}
 */
#ifndef IID_QUnknown
#define IID_QUnknown QUuid(0x1d8518cd, 0xe8f5, 0x4366, 0x99, 0xe8, 0x87, 0x9f, 0xd7, 0xe4, 0x82, 0xde)
#endif


/**
 * The QUuid for the internal component information interface 
 * {5F3968A5-F451-45b1-96FB-061AD98F926E}
 *
 * @internal 
 */
#ifndef IID_QComponentInformation
#define IID_QComponentInformation QUuid(0x5f3968a5, 0xf451, 0x45b1, 0x96, 0xfb, 0x6, 0x1a, 0xd9, 0x8f, 0x92, 0x6e)
#endif


/**
 * The class encapsulates version info for an interface class
 */
struct QComponentInformationInterface : public QUnknownInterface
{
    /**
     * The name of the interface  
     *
     * @retval return the name of the interface
     */
    virtual QString name() const = 0;

    /**
     * Some descriptions for the interface
     *
     * @retval return the description for the interface
     */
    virtual QString description() const = 0;

    /**
     * The author's name of the interface  
     *
     * @retval return the name of the author
     */
    virtual QString author() const = 0;

    /**
     * The version information of the interface
     *
     * @retval return the version of the interface
     */
    virtual QString version() const = 0;
};


/**
 * The QUuid for the internal component register/unregister interface 
 * {B5FEB5DE-E0CD-4E37-B0EB-8A812499A0C1}
 *
 * @internal 
 */
#ifndef IID_QComponentRegistration
#define IID_QComponentRegistration QUuid( 0xb5feb5de, 0xe0cd, 0x4e37, 0xb0, 0xeb, 0x8a, 0x81, 0x24, 0x99, 0xa0, 0xc1)
#endif

/**
 * The class can register and unregister some components
 *
 * @internal
 */
struct QComponentRegistrationInterface : public QUnknownInterface
{
    
    /**
     * Register the components under a directory to the system
     *
     * @param QString &filepath the absolute path of the components
     *
     * @retval true if register is successful, or return false 
     */
    virtual bool    registerComponents( const QString &filepath ) const = 0;

    /**
     * Unregister the components registered from the system
     *
     * @retval true if unregister is successful, or return false 
     */
    virtual bool    unregisterComponents() const = 0;
};

/**
 * The QUuid for the QLibrary interface 
 *
 * @internal 
 */
#ifndef IID_QLibrary
#define IID_QLibrary QUuid( 0xd16111d4, 0xe1e7, 0x4c47, 0x85, 0x99, 0x24, 0x48, 0x3d, 0xae, 0x2e, 0x07)
#endif
 
/**
 * The interfaces for the QLibrary to manage library 
 *
 * @internal
 */
struct Q_EXPORT QLibraryInterface : public QUnknownInterface
{
    /**
     * Initialize the QLibrary interface
     *
     * @retval true if initiation is successful, or return false 
     */
    virtual bool    init() = 0;

    /**
     * Clean up the QLibrary interface
     */
    virtual void    cleanup() = 0;

    /**
     * Judge if the QLibrary interface can be unloaded
     */
    virtual bool    canUnload() const = 0;
};

/**
 * Macro to create an instance for an interface 
 *
 * @param IMPLEMENTATION the name of the interface to be instanced
 *
 * @code
 * Q_CREATE_INSTANCE( EnglishKeyboardImpl )
 * @endcode
 */
#define Q_CREATE_INSTANCE( IMPLEMENTATION )              \
{                                                        \
    IMPLEMENTATION *i = new IMPLEMENTATION;          \
    QUnknownInterface* iface = 0;                    \
    QRESULT rt;                                      \
    rt = i->queryInterface( IID_QUnknown, &iface );  \
        if(rt == QS_OK)                                  \
           return iface;                                 \
        delete i;                                        \
        return NULL;                                     \
}

/**
 * Macro is to declare a common function, by which QLibrary instances an interface
 *
 * @code
 * Q_EXPORT_INTERFACE()
 * {
 *     Q_CREATE_INSTANCE( EnglishKeyboardImpl )
 * }
 * @endcode
 *
 * @see QLibrary
 */
#define Q_EXPORT_INTERFACE() extern "C" QUnknownInterface* ucm_instantiate()

/**
 * Macro to create an instance for an interface
 *
 * @see Q_CREATE_INSTANCE
 */
#define EZX_CREATE_INSTANCE( IMPLEMENTATION ) Q_CREATE_INSTANCE( IMPLEMENTATION )

/**
 * Macro is to declare a common function, by which QLibrary instances an interface 
 * @see  Q_CREATE_INSTANCE
 */
#define EZX_EXPORT_INTERFACE()  Q_EXPORT_INTERFACE()

#endif //QCOM_H
