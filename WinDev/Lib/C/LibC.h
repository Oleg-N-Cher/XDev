/*  Ofront 1.2 -xtspkae */

#ifndef LibC__h
#define LibC__h

#include "SYSTEM.h"

typedef
	struct LibC_Dirent *LibC_PtrDirent;

typedef
	INTEGER (*LibC_CmpFunc)(LibC_PtrDirent*, LibC_PtrDirent*);

typedef
	struct LibC_Dirent {
		INTEGER d_ino, d_off;
		SHORTINT d_reclen;
		BYTE d_type;
		CHAR d_name[257];
	} LibC_Dirent;

typedef
	struct {
		LONGINT len[1];
		LibC_Dirent data[1];
	} *LibC_PtrDirentArray;

typedef
	struct LibC_siginfo_t *LibC_Ptrsiginfo_t;

typedef
	struct LibC_ucontext_t *LibC_Ptrucontext_t;

typedef
	INTEGER (*LibC_SelectorFunc)(LibC_Dirent);

typedef
	struct {
		LONGINT len[1];
		SYSTEM_PTR data[1];
	} *LibC_StrArray;

typedef
	struct LibC_stat_t {
		LONGINT st_dev;
		char _prvt0[4];
		INTEGER st_ino;
		SET st_mode;
		INTEGER st_nlink, st_uid, st_gid;
		LONGINT st_rdev;
		char _prvt1[4];
		INTEGER st_size, st_blksize, st_blocks, st_atime;
		char _prvt2[4];
		INTEGER st_mtime;
		char _prvt3[4];
		INTEGER st_ctime;
		char _prvt4[12];
	} LibC_stat_t;

typedef
	INTEGER (*LibC___ftw_func_t)(SYSTEM_PTR, LibC_stat_t*, LONGINT *, INTEGER);

typedef
	struct LibC_fpreg {
		CHAR significand[4];
		CHAR exponent;
	} LibC_fpreg;

typedef
	struct LibC_fpstate *LibC_fpregset_t;

typedef
	struct LibC_fpstate {
		INTEGER cw, sw, tag, ipoff, cssel, dataoff, datasel;
		char _prvt0[40];
		INTEGER status;
	} LibC_fpstate;

typedef
	INTEGER LibC_gregset_t[19];

typedef
	INTEGER LibC_jmp_buf[6];

typedef
	struct LibC_mcontext_t {
		LibC_gregset_t gregs;
		LibC_fpregset_t fpregs;
		INTEGER oldmask, cr2;
	} LibC_mcontext_t;

typedef
	BYTE LibC_sigset_t[128];

typedef
	struct LibC_sigaction_t {
		void (*sa_sigaction)(INTEGER, LibC_Ptrsiginfo_t, LibC_Ptrucontext_t);
		LibC_sigset_t sa_mask;
		SET sa_flags;
		LONGINT sa_restorer;
	} LibC_sigaction_t;

typedef
	struct LibC_siginfo_t {
		INTEGER si_signo, si_errno, si_code, si_pid, si_uid, si_status, si_utime, si_stime, si_value, si_int;
		SYSTEM_PTR si_ptr, si_addr;
		INTEGER si_band, si_fd;
	} LibC_siginfo_t;

typedef
	struct LibC_sigjmp_buf {
		LibC_jmp_buf buf;
		INTEGER mask_was_saved;
		LibC_sigset_t saved_mask;
	} LibC_sigjmp_buf;

typedef
	struct LibC_stack_t {
		SYSTEM_PTR ss_sp;
		INTEGER ss_flags;
		SYSTEM_PTR ss_size;
	} LibC_stack_t;

typedef
	struct LibC_tmDesc *LibC_tm;

typedef
	struct LibC_tmDesc {
		INTEGER tm_sec, tm_min, tm_hour, tm_mday, tm_mon, tm_year, tm_wday, tm_yday, tm_isdst;
	} LibC_tmDesc;

typedef
	struct LibC_ucontext_t {
		INTEGER uc_flags;
		LibC_Ptrucontext_t uc_link;
		LibC_stack_t uc_stack;
		LibC_mcontext_t uc_mcontext;
		char _prvt0[128];
		LibC_fpstate __fpregs_mem;
	} LibC_ucontext_t;


import INTEGER LibC_timezone;
import SYSTEM_PTR LibC_stdin, LibC_stdout, LibC_stderr;

