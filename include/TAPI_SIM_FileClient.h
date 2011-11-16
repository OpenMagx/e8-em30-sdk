

// Copyright (c) 22-Nov-06 - 2008 Motorola, Inc. All rights reserved.


#ifndef _TAPI_SIM_FILE_CLIENT_H    
#define _TAPI_SIM_FILE_CLIENT_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "EZX_TypeDefs.h"
#include "TAPI_General.h"
#include "TAPI_SETUP_General.h"
#include "TAPI_CB_Client.h"
#include "TAPI_SIM_InternalAppData.h"

#define TAPI_SIM_MAX_READ_DATA_LEN (256)

#define TAPI_SIM_MAX_WRITE_DATA_LEN (255)

#define SIM_FILENAME_LENGTH_MIN 1

#define SIM_FILENAME_LENGTH_MAX 20

#define SIM_FILEREAD_MAXLENGTH 256

#define SIM_LANGUAGE_FILENAME "3F007F206F05"

#define TAPI_MAX_NUM_CHV  20

#define min_val(a,b) (((a)<(b))?(a):(b))

enum
{
    TAPI_ACCESS_COND_ALW,   
    TAPI_ACCESS_COND_VAR,   
    TAPI_ACCESS_COND_CHV1,  
    TAPI_ACCESS_COND_UPIN,  
    TAPI_ACCESS_COND_CHV2,  
    TAPI_ACCESS_COND_ADM,   
    TAPI_ACCESS_COND_NEVER, 
    TAPI_ACCESS_COND_UNKNOWN  
};
typedef UINT8 TAPI_ACCESS_COND_T;

enum
{
    TAPI_ACCESS_COMBINATION_OR = 0,   
    TAPI_ACCESS_COMBINATION_AND       
}; 
typedef UINT8 TAPI_ACCESS_COMBINATION_T;

enum _TAPI_SIM_FILE_TYPE_E
{
    TAPI_SIM_FILE_TYPE_BINARY_EV = 0,        
    TAPI_SIM_FILE_TYPE_RECORD_EV,            
    TAPI_SIM_FILE_TYPE_INVALID_EV            
};
typedef UINT16      TAPI_SIM_FILE_TYPE_E;           

typedef enum                    _TAPI_SIM_FILE_FLAG_E
{
    TAPI_SIM_FILE_READ_FLAG_SUCCESS         = 0,    
    TAPI_SIM_FILE_READ_FLAG_ERROR   
} TAPI_SIM_FILE_FLAG_E;

typedef enum    _TAPI_SIM_FILE_WRITE_STATUS_E
{
    TAPI_SIM_FILE_WRITE_SUCCESS             = 0,    
    TAPI_SIM_FILE_WRITE_ERROR           
} TAPI_SIM_FILE_WRITE_STATUS_E;

enum
{
    TAPI_SIM_EF_EXT8_TYPE_CALLED_PARTY_SUBADDRESS = 0x01, 
    TAPI_SIM_EF_EXT8_TYPE_ADDITIONAL_DATA         = 0x02, 
    TAPI_SIM_EF_EXT8_TYPE_RFU                     = 0X00  
};
typedef UINT8 TAPI_SIM_EF_EXT8_RECORD_TYPE_E;

enum
{
    TAPI_SIM_EF_MMSUP_TAG_IMPLEMENTATION = 0x80,
    TAPI_SIM_EF_MMSUP_TAG_PROFILE_NAME   = 0x81,
    TAPI_SIM_EF_MMSUP_TAG_INFORMATION    = 0x82
};
typedef UINT8 TAPI_SIM_EF_MMSUP_TAG_E;

