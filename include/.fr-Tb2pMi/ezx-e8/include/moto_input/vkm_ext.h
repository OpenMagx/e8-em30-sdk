/*
 * Copyright © 2006-2008, Motorola, All Rights Reserved.
 *
 * This program is licensed under a BSD license with the following terms:
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted
 * provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this list of conditions
 *   and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice, this list of
 *   conditions and the following disclaimer in the documentation and/or other materials provided
 *   with the distribution.
 * - Neither the name of Motorola nor the names of its contributors may be used to endorse or
 *   promote products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * Motorola 2008-Jan-07 - Updates for mode ioctl
 * Motorola 2007-Oct-01 - Add Mode Change ioctl and Slider Device
 * Motorola 2007-May-24 - Add new ioctl control
 * Motorola 2007-Apr-23 - Replace GET_LAST_KEY with GET_LAST_EVENT 
 * Motorola 2007-Apr-17 - Add SET_STATUS ioctl
 * Motorola 2007-Jan-30 - Adding device configuration ioctl
 * Motorola 2006-Nov-21 - Initial Creation
 */

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#ifndef __VKM_EXT_H__
#define __VKM_EXT_H__

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/
/*! @brief The major number of the VKM driver. */
#define VKM_MAJOR_NUM       225

/*! @brief The name of the device in /dev. */
#define VKM_DEV_NAME        "vkm"

/*! @brief The number of characters allowed in a device name. */
#define VKM_DEV_CHAR_NAME   32

/*! @brief Default value for status of status devices */
#define MOTO_INPUT_UNKNOWN  0xFF

/*! @brief Mask used for the press of a key */
#define MOTO_INPUT_KEY_EVENT_PRESSED_MASK 0x80000000

/*! @brief 0yyxxxxx (yy = array element, xxxxx = bit position in array) */
/*! @note  Currently the Macros only support up to 128 keys.  If any of these
 *         values are changed, the Macros below will need to be revised. */
#define MOTO_INPUT_VALID_KEY_MASK        0x7F
#define MOTO_INPUT_KEY_ARRAY_ELEM_SHIFT     5
#define MOTO_INPUT_KEY_BIT_POS_MASK      0x1f
#define MOTO_INPUT_KEY_BIT_ARRAY_SIZE       4

/*==================================================================================================
                                            MACROS
==================================================================================================*/
/*! @brief Macro for setting a bit in a bitmask of keys */
#define MOTO_INPUT_KEY_BITMASK_SET(mask,key) \
    ((mask)[((key) & MOTO_INPUT_VALID_KEY_MASK) >> MOTO_INPUT_KEY_ARRAY_ELEM_SHIFT] |= \
    (1 << ((key) & MOTO_INPUT_KEY_BIT_POS_MASK)))

/*! @brief Macro for setting all bits in a bitmask of keys */
#define MOTO_INPUT_KEY_BITMASK_SET_ALL(mask) \
    ((mask)[0] = (mask)[1] = (mask)[2] = (mask)[3] = 0xFFFFFFFF)

/*! @brief Macro for clearing a bit in a bitmask of keys */
#define MOTO_INPUT_KEY_BITMASK_CLEAR(mask,key) \
    ((mask)[((key) & MOTO_INPUT_VALID_KEY_MASK) >> MOTO_INPUT_KEY_ARRAY_ELEM_SHIFT] &= \
     ~(1 << ((key) & MOTO_INPUT_KEY_BIT_POS_MASK)))

/*! @brief Macro for clearing all bits in a bitmask of keys */
#define MOTO_INPUT_KEY_BITMASK_CLEAR_ALL(mask) \
    ((mask)[0] = (mask)[1] = (mask)[2] = (mask)[3] = 0)

/*! @brief Macro for checking a bit in a bitmask of keys */
#define MOTO_INPUT_KEY_BITMASK_ISSET(mask,key) \
    (((mask)[((key) & MOTO_INPUT_VALID_KEY_MASK) >> MOTO_INPUT_KEY_ARRAY_ELEM_SHIFT] & \
     (1 << ((key) & MOTO_INPUT_KEY_BIT_POS_MASK))) != 0)

