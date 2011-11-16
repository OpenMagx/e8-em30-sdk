//Fix for E8/EM30 by Ant-ON, 24-02-2010

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ZTEXT_H 
#define ZTEXT_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qtimer.h>
#include <qcolor.h>
#include "ZWrapLine.h"

class Q_EXPORT ZText
{
public:
    ZText();

    ZText(const QString &text);

    void setText( const QString & t){text = t;}

    QString getText() const { return text; }

    int getWrapTextHeight(QFont& font,
                          int width = 0,
                          ZWrapLine::WrapPolicy policy = ZWrapLine::Anywhere,
                          uint spacing = 2);

    void paint(QPainter& painter,
               int x, int y,
               int width = -1, const QString ellpsis = "...",
               bool outline = FALSE, QColor outlineColor = QColor(255, 0, 0), int outlineSize = 1);

    void paint(QPainter& painter,
               QRect& rect, bool wraped = FALSE,
               int align = Qt::AlignLeft|Qt::AlignTop,
               const QString ellpsis = "...",  uint spacing = 2,
               ZWrapLine::WrapPolicy wrapPolicy = ZWrapLine::Anywhere,
               bool outline = FALSE, QColor outlineColor = QColor(255, 0, 0), int outlineSize = 1);

    static uint getStringWidth(const QFont& font,
                               const QString& str,
                               int len = -1);

    static QString truncate(const QFont& font,
                            const QString& str,
                            uint widthlimit,
                            int len = -1,
                            const QString& ellipsis = QString("..."));
    static int getAlignInRTL(int aligninLTR);
private:
    QString text;

private:
    QString truncateTail(const QString& str, int len, uint width,
                         const QFont& font, const QString ellpsis);
    QString truncateHead(const QString& str, int len, uint width,
                         const QFont& font, const QString ellpsis);
    void drawOutline(QPainter& painter, int x, int y, int w, int h, int align,
                     const QString text, const QColor& outlineColor, int outlineSize = 1);
};

class ZMarqueeTextPrivate;

class Q_EXPORT ZMarqueeText : public QObject
{
    Q_OBJECT
public:
    ZMarqueeText();
    ZMarqueeText(const QString &text, QWidget* parent = NULL, bool wraped = FALSE);

    virtual ~ZMarqueeText();

    void setParent(QWidget* parent);

    QWidget* parent() const;

    void setText( const QString & t);

    QString getText() const;

    void setWraped(bool w);

    bool wraped() const;

    void setWrapPolicy( ZWrapLine::WrapPolicy policy );

    ZWrapLine::WrapPolicy wrapPolicy() const;

    void setLineSpacing(uint spacing);

    uint lineSpacing() const ;

    void setGeometry(int x,int y, int w, int h);

    QRect geometry() const;

    void setFont(QFont& font);

    QFont font() const;

public:      
    void start(uint step = 1, uint speed = 100, uint headWaitTime = 1000, uint
tailWaitTime = 1000, bool headToTail = TRUE);

    void stop();

    void pause();

    void restart(bool renew = FALSE);

    void paint(QPainter& painter, int align = Qt::AlignLeft|Qt::AlignTop,
               QString ellpsis = "...", const QRect* pixmapPainterRect = NULL,
               bool outline = FALSE, QColor outlineColor = QColor(255, 0, 0), int outlineSize = 1);
private slots:
    void slotTimer();

private:
    void init(const QString &text, QWidget* parent, bool wraped);
    void cleanWrap();
    bool needMarquee();
    void doWrap();
    QString getLine(int index);

    void drawOutline(QPainter& painter, int x, int y, int w, int h, int align,
                     const QString text, const QColor& outlineColor, int outlineSize = 1);
private:
    class ZMarqueeTextPrivate *d;

};
#endif 
