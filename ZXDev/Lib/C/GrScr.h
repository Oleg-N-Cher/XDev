#ifndef GrScr__h
#define GrScr__h


extern void GrScr_ScrToAtr (void) __preserves_regs(b,c,h,l,iyl,iyh);
extern void GrScr_SetScr (unsigned char hiadr) __z88dk_fastcall __preserves_regs(b,c,d,e,h,iyl,iyh);
extern void GrScr_XYtoScr (void) __preserves_regs(b,c,h,l,iyl,iyh);

#define GrScr__init()


#endif
