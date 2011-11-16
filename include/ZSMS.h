/*unoffical E8 EZX SDK
 *Author : tulanix@yahoo.com.cn 
 */
#ifndef ZSMS_H_
#define ZSMS_H_

#include <qobject.h>
#include <qdatetime.h>
class ZSMSPrivate;
class ZSMS_IncomingMsgPrivate;
class ZSMS_OutgoingMsgPrivate;
class ZSMS_MsgRecordIDPrivate;
class ZSMS_IncomingMsg;
class ZSMS_OutgoingMsg;
class ZSMS_MsgRecordID;

class ZSMS : public QObject
{
  Q_OBJECT
    public:
	  ZSMS(QObject* parent, char const* name);
	  virtual ~ZSMS();	  
	  bool interceptCheckIsEnabled() const;
	  bool sendMsg(ZSMS_OutgoingMsg const&);
	  bool sendMsgWithResult(unsigned int*, ZSMS_OutgoingMsg const&);
	  void enableInterceptCheck(bool enabled);
	  void gotoMessagingCenterHomeScreen();
	  void composeMsg(ZSMS_OutgoingMsg const&);
	  void notifyInterceptCheckResult(ZSMS_MsgRecordID const&, bool);
	signals:
	  void indOfIncomingMsg(ZSMS_IncomingMsg const&, ZSMS_MsgRecordID const&);
	  void rspnsOfSendMsgWithResult(unsigned int, int);
	private:
	  ZSMSPrivate *zsmsPrivate() const;
	private:
	  ZSMSPrivate *smsPrivate;
};

class ZSMS_IncomingMsg
{
    ZSMS_IncomingMsg(ZSMS_IncomingMsg const&);
	ZSMS_IncomingMsg();
	virtual ~ZSMS_IncomingMsg();
	ZSMS_IncomingMsg &operator=(ZSMS_IncomingMsg const&);
    QString getAddress() const;
    QString getMsgBody() const;
    QDateTime getSentTime() const;
  private:
    ZSMS_IncomingMsgPrivate *icmprivate;
};

class ZSMS_OutgoingMsg
{
  public:
    ZSMS_OutgoingMsg(QString const&, QString const&);
    ZSMS_OutgoingMsg(ZSMS_OutgoingMsg const&);
    virtual ~ZSMS_OutgoingMsg();
    ZSMS_OutgoingMsg &operator=(ZSMS_OutgoingMsg const&);
    void setAddress(QString const&);
    void setMsgBody(QString const&);
    QString getAddress() const;
    QString getMsgBody() const;
  private:
    ZSMS_OutgoingMsgPrivate *ogmprivate;
};

class ZSMS_MsgRecordID
{
  public:
    ZSMS_MsgRecordID(ZSMS_MsgRecordID const&);
    ZSMS_MsgRecordID();
    virtual ~ZSMS_MsgRecordID();
	ZSMS_MsgRecordID &operator=(ZSMS_MsgRecordID const&);
    bool isNull() const;
    bool isValid() const;
	void nullify();//???
  private:
    ZSMS_MsgRecordIDPrivate *mrprivate;
};
#endif //ZSMS_H_
