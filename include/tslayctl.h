/*****************************************************************************
 *
 *  tslayctl.h  - LayoutControl object interface.
 *
 *  Copyright (C) 2005 Monotype Imaging Inc. All rights reserved.
 *
 *  $Archive:   I:/BULL/DisplayImaging/archives/wtle/product/source/include/tslayctl.h_v  $
 *  $Date:   Jun 06 2005 09:21:48  $
 *  $Revision:   1.3  $
 *
 ****************************************************************************/

#ifndef TSLAYOUTCONTROL_H
#define TSLAYOUTCONTROL_H

#include "tstypes.h"

TS_BEGIN_HEADER


struct TsLayoutControl_;


/*****************************************************************************
 *
 *  TsLayout control object.
 *
 *  Description:
 *      The TsLayoutControl object manages information for text layout. 
 *      Each client should create one TsLayoutControl upon startup and delete
 *      it upon shutdown.
 *
 *      This object is used when creating a new TsLayout using TsLayout_new.
 *      TsLayout keeps a pointer to the TsLayoutControl object, so it should not
 *      be deleted until all TsLayout objects that reference it are deleted.
 *
 *      Clients in a single thread can share the same TsLayoutControl object,
 *      but clients in separate threads or processes must declare their own.
 *
 *  <GROUP layoutcontrol>
 */
typedef struct TsLayoutControl_ TsLayoutControl;


/*****************************************************************************
 *
 *  Creates a TsLayoutControl object.
 *
 *  Parameters:
 *      none
 *
 *  Return value:
 *      TsLayoutControl *
 *
 *  <GROUP layoutcontrol>
 */
TS_EXPORT(TsLayoutControl *)
TsLayoutControl_new(void);


/*****************************************************************************
 *
 *  Frees a TsLayoutControl object.
 *
 *  Parameters:
 *      layout  - [in] this
 *
 *  Return value:
 *      void
 *
 *  <GROUP layoutcontrol>
 */
TS_EXPORT(void)
TsLayoutControl_delete(TsLayoutControl *layout);


TS_END_HEADER

#endif /* TSLAYOUTCONTROL_H */

