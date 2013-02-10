/* by M. Feoktistov (C) 1999-2003  */

#ifndef _string_h_
#define _string_h_

#include <sys/types.h>

#ifndef __cplusplus
#define inline static __inline__
#endif


#define NULL 0

inline char *  memchr(const void *_s, int _c, size_t _n)
{
  asm volatile(
  "jecxz 2f;
   cld;  repne;scasb;
   je 1f;
   2: movl $1,%%edi;
   1: decl %%edi"
   :"=&D" (_s),"=&c" (_n),"=&a" (_c)
   :"0" (_s), "1"(_n),"2" (_c)
  );
  return (char *)_s;
};
inline int     memcmp(const void *_s1, const void *_s2, size_t _n)
{
  asm volatile("jecxz 1f;
   cld;  repe;cmpsb;
   movb -1(%%edi),%%cl
   subb -1(%%esi),%%cl
   movsbl %%cl,%%ecx
   1:;"
   :"=&c" (_n),"=&D" (_s1),"=&S"(_s2)
   :"0" (_n), "1" (_s1),"2" (_s2)
  );
  return _n;
};
inline void *  memcpy(void *_s1, const void *_s2, size_t _n)
{
  asm volatile("cld; rep; movsb;
    ":"=&D" (_s2),"=&S" (_s2),"=&c" (_n)
     :"0" (_s1),"1" (_s2),"2" (_n)
  );
  return _s1;
};
inline void *  memcpy_rl(void *_s1, const void *_s2, size_t _n)
{
  asm volatile("cld; rep; movsb;
   ":"=&D" (_s1),"=&S" (_s2),"=&c" (_n)
    :"0" (_s1),"1" (_s2),"2" (_n)
  );
  return _s1;
};
#define memmove(s1,s2,n) memcpy(s1,s2,n)
inline void *  memset(void *_s, int _c, size_t _n)
{
  asm volatile("cld;  rep;stosb;":"=&D" (_s),"=&c" (_n),"=&a" (_c)
       :"0" (_s),"1" (_n),"2" (_c)
  );
  return _s;
};
#define bzero(s,l) memset(s,0,l)
inline char *  rstrchr(const char *_s, int _c)
{
  asm volatile("std
  2: scasb
     je  1f
     cmpb $0,1(%%edi)
     jne  2b
     movl $-1,%%edi
  1: incl %%edi
     cld;       "
     :"=&D" (_s),"=&a" (_c)
     :"0" (_s),"1" (_c)
  );
  return (char *) _s;
};
inline char * strchr(const char *_s, int _c)
{
 asm volatile("cld;
  2: scasb;
     je  1f
     cmpb $0,-1(%%edi)
     jne  2b
     movl  $1,%%edi;
  1: decl %%edi;"
    :"=&D" (_s),"=&a" (_c)
    :"0" (_s),"1" (_c)
 );
  return (char *) _s;
};
inline char *  strcpy(char *_s1, const char *_s2)
{
  asm volatile("cld;
 1:lodsb
   stosb
   orb %%al,%%al
   jnz 1b"
   :"=&D" (_s1),"=&S" (_s2)
   :"0" (_s1),"1" (_s2)
   :"%eax"
  );
  return _s1;
};
inline char *  strcpy_rl(char *_s1, const char *_s2)
{
  asm volatile("cld;
  1:lodsb
    stosb
    orb %%al,%%al
    jnz 1b"
    :"=&D" (_s1),"=&S" (_s2)
    :"0" (_s1),"1" (_s2)
    :"%eax"
  );
  return _s1;
};
inline size_t  strcspn(const char *_s1, const char *_s2)
{
 register char * res=(char *) _s1;
 while((*res) && (!strchr(_s2,*res)) )res++;
 return res-_s1;
};
#define strerror( _errcode)  0;
inline size_t  strlen(const char *_s)
{
 int _x;
  asm volatile("cld;
    xorb %%al,%%al;
    xorl %%ecx,%%ecx;
    decl %%ecx;
    repne; scasb;
    incl %%ecx;
    notl %%ecx;"
   :"=c" (_s),"=&D" (_x)
   :"1" (_s)
   :"%eax"
  );
  return (int)_s;
};
inline char *  strncat(char *_s1, const char *_s2, size_t _n)
{
  asm volatile("cld; movl $-1,%%ecx;
    xor %%al,%%al;
    repne; scasb;
    decl %%edi;
    lea  1(%%edx),%%ecx;
   1:
    lodsb;
    stosb;
    orb %%al,%%al;
    loopnz 1b
    movb $0,-1(%%edi) "
    :"=&D" (_s2),"=&S" (_s2),"=&d" (_n)
    :"0" (_s1),"1" (_s2),"2" (_n)
    :"%ecx", "%eax"
  );
  return _s1;
};
inline char *  strncat_rl(char *_s1, const char *_s2, size_t _n)
{
  asm volatile("cld; movl $-1,%%ecx;
   xor %%al,%%al;
   repne; scasb;
   decl %%edi;
   lea  1(%%edx),%%ecx;;
  1:
   lodsb;
   stosb;
   orb %%al,%%al;
   loopnz 1b
   movb $0,-1(%%edi) "
   :"=&D" (_s1),"=&S" (_s2),"=&d" (_n)
   :"0" (_s1),"1" (_s2),"2" (_n)
   :"%eax","%ecx"
  );
  return _s1;
};
inline int  strncmp(const char *_s1, const char *_s2, size_t _n)
{
  asm volatile("cld;jecxz 1f;
  3: lodsb; scasb; jne 2f;
     orb %%al,%%al
     loopnz 3b;
     jecxz  1f;
  2: movl -1(%%edi),%%ecx
     subl -1(%%esi),%%ecx
  1:;"
    :"=&c" (_n),"=&D" (_s1),"=&S" (_s2)
    :"1" (_s1),"2" (_s2),"0" (_n)
    :"%eax"
);
  return _n;
};
inline char *  strncpy(char *_s1, const char *_s2, size_t _n)
{
  asm volatile("cld; incl %%ecx ;
    1:lodsb
      stosb
      orb %%al,%%al
      loopnz 1b;
    2:movb $0,-1(%%edi) "
  :"=&D" (_s2),"=&S" (_s2),"=&c" (_n)
  :"0" (_s1),"1" (_s2),"2" (_n)
  :"%eax"
  );
  return _s1;
};
inline char *  strncpy_rl(char *_s1, const char *_s2, size_t _n)
{
  asm volatile("cld; jecxz 2f;
  1:lodsb
    stosb
    orb %%al,%%al
    loopnz 1b;
    2:"
   :"=&D" (_s1),"=&S" (_s2),"=&c" (_n)
   :"0" (_s1),"1" (_s2),"2" (_n)
  :"%eax"
  );
  return _s1;
};
inline size_t  strspn(const char *_s1, const char *_s2)
{
 register char * res=(char *) _s1;
 while((*res) && (strchr(_s2,*res)) )res++;
 return res-_s1;
};
inline int strin(const char *_s1, const char *_s2)
{
  asm volatile("cld; movl $1,%%ecx;
  3: lodsb;
     orb %%al,%%al
     jz 1f;
     scasb;
     je 3b;
     decl   %%ecx
  1:;"
  :"=c" (_s1),"=&D" (_s2),"=&S" (_s2)
  :"1" (_s1),"2" (_s2)
  :"%eax"
  );
  return (int)_s1;
};
inline int strin1(const char *_s1, const char *_s2)
{
  asm volatile("cld; movl $-1,%%ecx;
   repe; cmpsb;
   xor   %%ecx,%%ecx
   cmpb  %%cl,-1(%%esi)
   sete  %%cl;
  1:;"
   :"=c" (_s1),"=&D" (_s2),"=&S" (_s2)
   :"1" (_s1),"2" (_s2)
   :"%eax"
);
  return (int)_s1;
};
#define  strxfrm  strncpy
inline char *  strcat(char *_s1, const char *_s2)
{
 asm volatile("cld;
   movl $-1,%%ecx;
   xor %%al,%%al;
   repne;scasb;
   decl %%edi;
  1:
   lodsb
   stosb
   orb %%al,%%al
   jnz 1b"
   :"=&D" (_s2),"=&S" (_s2)
   :"0" (_s1),"1" (_s2)
   :"%ecx","%eax"
 );
 return _s1;
};
inline int     strcmp(const char *_s1, const char *_s2)
{
 asm volatile("cld;
   3: lodsb; scasb; jne 2f;
      orb %%al,%%al
      jnz 3b;
   2: movb -1(%%edi),%%al
      subb -1(%%esi),%%al
      movsbl  %%al,%%eax
   1:;"
   :"=a" (_s1),"=&D" (_s2),"=&S" (_s2)
   :"1" (_s1),"2" (_s2)
   );
 return (int)_s1;
};
#define  strcmpnc stricmp
inline int stricmp(const char *_s1, const char *_s2)
{
 asm volatile("cld;
  3: lodsb; scasb; jne 2f;
     orb %%al,%%al
     jnz 3b;
  2: xor $0x20,%%al
     cmp -1(%%edi),%%al
     je  3b
     xor $0x20,%%al
     movb -1(%%edi),%%al
     subb -1(%%esi),%%al
     movsbl  %%al,%%eax
  1:;"
  :"=a" (_s1),"=&D" (_s2),"=&S" (_s2)
  :"1" (_s1),"2" (_s2)
 );
 return (int)_s1;
};
#define  strcoll(s1,s2) strcmp(s1,s2)
inline char *  strpbrk(const char *_s1, const char *_s2)
{
 asm volatile("cld;
     movl %%edx,%%edi
     xorl %%eax,%%eax;
     movl $-1,%%ecx;
     repne; scasb;
     lea  1(%%ecx),%%ebx
     notl %%ebx;
  3:
     lodsb
     or   %%al,%%al
     jnz   2f
     xorl  %%esi,%%esi
     jmp   1f
  2:
     movl %%edx,%%edi
     movl %%ebx,%%ecx
     repne; scasb;
     jne  3b
     decl %%esi;
  1:"
  :"=&S" (_s1),"=&d" (_s2)
  :"0"(_s1),"1" (_s2)
  :"%ecx","%ebx","%edi","%eax"
 );
 return (char *)_s1;
}
inline char *  strrchr(const char *_s, int _c)
{
  asm volatile("cld;
    xorb %%ah,%%ah;
    xorl %%edx,%%edx;
  2:cmp  (%%edi),%%ah;
    je  3f;
    scasb;
    jne 2b;
    lea -1(%%edi),%%edx;
    jmp 2b;
  3:"
   :"=d" (_s),"=&D" (_c),"=&a" (_c)
   :"1" (_s),"2" (_c)
);
  return (char *)_s;
};
inline int strinnc(const char *_s1, const char *_s2)
{
  asm volatile("cld; movl $1,%%ecx;
  3:lodsb;
    orb %%al,%%al
    jz 1f;
    scasb; je 3b;
    xorb $0x20,%%al
    cmpb -1(%%edi),%%al
    je  3b
    decl   %%ecx
  1:;"
  :"=c" (_s1),"=&D" (_s2),"=&S" (_s2)
  :"1" (_s1),"2" (_s2)
  :"%eax"
  );
  return (int)_s1;
};
inline char *  strstr(const char *_s1, const char *_s2)
{
 asm volatile("cld
  2:movl %%edx,%%esi
    movl %%ecx,%%edi
  3:lodsb
    orb  %%al,%%al
    jz 1f
    scasb
    je  3b
    incl %%ecx
    cmpb $0,(%%ecx)
    jne  2b
    xorl %%ecx,%%ecx
  1:
  ":"=&c"(_s1),"=&d"(_s2)
   :"0"(_s1),"1"(_s2)
   :"%edi","%esi","%eax"
  );
 return (char *) _s1;
}

#define  strstrnc stristr
inline char *  stristr(const char *_s1, const char *_s2)
{
 asm volatile("cld
  2: movl %%edx,%%esi
     movl %%ecx,%%edi
  3: lodsb
     orb  %%al,%%al
     jz 1f
     scasb
     je 3b
     xorb $0x20,%%al
     cmpb -1(%%edi),%%al
     je  3b

     incl %%ecx
     cmpb $0,(%%ecx)
     jne 2b
     xorl %%ecx,%%ecx
  1:
  ":"=&c"(_s1),"=&d"(_s2)
   :"0"(_s1),"1"(_s2)
   :"%edi","%esi","%eax" );
 return (char *) _s1;
}


#endif