import LONGINT *LibC_Dirent__typ;
import LONGINT *LibC_siginfo_t__typ;
import LONGINT *LibC_sigaction_t__typ;
import LONGINT *LibC_sigjmp_buf__typ;
import LONGINT *LibC_stack_t__typ;
import LONGINT *LibC_stat_t__typ;
import LONGINT *LibC_fpreg__typ;
import LONGINT *LibC_fpstate__typ;
import LONGINT *LibC_mcontext_t__typ;
import LONGINT *LibC_ucontext_t__typ;
import LONGINT *LibC_tmDesc__typ;

import void *LibC__init(void);

#define LibC___errno_location()	__errno_location()
__EXTERN INTEGER __errno_location(void);
#define LibC___xstat(version, filename, buf, buf__typ)	__xstat(version, filename, buf)
__EXTERN INTEGER __xstat(INTEGER version, SYSTEM_PTR filename, LibC_stat_t *buf);
#define LibC__init()	/*-noinit*/
#define LibC_atoi(nptr)	atoi((const char *)nptr)
#define LibC_calloc(num, size)	calloc(num, size)
__EXTERN SYSTEM_PTR calloc(SYSTEM_PTR num, SYSTEM_PTR size);
#define LibC_chdir(path)	_chdir((const char *)path)
#define LibC_chmod(path, mode)	chmod(path, mode)
__EXTERN void chmod(SYSTEM_PTR path, SET mode);
#define LibC_clock()	clock()
__EXTERN INTEGER clock(void);
#define LibC_closedir(dir)	closedir(dir)
__EXTERN INTEGER closedir(SYSTEM_PTR dir);
#define LibC_exit(status)	exit(status)
__EXTERN void exit(INTEGER status);
#define LibC_fclose(fp)	fclose(fp)
__EXTERN INTEGER fclose(SYSTEM_PTR fp);
#define LibC_feof(fp)	feof(fp)
__EXTERN INTEGER feof(SYSTEM_PTR fp);
#define LibC_fflush(fp)	fflush(fp)
__EXTERN INTEGER fflush(SYSTEM_PTR fp);
#define LibC_fgets(s, n, fp)	fgets(s, n, fp)
__EXTERN SYSTEM_PTR fgets(SYSTEM_PTR s, INTEGER n, SYSTEM_PTR fp);
#define LibC_fopen(filename, mode)	fopen(filename, mode)
__EXTERN SYSTEM_PTR fopen(SYSTEM_PTR filename, SYSTEM_PTR mode);
#define LibC_fread(ptr, size, nobj, stream)	fread(ptr, size, nobj, stream)
__EXTERN SYSTEM_PTR fread(SYSTEM_PTR ptr, SYSTEM_PTR size, SYSTEM_PTR nobj, SYSTEM_PTR stream);
#define LibC_free(p)	free(p)
__EXTERN void free(SYSTEM_PTR p);
#define LibC_fseek(stream, offset, origin)	fseek(stream, offset, origin)
__EXTERN INTEGER fseek(SYSTEM_PTR stream, INTEGER offset, INTEGER origin);
#define LibC_ftell(stream)	ftell(stream)
__EXTERN LONGINT ftell(SYSTEM_PTR stream);
#define LibC_ftw(filename, func, descriptors)	ftw(filename, func, descriptors)
__EXTERN INTEGER ftw(SYSTEM_PTR filename, LibC___ftw_func_t func, INTEGER descriptors);
#define LibC_fwrite(ptr, size, nobj, stream)	fwrite(ptr, size, nobj, stream)
__EXTERN SYSTEM_PTR fwrite(SYSTEM_PTR ptr, SYSTEM_PTR size, SYSTEM_PTR nobj, SYSTEM_PTR stream);
#define LibC_getcontext(ucontext_t)	getcontext(ucontext_t)
__EXTERN INTEGER getcontext(LibC_Ptrucontext_t ucontext_t);
#define LibC_getcwd(buf, size)	getcwd(buf, size)
__EXTERN SYSTEM_PTR getcwd(SYSTEM_PTR buf, SYSTEM_PTR size);
#define LibC_gets(s)	gets(s)
__EXTERN void gets(SYSTEM_PTR s);
#define LibC_gmtime(timep)	gmtime(timep)
__EXTERN LibC_tm gmtime(INTEGER *timep);
#define LibC_kill(pid, sig)	kill(pid, sig)
__EXTERN INTEGER kill(INTEGER pid, INTEGER sig);
#define LibC_localtime(timep)	localtime(timep)
__EXTERN LibC_tm localtime(INTEGER *timep);
#define LibC_malloc(size)	malloc(size)
__EXTERN SYSTEM_PTR malloc(SYSTEM_PTR size);
#define LibC_memcpy(dst, src, n)	memcpy((void*)dst, (const void*)src, n)
#define LibC_memset(s, c, n)	memset((void*)s, c, n)
#define LibC_mkdir(pathname, mode)	mkdir(pathname, mode)
__EXTERN INTEGER mkdir(SYSTEM_PTR pathname, SET mode);
#define LibC_mktime(timeptr)	mktime(timeptr)
__EXTERN INTEGER mktime(LibC_tm timeptr);
#define LibC_opendir(name)	opendir(name)
__EXTERN SYSTEM_PTR opendir(SYSTEM_PTR name);
#define LibC_printf(s)	printf(s)
#define LibC_readdir(dir)	readdir(dir)
__EXTERN LibC_PtrDirent readdir(SYSTEM_PTR dir);
#define LibC_remove(filename)	remove(filename)
__EXTERN INTEGER remove(SYSTEM_PTR filename);
#define LibC_rename(oldname, newname)	rename(oldname, newname)
__EXTERN INTEGER rename(SYSTEM_PTR oldname, SYSTEM_PTR newname);
#define LibC_scandir(dir, namelist, selector, cmp)	scandir(dir, namelist, selector, cmp)
__EXTERN INTEGER scandir(SYSTEM_PTR dir, LibC_PtrDirentArray namelist, LibC_SelectorFunc selector, LibC_CmpFunc cmp);
#define LibC_setcontext(ucontext_t)	setcontext(ucontext_t)
__EXTERN INTEGER setcontext(LibC_Ptrucontext_t ucontext_t);
#define LibC_setjmp(env)	setjmp(env)
__EXTERN INTEGER setjmp(LibC_jmp_buf env);
#define LibC_sigaction(sig_num, act, act__typ, oldact, oldact__typ)	sigaction(sig_num, act, oldact)
__EXTERN INTEGER sigaction(INTEGER sig_num, LibC_sigaction_t *act, LibC_sigaction_t *oldact);
#define LibC_sigaddset(set, sig)	sigaddset(set, sig)
__EXTERN INTEGER sigaddset(INTEGER set, INTEGER sig);
#define LibC_sigdelset(set, sig)	sigdelset(set, sig)
__EXTERN INTEGER sigdelset(INTEGER set, INTEGER sig);
#define LibC_sigemptyset(set)	sigemptyset(set)
__EXTERN INTEGER sigemptyset(INTEGER set);
#define LibC_sigfillset(set)	sigfillset(set)
__EXTERN INTEGER sigfillset(INTEGER set);
#define LibC_sigismemeber(set, sig)	sigismemeber(set, sig)
__EXTERN INTEGER sigismemeber(INTEGER set, INTEGER sig);
#define LibC_siglongjmp(env, env__typ, val)	siglongjmp(env, val)
__EXTERN void siglongjmp(LibC_sigjmp_buf *env, INTEGER val);
#define LibC_signal(sig_num, sighandler)	signal(sig_num, sighandler)
__EXTERN SYSTEM_PTR signal(INTEGER sig_num, SYSTEM_PTR sighandler);
#define LibC_sigsetjmp(env, env__typ, savemask)	__sigsetjmp(sigjmp_buf, savemask)
#define LibC_sprintf(str, n)	sprintf(str, "%ld", n)
#define LibC_sprintfL(str, n)	sprintf(str, "%lld", n)
#define LibC_sscanfai(src, format, a, i)	sscanf((const char*)src, (const char*)format, a, i)
#define LibC_sscanfi(src, format, i)	sscanf((const char*)src, (const char*)format, i)
#define LibC_strchr(str, ch)	((SYSTEM_PTR)strchr((const char *)str, (char)ch))
#define LibC_strcmp(str1, str2)	strcmp((const char*)str1, (const char*)str2)
#define LibC_strcpy(dst, src)	(SYSTEM_PTR)strcpy((char*)dst, (const char*)src)
#define LibC_strftime(s, max, format, ptm)	strftime(s, max, format, ptm)
__EXTERN SYSTEM_PTR strftime(SYSTEM_PTR s, SYSTEM_PTR max, SYSTEM_PTR format, LibC_tm ptm);
#define LibC_strlen(str)	strlen((const char *)str)
#define LibC_strncmp(str1, str2, count)	strncmp((const char*)str1, (const char*)str2, count)
#define LibC_strncpy(dst, src, len)	(SYSTEM_PTR)strncpy((char*)dst, (const char*)src, len)
#define LibC_strstr(str, substr)	((SYSTEM_PTR)strstr((const char *)str, (const char *)substr))
#define LibC_time(t)	time(t)
__EXTERN INTEGER time(INTEGER *t);

#endif
