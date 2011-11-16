//Change for not warning by Ant-ON

// Copyright (c) 16-Aug-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef QPAINTERMOTO_H
#define QPAINTERMOTO_H

#include "qpainter.h"

class QPainterMoto {
public:
    QPainterMoto(QPainter *o) : q(o) {}
    virtual ~QPainterMoto() {}

#ifndef QT_NO_WTLE
    enum TextDirection {
	Auto,
	RTL,
	LTR
    };

    void	drawText( int x, int y, const QString &, int len = -1, TextDirection dir = Auto);
    void	drawText( const QPoint &, const QString &, int len = -1, TextDirection dir = Auto);
    void     drawText( int x, int y, const QString &, int pos, int len, TextDirection dir = Auto );
    void     drawText( const QPoint &p, const QString &, int pos, int len, TextDirection dir = Auto );
#endif

private:
    QPainter *q;
};

#ifndef QT_NO_WTLE
//inline void QPainterMoto::drawText( const QPoint &p, const QString &s, int len, TextDirection dir )
inline void QPainterMoto::drawText( const QPoint &p, const QString &s, int len, TextDirection )
{
    drawText( p.x(), p.y(), s, len );
}

inline void QPainterMoto::drawText( const QPoint &p, const QString &s, int pos,
			            int len, TextDirection dir)
{
    drawText( p.x(), p.y(), s, pos, len, dir);
}
#endif

#include "mot_blend.h"

#endif
