// This file writed by Ant-ON <prozanton@gmail.com>, 2010
//
// Class in lib: libezx_mp_utility.so
//
// Information: this class use std player for show image in screen
//
// Presumably, use this:
// 
// MP_VideoWidget * mpView = new MP_VideoWidget(this);
// mpView->show();
// mpView->setGeometry( QRect(0,0,240,320) );
// mpView->clear();
// ...
// unsigned char* destFrame = mpView->getFramePtr();
// //srcFrame - source frame
// memcpy(destFrame, srcFrame, ... );
// mpView->drawFrame();

#ifndef MP_VIDEOWIDGET
#define MP_VIDEOWIDGET

//E8
#define LJ_7_3
//ZN5
#define LJ_6_3
//Z6
#define LJ_6_1

#include <ZWidget.h>
#include <qpixmap.h>

class Ezx_VideoDevice
{
public:
	enum RotateFlag 
	{
		Normal = 0,
		Left   = 1,
		Right  = 2
	};	
	
	enum ColorMode 
	{
		RGB565 = 1,
		RGB888 = 2,
		BGR888 = 3,
		BGRA8888 = 4,
		RGB666 = 5,
		BGRA6666 = 6 //???
	};
};


class MP_VideoWidget: public ZWidget, public Ezx_VideoDevice
{
	Q_OBJECT
public:
	MP_VideoWidget(QWidget *parent = 0, const char *name = 0, WFlags f=0 );
	~MP_VideoWidget();

public:	
	//virtual 
	int  getHeight();
	//virtual 
	int  getWidth();
	//virtual 
	void clear();
	//virtual 
	void drawFrame();
	//virtual 
	int  getBytesPerPix();
	//virtual 
	bool getFitForScreen() const;
	//virtual 
	int  lock();
	//virtual 
	int  unlock();
	//virtual 
	void setFitForScreen(bool newMode);
	//virtual 
	void setRotateFlag(RotateFlag newFlag);
	
	//virtual 
	ColorMode      getColorMode();	
	//virtual 
	unsigned char* getFramePtr() const;
	//virtual 
	unsigned int   getFrameStride() const;
	//virtual 
	RotateFlag     getRotateFlag() const;	
	
	#ifdef LJ_6_3
	//virtual 
	void getColorKey();//return type ?
	//virtual 
	int getXOffset();//int??
	//virtual 
	int getYOffset();//int??
	//virtual 
	void SetMEDLColorKeyFlag(bool);//return type ?
	#endif
	
	#ifdef LJ_7_3
	//virtual 
	void DisableColorKeyAlpha();//return type ?
	//virtual 
	void EnableColorKeyAlpha();//return type ?
	#endif
	
signals:
	virtual void clicked();
	virtual void focusGot();
	virtual void focusLost();
	virtual void pressAndHolded(const QPoint&);
	#ifdef LJ_6_3
	virtual void ProcessPosChanged();//is signal ?
	#endif
	
protected:
	virtual void focusInEvent( QFocusEvent* e );
	virtual void focusOutEvent( QFocusEvent* e );	
	virtual void mousePressEvent ( QMouseEvent * e );
	virtual void mouseReleaseEvent ( QMouseEvent * e );
	
	void paintEvent(QPaintEvent *);//non v
	void resizeEvent(QResizeEvent *);//non v
	
	#ifdef LJ_6_3
	virtual void eventFilter(QObject*, QEvent*);
	virtual void moveEvent(QMoveEvent*);
	#endif

//
private:
	#ifdef LJ_6_3
	virtual void SetNewParameters(int, int, int, int, Ezx_VideoDevice::RotateFlag, bool);
	virtual void setWidgetChangeCB(int (*)(void*, int), void*);	
	#endif

	#ifdef LJ_7_3
	virtual void unsetWidgetChangeCB();
	#endif
//

protected:
	class MyQPixmap : public QPixmap
	{
		public:
			MyQPixmap(int m_width, int m_height):QPixmap(m_width, m_height) 
			{
			}

		protected:
			uint fix[4];
	};
	MyQPixmap *pix;
	uint fix[100]; 
};

#endif
