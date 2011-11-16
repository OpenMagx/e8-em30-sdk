//Fix for E8/EM30 by Ant-ON, 25-10-2010

// Copyright (c)  - 2008 Motorola, Inc. All rights reserved.

#ifndef _ZCOLORPICKERDLG_H
#define _ZCOLORPICKERDLG_H

#include <qwidget.h>
#include <qstring.h>
#include <qevent.h>
#include <qcolor.h>

#include <ZPopup.h>

/* Size: 216=54*4 */

class ZColorModule;

class ZColorPickerDlg : public ZPopup
{
	Q_OBJECT
	void *data;
public:
	ZColorPickerDlg(QColor const&, unsigned*, int, QWidget* parent = 0, char const* name = 0, WFlags f = 0);
	virtual ~ZColorPickerDlg();
	
	ZColorModule* getColorModule();
	QColor getColor();
	
	
};

#endif
