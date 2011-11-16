

// Copyright (c) 20-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMMETADATACONTROL_H 
#define MMMETADATACONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMResult.h"
#include "MMGeneral.h"
#include "MMString.h"
typedef enum
{
    MMMETADATA_AUTHOR_KEY = 0x0001,       
    MMMETADATA_COPYRIGHT_KEY,             
    MMMETADATA_DATE_KEY,                  
    MMMETADATA_TITLE_KEY,                 
    MMMETADATA_ALBUM_KEY,                 
    MMMETADATA_GENRE_KEY,                 
    MMMETADATA_YEAR_KEY,                  
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
    MMMETADATA_PICTURETYPE_KEY,           
    MMMETADATA_ARTWORK_KEY,               
    MMMETADATA_RATING_KEY,                
    MMMETADATA_PLAYCOUNT_KEY,             
    MMMETADATA_ALBUMARTIST_KEY,           

    MMMETADATA_GIFANIMATION_KEY,          

    MMMETADATA_HAVEAUDIO_KEY,             
    MMMETADATA_HAVEVIDEO_KEY,             

    MMMETADATA_TOTALSIZE_KEY,             
    MMMETADATA_DURATION_KEY,              
    MMMETADATA_TOTALBITRATE_KEY,          
    MMMETADATA_COPYPROTECTED_KEY,         
    MMMETADATA_NUMOFAUDIOSTREAMS_KEY,         
    MMMETADATA_NUMOFVIDEOSTREAMS_KEY,         
    MMMETADATA_AUDIOBITRATE_KEY,          
    MMMETADATA_AUDIOCHANNELS_KEY,         
    MMMETADATA_AUDIOFRAMESIZE_KEY,        
    MMMETADATA_AUDIOBITSPERSAMPLE_KEY,    
    MMMETADATA_AUDIOFRAMES_KEY,           
    MMMETADATA_AUDIOSAMPLERATE_KEY,       
    MMMETADATA_AUDIOMAXBLOCKSIZE_KEY,     

    MMMETADATA_VIDEOWIDTH_KEY,            
    MMMETADATA_VIDEOHEIGHT_KEY,           
    MMMETADATA_VIDEOBITRATE_KEY,          
    MMMETADATA_VIDEOFPS_KEY,              
    MMMETADATA_VIDEOFRAMES_KEY,           
    MMMETADATA_VIDEOSTRIDE_KEY,           
    MMMETADATA_VIDEOCOLORMODE_KEY,        
    MMMETADATA_VIDEOBITSPERPIXEL_KEY,     

    MMMETADATA_CODEC_KEY,                     
    MMMETADATA_AUDIOCODECTYPE_KEY,        
    MMMETADATA_AUDIOCODECLEVEL_KEY,       
    MMMETADATA_VIDEOCODECTYPE_KEY,        
    MMMETADATA_VIDEOCODECLEVEL_KEY,       

    MMMETADATA_MOTO_SMARTALBUM_KEY,       
    MMMETADATA_MOTO_THUMBNAIL_KEY,        

    MMMETADATA_CANSEEK_KEY,               
    MMMETADATA_ISLIVE_KEY,                
    MMMETADATA_CREATETIME_KEY             

}MMMetadataKey;