enum
{
    TAPI_SIM_EF_MMSCP_TAG_CONNECTIVITY_PARAMETERS = 0xAB,
    TAPI_SIM_EF_MMSCP_TAG_IMPLEMENTATION          = 0x80,
    TAPI_SIM_EF_MMSCP_TAG_RELAY_SERVER            = 0x81,
    TAPI_SIM_EF_MMSCP_TAG_BEARER_INFO             = 0x82,
    TAPI_SIM_EF_MMSCP_TAG_GATEWAY                 = 0x83,
    TAPI_SIM_EF_MMSCP_AUTHENTICATION_MECHANISM    = 0x84,
    TAPI_SIM_EF_MMSCP_AUTHENTICATION_USERNAME     = 0x85

};
typedef UINT8 TAPI_SIM_EF_MMSCP_TAG_E;

enum 
{
    TAPI_SIM_MF_DIR = 0,        
    TAPI_SIM_DIR,
    TAPI_SIM_PL,
    TAPI_SIM_MF_ARR,
    TAPI_SIM_ICCID,
    TAPI_SIM_TELECOM_DIR,
    TAPI_SIM_TELECOM_ARR,
    TAPI_SIM_GLOBAL_ADN,
    TAPI_SIM_FDN,
    TAPI_SIM_SMS,
    TAPI_SIM_GLOBAL_CCP1,       
    TAPI_SIM_ECCP,
    TAPI_SIM_MSISDN,
    TAPI_SIM_SMSP,
    TAPI_SIM_SMSS,
    TAPI_SIM_LND,
    TAPI_SIM_SMSR,
    TAPI_SIM_SDN,
    TAPI_SIM_GLOBAL_EXT1,
    TAPI_SIM_EXT2,
    TAPI_SIM_EXT3,              
    TAPI_SIM_BDN,
    TAPI_SIM_EXT4,
    TAPI_SIM_SUME,
    TAPI_SIM_CMI,
    TAPI_SIM_PINBALL_YN,
    TAPI_SIM_GLOBAL_PHONEBOOK_DIR,
    TAPI_SIM_GLOBAL_PSC,
    TAPI_SIM_GLOBAL_CC,
    TAPI_SIM_GLOBAL_PUID,
    TAPI_SIM_GLOBAL_PBR,        
    TAPI_SIM_GLOBAL_IAP,
    TAPI_SIM_GLOBAL_SNE,
    TAPI_SIM_GLOBAL_ANR,
    TAPI_SIM_GLOBAL_PBC,
    TAPI_SIM_GLOBAL_GRP,
    TAPI_SIM_GLOBAL_AAS,
    TAPI_SIM_GLOBAL_GAS,
    TAPI_SIM_GLOBAL_UID,
    TAPI_SIM_GLOBAL_EMAIL,
    TAPI_SIM_GRAPHICS_DIR,      
    TAPI_SIM_IMG,
    TAPI_SIM_GSM_DIR,
    TAPI_SIM_LI,
    TAPI_SIM_IMSI,
    TAPI_SIM_CPHS_VMW,
    TAPI_SIM_CPHS_SST,
    TAPI_SIM_CPHS_CFF,
    TAPI_SIM_CPHS_ONS,
    TAPI_SIM_CPHS_CSP,
    TAPI_SIM_CPHS_INFO,         
    TAPI_SIM_CPHS_MBN,
    TAPI_SIM_CPHS_ONSF,
    TAPI_SIM_CPHS_IN,
    TAPI_SIM_KC,
    TAPI_SIM_DCK,
    TAPI_SIM_PLMNSEL,
    TAPI_SIM_HPLMN,
    TAPI_SIM_CNL,
    TAPI_SIM_ACMMAX,
    TAPI_SIM_UST,               
    TAPI_SIM_ACM,
    TAPI_SIM_GID1,
    TAPI_SIM_GID2,
    TAPI_SIM_PUCT,
    TAPI_SIM_CBMI,
    TAPI_SIM_SPN,
    TAPI_SIM_CBMID,
    TAPI_SIM_CBMIR,
    TAPI_SIM_NIA,
    TAPI_SIM_KCGPRS,            
    TAPI_SIM_PSLOCI,
    TAPI_SIM_PLMNWACT,
    TAPI_SIM_OPLMNWACT,
    TAPI_SIM_HPLMNWACT,
    TAPI_SIM_CPBCCH,
    TAPI_SIM_INVSCAN,
    TAPI_SIM_RPLMNACT,
    TAPI_SIM_BCCH,
    TAPI_SIM_ACC,
    TAPI_SIM_FPLMN,             
    TAPI_SIM_LOCI,
    TAPI_SIM_AD,
    TAPI_SIM_PHASE,
    TAPI_SIM_VGCS,
    TAPI_SIM_VGCSS,
    TAPI_SIM_VBS,
    TAPI_SIM_VBSS,
    TAPI_SIM_EMLPP,
    TAPI_SIM_AAEM,
    TAPI_SIM_GSM_ECC,           
    TAPI_SIM_USIM_ECC,
    TAPI_SIM_PNN,
    TAPI_SIM_OPL,
    TAPI_SIM_MBDN,
    TAPI_SIM_EXT6,
    TAPI_SIM_MBI,
    TAPI_SIM_MWIS,
    TAPI_SIM_CFIS,
    TAPI_SIM_EXT7,
    TAPI_SIM_SPDI,              
    TAPI_SIM_PINBALL_HZP,
    TAPI_SIM_PINBALL_LCD,
    TAPI_SIM_MEXE_DIR,
    TAPI_SIM_MEXE_ST,
    TAPI_SIM_ORPK,
    TAPI_SIM_ARPK,
    TAPI_SIM_TPRPK,
    TAPI_SIM_SOLSA_DIR,
    TAPI_SIM_SAI,
    TAPI_SIM_SLL,               
    TAPI_SIM_DCS1800_DIR,
    TAPI_SIM_MICROTEL_DIR,
    TAPI_SIM_MICROTEL_CT,
    TAPI_SIM_MICROTEL_DF2,
    TAPI_SIM_MICROTEL_SCT,
    TAPI_SIM_MICROTEL_ZI1,
    TAPI_SIM_MICROTEL_ZI2,
    TAPI_SIM_MICROTEL_CSP2,
    TAPI_SIM_MICROTEL_PARAM,
    TAPI_SIM_MICROTEL_ACM2,     
    TAPI_SIM_MICROTEL_DF1,
    TAPI_SIM_VIAG_DIR,
    TAPI_SIM_VIAG_HZP,
    TAPI_SIM_VIAG_HZC1,
    TAPI_SIM_VIAG_HZC2,
    TAPI_SIM_VIAG_HZC3,
    TAPI_SIM_VIAG_HZC4,
    TAPI_SIM_ADF_USIM_DIR,
    TAPI_SIM_ARR_ADF,
    TAPI_SIM_KEYS,              
    TAPI_SIM_KEYSPS,
    TAPI_SIM_EXT5,
    TAPI_SIM_EST,
    TAPI_SIM_ACL,
    TAPI_SIM_START_HFN,
    TAPI_SIM_THRESHOLD,
    TAPI_SIM_ICI,
    TAPI_SIM_OCI,
    TAPI_SIM_ICT,
    TAPI_SIM_OCT,               
    TAPI_SIM_HIDDENKEY,
    TAPI_SIM_NETPAR,
    TAPI_SIM_MMSN,
    TAPI_SIM_EXT8,
    TAPI_SIM_MMSICP,
    TAPI_SIM_MMSUP,
    TAPI_SIM_MMSUCP,
    TAPI_SIM_LOCAL_PHONEBOOK_DIR,
    TAPI_SIM_LOCAL_PSC,
    TAPI_SIM_LOCAL_CC,          
    TAPI_SIM_LOCAL_PUID,
    TAPI_SIM_LOCAL_PBR,
    TAPI_SIM_LOCAL_ADN,
    TAPI_SIM_LOCAL_IAP,
    TAPI_SIM_LOCAL_EXT1,
    TAPI_SIM_LOCAL_SNE,
    TAPI_SIM_LOCAL_ANR,
    TAPI_SIM_LOCAL_PBC,
    TAPI_SIM_LOCAL_GRP,
    TAPI_SIM_LOCAL_AAS,         
    TAPI_SIM_LOCAL_GAS,
    TAPI_SIM_LOCAL_UID,
    TAPI_SIM_LOCAL_EMAIL,
    TAPI_SIM_LOCAL_CCP1,
    TAPI_SIM_GSM_ACCESS_DIR,
    TAPI_SIM_SL_DIR,
    TAPI_SIM_SLST,
    TAPI_SIM_MOBILE_ID,
    TAPI_SIM_MOBILE_ID_TMSI,
    TAPI_SIM_CLONE_CARD,        
    TAPI_SIM_CING_3STRK,
    TAPI_SIM_AHPLMN,
    TAPI_SIM_TST,
    TAPI_SIM_IPSEC_USER,      
    TAPI_SIM_IPSEC_KEY, 
    TAPI_SIM_DCM_UICC,
    TAPI_SIM_DCM_SERIAL,
    TAPI_SIM_DCM_DCM1,
    TAPI_SIM_DCM_DCM_DIR,
    TAPI_SIM_DCM_IMODEPRO,      
    TAPI_SIM_DCM_IMODER,
    TAPI_SIM_DCM_PKI_DIR,
    TAPI_SIM_DCM_ACTIVATE,
    TAPI_SIM_DCM_CERTSTATE,
    TAPI_SIM_DCM_CERTA_DIR,
    TAPI_SIM_DCM_A_CERT,
    TAPI_SIM_DCM_A_PUBKEY,
    TAPI_SIM_DCM_CERTB_DIR,
    TAPI_SIM_DCM_B_CERT,
    TAPI_SIM_DCM_B_PUBKEY,      
    TAPI_SIM_DCM_CERTCA_DIR,
    TAPI_SIM_DCM_ROOT,
    TAPI_SIM_DCM_SUBROOT,
    TAPI_SIM_INFO_NUMS_OLD,
    TAPI_SIM_EHPLMN,
    TAPI_SIM_VIAG_TAGS,
    TAPI_SIM_VIAG_SLACCI1,
    TAPI_SIM_VIAG_SLACCI2,
    TAPI_SIM_VIAG_SLACCI3,
    TAPI_SIM_VIAG_SLACCI4,      
    TAPI_SIM_VIAG_UHZIUE,
    TAPI_SIM_ADF_ISIM_DIR,
    TAPI_SIM_ISIM_IMPI,
    TAPI_SIM_ISIM_DOMAIN,
    TAPI_SIM_ISIM_IMPU,
    TAPI_SIM_ISIM_ARR,
    TAPI_SIM_ISIM_AD,
    TAPI_SIM_ADF_PKCS15_DIR,
    TAPI_SIM_PKCS15_ODF,
    TAPI_SIM_PKCS15_TOKENINFO,  
    TAPI_SIM_PKCS15_UNUSEDSPACE,
    TAPI_SIM_PKCS15_PRKDF,
    TAPI_SIM_PKCS15_PUKDF,
    TAPI_SIM_PKCS15_TPUKDF,
    TAPI_SIM_PKCS15_SKDF,
    TAPI_SIM_PKCS15_CDF,
    TAPI_SIM_PKCS15_TCDF,
    TAPI_SIM_PKCS15_UCDF,
    TAPI_SIM_PKCS15_DODF,
    TAPI_SIM_PKCS15_AODF,       
    TAPI_SIM_PKCS15_ACIF,
    TAPI_SIM_PKCS15_ACF,
    TAPI_SIM_PKCS15_X509CF,
    TAPI_SIM_MEM,
    TAPI_SIM_PKCS15_BOOTSTRAP,
    TAPI_SIM_PKCS15_CONFIG1,
    TAPI_SIM_PKCS15_CONFIG2,
    TAPI_SIM_FILE_INVALID
}; typedef UINT8 TAPI_SIM_FILE_E;