/*! @brief Macro for checking for any bits in a bitmask of keys */
#define MOTO_INPUT_KEY_BITMASK_ISEMPTY(mask) \
    ((mask)[0] == 0 && (mask)[1] == 0 && (mask)[2] == 0 && (mask)[3] == 0)

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*! @brief Assigned value for a UINT32 bitmask */
typedef unsigned int MOTO_INPUT_KEY_BITMASK_ENTRY_T;

/*! @brief Array that will contain 4 UINT32 bitmasks for 128 keys */
typedef MOTO_INPUT_KEY_BITMASK_ENTRY_T MOTO_INPUT_KEY_BITMASK_T[MOTO_INPUT_KEY_BIT_ARRAY_SIZE];

/*! @brief Enumeration that specifies if the status device is open or closed */
typedef enum
{
    MOTO_INPUT_STATUS_FLIP_CLOSE,
    MOTO_INPUT_STATUS_FLIP_OPEN,
    MOTO_INPUT_STATUS_FLIP_MAX
} MOTO_INPUT_STATUS_FLIP_T;

/*! @brief Enumeration that specifies if the status device is pressed or released */
typedef enum
{
    MOTO_INPUT_STATUS_PROX_PRESS,
    MOTO_INPUT_STATUS_PROX_RELEASE,
    MOTO_INPUT_STATUS_PROX_MAX
} MOTO_INPUT_STATUS_PROX_T;

/*! @brief Enumeration that specifies if the status device is locked or unlocked */
typedef enum
{
    MOTO_INPUT_STATUS_LOCKSWITCH_LOCK,
    MOTO_INPUT_STATUS_LOCKSWITCH_UNLOCK,
    MOTO_INPUT_STATUS_LOCKSWITCH_MAX
} MOTO_INPUT_STATUS_LOCKSWITCH_T;

/*! @brief Enumeration of event types */
typedef enum
{
    MOTO_INPUT_EVENT_TYPE_KEY,
    MOTO_INPUT_EVENT_TYPE_STATUS,
    MOTO_INPUT_EVENT_TYPE_DEVICE,
    
    MOTO_INPUT_DEV_TYPE__UNUSED
} MOTO_INPUT_EVENT_TYPE_T;

/*! @brief Enumeration of status device types */
typedef enum
{
    MOTO_INPUT_STATUS_FLIP,
    MOTO_INPUT_STATUS_ROTATOR,
    MOTO_INPUT_STATUS_PROXIMITY,
    MOTO_INPUT_STATUS_LOCKSWITCH,
    MOTO_INPUT_STATUS_MAX
} MOTO_INPUT_STATUS_TYPE_T;

/*! @brief Enumeration of device device types */
typedef enum
{
    MOTO_INPUT_DEVICE_TOUCHSCREEN,
    MOTO_INPUT_DEVICE_OMEGA,
    MOTO_INPUT_DEVICE_SLIDER,
    MOTO_INPUT_DEVICE_UNKNOWN,
    MOTO_INPUT_DEVICE_MAX = MOTO_INPUT_DEVICE_UNKNOWN
} MOTO_INPUT_DEVICE_TYPE_T;

/*! @brief Enumeration of supported omegas */
typedef enum
{
    MOTO_INPUT_OMEGA_0,
    MOTO_INPUT_OMEGA_1,
    MOTO_INPUT_OMEGA_2,
    MOTO_INPUT_OMEGA_UNKNOWN,
    MOTO_INPUT_OMEGA_MAX = MOTO_INPUT_OMEGA_UNKNOWN
} MOTO_INPUT_OMEGA_T;

/*! @brief Structure that contains information about a key device */
typedef struct
{
    unsigned char device_name[VKM_DEV_CHAR_NAME];
    unsigned int device_id;
    unsigned int num_keys;
    unsigned int start_index;    
} MOTO_INPUT_KEY_DEV_T;

