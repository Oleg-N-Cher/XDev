#ifndef gwin_api_h
#define gwin_api_h

#define __stdcall  __attribute__((stdcall))

#if 0
#define PUSH_PAR(a)  asm volatile("pushl %0;": :"g" ( (a) ))

#define API1(f,a)  ({PUSH_PAR(a);f();})
#define API2(f,a1,a2)  ({ PUSH_PAR(a2);PUSH_PAR(a1);f();})
#define API3(f,a1,a2,a3)  ({ PUSH_PAR(a3);PUSH_PAR(a2);PUSH_PAR(a1);f();})
#define API4(f,a1,a2,a3,a4)  ({ PUSH_PAR(a4);PUSH_PAR(a3);PUSH_PAR(a2);PUSH_PAR(a1);f();})
#define API5(f,a1,a2,a3,a4,a5)  ({ PUSH_PAR(a5);PUSH_PAR(a4);PUSH_PAR(a3);PUSH_PAR(a2);PUSH_PAR(a1);f();})
#define API6(f,a1,a2,a3,a4,a5,a6)  ({ PUSH_PAR(a6);PUSH_PAR(a5);PUSH_PAR(a4);PUSH_PAR(a3);PUSH_PAR(a2);PUSH_PAR(a1);f();})
#define API7(f,a1,a2,a3,a4,a5,a6,a7)  ({ PUSH_PAR(a7);PUSH_PAR(a6);PUSH_PAR(a5);PUSH_PAR(a4);PUSH_PAR(a3);PUSH_PAR(a2);PUSH_PAR(a1);f();})
#define API8(f,a1,a2,a3,a4,a5,a6,a7,a8)  ({ PUSH_PAR(a8);PUSH_PAR(a7);PUSH_PAR(a6);PUSH_PAR(a5);PUSH_PAR(a4);PUSH_PAR(a3);PUSH_PAR(a2);PUSH_PAR(a1);f();})
#define API9(f,a1,a2,a3,a4,a5,a6,a7,a8,a9)  ({ PUSH_PAR(a9);PUSH_PAR(a8);PUSH_PAR(a7);PUSH_PAR(a6);PUSH_PAR(a5);PUSH_PAR(a4);PUSH_PAR(a3);PUSH_PAR(a2);PUSH_PAR(a1);f();})
#define API10(f,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10)  ({ PUSH_PAR(a10);PUSH_PAR(a9);PUSH_PAR(a8);PUSH_PAR(a7);PUSH_PAR(a6);PUSH_PAR(a5);PUSH_PAR(a4);PUSH_PAR(a3);PUSH_PAR(a2);PUSH_PAR(a1);f();})
#define API11(f,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11)  ({ PUSH_PAR(a11);PUSH_PAR(a10);PUSH_PAR(a9);PUSH_PAR(a8);PUSH_PAR(a7);PUSH_PAR(a6);PUSH_PAR(a5);PUSH_PAR(a4);PUSH_PAR(a3);PUSH_PAR(a2);PUSH_PAR(a1);f();})
#define API12(f,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12)  ({ PUSH_PAR(a12);PUSH_PAR(a11);PUSH_PAR(a10);PUSH_PAR(a9);PUSH_PAR(a8);PUSH_PAR(a7);PUSH_PAR(a6);PUSH_PAR(a5);PUSH_PAR(a4);PUSH_PAR(a3);PUSH_PAR(a2);PUSH_PAR(a1);f();})

#else

//template <class T> inline int PUSH(T a){ asm volatile("pushl %0;": :"g" (a) );};

inline void PUSH(int a){ asm volatile("pushl %0;": :"g" (a) );};
inline void PUSH(void* a){ asm volatile("pushl %0;": :"g" (a) );};
inline void PUSH(float a){ asm volatile("pushl %0;": :"g" (a) );};


#define API1(f,a)  ( PUSH(a),f())
#define API2(f,a1,a2)  ( PUSH(a2),PUSH(a1),f())
#define API3(f,a1,a2,a3)  ( PUSH(a3),PUSH(a2),PUSH(a1),f())
#define API4(f,a1,a2,a3,a4)  ( PUSH(a4),PUSH(a3),PUSH(a2),PUSH(a1),f())
#define API5(f,a1,a2,a3,a4,a5)  ( PUSH(a5),PUSH(a4),PUSH(a3),PUSH(a2),PUSH(a1),f())
#define API6(f,a1,a2,a3,a4,a5,a6)  ( PUSH(a6),PUSH(a5),PUSH(a4),PUSH(a3),PUSH(a2),PUSH(a1),f())
#define API7(f,a1,a2,a3,a4,a5,a6,a7)  ( PUSH(a7),PUSH(a6),PUSH(a5),PUSH(a4),PUSH(a3),PUSH(a2),PUSH(a1),f())
#define API8(f,a1,a2,a3,a4,a5,a6,a7,a8)  ( PUSH(a8),PUSH(a7),PUSH(a6),PUSH(a5),PUSH(a4),PUSH(a3),PUSH(a2),PUSH(a1),f())
#define API9(f,a1,a2,a3,a4,a5,a6,a7,a8,a9)  ( PUSH(a9),PUSH(a8),PUSH(a7),PUSH(a6),PUSH(a5),PUSH(a4),PUSH(a3),PUSH(a2),PUSH(a1),f())
#define API10(f,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10)  ( PUSH(a10),PUSH(a9),PUSH(a8),PUSH(a7),PUSH(a6),PUSH(a5),PUSH(a4),PUSH(a3),PUSH(a2),PUSH(a1),f())
#define API11(f,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11)  ( PUSH(a11),PUSH(a10),PUSH(a9),PUSH(a8),PUSH(a7),PUSH(a6),PUSH(a5),PUSH(a4),PUSH(a3),PUSH(a2),PUSH(a1),f())
#define API12(f,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12)  ( PUSH(a12),PUSH(a11),PUSH(a10),PUSH(a9),PUSH(a8),PUSH(a7),PUSH(a6),PUSH(a5),PUSH(a4),PUSH(a3),PUSH(a2),PUSH(a1),f())

#endif


typedef int (*API_FUNC)() __attribute__((stdcall));
typedef int (*WND_FUNC)(int hwnd,int msg,int wpar,long lpar) __attribute__((stdcall));
extern "C"
{
extern int (*PMessageBoxA)(int,char *,char *,int) __attribute__((stdcall));
extern int (*PExitProcess)(int) __attribute__((stdcall));
extern int (*PGetModuleHandleA)(char *) __attribute__((stdcall));
extern int (*PLoadLibraryA)(char *) __attribute__((stdcall));
extern API_FUNC (*PGetProcAddress)(int i,char *) __attribute__((stdcall));
};

extern "C"  int WinMain(int hndl,int prev_hndl,char *cmd_line,int cmd_show) __attribute__((stdcall));

//========================================
#endif