typedef UINT16  TAPI_SIM_FILE_SIZE_T;

typedef UINT16  TAPI_SIM_RECORD_NUM_T;

typedef UINT16  TAPI_SIM_RECORD_SIZE_T;

typedef UINT16  TAPI_SIM_LANG_PRIO_T;

typedef TAPI_CB_DCS_LANGUAGE_E  TAPI_SIM_LANG_CODE_E;

typedef UINT8   TAPI_SIM_FILE_NAME_A[SIM_FILENAME_LENGTH_MAX + 1];

typedef struct _TAPI_ACCESS_RULE_S
{
    UINT8                     offset;       
    UINT8                     length;  
    TAPI_ACCESS_COMBINATION_T combination;  
} TAPI_ACCESS_RULE_S;

typedef struct _TAPI_VAR_ACC_COND_S
{
  TAPI_ACCESS_RULE_S read;
  TAPI_ACCESS_RULE_S write;
  TAPI_ACCESS_RULE_S increase;
  TAPI_ACCESS_RULE_S invalidate;
  TAPI_ACCESS_RULE_S rehabilitate;
  TAPI_ACCESS_COND_T pins_data[TAPI_MAX_NUM_CHV] ;
} TAPI_VAR_ACC_COND_S ;

typedef struct  _TAPI_SIM_FILE_INFO_S
{
    TAPI_SIM_FILE_TYPE_E    fileType;   
    TAPI_SIM_FILE_SIZE_T    fileSize;   
    TAPI_SIM_RECORD_NUM_T   recordNum;  

    TAPI_SIM_RECORD_SIZE_T  recordSize; 
    TAPI_ACCESS_COND_T       read_access_cond; 
    TAPI_ACCESS_COND_T       write_access_cond; 
    TAPI_ACCESS_COND_T       invalidate_access_cond; 
    TAPI_ACCESS_COND_T       rehabilitate_access_cond; 
    TAPI_ACCESS_COND_T       increase_access_cond;  
    TAPI_VAR_ACC_COND_S      VarAccConditon ;   

} TAPI_SIM_FILE_INFO_S;

