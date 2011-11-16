

// Copyright (c)  - 2008 Motorola, Inc. All rights reserved.



#ifndef ZMediaSDK_H_
#define ZMediaSDK_H_

#ifndef MPTRACE
#define MPTRACE(...)
#endif 


#ifndef JSR135_SUPPORTED
#define JSR135_SUPPORTED
#endif 

#ifndef MPERROR_DEFINED
#define MPERROR_DEFINED

enum 
{
    MPERR_NONE = 0,                                        
    MPERR_SYS,                                               
    MPERR_NOT_SUPPORTED,                         
    MPERR_MISSING_PLUGIN,                        
    MPERR_EOF,                                   
    MPERR_INVALID_PLUGIN,                        
    MPERR_INTERFACE_NOT_IMPLEMENTED,             
    MPERR_AUDIO_DEVICE_OPEN_FAILED,              
    MPERR_NO_OPEN_FILE,                                
    MPERR_NOT_INITIALIZED,                           
    MPERR_INITIALIZE_FAILED,                        
    MPERR_WITHOUT_DRM_AUTH,                       
    MPERR_GENERAL,                                         
    MPERR_INVALID_FILE,                                 
    MPERR_MA3_BAD_MEDIA_FILE_NAME,                
    MPERR_MA3_FILE_SIZE_TOO_BIG,                 
    MPERR_MA3_MIDDLEWARE_ERROR,                  
    MPERR_MA3_NO_AUDIO_DEVICE,                   
    MPERR_MA3_CLOSE_2ND_SOCKET_ERROR,            
    MPERR_MA3_OPEN_2ND_SOCKET_ERROR,             
    MPERR_MA3_2ND_READ_ERROR,                    
    MPERR_MA3_CLOSE_DEVICE_ERROR,                
    MPERR_MA3_BAD_MEDIA_FILE,                    
    MPERR_NET_CONNECT_FAIL,                      
    MPERR_NET_URL_FAIL,                          
    MPERR_NET_SERVER_TIMEOUT,                    
    MPERR_RIGHTS_EXPIRED,                       
    MPERR_FTDC_GET_SDP_FAIL,                    
    MPERR_FTDC_NO_ENOUGH_SPACE,                 
    MPERR_FTDC_CONNECTION_LOST,                 
    MPERR_FTDC_FAIL,                            
    MPERR_FIFO_FAILED,                          
    MPERR_WMDRM_GENERAL,                        
    MPERR_WMDRM_BlUETOOTH_OUTPUTLEVEL,          
    MPERR_OMA_BLUETOOTH_CAPDEV,                 

    MPERR_MEDL_RESUMABLE,                       
    MPERR_MEDL_FATAL,                           
    MPERR_MEDL_GENERAL,                         
    MPERR_MEDL_STATE_MACHINE                    
};

typedef unsigned short MPError;

#endif 

typedef void (*LowWatermarkFunc) (void *mphx_hwvidadpt);

class IMP_HWVideoAdapter
{
	public:		
	  enum VideoType
	  {
	  	VIDEO_H263     = 0,
	  	VIDEO_H264,
	  	VIDEO_MPEG4,
	  	VIDEO_REAL_V8,    	
	  	VIDEO_REAL_V9,			
	  	VIDEO_WMV_V7,
	  	VIDEO_WMV_V8,
	  	VIDEO_WMV_V9
	  };

	struct VideoHeaderInfo
    {
        VideoType ulVideoType;
        unsigned int ulFrameWidth;
        unsigned int ulFrameHeight;

        unsigned char*  szSpecificData;
        unsigned int iDataLength;
    };

    struct VideoBuffer
    {
        int      iKeyFrame;
        unsigned int iFrameNumber;            
        unsigned int iTimeStamp;
        bool     bTImeStampValid;
        bool     bEndofFrame;

        unsigned int ulBufferLen;
        unsigned char* szBuffer;
    };

    virtual int MEDLInit( VideoHeaderInfo* pHeaderInfo, VideoBuffer* pFirstFrame ) = 0;

    virtual int Start( ) = 0;

    virtual int Stop( ) = 0;    

    virtual int OutputFrame( VideoBuffer* pBuffer ) = 0;

    virtual int EndofPackets( ) = 0;         

