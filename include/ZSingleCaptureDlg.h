/*
# Revision History:
# 
#    date         coreid  description
# ---------------------------------------------------------------------------
#    02-Jun-2008  BeZ     changed return type for functions:
#                            ZSingleCaptureDlg::getLineEdit()
*/

#ifndef _ZSINGLECAPTUREDLG_H
#define _ZSINGLECAPTUREDLG_H

#include <ZPopup.h>
//
#include <ZLineEdit.h>
#include <ZMultiLineEdit.h>

/* Size:216=54*4 */

#define TypeLineEdit normal
#define TypeLineEditPasswd secret
#define TypeTextField normal2
#define TypePasswdField secret2
class ZSingleCaptureDlg : public ZPopup
{
	Q_OBJECT
	void *point;
public: 
    enum CaptureDlgType
    {
        normal,                // text field,     use ZLineEdit widget
        secret,                // password field, use ZLineEdit widget

        normal2,              // text field,     use ZMultiLineEdit widget
        secret2,              // password field, use ZMultiLineEdit widget

        TypeCustom            // custom type, for extend use
    };
	ZSingleCaptureDlg(const QString& strDlgTitle,
                      const QString& strInstructText,
                      CaptureDlgType type,
                      QWidget* parent = NULL,
                      const char* name = 0,
                      bool modal = TRUE,
                      WFlags f = 0,
                      int auto_dismiss_time = 0);
                      
    ZSingleCaptureDlg(QWidget* parent = NULL,
                      const char* name = 0,
                      bool modal = TRUE,
                      WFlags f = 0);	
	virtual ~ZSingleCaptureDlg();
	CaptureDlgType getDialogType();
  	ZWidget* getEditWidget();
  	ZLineEdit* getLineEdit();
  	ZMultiLineEdit* getMultiLineEdit();
  	QString getResultText();
  	bool setEditWidget(ZWidget*);
private:
	void initialize(ZSingleCaptureDlg::CaptureDlgType);
public slots:
	virtual void  slotLSKClicked();
	virtual void  slotRSKClicked();
	virtual void  slotResizeAllChild(int);
};

#endif