typedef struct  _TAPI_SIM_BINARYFILE_REQ_S
{
    TAPI_SIM_FILE_SIZE_T    length;     

    TAPI_SIM_FILE_SIZE_T    offset;     
    TAPI_SIM_FILE_NAME_A    fileName;   
} TAPI_SIM_BINARYFILE_REQ_S;

typedef struct  _TAPI_SIM_RECORDFILE_REQ_S
{
    TAPI_SIM_FILE_NAME_A    fileName;      
    TAPI_SIM_RECORD_NUM_T   recordIndex;   

} TAPI_SIM_RECORDFILE_REQ_S;

typedef struct  _TAPI_SIM_USIMFILE_REQ_S
{
    TAPI_SIM_FILE_E         file;
    UINT8                   spRef1;     
    UINT8                   spRef2;     
    UINT8                   spRef3;     
    TAPI_SIM_RECORD_NUM_T   record;     
    TAPI_SIM_RECORD_NUM_T   lastRecord; 
    TAPI_SIM_FILE_SIZE_T    length;     
} TAPI_SIM_USIM_READFILE_REQ_S;

typedef struct  _TAPI_SIM_USIMWRITEFILE_REQ_S
{
    TAPI_SIM_FILE_E         file;
    UINT8                   spRef1;    
    UINT8                   spRef2;    
    UINT8                   spRef3;    
    TAPI_SIM_RECORD_NUM_T   record;    
    TAPI_SIM_FILE_SIZE_T    length;
    UINT8                   entryData[SIM_FILEREAD_MAXLENGTH * 2 ];
} TAPI_SIM_USIM_WRITEFILE_REQ_S;

