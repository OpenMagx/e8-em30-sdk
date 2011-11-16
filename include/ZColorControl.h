#ifndef ZCOLORCONTROL_H
#define ZCOLORCONTROL_H

#include "ZFormItem.h"
#include <qstring.h>

class ZColorControlPrivate;
class ZColorPickerDlg;

class ZColorControl: public ZFormItem
{
	Q_OBJECT
public:
	enum    TitlePosition {TitleTop, TitleLeft,TitleBottom,TitleRight};
	
	ZColorControl(QColor color,QRgb *,int,const QString & = QString::null,TitlePosition = TitleTop,QWidget *parent=0,const char *name=0,WFlags f=0,const ZSkinService::WidgetClsID clsId = ZSkinService::clsZColorPicker);
	ZColorControl(QColor color, const QString & title = QString::null,TitlePosition = TitleTop,QWidget *parent=0,const char *name=0,WFlags f=0,const ZSkinService::WidgetClsID clsId = ZSkinService::clsZColorPicker);
	
	virtual ~ZColorControl();
	
	QColor getColor();
	QString getColorName(QColor currColor);
	QSize sizeHint() const;
	
	void setTitlePosition(TitlePosition);
	void setTitle(const QString & );
	void setDlgTitle(const QString & t);
	void setSoftkeyTextLeft(const QString& );
	void setSoftkeyTextRight(const QString& );
	void setSoftkeyText(const QString&, const QString& );
	
private:
	uint fix[250];
};
#endif

