/*
 * posix_time.h
 *
 * Copyright 2004 Sony Corp.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU LIBRARY GENERAL PUBLIC LICENSE as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU LIBRARY GENERAL PUBLIC LICENSE for more details.
 *
 * You should have received a copy of the GNU LIBRARY GENERAL PUBLIC LICENSE
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * This file was coded based on:
 *  The Open Group Base Specifications Issue 6
 *  IEEE Std 1003.1, 2004 Edition
 *  http://www.opengroup.org/onlinepubs/009695399
 *
 */

#if !defined(_845E63F1_5406_4979_8D47_D538D127A090_H_)
#define _845E63F1_5406_4979_8D47_D538D127A090_H_

#include <posix_time_config.h>
#undef PACKAGE
#undef PACKAGE_BUGREPORT
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef PACKAGE_TARNAME
#undef PACKAGE_VERSION
#undef STDC_HEADERS
#undef VERSION

#include <time.h>
#include <signal.h>
#include <sys/syscall.h>
#include <errno.h>
#include <unistd.h>

#if !defined(SYS_clock_getres)
# define SYS_clock_getres __NR_clock_getres
#endif
#if !defined(SYS_clock_gettime)
# define SYS_clock_gettime __NR_clock_gettime
#endif
#if !defined(SYS_clock_nanosleep)
# define SYS_clock_nanosleep __NR_clock_nanosleep
#endif
#if !defined(SYS_clock_settime)
# define SYS_clock_settime __NR_clock_settime
#endif
#if !defined(SYS_timer_create)
# define SYS_timer_create __NR_timer_create
#endif
#if !defined(SYS_timer_delete)
# define SYS_timer_delete __NR_timer_delete
#endif
#if !defined(SYS_timer_getoverrun)
# define SYS_timer_getoverrun __NR_timer_getoverrun
#endif
#if !defined(SYS_timer_gettime)
# define SYS_timer_gettime __NR_timer_gettime
#endif
#if !defined(SYS_timer_settime)
# define SYS_timer_settime __NR_timer_settime
#endif

#if !defined(CLOCK_REALTIME)
# define CLOCK_REALTIME 0
#endif

#if !defined(CLOCK_MONOTONIC)
# define CLOCK_MONOTONIC 1
#endif

#if !defined(CLOCK_PROCESS_CPUTIME_ID)
# define CLOCK_PROCESS_CPUTIME_ID 2
#endif

#if !defined(CLOCK_THREAD_CPUTIME_ID)
# define CLOCK_THREAD_CPUTIME_ID 3
#endif

#if !defined(CLOCK_REALTIME_HR)
# define CLOCK_REALTIME_HR 4
#endif

#if !defined(CLOCK_MONOTONIC_HR)
# define CLOCK_MONOTONIC_HR 5
#endif

#if !defined(HAVE_CLOCKID_T)
typedef unsigned long clockid_t;
#endif

#if !defined(HAVE_TIMER_T)
typedef unsigned long timer_t;
#endif

#if !defined(HAVE_STRUCT_TIMESPEC)
struct timespec {
	time_t tv_sec;
	long tv_nsec;
};
#endif

#if !defined(HAVE_STRUCT_ITIMERSPEC)
struct itimerspec
{
	struct timespec it_interval; /* period */
	struct timespec it_value; /* expiration */
};
#endif

#if !defined(HAVE_STRUCT_SIGEVENT)
# error need_to_do.
#endif

#if (HAVE_SIGINFO_T_SI_TIMERID != 1)
# if (HAVE_SIGINFO_T_SI_TID == 1)
#  define si_timerid si_tid
# elif (HAVE_SIGINFO_T_SI_TIMER1 == 1)
#  define si_timerid si_timer1
# else
#  warning No siginfo_t.si_timerid or equivalent found.
# endif
#endif

#if (HAVE_SIGINFO_T_SI_OVERRUN != 1)
# if (HAVE_SIGINFO_T_SI_TIMER2 == 1)
#  define si_overrun si_timer2
# else
#  warning No siginfo_t.si_overrun or equivalent found.
# endif
#endif