typedef struct  _TAPI_SIM_WRITEFILE_REQ_S
{
    TAPI_SIM_FILE_TYPE_E    fileType;
    TAPI_SIM_FILE_SIZE_T    length;
    TAPI_SIM_RECORD_NUM_T   recordIndex;    

    TAPI_SIM_FILE_SIZE_T    offset;         
    TAPI_SIM_FILE_NAME_A    fileName;       
    UINT8                   entryData[SIM_FILEREAD_MAXLENGTH * 2];
} TAPI_SIM_WRITEFILE_REQ_S;

typedef struct _TAPI_SIM_USIMFILE_ASYNC_RSP_S
{
    TAPI_RESULT_E           result;         
    UINT32                  seqNum;         
} TAPI_SIM_USIMFILE_ASYNC_RSP_S;

typedef struct  _TAPI_SIM_READFILEINFO_REQ_S
{
    TAPI_SIM_FILE_NAME_A    fileName;  
    TAPI_SIM_FILE_E         file;      
    UINT8                   spRef1;    
    UINT8                   spRef2;    
    UINT8                   spRef3;    
} TAPI_SIM_READFILEINFO_REQ_S;

typedef struct
{
    UINT32                  sequence_number;   
    TAPI_SIM_FILE_E         file;              
    TAPI_SIM_RECORD_NUM_T   record;            
    TAPI_RESULT_E           read_result;       
    TAPI_SIM_FILE_SIZE_T    length;            
}
TAPI_SIM_READ_FILE_CNF_HEADER_T;

