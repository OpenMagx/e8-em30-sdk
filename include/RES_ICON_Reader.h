#ifndef __RES_ICON_READER_H__
#define __RES_ICON_READER_H__ 1

#include <qpixmap.h>
#include <qmovie.h>

class UTIL_Skin;

class RES_ICON_Reader {
public:
    RES_ICON_Reader();
    ~RES_ICON_Reader();

    QPixmap getIcon(char const*, bool);
    QPixmap getIcon(char const*, int, int);
    QMovie  getMovie(QString const&);

    inline QPixmap getIcon(char const* a) {
	return getIcon(a, 1);
    };

    static UTIL_Skin * pReader;
};

#endif