    virtual int Reset( ) = 0;

    virtual int SetTime( unsigned int ulTime ) = 0;

    virtual int Pause( ) = 0;

    virtual int SetLowWatermarkCB(LowWatermarkFunc fpLowWaterMark, void *mphx_hwvidadpt) = 0;
};

class IMP_AudioDevice
{
public:

    virtual int GetPriority() = 0;

    virtual int Open(unsigned long ulSamplesPerSec, 
                     unsigned short uChannels, 
                     unsigned short uBitsPerSample) = 0; 

    virtual int Close() = 0;

    virtual int Write(const unsigned char* pAudioData, 
                      unsigned long nDataLen,
                      unsigned long nAudioTime) = 0;

    virtual int Flush() = 0;

    virtual int CheckFormat(unsigned long ulSamplesPerSec, 
                            unsigned short uChannels, 
                            unsigned short uBitsPerSample) = 0;

    virtual int GetCurrentAudioTime(unsigned long& ulCurrentTime) = 0;

    virtual int Refresh() = 0;
};

class IMP_VideoDevice
{
public:

    enum ImageType
    {
        MPSDK_IMAGE_I420 = 0,           
        MPSDK_IMAGE_RGB565,             
        MPSDK_IMAGE_RGB666,             
        MPSDK_IMAGE_RGB888,             
        MPSDK_NUM_OF_IMAGE_TYPES        
    };

    virtual int InitDisplay(ImageType ulSrcType) = 0;

    virtual int DisplayFrame(unsigned char* pSrcBuffer, int nSrcWidth, int nSrcHeight) = 0;

    virtual int EndDisplay() = 0;
};

class IMP_NetworkService
{
};

class IMP_EventHandler
{
public:

    virtual int OnPosLength(unsigned int nPos, unsigned int nLength) = 0;

    virtual int OnPresentationOpened() = 0;

    virtual int OnPresentationClosed() = 0;

    virtual int OnPreSeek() = 0;

    virtual int OnPostSeek() = 0;

    virtual int OnBegin() = 0;

    virtual int OnStop() = 0;

    virtual int OnPause() = 0;

    virtual int OnContacting(const char* pHost) = 0;

    virtual int OnContacted() = 0;

    virtual int OnBuffering(unsigned int nFlags, unsigned short sPercent) = 0;

    virtual int OnError(unsigned long nErrorCode, const char* saplog_errString) = 0;

    virtual int OnDownloadProgress(unsigned int ulNewDurSoFar, unsigned int ulNewBytesSoFar) = 0;

    virtual int OnTotalDurChanged(unsigned int ulNewTotalDur) = 0;

    virtual int OnDownloadComplete() = 0;
};

#define IMP_STR_LEN    128

struct IMP_MetaItem
{
    int    nEncodingType;       
    char   szData[IMP_STR_LEN]; 
    int    size;                
};

struct IMP_MetaInfo
{
    IMP_MetaItem szTitle;       
    IMP_MetaItem szArtist;      
    IMP_MetaItem szAlbum;       
    IMP_MetaItem szGenre;       
    IMP_MetaItem szYear;        
    IMP_MetaItem szCopyright;   
    IMP_MetaItem szLyrics;       
    IMP_MetaItem szComposer;     
    IMP_MetaItem szTracknum;     
    IMP_MetaItem szLanguage;    
    IMP_MetaItem szComment;    

    IMP_MetaItem szFileType;    
    IMP_MetaItem szDirector;    
    IMP_MetaItem szStudio;      
    IMP_MetaItem szRecordDate;  
    IMP_MetaItem szRecordTime;  

    IMP_MetaItem szPicType;     
    char*        szArtWork;     
    unsigned int szBufLen;      

    unsigned int szRating;      
    unsigned int szPlayCount;   
    IMP_MetaItem szAlbumArtist; 
    unsigned int szCodec; 
};

class IMP_ClipInfo
{
public:
    char szFileType[ IMP_STR_LEN ];            
    int nFileSize;                             
    int nFileDuration;                         
    int nFileBitrate;                          
    int nFileCreateTime;                       

    int nDRMProtected;                         
    int nNumOfAudioStreams;                    
    int nNumOfVideoStreams;                    