typedef struct
{
    UINT32                  sequence_number;   
    TAPI_RESULT_E           write_result;      
}
TAPI_SIM_WRITE_FILE_CNF_T;

typedef struct _TAPI_SIM_CRSM_READ_FILE_REQ_S 
{

    TAPI_SIM_RECORD_NUM_T   recordIndex; 
    TAPI_SIM_FILE_SIZE_T    length;     
    TAPI_SIM_FILE_SIZE_T    offset;     
    TAPI_SIM_FILE_NAME_A    fileName;  
}TAPI_SIM_CRSM_READ_FILE_REQ_S ;

typedef TAPI_SIM_WRITEFILE_REQ_S TAPI_SIM_CRSM_UPDATE_REQ_S;

typedef struct _TAPI_SIM_CRSM_GET_RESPONSE_REQ_S
{
    TAPI_SIM_FILE_NAME_A    fileName;  
    UINT16 length ; 
}TAPI_SIM_CRSM_GET_RESPONSE_REQ_S;

typedef TAPI_SIM_CRSM_GET_RESPONSE_REQ_S TAPI_SIM_CRSM_STATUS_REQ_S ;

typedef struct _TAPI_SIM_CRSM_READ_FILE_RSP_S
{
    UINT8 SW1;
    UINT8 SW2;
    UINT16 data_length;
    UINT8 data[ TAPI_SIM_MAX_READ_DATA_LEN ];
}TAPI_SIM_CRSM_READ_FILE_RSP_S;

typedef struct _TAPI_SIM_CRSM_UPDATE_FILE_RSP_S
{
    UINT8 SW1;
    UINT8 SW2;
}TAPI_SIM_CRSM_UPDATE_FILE_RSP_S;

typedef TAPI_SIM_CRSM_READ_FILE_RSP_S TAPI_SIM_CRSM_GETRESPONSE_RSP_S ;

typedef TAPI_SIM_CRSM_READ_FILE_RSP_S TAPI_SIM_CRSM_STATUS_RSP_S;

typedef struct _TAPI_SIM_EF_MMSN_S
{
    UINT16 mms_status;          
    UINT8  mms_implementation;  
    UINT16 mms_notif_len;       
    UINT8* mms_notification;    
    UINT8  ext_record_num;      
} TAPI_SIM_EF_MMSN_S;

typedef struct _TAPI_SIM_EF_EXT8_S
{
    TAPI_SIM_EF_EXT8_RECORD_TYPE_E record_type;  
    UINT8  ext_data_len;                         
    UINT8* extension_data;                       
    UINT8  ext_identifier;                       
} TAPI_SIM_EF_EXT8_S;

