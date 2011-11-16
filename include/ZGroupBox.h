

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZGROUPBOX_H
#define PUBLIC_API_WIDGET_ZGROUPBOX_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZWidget.h"
#include "ZSkinService.h"

class ZRadioButton;
class ZCheckBox;
struct ZGroupBoxPrivate;

class Q_EXPORT ZGroupBox : public ZWidget
{
    Q_OBJECT

public:

    ZGroupBox( QWidget * parent = 0, bool noStyle = false, const char * name = 0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZGroupBox);

    ZGroupBox( const QString & title, QWidget * parent = 0,
            const char * name = 0,  const ZSkinService::WidgetClsID clsId = ZSkinService::clsZGroupBox);

    virtual ~ZGroupBox();

    virtual void setEnabled( bool enable );

    bool isZEnabled() const;

    void setSpacing( const int H1, const int V1 );

    QString title() const;

    QSize sizeHint() const;

    virtual QPixmap* getBgImageForTransparent(bool& freeImage);

    int insert(ZWidget *w,int id = -1);

    void remove(ZWidget *b);

    void remove(int id);

    void takeItem(int id);

    void takeItem(ZWidget *i);

    int getId(ZWidget *b) const;

    ZWidget* getButton( int id ) const;

    int count() const;

    ZRadioButton * selected() const;

    QList<ZCheckBox> *checkedList() const;

    void clear();

    void resize(int w,int h);

    QSize titleSize();

    virtual bool eventFilter(QObject * obj, QEvent *e);    

    void triggerUpdate(bool doLayout);
signals:

    void	contentsResizing(ZGroupBox*, int w, int h);

public slots:

    void setNoStyle( bool noStyle );

    void setTitle( const QString & title );

    void slotResizeChild();
protected:

    virtual void childEvent( QChildEvent * event );

    virtual void keyPressEvent( QKeyEvent * event );

    virtual void paintEvent( QPaintEvent * event );

    virtual void setPalette( const QPalette & pal );

    virtual void resizeEvent( QResizeEvent * );

    virtual void showEvent( QShowEvent* );

private slots:

    void updateRadioButtons( ZRadioButton * pRadio );

    void slotLayoutTimer();

private:

    void init();

    struct ZGroupBoxPrivate * d;

    void doLayout();

    QString mTitle;

private: 
#if defined(Q_DISABLE_COPY)
    ZGroupBox( const ZGroupBox & );
    ZGroupBox & operator=( const ZGroupBox & );
#endif
};
#endif 
