#ifndef UTIL_GRAPH_H
#define UTIL_GRAPH_H


/*
 * unoffical E8 EZX SDK 
 * Author : tulanix@yahoo.com.cn
 * 
*/

#include <qvaluelist.h>
class QPixmap;
class QString;

class UTIL_Graph
{
public:
    static QPixmap drawNegativeColorPixmap(const QPixmap &); 
    static QPixmap createDisabledPixmap( const QPixmap&);
    static QPixmap overlapPixmaps(QValueList<QPixmap>);
    static int scalePixmap(unsigned char* src,int srcwidth,int srcheight,int srcBytesPerRow,unsigned char* dest,int dstwidth,int dstheight,int dstBytesPerRow,int depth);
};

#endif //UTIL_GRAPH_H
