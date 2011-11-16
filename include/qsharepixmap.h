

// Copyright (c) 09-Apr-04 - 2008 Motorola, Inc. All rights reserved.


#ifndef QSHAREPIXMAP_H
#define QSHAREPIXMAP_H 

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <unistd.h>
#include <fcntl.h>
#include <qstring.h>
#include <qpixmap.h>

class QSharePixmap
{

public:

    QSharePixmap(const QString& name);
    ~QSharePixmap();

    bool lock();            
    bool unlock();          

    bool create(int w, int h, int depth); 
    bool destroy();         
    bool exists();          

    bool attach(QPixmap&);  
    bool detach();          

    bool set(const QPixmap&);

protected:

    int m_fd;               
    key_t m_tok;            
    int m_segmentID;        

    int m_nTimesLocked;     

    int m_nTimesAttached;   
    void *m_pData;          
    int m_pDataSize;        

    typedef struct {
        int check;          
        int width;          
        int height;         
        int depth;          
        int linestep;       
#ifndef QT_NO_QWS_MMI_TEST
        char file_Name_[30];
#endif
    } Hdr;

    Hdr *m_pHdr;            
    unsigned char *m_pPixmapData;  

};

#endif 