typedef enum
{
    MMCODECTYPE_MP3_LAYER1 = 0x1001,  
    MMCODECTYPE_MP3_LAYER2 = 0x1002,  
    MMCODECTYPE_MP3_LAYER3 = 0x1003,  

    MMCODECTYPE_AMR_NB = 0x1010,      
    MMCODECTYPE_AMR_WB = 0x1020,      

    MMCODECTYPE_WAVE_PCM   = 0x1030,  
    MMCODECTYPE_WAVE_ADPCM = 0x1031,  
    MMCODECTYPE_WAVE_ALAW  = 0x1032,  
    MMCODECTYPE_WAVE_MULAW = 0x1033,  

    MMCODECTYPE_AAC         = 0x2001,  
    MMCODECTYPE_AAC_PLUS    = 0x2002,  
    MMCODECTYPE_AAC_ENHANCE = 0x2003,  

    MMCODECTYPE_RMAUDIO_SIPR = 0x3001, 
    MMCODECTYPE_RMAUDIO_COOK = 0x3002, 
    MMCODECTYPE_RMAUDIO_ATRC = 0x3003, 
    MMCODECTYPE_RMAUDIO_RAAC = 0x3004, 
    MMCODECTYPE_RMVIDEO_RV10 = 0x3010, 
    MMCODECTYPE_RMVIDEO_RV20 = 0x3020, 
    MMCODECTYPE_RMVIDEO_RV30 = 0x3030, 
    MMCODECTYPE_RMVIDEO_RV40 = 0x3040, 

    MMCODECTYPE_MP4VIDEO_MP4V = 0x4001, 
    MMCODECTYPE_MP4AUDIO_MP4A = 0x4002, 
    MMCODECTYPE_MP4VIDEO_S263 = 0x4003, 
    MMCODECTYPE_MP4VIDEO_S264 = 0x4004, 
    MMCODECTYPE_MP4AUDIO_SAMR = 0x4005, 
    MMCODECTYPE_MP4AUDIO_SAWP = 0X4006  
}MMCodecType;

typedef enum
{
    MMMEDIATYPE_MP3           = 0x00000001, 
    MMMEDIATYPE_RM            = 0x00000002, 
    MMMEDIATYPE_MP4_3GP       = 0x00000003, 
    MMMEDIATYPE_ASF           = 0x00000004, 
    MMMEDIATYPE_MIDI          = 0x00000005, 
    MMMEDIATYPE_AAC           = 0x00000006, 
    MMMEDIATYPE_WAVE          = 0x00000007, 
    MMMEDIATYPE_AMR_NB        = 0x00000008, 
    MMMEDIATYPE_AMR_WB        = 0x00000009, 
    MMMEDIATYPE_NODEFINE      = 0x000000ff  
}MMMediaType;

typedef enum
{
    MMLICENSETYPE_PLAINTEXT       = 0x00000001, 
    MMLICENSETYPE_NOT_ALLOWED     = 0x00000002, 
    MMLICENSETYPE_UNLIMT          = 0x00000003, 
    MMLICENSETYPE_COUNT_BASE      = 0x00000004, 
    MMLICENSETYPE_TIME_BASE       = 0x00000005, 
    MMLICENSETYPE_PREVIEW_ONLY    = 0x00000006, 
    MMLICENSETYPE_SILENT_URL      = 0x00000007, 
}MMLicenseType;

static const MMString MMContentType[] = {"not support",            
                                         "audio/AMR",              
                                         "audio/AMR-WB",           
                                         "audio/AAC",              
                                         "audio/x-wav",            
                                         "audio/mpeg",             
                                         "audio/mp4",              
                                         "video/mp4",              
                                         "audio/3gpp",             
                                         "video/3gpp",             
                                         "audio/vnd.rn-realaudio", 
                                         "video/vnd.rn-realvideo", 
                                         "audio/x-ms-wma",         
                                         "video/x-ms-wmv",         
                                         "audio/midi",             
                                         "audio/mid",              
                                         "audio/smf",              
                                         "audio/imelody",          
                                         "audio/xmf",              
                                         "audio/mmf"               
                                        };

#define MMCONTENT_AMR       0x00000001
#define MMCONTENT_AMRWB     0x00000002
#define MMCONTENT_AAC       0x00000003
#define MMCONTENT_WAV       0x00000004
#define MMCONTENT_MP3       0x00000005
#define MMCONTENT_MP4AUDIO  0x00000006
#define MMCONTENT_MP4VIDEO  0x00000007
#define MMCONTENT_3GPAUDIO  0x00000008
#define MMCONTENT_3GPVIDEO  0x00000009
#define MMCONTENT_RMAUDIO   0x0000000a
#define MMCONTENT_RMVIDEO   0x0000000b
#define MMCONTENT_ASFAUDIO  0x0000000c
#define MMCONTENT_ASFVIDEO  0x0000000d
#define MMCONTENT_MIDI      0x0000000e
#define MMCONTENT_MID       0x0000000f
#define MMCONTENT_SMF       0x00000010
#define MMCONTENT_IMY       0x00000011
#define MMCONTENT_XMF       0x00000012
#define MMCONTENT_MMF       0x00000013
#define MMCONTENT_NONE      0x00000000