/*! @brief Structure that contains information of a status device for key filtering */
typedef struct
{
    MOTO_INPUT_STATUS_TYPE_T status_device_type;
    int status;
    MOTO_INPUT_KEY_BITMASK_T bitmask;
} MOTO_INPUT_AUTO_KEY_FILTER_T;

/*! @brief Structure that contains information about a status device */
typedef struct
{
    MOTO_INPUT_STATUS_TYPE_T device_type;
    int status;
} MOTO_INPUT_STATUS_T;

/*! @brief Structure that contains key, status, and device events for the upper layers */
typedef struct
{
    MOTO_INPUT_EVENT_TYPE_T type;
    
    union
    {
        unsigned int key_event;

        struct
        {
            MOTO_INPUT_STATUS_TYPE_T device_type;
            int status;
        } status_event;

        struct
        {
            MOTO_INPUT_DEVICE_TYPE_T device_type;
            unsigned int touch;
            unsigned int crunch;
            unsigned int event_data_1;
            unsigned int event_data_2;
            unsigned int event_data_3;
        } device_event;
    } event;
} MOTO_INPUT_EVENT_T;

/*! @brief Structure that contains the time between repeats for each key */
typedef struct 
{
    int r_repeat;                /* 1 to do autorepeat, 0 to not do it */
    int r_time_to_first_repeat;  /* time to first repeat in milliseconds */
    int r_time_between_repeats;  /* time between repeats in milliseconds */
} MOTO_INPUT_AUTOREPEAT_T;

/*! @brief Structure containing device configuration information */
typedef struct
{
    MOTO_INPUT_DEVICE_TYPE_T device_id;
    unsigned int param;
    unsigned int value;
} MOTO_INPUT_DEVICE_CONFIG_T;

/*! @brief Structure containing device stop data */
typedef struct
{
    MOTO_INPUT_OMEGA_T omega_num;
    unsigned int data;
} MOTO_INPUT_OMEGA_STOP_T;

/*==================================================================================================
                                           IOCTLS
==================================================================================================*/
#ifndef DOXYGEN_SHOULD_SKIP_THIS /* This stuff just clutters the documentation. Don't bother. */
/* These are the ranges of ioctl commands for the VKM driver. These cannot be used
 * directly from user-space, but are used to construct the request parameters used in ioctl()
 * calls to the driver. */

/* Base of all the ioctl() commands that will be handled for the input device. */
#define VKM_IOC_CMD_INPUT_DEVICE_BASE          (0x00)
/* Last of the range of ioctl() commands reserved for the input device. */
#define VKM_IOC_CMD_INPUT_DEVICE_LAST_CMD      (VKM_IOC_CMD_INPUT_DEVICE_BASE + 0x0F)

/* Base of all the ioctl() commands that will be handled for the event queue. */
#define VKM_IOC_CMD_EVENT_QUEUE_BASE           (VKM_IOC_CMD_INPUT_DEVICE_LAST_CMD + 1)
/* Last of the range of ioctl() commands reserved for the event queue. */
#define VKM_IOC_CMD_EVENT_QUEUE_LAST_CMD       (VKM_IOC_CMD_EVENT_QUEUE_BASE + 0x0F)

/* Base of all the ioctl() commands that will be handled for a key event. */
#define VKM_IOC_CMD_KEY_EVENT_BASE             (VKM_IOC_CMD_EVENT_QUEUE_LAST_CMD + 1)
/* Last of the range of ioctl() commands reserved for a key event. */
#define VKM_IOC_CMD_KEY_EVENT_LAST_CMD         (VKM_IOC_CMD_KEY_EVENT_BASE + 0x0F)

/* Base of all the ioctl() commands that will be handled for a status device. */
#define VKM_IOC_CMD_STATUS_DEVICE_BASE         (VKM_IOC_CMD_KEY_EVENT_LAST_CMD + 1)
/* Last of the range of ioctl() commands reserved for a status device. */
#define VKM_IOC_CMD_STATUS_DEVICE_LAST_CMD     (VKM_IOC_CMD_STATUS_DEVICE_BASE + 0x0F)