typedef struct _TAPI_SIM_EF_MMSUP_S
{
    TAPI_SIM_EF_MMSUP_TAG_E preference_tag;  
    UINT16 data_len;                         
    UINT8* data;                             
} TAPI_SIM_EF_MMSUP_S;

typedef struct _TAPI_SIM_EF_MMSCP_S
{
    TAPI_SIM_EF_MMSCP_TAG_E connectivity_tag; 
    UINT16 data_len;                          
    UINT8* data;                              
} TAPI_SIM_EF_MMSCP_S;

extern TAPI_RESULT_E   
TAPI_SIM_GetFileInfo(
                     const char*             pFileName,
                     TAPI_SIM_FILE_INFO_S*   pFileInfo 
                     );

extern TAPI_RESULT_E   
TAPI_SIM_ReadFileBinary(
                        const char*             pFileName,
                        TAPI_SIM_FILE_SIZE_T*   pLength,
                        TAPI_SIM_FILE_SIZE_T    offset,
                        void*                   pData 
                        );

extern TAPI_RESULT_E   
TAPI_SIM_ReadFileRecord(
                        const char*             pFileName,
                        TAPI_SIM_RECORD_NUM_T   recordIndex,
                        UINT16*                 pBufSize,
                        void*                   pData 
                        );

extern TAPI_RESULT_E   
TAPI_SIM_WriteFileBinary(
                         const char*             pFileName,
                         TAPI_SIM_FILE_SIZE_T*   pLength,
                         TAPI_SIM_FILE_SIZE_T    offset,
                         const void*             pData 
                         );

extern TAPI_RESULT_E   
TAPI_SIM_WriteFileRecord(
                         const char*             pFileName,
                         UINT16*                 pLength,
                         TAPI_SIM_RECORD_NUM_T   recordIndex,
                         const void*             pData 
                         );

extern TAPI_RESULT_E   
TAPI_SIM_GetLanguagePreference(
                               const TAPI_SIM_LANG_PRIO_T  langPriority,
                               TAPI_SIM_LANG_CODE_E*       pLangCode 
                               );

extern TAPI_RESULT_E 
TAPI_SIM_GetExtFileCapacity(
                            TAPI_SIM_EXT_FILE_E extFile,
                            TAPI_PHONEBOOK_CAPACITY_S* pCapacity
                            );

TAPI_RESULT_E   TAPI_SIM_CRSM_ReadFileBinary(
                    const char*             pFileName,
                    TAPI_SIM_FILE_SIZE_T*   pLength,
                    TAPI_SIM_FILE_SIZE_T    offset,
                    UINT8*                   pData,
                    UINT8*                  SW1,
                    UINT8*                  SW2  );

TAPI_RESULT_E   TAPI_SIM_CRSM_ReadFileRecord(
                    const char*             pFileName,
                    TAPI_SIM_RECORD_NUM_T   recordIndex,
                    TAPI_SIM_FILE_SIZE_T*   pLength,
                    UINT8*                   pData,
                    UINT8*                  SW1,
                    UINT8*                  SW2  );

TAPI_RESULT_E   TAPI_SIM_CRSM_WriteFileBinary(
                    const char*             pFileName,
                    TAPI_SIM_FILE_SIZE_T    Length,
                    TAPI_SIM_FILE_SIZE_T    offset,
                    const UINT8*             pData,
                    UINT8*                  SW1,
                    UINT8*                  SW2 );

TAPI_RESULT_E   TAPI_SIM_CRSM_WriteFileRecord(
                    const char*             pFileName,
                    UINT16                  Length,
                    TAPI_SIM_RECORD_NUM_T   recordIndex,
                    const UINT8*            pData ,
                    UINT8*      SW1,
                    UINT8*      SW2 );

TAPI_RESULT_E   TAPI_SIM_CRSM_GetResponse(
                    const char*             pFileName,
                    UINT16*                 pLength,
                    const UINT8*             pData ,
                    UINT8*      SW1,
                    UINT8*      SW2 );