#define MMFOURCHAR2INT32(a, b, c, d) ( (((unsigned char)(a)) << 24) | (((unsigned char)(b)) << 16) | \
                                       (((unsigned char)(c)) << 8)  | ((unsigned char)(d)) )

#define MMFILETYPE_AMR      MMFOURCHAR2INT32('a', 'm', 'r', 0x00)
#define MMFILETYPE_AWB      MMFOURCHAR2INT32('a', 'w', 'b', 0x00)
#define MMFILETYPE_AAC      MMFOURCHAR2INT32('a', 'a', 'c', 0x00)
#define MMFILETYPE_WAV      MMFOURCHAR2INT32('w', 'a', 'v', 0x00)
#define MMFILETYPE_MP3      MMFOURCHAR2INT32('m', 'p', '3', 0x00)
#define MMFILETYPE_MP4      MMFOURCHAR2INT32('m', 'p', '4', 0x00)
#define MMFILETYPE_M4A      MMFOURCHAR2INT32('m', '4', 'a', 0x00)
#define MMFILETYPE_3GP      MMFOURCHAR2INT32('3', 'g', 'p', 0x00)
#define MMFILETYPE_3GA      MMFOURCHAR2INT32('3', 'g', 'a', 0x00)
#define MMFILETYPE_RM       MMFOURCHAR2INT32('r', 'm', 0x00, 0x00)
#define MMFILETYPE_RMVB     MMFOURCHAR2INT32('r', 'm', 'v', 'b')
#define MMFILETYPE_RA       MMFOURCHAR2INT32('r', 'a', 0x00, 0x00)
#define MMFILETYPE_RV       MMFOURCHAR2INT32('r', 'v', 0x00, 0x00)
#define MMFILETYPE_ASF      MMFOURCHAR2INT32('a', 's', 'f', 0x00)
#define MMFILETYPE_WMA      MMFOURCHAR2INT32('w', 'm', 'a', 0x00)
#define MMFILETYPE_WMV      MMFOURCHAR2INT32('w', 'm', 'v', 0x00)
#define MMFILETYPE_MID      MMFOURCHAR2INT32('m', 'i', 'd', 0x00)
#define MMFILETYPE_XMF      MMFOURCHAR2INT32('x', 'm', 'f', 0x00)
#define MMFILETYPE_MMF      MMFOURCHAR2INT32('m', 'm', 'f', 0x00)
#define MMFILETYPE_IMY      MMFOURCHAR2INT32('i', 'm', 'y', 0x00)
#define MMFILETYPE_SMF      MMFOURCHAR2INT32('s', 'm', 'f', 0x00)
#define MMFILETYPE_MIDI     MMFOURCHAR2INT32('m', 'i', 'd', 'i')

#define STREAMTYPE_AUDIO      ((int)0x00000001L)   
#define STREAMTYPE_VIDEO      ((int)0x00000010L)   

#define STREAMTYPE_AUDIOANDVIDEO (STREAMTYPE_AUDIO | STREAMTYPE_VIDEO)

#define MMIMP_STR_LEN  (128)

typedef enum
{
    MMENCODETYPE_INTEGER     = 0, 
    MMENCODETYPE_BITFIELD,        
    MMENCODETYPE_BINARY,          
    MMENCODETYPE_ASCII,           
    MMENCODETYPE_UTF16BE,         
    MMENCODETYPE_UTF8,            
    MMENCODETYPE_UTF16LE          
}MMEncodingType;

enum MMStartType
{
    MMSTARTTYPE_PLAY_ASAP,
    MMSTARTTYPE_USER_PLAY,
    MMSTARTTYPE_DOWNLOAD_ONLY,
    MMSTARTTYPE_USER_END_PLAY,
    MMSTARTTYPE_DOWNLOAD_END_PLAY
};