/* Base of all the ioctl() commands that will be handled for the omega device. */
#define VKM_IOC_CMD_OMEGA_BASE                 (VKM_IOC_CMD_STATUS_DEVICE_LAST_CMD + 1)
/* Last of the range of ioctl() commands reserved for the omega device. */
#define VKM_IOC_CMD_OMEGA_LAST_CMD             (VKM_IOC_CMD_OMEGA_BASE + 0x0F)

#endif /* Doxygen */

/* End of ioctl range constants. -------------------------------------------------------------- */


/*!
 * @brief Number of Key Devices
 *
 * This command reads the current number of Key Devices 
 * connected to the Input Device Manager.
 *
 * A pointer to which the number of Key Devices attached should be stored.
 */
#define MOTO_INPUT_IOC_GET_NUM_KEY_DEVICES \
    _IOR(VKM_MAJOR_NUM, VKM_IOC_CMD_INPUT_DEVICE_BASE + 0x00, int *)

/*!
 * @brief Key Device Information
 *
 * This command reads all the information of any Key Devices 
 * currently connected to the Input Device Manager.
 *
 * A pointer to a Key Devices structure (MOTO_INPUT_KEY_DEV_T) that contains 
 * the device ID for which the information is being requested.  The device ID 
 * will range from 0 to the number of key devices-1.
 */
#define MOTO_INPUT_IOC_GET_KEY_DEVICE_INFO \
    _IOWR(VKM_MAJOR_NUM, VKM_IOC_CMD_INPUT_DEVICE_BASE + 0x01, MOTO_INPUT_KEY_DEV_T *)

/*!
 * @brief Enable Device
 *
 * This command enables the device specified by its type.
 *
 * The devices type.
 */
#define MOTO_INPUT_IOC_ENABLE_DEVICE_DEVICE \
    _IOW(VKM_MAJOR_NUM, VKM_IOC_CMD_INPUT_DEVICE_BASE + 0x02, MOTO_INPUT_DEVICE_TYPE_T)

/*!
 * @brief Disable Device
 *
 * This command disables the device specified by its type.
 *
 * The devices type.
 */
#define MOTO_INPUT_IOC_DISABLE_DEVICE_DEVICE \
    _IOW(VKM_MAJOR_NUM, VKM_IOC_CMD_INPUT_DEVICE_BASE + 0x03, MOTO_INPUT_DEVICE_TYPE_T)


/*!
 * @brief Configure Device
 *
 * This command configures parameters for a device.
 *
 * A pointer to a device config structure containing a valid device device type
 * (e.g., Omega), a parameter number, and the new parameter's value.  The parameter
 * numbers and values are specific to the device being configured.
 */
#define MOTO_INPUT_IOC_CONFIG_DEVICE_DEVICE \
    _IOW(VKM_MAJOR_NUM, VKM_IOC_CMD_INPUT_DEVICE_BASE + 0x04, MOTO_INPUT_DEVICE_CONFIG_T *)

/*!
 * @brief Read raw Omega device data
 *
 * This command reads raw data from the Omega wheel.
 *
 * The parameter is a pointer to at least eight bytes of data where the raw
 * device data should be stored.  Note that this command always reads from the
 * Omega device and does not work for other device types.
 */
#define MOTO_INPUT_IOC_READ_RAW_DEVICE_DEVICE \
    _IOR(VKM_MAJOR_NUM, VKM_IOC_CMD_INPUT_DEVICE_BASE + 0x05, unsigned char *)

/*!
 * @brief Change Mode
 *
 * This command changes the touch input mode and allows all connected devices to be
 * reconfigured based off the new mode.
 *
 * An unsigned integer that represents the new touch input mode.
 */
#define MOTO_INPUT_IOC_CHANGE_MODE \
       _IOW(VKM_MAJOR_NUM, VKM_IOC_CMD_INPUT_DEVICE_BASE + 0x06, int)

/*!
 * @brief Create Queue
 *
 * This command creates a new, empty event queue for a given process.
 */
