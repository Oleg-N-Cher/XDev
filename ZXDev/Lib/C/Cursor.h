#ifndef Cursor__h
#define Cursor__h


extern unsigned char Cursor_Std [39];


extern void Cursor_Init (void *shape) __z88dk_fastcall __preserves_regs(iyh,iyl);
extern void Cursor_Draw (unsigned char x, unsigned char y) __z88dk_callee __preserves_regs(iyh,iyl);
extern void Cursor_Hide (void) __preserves_regs(iyh,iyl);
extern unsigned char Cursor_GetControl (void) __preserves_regs(e,iyh,iyl);
extern void Cursor_ResetSpeedUp (void) __preserves_regs(a,b,c,d,e,iyh,iyl);
extern void Cursor_ResetMouseOrigin (void) __preserves_regs(b,c,d,e,h,l,iyh,iyl);

#define Cursor__init()


#endif
