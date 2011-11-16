#ifndef MYSTUFF_SAVE_Dialog_H
#define MYSTUFF_SAVE_Dialog_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>
#include <qstringlist.h>
#include <qevent.h>

#include <MYSTUFF_Global.h>
#include <MYSTUFF_Base_Widget.h>
#include <ZKbMainWidget.h>
#include <ZAppInfoArea.h>

#ifdef MYSTUFF_SUPPORT_OBEXFTP
#include <MYSTUFF_OBEX_Def.h>
#endif

enum MYSTUFF_SELECTFOLDER_NUM
{
    MYSTUFF_COPY = 0,
    MYSTUFF_MOVE,
    MYSTUFF_SAVE_TO,
    MYSTUFF_STORE_TO,
    MYSTUFF_MOVE_FOR_SAVEAS
};
typedef MYSTUFF_SELECTFOLDER_NUM MYSTUFF_SELECTFOLDER_NUM_T;


//--------------------------------------------------------------------------------------
//                            CLASS
//--------------------------------------------------------------------------------------
class ZIconViewItem;
class ZListBoxItem;
class MYSTUFF_MenuOption;

class MYSTUFF_SAVE_Dialog:public ZKbMainWidget, public MYSTUFF_Base_Widget
{
Q_OBJECT

public:
    // if insert = TRUE, then insert dialog; if insert = FALSE, then open dialog; 
    MYSTUFF_SAVE_Dialog(QStringList&,
		          QWidget* parent=0,
			      QString initDir = QString::null,
		          MYSTUFF_SELECTFOLDER_NUM_T selectFolderType = MYSTUFF_SAVE_TO, 
			      const char* name=0,
			      WFlags f=0,
                  QString selectedDir = QString::null);
#ifdef MYSTUFF_SUPPORT_OBEXFTP
     MYSTUFF_SAVE_Dialog(QStringList&,
                          QList<MYSTUFF_OBEX_CONN_T>* obexList,
                          QWidget* parent=0,
                          QString initDir = QString::null,
                          MYSTUFF_SELECTFOLDER_NUM_T selectFolderType = MYSTUFF_SAVE_TO,
                          const char* name=0,
                          WFlags f=0,
                          QString selectedDir = QString::null);

#endif

    ~MYSTUFF_SAVE_Dialog();
    int    exec();
    void   hide();

    // return to app selected file name;
    inline QString getFile()  const
    {
        return memberSelectFile;
    };

    inline QString getCurrentFolder()  const
    {
        return memberSelectFolder;
    };

    inline int result()
    {
        return rescode;
    };
    inline QString getObexServer()  const
    {
        return memberSelectObexServer;
    };


private:
    void customEvent( QCustomEvent * e );
    void upDateTitle();
    void upDateHeader();
    void upDateContent();
    void upDateCst();
    void setUpData();
    void upClicked();   // for "Back to" item

    MYSTUFF_SELECTFOLDER_NUM_T memberSelectFolderType; //for save,copy,move UI
    QString      memberSelectFile;
    QString      memberSelectFolder;
    MYSTUFF_MenuOption *pmemberPopupMenu;
    ZSoftKey 	       *pmemberSoftKey;
    ZAppInfoArea       *pmemberAia;
    bool  in_loop;
    int   rescode;
    QString      memberSelectObexServer;
    QString      memberSourceFolder;
private slots:
    void slotMouseButtonClicked(int, ZListBoxItem*, const QPoint&);
    void slotHighlighted(ZListBoxItem *);
    void slotHotPlugUpdateMainWindow(const QCString &, const QByteArray &);
    //void slotOpenApp();
    void slotNewFolderWg(void); 
    void slotUpdateMenuItem(void);	
    
    void slotReturnKeyPressed( ZListBoxItem* );

    void   slotOkClicked();
    void   slotCancelClicked();

//signals:
   // void signalOpenButtClick( const QString& fileName );
};
//--------------------------------------------------------------------------------------------
#endif //MYSTUFF_SAVE_Dialog_H