    int nAudioBitrate;                         
    int nMaxSampleRate;                        
    int nMaxChannels;                          
    int nBitsPerSample;                        
    int nMaxBlockSize;                         

    int nVideoBitrate;                          
    int nFrameWidth;                           
    int nFrameHeight;                          
    int nFrameRate;                            

    char szAudioContentType[ IMP_STR_LEN ];     
    char szVideoContentType[ IMP_STR_LEN ];     
};

extern "C" int MP_Metainfo_GetTrackType( const char* szFileName,
                                                     int * pType);
extern "C" int MP_Metainfo_GetMetaInfo( const char* szFileName,
                                        IMP_MetaInfo* &pMetaData);
extern "C" int MP_Metainfo_FreeMetaInfo( IMP_MetaInfo* &pMetaData);

#ifdef JSR135_SUPPORTED

class IMP_DataFifo
{
public:
    virtual ~IMP_DataFifo() {}

    virtual int Open() = 0;

    virtual void Close() = 0;

    virtual unsigned int GetDataSize() const = 0;

    virtual unsigned int GetSpaceSize() const = 0;

    virtual unsigned int GetReadPos() const = 0;

    virtual int Read(unsigned char* pBuf, unsigned int reqSize, unsigned int& readSize) = 0;

    virtual int Seek(unsigned int gOffset) = 0;

    virtual int Skip(int lOffset) = 0;

    virtual void Reset() = 0;

    virtual char const* GetContentType() const = 0;

};

#endif

#ifdef USE_FIFO
class IMP_FifoBuffer
{
public:
    virtual int Write(unsigned char* pBuf, int iSize, bool fileEnd)=0;
    virtual int GetEmptySize()=0;
    virtual int GetBufferedSize()=0;
    virtual void* GetHandle()=0;
};
#endif  

class IMP_PlayerEngine
{
public:

    virtual int SetAudioDevice(IMP_AudioDevice* pAudDev) = 0;

    virtual int SetVideoDevice(IMP_VideoDevice* pVidDev) = 0;

    virtual int SetHWVideoAdapter(IMP_HWVideoAdapter* pVidDev)
    {
        return MPERR_NOT_SUPPORTED;
    }; 

    virtual int SetNetworkService(IMP_NetworkService* pNetSvc) = 0;

    virtual int SetEventHandler(IMP_EventHandler* pEvtHdlr) = 0;

    virtual int Initialize() = 0;

    virtual int Terminate() = 0;

    virtual int GetMetaInfoQuickly(const char* szfilename, IMP_MetaInfo& metaInfo) = 0;

    virtual int GetClipInfoQuickly(const char* szURL, IMP_ClipInfo& pClipInfo) = 0;

    virtual int SetPreference(const char* szName, const char* szValue) = 0;

    virtual int GetPreference(const char* szName, char* szValue) = 0;

    virtual int EnableAudio(bool bEnable) = 0;

    virtual int OpenURL(const char* szURL) = 0;

    virtual int Play() = 0;

    virtual int Pause() = 0;

    virtual int Seek(unsigned long nPos) = 0;

    virtual int Stop() = 0;

    virtual int Close() = 0;

    virtual bool IsLive() = 0;

    virtual int GetClipInfo(IMP_ClipInfo*& pClipInfo) = 0;

    virtual int GetMetaInfo(IMP_MetaInfo*& pMetaInfo) = 0;

    virtual int GetCurrentPlayTime(unsigned long& ulCurrentTime) = 0;

    virtual int FastForward() = 0;

    virtual int FastRewind() = 0;

#ifdef USE_FIFO
    virtual int  OpenURL(const char* szURL, void* pFifoBuffer) = 0;
    virtual bool CreateFifo(IMP_FifoBuffer** ppFifoBuf)=0;
	virtual bool ReleaseFifo(IMP_FifoBuffer* pFifoBuf)=0;
#endif 

#ifdef JSR135_SUPPORTED
    virtual int OpenDataFifo(IMP_DataFifo*) = 0;
#endif 
};

extern "C" int MP_CreateInstance(IMP_PlayerEngine** ppEngine);

extern "C" int MP_FreeInstance(IMP_PlayerEngine* pEngine);

#endif 
#include <libaplog.h>
