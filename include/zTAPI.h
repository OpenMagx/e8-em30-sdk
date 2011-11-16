#ifndef ZTAPI_H
#define ZTAPI_H

//***** TAPI ***************
#define  IMEI_LENGTH                       15
typedef UINT8   IMEI_ARRAY[IMEI_LENGTH + 1];

extern "C" { 
  INT32 TAPI_CLIENT_Init(const UINT16* pBuf, UINT8 x);
  unsigned int   TAPI_ACCE_GetImei( IMEI_ARRAY IMEI );
  void  TAPI_CLIENT_Fini( void );
}

/*
How to use:
  1. first initialize client TAPI
  2. use function 
  3. deinitialize client TAPI
  
  how to get IMEI:
  
  // initialize TAPI ang get IMEI
  unsigned int res;
  IMEI_ARRAY imei;
  
  TAPI_CLIENT_Init(NULL, 0);
  res = TAPI_ACCE_GetImei(imei);     
  if ( res == 0)
{
    QString pImei = QString::fromLatin1( reinterpret_cast<char*>( imei ) );
    qDebug(QString("\nIMEI: %1").arg(pImei));
}
  else { qDebug(QString("*** FAIL: error %1").arg(res)); }
  TAPI_CLIENT_Fini();
  
  
*/
#endif