#define MOTO_INPUT_IOC_CREATE_EVENT_QUEUE \
    _IO(VKM_MAJOR_NUM, VKM_IOC_CMD_EVENT_QUEUE_BASE + 0x00)

/*!
 * @brief Number of Events on a Queue
 *
 * This command reads the current number of events on a process' queue.
 *
 * A pointer to which the number of events currently on a process' 
 * queue should be stored.
 */
#define MOTO_INPUT_IOC_GET_NUM_EVENTS_ON_QUEUE \
    _IOR(VKM_MAJOR_NUM, VKM_IOC_CMD_EVENT_QUEUE_BASE + 0x01, int *)

/*!
 * @brief Flush Queue
 *
 * This command will flush the event queue for a given process.
 */
#define MOTO_INPUT_IOC_FLUSH_EVENT_QUEUE \
    _IO(VKM_MAJOR_NUM, VKM_IOC_CMD_EVENT_QUEUE_BASE + 0x02)

/*!
 * @brief Insert Event
 *
 * This command will insert an input event onto all event queues.
 *
 * A pointer to an input event (MOTO_INPUT_EVENT_T).
 */
#define MOTO_INPUT_IOC_INSERT_EVENT \
    _IOW(VKM_MAJOR_NUM, VKM_IOC_CMD_EVENT_QUEUE_BASE + 0x03, MOTO_INPUT_EVENT_T *)

/*!
 * @brief Haptic Response Mask
 *
 * This command will set a mask of the current keys that will have a 
 * haptic response when pressed and released.
 *
 * A pointer to the haptic key mask that is to be set (MOTO_INPUT_KEY_BITMASK_ENTRY_T). 
 */
#define MOTO_INPUT_IOC_SET_KEY_HAPTIC_MASK \
    _IOW(VKM_MAJOR_NUM, VKM_IOC_CMD_KEY_EVENT_BASE + 0x00, MOTO_INPUT_KEY_BITMASK_ENTRY_T *)

/*!
 * @brief Set Manual Key Filter
 *
 * This command will set a mask of keys that are to be manually 
 * filtered when pressed or released.
 *
 * A pointer to the manual key filter mask that is to be set (MOTO_INPUT_KEY_BITMASK_ENTRY_T). 
 */
#define MOTO_INPUT_IOC_SET_MANUAL_KEY_FILTER \
    _IOW(VKM_MAJOR_NUM, VKM_IOC_CMD_KEY_EVENT_BASE + 0x01, MOTO_INPUT_KEY_BITMASK_ENTRY_T *)

/*!
 * @brief Unset Manual Key Filter
 *
 * This command will unset a mask of keys that were to be manually 
 * filtered when pressed or released.
 */
#define MOTO_INPUT_IOC_UNSET_MANUAL_KEY_FILTER \
    _IO(VKM_MAJOR_NUM, VKM_IOC_CMD_KEY_EVENT_BASE + 0x02)

/*!
 * @brief Auto Key Filter
 *
 * This command will set the given key filter for a specified device.  
 * This key filter will be used by each device to enable and disable 
 * keys depending on the status of the phone.  E.g.  If the flip is 
 * closed, the keys on the inside can be filtered, or if the flip is 
 * open, the keys on the flip can be filtered.
 *
 * A pointer to a structure that will give the device ID for which the 
 * auto key filter is to be added, along with the status of the device,
 * and the key filter mask that is to be used for that device.
 */
#define MOTO_INPUT_IOC_ADD_AUTO_KEY_FILTER \
    _IOW(VKM_MAJOR_NUM, VKM_IOC_CMD_KEY_EVENT_BASE + 0x03, MOTO_INPUT_AUTO_KEY_FILTER_T *)

/*!
 * @brief Remove All Filters
 *
 * This command will remove all filters that are currently set.
 */
#define MOTO_INPUT_IOC_REMOVE_ALL_FILTERS \
    _IO(VKM_MAJOR_NUM, VKM_IOC_CMD_KEY_EVENT_BASE + 0x04)

/*!
 * @brief Autorepeat
 *
 * This command will turn on autorepeat of any key event.
 */
