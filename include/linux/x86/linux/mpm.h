#ifndef LINUX_MPM_H
#define LINUX_MPM_H

/* mpm.h 
 *                               
 * © Copyright Motorola 2005    
 *                             
 * Maintainers: Sharad Gang                           
 */                                                  

/*
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */



/*
 * ioctl operations
 */
#include <linux/ioctl.h>




typedef unsigned long mpm_op_t;

/*
 * kernel event definitions for our ezx platform
 */
typedef struct {
	unsigned short type;	/*	What type of events.	*/
	unsigned short kind;	/*	What kind, or sub-type of events.*/
	unsigned int info;
} mpm_event_t;

typedef struct {
    int cnt;
    int *si;
} mpm_slpint_t;



#define DEVICE_NAME "mpm"
/* device name string used to open the MPM device */
#define MPM_DEV_NAME        "/dev/"DEVICE_NAME

/* event types */
#define	MPM_EVENT_DEVICE	0x2		/*	Device event.	*/

/* event kinds */ 

#define EVENT_DEV_ACCS		0x0
#define EVENT_DEV_BT		0x1
#define EVENT_DEV_TS		0x2
#define EVENT_DEV_KEY		0x3
#define EVENT_DEV_RTC		0x4
#define EVENT_DEV_FLIP		0x5
#define EVENT_DEV_ICL		0x6

/* event info */

#define DEV_OFF			0x0
#define DEV_ON			0x1

#define DEV_DETACH              0x0
#define DEV_ATTACH              0x1

/*
 * some new io control commands
 */
#define MPM_IOC_GET_NUMOP    _IOR('A', 4, int)
#define MPM_IOC_GETALL_OP       _IOR('A', 5, mpm_op_t)
#define MPM_IOC_SET_OP       _IOW('A', 6, mpm_op_t)
#define MPM_IOC_GET_NUMSLPMODES    _IOR('A', 7, int)
#define MPM_IOC_SET_SLEEPINT	_IOW('A', 8, mpm_slpint_t)
#define MPM_IOC_AWAKE_REQ		_IO('A', 9)
#define MPM_IOC_GETCUR_OP       _IOR('A', 10, mpm_op_t)
#define MPM_IOC_REFLASH			_IO('A', 12)

#define MPM_IOC_INSERT_DEV_EVENT _IOW('A', 13, mpm_event_t)
#define MPM_IOC_PRINT_OPSTAT     _IO('A', 14)
#define MPM_IOC_START_OPSTAT     _IO('A', 15)
#define MPM_IOC_STOP_OPSTAT      _IO('A', 16)


#ifdef __KERNEL__


#ifdef MPM_DEBUG
#define MPM_DPRINTK(format, args...)	printk(format, ##args)
#else
#define MPM_DPRINTK(format, args...)
#endif

extern int mpm_queue_empty(void);
extern void mpm_get_queued_event(mpm_event_t *);
extern wait_queue_head_t mpm_wq;
extern void mpm_event_notify(short type, short kind, int info);
extern int mpm_periodic_jobs_done(void);
extern int mpm_getnum_op(void);
extern int mpm_set_op (mpm_op_t arg);
extern mpm_op_t mpm_getcur_op(void);
extern const mpm_op_t* const mpm_getall_op(void);
extern void mpm_print_opstat(char *buf, int buflen);
extern void mpm_start_opstat(void);
extern void mpm_stop_opstat(void);


/*
 * Maximum number of events that can be stored in
 *  Queue are 20
 */
#define MPM_MAX_EVENTS		  21

typedef struct {
	int		event_head;
	int		event_tail;
	mpm_event_t	events[MPM_MAX_EVENTS];
} mpm_devq_t;

#endif /* __KERNEL__ */

#endif	/* LINUX_MPM_H */
