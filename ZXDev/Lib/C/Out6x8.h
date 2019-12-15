#ifndef Out6x8__h
#define Out6x8__h


extern unsigned int Out6x8_font;

extern void Out6x8_At (signed char x, signed char y) __z88dk_callee __preserves_regs(b,d,e,iyl,iyh);
extern void Out6x8_Ch (unsigned char ch) __z88dk_fastcall __preserves_regs(iyl,iyh);
extern void Out6x8_Ln (void) __preserves_regs(iyl,iyh);
extern void Out6x8_Str (unsigned char *str) __z88dk_fastcall __preserves_regs(iyl,iyh);
extern void Out6x8_GenFont (unsigned int dest) __z88dk_fastcall __preserves_regs(iyl,iyh);

#define Out6x8__init()


#endif