TAPI_RESULT_E   TAPI_SIM_CRSM_GetStatus(
                    const char*             pFileName,
                    UINT16*                 pLength,
                    const UINT8*             pData ,
                    UINT8*      SW1,
                    UINT8*      SW2 );

TAPI_RESULT_E TAPI_SIM_GetUSIMFileInfo( TAPI_SIM_FILE_E file, UINT8 spRef1, UINT8 spRef2, UINT8 spRef3, TAPI_SIM_FILE_INFO_S *pFileInfo );

TAPI_RESULT_E TAPI_SIM_ReadFile( TAPI_SIM_FILE_E file, UINT8 spRef1, UINT8 spRef2, UINT8 spRef3, TAPI_SIM_RECORD_NUM_T record, TAPI_SIM_FILE_SIZE_T length, UINT8 *buffer );

TAPI_RESULT_E TAPI_SIM_ReadFileAsync( TAPI_SIM_FILE_E file, UINT8 spRef1, UINT8 spRef2, UINT8 spRef3, TAPI_SIM_RECORD_NUM_T firstRecord, TAPI_SIM_RECORD_NUM_T lastRecord, UINT32 *pSeqNum );

TAPI_RESULT_E TAPI_SIM_WriteFile( TAPI_SIM_FILE_E file, UINT8 spRef1, UINT8 spRef2, UINT8 spRef3, TAPI_SIM_RECORD_NUM_T record, TAPI_SIM_FILE_SIZE_T length, UINT8 *buffer );

TAPI_RESULT_E TAPI_SIM_WriteFileAsync( TAPI_SIM_FILE_E file, UINT8 spRef1, UINT8 spRef2, UINT8 spRef3, TAPI_SIM_RECORD_NUM_T record, TAPI_SIM_FILE_SIZE_T length, UINT8 *buffer, UINT32 *pSeqNum );

TAPI_RESULT_E TAPI_SIM_EncodeMMSN ( TAPI_SIM_EF_MMSN_S * struct_ptr, UINT16 sim_data_length, 
                                    UINT8 *sim_data_ptr );

TAPI_RESULT_E TAPI_SIM_DecodeMMSN ( UINT8 *sim_data_ptr, UINT16 sim_data_length, 
                                    TAPI_SIM_EF_MMSN_S * struct_ptr );

TAPI_RESULT_E TAPI_SIM_EncodeEXT8 ( TAPI_SIM_EF_EXT8_S * struct_ptr, UINT16 sim_data_length, 
                                    UINT8 *sim_data_ptr );

TAPI_RESULT_E TAPI_SIM_DecodeEXT8 ( UINT8 *sim_data_ptr, UINT16 sim_data_length, 
                                    TAPI_SIM_EF_EXT8_S * struct_ptr );

TAPI_RESULT_E TAPI_SIM_EncodeMMSUP ( TAPI_SIM_EF_MMSUP_S * struct_ptr, UINT16 sim_data_length, 
                                     UINT8 num_tlv, UINT8 *sim_data_ptr );

TAPI_RESULT_E TAPI_SIM_DecodeMMSUP ( UINT8 *sim_data_ptr, UINT16 sim_data_length, 
                                     UINT8 num_tlv, TAPI_SIM_EF_MMSUP_S * struct_ptr );

TAPI_RESULT_E TAPI_SIM_EncodeMMSCP ( TAPI_SIM_EF_MMSCP_S * struct_ptr, UINT16 sim_data_length, 
                                     UINT8 num_tlv, UINT8 *sim_data_ptr );

TAPI_RESULT_E TAPI_SIM_DecodeMMSCP ( UINT8 *sim_data_ptr, UINT16 sim_data_length, 
                                     UINT8 num_tlv, TAPI_SIM_EF_MMSCP_S * struct_ptr );

TAPI_RESULT_E TAPI_SIM_GetNumTLV ( UINT8 *sim_data_ptr, UINT16 sim_data_length, 
                                   TAPI_SIM_FILE_E file_type, UINT8 *num_tlv);

#ifdef __cplusplus
}
#endif 

#endif  