#define MOTO_INPUT_IOC_SET_KEY_AUTOREPEAT \
    _IOW(VKM_MAJOR_NUM, VKM_IOC_CMD_KEY_EVENT_BASE + 0x05, MOTO_INPUT_AUTOREPEAT_T *)

/*!
 * @brief Currently Pressed Keys
 *
 * This command reads the current keys that are being pressed.
 *
 * A pointer to which the currently pressed keys should be stored 
 * (MOTO_INPUT_KEY_BITMASK_ENTRY_T).  The position of the pressed 
 * key in the bitmask will be the same as the key index that 
 * corresponds to that key.
 */
#define MOTO_INPUT_IOC_GET_PRESSED_KEYS_MASK \
    _IOR(VKM_MAJOR_NUM, VKM_IOC_CMD_KEY_EVENT_BASE + 0x06, MOTO_INPUT_KEY_BITMASK_ENTRY_T *)

/*!
 * @brief Last Key Pressed
 *
 * This command reads the last key that was pressed/released or 
 * is currently being pressed.
 *
 * A pointer to which the last key pressed should be stored (unsigned int).
 */
#define MOTO_INPUT_IOC_GET_LAST_KEY \
    _IOR(VKM_MAJOR_NUM, VKM_IOC_CMD_KEY_EVENT_BASE + 0x07, unsigned int *)

/*!
 * @brief Last Event
 *
 * This command reads the last event that occurred and sends it to TCMD.
 *
 * A pointer to which the last event should be stored (MOTO_INPUT_EVENT_T).
 */
#define MOTO_INPUT_IOC_GET_LAST_EVENT \
    _IOR(VKM_MAJOR_NUM, VKM_IOC_CMD_KEY_EVENT_BASE + 0x08, MOTO_INPUT_EVENT_T *)

/*!
 * @brief Status of a Status Device
 *
 * This command reads a Status Devices type and its status and 
 * returns it to the caller.
 *
 * A pointer to which the device type is specified and the status 
 * of the device should be stored (MOTO_INPUT_STATUS_T).
 */
#define MOTO_INPUT_IOC_GET_STATUS \
    _IOWR(VKM_MAJOR_NUM, VKM_IOC_CMD_STATUS_DEVICE_BASE + 0x00, MOTO_INPUT_STATUS_T *)

/*!
 * @brief Enable Status Device
 *
 * This command enables the status device specified by its type.
 *
 * The devices type.
 */
#define MOTO_INPUT_IOC_ENABLE_STATUS_DEVICE \
    _IOW(VKM_MAJOR_NUM, VKM_IOC_CMD_STATUS_DEVICE_BASE + 0x01, MOTO_INPUT_STATUS_TYPE_T)

/*!
 * @brief Disable Status Device
 *
 * This command disables the status device specified by its type.
 *
 * The devices type.
 */
#define MOTO_INPUT_IOC_DISABLE_STATUS_DEVICE \
    _IOW(VKM_MAJOR_NUM, VKM_IOC_CMD_STATUS_DEVICE_BASE + 0x02, MOTO_INPUT_STATUS_TYPE_T)
    
/*!
 * @brief Status of a Status Device
 *
 * This command sets a status for a status device.
 *
 * A pointer to which the device type and status is specified (MOTO_INPUT_STATUS_T).
 */
#define MOTO_INPUT_IOC_SET_STATUS \
    _IOWR(VKM_MAJOR_NUM, VKM_IOC_CMD_STATUS_DEVICE_BASE + 0x03, MOTO_INPUT_STATUS_T *)

/*!
 * @brief Stop Event
 *
 * This command sends a STOP event to the Omega.
 *
 * unsigned int of the STOP event. 
 */
#define MOTO_INPUT_IOC_OMEGA_STOP_EVENT \
    _IOW(VKM_MAJOR_NUM, VKM_IOC_CMD_OMEGA_BASE + 0x00, MOTO_INPUT_OMEGA_STOP_T *)

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATION
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* __VKM_EXT_H__ */