typedef struct MMMetaItem
{
    int key_type;                        
    int encoding_type;                   
    int data_size;                       
    unsigned char * p_data;              

    MMMetaItem ()
    {
        p_data = NULL;
    }

    ~MMMetaItem ()
    {
        if (p_data != NULL)
        {
            delete []p_data;
            p_data = NULL;
        }
    }

    MMMetaItem (const MMMetaItem & item)
    {
        key_type = item.key_type;
        encoding_type = item.encoding_type;
        data_size = item.data_size;
        if (item.p_data)
        {
            p_data = new unsigned char[item.data_size];
            memcpy(p_data, item.p_data, item.data_size);
        }
    }

    MMMetaItem & operator = (const MMMetaItem & item)
    {
        if(this == &item)
            return *this;
        key_type = item.key_type;
        encoding_type = item.encoding_type;
        data_size = item.data_size;
        if (item.p_data)
        {
            p_data = new unsigned char[item.data_size];
            memcpy(p_data, item.p_data, item.data_size);
        }
        return *this;
    }
} *PMMMetaItem;

typedef struct MMMetaInfoItem
{
    int    encoding_type;           
    char   data[ MMIMP_STR_LEN ];   
    int    size;                    
};

typedef struct MMMetaInfo
{
    MMMetaInfoItem title;       
    MMMetaInfoItem artist;      
    MMMetaInfoItem album;       
    MMMetaInfoItem genre;       
    MMMetaInfoItem year;        
    MMMetaInfoItem copyright;   
    MMMetaInfoItem lyrics;       
    MMMetaInfoItem composer;     
    MMMetaInfoItem tracknum;     
    MMMetaInfoItem language;    
    MMMetaInfoItem comment;     

    MMMetaInfoItem file_type;   
    MMMetaInfoItem director;    
    MMMetaInfoItem studio;      
    MMMetaInfoItem record_date; 
    MMMetaInfoItem record_time; 

    MMMetaInfoItem pic_type;    
    char*           art_work;   
    unsigned int    buf_len;    

    unsigned int    rating;     
    unsigned int    play_count; 
    MMMetaInfoItem album_artist;
    unsigned int    codec;      

    MMMetaInfo()
    {
        art_work = NULL;
    }
    ~MMMetaInfo()
    {
        if (art_work != NULL)
        {
            delete []art_work;
            art_work = NULL;
        }
    }
} *PMMMetaInfo;

typedef struct MMLicenseInfo
{
    MMLicenseType  license_category;  
    unsigned long  count_remaining;   
    time_t         time_remaining;    
};

typedef struct MMFTInfo
{
    bool         security_flag;           
    MMStartType  start_type;              
    char *       url_in_pvx;              

    MMFTInfo()
    {
        url_in_pvx = NULL;
        start_type = MMSTARTTYPE_PLAY_ASAP;
        security_flag = false; 
    }

    ~MMFTInfo()
    {
        if(url_in_pvx != NULL)
        {
            delete []url_in_pvx;
            url_in_pvx = NULL;
        }
    }

};

typedef struct MMClipInfo
{
    char file_type[ MMIMP_STR_LEN ];           
    int file_size;                             
    int file_duration;                         
    int file_bitrate;                          
    int file_create_time;                      

    int drm_protected;                         
    int num_audio_streams;                     

    int num_video_streams;                     

    int audio_bitrate;                         
    int max_sample_rate;                       
    int max_channels;                          
    int bits_per_sample;                       
    int max_block_size;                        

    int video_bitrate;                          
    int frame_width;                           
    int frame_height;                          
    int frame_rate;                            

    char audio_content_type[ MMIMP_STR_LEN ]; 
    char video_content_type[ MMIMP_STR_LEN ]; 

    int seekable;                             
    int live;                                 
    char file_name[ MMIMP_STR_LEN ];          

    MMLicenseInfo license_info;               
    int is_fast_track;                      
    MMFTInfo           ft_info;                
};

typedef MMMetaItem* MMMetaItemList;

typedef int  MMKey;

typedef MMKey* MMKeyList;

class MMMetaDataControl
{
public:
    virtual MMResult getKeys(MMKeyList& r_keyList, int& r_numOfKeys) = 0;

    virtual MMResult getKeyValue(MMKey key, MMMetaItem& r_value) = 0; 

    virtual MMResult getValues(MMMetaItemList& r_values, int& r_numOfValues) = 0;

    virtual MMResult getMetainfoValue(MMMetaInfo& r_metaInfo) = 0;

    virtual MMResult getClipinfoValue(MMClipInfo& r_clipInfo) = 0;

protected:
    virtual ~MMMetaDataControl(){}
};

#endif  

