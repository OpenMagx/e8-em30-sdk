

// Copyright (c) 20-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMMEDIAEXTRACTOR_H 
#define MMMEDIAEXTRACTOR_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMGeneral.h"

#include "MMMetaDataControl.h"

#include "ZMediaSDK.h"

#define FREEPOINT(v1) \
    { \
        if ((v1) != NULL) \
        { \
            delete (v1); \
            (v1) = NULL; \
        } \
    }

#define FREEPOINT_V(v1) \
    { \
        if ((v1) != NULL) \
        { \
            delete [](v1); \
            (v1) = NULL; \
        } \
    }

#define CHECKPOINT(v1) \
    { \
        if (v1 == NULL) \
        { \
            MM_DEBUG("No enough memory\n"); \
            return MMRESULT_MEMORY_FULL; \
        } \
    }

#define GETSYMBOL(v1, v2, v3) \
    { \
        v1 = (v2)dlsym(m_phandle,v3);\
        if (v1 == NULL) \
        { \
            MM_DEBUG("get symbol failed: %s\n", dlerror()); \
            dlclose(m_phandle); \
            m_phandle = NULL; \
            return MMRESULT_UNKNOWN; \
        } \
    }

#define GETMETAITEMDATA(v1, v2, v3, v4) \
    { \
        if (pmetainfolist != NULL) \
        { \
            pmetainfolist[keynum].encoding_type = v1;  \
            pmetainfolist[keynum].data_size = v2; \
            pmetainfolist[keynum].p_data = new unsigned char[v2]; \
            CHECKPOINT(pmetainfolist[keynum].p_data); \
            memcpy(pmetainfolist[keynum].p_data, v3, v2); \
            pmetainfolist[keynum].key_type = v4; \
        } \
    }

#define IMP_MetaItemNum 17
#define IMP_ClipInfoNum 16

typedef struct _ME_CODECTYPE
{
    int audioCodecType;
    int audioCodecLevel;
    int videoCodecType;
    int videoCodecLevel;
}ME_CODECTYPE, *PME_CODECTYPE;

typedef struct _ME_MOTOTAGINFO
{
    int  motoflag;
    unsigned char * psmartalbum;
    int  smartalbumsize;
    unsigned char * pthumbnail;
    int  thumbnailsize;
    _ME_MOTOTAGINFO()
    {
        motoflag = 0;
        smartalbumsize = 0;
        thumbnailsize = 0;
        psmartalbum = NULL;
        pthumbnail = NULL;
    }
    ~_ME_MOTOTAGINFO()
    {
        if (psmartalbum)
        {
            delete []psmartalbum;
            psmartalbum = NULL;
        }
        if (pthumbnail)
        {
            delete []pthumbnail;
            pthumbnail = NULL;
        }
    }
}ME_MOTOTAGINFO, *PME_MOTOTAGINFO;

static MMMetadataKey MetaDataKey[] = 
{
    MMMETADATA_TITLE_KEY,
    MMMETADATA_AUTHOR_KEY,
    MMMETADATA_ALBUM_KEY,
    MMMETADATA_GENRE_KEY,
    MMMETADATA_YEAR_KEY,
    MMMETADATA_COPYRIGHT_KEY,
    MMMETADATA_LYRICS_KEY,
    MMMETADATA_COMPOSER_KEY,
    MMMETADATA_TRACKNUM_KEY,
    MMMETADATA_LANGUAGE_KEY,
    MMMETADATA_COMMENT_KEY,
    MMMETADATA_FILETYPE_KEY,
    MMMETADATA_DIRECTOR_KEY,
    MMMETADATA_STUDIO_KEY,
    MMMETADATA_RECORDDATE_KEY,
    MMMETADATA_RECORDTIME_KEY,
    MMMETADATA_PICTURETYPE_KEY
};

static MMMetadataKey ClipInfoKey[] =
{
    MMMETADATA_TOTALSIZE_KEY,
    MMMETADATA_DURATION_KEY,
    MMMETADATA_TOTALBITRATE_KEY,
    MMMETADATA_CREATETIME_KEY,
    MMMETADATA_COPYPROTECTED_KEY,
    MMMETADATA_NUMOFAUDIOSTREAMS_KEY,
    MMMETADATA_NUMOFVIDEOSTREAMS_KEY,
    MMMETADATA_AUDIOBITRATE_KEY,
    MMMETADATA_AUDIOSAMPLERATE_KEY,
    MMMETADATA_AUDIOCHANNELS_KEY,
    MMMETADATA_AUDIOBITSPERSAMPLE_KEY,
    MMMETADATA_AUDIOMAXBLOCKSIZE_KEY,
    MMMETADATA_VIDEOBITRATE_KEY,
    MMMETADATA_VIDEOWIDTH_KEY,
    MMMETADATA_VIDEOHEIGHT_KEY,
    MMMETADATA_VIDEOFPS_KEY
};

typedef int (*GetMetaInfo)(const char* szFileName, IMP_MetaInfo* pMetaData);
typedef int (*GetClipInfo)(const char* szFileName, IMP_ClipInfo* pClipInfo);
typedef int (*FreeMetaInfo)(IMP_MetaInfo* pMetaData);
typedef int (*FreeClipInfo)(IMP_ClipInfo* pClipInfo);
typedef int (*CheckMediaType)(const char* szFileName,int * ptype);
typedef int (*GetCodecType)(const char* szFileName,ME_CODECTYPE* pCodecType);
typedef int (*GetMotoTag)(const char* szFileName,
                          int * pmotoflag,
                          unsigned char ** ppsmartalbum,
                          int * psmartalbumsize,
                          unsigned char ** ppthumbnail,
                          int * pthumbnailsize);

typedef int (*GetTrackType)( const char* szFileName,
                             int * pType);
class MMMediaExtractor : public MMMetaDataControl
{
public:
    MMMediaExtractor();

    ~MMMediaExtractor() ;

    MMResult open( const MMString& cp_locator);

    MMResult close();

    MMResult getVideoFrame(int num, char*& pr_buffer, int& r_size);

    MMResult getAudioData(int beginTime, int endTime, char*& pr_data, int& r_size);

    virtual MMResult getKeys(MMKeyList& r_keyList, int& r_numOfKeys);

    virtual MMResult getKeyValue(MMKey key, MMMetaItem& r_value); 

    virtual MMResult getValues(MMMetaItemList& r_values, int& r_numOfValues);

    virtual MMResult getMetainfoValue(MMMetaInfo& r_metaInfo);

    virtual MMResult getClipinfoValue(MMClipInfo& r_clipInfo);

    MMResult getTrackType( int * pType);
MM_PRIVATE:
    MMResult getMetaInfo();
    MMResult getMetaData();
    int getKeyNumAndData(MMMetaItem * pmetainfolist = NULL);
MM_PRIVATE:
    IMP_MetaInfo * m_pmetainfo;
    IMP_ClipInfo * m_pclipinfo;
    ME_CODECTYPE * m_pcodectype;
    ME_MOTOTAGINFO * m_pmototag;

    char* m_pfilename; 
    MMMetaItem * m_pmetainfolist;

    void * m_phandle; 
    int m_keynum; 

    pthread_mutex_t     a_mtMediaExtractor;
};

#endif  

