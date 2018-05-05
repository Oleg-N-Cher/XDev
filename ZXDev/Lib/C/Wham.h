#ifndef Wham__h
#define Wham__h


extern void Wham_InitPlayNote (unsigned int chan1, unsigned int chan2) __z88dk_callee __preserves_regs(b,c,iyl,iyh);
extern void Wham_PlayNote (void) __preserves_regs(iyl,iyh);
extern void Wham_PlayKeyPress (unsigned int chan1, unsigned int chan2) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Wham_PlayTuneEnd (unsigned int chan1, unsigned int chan2) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Wham_SetTempo (unsigned char tempo) __z88dk_fastcall __preserves_regs(b,c,d,e,h,iyl,iyh);
#define Wham__init()


#endif
