#ifndef ZX7__h
#define ZX7__h


extern void ZX7_Standard (unsigned int src, unsigned int dst) __z88dk_callee __preserves_regs(iyl,iyh);
extern void ZX7_Turbo (unsigned int src, unsigned int dst) __z88dk_callee __preserves_regs(iyl,iyh);
extern void ZX7_Mega (unsigned int src, unsigned int dst) __z88dk_callee __preserves_regs(iyl,iyh);
extern void ZX7_SmartRCS (unsigned int src, unsigned int dst) __z88dk_callee __preserves_regs(iyl,iyh);
extern void ZX7_AgileRCS (unsigned int src, unsigned int dst) __z88dk_callee __preserves_regs(iyl,iyh);

#define ZX7__init()


#endif

