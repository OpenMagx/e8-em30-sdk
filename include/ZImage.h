
// Copyright (c)  - 2008 Motorola, Inc. All rights reserved.

#ifndef __ZIMAGE_H__
#define __ZIMAGE_H__

#include "qpixmap.h"
#include "qsize.h"
#include "qmovie.h"
#include "ZWidget.h"

class Q_EXPORT ZImage : public ZWidget
{   
public:
    ZImage(QWidget * parent,const char * name = 0, WFlags f  = 0);
    ZImage(QPixmap & pixmap, QWidget * parent,const char * name = 0, WFlags f  = 0);
    ~ZImage();

    QPixmap * pixmap() const {return lpixmap;}
    QMovie      *movie()		const;
    void        setMovie(const QMovie &);
    void      setPixmap(const QPixmap & pixmap);
    void getFrameWidth(int & nleftf,int & nrightf,int & ntopf, int & nbottomf) const;
    virtual void setGeometry(int x,int y, int w, int h);
    virtual void setGeometry(const QRect & r);
    virtual void resize(int w, int h);
    QSize sizeHint() const ;
    virtual void setEnabled(bool enable);
    bool isZEnabled();
    bool isZDisabled();


signals:
    void sizeChange(const QSize & size);

private slots:
    void	 movieUpdated(const QRect&);
    void	 movieResized(const QSize&);
	
private:
    void init();
    void clearContents();
    QRect getContentRect();

protected:
    void paintEvent(QPaintEvent * );
    virtual void setPalette(const QPalette &);
    
private:
    QPixmap * lpixmap;
    QMovie *	lmovie;
    int nMoview;
    int nMovieh;
    bool mIsEnabled;
};




#endif
