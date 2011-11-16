

// Copyright (c) 07-Jun-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef USB_MTP_IF_H 
#define USB_MTP_IF_H

#ifdef __cplusplus 
extern "C" {
#endif

#define MTP_CTL_CLASS_REQ    1       
#define MTP_CTL_CLASS_REPLY  2   
#define MTP_EVENT_SIZE   28 

#define MTP_IOC_MAGIC    'm' 
#define MTP_IOC_MAXNR    10  

#define MTP_IOC_SEND_ZLP         _IO(MTP_IOC_MAGIC, 2) 
#define MTP_IOC_GET_EP_SIZE_IN   _IOR(MTP_IOC_MAGIC, 3, int) 
#define MTP_IOC_GET_VENDOR_FLAG  _IOR(MTP_IOC_MAGIC, 4, int) 
#define MTP_IOC_CANCEL_IO        _IO(MTP_IOC_MAGIC, 5) 
#define MTP_IOC_DEVICE_RESET     _IO(MTP_IOC_MAGIC, 6) 

struct mtp_ctl_msg_header 
{
    int msg_len; 
    int msg_id;  
};

struct mtp_event_data {
    unsigned char data[MTP_EVENT_SIZE]; 
};

#define MTP_CTL_MSG_HEADER_SIZE   (sizeof(struct mtp_ctl_msg_header)) 
#define MTP_IOC_EVENT            _IOW(MTP_IOC_MAGIC, 1, struct mtp_event_data)    

#ifdef __cplusplus
}
#endif 

#endif  

