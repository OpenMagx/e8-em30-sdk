// Copied from qconfig-barbados.h
/*
 * Copyright (C) 2007 Motorola Inc.
 *
 * Date         Author         Comment
 * 09/25/07     Motorola       Motorola customization.
 * 01/12/09     Ant-ON         Fix for Motorola E8.
*/

#ifndef QT_H
#endif // QT_H

#ifndef QT_DLL
#define QT_DLL 
#endif

//###### Add by Ant-ON ######

#ifndef QWS
#define QWS
#endif
#define QT_NO_QWS_DEPTH_24_ALPHA

//###########################

#define QT_NO_PROPERTIES
#define QT_NO_QWS_IM  
#define QT_NO_MONOTYPE_THAI
#define QT_NO_QWS_MOUSE_AUTO

//#define QT_NO_JPUNICODE
#define QT_NO_EUCKRCODEC
#define QT_NO_RTLCODEC
#define QT_NO_TSCIICODEC

//#define QT_NO_UNICODETABLES

#define QT_NO_FREETYPE       
#define QT_NO_BDF
//#define QT_NO_FONTDATABASE	//  font attributes and available font library
#define QT_NO_QWS_SAVEFONTS     

#define QT_NO_IMAGE_TEXT

#define QT_NO_COLORNAMES		
//#define QT_NO_TRANSFORMATIONS		
#define QT_NO_TRANSLATION_BUILDER
#define QT_NO_COMPLEXTEXT		
#define QT_NO_PRINTER
#define QT_NO_PICTURE		 
#define QT_NO_DRAGANDDROP
#define QT_NO_WORKSPACE
#define QT_NO_DIAL
#define QT_NO_ACTION
#define QT_NO_TABBAR
//#define QT_NO_ACCEL
#define QT_NO_SIZEGRIP

#define QT_NO_QWS_MANAGER
#define QT_NO_QWS_WINDOWS_WM_STYLE
#define QT_NO_QWS_KDE_WM_STYLE
#define QT_NO_QWS_KDE2_WM_STYLE
#define QT_NO_QWS_BEOS_WM_STYLE
#define QT_NO_QWS_HYDRO_WM_STYLE

#define QT_NO_STYLE_COMPACT
#define QT_NO_STYLE_AQUA		
#define QT_NO_STYLE_MOTIF
#define QT_NO_STYLE_PLATINUM

#define QT_NO_FILEDIALOG
#define QT_NO_FONTDIALOG
#define QT_NO_PRINTDIALOG
#define QT_NO_COLORDIALOG
#define QT_NO_INPUTDIALOG
#define QT_NO_MESSAGEBOX
#define QT_NO_PROGRESSDIALOG

#define QT_NO_TABDIALOG			
#define QT_NO_WIZARD

#define QT_NO_MENUBAR
#define QT_NO_SPINBOX			
#define QT_NO_LCDNUMBER			

//#define QT_NO_EFFECTS

#ifndef QT_NO_QWS_MACH64
#define QT_NO_QWS_MACH64
#define QT_NO_QWS_VOODOO3
#define QT_NO_QWS_MATROX
#define QT_NO_QWS_SVGALIB
#endif

#define QT_NO_SOUND

#define NO_CHECK
#define AMT_NO_THAI_DICTIONARY

#define QT_KEYPAD_MODE

//#define QT_NO_COMPAT

#define QT_NO_ICONVIEW
#define QT_NO_LISTVIEW
#define QT_NO_MULTILINEEDIT
// #define QT_NO_LINEEDIT
#define QT_NO_GRID
// #define QT_NO_PUSHBUTTON

// #define QT_NO_POPUPMENU
#define QT_NO_MENUBAR
// #define QT_NO_MENUDATA

//#define QT_NO_GROUPBOX
#define QT_NO_LCDNUMBER

#define QT_NO_SLIDER
#define QT_NO_TOOLBUTTON
#define QT_NO_TOOLTIP
#define QT_NO_WHATSTHIS
#define QT_NO_TOOLBAR
// #define QT_NO_CHECKBOX
// #define QT_NO_RADIOBUTTON

#define QT_NO_SPLITTER
#define QT_NO_SPINBOX
// #define QT_NO_LISTBOX
#define QT_NO_TEXTVIEW
#define QT_NO_TEXTBROWSER

#define QT_NO_NETWORKPROTOCOL_FTP
#define QT_NO_STATUSBAR
#define QT_NO_DIAL
#define QT_NO_SIZEGRIP

#define QT_NO_PROGRESSBAR
#define QT_NO_SESSIONMANAGER
#define QT_NO_MAINWINDOW

#define QT_NO_ACTION

//#define QT_NO_CANVAS

#define QT_MULTILCD

//#ifndef QT_NO_QWS_DEPTH_18
//#define QT_NO_QWS_DEPTH_18
//#endif



//#define QT_NO_YOPYBUTTON_HANDLER
//#define QT_NO_TTYKEYBOARD_HANDLER
//#define QT_NO_USBKEYBOARD_HANDLER
//#define QT_NO_VR41XX_HANDLER
//#define QT_NO_VFBKEYBOARD_HANDLER
//#define AMT_NO_THAI_ADDITIONS
#define QT_NO_QWS_SHARED_MEMORY_CACHE
//#define QT_NO_QWS_FADEBACKGROUND  // no fading background compilation 
