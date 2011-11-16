

// Copyright (c) 01-Feb-04 - 2008 Motorola, Inc. All rights reserved.


#ifndef QWALLPAPER_H
#define QWALLPAPER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qpixmap.h>

class QWallpaper {

public:

    enum Position
    {
        Stretch = 0,
        Center,
        Tile
    };

    static void setSysWallpaper(const QPixmap*,QWallpaper::Position = QWallpaper::Stretch);
    static QPixmap* sysWallpaper();

    static void setSysDialogWallpaper(const QPixmap*,QWallpaper::Position = QWallpaper::Stretch);
    static QPixmap* sysDialogWallpaper();

    static void setAppWallpaper(const QPixmap*,QWallpaper::Position pos = QWallpaper::Stretch);
    static QPixmap* appWallpaper();

    static void setFillColor(uint color);

    enum Mode
    {
        UseSysWallpaper,
        UseAppWallpaper,
        Off
    };

    static void setAppWallpaperMode(Mode mode);
    static Mode appWallpaperMode();

    static QPixmap* wallpaper(); 
    static QPixmap* dialogWallpaper();

};

#endif 

