

// Copyright (c) 04-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ADDRBK_UI_PICKER_H  
#define ADDRBK_UI_PICKER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "qobject.h"
#include "qobjectdefs.h"
#include "qlist.h"
#include "qcollection.h"
#include "qglist.h"
#include "qwidget.h"
#include "qstring.h"
#include "qstringlist.h"
#include "EZX_TypeDefs.h"
#include "ADDRBK_ENG_Global.h"

class ADDRBK_UI_PickerManager;
class ContactsFLPickerMgr;

class ADDRBK_UI_PickerInterface: public QObject
{
Q_OBJECT
public:
    enum PICKER_TYPE_T {
        PICKER_TYPE_CALENDAR,         
        PICKER_TYPE_CAMERA_AUTOSEND,  
        PICKER_TYPE_CAMERA_QUICKSEND, 
        PICKER_TYPE_CAMERA_LIVE_VIDEO,
        PICKER_TYPE_SEND_MSG,         
        PICKER_TYPE_SEND_EMAIL,       
        PICKER_TYPE_SEND_POSTCARD,    
        PICKER_TYPE_VCARD,            
        PICKER_TYPE_ONE_CONTACT,      
        PICKER_TYPE_ONE_INFO,         
        PICKER_TYPE_ONE_NUMBER,       
        PICKER_TYPE_ONE_ADDRESS       
	};

    enum MSG_ACTION_TYPE_T {
        ACTION_BACK_TO_MSG = 1 << 0,      
        ACTION_SENDING_OPTIONS = 1 << 1,  
        ACTION_SAVE_TO_DRAFTS = 1 << 2,   
        ACTION_CANCEL_MESSAGE = 1 << 3,   
        ACTION_SEND = 1 << 4,              
        ACTION_SEND_NSM = 1 << 5          
    };

    enum PICK_INFO_T {
        PICK_INFO_NUMBER = 1 << 0,      
        PICK_INFO_EMAIL = 1 << 1,       
        PICK_INFO_IM = 1 << 2,       
    };

    struct SelectedAddress
    {
        ADDRBK_CONTACT_UID_S contactUID; 
        ADDRBK_RECORD_ID_T   recordID;   
        QString firstName;               
        QString lastName;                
        QString displayName;             
        QString addtional;               
        QString country;                 
        QString zip;                     
        QString state;                   
        QString city;                    
        QString street;                  
    };

    virtual void close() = 0;

    virtual void destroy() = 0;

    virtual int exec() = 0;

    virtual bool getSelectedAddresses(QList<SelectedAddress>& addressList) = 0;

   virtual bool getSelectedContacts(QList<ADDRBK_RECIPIENT_S>& dataList) = 0;

   virtual bool getSelectedUIDs(QList<ADDRBK_CONTACT_UID_S>& UIDList) = 0;

    virtual bool getSelectedAddress(SelectedAddress& address) = 0;

    virtual bool getSelectedContact(ADDRBK_RECIPIENT_S& contact) = 0;

    virtual bool getSelectedVCards(QStringList& vcardList) = 0;

    virtual QWidget* getWidget() = 0;

    virtual void init() = 0;

    virtual void setLimit(UINT32 limit) = 0;

    virtual void setCountLimit(UINT32 limit) = 0;

    virtual void setCharLimit(UINT32 limit) = 0;

    virtual void setSelectedContacts(const QList<ADDRBK_RECIPIENT_S>& dataList) = 0;

    virtual void setSelectedContacts(const QList<SelectedAddress>& addressList) = 0;

    virtual void setTitle(const QString& title) = 0;

    virtual void setRightSKText(const QString& text) = 0;

    virtual void setSpecOptions(int options) = 0;

    virtual void setInfoList(int infoList = PICK_INFO_NUMBER) = 0;

    virtual void setHlightOwnerInfo(bool hlOwnerInfo = FALSE) = 0;

    virtual void showMFMR(bool showMFMR = TRUE) = 0;
signals:
   void actionPressed(ADDRBK_UI_PickerInterface::MSG_ACTION_TYPE_T actionType);

   void pickerClosed(int result);
};

class ADDRBK_UI_Picker: public ADDRBK_UI_PickerInterface
{
Q_OBJECT
public:

    ADDRBK_UI_Picker(PICKER_TYPE_T type,
                     QWidget* parent = 0);
    ~ADDRBK_UI_Picker();

    void close();

    void destroy();

    int exec();

    bool getSelectedAddresses(QList<SelectedAddress>& addressList);

   bool getSelectedContacts(QList<ADDRBK_RECIPIENT_S>& dataList);

   bool getSelectedUIDs(QList<ADDRBK_CONTACT_UID_S>& UIDList);

    bool getSelectedAddress(SelectedAddress& address);

    bool getSelectedContact(ADDRBK_RECIPIENT_S& contact);

    bool getSelectedVCards(QStringList& vcardList);

    QWidget* getWidget();

    void init();

    void setLimit(UINT32 limit);

    void setCountLimit(UINT32 limit);

    void setCharLimit(UINT32 limit);

    void setSelectedContacts(const QList<ADDRBK_RECIPIENT_S>& dataList);

    void setSelectedContacts(const QList<SelectedAddress>& addressList);

    void setTitle(const QString& title);

    void setRightSKText(const QString& text);

    void setSpecOptions(int options);

    void setIsSendNSM(const bool sendNSM);

    void setInfoList(int infoList = PICK_INFO_NUMBER);

    void setHlightOwnerInfo(bool hlOwnerInfo = FALSE);

    void showMFMR(bool showMFMR = TRUE);

signals:
   void actionPressed(ADDRBK_UI_Picker::MSG_ACTION_TYPE_T actionType);

   void pickerClosed(int result);

private slots:
   void slotPickerClosed(int result);

private:
   ADDRBK_UI_PickerManager* pickerMgr;
   ContactsFLPickerMgr* flPickerMgr;
   bool flPickerActive;
   void * mpPickerHandle;

};

extern "C" ADDRBK_UI_PickerInterface* ADDRBK_CreatePicker(
                     ADDRBK_UI_PickerInterface::PICKER_TYPE_T type,
                     QWidget* parent);

typedef ADDRBK_UI_PickerInterface* (*ADDRBK_CreatePicker_T)(
                     ADDRBK_UI_PickerInterface::PICKER_TYPE_T,
                     QWidget*);

#endif 