#if defined(__cplusplus)
extern "C" {
#endif

#if (HAVE_DECL_CLOCK_GETRES == 0)
# if !defined(HAVE_CLOCK_GETRES)
static inline int
clock_getres (clockid_t clockid, struct timespec* res)
{
	return syscall(SYS_clock_getres, clockid, res);
}
# else
int
clock_getres (clockid_t clockid, struct timespec* res);
# endif
#endif

#if (HAVE_DECL_CLOCK_GETTIME == 0)
# if !defined(HAVE_CLOCK_GETTIME)
static inline int
clock_gettime (clockid_t clockid, struct timespec* tp)
{
	return syscall(SYS_clock_gettime, clockid, tp);
}
# else
int
clock_gettime (clockid_t clockid, struct timespec* tp);
# endif
#endif

#if (HAVE_DECL_CLOCK_NANOSLEEP == 0)
# if !defined(HAVE_CLOCK_NANOSLEEP)
#ifdef __USE_XOPEN2K
inline int
#else 
static inline int
#endif
clock_nanosleep (clockid_t clockid, int flags, const struct timespec* rqtp,
	struct timespec* rmtp)
{
	const int e_save = errno;
	int result = syscall(SYS_clock_nanosleep, clockid, flags, rqtp,
		rmtp);

	if(result != 0)
		result = errno;

	errno = e_save;

	return result;
}
# else
int
clock_nanosleep (clockid_t clockid, int flags, const struct timespec* rqtp,
	struct timespec* rmtp);
# endif
#endif

#if (HAVE_DECL_CLOCK_SETTIME == 0)
# if !defined(HAVE_CLOCK_SETTIME)
static inline int
clock_settime (clockid_t clockid, const struct timespec* tp)
{
	return syscall(SYS_clock_settime, clockid, tp);
}
# else
int
clock_settime (clockid_t clockid, const struct timespec* tp);
# endif
#endif

#if (HAVE_DECL_TIMER_CREATE == 0)
# if !defined(HAVE_TIMER_CREATE)
static inline int
timer_create (clockid_t clockid, struct sigevent* evp, timer_t* timerid)
{
	return syscall(SYS_timer_create, clockid, evp, timerid);
}
# else
int
timer_create (clockid_t clockid, struct sigevent* evp, timer_t* timerid);
# endif
#endif

#if (HAVE_DECL_TIMER_DELETE == 0)
# if !defined(HAVE_TIMER_DELETE)
static inline int
timer_delete (timer_t timerid)
{
	return syscall(SYS_timer_delete, timerid);
}
# else
int
timer_delete (timer_t timerid);
# endif
#endif

#if (HAVE_DECL_TIMER_GETOVERRUN == 0)
# if !defined(HAVE_TIMER_GETOVERRUN)
static inline int
timer_getoverrun (timer_t timerid)
{
	return syscall(SYS_timer_getoverrun, timerid);
}
# else
int
timer_getoverrun (timer_t timerid);
# endif
#endif

#if (HAVE_DECL_TIMER_GETTIME == 0)
# if !defined(HAVE_TIMER_GETTIME)
static inline int
timer_gettime (timer_t timerid, struct itimerspec* value)
{
	return syscall(SYS_timer_gettime, timerid, value);
}
# else
int
timer_gettime (timer_t timerid, struct itimerspec* value);
# endif
#endif

#if (HAVE_DECL_TIMER_SETTIME == 0)
# if !defined(HAVE_TIMER_SETTIME)
static inline int
timer_settime (timer_t timerid, int flags, const struct itimerspec* value,
	struct itimerspec* ovalue)
{
	return syscall(SYS_timer_settime, timerid, flags, value, ovalue);
}
# else
int
timer_settime (timer_t timerid, int flags, const struct itimerspec* value,
	struct itimerspec* ovalue);
# endif
#endif

#if defined(__cplusplus)
}
#endif

#endif
